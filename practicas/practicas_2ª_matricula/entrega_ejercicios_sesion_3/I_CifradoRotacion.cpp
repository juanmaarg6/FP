/*
	Relaci�n de ejercicios 1

	Ejercicio 28: Programa que, dadas una clave representada por un n�mero
	              entero y una letra may�scula, codifica el car�cter seg�n
	              la clave introducida.
	              
	              Para codificar el car�cter se considera una representaci�n 
				  circular del alfabeto, de tal forma que el car�cter que
				  sigue a 'Z' es 'A'. Por ejemplo, si clave = 4, entonces la 
				  'A' se reemplaza por la 'E' y la 'Z' por la 'D'. Utilizando 
				  clave = 0 la secuencia cifrada es igual a la original.
	
	Entradas: Clave (clave),
	          Letra may�scula (mayuscula).
	Salidas: Letra may�scula codificada (mayuscula_codificada).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusi�n de los recursos de E/S

using namespace std;

// Programa principal

int main() {				

	// Declaraci�n de constantes
	
	const int LONG_ALFABETO = 'Z' - 'A' + 1;
	const char PRIMERA_LETRA = 'A';
		
	// Declaraci�n de variables
	
	int clave = 0, suma = 0;
	char mayuscula = 'a', mayus_codificada = 'a';
							
	// Entradas de datos
	
	cout << " Introduzca una clave (valor entero): ";
	cin >> clave;
	cout << " Introduzca una letra mayuscula: ";
	cin >> mayuscula;
	
	// C�lculos
	
	/*
		Algoritmo:
				
		Sumar la clave a la letra may�scula introducida.
		
		Calcular el resultado final dot�ndolo de estructura circular
		(destacar que todos los c�lculos se realizan seg�n la correspondencia
		de las letras may�sculas en c�digo ASCII).
	*/
	
	suma = mayuscula + clave;
	mayus_codificada = PRIMERA_LETRA + ((suma - PRIMERA_LETRA) % LONG_ALFABETO);
	
	// Salidas
	
	cout << endl << " Con una clave igual a " << clave << ", el caracter "
	     << mayuscula << " se codifica en el caracter " << mayus_codificada
		 << endl << endl;
	
	return 0;
}
