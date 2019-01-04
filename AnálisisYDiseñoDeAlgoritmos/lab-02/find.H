//Yurley Barrios
//C.I. 22.986.327


using namespace std;


// retorna la cantidad de nodos que satisfacen la máscara de color
size_t count_node_color(const SocialNet & net, NetColor color)
{
	size_t c=0;
  	net.for_each_node([&c, &color](auto i)
  	{
  		if (i->get_info().color  == color)
			c++;
  	});

    return c;
}

// retorna la cantidad de arcos que satisfacen la máscara de color
size_t count_arc_color(const SocialNet & net, NetColor color)
{
	size_t c=0;
  	net.for_each_arc([&c, &color](auto i)
  	{
  		if (i->get_info().color  == color)
			c++;
  	});

    return c;
}

// Retorna una lista ordenada por colores pares <color,cantidad de nodos>
DynList<std::pair<NetColor, size_t>> count_node_color(const SocialNet & net)
{
	DynList<std::pair<NetColor, size_t>> lista;
	DynMapTree<NetColor, long , Treap> mt;
	std::pair<NetColor, size_t> par;
	size_t cont=1;
	
	net.for_each_node([&lista, &par, &cont, &mt] (auto p)
	{
		auto & f = p->get_info();
		mt.for_each([&cont, &f, &p, &par](auto i)
		{
			if(f.color == i.first)
				cont++;
		});
    	par.first = f.color;
		par.second=cont;
		mt.insert(par);
   	});
 	mt.for_each([&lista](auto i)
	{
		lista.append(i);
	});

	return lista;
}

// Retorna una lista ordenada por colores pares <color,cantidad de arcos>
DynList<std::pair<NetColor, size_t>> count_arc_color(const SocialNet & net)
{
 	DynList<std::pair<NetColor, size_t>> lista;
	DynMapTree<NetColor, long , Treap> mt;
	std::pair<NetColor, size_t> par;
	size_t cont=1;
	
	net.for_each_arc([&lista, &par, &cont, &mt] (auto p)
	{
		auto & f = p->get_info();
		mt.for_each([&cont, &f, &p, &par](auto i)
		{
			if(f.color == i.first)
				cont++;
		});
    	par.first = f.color;
		par.second=cont;
		mt.insert(par);
   	});
 	mt.for_each([&lista](auto i)
	{
		lista.append(i);
	});

	return lista;
}

// Retorna una lista de nodos que satisfacen la máscara de color. La
// lista está ordenada por id de nodo
DynList<SocialNet::Node*> nodes(const SocialNet & net, NetColor color)
{
	DynList<SocialNet::Node*> lista;
	net.for_each_node([&lista, &color] (auto p)
	{
		auto & f = p->get_info();
		if(f.color == color)
			lista.insert(p);
   	});

   	lista = sort(lista, [ ] (auto i1, auto i)
   	{ return true ;	});

	return lista;
}

// retorna una lista de arcos que satisfacen la máscara de color. La
// lista está ordenada por el costo del arco
DynList<SocialNet::Arc*> arcs(const SocialNet & net, NetColor color) 
{
  	DynList<SocialNet::Arc*> lista;
  	net.for_each_arc([&lista, &color] (auto p)
	{
		auto & f = p->get_info();
		if(f.color == color)
			lista.insert(p);
   	});

   	
  	auto lista2=  sort(lista, [ ] (auto i, auto i2)
   	{
   		
   		if (i->get_info().cost < i2->get_info().cost) 
   		  return  true; 
   		
   		if (i ->get_info().cost == i2->get_info().cost) 
   		{
   			if (bits_str(i->get_info().color) <  bits_str(i2 ->get_info().color)) 
   				return  true; 
   		}
   		return false;
 	});
	return lista2;
}



Path<SocialNet> find_path_depth_first(const SocialNet & net, 
				      const unsigned long start_id,
				      const unsigned long end_id,
				      const NetColor node_colors,
				      const NetColor arc_colors)
{

	Path<SocialNet> path;
	Graph_Anode<Friend> * n_start; 
	Graph_Anode<Friend> * n_end; 
	DynList<SocialNet::Arc*>  l2;

	net.reset_nodes();
  	net.reset_arcs();

  	for (SocialNet::Node_Iterator it(net); it.has_curr(); it.next())
    {
    	auto p = it.get_curr();
		if (p->get_info().id  == start_id) 
		{
			path.init(p); 
			n_start = p;
		}
		if (p->get_info().id == end_id)
			n_end = p;
	}
    
    if( start_id == end_id )   
        return path; 
  

     auto l = net.arcs(n_start);
   
     l.for_each([&node_colors, &arc_colors, &net, &path, &l2] (auto i)
     { 

     	if (i->get_info().color == arc_colors) 
     	{  	
     		auto  n = net.get_tgt_node(i);
     		if (n->get_info().color == node_colors)
     			l2.insert(i);
     	}
     });

    auto lista3=  sort(l2, [ &net] (auto i, auto i2)
   	{
   		if (net.get_num_arcs(net.get_tgt_node(i))  < net.get_num_arcs(net.get_tgt_node(i2))) 
   		  return  true; 
   		return false;
 	});

    lista3.for_each([&net, &node_colors, &arc_colors, &end_id, &path]( auto  i)
	{	
		path.insert(i) ;
		path.insert(net.get_tgt_node(i));
		
	});


	return path;
}





Path<SocialNet> find_path_breadth_first(const SocialNet & net, 
					const unsigned long start_id,
					const unsigned long end_id,
					const NetColor node_colors,
					const NetColor arc_colors)
{
Path<SocialNet> path;
Array_Graph<Graph_Anode<Friend>, Graph_Aarc<FriendShip>>  lista;
DynList <Graph_Anode<Friend>>  l_n;


	

	return path; 
	
}

long long cost(const Path<SocialNet> & path)
{
	int cost=0;
	path.for_each_arc([&cost](auto i)
	{
		cost=cost+ i->get_info().cost;

	});

  return cost;
}


long long cost(Path<SocialNet> && path)
{
  return cost(path);
}

