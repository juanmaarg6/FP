/*
	Relación de ejercicios 1

	Ejercicio 37: Programa que, dados dos puntos en el plano, calcula la 
				  distancia euclídea entre ellos.
	
	Entradas: Coordenadas de los dos puntos (x_1, y_1, x_2, y_2).
	Salidas: Distancia euclídea entre ellos (distancia_euclidea).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>		// Inclusión de los recursos de E/S
#include <cmath>		// Inclusión de los recursos matemáticos

using namespace std;

// Programa principal

int main() {
	
	// Declaración de variables
	
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
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Calcular la distancia euclídea entre los dos puntos usando la fórmula:
		
							          --------------------------------
		        Distancia euclídea = V  (x_1 - x_2)^2 + (y_1 - y_2)^2
	*/
	
	distancia_euclidea = sqrt(((x_1 - x_2) * (x_1 - x_2)) + 
	                          ((y_1 - y_2) * (y_1 - y_2))); 
	
	// Salidas
	
	cout << endl << " La distancia entre (" << x_1 << ", " << y_1 << ") y ("
	     << x_2 << ", " << y_2 << ") es " << distancia_euclidea << endl << endl;

	return 0;
}
