#include <iostream>

using namespace std;

class Punto3D{
	private:
		double x;
		double y;
		double z;
	public:
		Punto3D();
		Punto3D(double[4]);
		void setx(double);
		void sety(double);
		void setz(double);
		double getx();
		double gety();
		double getz();
};

Punto3D::Punto3D(){
	x=0;
	y=0;
	z=0;
}

Punto3D::Punto3D(double informacion[4]){
	x=informacion[1];
	y=informacion[2];
	z=informacion[3];
}

void Punto3D::setx(double s){
	x=s;
}

void Punto3D::sety(double s){
	y=s;
}

void Punto3D::setz(double s){
	z=s;
}

double Punto3D::getx(){
	return x;
}

double Punto3D::gety(){
	return y;
}

double Punto3D::getz(){
	return z;
}

