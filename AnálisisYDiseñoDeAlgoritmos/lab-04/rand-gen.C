
# include <gsl/gsl_rng.h>
# include <gsl/gsl_randist.h>
# include <tclap-1.2.1/include/tclap/CmdLine.h>
# include <net.H>

using namespace TCLAP;

DynList<Course> generate_courses(const size_t        n, 
				 const double        cap_lambda,
				 const Ulong         cost_mu,
				 const double        cost_sigma,
				 const unsigned long seed,
				 const size_t        min_cap = 2,
				 const long          min_cost = 1000)
{
  gsl_rng * r = gsl_rng_alloc(gsl_rng_mt19937);
  gsl_rng_set(r, seed);

  DynList<Course> ret;
  for (size_t i = 0; i < n; ++i)
    {
      const size_t cap = max(min_cap, (size_t) gsl_ran_poisson(r, cap_lambda));
      long cost = cost_mu + gsl_ran_gaussian(r, cost_sigma);
      if (cost < min_cost)
	cost = min_cost;
      ret.append(Course(cap, cost));
    }

  gsl_rng_free(r);
  return ret;
}


//                            A    B    C
double student_type_prob[] { 0.1, 0.6, 0.3 };

char sample_student_type(double probs[], gsl_rng * r)
{
  const double sample = gsl_rng_uniform(r);
  if (sample < probs[0])
    return 'A';
  else if (sample < probs[1])
    return 'B';
  else 
    return 'C';
}
      
//                   1    2    3
double prob_A[] = { 0.6, 0.3, 0.1 };
double prob_B[] = { 0.7, 0.2, 0.1 };
double prob_C[] = { 0.9, 0.07, 0.03 };

short sample_num_courses(double probs[], gsl_rng * r)
{
  const double sample = gsl_rng_uniform(r);
  if (sample < probs[0])
    return 1;
  else if (sample < probs[1])
    return 2;
  else 
    return 3;
}

DynList<Student> 
generate_students(const size_t            n, 
		  const size_t            num_potential_courses_lambda,
		  const DynList<Course> & courses_list,
		  unsigned long           seed)
{
  DynArray<Course> courses = courses_list;
  const size_t num_sel_courses = courses.size();

  gsl_rng * r = gsl_rng_alloc(gsl_rng_mt19937);
  gsl_rng_set(r, seed);
  DynList<Student> ret;
  for (size_t i = 0; i < n; ++i)
    {
      char student_type = sample_student_type(student_type_prob, r);
      short num_courses;
      switch (student_type)
	{
	case 'A': num_courses = sample_num_courses(prob_A, r); break;
	case 'B': num_courses = sample_num_courses(prob_B, r); break;
	case 'C': num_courses = sample_num_courses(prob_C, r); break;
	}

      long ncourses = gsl_ran_poisson(r, num_potential_courses_lambda);
      if (ncourses < num_courses)
	ncourses = num_courses;
      else if (ncourses > num_sel_courses)
	ncourses = num_sel_courses;
      DynList<Ulong> selected_courses;
          // select num_courses randomly
      for (short k = 0; k < ncourses; ++k)
	while (true) // select course id without duplications 
	  {
	    const Course & course = 
	      courses(gsl_rng_uniform_int(r, num_sel_courses));
	    if (selected_courses.exists([&course] (Ulong id) 
					{ return course.id == id; }))
	      continue;
	    else
	      {
		selected_courses.append(course.id);
		break;
	      }
	  }
      ret.append(Student(student_type, num_courses, move(selected_courses)));
    }

  gsl_rng_free(r);

  return ret;
}

tuple<size_t, DynList<Course>, size_t, DynList<Student>>
parse_command_line_and_generate(int argc, char ** argv)
{
  CmdLine cmd("Sampler of courses and students", ' ', "0.0");
  ValueArg<size_t> num_courses("n", "num-courses", "number of courses", true,
			       200, "number of courses to be generated");
  cmd.add(num_courses);

  ValueArg<size_t> num_students("m", "num-students", "number of students", true,
				4000, "number of students to be generated");
  cmd.add(num_students);

  ValueArg<unsigned long> seed("s", "seed", "seed", false, 0, 
			       "seed for random number generator");
  cmd.add(seed);

  ValueArg<Ulong> course_cap("c", "cap", "course capacity mean", false, 20,
			     "Poisson mean of course capacity");
  cmd.add(course_cap);

  ValueArg<Ulong> course_cost("C", "cost", "course cost mean", false, 800,
			      "Gaussian mean of course cost");
  cmd.add(course_cost);

  ValueArg<Ulong> course_sigma("S", "sigma", "course cost deviation", false,
			       200, "Gaussian sigma of course cost");
  cmd.add(course_sigma);
  
  ValueArg<size_t> selected_courses("p", "selected-courses", 
				    "number of selected courses of student",
				    false, 4,
				    "Poisson mean number of selected courses");
  cmd.add(selected_courses);

  cmd.parse(argc, argv);

  DynList<Course> courses = 
    generate_courses(num_courses.getValue(), course_cap.getValue(), 
		     course_cost.getValue(), course_sigma.getValue(),
		     seed.getValue());

  DynList<Student> students =
    generate_students(num_students.getValue(), selected_courses.getValue(),
		      courses, seed.getValue());

  return make_tuple(num_courses.getValue(), move(courses), 
		    num_students.getValue(), move(students));
}

int main(int argc, char *argv[])
{
  tuple<size_t, DynList<Course>, size_t, DynList<Student>> sample =
    parse_command_line_and_generate(argc, argv);

  cout << get<0>(sample) << endl;
  get<1>(sample).for_each([] (const Course & c)
    {
      cout << c.id << " " << c.cap << " " << c.cost << endl;
    });

  cout << get<2>(sample) << endl;
  get<3>(sample).for_each([] (const Student & st)
    {
      cout << st.id << " " << st.type << " " << st.num_courses << " "
	   << st.selected_courses.size();
      st.selected_courses.for_each([] (Ulong id) { cout << " " << id; });
      cout << endl;
    });
}

