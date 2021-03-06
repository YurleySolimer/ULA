# ifndef PIPEREGISTERS_H
# define PIPEREGISTERS_H

# include "RegisterEnable.h"

class PipeRegisters:public sc_module{
	public:

		///Puerto de reloj 
		sc_in_clk clk_in;
		///Puerto en los registros del pipe
		sc_in<bool> en_in;
		///Puerto de entrada de dato0
		sc_in< bool > data0_in;
		sc1_in<bool> data1_in;
		///Puerto de salida de dato0
		sc_out< bool > data0_out;
		sc1_out <bool> data1_out;
		
		///Constructor
		SC_CTOR(PipeRegisters){

			//se reserva memoria para reg0
			reg0=new RegisterEnable<bool>("reg0");
			reg1=new RegisterEnable<bool>("reg1");

			//se hacen las conexiones
			reg0->en_in(this->en_in);
			reg0->clk_in(this->clk_in);
			reg0->data_in(this->data0_in);
			reg0->data_out(data0_out);

			reg1->en_in(this->en_in);
			reg1->clk_in(this->clk_in);
			reg1->data_in(this->data1_in);
			reg1->data_out(data1_out);
		}


		///provee informacion para reporte de errores
		virtual const char* kind() const{
			return "PipeRegisters";
		}

	private:
		///puntero a un registro
		RegisterEnable<bool> * reg0;
		RegisterEnable<bool> * reg1;



};

# endif
