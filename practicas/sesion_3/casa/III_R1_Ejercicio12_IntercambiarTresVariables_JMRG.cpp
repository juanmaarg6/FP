/*
	Ejercicio 12: Programa que declara tres variables e intercambian
					  sus valores entre s�.
					  
	Entradas: tres variables (x, y, z).
	Salidas: tres variables pero con sus valores intercambiados entre
			  s�, de forma que el valor de 'x' pasa a 'y', el valor de 
			  'y' pasa a 'z' y el valor de 'z' pasa a 'x'.
			  
			  						y <-- x <-- z

	C�digo fuente escrito por Juan Manuel Rodr�guez G�mez.
*/

#include <iostream>

using namespace std;

int main(){	

	// Declaraci�n de variables
	
	int x, y, z;
	int copia_x;		// Variable auxiliar
	
	// Asignaci�n de valores y muestra en pantalla
	
	x = 10;
	y = 20;
	z = 30;
	
	copia_x = x;
	
	cout << "Inicialmente, los valores de las tres variables son: ";
	cout << "\n\n\tx = " << x;
	cout << "\n\ty = " << y;
	cout << "\n\tz = " << z;
	
	// Intercambio de los valores de las variables
		
	x = z;
	z = y;
	y = copia_x;
	
	// Resultado mostrado en pantalla
	
	cout << "\n\nTras el intercambio, los valores de las tres variables son: ";
	cout << "\n\n\tx = " << x;
	cout << "\n\ty = " << y;
	cout << "\n\tz = " << z << "\n\n";

	system("pause");
}
