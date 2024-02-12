/*
	Relación de ejercicios 1

	Ejercicio 4: Programa para calcular las siguientes aproximaciones 
	             del número PI:
					
							  256				      1					 377
				 1)	PI aprox. ---	2) PI aprox. 3 + ---	3) PI aprox. ---
					 		   81					  8					 120
	
	Entrada: -
	Salidas: Valores de las diferentes aproximaciones del número PI 
	         (aprox_pi_rhind, aprox_pi_mesopotamia, aprox_pi_ptolomeo).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusión de librería de recursos de E/S

using namespace std;

// Programa principal
	
int main(){	
	
	// Declaración de variables
		  
	double aprox_pi_rhind = 0.0;
	double aprox_pi_mesopotamia = 0.0;
	double aprox_pi_ptolomeo = 0.0;
				
	// Cálculos
	
	aprox_pi_rhind = 256 / 81.0;	
	aprox_pi_mesopotamia = 3 + (1 / 8.0);
	aprox_pi_ptolomeo = 377 / 120.0;
			
	// Salidas
	
	cout << endl << " Aproximaciones del numero PI: ";
	cout << endl << "\n\t Egipto: " << aprox_pi_rhind;	
	cout << endl << "\t Mesopotamia: " << aprox_pi_mesopotamia;	
	cout << endl << "\t Ptolomeo: " << aprox_pi_ptolomeo << endl << endl;	

	system("pause");
	return 0;
}
