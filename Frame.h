#include <iostream>

using namespace std;

class Frame{
	private:
		int nodoinicio;
		int nodofinal;
		double longitud;
		int nromaterial;
		int nroseccion;
		double angulo;
		int tipo;
	public:
		Frame();
		Frame(double[8]);
		int getinicio();
		int getfinal();
		double getlongitud();
		int getnromaterial();
		int getnroseccion();
		double getangulo();
		void setinicio(int);
		void setfinal(int);
		void setlongitud(double);
		void setnromaterial(int);
		void setnroseccion(int);
		void setangulo(double);
};

Frame::Frame(){
	nodoinicio=0;
	nodofinal=0;

	longitud=0;
	nromaterial=0;
	nroseccion=0;
	angulo=0;
	tipo=1;
}

Frame::Frame(double informacion[8]){
	nodoinicio=informacion[1];
	nodofinal=informacion[2];

	longitud=informacion[3];
	nromaterial=informacion[4];
	nroseccion=informacion[5];
	angulo=informacion[6];
	tipo=informacion[7];
}

int Frame::getinicio(){
	return nodoinicio;
}

int Frame::getfinal(){
	return nodofinal;
}

double Frame::getlongitud(){
	return longitud;
}

int Frame::getnromaterial(){
	return nromaterial;
}

int Frame::getnroseccion(){
	return nroseccion;
}

double Frame::getangulo(){
	return angulo;
}

void Frame::setinicio(int s){
	nodoinicio=s;
}

void Frame::setfinal(int s){
	nodofinal=s;
}

void Frame::setlongitud(double s){
	longitud=s;
}

void Frame::setnromaterial(int s){
	nromaterial=s;
}

void Frame::setnroseccion(int s){
	nroseccion=s;
}

void Frame::setangulo(double s){
	angulo=s;
}

