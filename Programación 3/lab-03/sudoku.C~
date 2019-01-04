//Yurley Solimer Barrios Monsalve
//C.I. 22.986.327

//1- retorna true si los elementos en la lista no están repetidos
bool check(const DynList<int> & l)
	{
		if (l.size()!=9)
			return false;
		int val=1;
		l.for_each([&val] (int elem)
			{
				val=val*elem;
			}); 
		if(val==362880)
			 return true;
		return false;
	}


//2- retorna l1 == l2
bool lists_equal (const DynList<int> & l1, const DynList<int> & l2)
	{
		int igual=0;
		DynList<int>::Iterator it1(l1);
		DynList<int>::Iterator it2(l2);
		if(l1.is_empty()&&l2.is_empty())
			return true;
		if(l1.size()!=l2.size())
			return false;
		for(it1,it2;it1.has_current(),it2.has_current();it1.next(),it2.next())
			{
				if(it1.get_current()==it2.get_current())
					igual++;
			} 
		if(igual==l1.size() && igual==l2.size())
			 return true;
		return false;
	}


//3- retorna una lista con el contenido de la fila row del sudoku
DynList<int> sudoku_row(const Sudoku & sudoku, int row)
	{
		DynList<int> l;
		for(int j=0; j<9; j++) 
			l.append(sudoku.nth(row).nth(j));
	  return (l);
	}


//4- retorna una lista con el contenido de la columna col del sudoku
DynList<int> sudoku_col(const Sudoku & sudoku, int col)
	{
	  	DynList<int> l;
		for(int j=0; j<9; j++)
			l.append(sudoku.nth(j).nth(col));
		return (l);

	}


//5- retorna true si la fila row del sudoku es válida; o sea que no tiene
// números repetidos y están en [1,9] 
bool check_row(const Sudoku & sudoku, int row)
	{
		DynList<int> l=sudoku_row(sudoku, row);
		if (check(l)) 
			return true;
		return false;
	}


//6- retorna true si todas las filas del sudoku son válidas
bool check_rows(const Sudoku & sudoku)
	{
		int val=0;	
		for(int j=0; j<9; j++) 
			{	
				if(check_row(sudoku, j))
					val++;
			}
		if(val==9) 
			return true; 
		return false;
	}
 

//7- retorna true si la columna col del sudoku es válida; o sea que
// no tiene números repetidos y están en [1,9]
bool check_col(const Sudoku & sudoku, int col)
	{
  	DynList<int> l=sudoku_col(sudoku, col);
		if (check(l)) 
			return true;
		return false;
	}


//8- retorna true si todas las columnas del sudoku son válidas
bool check_cols(const Sudoku & sudoku)
	{
		int val=0;	
		for(int j=0; j<9; j++) 
			{	
				if(check_col(sudoku, j))
					val++;
			}
		if(val==9) 
			return true; 
		return false;
	}


//9- retorna una lista con el contenido del cuadrado 3x3 que comienza en
// la fila row y columna col
DynList<int> sudoku_square(const Sudoku & sudoku, int row, int col)
	{
		DynList<int> l;
		for(int j=0;j<=2;j++) 
			{
				l.append(sudoku.nth(row).nth(col));
				col++;
			}
		for(int j=0;j<=2;j++) 
			{
				l.append(sudoku.nth(row+1).nth(col-3));
				col++;
			}
		for(int j=0;j<=2;j++) 
			{
				l.append(sudoku.nth(row+2).nth(col-6));
				col++;
			}
	return (l);
	}


//10- retorna true si el cudrado 3x3 de de la coordenada row,col es válido;
// o sea que no tiene números repetidos y están en [1,9]
bool check_square(const Sudoku & sudoku, int row, int col)
	{
		DynList<int> l= sudoku_square(sudoku, row, col);
		if (check(l)) 
			return true;
		return false;
	}


