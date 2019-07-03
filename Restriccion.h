#include <iostream>

using namespace std;

class Restriccion{
	private:
		int nodo;
		int grado1;
		int grado2;
		int grado3;
		int grado4;
		int grado5;
		int grado6;
	public:
		Restriccion();
		Restriccion(int[8]);
		int getnodo();
		int getgrado1();
		int getgrado2();
		int getgrado3();
		int getgrado4();
		int getgrado5();
		int getgrado6();
		void setnodo(int);
		void setgrado1(int);
		void setgrado2(int);
		void setgrado3(int);
		void setgrado4(int);
		void setgrado5(int);
		void setgrado6(int);
};

Restriccion::Restriccion(){
	nodo=0;
	grado1=0;
	grado2=0;
	grado3=0;
	grado4=0;
	grado5=0;
	grado6=0;
}

Restriccion::Restriccion(int informacion[8]){
	nodo=informacion[1];
	grado1=informacion[2];
	grado2=informacion[3];
	grado3=informacion[4];
	grado4=informacion[5];
	grado5=informacion[6];
	grado6=informacion[7];
}

int Restriccion::getnodo(){
	return nodo;
}

int Restriccion::getgrado1(){
	return grado1;
}

int Restriccion::getgrado2(){
	return grado2;
}

int Restriccion::getgrado3(){
	return grado3;
}

int Restriccion::getgrado4(){
	return grado4;
}

int Restriccion::getgrado5(){
	return grado5;
}

int Restriccion::getgrado6(){
	return grado6;
}

void Restriccion::setnodo(int s){
	nodo=s;
}

void Restriccion::setgrado1(int s){
	grado1=s;
}

void Restriccion::setgrado2(int s){
	grado2=s;
}

void Restriccion::setgrado3(int s){
	grado3=s;
}

void Restriccion::setgrado4(int s){
	grado4=s;
}

void Restriccion::setgrado5(int s){
	grado5=s;
}

void Restriccion::setgrado6(int s){
	grado6=s;
}
