#include <iostream>
#include <vector>

using namespace std;

template<typename t>
void zeros(vector<t>& vectore,int longitud){
	for(int i=0;i<longitud;i++){
		vectore[i]=0;
	}
}

template<typename t>
void resta(vector<t>& v,vector<t>& v1,vector<t>& v2,vector<t>& v3,int longitud){
	for(int i=0;i<longitud;i++){
		v[i]=v1[i]-v2[i]+v3[i];
	}
}

void impmatriz(double**&matriz,int filas,int columnas){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
}