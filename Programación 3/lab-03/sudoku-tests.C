
# include <cassert>
# include <fstream>
# include <iostream>
# include <sstream>
# include <string>

# include <ahSort.H>

# include "sudoku.H"
# include "sudoku.C"

using namespace std;
using namespace Aleph;

Sudoku ill_sudoku = {{5,3,4,6,7,8,9,1,2},
		     {6,7,2,1,9,5,3,4,8},
		     {1,9,8,3,4,2,5,6,7},
		     {8,5,9,7,6,1,4,2,3},
		     {4,2,6,8,5,3,7,9},  // <---
		     {7,1,3,9,2,4,8,5,6},
		     {9,6,1,5,3,7,2,8,4},
		     {2,8,7,4,1,9,6,3,5},
		     {3,4,5,2,8,6,1,7,9}};

Sudoku good_sudoku = {{5,3,4,6,7,8,9,1,2},
		            {6,7,2,1,9,5,3,4,8},
		            {1,9,8,3,4,2,5,6,7},
		            {8,5,9,7,6,1,4,2,3},
		            {4,2,6,8,5,3,7,9,1},
		            {7,1,3,9,2,4,8,5,6},
		            {9,6,1,5,3,7,2,8,4},
		            {2,8,7,4,1,9,6,3,5},
		            {3,4,5,2,8,6,1,7,9}};

Sudoku bad_sudoku = {{5,3,4,6,7,8,9,1,2},
		           {6,7,2,1,9,5,3,4,8},
		           {1,9,8,3,4,2,5,6,7},
		           {8,5,9,7,6,1,4,2,3},
		           {4,2,6,8,5,3,7,9,1},
		           {7,1,3,9,2,7,8,5,6},
		           {9,6,1,5,3,4,2,8,4},
		           {2,8,7,4,1,9,6,3,5},
		           {3,4,5,2,8,6,1,9,2}}; 

Sudoku easy_sudoku = {{9,1,0,7,0,0,0,0,0},
		     				 {0,3,2,6,0,9,0,8,0},
						    {0,0,7,0,8,0,9,0,0},
				  	       {0,8,6,0,3,0,1,7,0},
		                {3,0,0,0,0,0,0,0,6},
		  				    {0,5,1,0,2,0,8,4,0},
		    			    {0,0,9,0,5,0,3,0,0},
		      		    {0,2,0,3,0,1,4,9,0},
		     				 {0,0,0,0,0,2,0,6,1}};

Sudoku medium_sudoku = {{0,3,0,0,0,0,1,5,2},
			{0,0,1,4,0,2,0,9,3},
			{0,0,0,1,0,0,0,0,6},
			{5,7,6,0,0,4,0,0,0},
			{0,0,0,0,0,0,0,0,0},
			{0,0,0,3,0,0,9,2,7},
			{7,0,0,0,0,9,0,0,0},
			{3,6,0,8,0,1,5,0,0},
			{9,1,4,0,0,0,0,3,0}};

Sudoku hard_sudoku = {{7,0,3,1,6,0,0,0,0},
		      {0,0,9,0,8,0,0,0,1},
		      {0,4,0,3,0,0,0,0,7},
		      {0,0,0,0,0,4,0,9,0},
		      {5,0,4,0,0,0,7,0,8},
		      {0,9,0,8,0,0,0,0,0},
		      {9,0,0,0,0,1,0,2,0},
		      {4,0,0,0,5,0,6,0,0},
		      {0,0,0,0,4,9,1,0,5}};

Sudoku devil_sudoku = {{0,0,2,0,0,0,0,0,0},
		       {1,7,4,0,0,8,0,0,0},
		       {0,0,0,0,0,0,2,3,1},
		       {0,0,5,2,1,3,0,6,0},
		       {0,0,0,0,0,0,0,0,0},
		       {0,2,0,6,9,4,1,0,0},
		       {6,9,8,0,0,0,0,0,0},
		       {0,0,0,7,0,0,9,4,6},
		       {0,0,0,0,0,0,3,0,0}};

