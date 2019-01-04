//Alumna: Yurley Barrios  C.I. 22.986.327

#include <tpl_dynArray.H>
# include <tuple>
using namespace std;
using namespace Aleph;


//Pivote del elemento mas a la izquierda - pivote=l
tuple<size_t, size_t>
select_left(const DynArray<long> & a, const long l, const long r)
{
	return make_tuple(l, 0);
}

//Particion - rutina que particiona el arreglo a entre los indices l y r
QSinfo qs_partition(DynArray<long> & a, const long l, const long r, 
		   		Sel_Pivot sel_pivot)
{
     long i=l+1; //comienza en el elemento siguiente al pivote
	long j=l+1;//comienza en el elemento siguiente al pivote
	long ip=get<0>(sel_pivot(a,l,r)); //indice del pivote 
	long vp = a[ip];//valor del pivote
	size_t sw=0; //contador de swaps
	size_t cm=get<1>(sel_pivot(a,l,r)); //contador de comparaciones       

	//particion cuando el pivote esta al lado izquierdo	
	if (ip!=l) {
		swap(a(ip),a(l));
		ip=0;
	}
		while(j<=r) {
			cm++;
	
			if (a(j)<vp) {       
				swap(a(i),a(j)); 
				i++; 
				sw++;
			}
			j++;
		}	
	
		if(j=r+1) {
			swap(a(l), a(i-1)); //temina la particion
			ip=i-1;
			sw++; }
	

	 //Del lado izquierdo del arreglo deben estar los elementos menores que el pivote
	//Del lado derecho los elementos iguales o mayores que el pivote

	return make_tuple(ip, cm, sw);
}

//Quicksort - ordena el arreglo usando una particion y una seleccion de pivote
tuple<size_t, size_t>
qs(DynArray<long> & a, const long l, const long r, Sel_Pivot sel_pivot)
{
	long i=0;
	
	if(l>=r)
		return make_tuple(0,0);
	
	auto ip=get<0>(qs_partition(a,l,r,sel_pivot)); //indice del pivote de acuerdo a la particion
	//ordeno primero la particion de menor tamaño
	auto cm= get<1>(qs_partition(a,l,r,sel_pivot));
	auto sw= get<2>(qs_partition(a,l,r,sel_pivot));

	if(ip-1-l<=r-ip) {
		qs(a,l,ip-1,sel_pivot);
		qs(a,ip+1,r,sel_pivot);
		} 
	if(ip-1-l>r-ip){ 
		qs(a,ip+1,r,sel_pivot);
		qs(a,l,ip-1,sel_pivot); 
		}

	if(i>=1){
		cm=cm+get<0>(qs(a,l,r,sel_pivot));
		sw=sw+get<1>(qs(a,l,r,sel_pivot)); 
		return make_tuple(cm,sw); }
	i++;
	return make_tuple(cm,sw);
}

//Pivote del elemento mas a la derecha - pivote=r
tuple<size_t, size_t> 
select_right(const DynArray<long> & a, const long l, const long r)
{
  	long p=r; //Seleccion del pivote

	return make_tuple(r, 0);
}


//Pivote seleccionado al azar
/* Selección del pivote al azar. ATENCIÓN, para hacer el problema
   objetivamente reproducible, debes hacer exactamente un sorteo. Si
   haces más tus resultados podrán ser diferentes y tendrás mal este
   ejercicio 
*/
   
tuple<size_t,size_t> 
select_random(const DynArray<long> &, const long l, const long r)
{
	auto vp=gsl_rng_uniform_int(g,r-l+1);

	return make_tuple(vp, 0);
}


//Pivote como la mediana de los extremos
/* Selección del pivote la mediana entre los extremos l, r y (l+r)/2 
 */
tuple<size_t, size_t>
select_median(const DynArray<long> & a, const long l, const long r)
{
	long cm=0; //contador de comparaciones
	long m=((l+r)/2);
	const long & x = a(l);
	const long & y = a(m);
	const long & z = a(r);
	long median; //variable para guardar la mediana
	long sw; //contador de intercambios (swaps)
	long vp; //variable para guardar el pivote
	long ip; //variable para guardar el indice del pivote

	if (x < y) {
		if (y < z) {
			median = y; }
		else {
			if (x < z) {
				cm++;
				median = z; }
			else{
				cm++;
				median = x;}
		}
	}
	else if (x < z) {
		median = x; }
	
	else{
		if (y < z) {
			median = z;
			cm++; }
		else{
		median = y;
		cm++;}
	}

	vp=median;
	if(median==x){
		ip=l;
		cm++;}
		
	if(median==y){
		ip=m;
		cm++;}
	
	if(median==z){
		ip=r;
		cm++;}
		
	if(r-l<=2){
		return make_tuple(r,cm);
		cm++;}
	
	return make_tuple(ip,cm);
}


//Pivote como la mediana de Num Samples elementos al azar
/* 
   Selección del pivote entre la mediana de Num_Samples elementos
   seleccionados al azar.

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
  
	long k;
	DynArray<tuple<long,long>> samples;
	DynArray<tuple<long,long>> aux;
	for(long i=0; i<=Num_Samples; i++) {
		k=gsl_rng_uniform_int(g,r-l+1);
		tuple<long, long>;
		samples[i]=make_tuple(a(k),k);  }
	

	 */
  

return make_tuple(0, 0);
}
