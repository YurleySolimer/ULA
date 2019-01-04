// Yurley Barrios C.I. 22.986.327
// Carlos Remirez C.I 24.196.192

class Points 
{
 
  DynList<City> l2;
   
  public:

    Points(const DynList<City> & l)
    { 
      l2=l;  
 
    }

  Gmap build_gmap(const double span_dist)
  {
    Gmap g;
  
    DynList<Gmap::Node *> ln;
   
    for(DynList<City>::Iterator it(l2); it.has_curr();it.next())
      ln.insert(g.insert_node(it.get_current()));
    auto  ln2=ln;

    for(DynList<Gmap::Node *>::Iterator it1(ln); it1.has_curr();it1.next())
    {
      auto c1 = it1.get_current()->get_info();
      auto x1=  get<0>(get<0>(c1)) ;
      auto y1=  get<1>(get<0>(c1));

      if (not ln2.is_empty())
      {
        ln2.remove_first();
        for(DynList<Gmap::Node *>::Iterator it2(ln2); it2.has_curr();it2.next())
        {     
          auto c2 = it2.get_current()->get_info();
          auto x2=  get<0>(get<0>(c2));
          auto y2=  get<1>(get<0>(c2));
          auto d= (pow(x2-x1, 2) + pow(y2-y1, 2));


          if(d <= pow(span_dist,2))
            g.insert_arc(it1.get_current(), it2.get_current(),d);
        } 
      } 
    }
    return g;
  }

  const Point & get_point(const unsigned long id) const 
  {
    City c;
    for(DynList<City>::Iterator it(l2); it.has_curr();it.next())
        {     
          if (get<1>(it.get_current()) == id )
            c = it.get_current();
        }        
       
    return get<0>(c);
  }

  static size_t num_blocks(const Gmap & g) 
  {
     auto l = blocks(g);
     double i = l.size();
    
     return i;
  }

  static size_t num_blocks(const Gmap && g) 
  {
    return num_blocks(g);
  }

  static DynList<DynList<Gmap::Node*>> blocks(const Gmap & g)
  {
    g.reset_nodes();
    g.reset_arcs();

    DynList<DynList<Gmap::Node*>> cconex;
    DynList<Gmap> l;
     
    for(Gmap::Node_Iterator i(g); i.has_curr(); i.next())
    {
      auto  x=  i.get_current();
     
      if (IS_NODE_VISITED(x, Depth_First)) 
        continue; 
   
       Gmap comp;

      if (g.arcs(i.get_current()).is_empty())
        continue;
       NODE_BITS(x).set_bit(Depth_First, true);
            
        auto n1 = comp.insert_node(x->get_info());
    
        DynListQueue<Gmap::Node *> pila;
        pila.put(x);
     
        while (not pila.is_empty())
        {
          auto c=pila.get();
          for (Gmap::Node_Arc_Iterator it1(c); it1.has_curr(); it1.next())
          {
            auto a = it1.get_current_arc();
            if (IS_ARC_VISITED(a, Depth_First))
              continue;
            ARC_BITS(a).set_bit(Depth_First, true);

            auto ad = it1.get_tgt_node();
            if (IS_NODE_VISITED(ad, Depth_First))
              continue;

            NODE_BITS(ad).set_bit(Depth_First, true);

            auto n2= comp.insert_node(ad->get_info());
            comp.insert_arc(n1, n2);

            pila.put(ad);

          }
        }

        l.append(comp);
             
      }

      for(DynList<Gmap>:: Iterator j(l); j.has_curr(); j.next())
      {
        auto cconex2=  sort(j.get_current().nodes(), [ ] (auto i, auto i2)
        {      
          if (get<1>(i->get_info()) <= get<1>(i2->get_info()))
            return  true;      
          return false;
        });
        cconex.append(cconex2); 
      }
      
      
      return cconex;
  }

