#include"registerfile.h"

void  Registerfile::read(){

	ra_out.write(registerfile[ dira_in.read() ] );
	
	rb_out.write(registerfile[ dirb_in.read() ] );

}



void Registerfile::write(){
	registerfile[dirdata_in.read()]=data_in.read();
	registerfile[0]=0;
}