//11- retorna true si todos los cudrados 3x3 del sudoku son válidos
bool check_squares(const Sudoku & sudoku)
	{
		int val=0;
		int row;
		int col;	
		for(int j=0, col=0; j<3;j++)	
			{
				row=0;
				if(check_square(sudoku, row , col))
					{
						col=col+3;
						val++;
					}
			}
		for(int j=0, col=0; j<3;j++)	
			{
				row=3;
				if(check_square(sudoku, row , col))
					{
						col=col+3;
						val++;
					}
			}
		for(int j=0, col=0; j<3;j++)	
			{
				row=6;
				if(check_square(sudoku, row , col))
					{
						col=col+3;
						val++;
					}
			}
	if(val==9) 
		return true; 
	return false;
	}


//12- retorna true si el sudoku, probablemente no resuelto, está bien
// formado; es decir, tiene nueve filas, todas las filas (tienen nueve
// elementos) y los elementos se encuentran en [0,9] donde sólo es
// posible que esté repetido el cero
bool check_well_formed(const Sudoku & sudoku)
	{
		int i=0;
		sudoku.for_each([&i] (const DynList<int> & fila)
		 {
				int j=0;
				fila.for_each([&j] (int col)
				{	
					j++;
				});
				if(j==9)
				 i++;
		 });
	
	if (i!=9)
		return false; 
	int cero=0;
	for(int row=0;row<9;row++) 
			{
				DynList<int> l=sudoku_row(sudoku, row);
				DynList<int>::Iterator it(l);
				while(it.has_current()) 
					{
						if(it.get_current()==0)
							cero++;
					it.next();
					}
				if(cero==0){
					if(!check(l))
						return false; 
					}
			}
	return true;
	}


//13- retorna true si el sudoku es válido
bool check_sudoku(const Sudoku & sudoku)
	{ 
		if (check_rows(sudoku) && check_cols(sudoku) && check_squares(sudoku))
			return true;
		return false;
	}


//14 retorna true si la lista l contiene a val
bool list_has(const DynList<int> & l, int val) 
	{
	   int si=0;
  		l.for_each([&val, &si] (int elem)
		{    
			if(elem==val)		
				si++;
		});	
	if(si>0)
		return true;
	return false;
}


//15- retorna true si los sudokus s1 y s2 son identicos.
bool are_equals(const Sudoku & s1, const Sudoku & s2)
	{
		if(check_well_formed(s1) && !check_well_formed(s2))
			return false;
		if(!check_well_formed(s1) && check_well_formed(s2))
			return false;

		int bien=0;
		for(int row=0;row<9;row++)
		{
			DynList<int> l1;
			DynList<int> l2;
			l1.append(sudoku_row(s1,row));
			l2.append(sudoku_row(s2,row));
			if(lists_equal(l1,l2))
				bien++;
		}
	if(bien==9)
		 return true;
	else
		return false;
	}


//16- retorna true si es posible añadir val a la lista l sin que l devenga invalida.

bool ok_for_list(const DynList<int> & l, int val)
	{
		int si=0;
	  	if(list_has(l,val))
			si++;
		if (si==0)
			return true;
		return false;
	}


//17- retorna true si es posible poner val en la fila row del sudoku
bool ok_for_row(const Sudoku & sudoku, int row, int val)
	{
		DynList<int> l=(sudoku_row(sudoku,row));
		if(ok_for_list(l,val))
			return true;
		return false;
	}

//18- retorna true si es posible poner val en la columna col del sudoku
bool ok_for_col(const Sudoku & sudoku, int col, int val)
	{
  		DynList<int> l=(sudoku_col(sudoku,col));
		if(ok_for_list(l,val))
			return true;
		return false;
	}

//19- retorna true si es posible poner val en el cuadrado del sudoku
// situado en la coordenada row,col
bool ok_for_square(const Sudoku & sudoku, int row, int col, int val)
	{
		DynList<int> l=(sudoku_square(sudoku,row,col));
		if(ok_for_list(l,val))
			return true;
		return false;
	}

