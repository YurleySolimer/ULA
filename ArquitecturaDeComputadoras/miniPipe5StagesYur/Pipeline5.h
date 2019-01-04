# ifndef PIPELINE5_H
# define PIPELINE5_H

# include "PipeRegisters.h"

class Pipeline5:public sc_module{
	public:

		///Puerto de reloj 
		sc_in_clk clk_in;
		///Puerto en los registros del pipe
		sc_in<bool> en_in;
		sc1_in<bool> en_in;
		///Puerto de entrada de dato0 (en la etapa 1)
		sc_in< bool > data0_in;
		sc1_in< bool > data1_in;
		///Puerto de salida de dato0 (en la etapa 5)
		sc_out< bool > data0_out;
		sc1_out< bool > data1_out;

		
		///Constructor
		SC_CTOR(Pipeline5){

			pipe0=new PipeRegisters("pipe0");
			pipe1=new PipeRegisters("pipe1");
			pipe2=new PipeRegisters("pipe2");
			pipe3=new PipeRegisters("pipe3");
			pipe4=new PipeRegisters("pipe3");

			pipe0->en_in(this->en_in);
			pipe1->en_in(this->en_in);
			pipe2->en_in(this->en_in);
			pipe3->en_in(this->en_in);
			pipe4->en_in(this->en_in);

			pipe0->clk_in(this->clk_in);
			pipe1->clk_in(this->clk_in);
			pipe2->clk_in(this->clk_in);
			pipe3->clk_in(this->clk_in);
			pipe4->clk_in(this->clk_in);

			pipe0->data0_in(this->data0_in);
			pipe0->data0_out(s1_sg);
			
			pipe1->data0_in(s1_sg);
			pipe1->data0_out(s2_sg);
			
			pipe2->data0_in(s2_sg);
			pipe2->data0_out(s3_sg);
			
			pipe3->data0_in(s3_sg);
			pipe3->data0_out(s4_sg);

			pipe4->data0_in(s4_sg);
			pipe4->data0_out(this->data0_out);
		}


		virtual const char* kind() const{
			return "Pipeline5";
		}

	private:
		///puntero a un registro
		PipeRegisters * pipe0,*pipe1,*pipe2,*pipe3, *pipe4;
		sc_signal<bool> s1_sg,s2_sg,s3_sg, s4_sg;



};

# endif
