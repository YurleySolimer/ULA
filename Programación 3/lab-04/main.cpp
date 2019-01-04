#include <dictnode.H> 
#include <string.h>  //Libreria utilizada para manejar cadenas de caracteres
#include <stdlib.h>  //Libreria utilizada para generar numeros y letras aleatorias(Funcion srand)
#include <time.h> 

	Tree_Node<char> *t= NULL;


int main()
{	


	Cnode r('-');
	const char *z="hola";


	char c= 'a'+ ( rand() % ('z' - 'a') ) ;
	Cnode d(c); 
	cout<<get<0>(r.search_prefix("à"))->get_key();
	cout<<",";
	cout<<get<1>(r.search_prefix("à"));
	cout<<" "<<endl<<endl;

	Cnode *ptr=&d;
	r.insert_child(ptr);
	char c1= 'a'+ ( rand() % ('z' - 'a') ) ;
	Cnode l(c1); 
	Cnode *ptr2=&l;
	r.insert_child(ptr2);
	char c2= 'a'+ ( rand() % ('z' - 'a') ) ;
	Cnode q(c2); 
	Cnode *ptr3=&q;
	r.insert_child(ptr3);
	char c3= 'a'+ ( rand() % ('z' - 'a') ) ;
	Cnode h(c3); 
	Cnode *ptr4=&h;

	cout<<"Lista de nodos hijos de la raiz: "<<endl;
	r.children().for_each([] (Cnode * elem)   
   {
			char c=elem->symbol();					
			cout<<c;
			cout<<" ";
	});
	cout<<" "<<endl<<endl;
	int j=0;
	while(j<3) {
	char c= 'a'+ ( rand() % ('z' - 'a') ) ;
	Cnode b(c); 
	Cnode *ptr1=&b;
	d.insert_child(ptr1);	
	j++;
}
	cout<<"Lista de nodos hijos de : "<<c<<endl;
	d.children().for_each([] (Cnode * elem)   
   {
			char c=elem->symbol();					
			cout<<c;
			cout<<" ";
	});
	cout<<" "<<endl<<endl;
	int k=0;
	while(k<2) {
	char c= 'a'+ ( rand() % ('z' - 'a') ) ;
	Cnode o(c); 
	Cnode *ptr6=&o;
	l.insert_child(ptr6);	
	k++;

	l.insert_child(ptr4);
	}
	cout<<"Lista de nodos hijos de : "<<c1<<endl;
	l.children().for_each([] (Cnode * elem)   
   {
			char c=elem->symbol();					
			cout<<c;
			cout<<" ";
	});
	cout<<" "<<endl<<endl;

	int x=0;
	while(x<2) {
	char c= 'a'+ ( rand() % ('z' - 'a') ) ;
	Cnode f(c); 
	Cnode *ptr8=&f;
	h.insert_child(ptr8);	
	x++;
}
	cout<<"Lista de nodos hijos de : "<<c3<<endl;
	h.children().for_each([] (Cnode * elem)   
   {
			char c=elem->symbol();					
			cout<<c;
			cout<<" ";
	});
	cout<<" "<<endl<<endl;

	int w=0;
	while(w<3) {
	char c= 'a'+ ( rand() % ('z' - 'a') ) ;
	Cnode y(c); 
	Cnode *ptr7=&y;
	q.insert_child(ptr7);	
	w++;
}
	cout<<"Lista de nodos hijos de : "<<c2<<endl;
	q.children().for_each([] (Cnode * elem)   
   {
			char c=elem->symbol();					
			cout<<c;
			cout<<" ";
	});


	cout<<" "<<endl<<endl;

	d.mark_end_word();
	l.mark_end_word();
	h.mark_end_word();
	q.mark_end_word();
	tuple<const Cnode* , const char*> t;
	
	cout<<get<0>(r.search_prefix("casa"))->get_key();
	cout<<",";
	cout<<get<1>(r.search_prefix("casa"));
	cout<<" "<<endl<<endl;

	cout<<get<0>(r.search_prefix("pva"))->get_key();
	cout<<",";
	cout<<get<1>(r.search_prefix("pva"));
	cout<<" "<<endl<<endl;


	cout<<get<0>(r.search_prefix("ika"))->get_key();
	cout<<",";
	cout<<get<1>(r.search_prefix("ika"));
	cout<<" "<<endl<<endl;

		r.children();
    r.to_str();
    r.is_end_word();
    r.search_child('c');
    r.search_prefix("hola"); 
    r.contains("hola");
    r.words();
    r.clon();

	char c, c1, c2, c3, c4,c5;


	cout<<r.search_child('k')<<endl;	
	cin>>c;
	Cnode a(c); 
	Cnode *ptr=&a;
	cout<<"Nodo insertado: ";
	cout<<r.insert_child(ptr)<<endl;
	
	cin>>c1;
	Cnode b(c1);
	Cnode *ptr1=&b;
	cout<<"Nodo insertado: ";	
	cout<<r.insert_child(ptr1)<<endl;

	cin>>c2;
	Cnode d(c2);
	Cnode *ptr2=&d;
	cout<<"Nodo insertado: ";	
	cout<<r.insert_child(ptr2)->symbol()<<endl;
	

	cin>>c3;
	Cnode e(c3);
	Cnode *ptr3=&e;
	cout<<"Nodo insertado: ";	
	cout<<r.insert_child(ptr3)->symbol()<<endl;

	cout<<"Lista de nodos hijos: ";
	r.children().for_each([] (Cnode * elem)   
   {
			char c=elem->symbol();					
			cout<<c;
			cout<<" ";
	});	
	cout<<endl;

	cout<<"Busqueda de: ";
	cout<<c<<endl;
	cout<<"Encontrado: ";
	cout<<r.search_child(c)->symbol()<<endl;
	cout<<r.search_child('k')->symbol()<<endl;
	cout<<"Busqueda de: ";
	cout<<c3<<endl;
	cout<<"Encontrado: "<<endl;
	cout<<r.search_child(c3)->symbol()<<endl;
	
	cout<<"Marcado de palabra: "<<endl<<endl;
	if(r.is_end_word());
		cout<<"fin de palabra"<<endl<<endl;	
	if(r.mark_end_word())
		cout<<"palabra marcada"<<endl;

	//Hijos de a
	int i=0;
	while(i<20) {
	char a='*';
	i++;
	cout<<a;}

	cout<<endl;
	cin>>c4;
	Cnode f(c4);
	Cnode *ptr4=&f;
	cout<<"Nodo insertado: ";	
	cout<<a.insert_child(ptr4)->symbol()<<endl;

	cin>>c5;
	Cnode g(c5);
	Cnode *ptr5=&g;
	cout<<"Nodo insertado: ";	
	cout<<a.insert_child(ptr5)->symbol()<<endl;

	cout<<"Lista de nodos hijos de a: ";
	a.children().for_each([] (Cnode * elem)   
   {
			char c=elem->symbol();					
			cout<<c;
			cout<<" ";
	});	
	cout<<endl;
	cout<<"Busqueda de: ";
	cout<<c<<endl;
	cout<<"Encontrado: ";
	cout<<a.search_child(c)->symbol()<<endl;
	cout<<a.search_child('k')->symbol()<<endl;
	cout<<"Busqueda de: ";
	cout<<c5<<endl;
	cout<<"Encontrado: "<<endl;
	cout<<a.search_child(c5)->symbol()<<endl;
	
	cout<<"Marcado de palabra: "<<endl<<endl;
	if(a.is_end_word());
		cout<<"fin de palabra"<<endl<<endl;	
	if(a.mark_end_word())
		cout<<"palabra marcada"<<endl;


}
