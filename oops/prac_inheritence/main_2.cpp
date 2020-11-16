#include<bits/stdc++.h>
using namespace std;

class convert{
	protected:
		double val1 , val2 ;
		
		double getinit(){
			return val1 ;
		}
		double getconv(){
			return val2 ;
		}
		
	public : virtual void compute() = 0 ;
	
};

class km_to_m:public convert{
	
	public :
		void compute(){
			cout <<" Enter value in Km to be converted to meters :  " ;
			cin >> val1 ;
			val2 = val1 * 1000 ;
			cout <<getinit()<<" km is "<<getconv()<<" meters\n" ;
		}
	
};

class kg_to_pound:public convert{
	
	public :
		void compute(){
			cout <<" Enter value in Kg to be converted to Pounds :  " ;
			cin >> val1 ;
			val2 = val1 * 2.20462 ;
			cout <<getinit()<<" Kg is "<<getconv()<<" pounds\n" ;
		}
	
};

class miles_to_km:public convert {
	
	public :
		void compute(){
			cout <<" Enter value in Miles to be converted to Kms :  " ;
			cin >> val1 ;
			val2 = val1 * 1.60934 ;
			cout <<getinit()<<" Miles is "<<getconv()<<" Km\n" ;
		}
	
};

int main() {
	convert *p ;
	miles_to_km o1 ;
	p=&o1	;
	p->compute();
	
	km_to_m o2 ;
	p=&o2	;
	p->compute();
	
	kg_to_pound o3 ;
	p=&o3	;
	p->compute();	
}