  static Path<Gmap> 
  min_path(const Gmap & g, unsigned long src_id, unsigned long tgt_id)
  {
    Dijkstra_Min_Paths<Gmap, Dft_Dist<Gmap> , Node_Arc_Iterator> d;
    Gmap::Node* src;
    Gmap::Node* tgt;
    Path<Gmap> p(g);
    bool src1=false;
    bool tgt1=false;

    g.for_each_node([&src_id, &tgt_id, &src, &tgt, &src1, &tgt1](auto i) 
      { 
        if (src_id==get<1>(i->get_info()))
        {
          src=i;
          src1=true;

        }
        if (tgt_id==get<1>(i->get_info()))
        {
          tgt=i;
          tgt1=true;
        }
      });

    if(not src1 || not tgt1) //{
      throw domain_error("node id not found"); //return  p; }

    if(src == tgt)
      return  p;

    if (d.paint_partial_min_paths_tree(g, src, tgt))
      d.get_min_path(tgt, p);

    return p;
  }

  double min_connectivity_distance()
  {
    DynList<Gmap::Node *> ln;
    Gmap ge;
    Gmap minimo;

    struct Cmp_Dist
    {
      bool operator () (Gmap::Arc * a1, Gmap::Arc * a2) 
      { 
        if (a1<=a2)
          return true;
        return false;
      }
    };
   
    for(DynList<City>::Iterator it(l2); it.has_curr();it.next())
      ln.insert(ge.insert_node(it.get_current()));
    auto  ln2=ln;
   
    for(DynList<Gmap::Node *>::Iterator it1(ln); it1.has_curr();it1.next())
    {
      auto c1 = it1.get_current()->get_info();
      auto x1=  get<0>(get<0>(c1)) ;
      auto y1=  get<1>(get<0>(c1));

      if (not ln2.is_empty())
      {
        ln2.remove_first();
        for(DynList<Gmap::Node *>::Iterator it2(ln2); it2.has_curr();it2.next())
        {     
          auto c2 = it2.get_current()->get_info();
          auto x2=  get<0>(get<0>(c2));
          auto y2=  get<1>(get<0>(c2));
          auto d= (pow(x2-x1, 2) + pow(y2-y1, 2));
          ge.insert_arc(it1.get_current(),it2.get_current(),d);

        } 
      } 
    }


    ge.sort_arcs(Cmp_Dist());
    ge.reset_nodes();
    ge.reset_arcs();

    Gmap::Arc * a;
      
    for(Gmap::Arc_Iterator it(ge); minimo.get_num_arcs() < ge.get_num_nodes() - 1;  it.next())
    {
      auto m_a= it.get_current_arc();
      auto n_src=ge.get_src_node(m_a);
 
      Gmap::Node * src_node;
     

      if (not IS_NODE_VISITED(n_src, Aleph::Spanning_Tree)) 
      {    
        NODE_BITS(n_src).set_bit(Aleph::Spanning_Tree, true); 
        src_node = minimo.insert_node(n_src->get_info());
      }
      else
      {
        for(Gmap::Node_Iterator i1(minimo); i1.has_curr(); i1.next())
        {
          if(get<1>(i1.get_current()->get_info())==get<1>(n_src->get_info()))
          {
            src_node=i1.get_current();
            break;
          }
        }
      }

      auto n_tgt=ge.get_tgt_node(m_a);
      Gmap::Node * tgt_node;

      if(n_tgt== nullptr)
        continue;

      if (not IS_NODE_VISITED(n_tgt, Aleph::Spanning_Tree)) 
      {    
        NODE_BITS(n_tgt).set_bit(Aleph::Spanning_Tree, true); 
        tgt_node = minimo.insert_node(n_tgt->get_info());
      }

      else
      {
        for(Gmap::Node_Iterator i1(minimo); i1.has_curr(); i1.next())
        {
          if(get<1>(i1.get_current()->get_info())==get<1>(n_tgt->get_info()))
          {
            tgt_node=i1.get_current();
            break;
          }
        }
      }
    
      a = minimo.insert_arc(src_node, tgt_node);

      if(has_cycle(minimo))
      {
        minimo.remove_arc(a);
        continue;
      }

   }
   int dmin = ceil(a->get_info());
   return dmin;
  }
};
