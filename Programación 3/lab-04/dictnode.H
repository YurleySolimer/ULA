// Yurley Solimer Barrios Monsalve
// C.I. 22.986.327
//Jorlen Stefanie Osuna Uzcategui
// C.I. 24.196.692

#ifndef DICTNODE_H
#define DICTNODE_H


using namespace Aleph;
using namespace std;


class Cnode: public Tree_Node<char> {

	public:
	 // 1. Constructor
	Cnode(const char c)  
	{
		unsigned char c2=c;
		get_key()=c;
		if((int)c2 >=65 && (int)c2 <=90)	
		c2 = tolower(c2);

		if(c=='á' || c=='ä'|| c=='â' ||  c=='à'||  c=='ã') 
			c2='a'; 
		if(c=='é' || c=='ë' || c=='ê' ||  c=='è') 
			c2='e';
		if(c=='í' || c=='ï'|| c=='î' || c=='ì') 
			c2='i';
		if(c=='ó' || c=='ö'|| c=='ô' || c=='ò'|| c=='õ') 
			c2='o';
		if(c=='ú' ||c=='ü'|| c=='û' || c=='ù') 
			c2='u';
		if(c=='ñ' || c=='Ñ') 
			c2='n';
		if(c=='¢') 
			c2='c';
	
	 
	  switch(c2)
		{
  
				break;
  			case 'a': 
				break;
  			case 'c': 
				break;
  			case 'd': 
				break;
  			case 'e': 
				break;
  			case 'f': 
				break;
  			case 'g': 
				break;
  			case 'h': 
				break;
  			case 'i': 
				break;
  			case 'j': 
				break;
  			case 'k': 
				break;
  			case 'l': 
				break;
  			case 'm': 
				break;
  			case 'n': 
				break;
  			case 'o': 
				break;
  			case 'p': 
				break;
  			case 'q': 
				break;
  			case 'r': 
				break;
  			case 's': 
				break;
  			case 't': 
				break;
  			case 'u': 
				break;
  			case 'v': 
				break;
  			case 'w': 
				break;
  			case 'x': 
				break;
  			case 'y': 
				break;
  			case 'z': 
				break;
  			case '$': 
				break;
			case '-': 
				break;
  			default:
				throw invalid_argument("Invalid character");
		}
		get_key()=c2;	
  }

	// 2. Observador
  char symbol() const noexcept 
	{ 
		if(this==nullptr)
			return '0';		
		return this->get_key() ; //retorna el simbolo almacenado en el nodo this.

	}  

	// 4. Consulta de hijos
  DynList<Cnode*> children() const 
  {

		DynList<Cnode*> l;
		this->for_each_child ([&l] (Tree_Node<char>* p)   
      {
			l.append(new Cnode(p->get_key()));  
							
		});
		
    return l;
  }

  string to_str() const 
  {
    string ret(1, symbol());
    children().for_each([&ret] (Cnode * p) 
	 { 
		ret += "(" + p->to_str() + ")"; 
	 });
    return ret;
  }

private:

  // Este functor es usado por ntreepic(); no lo elimines si deseas
  // invocar a ntreepic()
  struct W
  {
    const string operator () (Cnode * p) const
    {
      char c = p->symbol();
      return c != '$' ? string(1, p->symbol()) : string("\\$");
    }
  };

public:

  void ntreepic(ostream & out) const
  {
   // generate_tree<Cnode, W>(const_cast<Cnode*>(this), out);
  }


	//7.Prueba de palabra
  bool is_end_word() const noexcept
  {
			int i=0;			
			children().for_each([&i] (Cnode * elem)   
			{
				if (elem->symbol() == '$')
					i++;

			});
			if(i>0)
				return true;
			return false;
  }

	//6. Marcado de palabra
	bool mark_end_word()
	{
		
	int i = children().size()-1;
	if(this->is_leaf() && this->get_key()=='-')
	{
				cout<<"no insertado";
		return false;
	}	
	else
	{
		this->children().for_each([] (Cnode * elem)
		{				
			if (elem->is_end_word() == false && elem->is_leaf())
			{
				elem->insert_child(new Cnode ('$'));
				//cout<<"insertado"<<endl;
				return true;
			}
			else
			{
			elem->mark_end_word();
			cout<<"no insertado";

			}

		}); 
	return false;
	}  

}

	//5. Busqueda de hijo
  Cnode * search_child(const char c) const noexcept
  {
		Cnode *e=nullptr;
		if(children().is_empty())
			return e;

		children().for_each([&c, &e] (Cnode * elem)   
     	{
			if (c == elem->symbol()) 
			{
				e=elem;
			}
		});	
			return e;
  }
	//8.Busqueda de prefijo
  // retorna el nodo situado al final del prefijo prefix
  tuple<const Cnode* , const char*> search_prefix(const char * prefix) const
  {
		/*tuple<const Cnode* , const char*> t;
		int j=0;
		auto aux=prefix;
		int i=0;
		int bien=0;
		DynList<Cnode*>::iterator it(this->children());

			if(this->children().is_empty())
				{
					if (this->symbol()==aux[0])
					{	
						int j=0;
						char aux2 [30];					
						while(aux[j]!='\0')
						{
							aux2[j]=aux[j+1];	
							j++;
						}			
						t=make_tuple(this,aux2) ;				
						return t;	
					}

					else 
					{
						t=make_tuple(this,aux);				
						return t;

					}	
				}
			

		while (it.has_current() && aux[0]!='\0')
		{	
				if (it.get_curr()->symbol()==aux[0])
					{
						bien++;					
					
						char aux2 [30];					
						while(aux[j]!='\0')
						{
							aux2[j]=aux[j+1];	
							j++;
						}			
						t=make_tuple(it.get_curr(),aux2) ;
						it.next();
						i++;
					}
				else if (it.get_curr()->symbol()!=aux[0])
					{
						if(bien==0)
						{					
							t=make_tuple(it.get_curr(),aux);				
							it.next();
							i++;
						}
						if (bien>0)
							return t;
					}
			it.next();
		}
		
		return t;
	
		/* lista recursiva de los hjos de this, hasta hoja.. str=prefix, cmparar|*/
		return make_tuple(nullptr,nullptr);
  }


	//9.Busqueda de palabra
  bool contains(const string & word) const noexcept
  {
    return false;
  }


  //3. Insercion de un hijo
  Cnode * insert_child(Cnode * child)  
  {
		bool s;
		if(this->is_end_word()==false)
		{ 
			child = new Cnode(child->get_key());
			if (this->is_leaf() )
			{
				this->insert_rightmost_child(new Tree_Node<char>(child->symbol()));
				//cout<<this->get_right_child()<<endl;
				return (Cnode*)this->get_right_child();
			}	
			else
			{
				if (search_child(child->symbol()) == nullptr)   
     			{		
					this->insert_rightmost_child(new Tree_Node<char>(child->symbol()));
					return (Cnode*)this->get_right_child();
				}
				else
					return nullptr;

			}
		}
		else
			return nullptr;

	}	
	


	//10.Insercion de palabra
  bool insert_word(const string & word) 
  {
    return false;
  }


	//11.Clonacion
  Cnode * clon() const { return nullptr; }

 

	//12.Destructor
 void destroy()
  {
    // programa
  }

  DynArray<string> words() const
  {
    return DynArray<string>();
  }

  void print_words() const
  {
    words().for_each([] (const string & w) { cout << w << endl; });
  }
};
#endif

