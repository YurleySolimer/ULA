
# include <tpl_netcost.H>

using Ulong = unsigned long;

using Prob_Mat = DynList<DynList<double>>;

class Uid
{
  static Ulong id_counter;

public:

  Ulong id;

  Uid() : id(id_counter++) { /* empty */ }

  virtual ~Uid() {} // this class is polymorphic
};

struct Course : public Uid
{
  size_t cap; // capacity in number of places
  Ulong cost; // cost by student

  DynList<Ulong> student_list; // to be assigned by system

  Course(const size_t __cap, const Ulong __cost) : cap(__cap), cost(__cost)
  {
    // empty
  }

  Course() {}

  bool operator == (const Course & c) const
  {
    return id == c.id and cap == c.cap and c.cost == c.cost;
  }
};


struct Student : public Uid
{
  char type;          // A: excelent, B: regular, C: not very good
  short num_courses; // number of courses that this student wants to take
  DynList<Ulong> selected_courses; // student selection 

  DynList<Ulong> assigned_courses; // system assignment

  Student(const char t, const short ncourses, DynList<Ulong> && sel_courses)
    : type(t), num_courses(ncourses), selected_courses(move(sel_courses))
  {
    if (type < 'A' or type > 'C')
      throw std::domain_error("Invalid student type");
    assert(not selected_courses.is_empty());
  }

  Student() {}

  bool operator == (const Student & st) const
  {
    return id == st.id and num_courses == st.num_courses and 
      eq(selected_courses, st.selected_courses);
  }
};


using Node = Net_Cost_Node<Uid*>; // id of instructor or student

using Arc = Net_Cost_Arc<Empty_Class, long>;

using Net = Net_Cost_Graph<Node, Arc>;




