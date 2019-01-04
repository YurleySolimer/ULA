// Yurley Solimer Barrios Monsalve
//C.I. 22.986.327

using Move = tuple<char, Cell>;

using WordMove = tuple<string, DynList<Cell>>;

using Solution = DynList<WordMove>;

// Este es un functor para comparar lexicograficamente WordMove. Sólo
// funciona si tienes aleph-w >= 1.5a.1
struct CmpMove
{
  bool operator () (const WordMove & m1, const WordMove & m2) const
  {
    const string & s1 = get<0>(m1);
    const string & s2 = get<0>(m2);
    if (s1 != s2)
      return s1 < s2;

    return lesser(get<1>(m1), get<1>(m2));
  }
};

struct WordFind
{
  Cnode prefix_root;

  Grid grid;

  Trace trace; 

  Solution sol; 

  FixedStack<Move> stack; 

//*************Constructor****************//
  WordFind(const Grid & g) 
    : prefix_root('-'), grid(g), trace(g.rows(), g.cols()) 
  {
		trace.set_default_initial_value(false);
		stack.pushn(prefix_root.children().size()+2); 
  }

//*************Movimientos legales****************//
  DynList<Cell> legal_moves(const int row, const int col)
  {
		DynList<Cell> l;

		if(col>=grid.cols () || row>=grid.rows ())
			return l;

		if(col<0 || row<0)
			return l;
		
		stack.push(make_tuple(grid.read(row,col), make_tuple(row,col)));
		trace.write(row,col, true);

		if(row==0)
				l.append(make_tuple(grid.rows ()+1,col));
		if(col==0)
					l.append(make_tuple(row,col+1)); 

		if(row==grid.rows ()-1)
		{
			if(trace.read(row-1,col)==false)
				l.append(make_tuple(row-1,col));
		}
		if(col==grid.cols ()-1)
		{
			if(trace.read(row,col-1)==false)
				l.append(make_tuple(row,col-1));
		}

		if(row>0 && row<grid.rows ()-1)
		{
			if(trace.read(row-1,col)==true)
				l.append(make_tuple(row+1,col));
			else
			{
					l.append(make_tuple(row-1,col));
					l.append(make_tuple(row+1,col));
			}
		}
		if(col>0 && col<grid.cols ()-1)
		{
			if(trace.read(row,col-1)==true)
				l.append(make_tuple(row,col+1));
			else
			{
					l.append(make_tuple(row,col-1));
					l.append(make_tuple(row,col+1));
			}
		}

    return l;
  }

  // *****Calcular la palabra de la pila****//
  void extract_word_from_stack()
  {
	/*	FixedStack<Move> stack2;
		stack2=stack;

		FixedStack<Move> stack3;
		stack3=stack;

		DynList<Cell> celdas;
		string p;
		int i=0;

		if(!stack2.is_empty()) 
		{
			while(i<=stack2.size()-1)
			{
				p[i]=get<0>(stack2.pop()); 
		
				celdas.insert(get<1>(stack3.pop()));
				i++;
			}
		}


	sol.append(make_tuple( p,celdas));*/
	}

	//**************************Busqueda de palabra*********************************//
  void search(const int row, const int col, Cnode * root)
  {
	 	if(legal_moves(row, col).is_empty())
			return;

		if(root->children().is_empty())
			return;

		if(root->search_child(grid.read(row,col)) !=nullptr && root->search_child(grid.read(row,col))->is_end_word())
			extract_word_from_stack();	
		return;
		
		DynList<Cell> l= legal_moves(row,col);
		DynList<Cell>::Iterator it(l);
         
		while(it.has_current())
		{
			search(get<0>(it.get_current()), get<1>(it.get_current()), (root->search_child(grid.read(row,col))));  
			it.next();   
		} 
  }

	//******************Solucion******************//
  Solution solve(istream & in)
  {
		string word;
		do
			prefix_root.insert_word(word);
		while (in>>word);

		for(int row=0; row<=grid.rows()-1 ;row++)
		{
			for(int col=0; col<=grid.cols()-1;col++)
				search(row,col,&prefix_root);
		}
			
		quicksort(sol, CmpMove());

    return sol;
  }

	//******************Destructor******************//
  ~WordFind()
  {
		prefix_root.destroy();
		stack.empty();
		sol.empty();
		trace.set_dimension(0,0);
		grid.set_dimension(0,0);
	}  
};
