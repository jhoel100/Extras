#include <iostream>
#include <vector>
#include "Solver.h"


int main(){

	//Ingreso de datos
	//ID  framecargado(numero)inicia en 1     fx-i fy-i fz-i mx-i my-i mz-i    fx-j fy-j fz-j mx-j my-j mz-j 
	double cargframe[][14]={{1,1,0,0,0,0,0,0,0,0,0,0,0,0}};
	//ID numero de nodo(numero)inicia en 1     fx fy fz mx my mz
	double carnodal[][8]={{1,2,5,0,0,0,0,0},{2,3,10,0,0,0,0,0},{3,5,5,0,0,0,0,0},{4,6,10,0,0,0,0,0}};
	//ID numero de area(numero)inicia en 1     wx  wy  wz
	double carareas[][5]={{1,1,0,0,-0.3},{2,2,0,0,-0.3}};
	//ID E poisson G
	double materiales[][4]={{1,2188197.89,0.2,911749.12}};
	//ID X  Y  Z
	double coord[][4]={{1,0,0,0},{2,0,0,3},{3,0,0,6},{4,0,4,0},{5,0,4,3},{6,0,4,6},{7,4,0,0},{8,4,0,3},{9,4,0,6},{10,4,4,0},{11,4,4,3},{12,4,4,6}};
	//ID  numero de nodo  nodo1  nodo2  nodo3  nodo4  nodo5  nodo6
	int restr[][8]={{1,1,1,1,1,1,1,1},{2,4,1,1,1,1,1,1},{3,7,1,1,1,1,1,1},{4,10,1,1,1,1,1,1}};
	//ID  ancho  peralte 
	double seccframe[][3]={{1.0,0.3,0.3}};
	//ID  espesor  tipo 0-1 (1:thick 0:thin)
	double seccarea[][3]={{1,0.2,1},{2,0.2,1}};
	//ID  nodoj nodok longitud nromaterial  nroseccion  giro  tipo
	double infoframe[][8]={{1,1,2,3,1,1,0,1},{2,2,3,3,1,1,0,1},{3,4,5,3,1,1,0,1},{4,5,6,3,1,1,0,1},{5,7,8,3,1,1,0,1},{6,8,9,3,1,1,0,1},{7,10,11,3,1,1,0,1},{8,11,12,3,1,1,0,1},{9,8,2,4,1,1,0,1},{10,11,8,4,1,1,0,1},{11,9,11,4,1,1,0,1},{12,2,5,4,1,1,0,1},{13,9,3,4,1,1,0,1},{14,12,9,4,1,1,0,1},{15,6,12,4,1,1,0,1},{16,3,6,4,1,1,0,1}};
	//ID  nodoj  nodok  nodol  nodom  nromaterial  nroseccion 
	double infoarea[][7]={{1,8,11,5,2,1,1},{2,9,12,6,3,1,1}};

	//parametros iniciales
	int numnodos=sizeof(coord)/sizeof(coord[0]);
	int numframes=sizeof(infoframe)/sizeof(infoframe[0]);
	int numshells=sizeof(infoarea)/sizeof(infoarea[0]);
	int numrestricciones=sizeof(restr)/sizeof(restr[0]);
	int numcargasframe=sizeof(cargframe)/sizeof(cargframe[0]);
	int numcargasshell=sizeof(carareas)/sizeof(carareas[0]);
	int numcargasnodo=sizeof(carnodal)/sizeof(carnodal[0]);
	//parametros etra
	int nummateriales=sizeof(materiales)/sizeof(materiales[0]);
	int numseccframes=sizeof(seccframe)/sizeof(seccframe[0]);
	int numseccshell=sizeof(seccarea)/sizeof(seccarea[0]);

	//Parametros de AlgoritmoGenetico 
	//individuos multiplo del numero de procesos a usar
	int generaciones=15;
	int numindividuos=15;
	int mutacion=8;

	//Activar Geneticos?
	//Activa o desactiva la generacion de secciones aleatorias
	bool aleatorioinicial=true;

	//Cuantos procesadores Extra aparte del main? maximo 3
	int procesos=3;

	shared_ptr<Solver> solver=Solver::getInstancia(numnodos,numframes,numshells,numrestricciones,numcargasframe,numcargasshell,numcargasnodo,nummateriales,numseccframes,numseccshell,cargframe,carnodal,carareas,materiales,coord,restr,seccframe,seccarea,infoframe,infoarea,generaciones,numindividuos,mutacion,aleatorioinicial,procesos);

	


}

