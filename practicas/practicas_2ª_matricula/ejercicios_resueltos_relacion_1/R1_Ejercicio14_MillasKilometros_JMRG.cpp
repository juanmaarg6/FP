/*
	Relaci�n de ejercicios 1

	Ejercicio 14: Programa que, dada una distancia en millas, muestra la
	              distancia equivalente en kil�metros y viceversa
	
	Entrada:  Distancia en millas (dist_millas).
	Salidas: Distancia en kil�metros (dist_kilometros).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusi�n de librer�a de recursos de E/S

using namespace std;

// Programa principal

int main(){
	
	// Declaraci�n de constantes
	
	const double MILLA_A_KILOMETROS = 1.609344;

	// Declaraci�n de variables	

	double dist_millas1 = 0.0;
	double dist_kilometros1 = 0.0;
	double dist_millas2 = 0.0;
	double dist_kilometros2 = 0.0;	
	
	// Entradas de datos
	
	cout << " Introduzca la distancia (en millas): ";	
	cin >> dist_millas1;
				
	// C�lculos 
	
	dist_kilometros1 = dist_millas1 * MILLA_A_KILOMETROS;			 
			
	// Salidas
	
	cout << endl << " " << dist_millas1 << " millas equivalen a "
	     << dist_kilometros1 << " kilometros" << endl << endl;	
		 
	// Entradas de datos
	
	cout << " Introduzca la distancia (en kilometros): ";	
	cin >> dist_kilometros2;
				
	// C�lculos 
	
	dist_millas2 = dist_kilometros2 / MILLA_A_KILOMETROS;			 
			
	// Salidas
	
	cout << endl << " " << dist_kilometros2 << " kilometros equivalen a "
	     << dist_millas2 << " millas" << endl << endl;	
	
	system("pause");
	return 0;
}
