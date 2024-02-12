/*
	Ejercicio 15: Programa que pasa una letra de may�scula a min�scula
					  
	Entrada: letra may�scula (mayuscula).
	Salida: letra min�scula (minuscula).

	C�digo fuente escrito por Juan Manuel Rodr�guez G�mez.
*/

#include <iostream>

using namespace std;

int main(){	

	// Declaraci�n de variables
	
	char minuscula, mayuscula;
	
   const int distancia_mayus_minus = 'a'-'A';		// Indica el n�mero de caracteres que hay entre
   													   	   // 'A' y 'a' en el c�digo ASCII. Esta distancia
   													   	   // (32) ser� la misma para cualquier letra en
   													   	   // may�scula con su respectiva min�scula.

	// Entrada de datos
	
   cout << "Introduzca una letra mayuscula: ";
   cin >> mayuscula;
   
   // Conversi�n de may�scula a min�scula

   minuscula = mayuscula + distancia_mayus_minus;   
   
   // Resultado mostrado en pantalla

   cout << "\nLa letra " << mayuscula << " en minuscula es: " << minuscula << "\n\n";

	system("pause");
}
