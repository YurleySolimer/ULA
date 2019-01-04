// YURLEY BARRIOS C.I 22.986.327
// CARLOS RAMIREZ C.I 24.196.192

class Solver
{
  DynList<Student> l_st;  
  DynList<Course> l_cs;

  DynSetHash<Student> TableStudentA;
  DynSetHash<Course> TableCourseA;

  Prob_Mat matrixA;
  Prob_Mat matrixB;
  Prob_Mat matrixC;

  long cost_st;
  Net net;

public:

  Solver(Prob_Mat && pA, Prob_Mat && pB, Prob_Mat && pC,
   DynList<Course> && course_list, DynList<Student> && st_list,
   const long cost_by_student)
  {
    cost_st= cost_by_student;

    l_st = sort(st_list, [ ] (auto s1, auto s2)
    { 
      if (s1.id<=s2.id)
        return true;
      return false;
    }); 

    for(DynList<Student>::Iterator it(l_st); it.has_current(); it.next())
      TableStudentA.insert(it.get_curr());

    l_cs = sort(course_list, [] (auto c1, auto c2)
    {
      if (c1.id <= c2.id)
        return true;
      return false;
    });

    for(DynList<Course>::Iterator it(l_cs); it.has_curr(); it.next())
      TableCourseA.insert(it.get_curr());
     
    matrixA=pA;
    matrixB=pB;
    matrixC=pC;
  }

  const Net & build_net()
  {
    DynList<Node *> TableNodeS;
    DynList<Node *> TableNodeC;

    auto sink = net.insert_node(new Uid);

    for(DynList<Course>::Iterator it(l_cs); it.has_curr(); it.next())
      {
        Uid *course = dynamic_cast<Uid *>(&it.get_curr());
        
        auto n_cs = net.insert_node(course);
        auto cs_ncourse = it.get_curr().cap;
        auto cs_cexpected = it.get_curr().cost;
  
        TableNodeC.insert(n_cs);
        net.insert_arc(n_cs, sink, cs_ncourse, cs_cexpected);
      }

    auto sourc = net.insert_node(new Uid);

    for(DynList<Student>::Iterator it(l_st); it.has_curr(); it.next())
      {
        Uid *student = dynamic_cast<Uid *> (&it.get_curr());
  
        auto n_st = net.insert_node(student);
        auto st_ncourse = it.get_curr().num_courses;
        auto st_cexpected = expected_cost(it.get_curr());

        net.insert_arc(sourc, n_st, st_ncourse, st_cexpected);
        TableNodeS.insert(n_st);
      }

    for(DynList<Node*>::Iterator it(TableNodeS); it.has_current();it.next())
    {
      Student * st_ptr = dynamic_cast<Student*>(it.get_curr()->get_info());
      
      auto l_courses = st_ptr->selected_courses;
      for(DynList<Ulong>::Iterator it2(l_courses); it2.has_current(); it2.next())
        {
          for(DynList<Node*>::Iterator it3(TableNodeC); it3.has_current(); it3.next())
          {
            Course * cs_ptr = dynamic_cast<Course*>(it3.get_curr()->get_info());
            if (it2.get_curr() == cs_ptr->id)
              net.insert_arc(it.get_curr(), it3.get_curr(), 1, 0); 
          }
        }
    }

    return net;
  }

  const Net & get_net() const { return net; }

  template 
  <template <class, template <class> class> class Max_Flow_Min_Cost_Algo,
   template <class> class Max_Flow_Algo = Fifo_Preflow_Maximum_Flow>
  const Net & assign(double it_factor = 0.5, size_t step = 8) 
  {

    Max_Flow_Min_Cost_By_Cycle_Canceling <Net,  Max_Flow_Algo> () (net, it_factor, step);
    
    return net;
  }

  const DynList<Student> & get_students() const 
  {
    return l_st;
  }

  const DynList<Course> & get_courses() const 
  {
    return l_cs;
  }

  const Student & get_student(Ulong id) const 
  {
    for(DynList<Student>::Iterator it(l_st); it.has_curr(); it.next())
      {
        if (it.get_curr().id == id)
          return it.get_curr();
      }

     throw std::domain_error("id not found");
  }

  const Course & get_course(Ulong id) const
  {
    for(DynList<Course>::Iterator it(l_cs); it.has_curr(); it.next())
      {
        if (it.get_curr().id == id)
          return it.get_curr();
      }
    
    throw std::domain_error("id not found");
  }

