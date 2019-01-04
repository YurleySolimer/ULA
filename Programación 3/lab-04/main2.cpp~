#include <dictnode.H>  



	Tree_Node<char> *t= NULL;


int main()
{	

	/*int i=0;
	while(i<50) {
		char c ='á';
	
	cout<<(int)c<<endl;}*/


	char c, c1, c2;
	cin>>c;

	Cnode r('-'),a(c), b(c1), d(c2);
	Cnode *ptr=&a;
	
	r.insert_child(ptr); 
	cout<<r.get_right_child()->get_key()<<endl;
	cout<<r.get_left_child()->get_key()<<endl;

	//r.children();
	cin>>c1;
	Cnode *ptr1=&b;
	
	r.insert_child(ptr1);
	cout<<r.get_right_child()->get_key()<<endl;
	cout<<r.get_left_child()->get_key()<<endl;

//	r.children();
	cin>>c2;
	Cnode *ptr2=&d;
	
	r.insert_child(ptr2);
	cout<<r.get_right_child()->get_key()<<endl;
	//cout<<r.get_left_child()->get_key()<<endl<<endl;

	DynList<Cnode*>::iterator it(r.children());
	while (it.has_curr() and)
	{
		cout<<it.get_curr()->get_key()<<endl<<endl;
	}


	cout<<r.search_child(c)->get_key()<<endl;

	
	








}
