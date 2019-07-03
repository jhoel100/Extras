#include <iostream>

using namespace std;

class CarShell{
	private:
		int numero;
		double WX;
		double WY;
		double WZ;
	public:
		CarShell();		
		CarShell(double[5]);
		int getnumero();
		void setnumero(int s);
		double getwx();
		double getwy();
		double getwz();
		void setwx(double);
		void setwy(double);
		void setwz(double);
};

CarShell::CarShell(){
	numero=0;
	WX=0;
	WY=0;
	WZ=0;
}

CarShell::CarShell(double informacion[5]){
	numero=informacion[1];
	WX=informacion[2];
	WY=informacion[3];
	WZ=informacion[4];
}

int CarShell::getnumero(){
	return numero;
}

void CarShell::setnumero(int s){
	numero=s;
}

double CarShell::getwx(){
	return WX;
}

double CarShell::getwy(){
	return WY;
}

double CarShell::getwz(){
	return WZ;
}

void CarShell::setwx(double s){
	WX=s;
}

void CarShell::setwy(double s){
	WY=s;
}

void CarShell::setwz(double s){
	WZ=s;
}

