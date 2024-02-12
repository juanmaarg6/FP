/*
	Relaci�n de ejercicios 1

	Ejercicio 5: Programa para calcular una aproximaci�n del valor 
				 del n�mero PI a partir de la siguiente f�rmula:
					
					 PI					
				 	--- = arcsen(0.5) -->  PI = arcsen(0.5) * 6
					 6						  
	
	Entrada: -
	Salidas: Aproximaci�n del valor del n�mero PI (aprox_pi_arcsen).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusi�n de librer�a de recursos de E/S
#include <iomanip>		// Inclusi�n de librer�a de recursos para personalizar E/S
#include <cmath>	    // Inclusi�n de librer�a de recursos matem�ticos

using namespace std;

// Programa principal
	
int main(){	

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	
	 // Declaraci�n de variables
	 
	double aprox_pi_arcsen = 0.0;	 
				
	// C�lculos 
	
	aprox_pi_arcsen = asin(0.5) * 6;
			
	// Salidas
	
	cout << endl << " La aproximacion del valor del numero PI calculada es: "
	     << setw(15) << setprecision(10) << aprox_pi_arcsen << endl << endl;		

	system("pause");
	return 0;
}
