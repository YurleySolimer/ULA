class Points 
{
 
  DynList<City> l2;
  DynList<tuple<tuple<City,City>,double>> l3;
  DynList<tuple<tuple<City,City>,double>> lista2;

  public:

    Points(const DynList<City> & l)
    {
      this->l2=l;
      for(DynList<City>::Iterator it1(l); it1.has_curr();it1.next())
      {
        auto c1 = it1.get_current();
        auto x1=  get<0>(get<0>(c1)) ;
        auto y1=  get<1>(get<0>(c1));

        if (not l2.is_empty())
        {
          l2.remove_first();
          for(DynList<City>::Iterator it2(l2); it2.has_curr();it2.next())
          {     
            auto c2 = it2.get_current();
            auto x2=  get<0>(get<0>(c2));
            auto y2=  get<1>(get<0>(c2));
            auto d= (pow(x2-x1, 2) + pow(y2-y1, 2));
            l3.append(make_tuple(make_tuple(c1,c2),d));
          } 
        } 
      }
      lista2=  sort(l3, [ ] (auto i, auto i2)
      {      
        if (get<1>(i) <= get<1>(i2))
          return  true;      
        return false;
      });
    }

  Gmap build_gmap(const double span_dist)
  {
    Gmap ge;
     
    ge.reset_nodes();
    ge.reset_arcs();

    Gmap::Node * n1;
    Gmap::Node * n2;
 
    for(DynList<tuple<tuple<City,City>,double>>::Iterator it1(lista2); it1.has_curr();it1.next())
    {
      bool s1=false;
      bool s2=false;
      if(ge.get_num_nodes()==0)
      {
        n1= ge.insert_node(get<0>(get<0>(it1.get_current())));
        n2= ge.insert_node(get<1>(get<0>(it1.get_current())));
        s1=true;
        s2=true;
        if(get<1>(it1.get_current()) <= pow(span_dist,2))
          ge.insert_arc(n1,n2, get<1>(it1.get_current()));
        continue;
      }
      auto a=ge.nodes();
       for(DynList<Gmap::Node*>:: Iterator i(a); i.has_curr(); i.next())
       {
        if(get<0>(get<0>(it1.get_current())) == i.get_current()->get_info())
          s1=true;
         if(get<1>(get<0>(it1.get_current())) == i.get_current()->get_info())
          s2=true;
       }
       if(not s1)
        n1= ge.insert_node(get<0>(get<0>(it1.get_current())));
       if(not s2)
        n2= ge.insert_node(get<1>(get<0>(it1.get_current())));
        if(get<1>(it1.get_current()) <= pow(span_dist,2))
          ge.insert_arc(n1,n2, get<1>(it1.get_current()));
        continue;
        
    }
       
    
    return ge;
  }













    for (Gmap::Node_Iterator it(ge); it.has_curr(); it.next())
    cout << get<1>(it.get_curr()->get_info()) << endl;

  cout << ge.get_num_arcs() << " arcs\n";
    
  for (Gmap::Arc_Iterator it(ge); it.has_curr(); it.next())
    {
      auto a = it.get_curr();
      auto s = ge.get_src_node(a);
      auto t = ge.get_tgt_node(a);
      cout << get<1>(s->get_info()) << " -- " << get<1>(t->get_info()) << endl;
    }

  cout << endl;