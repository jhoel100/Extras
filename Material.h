#include <iostream>

using namespace std;

class Material{
	private:
		double E;
		double poi;
		double G;
	public:
		Material();
		Material(double[4]);
		double getE();
		double getpoi();
		double getG();
		void setE(double);
		void setpoi(double);
		void setG(double);
};

Material::Material(){
	E=0;
	poi=0;
	G=0;
}

Material::Material(double informacion[4]){
	E=informacion[1];
	poi=informacion[2];
	G=informacion[3];
}

double Material::getE(){
	return E;
}

double Material::getpoi(){
	return poi;
}

double Material::getG(){
	return G;
}

void Material::setE(double s){
	E=s;
}

void Material::setpoi(double s){
	poi=s;
}

void Material::setG(double s){
	G=s;
}

