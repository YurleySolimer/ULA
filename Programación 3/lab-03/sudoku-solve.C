
# include <cassert>
# include <fstream>
# include <iostream>
# include <sstream>
# include <string>

# include "sudoku.H"

# include "sudoku.C"

Sudoku load_sudoko(istream & in)
{
  Sudoku ret;

  while (not in.eof())
    {
      string line;
      getline(in, line);
      if (in.eof())
	break;

      DynList<int> list;
      istringstream line_stream(line);
      while (not line_stream.eof())
	{
	  int value;
	  if (line_stream >> value)
	    list.append(value);
	}
      ret.append(std::move(list));
    }

  return ret;
}

int main(int argc, char *argv[])
{
  if (argc < 2)
    {
      cout << "sudoku input-file" << endl;
      exit(0);
    }

  ifstream in(argv[1]);
  if (not in)
    {
      cout << "cannot open " << argv[1] << " file" << endl;
      exit(0);
    }

  Sudoku sudoku = load_sudoko(in); 

  print_sudoko(sudoku);
  print_sudoko(solve(sudoku));
      
  return 0;
}
