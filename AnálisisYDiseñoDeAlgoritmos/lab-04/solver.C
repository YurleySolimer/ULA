
# include <iostream>
# include <fstream>
# include <tclap/CmdLine.h>
# include <ahSort.H>
# include <tpl_dynSetHash.H>
# include <generate_graph.H>
# include <net.H>

using namespace TCLAP;

bool verbose_mode = true;

# include <solver.H>

Prob_Mat read_probs(istream & in)
{
  double probs[3][4];
  in >> probs[0][0] >> probs[0][1] >> probs[0][2] >> probs[0][3];
  in >> probs[1][0] >> probs[1][1] >> probs[1][2] >> probs[1][3];
  in >> probs[2][0] >> probs[2][1] >> probs[2][2] >> probs[2][3];

  Prob_Mat ret;
  DynList<double> p;

  p.append(probs[0][0]);
  p.append(probs[0][1]);
  p.append(probs[0][2]);
  p.append(probs[0][3]);
  ret.append(DynList<double>(move(p)));

  p.append(probs[1][0]);
  p.append(probs[1][1]);
  p.append(probs[1][2]);
  p.append(probs[1][3]);
  ret.append(DynList<double>(move(p)));

  p.append(probs[2][0]);
  p.append(probs[2][1]);
  p.append(probs[2][2]);
  p.append(probs[2][3]);
  ret.append(DynList<double>(move(p)));

  return ret;
}

tuple<Prob_Mat, Prob_Mat, Prob_Mat> read_prob_mats(const string & filename)
{
  ifstream in(filename);
  Prob_Mat pA = read_probs(in);
  Prob_Mat pB = read_probs(in);
  Prob_Mat pC = read_probs(in);

  return make_tuple(move(pA), move(pB), move(pC));
}

ostream & operator << (ostream & s, const Prob_Mat & mat)
{
  size_t sz = mat.foldl<size_t>(0, [] (size_t acu, const DynList<double> & l)
    {
      return std::max(acu, l.foldl<size_t>(0, [] (size_t a, double d)
                              {
				return std::max(a, to_str(d).size());
			      }));
    });

  mat.for_each([sz, &s] (const DynList<double> & l)
    {
      l.for_each([sz, &s] (double d)
		 {
		   const string str = to_str(d);
		   s << string(sz - str.size() + 1, ' ') << str;
		 });
      s << endl;
    });

  return s;
}


DynList<Course> read_courses(istream & in)
{
  if (verbose_mode)
    cout << "Reading courses ..." << endl;
  DynList<Course> courses;

  size_t n;
  in >> n;
  if (verbose_mode)
    cout << n << endl;

  for (size_t i = 0; i < n; ++i)
    {
      Course course;
      in >> course.id >> course.cap >> course.cost;

      if (verbose_mode)
	cout << course.id << " " << course.cap << " " << course.cost << endl;

      courses.append(course);
    }

  if (verbose_mode)
    cout << "Courses reading done!" << endl << endl;

  return courses;
}

DynList<Student> read_students(istream & in)
{
  if (verbose_mode)
    cout << "Reading students ..." << endl;

  DynList<Student> st_list;

  size_t n;
  in >> n;
  if (verbose_mode)
    cout << n << endl;

  for (size_t i = 0; i < n; ++i)
    {
      Student st;
      size_t num_sel_courses;
      in >> st.id >> st.type >> st.num_courses >> num_sel_courses;
      for (size_t k = 0; k < num_sel_courses; ++k)
	{
	  Ulong course_id;
	  in >> course_id;
	  st.selected_courses.append(course_id);
	}

      if (verbose_mode)
	{
	  cout << st.id << " " << st.type << " " << st.num_courses << " "
	       << num_sel_courses;
	  st.selected_courses.for_each([] (Ulong id) { cout << " " << id; });
	  cout << endl;
	}

    st_list.append(st);
    }

  if (verbose_mode)
    cout << "Students reading done!" << endl;

  return st_list;
}


