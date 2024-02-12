/*
	Ejercicio 16: Programa que pasa un carácter (dígito entre '0' y '9')
				     a un número entero.
					  
	Entrada: carácter (caracter).
	Salida: número entero (entero).

	Código fuente escrito por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

int main(){	

	// Declaración de variables
	
	char caracter;
	int entero;
	
	/*
	Al sumar/restar dos caracteres, el resultado es la suma/resta de los órdenes en el código
	ASCII de dichos caracteres, es decir, el resultado es un entero. Por tanto, usaremos el
	orden del carácter '0' para restárselo al caracter numérico y que así
	devuelva su valor entero correspondiente.
   */
	
   const char ORDEN_ASCII_CERO = '0';		

	// Entrada de datos
	
   cout << "Introduzca un caracter numerico: ";
   cin >> caracter;
   
   // Conversión de caracter a entero

   entero = caracter - ORDEN_ASCII_CERO;   
   
   // Resultado mostrado en pantalla

   cout << "\nEl caracter numerico " << caracter << " tiene el siguiente entero correspondiente: " << entero << "\n\n";

	system("pause");
}
