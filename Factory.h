
#include <iostream> 

using namespace std; 
  
enum ElementoTipo { 
    VT_Binodo,    VT_Trinodo,    VT_Tetranodo 
}; 
  
class Elemento { 
public: 
    virtual void printElemento() = 0; 
    static Elemento* Create(ElementoTipo type);
}; 

class Binodo : public Elemento { 
public: 
    void printElemento() { 
        cout << "Elemento 2 nodos" << endl; 
    } 
}; 

class Trinodo : public Elemento { 
public: 
    void printElemento() { 
        cout << "Elemento 3 nodos" << endl; 
    } 
}; 

class Tetranodo : public Elemento { 
    public: 
    void printElemento() { 
        cout << "Elemento 4 nodos" << endl; 
    } 
}; 
  
Elemento* Elemento::Create(ElementoTipo type) { 
    if (type == VT_Binodo) 
        return new Binodo(); 
    else if (type == VT_Trinodo) 
        return new Trinodo(); 
    else if (type == VT_Tetranodo) 
        return new Tetranodo(); 
    else return NULL; 
} 
  
class Proveedor { 
public: 
  
    Proveedor(int numero) 
    { 
        ElementoTipo type;
        switch(numero){
            case 1:{
            type = VT_Binodo;
            break;}
            case 2:{
            type = VT_Trinodo;
            break;}
            case 3:{
            type = VT_Tetranodo;
            break;}
            default:{
            type = VT_Binodo;
            break;}
        } 
        pElemento = Elemento::Create(type); 
    } 

    ~Proveedor() { 
        if (pElemento) { 
            delete[] pElemento; 
            pElemento = NULL; 
        } 
			cout<<"Uso el destructor"<<endl;
    } 
    Elemento* getElemento()  { 
        return pElemento; 
    } 
  
private: 
    Elemento *pElemento; 
}; 