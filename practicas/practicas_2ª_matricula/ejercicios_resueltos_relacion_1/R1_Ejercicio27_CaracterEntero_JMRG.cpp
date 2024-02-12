/*
	Relación de ejercicios 1

	Ejercicio 27: Programa que, dado un carácter numérico (entre '0' y '9'), 
	              lo transforma en su número entero correspondiente.
	
	Entradas: Carácter numérico (caracter).
	Salidas: Número entero (entero).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de los recursos de E/S

using namespace std;

// Programa principal

int main() {				
	
	// Declaración de constantes
	
	const char CERO_ASCII = '0';
	
	// Declaración de variables
	
	char caracter;
	int entero;
							
	// Entrada de datos
	
	cout << " Introduzca un caracter numerico: ";
    cin >> caracter;
	
	// Cálculos
	
	/*
		Algoritmo:
				
		Al sumar/restar dos caracteres, el resultado es la suma/resta de los
		valores correspondientes en el código ASCII de dichos caracteres, es 
		decir, el resultado es un entero. Por tanto, usamos el valor 
		correspondiente del carácter '0' para restárselo al carácter numérico 
		y que así devuelva su valor entero correspondiente.
	*/
	
	entero = caracter - CERO_ASCII;   
	
	// Salidas
	
	cout << endl << " El caracter numerico '" << caracter << "' tiene el"
         << " siguiente entero correspondiente: " << entero << endl << endl;
			
	return 0;
}
