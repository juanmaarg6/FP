/*
	Relaci�n de ejercicios 1

	Ejercicio 6: Programa para convertir una cantidad g de grados 
				 a una cantidad r de radianes mediante la siguiente f�rmula:
					
							      PI					
				 		 r = g * ---
					 		     180						  
	
	Entrada: N�mero de grados (grados).
	Salidas: Radianes correspondientes a los grados introducidos (radianes).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusi�n de librer�a de recursos de E/S
#include <cmath>		    // Inclusi�n de librer�a de recursos matem�ticos

using namespace std;

// Programa principal
	
int main(){	
	
	// Declaraci�n de constantes
		
	const double PI = asin(0.5) * 6;		 		
	const double GRADOS_A_RADIANES = PI / 180;	
	
	// Declaraci�n de variables
	     
	double grados = 0.0;
	double radianes = 0.0;	 

	// Entradas de datos
	
	cout << " Introduzca numero de grados: ";
	cin >> grados;
	
	// C�lculos
	
	radianes = grados *	GRADOS_A_RADIANES;
			
	// Salidas
	
	cout << endl;
	cout << " " << grados << " grados son " << radianes << " radianes";
	cout << endl << endl;

	system("pause");
	return 0;
}
