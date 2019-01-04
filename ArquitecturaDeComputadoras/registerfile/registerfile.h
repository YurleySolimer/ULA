#ifndef REGISTERFILE_H_
#define REGISTERFILE_H_

#include <systemc.h>
#include <cstring>
#include <cstdlib>

	class Registerfile : public sc_module{

public:
//reloj
 sc_in_clk clk;

//write enable
 //sc_in<bool> we;

//direcciones
  sc_in<sc_uint<5> > dirdata_in;

  sc_in<sc_uint<5> > dira_in;

  sc_in<sc_uint<5> > dirb_in;

//  dato a escribir
  sc_in<sc_uint<32> > data_in;

 //registro a
 sc_out<sc_uint<32> > ra_out;

 //registro b
sc_out<sc_uint<32> > rb_out;

	//Constructor
	SC_CTOR(Registerfile){

	SC_METHOD(read);	
	//Sensible al flanco negativo y las direcciones(dir_a,dir_b)
	sensitive<<clk.neg()<<dira_in<<dirb_in;



	SC_METHOD(write);	
	//Sensible al flanco positivo, a dir_wd y a written_data
	sensitive<<clk.pos()<<dirdata_in<<data_in;

for (int i=0;i<32;i++)
	registerfile[i]=i;
}
private:
  sc_uint<32 > registerfile[32];

void  read();
void write();


};

#endif
