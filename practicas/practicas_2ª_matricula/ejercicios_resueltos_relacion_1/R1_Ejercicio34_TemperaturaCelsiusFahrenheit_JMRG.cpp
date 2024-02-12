/*
	Relación de ejercicios 1

	Ejercicio 34: Programa que, dada una temperatura en grados Celsius, 
	              calcula la temperatura correspondiente en grados Fahrenheit.
	
	Entradas: Temperatura en grados Celsius (grados_celsius).
	Salidas: Temperatura en grados Fahrenheit (grados_fahrenheit).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>		// Inclusión de los recursos de E/S

using namespace std;

// Programa principal

int main() {
	
	// Declaración de variables
	
	double grados_celsius = 0.0, grados_fahrenheit = 0.0;
	
	// Entradas de datos
	
	cout << " Introduzca la temperatura en grados Celsius: ";
	cin >> grados_celsius;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Calcular los grados Fahrenheit correspondientes usando la fórmula:
		
	            Grados Fahrenheit = (Grados Celsius * 180 / 100) + 32
	*/
	
	grados_fahrenheit = (grados_celsius * 180 / 100) + 32;
	
	// Salidas
	
	cout << endl << " " << grados_celsius << " grados Celsius equivalen a " 
	     << grados_fahrenheit << " grados Fahrenheit" << endl << endl; 

	return 0;
}
