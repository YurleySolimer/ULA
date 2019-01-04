# ifndef MODULE_H_
# define MODULE_H_
# include<systemc.h>
# include<string>


class SevenSegments:public sc_module{
	public:
		sc_in<sc_uint<4> > x_in;
		sc_out<bool > z_out[7];
		
		SC_CTOR(SevenSegments){
			SC_METHOD(operation);
				sensitive<<x_in;
	
		}

		~SevenSegments(){}

	private:
		void operation(){
		if(x_in.read()==0){
		for(int i=0;i<7;i++){
			if(i!=5)
				z_out[i].write(1);

			else 		
				z_out[i].write(0);
		}
		return;
	}



	else if(x_in.read()==1){
		for(int i=0;i<7;i++){
			if(i==1 or i==2)
				z_out[i].write(1);

			else 		
				z_out[i].write(0);
		}
		return;
	}



	else if(x_in.read()==2){
		for(int i=0;i<7;i++){
			if(i==2 or i==6)
				z_out[i].write(0);

			else 		
				z_out[i].write(1);
		}
		return;
	}




	else if(x_in.read()==3){
		for(int i=0;i<7;i++){
			if(i==4 or i==6)
				z_out[i].write(0);

			else 		
				z_out[i].write(1);
		}
		return;
	}



	else if(x_in.read()==4){
		for(int i=0;i<7;i++){
			if(i==0 or i==3 or i==4)
				z_out[i].write(0);

			else 		
				z_out[i].write(1);
		}
		return;
	}



	else if(x_in.read()==5){
		for(int i=0;i<7;i++){
			if(i==1 or i==4)
				z_out[i].write(0);

			else 		
				z_out[i].write(1);
		}
		return;
	}


	else if(x_in.read()==6){
		for(int i=0;i<7;i++){
			if(i==1)
				z_out[i].write(0);

			else 		
				z_out[i].write(1);
		}
		return;
	}



	else if(x_in.read()==7){
		for(int i=0;i<7;i++){
			if(i==3 or i==4 or i==6)
				z_out[i].write(0);

			else 		
				z_out[i].write(1);
		}
		return;
	}


	else if(x_in.read()==8){
		for(int i=0;i<7;i++)
			z_out[i].write(1);
		return;
	}



	else if(x_in.read()==9){
		for(int i=0;i<7;i++){
			if(i==3 or i==4)
				z_out[i].write(0);

			else 		
				z_out[i].write(1);
		}
		return;
	}




}

};/*end of class SevenSegments*/

#endif/*end of SEVENSEGMENTS_H*/
