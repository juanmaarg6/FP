/*
	Relación de ejercicios 1

	Ejercicio 5: Programa para calcular una aproximación del valor 
				 del número PI a partir de la siguiente fórmula:
					
					 PI					
				 	--- = arcsen(0.5) -->  PI = arcsen(0.5) * 6
					 6						  
	
	Entrada: -
	Salidas: Aproximación del valor del número PI (aprox_pi_arcsen).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de librería de recursos de E/S
#include <iomanip>		// Inclusión de librería de recursos para personalizar E/S
#include <cmath>	    // Inclusión de librería de recursos matemáticos

using namespace std;

// Programa principal
	
int main(){	

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	
	 // Declaración de variables
	 
	double aprox_pi_arcsen = 0.0;	 
				
	// Cálculos 
	
	aprox_pi_arcsen = asin(0.5) * 6;
			
	// Salidas
	
	cout << endl << " La aproximacion del valor del numero PI calculada es: "
	     << setw(15) << setprecision(10) << aprox_pi_arcsen << endl << endl;		

	system("pause");
	return 0;
}