void tests()
{
  // Descomenta estos asertos en la medida en que vayas programando 

 const Sudoku easy_sol = {{9,1,8,7,4,5,6,3,2},
                           {5,3,2,6,1,9,7,8,4},
                           {6,4,7,2,8,3,9,1,5},
                           {2,8,6,5,3,4,1,7,9},
                           {3,9,4,1,7,8,2,5,6},
                           {7,5,1,9,2,6,8,4,3},
                           {1,6,9,4,5,7,3,2,8},
                           {8,2,5,3,6,1,4,9,7},
			  						 {4,7,3,8,9,2,5,6,1}};

  const Sudoku medium_sol = {{4,3,7,9,8,6,1,5,2},
                            {6,5,1,4,7,2,8,9,3},
                            {8,2,9,1,5,3,7,4,6},
                            {5,7,6,2,9,4,3,8,1},
                            {2,9,3,7,1,8,4,6,5},
                            {1,4,8,3,6,5,9,2,7},
                            {7,8,5,6,3,9,2,1,4},
                            {3,6,2,8,4,1,5,7,9},
                            {9,1,4,5,2,7,6,3,8}};
  const Sudoku hard_sol = {{7,8,3,1,6,5,9,4,2},
                           {2,5,9,4,8,7,3,6,1},
                           {6,4,1,3,9,2,5,8,7},
                           {8,7,6,5,1,4,2,9,3},
                           {5,3,4,9,2,6,7,1,8},
                           {1,9,2,8,7,3,4,5,6},
                           {9,6,5,7,3,1,8,2,4},
                           {4,1,7,2,5,8,6,3,9},
                           {3,2,8,6,4,9,1,7,5}};
  const Sudoku devil_sol = {{5,3,2,1,6,9,8,7,4},
			    {1,7,4,3,2,8,6,9,5},
			    {8,6,9,5,4,7,2,3,1},
			    {4,8,5,2,1,3,7,6,9},
			    {9,1,6,8,7,5,4,2,3},
			    {3,2,7,6,9,4,1,5,8},
			    {6,9,8,4,3,2,5,1,7},
			    {2,5,3,7,8,1,9,4,6},
			    {7,4,1,9,5,6,3,8,2}};

  const Sudoku bad_easy_sol = {{9,1,8,7,4,5,6,3,2},
                               {5,3,2,6,1,9,7,8,4},
                               {6,4,7,2,8,3,9,1,5},
                               {2,8,6,5,3,4,1,7,9},
                               {3,9,4,1,7,8,2,5,6},
                               {7,5,1,9,2,6,8,4,3},
                               {1,6,9,4,5,7,3,2,8},
                               {8,2,5,3,6,1,4,9,7},
                               {4,7,3,8,9,2,5,1,6}};
  const Sudoku bad_medium_sol = {{4,3,7,9,8,6,1,5,2},
				 {6,5,1,4,7,2,8,9,3},
				 {8,2,9,1,5,3,7,4,6},
				 {5,7,6,2,9,4,3,8,1},
				 {2,9,3,7,1,8,4,6,5},
				 {1,4,8,3,6,5,9,2,7},
				 {7,8,5,6,3,9,2,1,4},
				 {3,6,2,8,4,1,5,7,9},
				 {9,1,4,5,7,2,6,3,8}};
  const Sudoku bad_hard_sol = {{7,8,3,1,6,5,9,4,2},
			       {2,5,9,4,8,7,3,6,1},
			       {6,4,1,3,9,2,5,8,7},
			       {8,7,6,5,1,4,2,9,3},
			       {5,3,4,9,2,6,7,1,8},
			       {1,9,2,8,7,3,4,5,6},
			       {9,6,5,7,3,1,8,2,4},
			       {4,1,7,2,5,8,6,3,9},
			       {3,2,8,6,4,9,7,1,5}};
  const Sudoku bad_devil_sol = {{5,3,2,1,6,9,8,7,4},
				{1,7,4,3,2,8,6,9,5},
				{8,6,9,5,4,7,2,3,1},
				{4,8,5,2,1,3,7,6,9},
				{9,1,6,8,7,5,4,2,3},
				{3,2,7,6,9,4,1,5,8},
				{6,9,8,4,3,2,5,1,7},
				{2,5,3,7,8,1,3,4,6},
				{7,4,1,9,5,6,9,8,2}};
  

  assert(not check({0,1,2,3,4,5,6,7,8}));
  cout << "paso" << endl;
  assert(not check({}));
  cout << "paso" << endl;
  assert(not check({1,3,2,4,5}));
  cout << "paso" << endl;
  assert(not check({1,2,3,4,5,6,7,8}));
  cout << "paso" << endl;
  assert(not check({1,2,3,4,5,6,7,8,3}));
  cout << "paso" << endl;
  assert(not check({1,2,3,4,5,6,7,8,10}));
  cout << "paso" << endl;
  assert(not check({1,2,3,0,5,6,7,8,9}));
  cout << "paso" << endl;
  assert(check({1,2,3,4,5,6,7,8,9}));
  cout << "paso" << endl;
  assert(not check({1,3,5,7,9,2,4,6,8,1,1}));
  cout << "paso" << endl;
  cout << "numeros iguales pasado" << endl<<endl;


  assert(lists_equal(sudoku_row(good_sudoku, 0), {5,3,4,6,7,8,9,1,2}));
  cout << "paso" << endl;
  assert(lists_equal(sudoku_row(good_sudoku, 8), {3,4,5,2,8,6,1,7,9}));
  cout << "paso" << endl;
  assert(not lists_equal(sudoku_row(good_sudoku, 8), {3,4,5,2,8,6,1,7,0}));
  cout << "paso" << endl;
  cout << "fila paso" << endl<<endl;

 
  assert(lists_equal(sudoku_col(good_sudoku, 0), {5,6,1,8,4,7,9,2,3}));
  cout << "paso" << endl;
  assert(lists_equal(sudoku_col(good_sudoku, 8), {2,8,7,3,1,6,4,5,9}));
  cout << "paso" << endl;
  assert(not lists_equal(sudoku_col(good_sudoku, 8), {2,8,7,3,1,6,3,0,9}));
  cout << "paso" << endl;
  cout << "columna paso" << endl<<endl;


  assert(check_rows(good_sudoku));
  cout << "paso" << endl;
  assert(not check_rows(bad_sudoku));
  cout << "paso" << endl;
  cout << "verifica fila paso" << endl<<endl;

  assert(check_cols(good_sudoku));
  cout << "paso" << endl;
  assert(not check_cols(bad_sudoku));
  cout << "paso" << endl;
  cout << "verifica columna paso" << endl<<endl;

  assert(lists_equal(sudoku_square(good_sudoku, 0, 0), {5,3,4,6,7,2,1,9,8}));
  cout << "paso" << endl;
  assert(lists_equal(sudoku_square(good_sudoku, 3, 0), {8,5,9,4,2,6,7,1,3}));
  cout << "paso" << endl;
  assert(lists_equal(sudoku_square(good_sudoku, 3, 3), {7,6,1,8,5,3,9,2,4}));
  cout << "paso" << endl;
  assert(lists_equal(sudoku_square(good_sudoku, 6, 6), {2,8,4,6,3,5,1,7,9}));
  cout << "paso" << endl;
  assert(!lists_equal(sudoku_square(good_sudoku, 6, 6), {2,8,4,6,3,5,1,9,7}));
  cout << "paso" << endl;
  assert(!lists_equal(sudoku_square(good_sudoku, 0, 0), {5,3,4,6,7,1,2,9,8}));
  cout << "paso" << endl;
  assert(!lists_equal(sudoku_square(good_sudoku, 3, 0), {8,5,9,4,6,2,7,1,3}));
  cout << "paso" << endl;
  assert(!lists_equal(sudoku_square(good_sudoku, 3, 3), {7,6,1,8,5,9,3,2,4}));
  cout << "paso" << endl;
  cout << "Cuadrado 3x3 paso" << endl<<endl;

  assert(check_square(good_sudoku, 0, 0));
  cout << "paso" << endl;
  assert(check_square(good_sudoku, 0, 3));
  cout << "paso" << endl;
  assert(check_square(good_sudoku, 0, 6));
  cout << "paso" << endl;
  assert(check_square(good_sudoku, 3, 0));
  cout << "paso" << endl;
  assert(check_square(good_sudoku, 3, 3));
  cout << "paso" << endl;
  assert(check_square(good_sudoku, 3, 6));
  cout << "paso" << endl;
  assert(check_square(good_sudoku, 6, 0));
  cout << "paso" << endl;
  assert(check_square(good_sudoku, 6, 3));
  cout << "paso" << endl;
  assert(check_square(good_sudoku, 6, 6));
  cout << "paso" << endl;
  assert(!check_square(bad_sudoku, 6, 6));
  cout << "paso" << endl;
  cout << "Verifica cuadrado 3x3 paso" << endl<<endl;

  assert(check_squares(good_sudoku));
  cout << "paso" << endl;
  assert(not check_squares(bad_sudoku));
  cout << "paso" << endl;
  cout << "Verifica todos los cuadrados 3x3 paso" << endl<<endl;

  assert(not check_well_formed(ill_sudoku));
  cout << "paso" << endl;
  assert(not check_well_formed(bad_sudoku));
  cout << "paso" << endl;
  assert(check_well_formed(good_sudoku));
  cout << "paso" << endl;
  assert(check_well_formed(easy_sudoku));
  cout << "paso" << endl;
  assert(check_well_formed(medium_sudoku));
  cout << "paso" << endl;
  assert(check_well_formed(hard_sudoku));
  cout << "paso" << endl;
  assert(check_well_formed(devil_sudoku));
  cout << "paso" << endl;
  cout << "sudoku posiblemente resuelto paso" << endl<<endl;


  assert(list_has({1,2,3,4,5,6,7,8,9}, 1));
  cout << "paso" << endl;
  assert(list_has({1,2,3,4,5,6,7,8,9}, 2));
  cout << "paso" << endl;
  assert(list_has({1,2,3,4,5,6,7,8,9}, 9));
  cout << "paso" << endl;
  assert(not list_has({1,2,3,4,5,6,7,8,9}, 10));
  cout << "paso" << endl;
  assert(list_has({0,1,0,0,5,6,0,0,7,8,0}, 6));
  cout << "paso" << endl;
  assert(list_has({0,1,0,0,5,6,0,0,7,8,0}, 0));
  cout << "paso" << endl;
  assert(list_has({0,1,0,0,5,6,0,0,7,8,0}, 1));
  cout << "paso" << endl;
  assert(list_has({0,1,0,0,5,6,0,0,7,8,0}, 8));
  cout << "paso" << endl;
  assert(not list_has({0,1,0,0,5,6,0,0,7,8,0}, 2));
  cout << "paso" << endl;
  assert(not list_has({0,1,0,0,5,6,0,0,7,8,0}, 3));
  cout << "paso" << endl;
  assert(not list_has({0,1,0,0,5,6,0,0,7,8,0}, 4));
  cout << "paso" << endl;
  assert(not list_has({0,1,0,0,5,6,0,0,7,8,0}, 9));
  cout << "paso" << endl;
  cout << "lista l contiene a val paso" << endl<<endl; 

  assert(ok_for_list({0,1,2,3,4,5,6,7,0}, 8));
  cout << "paso" << endl;
  assert(ok_for_list({0,1,2,3,4,5,6,7,0}, 9));
  cout << "paso" << endl;
  assert(not ok_for_list({0,1,2,3,4,5,6,7,0}, 2));
  cout << "paso" << endl;
  assert(not ok_for_list({0,1,2,3,4,5,6,7,0}, 7));
  cout << "paso" << endl;
  cout << "val en l paso" << endl<<endl;

  assert(ok_for_row(easy_sudoku, 0, 3));
  cout << "paso" << endl;
  assert(ok_for_row(hard_sudoku, 0, 8));
  cout << "paso" << endl;
  assert(not ok_for_row(medium_sudoku, 3, 4));
  cout << "paso" << endl;
  cout << "val en row paso" << endl<<endl;

  assert(ok_for_col(devil_sudoku, 2, 7));
  cout << "paso" << endl;
  assert(not ok_for_col(devil_sudoku, 2, 8));
  cout << "paso" << endl;
  assert(ok_for_col(medium_sudoku, 8, 8));
  cout << "paso" << endl;
  assert(not ok_for_col(medium_sudoku, 8, 7));
  cout << "paso" << endl;
  cout << "val en col paso" << endl<<endl;

  assert(ok_for_square(devil_sudoku, 6, 6, 5));
  cout << "paso" << endl;
  assert(not ok_for_square(devil_sudoku, 6, 6, 6));
  cout << "paso" << endl;
  cout << "val en cuadro paso" << endl<<endl;

  assert(check_sudoku(easy_sol));
  cout << "paso" << endl;
  assert(check_sudoku(medium_sol));
  cout << "paso" << endl;
  assert(check_sudoku(hard_sol));
  cout << "paso" << endl;
  assert(check_sudoku(devil_sol));
  cout << "paso" << endl;
  assert(not check_sudoku(bad_easy_sol));
  cout << "paso" << endl;
  assert(not check_sudoku(bad_medium_sol));
  cout << "paso" << endl;
  assert(not check_sudoku(bad_hard_sol));
  cout << "paso" << endl;
  assert(not check_sudoku(bad_devil_sol));
  cout << "paso" << endl;
  cout << "verifica sudoku paso" << endl<<endl;

  assert(cell_to_square(1,1) == make_tuple(0, 0));
  cout << "paso" << endl;
  assert(cell_to_square(8,8) == make_tuple(6,6));
  cout << "paso" << endl;
  assert(cell_to_square(6,6) == make_tuple(6,6));
  cout << "paso" << endl;
  assert(cell_to_square(4,7) == make_tuple(3,6));
  cout << "paso" << endl;
  cout << "coordenadas de inicio paso" << endl<<endl;

  assert(range(0, 8).all([&] (int r) { return check_row(good_sudoku, r); }));
  cout << "paso" << endl;
  assert(range(0, 8).all([&] (int c) { return check_col(good_sudoku, c); }));
  cout << "paso" << endl;
  assert(not range(0, 8).all([&] (int r) { return check_row(bad_sudoku, r); }));
  cout << "paso" << endl;
  assert(not range(0, 8).all([&] (int c) { return check_col(bad_sudoku, c); }));
  cout << "paso" << endl;
  cout << "mas col y row paso" << endl<<endl<<endl;

  

 {
    Sudoku tmp_sudoku = devil_sudoku;

    assert(ok_for_cell(tmp_sudoku, 8, 8, 2));
	 cout << "paso" << endl;
    assert(not ok_for_cell(tmp_sudoku, 8, 8, 9));
	 cout << "paso" << endl;

    tmp_sudoku.nth(8).nth(8) = 2;
    
    assert(ok_for_cell(tmp_sudoku, 8, 7, 5));
 	 cout << "paso" << endl;
    assert(not ok_for_cell(tmp_sudoku, 8, 7, 6));
	 cout << "paso" << endl;
	 cout << "val en celda paso" << endl<<endl;
  }

	assert(lists_equal((avail_numbers(devil_sudoku, 8, 8)), {2, 5, 7, 8}));
  cout << "lista de numeros val en la celda paso" << endl<<endl; 

	avail_cells(devil_sudoku);

  	assert(lists_equal(cells_to_list(avail_cells(devil_sudoku)),
		     {0,0,0,1,0,3,0,4,0,5,0,6,0,7,0,8,1,3,1,4,1,6,1,7,1,8,2,0,
		      2,1,2,2,2,3,2,4,2,5,3,0,3,1,3,6,3,8,4,0,4,1,4,2,4,3,4,4,
		      4,5,4,6,4,7,4,8,5,0,5,2,5,7,5,8,6,3,6,4,6,5,6,6,6,7,6,8,
		      7,0,7,1,7,2,7,4,7,5,8,0,8,1,8,2,8,3,8,4,8,5,8,7,8,8}));

 	 cout << "paso" << endl;
	 cout << "lista de cells en int paso" << endl<<endl;


	assert(are_equals(easy_sudoku, easy_sudoku));
  assert(not are_equals(easy_sol, bad_easy_sol));
		assert(are_equals(medium_sol, medium_sol));
  assert(not are_equals(easy_sol, bad_easy_sol));
  cout << "sudokus iguales paso" << endl<<endl<<endl;


assert(not are_equals(easy_sol, bad_easy_sol));
 	 cout << "paso" << endl;
//  assert(are_equals(solve(easy_sudoku), easy_sol));
 	// cout << "paso" << endl;
  
	 
 // assert(are_equals(solve(medium_sudoku), medium_sol));
 	// cout << "paso" << endl;
  assert(not are_equals(medium_sol, bad_medium_sol));
 	 cout << "paso" << endl;

 // assert(are_equals(solve(hard_sudoku), hard_sol));
 	// cout << "paso" << endl;
  assert(not are_equals(hard_sol, bad_hard_sol));
 	 cout << "paso" << endl;

  assert(are_equals(solve(devil_sudoku), devil_sol));
 	 cout << "paso" << endl;
  assert(not are_equals(devil_sol, bad_devil_sol));
 	 cout << "paso" << endl;
  
  cout << "WOOOOOOW! ... all tests were passed!" << endl; 
  
}


int main(int, char ** )
{
  tests();

  return 0;
}
