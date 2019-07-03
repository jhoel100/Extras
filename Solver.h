#include <iostream>
#include "Genetico.h"
#include <vector>
#include <memory>
#include <thread>

using namespace std;

void iniciar(int numseccframes,int numseccshell,double seccframe[][3],double seccarea[][3],Invariante &invariante,int &numnodos,int &numrestricciones,int &numcargasframe,int &numcargasshell,int &numcargasnodo,int &nummateriales,int numframes,int numshells,Edificio*& estructura,Matriz& aptitudes,int numindividuo){
	//Cantidad de grados de libertad restringidos
	int nglr=6*numrestricciones;
	
	//Cantidad de grados de libertad no restringidos
	int nglu=6*numnodos-nglr;

	Matriz forcepgmod(4*numshells,15);
	Matriz forcenodomod(4*numshells,15);
	Matriz forcenodomodpro(4*numshells,15);	

	Matriz stresspgmod(4*numshells,15);
	Matriz stressnodomod(4*numshells,15);
	Matriz stressnodomodpro(4*numshells,15);

	Matriz ftframe(numframes,12);

	vector<double> fr;
	fr.reserve(nglr);
	zeros(fr,nglr);

	vector<double> d;
	d.reserve(6*numnodos);
	zeros(d,6*numnodos);

	//Calculo de los grados de libertad restringidos y no restringidos asi como su cantidad
	vector<int> rl;
	rl.reserve(6*numnodos);
	zeros(rl,6*numnodos);

	for(int i=0;i<numrestricciones;i++){
		rl[6*invariante.restricciones[i].getnodo()-6]=invariante.restricciones[i].getgrado1();
		rl[6*invariante.restricciones[i].getnodo()-5]=invariante.restricciones[i].getgrado2();
		rl[6*invariante.restricciones[i].getnodo()-4]=invariante.restricciones[i].getgrado3();
		rl[6*invariante.restricciones[i].getnodo()-3]=invariante.restricciones[i].getgrado4();
		rl[6*invariante.restricciones[i].getnodo()-2]=invariante.restricciones[i].getgrado5();
		rl[6*invariante.restricciones[i].getnodo()-1]=invariante.restricciones[i].getgrado6();
	}
	
	//Vector con los grados de libertad no restringidos
	vector<int> glu;
	glu.reserve(nglu);
	zeros(glu,nglu);
	
	int ctd=-1;

	//ya esta con los valores -1
	for(int i=0;i<6*numnodos;i++){
		if(rl[i]==0){
			ctd++;
			glu[ctd]=i;
		}
	}

	//Vector con los grados de libertad restringidos
	vector<int> glr;
	glr.reserve(nglr);
	zeros(glr,nglr);
	
	ctd=-1;

	for(int i=0;i<(6*numnodos);i++){
		if(rl[i]==1){
			ctd=ctd+1;
			glr[ctd]=i;
		}
	}

	//vector agregado faltante
	vector<int> arreglo;
	arreglo.reserve(6*numnodos);
	zeros(arreglo,6*numnodos);

	cat2(arreglo,glu,nglu,glr,nglr);

	//Hallar la matriz de rigidez ensamblada de la estructura
	//Matriz de rigidez incial con 0
	Matriz k(6*numnodos,6*numnodos); //rigidez total

	//Vectores iniciales de ceros
	//vector de cargas totales
	vector<double> f;
	f.reserve(6*numnodos);
	zeros(f,6*numnodos);

	//vector de cargas totales
	vector<double> fu;
	fu.reserve(nglu);
	zeros(fu,nglu);

	//vector de cargas nodales
	vector<double> fn;
	fn.reserve(6*numnodos);
	zeros(fn,6*numnodos);

	//vector de cargas frame
	vector<double> ff;
	ff.reserve(6*numnodos);
	zeros(ff,6*numnodos);

	//vector de cargas areas
	vector<double> fa;
	fa.reserve(6*numnodos);
	zeros(fa,6*numnodos);
	

	//ACA VAN LOS METODOS DE LAS AREAS
	//Vectores y Matriz
	vector<double> ya;
	ya.reserve(4);
	zeros(ya,4);

	vector<double> xa;
	xa.reserve(4);
	zeros(xa,4);

	Matriz tsa(24,24);
	Matriz tsa2(24,24);
	Matriz dm(3,3);
	Matriz dp(5,5);
	Matriz ssl(24,24);
	Matriz ssg(24,24);

	//Matriz auxiliar
	Matriz auxiliar(24,24);

	Bloque ap(5,16,5);
	Bloque am(3,16,5);

	vector<double> gl;
	gl.reserve(4);
	zeros(gl,4);

	vector<int> va;
	va.reserve(24);
	zeros(va,24);

	vector<double> vcd;
	vcd.reserve(24);
	zeros(vcd,24);

	vector<double> vcda;
	vcda.reserve(24);
	zeros(vcda,24);

	vector<double> vcdag;
	vcdag.reserve(24);
	zeros(vcdag,24);

	Matriz nn(24,6);

	int valor=24;
	
	//No estan los procedimientos de solucion del solver
	//En esta parte iba el metodo de solucion del proyecto

}


class Solver{
public:
    Solver (Solver const&) = delete;
    Solver& operator=(Solver const&) = delete;

	static shared_ptr<Solver> instancia;

    static shared_ptr<Solver> getInstancia(int,int,int,int,int ,int ,int ,int,int,int,double [][14],double [][8],double [][5],double [][4],double [][4],int [][8],double [][3],double [][3],double [][8],double [][7],int,int,int,bool,int);

