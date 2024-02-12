/*
	Relación de ejercicios 2

	Ejercicio 9: Programa que, dadas una clave representada por un número
	             entero y una letra mayúscula, codifica el carácter según
	             la clave introducida.
	              
	             Para codificar el carácter se considera una representación 
				 circular del alfabeto, de tal forma que el carácter que
				 sigue a 'Z' es 'A'. Por ejemplo, si clave = 4, entonces la 
				 'A' se reemplaza por la 'E' y la 'Z' por la 'D'. Utilizando 
				 clave = 0 la secuencia cifrada es igual a la original.
	
	Entradas: Clave (clave),
	          Letra mayúscula (mayuscula).
	Salidas: Letra mayúscula codificada (mayuscula_codificada).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de los recursos de E/S

using namespace std;

// Programa principal

int main() {				

	// Declaración de constantes
	
	const char PRIMERA_LETRA = 'A';
	const char ULTIMA_LETRA = 'Z';
	
	// Declaración de variables
	
	int clave = 0, suma = 0;
	char mayuscula = 'a', mayuscula_codificada = 'a';
							
	// Entradas de datos
	
	cout << " Introduzca una clave (valor entero): ";
	cin >> clave;
	cout << " Introduzca una letra mayuscula: ";
	cin >> mayuscula;
	
	// Cálculos
	
	/*
		Algoritmo:
				
		Sumar la clave a la letra mayúscula.
		
		Si la clave es mayor o igual que 0:
		
			Si la suma anterior supera a la última letra del alfabeto, 
			la codificación se calcula mediante una estructura circular.
			
			Si no, la codificación es igual a la suma.
			
		Si no (es decir, la clave es menor que 0):
		
			Si la suma (realmente es una resta) anterior supera a la primera
			letra del alfabeto, la codificación se calcula mediante una 
			estructura circular.
			
			Si no, la codifcación es igual a la suma.
	*/
	
	bool clave_positiva = (clave >= 0);
	
	suma = mayuscula + clave;
	
	if(clave_positiva) {
		if(suma > 'Z')
			mayuscula_codificada = PRIMERA_LETRA + (suma - ULTIMA_LETRA - 1);
		else
			mayuscula_codificada = suma;
	}
	else {
		if(suma < 'A')
			mayuscula_codificada = ULTIMA_LETRA - (PRIMERA_LETRA - suma - 1);
		else
			mayuscula_codificada = suma;
	}
			
	// Salidas
	
	cout << endl << " Con una clave igual a " << clave << ", el caracter "
	     << mayuscula << " se codifica en el caracter " << mayuscula_codificada
		 << endl << endl;
	
	return 0;
}
