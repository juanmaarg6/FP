/*
	Relaci�n de ejercicios 2

	Ejercicio 9: Programa que, dadas una clave representada por un n�mero
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
	
	const char PRIMERA_LETRA = 'A';
	const char ULTIMA_LETRA = 'Z';
	
	// Declaraci�n de variables
	
	int clave = 0, suma = 0;
	char mayuscula = 'a', mayuscula_codificada = 'a';
							
	// Entradas de datos
	
	cout << " Introduzca una clave (valor entero): ";
	cin >> clave;
	cout << " Introduzca una letra mayuscula: ";
	cin >> mayuscula;
	
	// C�lculos
	
	/*
		Algoritmo:
				
		Sumar la clave a la letra may�scula.
		
		Si la clave es mayor o igual que 0:
		
			Si la suma anterior supera a la �ltima letra del alfabeto, 
			la codificaci�n se calcula mediante una estructura circular.
			
			Si no, la codificaci�n es igual a la suma.
			
		Si no (es decir, la clave es menor que 0):
		
			Si la suma (realmente es una resta) anterior supera a la primera
			letra del alfabeto, la codificaci�n se calcula mediante una 
			estructura circular.
			
			Si no, la codifcaci�n es igual a la suma.
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
