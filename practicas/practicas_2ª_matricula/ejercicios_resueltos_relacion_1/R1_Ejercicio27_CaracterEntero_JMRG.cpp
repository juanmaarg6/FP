/*
	Relaci�n de ejercicios 1

	Ejercicio 27: Programa que, dado un car�cter num�rico (entre '0' y '9'), 
	              lo transforma en su n�mero entero correspondiente.
	
	Entradas: Car�cter num�rico (caracter).
	Salidas: N�mero entero (entero).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusi�n de los recursos de E/S

using namespace std;

// Programa principal

int main() {				
	
	// Declaraci�n de constantes
	
	const char CERO_ASCII = '0';
	
	// Declaraci�n de variables
	
	char caracter;
	int entero;
							
	// Entrada de datos
	
	cout << " Introduzca un caracter numerico: ";
    cin >> caracter;
	
	// C�lculos
	
	/*
		Algoritmo:
				
		Al sumar/restar dos caracteres, el resultado es la suma/resta de los
		valores correspondientes en el c�digo ASCII de dichos caracteres, es 
		decir, el resultado es un entero. Por tanto, usamos el valor 
		correspondiente del car�cter '0' para rest�rselo al car�cter num�rico 
		y que as� devuelva su valor entero correspondiente.
	*/
	
	entero = caracter - CERO_ASCII;   
	
	// Salidas
	
	cout << endl << " El caracter numerico '" << caracter << "' tiene el"
         << " siguiente entero correspondiente: " << entero << endl << endl;
			
	return 0;
}
