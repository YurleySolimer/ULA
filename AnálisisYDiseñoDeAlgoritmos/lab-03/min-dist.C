# include <math.h>

# include <ahSort.H>
# include <tpl_agraph.H>
# include <Dijkstra.H>
# include <tpl_graph_utils.H>
# include <tpl_union.H>

# include <defs.H>

# include <min-dist.H>

void usage()
{
  cout << "min-dist num-point xsize ysize seed" << endl;
  exit(0);
}

int main(int argc, char *argv[])
{
  if (argc != 5)
    usage();

  size_t num_points = atoi(argv[1]);
  double xsize = atof(argv[2]);
  double ysize = atof(argv[3]);
  unsigned long seed = atoi(argv[4]);

  cout << "Generating ramdon points ... " << endl;
  DynList<City> cs = cities(num_points, xsize, ysize, seed);
  Points points = cs;
  cout << "done!" << endl
       << endl;

  resize_process_stack(256*1024*1024);
  
  {
    double md = points.min_connectivity_distance();
    cout << "Done" << endl
	 << "minimum conectivity distance " << md << endl 
	 << endl;

    double min_dist;
    cout << "Enter span distance = ";
    cin >> min_dist;

    Gmap g = points.build_gmap(min_dist);

    cout << endl
	 <<"vsize = " << g.vsize() << endl
	 << "esize = " << g.esize() << endl
	 << "number of blocks       = " << points.num_blocks(g) << endl
	 << endl;

    {
      int i = 0;
      DynList<DynList<Gmap::Node*>> blocks = Points::blocks(g);
      blocks.for_each([&i] (const DynList<Gmap::Node*> & blk)
        {
	  cout << "Block " << i++ << ":";
	  sort(blk, [] (Gmap::Node * p1, Gmap::Node * p2)
	       {
		 return get<1>(p1->get_info()) < get<1>(p2->get_info());
	       }).for_each([] (Gmap::Node * p)
		   {
		     cout << " " << get<1>(p->get_info());
		   });
	  cout << endl
	       << endl;
	});
    }

    long src_id, tgt_id;

    while (true)
      {
	cout << "Enter source and target ids for a minimum path "
	  "(^d or negative for leaving)" << endl;
	if (not (cin >> src_id >> tgt_id) or src_id < 0 or tgt_id < 0) 
	  break;
	cout << "src id = " << src_id << endl
	     << "tgt id = " << tgt_id << endl;
	try
	  {
	    Path<Gmap> path = Points::min_path(g, src_id, tgt_id);
	    cout << path << endl;
	  }
	catch (exception & e)
	  {
	    cout << e.what() << endl;
	  }
      }
  }
}
