/*
	Relaci�n de ejercicios 1

	Ejercicio 37: Programa que, dados dos puntos en el plano, calcula la 
				  distancia eucl�dea entre ellos.
	
	Entradas: Coordenadas de los dos puntos (x_1, y_1, x_2, y_2).
	Salidas: Distancia eucl�dea entre ellos (distancia_euclidea).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>		// Inclusi�n de los recursos de E/S
#include <cmath>		// Inclusi�n de los recursos matem�ticos

using namespace std;

// Programa principal

int main() {
	
	// Declaraci�n de variables
	
	double x_1 = 0.0, y_1 = 0.0;
	double x_2 = 0.0, y_2 = 0.0;
	double distancia_euclidea = 0.0;
	
	// Entradas de datos
	
	cout << " Introduzca la coordenada x del primer punto: ";
	cin >> x_1;
	cout << " Introduzca la coordenada y del primer punto: ";
	cin >> y_1;

	cout << endl << " Introduzca la coordenada x del segundo punto: ";
	cin >> x_2;
	cout << " Introduzca la coordenada y del segundo punto: ";
	cin >> y_2;
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Calcular la distancia eucl�dea entre los dos puntos usando la f�rmula:
		
							          --------------------------------
		        Distancia eucl�dea = V  (x_1 - x_2)^2 + (y_1 - y_2)^2
	*/
	
	distancia_euclidea = sqrt(((x_1 - x_2) * (x_1 - x_2)) + 
	                          ((y_1 - y_2) * (y_1 - y_2))); 
	
	// Salidas
	
	cout << endl << " La distancia entre (" << x_1 << ", " << y_1 << ") y ("
	     << x_2 << ", " << y_2 << ") es " << distancia_euclidea << endl << endl;

	return 0;
}
