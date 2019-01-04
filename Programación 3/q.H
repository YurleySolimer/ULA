//Jorlen Osuna. C.I.: 24196692

//using namespace std;
//#include <algorithm>

QSinfo qs_partition(DynArray<long> & a, const long l, const long r, 
		    Sel_Pivot sel_pivot)
{      
	int pivot = get<0>(sel_pivot(a,l,r));
	int i = l;
	int j = r-1;
	size_t comp = 0;
	size_t swp = 0;
	long piv = a[pivot];
 
	swap(a(pivot), a(r));
	swp++;

	while (true){
		while (a(i) < piv){
			i++;			
			comp++;		
		
			if (i == r)
				break;
		}
		
		while (a(j) >= piv){
			j-- ;			
			comp++;
				
			if (j == l)
				break;
		}

		if (i >= j)
			break;

		swap(a(i), a(j));
		swp++;
	}

	swap(a(i), a(r));
	swp++;

  return make_tuple(i, comp, swp);
}


    tuple<size_t, size_t>
qs(DynArray<long> & a, const long l, const long r, Sel_Pivot sel_pivot)
{

	if (l >= r)
		return make_tuple(0, 0);

	size_t pivot = get<0>(qs_partition(a,l,r,sel_pivot));
	
	qs(a,l,pivot-1,sel_pivot);
	qs(a,pivot+1,r,sel_pivot);

  return make_tuple(get<1>(qs_partition(a,l,r,sel_pivot)), get<2>(qs_partition(a,l,r,sel_pivot)));
}


    tuple<size_t, size_t> 
select_left(const DynArray<long> & , const long l, const long r)
{

//	long piv = a[l];

  return make_tuple(l, 0);
}


    tuple<size_t, size_t> 
select_right(const DynArray<long> &, const long, const long r)
{
	
//	long piv = a[r];

  return make_tuple(r, 0);
}


/* Selección del pivote al azar. ATENCIÓN, para hacer el problema
   objetivamente reproducible, debes hacer exactamente un sorteo. Si
   haces más tus resultados podrán ser diferentes y tendrás mal este
   ejercicio 
*/
    tuple<size_t,size_t> 
select_random(const DynArray<long> &, const long l, const long r)
{
//gsl_rng_uniform_int(g, r-l+1)
  return make_tuple(0, 0);
}

/* Selección del pivote la mediana entre los extremos l, r y (l+r)/2 
 */
    tuple<size_t, size_t>
select_median(const DynArray<long> & a, const long l, const long r)
{
/*	long m = (r - l)/2; 

	long & x = a(l);
	long & y = a(m);
	long & z = a(r);
	long median;

	if (x < y){
		if (y < z)
			median = y;
		else {
			if (x < z)
				median = z;
			else
				median = x
		}
	}

	else
		if (x < z)
			median = x
		else {
			if (y < z)
				median = z;
			else
				median = y;
		}

	*/
  return make_tuple(0, 0);
}


/* 
   Selección del pivote entre la mediana de Num_Samples elementos
   seleccionados al azar.

   No olvides contabilizar correctamente la cantidad de comparaciones.

   El valor de retorno es Pair, donde
   first: índice del elemento que fue seleccionado como pivote
   second: cantidad de comparaciones que fue necesario realizar
 */
    tuple<size_t, size_t> 
select_random_median(const DynArray<long> & a, const long l, const long r)
{
  if (r - l + 1 <= Random_Threshold) 
    return select_median(a, l, r); // Si la partición es menor que
				   // Random_Threshold entonces
				   // selecciono pivote entre la media
				   // de sus extremos

  // TODO: a partir de aquí es tu trabajo, el cual se resume en dos
  // fases:

  /*
    1-. Haz Num_Samples sorteos; para ello usa gsl_rng_uniform_int()
        (consulta la doc para conocer su interfaz) y almacena cada
	muestra, junto con su valor dentro del arreglo en samples

    2-. Ordena la muestras puestas en samples mediante el método de
        inserción (que ya está implementado)
  */
  return make_tuple(0, 0);
}
