/*
	Ejercicio 15: Programa que pasa una letra de mayúscula a minúscula
					  
	Entrada: letra mayúscula (mayuscula).
	Salida: letra minúscula (minuscula).

	Código fuente escrito por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

int main(){	

	// Declaración de variables
	
	char minuscula, mayuscula;
	
   const int distancia_mayus_minus = 'a'-'A';		// Indica el número de caracteres que hay entre
   													   	   // 'A' y 'a' en el código ASCII. Esta distancia
   													   	   // (32) será la misma para cualquier letra en
   													   	   // mayúscula con su respectiva minúscula.

	// Entrada de datos
	
   cout << "Introduzca una letra mayuscula: ";
   cin >> mayuscula;
   
   // Conversión de mayúscula a minúscula

   minuscula = mayuscula + distancia_mayus_minus;   
   
   // Resultado mostrado en pantalla

   cout << "\nLa letra " << mayuscula << " en minuscula es: " << minuscula << "\n\n";

	system("pause");
}
