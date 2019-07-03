#include <iostream>
#include "Edificio.h"
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <iomanip>

#define PI 3.14159265

using namespace std;

template<typename t>
void imprimir(vector<t>& vectore,int longitud){
	for(int i=0;i<longitud;i++){
		cout<<i+1<<"_____"<<std::fixed<<std::setprecision(9)<<vectore[i]<<endl;
	}
}

class Matriz{
	public:
		Matriz(int,int);
		~Matriz();
		double** contenido;
		int filas;
		int columnas;
		void imprimir();
		void imprimir2();		
		void parametro();
		void parametro2();
};

Matriz::Matriz(int filas1,int columnas1){
	filas=filas1;
	columnas=columnas1;
	contenido=new double*[filas];
	for(int i=0;i<filas;i++){
		contenido[i]=new double[columnas];
	}

	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			contenido[i][j]=0;
		}
	}
}

Matriz::~Matriz(){
	for(int i=0;i<filas;i++){
		delete [] contenido[i];
	}
	delete [] contenido;
}

void Matriz::imprimir(){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			std::cout<<std::fixed<<std::setprecision(5)<<contenido[i][j]<<"  ";
		}
		std::cout<<endl;
	}
}

void Matriz::imprimir2(){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			std::cout<<std::fixed<<std::setprecision(4)<<contenido[i][j]<<"  ";
		}
		std::cout<<endl;
	}
}

void Matriz::parametro(){
	double sum=0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			sum=sum+contenido[i][j];
		}
	}
	std::cout<<std::fixed<<std::setprecision(5)<<sum<<endl;
}

void Matriz::parametro2(){
	double sum=0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			sum=sum+contenido[i][j];
		}
		std::cout<<i+1<<"_____"<<std::fixed<<std::setprecision(5)<<sum<<endl;
		sum=0;
	}
}

class Bloque{
	public:
		Bloque(int,int,int);
		vector<Matriz> contenido;
		int profundidad;
		int filas;
		int columnas;
		void imprimir();
		void limpiar();
		void parametro();
		void parametro2();
};

Bloque::Bloque(int profundidad1,int filas1,int columnas1){
	filas=filas1;
	columnas=columnas1;
	profundidad=profundidad1;

	contenido.reserve(profundidad);

	for(int i=0;i<profundidad;i++){
		contenido.emplace_back(filas,columnas);
	}
}

void Bloque::imprimir(){
	for(int i=0;i<columnas;i++){
		for(int j=0;j<profundidad;j++){
			for(int k=0;k<filas;k++){
				std::cout<<contenido[j].contenido[k][i]<<" " ;
			}
			std::cout<<endl;
		}
		std::cout<<endl;
	}
}

void Bloque::parametro2(){
	double sum;
	
	for(int i=0;i<profundidad;i++){
		for(int j=0;j<filas;j++){
			for(int k=0;k<columnas;k++){
				sum=sum+contenido[i].contenido[j][k];
			}
			std::cout<<i+1<<"__"<<j+1<<"__"<<std::fixed<<std::setprecision(5)<<sum<<endl;
			sum=0;
		}
		std::cout<<endl;
	}
}

void Bloque::parametro(){
	double sum=0;

	for(int i=0;i<profundidad;i++){
		for(int j=0;j<filas;j++){
			for(int k=0;k<columnas;k++){
				sum=sum+contenido[i].contenido[j][k];
			}
		}
	}
	std::cout<<std::fixed<<std::setprecision(5)<<sum<<endl;
}

void Bloque::limpiar(){
	for(int i=0;i<profundidad;i++){
		for(int j=0;j<filas;j++){
			for(int k=0;k<columnas;k++){
				contenido[i].contenido[j][k]=0;
			}
		}
	}
}

