#include <iostream>

using namespace std;

class CarFrame{
	private:
		int numero;
		double FX1;
		double FY1;
		double FZ1;
		double MX1;
		double MY1;
		double MZ1;
		double FX2;
		double FY2;
		double FZ2;
		double MX2;
		double MY2;
		double MZ2;
	public:
		CarFrame();
		CarFrame(double[14]);
		int getnumero();
		void setnumero(int);

		double get1fx();
		double get1fy();
		double get1fz();
		double get1mx();
		double get1my();
		double get1mz();
		double get2fx();
		double get2fy();
		double get2fz();
		double get2mx();
		double get2my();
		double get2mz();

		void set1fx(double);
		void set1fy(double);
		void set1fz(double);
		void set1mx(double);
		void set1my(double);
		void set1mz(double);
		void set2fx(double);
		void set2fy(double);
		void set2fz(double);
		void set2mx(double);
		void set2my(double);
		void set2mz(double);
};

CarFrame::CarFrame(){
	numero=0;
	FX1=0;
	FY1=0;
	FZ1=0;
	MX1=0;
	MY1=0;
	MZ1=0;
	FX2=0;
	FY2=0;
	FZ2=0;
	MX2=0;
	MY2=0;
	MZ2=0;
}

CarFrame::CarFrame(double informacion[14]){
	numero=(int)informacion[1];
	FX1=informacion[2];
	FY1=informacion[3];
	FZ1=informacion[4];
	MX1=informacion[5];
	MY1=informacion[6];
	MZ1=informacion[7];
	FX2=informacion[8];
	FY2=informacion[9];
	FZ2=informacion[10];
	MX2=informacion[11];
	MY2=informacion[12];
	MZ2=informacion[13];

}

double CarFrame::get1fx(){
	return FX1;
}

double CarFrame::get1fy(){
	return FY1;
}

double CarFrame::get1fz(){
	return FZ1;
}

double CarFrame::get1mx(){
	return MX1;
}

double CarFrame::get1my(){
	return MY1;
}

double CarFrame::get1mz(){
	return MZ1;
}

double CarFrame::get2fx(){
	return FX2;
}

double CarFrame::get2fy(){
	return FY2;
}

double CarFrame::get2fz(){
	return FZ2;
}

double CarFrame::get2mx(){
	return MX2;
}

double CarFrame::get2my(){
	return MY2;
}

double CarFrame::get2mz(){
	return MZ2;
}

int CarFrame::getnumero(){
	return numero;
}

void CarFrame::setnumero(int s){
	numero=s;
}

void CarFrame::set1fx(double s){
	FX1=s;
}

void CarFrame::set1fy(double s){
	FY1=s;
}

void CarFrame::set1fz(double s){
	FZ1=s;
}

void CarFrame::set1mx(double s){
	MX1=s;
}

void CarFrame::set1my(double s){
	MY1=s;
}

void CarFrame::set1mz(double s){
	MZ1=s;
}

void CarFrame::set2fx(double s){
	FX2=s;
}

void CarFrame::set2fy(double s){
	FY2=s;
}

void CarFrame::set2fz(double s){
	FZ2=s;
}

void CarFrame::set2mx(double s){
	MX2=s;
}

void CarFrame::set2my(double s){
	MY2=s;
}

void CarFrame::set2mz(double s){
	MZ2=s;
}

