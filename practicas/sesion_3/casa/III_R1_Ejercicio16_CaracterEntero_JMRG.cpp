/*
	Ejercicio 16: Programa que pasa un car�cter (d�gito entre '0' y '9')
				     a un n�mero entero.
					  
	Entrada: car�cter (caracter).
	Salida: n�mero entero (entero).

	C�digo fuente escrito por Juan Manuel Rodr�guez G�mez.
*/

#include <iostream>

using namespace std;

int main(){	

	// Declaraci�n de variables
	
	char caracter;
	int entero;
	
	/*
	Al sumar/restar dos caracteres, el resultado es la suma/resta de los �rdenes en el c�digo
	ASCII de dichos caracteres, es decir, el resultado es un entero. Por tanto, usaremos el
	orden del car�cter '0' para rest�rselo al caracter num�rico y que as�
	devuelva su valor entero correspondiente.
   */
	
   const char ORDEN_ASCII_CERO = '0';		

	// Entrada de datos
	
   cout << "Introduzca un caracter numerico: ";
   cin >> caracter;
   
   // Conversi�n de caracter a entero

   entero = caracter - ORDEN_ASCII_CERO;   
   
   // Resultado mostrado en pantalla

   cout << "\nEl caracter numerico " << caracter << " tiene el siguiente entero correspondiente: " << entero << "\n\n";

	system("pause");
}
