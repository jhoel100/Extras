#include <iostream>

using namespace std;

class SecFrame{
	private:
		double ancho;
		double peralte;
		double Ix;
		double Iz;
		double Iy;
		double Asy;
		double Asz;
	public:
		SecFrame();
		SecFrame(double[8]);
		void parametros();
		double getancho();
		double getperalte();
		void setancho(double);
		void setperalte(double);
		double getIx();
		double getIz();
		double getIy();
		double getAsy();
		double getAsz();
};

SecFrame::SecFrame(){
	ancho=0;
	peralte=0;
	SecFrame::parametros();
}

//corregir los valor de inercias
SecFrame::SecFrame(double informacion[3]){
	ancho=informacion[1];
	peralte=informacion[2];
	Ix=ancho*peralte*peralte*peralte/12;
	Iz=peralte*ancho*ancho*ancho/12;
	Iy=peralte*ancho*ancho*ancho/12;
	Asy=ancho*peralte*0.8333333333333;
	Asz=ancho*peralte*0.8333333333333;
}

void SecFrame::parametros(){
	Ix=ancho*peralte*peralte*peralte/12;
	Iz=peralte*ancho*ancho*ancho/12;
	Iy=peralte*ancho*ancho*ancho/12;
	Asy=ancho*peralte*0.8333333333333;
	Asz=ancho*peralte*0.8333333333333;
}

double SecFrame::getancho(){
	return ancho;
}

double SecFrame::getperalte(){
	return peralte;
}

double SecFrame::getIx(){
	return Ix;
}

double SecFrame::getIz(){
	return Iz;
}

double SecFrame::getIy(){
	return Iy;
}

double SecFrame::getAsy(){
	return Asy;
}

double SecFrame::getAsz(){
	return Asz;
}

void SecFrame::setancho(double s){
	ancho=s;
	parametros();
}

void SecFrame::setperalte(double s){
	peralte=s;
	parametros();
}

