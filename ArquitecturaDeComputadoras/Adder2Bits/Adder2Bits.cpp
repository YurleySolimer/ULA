#include"Adder2Bits.h"
void Adder2Bits::split(){
uint2 _x=x_in.read(),_y=y_in.read();
x[0]=_x[0];
x[1]=_x[1];
y[0]=_y[0];
y[1]=_y[1];
c[0].write(c_in.read());
}

void Adder2Bits::join(){
uint2 _z;
_z[0]=z[0];
_z[1]=z[1];

z_out.write(_z);
}

void Adder2Bits::check_carry(){
c_out.write(c[2].read());
}