void frame(Matriz& m,Invariante& i,Edificio& e,int numero){
		//numero con indice inicial 0 		e.frames[numero]
		double E=i.materiales[i.frames[numero].getnromaterial()-1].getE();
		double poi=i.materiales[i.frames[numero].getnromaterial()-1].getpoi();
		double G=i.materiales[i.frames[numero].getnromaterial()-1].getG();

		double ancho=e.secframes[i.frames[numero].getnroseccion()-1].getancho();
		double peralte=e.secframes[i.frames[numero].getnroseccion()-1].getperalte();
		double A=ancho*peralte;
		double Ix=e.secframes[i.frames[numero].getnroseccion()-1].getIx();
		double Iz=e.secframes[i.frames[numero].getnroseccion()-1].getIz();
		double Iy=e.secframes[i.frames[numero].getnroseccion()-1].getIy();
		double Asy=e.secframes[i.frames[numero].getnroseccion()-1].getAsy();
		double Asz=e.secframes[i.frames[numero].getnroseccion()-1].getAsz();
		
		double l=i.frames[numero].getlongitud();
		double a=i.frames[numero].getangulo();

		double AY=(12*E*Iz)/(G*Asy*l*l);
		double AZ=(12*E*Iy)/(G*Asz*l*l);

		m.contenido[0][0]=E*A/l;
		m.contenido[6][0]=-E*A/l;

		m.contenido[1][1]=(12*E*Iz)/((1+AY)*l*l*l);
		m.contenido[5][1]=(6*E*Iz)/((1+AY)*l*l);
		m.contenido[7][1]=-(12*E*Iz)/((1+AY)*l*l*l);
		m.contenido[11][1]=(6*E*Iz)/((1+AY)*l*l);

		m.contenido[2][2]=(12*E*Iy)/((1+AZ)*l*l*l);
		m.contenido[4][2]=-(6*E*Iy)/((1+AZ)*l*l);
		m.contenido[8][2]=-(12*E*Iy)/((1+AZ)*l*l*l);
		m.contenido[10][2]=-(6*E*Iy)/((1+AZ)*l*l);
		
		m.contenido[3][3]=G*Ix/l;
		m.contenido[9][3]=-G*Ix/l;

		m.contenido[4][4]=((4+AZ)*E*Iy)/((1+AZ)*l);
		m.contenido[8][4]=(6*E*Iy)/((1+AZ)*l*l);
		m.contenido[10][4]=((2-AZ)*E*Iy)/((1+AZ)*l);
		
		m.contenido[5][5]=((4+AY)*E*Iz)/((1+AY)*l);
		m.contenido[7][5]=-(6*E*Iz)/((1+AY)*l*l);
		m.contenido[11][5]=((2-AY)*E*Iz)/((1+AY)*l);
		
		m.contenido[6][6]=E*A/l;

		m.contenido[7][7]=(12*E*Iz)/((1+AY)*l*l*l);
		m.contenido[11][7]=-(6*E*Iz)/((1+AY)*l*l);

		m.contenido[8][8]=(12*E*Iy)/((1+AZ)*l*l*l);
		m.contenido[10][8]=(6*E*Iy)/((1+AZ)*l*l);

		m.contenido[9][9]=G*Ix/l;

		m.contenido[10][10]=((4+AZ)*E*Iy)/((1+AZ)*l);
		m.contenido[11][11]=((4+AY)*E*Iz)/((1+AY)*l);

		for(int i=0;i<12;i++){
			for(int j=0;j<12;j++){
				m.contenido[i][j]=m.contenido[j][i];
			}
		}

}