//20- Retorna las coordenadas de inicio del cudrado sudoku correspondiente
// a la celda row,col
tuple<int, int> cell_to_square(int row, int col)
{
	int i;
	int j;
		if(row>=0 && row <=2){
			if(col>=0 && col <=2){
				i=0;
				j=0;
			}
			if(col>2 && col <=5){
				i=0;
				j=3;
			}
			if(col>5 && col <=8){
				i=0;
				j=6;
			}

		}

	if(row>2 && row <=5){
			if(col>=0 && col <=2){
				i=3;
				j=0;
			}
			if(col>2 && col <=5){
				i=3;
				j=3;
			}
			if(col>5 && col <=8){
				i=3;
				j=6;
			}

		}

	if(row>5 && row <=8){
			if(col>=0 && col <=2){
				i=6;
				j=0;
			}
			if(col>2 && col <=5){
				i=6;
				j=3;
			}
			if(col>5 && col <=8){
				i=6;
				j=6;
			}

		}

  return make_tuple(i,j);
}

//21- retorna true si es posible poner en la celda row,col del sudoku el
// valor val
bool ok_for_cell(const Sudoku & sudoku, int row, int col, int val)
	{
		DynList<int> l1,l2,l3;
		
		l1.append(sudoku_square(sudoku, get<0>(cell_to_square(row, col)), get<1>(cell_to_square(row, col))));
		l2.append(sudoku_row(sudoku,row));
		l3.append(sudoku_col(sudoku,col));
		if(ok_for_list(l1,val) && ok_for_list(l2,val) && ok_for_list(l3,val))
			return true;
		return false;
	}

//22- Dado un sudoku, retorna una lista de valores válidos que se pueden
// poner en la celda row,col
DynList<int> avail_numbers(const Sudoku & sudoku, int row, int col)
	{
		DynList<int> list;
		for(int val=1; val<=9; val++) 
		{
			if(ok_for_cell(sudoku,row,col,val))
				list.append(val);

		}
	
		return list;

	}


//23- retorna la lista de celdas disponibles del sudoku; es decir, las
// celdas con valor 0
Cells avail_cells(const Sudoku & sudoku)
	{
		DynList<tuple<int,int>> l;
		   for(int row=0; row<9; row++) 
			{
				for(int col=0; col<9; col++) 
					{
						if((sudoku.nth(row).nth(col))==0)
							l.append(make_tuple(row,col));
					}
			}

		return (l);
	}

//24- retorna una lista plana de enteros correspondientes a celdas
// disponibles. Las celdas deben estar ordenadas lexicograficamente por
// fila, col; es decir (0,0) < (0,1) pero (1,0) > (0,8)
DynList<int> cells_to_list(const Cells & cells)
	{
		DynList<int> l;
		Cells::Iterator it(cells);
		while (it.has_current())
			{
				auto elem= it.get_current();
				l.append(get<0>(elem));
				l.append(get<1>(elem));
				it.next();
			}
  return (l);
	}

//25 Retorna true si sudoku tiene solución, en cuyo caso la matriz es
// asignada con los valores de solución.
bool solve(Sudoku & sudoku, DynList<Cell> & cells)
{
		Sudoku s1=sudoku;
  		if(!check_well_formed(sudoku))
				return false;
		
		if(check_sudoku(sudoku))
				return true;

		DynList<Cell>::Iterator it1(cells);
		auto tup=it1.get_current();
		auto row=get<0>(tup);
		auto col=get<1>(tup);
		DynList<int> posible=avail_numbers(sudoku, row, col);
		DynList<int>::Iterator it2(posible);
		sudoku.nth(row).nth(col)=it2.get_current();
		if(check_well_formed(sudoku)){
			cells.remove_first();
			solve(sudoku,cells);	}
		else{
			sudoku.nth(row).nth(col)=0;
			cells.remove_first();
			solve(sudoku,cells);	}
}

//26-
Sudoku solve(const Sudoku & sudoku)
{
	 /* if(!check_well_formed(sudoku))
  {}

  try
  {
    check_well_formed(sudoku);
  }
  catch(std::domain_error)
  {
    cerr << "sudoku is not well formed" << endl;
  }
*/

	  return Sudoku();
}
   
