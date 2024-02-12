/*
	Relaci�n de ejercicios 1

	Ejercicio 25: Programa que, dada una letra en may�scula, muestra dicha
	              letra en min�scula.
	              
	Entradas: Car�cter en may�scula (caracter_mayuscula).
	Salidas: Car�cter en min�scula (caracter_minuscula).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusi�n de los recursos de E/S

using namespace std;

// Programa principal

int main() {				
	
	// Declaraci�n de constantes
	
	const int distancia_mayus_minus = 'a'-'A';
	
	/*
		La constante distancia_mayus_minus indica el n�mero de caracteres que 
		hay entre 'A' y 'a' en el c�digo ASCII. Esta distancia (32) ser� la 
		misma para cualquier letra en may�scula con su respectiva min�scula.
	*/
   													   	   
	// Declaraci�n de variables
	
	char mayuscula = 'a';
	char minuscula = 'a';
							
	// Entradas de datos
	
	cout << " Introduzca una letra en mayuscula: ";
	cin >> mayuscula;
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Sumar a una letra may�scula el n�mero de car�cteres que hay entre ella
		y su correspondiente letra min�scula en el c�digo ASCII.
	*/
	
	minuscula = mayuscula + distancia_mayus_minus;
	
	// Salidas
	
	cout << endl << " Letra " << mayuscula 
	     << " en minuscula: " << minuscula << endl << endl;
	
	return 0;
}