void giro(Matriz& m,Invariante& i,Edificio& e,int numero){
		//numero con indice inicial 0 		e.frames[numero]
		double inicio=i.frames[numero].getinicio()-1;
		double fin=i.frames[numero].getfinal()-1;
		double xj=i.coord[inicio].getx();
		double yj=i.coord[inicio].gety();
		double zj=i.coord[inicio].getz();
		double xk=i.coord[fin].getx();
		double yk=i.coord[fin].gety();
		double zk=i.coord[fin].getz();
		double roll=i.frames[numero].getangulo();
		double l=i.frames[numero].getlongitud();

		double cc;
		double c1,c2,c3,dd;

		Matriz aux(3,3);
		
		if(xj==xk && yj==yk){
			if(zj<zk){
				cc=1;
			}
			else{
				cc=-1;
			}
			aux.contenido[0][0]=0;
			aux.contenido[0][1]=0;
			aux.contenido[0][2]=cc;
			aux.contenido[1][0]=cos(roll*PI/180.0);
			aux.contenido[1][1]=cc*sin(roll*PI/180.0);
			aux.contenido[1][2]=0;
			aux.contenido[2][0]=-sin(roll*PI/180.0);
			aux.contenido[2][1]=cc*cos(roll*PI/180.0);
			aux.contenido[2][2]=0;
		}
		else{
			c1=(xk-xj)/l;
			c2=(yk-yj)/l;
			c3=(zk-zj)/l;
			dd=pow((c1*c1+c2*c2),0.5);
			aux.contenido[0][0]=c1;
			aux.contenido[0][1]=c2;
			aux.contenido[0][2]=c3;
			aux.contenido[1][0]=(-c1*c3*cos(roll*PI/180.0)/dd)+(c2*sin(roll*PI/180.0)/dd);
			aux.contenido[1][1]=(-c1*sin(roll*PI/180.0)/dd)-(c2*c3*cos(roll*PI/180.0)/dd);
			aux.contenido[1][2]=(dd*cos(roll*PI/180.0));
			aux.contenido[2][0]=(c1*c3*sin(roll*PI/180.0)/dd)+(c2*cos(roll*PI/180.0)/dd);
			aux.contenido[2][1]=(-c1*cos(roll*PI/180.0)/dd)+(c2*c3*sin(roll*PI/180.0)/dd);
			aux.contenido[2][2]=(-dd*sin(roll*PI/180.0));
		}		
		
		m.contenido[0][0]=aux.contenido[0][0];
		m.contenido[0][1]=aux.contenido[0][1];
		m.contenido[0][2]=aux.contenido[0][2];
		m.contenido[1][0]=aux.contenido[1][0];
		m.contenido[1][1]=aux.contenido[1][1];
		m.contenido[1][2]=aux.contenido[1][2];
		m.contenido[2][0]=aux.contenido[2][0];
		m.contenido[2][1]=aux.contenido[2][1];
		m.contenido[2][2]=aux.contenido[2][2];
		
		m.contenido[3][3]=aux.contenido[0][0];
		m.contenido[3][4]=aux.contenido[0][1];
		m.contenido[3][5]=aux.contenido[0][2];
		m.contenido[4][3]=aux.contenido[1][0];
		m.contenido[4][4]=aux.contenido[1][1];
		m.contenido[4][5]=aux.contenido[1][2];
		m.contenido[5][3]=aux.contenido[2][0];
		m.contenido[5][4]=aux.contenido[2][1];
		m.contenido[5][5]=aux.contenido[2][2];

		m.contenido[6][6]=aux.contenido[0][0];
		m.contenido[6][7]=aux.contenido[0][1];
		m.contenido[6][8]=aux.contenido[0][2];
		m.contenido[7][6]=aux.contenido[1][0];
		m.contenido[7][7]=aux.contenido[1][1];
		m.contenido[7][8]=aux.contenido[1][2];
		m.contenido[8][6]=aux.contenido[2][0];
		m.contenido[8][7]=aux.contenido[2][1];
		m.contenido[8][8]=aux.contenido[2][2];

		m.contenido[9][9]=aux.contenido[0][0];
		m.contenido[9][10]=aux.contenido[0][1];
		m.contenido[9][11]=aux.contenido[0][2];
		m.contenido[10][9]=aux.contenido[1][0];
		m.contenido[10][10]=aux.contenido[1][1];
		m.contenido[10][11]=aux.contenido[1][2];
		m.contenido[11][9]=aux.contenido[2][0];
		m.contenido[11][10]=aux.contenido[2][1];
		m.contenido[11][11]=aux.contenido[2][2];

}

void vframe(Matriz& m,Edificio& e,int numero,Invariante& i){
		
	int j=i.frames[numero].getinicio();
	int k=i.frames[numero].getfinal();
	m.contenido[0][0]=6*j-6;
	m.contenido[0][1]=6*j-5;
	m.contenido[0][2]=6*j-4;
	m.contenido[0][3]=6*j-3;
	m.contenido[0][4]=6*j-2;
	m.contenido[0][5]=6*j-1;
	m.contenido[0][6]=6*k-6;
	m.contenido[0][7]=6*k-5;
	m.contenido[0][8]=6*k-4;
	m.contenido[0][9]=6*k-3;
	m.contenido[0][10]=6*k-2;
	m.contenido[0][11]=6*k-1;
}

//Halla la transpuesta de la matriz cuadrada
void transpuesta(Matriz& m){
	double aux;
	for(int i=0;i<m.filas;i++){
		for(int j=0;j<i;j++){
			aux=m.contenido[i][j];
			m.contenido[i][j]=m.contenido[j][i];
			m.contenido[j][i]=aux;
		}
	}
}
//multiplicacion de matrices, multiplica m1 y m2, guarda en m
void multi(Matriz& m,Matriz& m1,Matriz& m2){
	double sum=0;
	for(int i=0;i<m2.filas;i++){
		for(int k=0;k<m1.columnas;k++){
			for(int j=0;j<m1.filas;j++){
				sum=sum+m1.contenido[i][j]*m2.contenido[j][k];
				
			}
			
			m.contenido[i][k]=sum;
			sum=0;
		}
	}
}

//Multiplicacion de vector forma matriz m1 por matriz m2 
void multi2(Matriz& m,Matriz& m1,Matriz& m2){
	double sum=0;
	for(int i=0;i<12;i++){
		for(int j=0;j<12;j++){
			sum=sum+m1.contenido[i][j]*m2.contenido[j][0];
		}
		m.contenido[i][0]=sum;
		sum=0;
	}	
}

