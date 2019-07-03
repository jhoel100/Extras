#include <iostream>

using namespace std;

class Shell{
	private:
		int nodo1;
		int nodo2;
		int nodo3;
		int nodo4;
		int nroseccion;
		int nromaterial;
	public:
		Shell();
		Shell(double[7]);
		int getnodo1();
		int getnodo2();
		int getnodo3();
		int getnodo4();
		int getnroseccion();
		int getnromaterial();

		void setnodo1(int);
		void setnodo2(int);
		void setnodo3(int);
		void setnodo4(int);
		void setnroseccion(int);
		void setnromaterial(int);
};

Shell::Shell(){
	nodo1=0;
	nodo2=0;
	nodo3=0;
	nodo4=0;
	nroseccion=0;
	nromaterial=0;
}

Shell::Shell(double informacion[7]){
	nodo1=informacion[1];
	nodo2=informacion[2];
	nodo3=informacion[3];
	nodo4=informacion[4];
	nroseccion=informacion[5];
	nromaterial=informacion[6];
}

int Shell::getnodo1(){
	return nodo1;
}

int Shell::getnodo2(){
	return nodo2;
}

int Shell::getnodo3(){
	return nodo3;
}

int Shell::getnodo4(){
	return nodo4;
}

int Shell::getnroseccion(){
	return nroseccion;
}

int Shell::getnromaterial(){
	return nromaterial;
}

void Shell::setnodo1(int s){
	nodo1=s;
}

void Shell::setnodo2(int s){
	nodo2=s;
}

void Shell::setnodo3(int s){
	nodo3=s;
}

void Shell::setnodo4(int s){
	nodo4=s;
}

void Shell::setnroseccion(int s){
	nroseccion=s;
}

void Shell::setnromaterial(int s){
	nromaterial=s;
}

