/*
	Relación de ejercicios 1

	Ejercicio 30: Programa que, dadas cuatro afirmaciones, se razona la 
	              falsedad o no de ellas.
	              
	
	Entradas: -
	Salidas: Veracidad o falsedad de las afirmaciones.

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusión de librería de recursos de E/S

using namespace std;

// Programa principal
   
int main() {					
		
	// Salidas
	
	cout << " 1) 'c' es una expresion de caracteres " << endl << endl;
	cout << "\t Falso. 'c' es una expresion de caracter, no de caracteres";
	
	cout << endl << endl;
	cout << " 2) 4 < 3 es una expresion numerica " << endl << endl;
	cout << "\t Falso. 4 < 3 es una expresion logica, no numerica";
	
	cout << endl << endl;
	cout << " 3) (4 + 3) < 5 es una expresion numerica " << endl << endl;
	cout << "\t Falso. (4 + 3) < 5 es una expresion logica, no numerica";
	
	cout << endl << endl;
	cout << " 4) cout << a; da como salida la escritura en pantalla de una a " 
	     << endl << endl;
	cout << "\t Falso. cout << a; da como salida el valor que contenga la"
	     << " variable a (un numero entero, un numero real, un caracter...)"
	     << endl << endl;
	
	return 0;
}
