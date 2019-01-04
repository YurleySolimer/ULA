#include "buffer.h"


Buffer::Buffer(sc_module_name nm):sc_module(nm){
	}
void Buffer::comprobar(){
		
		if(c_in.read()==0)
			s_out.write(s_in.read());

		else

			s_out.write("ZZZZZZZZ");
}
