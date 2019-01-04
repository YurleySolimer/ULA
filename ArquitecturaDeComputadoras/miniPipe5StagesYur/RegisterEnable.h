# ifndef REGISTER_H
# define REGISTER_H

# include <systemc.h>

///DataType es el tipo de dato que almacenara el registro
template <typename DataType>

class RegisterEnable:public sc_module{
	public:

		///Puerto de reloj 
		sc_in_clk clk_in;
		///Puerto para habilitar escritura
		sc_in<bool> en_in;
		sc1_in<bool> en_in;
		///Puerto de entrada de dato
		sc_in< DataType > data_in;
		sc1_in< DataType > data1_in;
		
		///Puerto de salida de dato
		sc_out< DataType > data_out;
		sc1_out< DataType > data1_out;
		
		///Constructor
		SC_CTOR(RegisterEnable){
			data=0;

			SC_METHOD(readOperation)
				sensitive<<clk_in.pos();

			SC_METHOD(writeOperation)
				sensitive<<clk_in.neg()<<en_in<<data_in;

		}


		///provee informacion para reporte de errores
		virtual const char* kind() const{
			return "RegisterEnable";
		}

	private:
	
		DataType data;

		
		void readOperation(){
				data_out.write(data);
		}


		void writeOperation(){
			if(clk_in.read()== 0 and en_in.read()){
				data=data_in.read();
			}
		}




};

# endif