	 ~Solver(){
		cout<<"Se destruyo el Solver "<<endl;
	}

private:

    Solver(int numnodos,int numframes,int numshells,int numrestricciones,int numcargasframe,int numcargasshell,int numcargasnodo,int nummateriales,int numseccframes,int numseccshell,double cargframe[][14],double carnodal[][8],double carareas[][5],double materiales[][4],double coord[][4],int restr[][8],double seccframe[][3],double seccarea[][3],double infoframe[][8],double infoarea[][7],int generaciones,int numindividuos,int mutacion,bool aleatorioinicial,int procesos) {
		//Esta es la poblacion de edificios y el aleatorio
		//Aca se ejcutan los Alg geneticos
		Poblacion edificios;
		srand(time(NULL));
		int num=1+rand()%(9-1);

		//Crea la poblacion inicial de individuos		
		for(int i =0 ; i < numindividuos; i++){
			for(int j=0;j<numseccframes;j++){
				if(aleatorioinicial){
					num=1+rand()%(9-1);
					seccframe[j][1]=Genetico::genseccframe(num);

					num=1+rand()%(9-1);
					seccframe[j][2]=Genetico::genseccframe(num);
				}
				edificios.agregar(i+1,numseccframes,seccframe,numseccshell,seccarea);
			}
		}

		//Muestra la poblacion de edificios inicial
		cout<<endl;
		cout << "La poblacion de edificios Inicial contiene: " << edificios.gettam()<<" edificios" << endl;

		cout<<"Estos son los ID de los edificios: "<<endl;
		Poblacion::Iterator iterador;
		int contador=1;
	    for(iterador=edificios.getinicio(); iterador!=NULL;iterador.operator++())
	     { 
	       cout<<"Edificio "<<contador<<"  ID: "<<iterador.getvalor()<<endl;
		   contador++;   
	     }
		 cout<<endl;

		//Aptitud de los elementos
		Matriz aptitudes(numindividuos,numframes+numshells);

		//Creacion de los objetos
		Invariante invariante(numframes,numcargasframe,cargframe,numcargasnodo,carnodal,numcargasshell,carareas,nummateriales,materiales,numnodos,coord,numrestricciones,restr,numframes,infoframe,numshells,infoarea);
		
		//Parametros para calcular
		for(int i=0;i<generaciones;i++){
			cout<<"Resolviendo la Generacion numero: "<<i+1<<endl;

			Edificio * ptr_edificio;

			/*
			contador=0;
			for(iterador=edificios.getinicio(); iterador!=NULL;iterador.operator++())
  		    { 
  		       ptr_edificio=iterador.getedificio();
			   cout<<"Resolvio el individuo: "<<contador+1<<endl;
			
				iniciar(numseccframes,numseccshell,seccframe,seccarea,invariante,numnodos,numrestricciones,numcargasframe,numcargasshell,numcargasnodo,nummateriales,numframes,numshells,ptr_edificio,aptitudes,contador);
		        contador++;
 		    }
			cout<<endl;
			*/
			 
			iterador=edificios.getinicio();

			contador=0;

			for(int i1=0;i1<(numindividuos/procesos);i1++)
  		    { 
				//Creacion del numero de procesos
				vector<thread> hilos;
	 			hilos.reserve(procesos);
				
				for(int i2=0;i2<procesos;i2++){
					ptr_edificio=iterador.getedificio();

					hilos.emplace_back(iniciar,numseccframes,numseccshell,seccframe,seccarea,ref(invariante),ref(numnodos),ref(numrestricciones),ref(numcargasframe),ref(numcargasshell),ref(numcargasnodo),ref(nummateriales),ref(numframes),ref(numshells),ref(ptr_edificio),ref(aptitudes),contador);
					iterador.operator++();
			 	}

			 	for(int i3=0;i3<procesos;i3++){
					hilos[i3].join();
					cout<<"Resolvio el individuo: "<<contador+1<<endl;
					contador++;
		 		}
				
 		    }
			cout<<endl;
			
			//Cambiar las secciones de los edificios de la generacion
			for(int ii =0 ; ii < numindividuos; ii++){
				for(int j=0;j<numseccframes;j++){
					//modifica el ancho
					num=1+rand()%(9-1);
					edificios.Modificar(ii+1,j,Genetico::genseccframe(num),1);

					//modifica el peralte
					num=1+rand()%(9-1);
					edificios.Modificar(ii+1,j,Genetico::genseccframe(num),2);

				}
			}



		}

	}
};
shared_ptr<Solver> Solver::getInstancia(int numnodos,int numframes,int numshells,int numrestricciones,int numcargasframe,int numcargasshell,int numcargasnodo,int nummateriales,int numseccframes,int numseccshell,double cargframe[][14],double carnodal[][8],double carareas[][5],double materiales[][4],double coord[][4],int restr[][8],double seccframe[][3],double seccarea[][3],double infoframe[][8],double infoarea[][7],int generaciones,int numindividuos,int mutacion,bool aleatorioinicial,int procesos)
{
    if (instancia == nullptr)
    {
        static shared_ptr<Solver> s{new Solver(numnodos,numframes,numshells,numrestricciones,numcargasframe,numcargasshell,numcargasnodo,nummateriales,numseccframes,numseccshell,cargframe,carnodal,carareas,materiales,coord,restr,seccframe,seccarea,infoframe,infoarea,generaciones,numindividuos,mutacion,aleatorioinicial,procesos)};
        instancia=s;
    }

    return instancia;
}

shared_ptr<Solver> Solver::instancia = nullptr;


