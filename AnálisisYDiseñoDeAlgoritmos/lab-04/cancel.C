extern bool verbose;

template 
<class Net, 
 template <class> class Max_Flow_Algo = Ford_Fulkerson_Maximum_Flow>
tuple<size_t, double>
my_max_flow_min_cost_by_cycle_canceling(Net & net, 
				     double it_factor,
				     size_t step,
				     double time)
{    
  Max_Flow_Algo <Net> () (net); // compute max flow

  using Rnet = Residual_Net<typename Net::Flow_Type>;
  using BF = 
    Bellman_Ford<Rnet, Rcost<Rnet>, Arc_Iterator, Out_Iterator, Res_Filt<Rnet>>;

  Rnet rnet;
  DynMapTree<void*, void*> arcs_map;
  typename Rnet::Node * source = build_residual_net(net, rnet, arcs_map);

  size_t count = 0;

  double t = now();
  while (true)
    { search: 
      tuple<Path<Rnet>, size_t> cycle =
	BF(rnet).search_negative_cycle(source, it_factor, step); 
      if (get<0>(cycle).is_empty())
	break;
      
      if (verbose)
	cout << "Canceling cycle " << ++count << " (" << 100*it_factor 
	     << " %, " << get<1>(cycle) << ")" << endl;

      it_factor = ((double) get<1>(cycle))/net.vsize();
      cancel_cycle(rnet, get<0>(cycle));

      double tt = now_delta(&t);
      if (verbose)
	cout << "Elapsed time = " << tt << endl;
      if (tt > time)
	{
	  throw std::range_error(fmt("Maximum time %f exceeded", time));
	}
    }
  
  tuple<Path<Rnet>, size_t> cycle = 
    BF(rnet).search_negative_cycle(it_factor, step); 
  if (not get<0>(cycle).is_empty()) // negative cycle found?
    {
      cancel_cycle(rnet, get<0>(cycle));      
      if (verbose)
	cout << "Canceling cycle " << ++count << " (" << 100*it_factor 
	     << " %, " << get<1>(cycle) << ")" << endl;
      goto search;
    }

  residual_to_net<Net>(arcs_map);

  return make_tuple(count, it_factor);
}

template <class Net, 
	  template <class> class Max_Flow_Algo = Ford_Fulkerson_Maximum_Flow>
struct My_Max_Flow_Min_Cost
{
  tuple<size_t, double> operator () (Net & net, 
				     double it_factor = 0.4, 
				     size_t step = 10)
  {
    return my_max_flow_min_cost_by_cycle_canceling<Net, Max_Flow_Algo>
      (net, it_factor, step);
  }
};
