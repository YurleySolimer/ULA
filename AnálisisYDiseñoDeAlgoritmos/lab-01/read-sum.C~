/* 
	Alumna: Yurley Barrios
	C.I.: 22.986.327
*/


#include <iostream>
#include <fstream>
#include <tpl_dynBinHeap.H>
#include <tpl_binHeap.H>
#include <map>
#include <tpl_arrayHeap.H>

std::pair<SumExtremes, SumExtremes> 
compute_extremes(ifstream & in, const size_t num_lines, const size_t m)
{
  if (m > num_lines)
    {
      cout << "num_lines is smaller than n";
      exit(0);
    }

  // declaracion de estructuras de datos

	DynBinHeap<Ulong, std::greater<Ulong>> heap_smallers;
	U64 sum_line_small=0;

	DynBinHeap<Ulong, std::less<Ulong>> heap_biggers;
	U64 sum_line_big=0;

  // leer los primeros m números, pues antes no se tiene la suma en
  // línea. Guardarlos en las estructuras de datos 

  for (int i = 0; i < m and not in.eof(); ++i) 
    {
      Ulong value;
      in >> value;

		heap_smallers.insert(value);
		sum_line_small=sum_line_small+value;

		heap_biggers.insert(value);
		sum_line_big=sum_line_big+value;

    }

  // continuas leyendo hasta que completes los num_lines o se
  // alcance el fin del archivo

  for (int i = m; i < num_lines and not in.eof(); ++i)
    {
      Ulong value;
      in >> value;

		if(value < heap_smallers.top()) 
			{
				heap_smallers.getMin();
				heap_smallers.insert(value);
				sum_line_small=sum_line_small+value;
			}


		if(value > heap_biggers.top()) 
			{
				heap_biggers.getMin();
				heap_biggers.insert(value);
				sum_line_big=sum_line_big+value;
			}
    }

  
	DynList<Ulong> biggers;
   DynList<Ulong> smallers;

	for (int i = 0; i<m; ++i) 
		{
			smallers.insert(heap_smallers.get());
			biggers.insert(heap_biggers.get());
		}

  //valor de retorno
	std::pair<SumExtremes, SumExtremes> ret_val;

	ret_val.first.extremes=smallers;
	ret_val.first.sum=sum_line_small;

	ret_val.second.extremes=biggers;
	ret_val.second.sum=sum_line_big;


  return ret_val;
}
