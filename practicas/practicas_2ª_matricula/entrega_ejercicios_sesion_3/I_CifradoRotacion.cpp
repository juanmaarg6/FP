/*
	Relación de ejercicios 1

	Ejercicio 28: Programa que, dadas una clave representada por un número
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
	
	const int LONG_ALFABETO = 'Z' - 'A' + 1;
	const char PRIMERA_LETRA = 'A';
		
	// Declaración de variables
	
	int clave = 0, suma = 0;
	char mayuscula = 'a', mayus_codificada = 'a';
							
	// Entradas de datos
	
	cout << " Introduzca una clave (valor entero): ";
	cin >> clave;
	cout << " Introduzca una letra mayuscula: ";
	cin >> mayuscula;
	
	// Cálculos
	
	/*
		Algoritmo:
				
		Sumar la clave a la letra mayúscula introducida.
		
		Calcular el resultado final dotándolo de estructura circular
		(destacar que todos los cálculos se realizan según la correspondencia
		de las letras mayúsculas en código ASCII).
	*/
	
	suma = mayuscula + clave;
	mayus_codificada = PRIMERA_LETRA + ((suma - PRIMERA_LETRA) % LONG_ALFABETO);
	
	// Salidas
	
	cout << endl << " Con una clave igual a " << clave << ", el caracter "
	     << mayuscula << " se codifica en el caracter " << mayus_codificada
		 << endl << endl;
	
	return 0;
}
