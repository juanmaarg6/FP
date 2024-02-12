/*
	Relación de ejercicios 1

	Ejercicio 25: Programa que, dada una letra en mayúscula, muestra dicha
	              letra en minúscula.
	              
	Entradas: Carácter en mayúscula (caracter_mayuscula).
	Salidas: Carácter en minúscula (caracter_minuscula).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de los recursos de E/S

using namespace std;

// Programa principal

int main() {				
	
	// Declaración de constantes
	
	const int distancia_mayus_minus = 'a'-'A';
	
	/*
		La constante distancia_mayus_minus indica el número de caracteres que 
		hay entre 'A' y 'a' en el código ASCII. Esta distancia (32) será la 
		misma para cualquier letra en mayúscula con su respectiva minúscula.
	*/
   													   	   
	// Declaración de variables
	
	char mayuscula = 'a';
	char minuscula = 'a';
							
	// Entradas de datos
	
	cout << " Introduzca una letra en mayuscula: ";
	cin >> mayuscula;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Sumar a una letra mayúscula el número de carácteres que hay entre ella
		y su correspondiente letra minúscula en el código ASCII.
	*/
	
	minuscula = mayuscula + distancia_mayus_minus;
	
	// Salidas
	
	cout << endl << " Letra " << mayuscula 
	     << " en minuscula: " << minuscula << endl << endl;
	
	return 0;
}
