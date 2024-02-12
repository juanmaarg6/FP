/*
	Relación de ejercicios 1

	Ejercicio 35: Programa que, dado un número entero, calcula el mínimo 
	              número de dígitos que se necesitan para su representación
	              en binario.
	
	Entradas: Número entero (n).
	Salidas: Número de bits necesarios para representar el valor entero
	         en binario (num_bits).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de los recursos de E/S
#include <cmath>		// Inclusión de los recursos matemáticos

using namespace std;

// Programa principal

int main() {				

	// Declaración de variables
	
	int n = 0, num_bits = 0;
	bool aux = false;
					
	// Entradas de datos
	
	cout << " Introduzca un numero entero (mayor o igual que 0): ";
	cin >> n;
	
	// Cálculos
	
	/*
		Algoritmo:
				
		Si el numero introducido es mayor que 0, aux tiene el valor 1. En caso
		contrario, aux tiene el valor 0.
		
		Calculamos el número de bits haciendo el logaritmo en base 2 del 
		número entero.
		
		Multiplicamos el número de bits por aux. De esta forma si el número
		entero es positivo, el número de bits será igual al logaritmo en 
		base 2 del número entero más 1. Si el número introducido es cero, 
		entonces el número de bits será igual a 1 (se suma 1 para contar
		la potencia 2 elevado a 0 a la hora de calcular el número de bits).
	*/
	
	aux = n > 0;
	
	num_bits = log2(n);
	num_bits = (aux * num_bits) + 1;
	
	// Salidas
	
	cout << endl << " Para representar en binario al numero entero " << n 
	     << ", son necesarios " << num_bits << " bits" << endl << endl;
	
	return 0;
}