//Multiplicacion de vector m2 por Matriz m1 cuadrada, alamcena en m
void multi3(vector<double>& m,Matriz& m1,vector<double>& m2,int dim){
	double sum=0;
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			sum=sum+m1.contenido[i][j]*m2[j];
		}
		m[i]=sum;
		sum=0;
	}	
}

//Multiplicacion de matriz m1 por vector columna m2, alamcena en m
void multi4(vector<double>& m,Matriz& m1,vector<double>& m2,int filas,int columnas){
	double sum=0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			sum=sum+m1.contenido[i][j]*m2[j];
		}
		m[i]=sum;
		sum=0;
	}

}

//Multiplicacion de matriz m1 por vector columna m2, que tiene 12 columnas
void multi5(vector<double>& m,Matriz& m1,vector<double>& m2,int numero){
	double sum=0;
	for(int i=0;i<numero;i++){
		for(int j=0;j<12;j++){
			sum=sum+m1.contenido[i][j]*m2[j];
		}
		m[i]=sum;
		sum=0;
	}

}

void filtrar(Matriz& s,Matriz& e,vector<int>& filas,vector<int>& columnas,int nfila,int ncol){
	for(int i=0;i<nfila;i++){
		for(int j=0;j<ncol;j++){
			s.contenido[i][j]=e.contenido[filas[i]][columnas[j]];
		}
	}	
}

//s donde se guarda, e entrada, filas tiene los indices, nfila el numero de filas del vector
void filtrar2(vector<double>& s,vector<double>& e,vector<int>& filas,int nfila){
	for(int i=0;i<nfila;i++){
		s[i]=e[filas[i]];
	}
}

//saca elementos de un vector con otro vector
void filtrar3(vector<double>& salida,vector<double>& entrada,Matriz& indices,int numero){
	for(int i=0;i<numero;i++){
		salida[i]=entrada[(int)indices.contenido[0][i]];
	}
}

//saca elementos de un vector con otro vector
void filtrar4(vector<double>& salida,vector<double>& entrada,vector<int>& indices,int numero){
	for(int i=0;i<numero;i++){
		salida[i]=entrada[indices[i]];
	}
}

//saca elementos de una matriz a un vector
void filtrar5(vector<double>& salida,Matriz& matriz,int numero){
	for(int i=0;i<4;i++){
		salida[i]=matriz.contenido[i][numero];
	}
}

//saca elementos de una matriz a un vector
void filtrar6(Matriz& almacenamiento,Matriz& entrada,int numero,int filas,int columnas){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			almacenamiento.contenido[i+numero][j]=entrada.contenido[i][j];
		}
	}
}

void GaussSeidell1(Matriz& f,vector<double>& e,vector<double>& r,int max)
{
	//equation factors tiene los coeficientes
	//equation values tiene los valores del vector
    float xo[max];
	 //Tamaño de la matriz
    int num = max;

	 //Valores iniciales de los iteradores
    for (int i = 0; i < max; i++)
    {
        xo[i]=0.01;
    }

    // El numero de iteracciones
    while (num> 0)
    {
        for (int i = 0; i < max; i++)
        {
            r[i] = (e[i] / f.contenido[i][i]);
            for (int j = 0; j < max; j++)
            {
                if (j == i) // not for diagonals
                    continue;
                // the real deal happens below
                r[i] = r[i] - ((f.contenido[i][j] / f.contenido[i][i]) * xo[j]);
                xo[i] = r[i];
            }

        }
        // loop condition manipulation
        num--;
    }
}

