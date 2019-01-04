#include <iostream>
#include <htlist.H>
#include <string.h>


using namespace std;

using namespace Aleph;


class Student
{

	public:		
		int id;
		char name[31];
		int sec;

		Student()
		{
			id= -1;			
			strcpy(name, "empty");
			sec = 0;
		}
		Student(const int Id, const char *Name, int Sec)
		{
			id= Id;
			strcpy(name, Name);	
			sec = Sec;
		}
		Student(const Student &rhs)
		{
			id= rhs.id;
			strcpy(name, rhs.name);
			sec = rhs.sec;
		} 

};

int main()
{
	DynList<Student> students;
	
	int op;

	do
	{
		//show menu
		cin>>op;
		switch(op)
		{
			case 0:		
			{
				cout<<"Agregar."<<endl;

				Student aux;
				//ingrese el id
				cin>>aux.id;
				cin.ignore();
				//ingrese el nombre
				cin.getline(aux.name, 31);
				//ingrese la seccion
				cin>>aux.sec;

				students.append(aux);
			}		
			break;
			case 1:
			{
				cout << "Mostrar seccion unida." << endl;
				int a, b;

				cin >> a;
				cin >> b;

				auto listA = students.filter([&a](const Student &st)
					{
						if(st.sec == a)
							return true;
						return false;
					});

				auto listB = students.filter([&b](const Student &st)
					{
						if(st.sec == b)
							return true;
						return false;
					});

				listA.concat(listB);

				listA.for_each([](const Student &st)
					{
						cout << "ID: " << st.id << endl;
						cout << "\tNombre: " << st.name << endl;
						cout << "\tSeccion: " << st.sec << endl;
					});

			}
			break;
			case 2:
			{
				cout<< "mostrar invertida" <<endl;

				auto aux= students;
				aux.reverse();
				aux.for_each([](const Student &st)
					{
						cout << "ID: " << st.id << endl;
						cout << "\tNombre: " << st.name << endl;
						cout << "\tSeccion: " << st.sec << endl;
					});
			}
			break;
			case 3:
			{
				cout<<"picar desde un alumno."<<endl;
				int id;
				cin>>id;
				auto aux= students;

				DynList<Student>::Iterator it(aux);
				
				for(; it.has_curr(); it.next())				
					if(it.get_curr().id == id)											
						break;

				DynList<Student> res;
				aux.cut_list(it, res);

				cout<<"part 1:\n";
				aux.for_each([](const Student &st)
					{
						cout << "ID: " << st.id << endl;
						cout << "\tNombre: " << st.name << endl;
						cout << "\tSeccion: " << st.sec << endl;
					});
				cout<<"part 2:\n";

				res.for_each([](const Student &st)
					{
						cout << "ID: " << st.id << endl;
						cout << "\tNombre: " << st.name << endl;
						cout << "\tSeccion: " << st.sec << endl;
					});
			}
			break;
			case 4:
			{

				cout<< "mostrar todo"<<endl;

				students.for_each([](const Student &st)
					{
						cout << "ID: " << st.id << endl;
						cout << "\tNombre: " << st.name << endl;
						cout << "\tSeccion: " << st.sec << endl;
					});

			}
			break;
			case -1:
			break;
			default:
				cout<<"Invalid option";
			break;
		}


	}while(op != -1);


	cout << "Saliendo.." << endl;








	return 0;
}