  double expected_cost(const Student & st) const
  {
    DynList<Ulong> l_cost;
    Course cr;
    auto type_st = st.type;
    auto list_courses = st.selected_courses;
    auto ncourse = st.num_courses;   
    
    double mcost = 0;
    double i = 1;
      
    switch (type_st) 
      {
      case 'A': 

      for(DynList<DynList<double>>::Iterator it(matrixA); it.has_curr();it.next())
        {
           if (i==ncourse) 
           {
              for (DynList<double>::Iterator it_2(it.get_curr()); it_2.has_curr();it_2.next())
              {
                mcost = (ncourse*cost_st*it_2.get_curr()) + mcost;
                ncourse--;
              }

              return mcost;
            } 
          
            i++;
        }
    
      case 'B': 
  
      for(DynList<DynList<double>>::Iterator it(matrixB); it.has_curr();it.next())
        {
           if (i==ncourse) 
           {
              for (DynList<double>::Iterator it_2(it.get_curr()); it_2.has_curr();it_2.next())
              {
                mcost = (ncourse*cost_st*it_2.get_curr()) + mcost;
                ncourse--;
              }

              return mcost;
            } 
          
            i++;
        }
    
      case 'C':
    
      for(DynList<DynList<double>>::Iterator it(matrixC); it.has_curr();it.next())
        {
           if (i==ncourse) 
           {
              for (DynList<double>::Iterator it_2(it.get_curr()); it_2.has_curr();it_2.next())
              {
                mcost = (ncourse*cost_st*it_2.get_curr()) + mcost;
                ncourse--;
              }

              return mcost;
            } 
          
            i++;
        }
   
    }
    return mcost;
  }

  double assigned_expected_cost(const Student & st) const
  {
    DynList<Ulong> l_cost;
    Course cr;

    auto type_st = st.type;
    auto list_courses = st.assigned_courses;
    auto ncourse = st.num_courses; 

    double mcost = 0;
    double i = 1;
      
    switch (type_st) 
      {
      case 'A': 

      for(DynList<DynList<double>>::Iterator it(matrixA); it.has_curr();it.next())
        {
           if (i==ncourse) 
           {
              for (DynList<double>::Iterator it_2(it.get_curr()); it_2.has_curr();it_2.next())
              {
                mcost = (ncourse*cost_st*it_2.get_curr()) + mcost;
                ncourse--;
              }
              return mcost;
            } 
          i++;
        }

    
      case 'B': 
  
      for(DynList<DynList<double>>::Iterator it(matrixB); it.has_curr();it.next())
        {
          if (i==ncourse) 
          {
            for (DynList<double>::Iterator it_2(it.get_curr()); it_2.has_curr();it_2.next())
            {
              mcost = (ncourse*cost_st*it_2.get_curr()) + mcost;
              ncourse--;
            }
           return mcost;
          } 

        i++;
        }
    
      case 'C':
    
      for(DynList<DynList<double>>::Iterator it(matrixC); it.has_curr();it.next())
        {
          if (i==ncourse) 
          {
            for (DynList<double>::Iterator it_2(it.get_curr()); it_2.has_curr();it_2.next())
            {
              mcost = (ncourse*cost_st*it_2.get_curr()) + mcost;
              ncourse--;
            }
          return mcost;
          } 
          
          i++;
        }
   
    }
    return mcost;
  }

  double expected_payment(const Course & c) const
  {
    long i=0;
    for(DynList<Student>::Iterator it(l_st);it.has_curr();it.next()){
      for(DynList<Ulong>::Iterator it2(it.get_curr().selected_courses);it2.has_curr();it2.next()){
        if (it2.get_curr() == c.id)
          i++;
      }
    }

    return c.cost*i;
  }

  double cost_gain(const Course & c) const
  {
    return c.cost;
  }

  DynList<tuple<Ulong, double>> students_expected_payment() const
  {
    DynList<tuple<Ulong, double>> students_payment;

    for(DynList<Student>::Iterator it(l_st);it.has_curr();it.next())
      students_payment.append(make_tuple(it.get_curr().id, assigned_expected_cost(it.get_curr())));

    return students_payment;
  }

  DynList<tuple<Ulong, double, double>> course_payment() const
  {
    DynList<tuple<Ulong, double, double>> cs_payment;

    for(DynList<Course>::Iterator it(l_cs);it.has_curr();it.next())
      cs_payment.append(make_tuple(it.get_curr().id, cost_gain(it.get_curr()), 
           expected_payment(it.get_curr())));
    return cs_payment;
  }

private:

  struct Node_Attr
  {
    void operator () (const Net & net, Net::Node * p, std::ostream & out)
    {
      out << "label = \"";
      if (p == net.get_source())
  out << "Source";
      else if (p == net.get_sink())
  out << "Sink";
      else
  {
    out << p->get_info()->id;
    Student * st_ptr = dynamic_cast<Student*>(p->get_info());
    if (st_ptr)
      out << " " << st_ptr->type;
  }
      out << "\"";
    }
  };

  struct Arc_Attr
  {
    void operator () (const Net &, Net::Arc * a, std::ostream & out)
    {
      out << "label = \"" << a->cap << " / " << a->cost << "\"";
    }
  };

  struct Arc_Flow
  {
    void operator () (const Net &, Net::Arc * a, std::ostream & out)
    {
      out << "label = \"" << a->flow << " / " << a->cap << "\"";
    }
  };

public:

  // genera graphviz de la red inicial (capacidades y costes)
  void graphviz_cap(std::ostream & out) const
  {
    To_Graphviz<Net, Node_Attr, Arc_Attr>().digraph(get_net(), out);
  }

  // genera graphviz de la red con flujos (flujos y capacidades)
  void graphviz_flow(std::ostream & out) const
  {
    To_Graphviz<Net, Node_Attr, Arc_Flow>().digraph(get_net(), out);
  }
};