void parse_command_line_and_process(int argc, char ** argv)
{
      // command line parameter parsing specification
  CmdLine cmd("\"Optimal\" matcher between courses and students", ' ', "0.0");
  SwitchArg v("v", "verbose", "verbose mode", false);
  cmd.add(v);
  vector<string> names = {"ford-fulkerson", "edmonds-karp", "fifo-preflow",
			  "heap-preflow", "rand-preflow"};
  ValuesConstraint<string> algos = names;
  ValueArg<string> algo("a", "algo-type", "Maximum flow algorithm", false,
			"ford-fulkerson", &algos);
  cmd.add(algo);
  ValueArg<double> it("i", "it-factor", "iteration factor for cycle searching",
		      false, 0.4, "Iteration factor for cycle searching");
  cmd.add(it);
  ValueArg<size_t> step("s", "step", "step increase", false, 100,
			"step increase for negative cycle searching");
  cmd.add(step);
  ValueArg<string> filename("f", "filename", "file where are probs", true,
			    "", "file name where are the probabilities");
  cmd.add(filename);
  ValueArg<long> cost("c", "cost", "cost by student", false, 1000,
		      "Cost by student");
  cmd.add(cost);
  SwitchArg p("p", "print-parameters", "print all parameters and exit", false);
  cmd.add(p);
  SwitchArg graphviz_cap("g", "graphviz-cap",
			 "print graphviz draw of initial network", false);
  cmd.add(graphviz_cap);
  SwitchArg graphviz_op("G", "graphviz-op",
			"print graphviz draw of optimized network", false);
  cmd.add(graphviz_op);

  cmd.parse(argc, argv);

  const double & factor = it.getValue();
  if (factor <= 0.0 or factor > 1.0)
    {
      cout << "Error: iteration factor must be between 0 and 1.0" << endl;
      exit(0);
    }

  tuple<Prob_Mat, Prob_Mat, Prob_Mat> probs =
    read_prob_mats(filename.getValue());

  if (p.getValue())
    {
      cout << "Algorithm        = " << algo.getValue() << endl
	   << "Cost by student  = " << cost.getValue() << endl
	   << "Iteration factor = " << it.getValue() << endl
	   << "Iteration step   = " << step.getValue() << endl
	   << "A" << endl
	   << get<0>(probs) << endl
	   << "B" << endl
	   << get<1>(probs) << endl
	   << "C" <<  endl
	   << get<2>(probs) << endl;
      exit(0);
    }

  verbose_mode = v.getValue();

  Solver solver(move(get<0>(probs)), move(get<1>(probs)), move(get<2>(probs)),
		read_courses(cin), read_students(cin), cost.getValue());

  solver.build_net();

  if (graphviz_cap.getValue())
    {
      solver.graphviz_cap(cout);
      exit(0);
    }

  const string & str = algo.getValue();
  if (str == "ford-fulkerson")
    solver.
      assign<Max_Flow_Min_Cost_By_Cycle_Canceling, Ford_Fulkerson_Maximum_Flow>
      (factor, step.getValue());
  else if (str == "edmonds-karp")
    solver.
      assign<Max_Flow_Min_Cost_By_Cycle_Canceling, Edmonds_Karp_Maximum_Flow>
      (factor, step.getValue());
  else if (str == "fifo-preflow")
    solver.
      assign<Max_Flow_Min_Cost_By_Cycle_Canceling, Fifo_Preflow_Maximum_Flow>
      (factor, step.getValue());
  else if (str == "heap-preflow")
    solver.
      assign<Max_Flow_Min_Cost_By_Cycle_Canceling, Heap_Preflow_Maximum_Flow>
      (factor, step.getValue());
  else if (str == "rand-preflow")
    solver.
      assign<Max_Flow_Min_Cost_By_Cycle_Canceling, Random_Preflow_Maximum_Flow>
      (factor, step.getValue());
  else
    {
      cout << "Error: invalid " << str << " algorithm" << endl;
      exit(0);
    }

  if (graphviz_op.getValue())
    solver.graphviz_flow(cout);


  if (verbose_mode)
    {
      cout << "Courses " << endl;
      solver.get_courses().for_each([] (const Course & c)
       {
	 cout << "Course " << c.id << endl;
   c.student_list.for_each([] (Ulong id)
				 {
				   cout << "    " << id << endl;
				 });
       });

      cout << "Students" << endl;
      solver.get_students().for_each([] (const Student & s)
        {
	  cout << "Student " << s.id << " (" << s.num_courses << ")" << endl
	       << "  Selection: ";
	  s.selected_courses.for_each([] (Ulong id) { cout << " " << id; });
	  cout << endl;
	  if (s.assigned_courses.is_empty())
	    cout << "NOT COURSES" << endl;
	  else
	    {
	      cout << "  Assigned:  ";
	      s.assigned_courses.for_each([] (Ulong id) { cout << " " << id; });
	      cout << endl;
	    }
	});
    }


    ///////////////////////////
      //Mis pruebas

    try
      {
        cout << "Estudante id: 4100 " ;Student st = solver.get_student(4100);
      }
    catch (exception & e)
      {
        cout << e.what() << endl;
      }
      cout << endl;

      ///////////////////////////
      //Mis pruebas
      cout << endl << "Busqueda de Cursos" << endl;
      cout << "Curso id: " << (solver.get_course(0)).id << endl;
      cout << "Curso id: " << (solver.get_course(1)).id << endl;
      cout << "Curso id: " << (solver.get_course(2)).id << endl;

      ///////////////////////////
        //Mis pruebas

      try
        {
          cout << "Curso id: -1 " ;Course st = solver.get_course(-1);
        }
      catch (exception & e)
        {
          cout << e.what() << endl;
        }
        cout << endl;

        ///////////////////////////
      ///////////////////////////
      DynList<tuple<Ulong, double>> l = solver.students_expected_payment();
      if (!l.is_empty()){
      for (DynList<tuple<Ulong, double>> :: iterator it(l);
            it.has_curr() ; it.next())
        {
          cout << "Student id: " << get<0>(it.get_curr())
               << "  , expected_cost: " << get<1>(it.get_curr()) << endl;
        }}


        DynList<tuple<Ulong, double, double>> lcourse = solver.course_payment();
        if (!l.is_empty()){
        for (DynList<tuple<Ulong, double, double>> :: iterator it(lcourse);
              it.has_curr() ; it.next())
          {
            cout << "Course id: " << get<0>(it.get_curr())
                 << "  , ganancia: " << get<1>(it.get_curr())
                 << "  , cost esperado: " << get<2>(it.get_curr()) << endl;
          }}
/////////////////////7
//////////


  cout << endl
       << "Computed with " << str << " algorithm" << endl << endl
       << "    Total flow = " << solver.get_net().flow_value() << endl
       << "    Total cost = " << solver.get_net().flow_cost() << endl;
}

int main(int argc, char ** argv)
{
  parse_command_line_and_process(argc, argv);
}