void GaussianElimination(Matriz& A,vector<double>& b,vector<double>& x,int n){
	double pivot,swap,M;
	int maxindex;
	//Esta es lamatriz aumentada con la columna al ultimo
	Matriz Ab(n,n+1);
	//LLenado de la matriz aumentada
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			Ab.contenido[i][j]=A.contenido[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		Ab.contenido[i][n]=b[i];
	}
	
	for(int i=0;i<n;i++){
		//pivote
		pivot = abs(Ab.contenido[i][i]);
		maxindex = i;

		for(int k=(i+1);k<n;k++){
			if ( abs(Ab.contenido[k][i]) >pivot ){
				pivot = abs(Ab.contenido[k][i]);
				maxindex = k;
			}
		}

		for(int k=i;k<(n+1);k++){
			swap = Ab.contenido[maxindex][k];
			Ab.contenido[maxindex][k] = Ab.contenido[i][k];
			Ab.contenido[i][k] = swap;
		}

		//Eliminacion
		for(int k=(i+1);k<n;k++){
			M = Ab.contenido[k][i]/Ab.contenido[i][i];

			for(int j=i;j<(n+1);j++){
				if (i==j){
					Ab.contenido[k][j]=0; }
				else{
					Ab.contenido[k][j] = Ab.contenido[k][j] - (M*Ab.contenido[i][j]); }
			}
		}
	}
	// SUSTITUCION REGRESIVA (SOLUCION DE Ax = b) x es un vector de zeros

	for(int i=(n-1);i>-1;i--){
		x[i] = Ab.contenido[i][n]/Ab.contenido[i][i];
		for(int k=(i-1);k>-1;k--){
			Ab.contenido[k][n]=Ab.contenido[k][n]-Ab.contenido[k][i]*x[i];
		}
	}

}

//Copiar el contenido de m1 a m2
void copiar(Matriz &m1,Matriz &m2,int& filas,int& columnas){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			m2.contenido[i][j]=m1.contenido[i][j];
		}
	}
}

void cat(vector<double> &v,vector<double> &d,int nv,int a){
	for(int i=0;i<nv;i++){
		if(a>i){
			v[i]=d[i];
		}
		else{
			v[i]=0;
		}
	}
}

void cat2(vector<int> &v,vector<int> &d1,int nd1,vector<int> &d2,int nd2){
	for(int i=0;i<(nd1+nd2);i++){
		if((nd1-1)>=i){
			v[i]=d1[i];
		}
		else{
			v[i]=d2[i-nd1];
		}
	}
}

template<typename t>
void suma(vector<t>& v,Matriz& m,int longitud){
	for(int i=0;i<longitud;i++){
		v[i]=v[i]+m.contenido[i][0];
	}
}

void operacion1(vector<double>& v,vector<double>& v11,vector<double>& v22,vector<double>& v12){
	for(int i=0;i<4;i++){
		v[i]=0.5*(v11[i]+v22[i])+pow(pow(0.5*(v11[i]-v22[i]),2) + pow(v12[i],2),0.5);
	}
}

void operacion2(vector<double>& v,vector<double>& v11,vector<double>& v22,vector<double>& v12){
	for(int i=0;i<4;i++){
		v[i]=0.5*(v11[i]+v22[i])-pow(pow(0.5*(v11[i]-v22[i]),2) + pow(v12[i],2),0.5);
	}
}

void operacion3(vector<double>& v,vector<double>& v13,vector<double>& v23){
	for(int i=0;i<4;i++){
		v[i]=pow(pow(v13[i],2)+pow(v23[i],2),0.5);
	}
}

void agrupar(vector<double>& v1,vector<double>& v2,vector<double>& v3,vector<double>& v4,vector<double>& v5,vector<double>& v6,vector<double>& v7,vector<double>& v8,vector<double>& v9,vector<double>& v10,vector<double>& v11,vector<double>& v12,vector<double>& v13,vector<double>& v14,vector<double>& v15,Matriz& matriz){

	for(int i=0;i<4;i++){
		matriz.contenido[i][0]=v1[i];
	}
	for(int i=0;i<4;i++){
		matriz.contenido[i][1]=v2[i];
	}
	for(int i=0;i<4;i++){
		matriz.contenido[i][2]=v3[i];
	}
	for(int i=0;i<4;i++){
		matriz.contenido[i][3]=v4[i];
	}
	for(int i=0;i<4;i++){
		matriz.contenido[i][4]=v5[i];
	}
	for(int i=0;i<4;i++){
		matriz.contenido[i][5]=v6[i];
	}
	for(int i=0;i<4;i++){
		matriz.contenido[i][6]=v7[i];
	}
	for(int i=0;i<4;i++){
		matriz.contenido[i][7]=v8[i];
	}
	for(int i=0;i<4;i++){
		matriz.contenido[i][8]=v9[i];
	}
	for(int i=0;i<4;i++){
		matriz.contenido[i][9]=v10[i];
	}
	for(int i=0;i<4;i++){
		matriz.contenido[i][10]=v11[i];
	}
	for(int i=0;i<4;i++){
		matriz.contenido[i][11]=v12[i];
	}
	for(int i=0;i<4;i++){
		matriz.contenido[i][12]=v13[i];
	}
	for(int i=0;i<4;i++){
		matriz.contenido[i][13]=v14[i];
	}
	for(int i=0;i<4;i++){
		matriz.contenido[i][14]=v15[i];
	}


}



