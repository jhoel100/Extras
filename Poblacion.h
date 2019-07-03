#include <iostream>
#include <vector>
#include <memory>
#include "Matriz.h"

using namespace std;

class Individuo{
	private:
		int numero;
		Edificio *edificio;
		Individuo *siguiente;
	public:
		Individuo(int,int,double[][3],int ,double [][3]);
		~Individuo();

		void setdata(int);
		void setnext(Individuo *);
		int getdata();
		Edificio* getdatos();
		Individuo *getnext();
		int BuscarDir(int) ;
		Individuo *getDir();
};

Edificio* Individuo::getdatos(){
	return edificio;

	}

Individuo::Individuo(int nuevo,int numseccframes1,double frames[][3],int numseccshell1,double shells[][3]){
	siguiente = NULL;
	numero = nuevo;
	edificio =new Edificio(numseccframes1,frames,numseccshell1,shells);

	}

void Individuo::setnext(Individuo *s) { 
	siguiente = s; 
}

Individuo::~Individuo(){
	siguiente = NULL;
	delete edificio;
	cout<<"Se elimino el individuo "<<numero<<endl;
	}

//LLamar si se uso el constructor vacio
void Individuo::setdata(int nuevo){
	numero = nuevo;
	}

int Individuo::getdata(){ 
	return numero; 
	}

Individuo * Individuo::getnext() { 
	return siguiente;
	}

Individuo * Individuo::getDir() { 
	return this; 
	}

int Individuo::BuscarDir(int elemento) {
	Individuo *aux = siguiente;
	int ubicacion=1;

	if(numero!=elemento){
		while(aux){
			if(aux->getdata()==elemento){
				return (ubicacion+1);				
			}
			aux = aux->getnext();
			ubicacion=ubicacion+1;
		}
		return -1;
	}
	else{
		return ubicacion;
	}

}


class Poblacion{
	private:
		Individuo *inicio;
		Individuo *fin;
		int tam;
	public:
		Poblacion();
		~Poblacion();
		void agregar(int,int,double [][3],int,double [][3]);
		int gettam() ;
		bool empty() ;
		void Mostrar() ;
		void Buscar(int) ;
		void Eliminar(int) ;
		void Modificar(int,int,double,int);
		Individuo * getinicio(){
			return inicio;
		}
		Individuo * getfin(){
			return fin;
		}

    class Iterator{
        Individuo *IndividuoPoblacion;
     public:
        Iterator(){}
        bool operator != (Individuo* entrada)
        {         
            return (IndividuoPoblacion != entrada);
        }

			Individuo& operator*()
        {
            return *IndividuoPoblacion;
        }

        Iterator& operator=(Individuo *igual)
        {
            IndividuoPoblacion=igual;
            return *this;
        }
        Iterator& operator ++()
        {
            IndividuoPoblacion=IndividuoPoblacion->getnext();
            return *this;
        }

        int getvalor(){return (IndividuoPoblacion->getdata());}
		Edificio* getedificio(){return (IndividuoPoblacion->getdatos());}

    };

};

Poblacion::Poblacion() {
	inicio=NULL;
	fin=NULL;
	tam=0;
}

void Poblacion::Mostrar() {
	cout<<"El contenido de la Poblacion es el siguiente: "<<endl;
	cout << inicio->getdata() <<" ";
	Individuo *aux = inicio->getnext();
	while(aux){
		cout << aux->getdata() <<" ";
		aux = aux->getnext();
	}
	cout<<endl;
}

int Poblacion::gettam() { 
	return tam; }

bool Poblacion::empty() {
	return (inicio == NULL);
}

void Poblacion::Buscar(int elemento) {

	Individuo *aux = inicio->getDir();
	int pos=1;
	bool flag=false;

	if(aux->getdata()!=elemento){
		while(aux){
			
			if(aux->getdata()==elemento){
				cout<<"Se encuentra en la ubicacion "<<pos<<endl;
				flag=true;	
			}
			aux = aux->getnext();
			pos++;
		}
		if(flag==false){
			cout<<"No se encontro"<<endl;
		}
	}
	else{
		cout<<"Se encuentra en la ubicacion "<<pos<<endl;
	}

}

//la posicion comienza con uno, osea elemento =1 inicial
//elemento es su ubicacion el poblacion
//posseccion es su ubicacion en la lista de secciones cual
//valor es el valor a cambiar
//ubicacion es si es ancho o peralte 1 o 2
void Poblacion::Modificar(int elemento,int posseccion,double valor,int ubicacion) {

	Individuo *aux = inicio->getDir();
	int pos=1;
	bool flag=false;

	if(aux->getdata()!=elemento){
		while(aux){
			
			if(aux->getdata()==elemento){
				(aux->getdatos())->modificar(posseccion,valor,ubicacion);
				flag=true;			
			}
			aux = aux->getnext();
			pos++;
		}
		if(flag==false){
			cout<<"No se encontro error esto no deveria pasar :("<<endl;
		}
	}
	else{
		(aux->getdatos())->modificar(posseccion,valor,ubicacion);
	}

}

//Falta corregir eleminicar
void Poblacion::Eliminar(int numero) {
	cout<<"Se elimino el elemento de posicion "<<numero<<endl;
	Individuo *aux = inicio;
	Individuo *aux2;
	Individuo *anterior;

	int cont=1;

	if(tam>=numero){
		while(numero>=cont){
			if(cont==numero){
				aux2=aux->getnext();
				delete aux;
				anterior->setnext(aux2);
			}
			anterior=aux;
			aux = aux->getnext();
			cont=cont+1;
		}
		tam--;
	}
}

Poblacion::~Poblacion(){
	Individuo *aux = inicio;
	if(!empty()){
		while(inicio){
			inicio = inicio->getnext();
			delete aux;
			aux = inicio;
		}
	}
	fin = NULL;
	tam = 0;
}

void Poblacion::agregar(int nuevo,int numseccframes1,double frames[][3],int numseccshell1,double shells[][3]){
	Individuo *aux = new Individuo(nuevo,numseccframes1,frames,numseccshell1,shells);
	if(empty()){
		inicio = aux;
	}else{
		fin->setnext(aux);
	}
	fin = aux;
	tam++;
}
