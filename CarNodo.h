#include <iostream>

using namespace std;

class CarNodo{
	private:
		int numero;
		double FX1;
		double FY1;
		double FZ1;
		double MX1;
		double MY1;
		double MZ1;
	public:
		CarNodo();
		CarNodo(double[8]);
		double get1fx();
		double get1fy();
		double get1fz();
		double get1mx();
		double get1my();
		double get1mz();

		void set1fx(double);
		void set1fy(double);
		void set1fz(double);
		void set1mx(double);
		void set1my(double);
		void set1mz(double);

		int getnumero();
		void setnumero(int);
};

CarNodo::CarNodo(){
	numero=0;
	FX1=0;
	FY1=0;
	FZ1=0;
	MX1=0;
	MY1=0;
	MZ1=0;
}

CarNodo::CarNodo(double informacion[8]){
	numero=(int)informacion[1];
	FX1=informacion[2];
	FY1=informacion[3];
	FZ1=informacion[4];
	MX1=informacion[5];
	MY1=informacion[6];
	MZ1=informacion[7];
}

double CarNodo::get1fx(){
	return FX1;
}

double CarNodo::get1fy(){
	return FY1;
}

double CarNodo::get1fz(){
	return FZ1;
}

double CarNodo::get1mx(){
	return MX1;
}

double CarNodo::get1my(){
	return MY1;
}

double CarNodo::get1mz(){
	return MZ1;
}

void CarNodo::set1fx(double s){
	FX1=s;
}

void CarNodo::set1fy(double s){
	FY1=s;
}

void CarNodo::set1fz(double s){
	FZ1=s;
}

void CarNodo::set1mx(double s){
	MX1=s;
}

void CarNodo::set1my(double s){
	MY1=s;
}

void CarNodo::set1mz(double s){
	MZ1=s;
}

void CarNodo::setnumero(int s){
	numero=s;
}

int CarNodo::getnumero(){
	return numero;
}

