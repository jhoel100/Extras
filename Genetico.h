#include <iostream>
#include "Poblacion.h"

#include <stdlib.h>
#include <time.h>

using namespace std;

class Genetico{
	public:
		double static genseccframe(int numero){
			switch (numero){
				case 1:{
					return 0.25;
					break;
				}
				case 2:{
					return 0.3;
					break;
				}
				case 3:{
					return 0.35;
					break;
				}
				case 4:{
					return 0.40;
					break;
				}
				case 5:{
					return 0.45;
					break;
				}
				case 6:{
					return 0.5;
					break;
				}
				case 7:{
					return 0.55;
					break;
				}
				case 8:{
					return 0.6;
					break;
				}
				default:{
					return 0.65;
					break;
				}
				
			}
		}

};
