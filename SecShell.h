#include <iostream>

using namespace std;

class SecShell{
	private:
		double espesor;
		int tipo;
	public:
		SecShell();
		SecShell(double[3]);
		double getespesor();
		int gettipo();
		void setespesor(double);
		void settipo(int);
};

SecShell::SecShell(){
	espesor=0;
	tipo=0;
}

SecShell::SecShell(double informacion[3]){
	espesor=informacion[1];
	tipo=(int)informacion[2];
}

double SecShell::getespesor(){
	return espesor;
}

int SecShell::gettipo(){
	return tipo;
}

void SecShell::setespesor(double s){
	espesor=s;
}

void SecShell::settipo(int s){
	tipo=s;
}

