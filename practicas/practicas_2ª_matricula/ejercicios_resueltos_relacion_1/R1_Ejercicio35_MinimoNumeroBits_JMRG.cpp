/*
	Relaci�n de ejercicios 1

	Ejercicio 35: Programa que, dado un n�mero entero, calcula el m�nimo 
	              n�mero de d�gitos que se necesitan para su representaci�n
	              en binario.
	
	Entradas: N�mero entero (n).
	Salidas: N�mero de bits necesarios para representar el valor entero
	         en binario (num_bits).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusi�n de los recursos de E/S
#include <cmath>		// Inclusi�n de los recursos matem�ticos

using namespace std;

// Programa principal

int main() {				

	// Declaraci�n de variables
	
	int n = 0, num_bits = 0;
	bool aux = false;
					
	// Entradas de datos
	
	cout << " Introduzca un numero entero (mayor o igual que 0): ";
	cin >> n;
	
	// C�lculos
	
	/*
		Algoritmo:
				
		Si el numero introducido es mayor que 0, aux tiene el valor 1. En caso
		contrario, aux tiene el valor 0.
		
		Calculamos el n�mero de bits haciendo el logaritmo en base 2 del 
		n�mero entero.
		
		Multiplicamos el n�mero de bits por aux. De esta forma si el n�mero
		entero es positivo, el n�mero de bits ser� igual al logaritmo en 
		base 2 del n�mero entero m�s 1. Si el n�mero introducido es cero, 
		entonces el n�mero de bits ser� igual a 1 (se suma 1 para contar
		la potencia 2 elevado a 0 a la hora de calcular el n�mero de bits).
	*/
	
	aux = n > 0;
	
	num_bits = log2(n);
	num_bits = (aux * num_bits) + 1;
	
	// Salidas
	
	cout << endl << " Para representar en binario al numero entero " << n 
	     << ", son necesarios " << num_bits << " bits" << endl << endl;
	
	return 0;
}
