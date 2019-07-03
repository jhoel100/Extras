#include <iostream>
#include <vector>
#include <iomanip>
#include "CarFrame.h"
#include "CarNodo.h"
#include "CarShell.h"
#include "Frame.h"
#include "Material.h"
#include "Punto3D.h"
#include "Restriccion.h"
#include "SecFrame.h"
#include "SecShell.h"
#include "Shell.h"
#include "Extras.h"

using namespace std;

class Edificio{
	private:
		int numseccframes;
		int numseccshell;
	public:
		Edificio(int,double [][3],int,double [][3]);
		Edificio(){}
		vector<SecFrame> secframes;
		vector<SecShell> secshells;
		void modificar(int posseccion,double valor,int ubicacion){
			if(ubicacion==1){
				secframes[posseccion].setancho(valor);
			}
			if(ubicacion==2){
				secframes[posseccion].setperalte(valor);
			}
		}
	
};

Edificio::Edificio(int numseccframes1,double s[][3],int numseccshell1,double sa[][3]){
	numseccframes=numseccframes1;
	numseccshell=numseccshell1;

	secframes.reserve(numseccframes);

	for(int i=0;i<numseccframes;i++){
		secframes.emplace_back(s[i]);
	}

	secshells.reserve(numseccshell);

	for(int i=0;i<numseccshell;i++){
		secshells.emplace_back(sa[i]);
	}


}

class Invariante{
	private:
		int numcargasframe;
		int numcargasnodo;
		int numcargasshell;
		int nummateriales;
		int numpuntos;
		int numrestricciones;
		int numframes;
		int numshells;

	public:
		Invariante(int,int,double[][14],int,double[][8],int,double[][5],int,double[][4],int,double[][4],int,int[][8],int,double[][8],int,double[][7]);
		vector<CarFrame> cargaframe;
		vector<CarNodo> carganodo;
		vector<CarShell> cargashell;		
		vector<Material> materiales;
		vector<Punto3D> coord;
		vector<Restriccion> restricciones;
		vector<Shell> shells;
		vector<Frame> frames;
};

Invariante::Invariante(int numframes,int numcargasframe1,double cf[][14],int numcargasnodo1,double cn[][8],int numcargasshell1,double cs[][5],int nummateriales1,double m[][4],int numpuntos1,double p[][4],int numrestricciones1,int r[][8],int numframes1,double f[][8],int numshells1,double s[][7]){

	numcargasframe=numcargasframe1;
	numcargasnodo=numcargasnodo1;
	numcargasshell=numcargasshell1;
	nummateriales=nummateriales1;
	numpuntos=numpuntos1;
	numrestricciones=numrestricciones1;

	numshells=numshells1;
	numframes=numframes1;

	cargaframe.reserve(numcargasframe);
	for(int i=0;i<numcargasframe;i++){
		cargaframe.emplace_back(cf[i]);
	}
	
	carganodo.reserve(numcargasnodo);
	
	for(int i=0;i<numcargasnodo;i++){
		carganodo.emplace_back(cn[i]);
	}

	cargashell.reserve(numcargasshell);

	for(int i=0;i<numcargasshell;i++){
		cargashell.emplace_back(cs[i]);
	}
	
	materiales.reserve(nummateriales);
	
	for(int i=0;i<nummateriales;i++){
		materiales.emplace_back(m[i]);
	}

	coord.reserve(numpuntos);

	for(int i=0;i<numpuntos;i++){
		coord.emplace_back(p[i]);
	}

	restricciones.reserve(numrestricciones);

	for(int i=0;i<numrestricciones;i++){
		restricciones.emplace_back(r[i]);
	}

	shells.reserve(numshells);

	for(int i=0;i<numshells;i++){
		shells.emplace_back(s[i]);
	}

	frames.reserve(numframes);

	for(int i=0;i<numframes;i++){
		frames.emplace_back(f[i]);
	}



}

