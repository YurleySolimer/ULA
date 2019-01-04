/* Integrantes:
	Barrios Monsalve Yurley Solimer - C.I: 22.986.327
	Cadenas Torres Lesly Micaela - C.I: 21.185.223
*/

//1. Busqueda de un elemento modulo x
tuple<long, bool> find_mod_x(const DynList<long> & l, long x)
{
	DynList<long> l2;
	long i =0;
	l.for_each([&x, &l2] (const long elem){    
		if(elem % x == 0) 
			l2.insert(elem);
		});
	l2.for_each([&x, &i] (const long elem){    
		if(elem % x == 0) 
			i=elem;
		});
	if(i==0)
		return (make_tuple(0, false)); 
	return (make_tuple(i, true)); 	 

}

//2. Lista de elementos divididos entre x
DynList<long> divide_by_x(const DynList<long> & l, long x)
{

	DynList<long> l2;
	l.for_each([&l2, &x] (const long elem){
		l2.append(elem/x);
	}); 
  	
	return DynList<long>(l2);
}

//3. División de los elementos de una lista entre x
DynList<long> & transform_divided_by_x(DynList<long> & l, long x)
{

	DynList<long> l2;
	l.for_each([&x, &l2] (long elem){
		l2.insert(elem/x);
	});
	
	l2.for_each([&l] (long elem){
		l.remove();
	});

	l2.for_each([&l] (long elem){
		l.insert(elem);
	});

  return l;
}

//4. Lista de elementos divisibles entre x
DynList<long> divisible_by_x(const DynList<long> & l, long x)
{
	
	DynList<long> l2;
	DynList<long>::Iterator it(l);
	
	while(it.has_curr()){
		if(it.get_curr() % x == 0) 
			l2.append(it.get_curr());
		it.next(); 
    	}

	return DynList<long>(l2);
}

//5. ¿Son todos divisibles entre x?
bool all_are_divisible_by_x(const DynList<long> & l, long x)
{

	int j=0;
	int i=0;
	l.for_each([&x, &j, &i] (const long elem){
		if(elem % x == 0) {
			i++;		
		}
		j++;	                   
	}); 

	if(j==i) 
 		return true;
	else
		return false;
}

//6. ¿Hay un elemento divisible entre x?
bool exist_divisible_by_x(const DynList<long> & l, long x)
{

	long i=0;
	l.for_each([&x, &i] (const long elem){
		if(elem % x == 0) 
			i++;
		});		

	if(i>=1)
		return true;
	else
		return false;	 
}

//7. Suma de todos los elementos
long long sum(const DynList<long> & l)
{
	long suma=0;
	l.for_each([&suma] (const long elem){
		suma=suma+elem;
	}); 
    	
	return suma;
}

//8. Pares de elementos cuya suma es x
DynList<tuple<long, long>> pairs_whose_sum_is_x(const DynList<long> & l1, 
						const DynList<long> & l2,
						const long x)
{
	DynList<tuple<long, long> > laux;
	DynList<long>::Iterator it1(l1);
	DynList<long>::Iterator it2(l2);
	
	while(it1.has_curr() && it2.has_curr() ){
		if(it1.get_curr() + it2.get_curr() == x) {
			laux.append(make_tuple(it1.get_curr(), it2.get_curr()));
		}
		it1.next(); 
		it2.next(); 
    	}

	return DynList<tuple<long, long>>(laux);
}

//9. Lista de múltiplos
DynList<long> multiples_of(const DynList<long> & l, const DynList<long> & mults)
{
	DynList<long> l2;
	
	l.for_each([&l2, &mults] (long elem){
		long i=0;	
		mults.for_each([&l2, &elem, &i] (long mult){
			if(mult>0 && elem>0 && elem%mult==0) 
				while(i<1){
					l2.append(elem);
				i++;}
			}); 
	}); 

	return DynList<long>(l2);
}

//10. Valores contenidos en un rango
DynList<tuple<long, size_t>> range_pos(const DynList<long> & ll, long l, long r)
{
	size_t j=0;
	DynList<tuple<long, size_t>> l2;
	ll.for_each([&j, &l2, &r, &l] (long elem){
		if((elem >= l) && (r >= elem)){
			l2.append(make_tuple(elem, j));
			}
		j++;
	}); 
	
	return DynList<tuple<long, size_t>>(l2);
}
