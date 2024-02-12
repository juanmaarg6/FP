/*
	Relación de ejercicios 1

	Ejercicio 17: Programa que, dadas dos cajas que contienen una cierta
	              cantidad de dinero dentro, intercambia las cantidades
	              de cada caja y muestra el resultado final.
	              
	
	Entradas: Cantidad de dinero de la caja izquierda (caja_izda),
	          Cantidad de dinero de la caja derecha (caja_dcha).
	Salidas: Cantidad de dinero de dinero de la caja izquierda tras
	         el intercambio (caja_izda),
	         Cantidad de dinero de dinero de la caja derecha tras
	         el intercambio (caja_dcha).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusión de librería de recursos de E/S

using namespace std;

// Programa principal
   
int main() {					

	// Declaracion de variables
 		   
	double caja_izda, caja_dcha, intercambio; 				     
							
	// Entradas de datos
	
	cout << " Introduzca la cantidad de dinero de la caja izquierda: ";
	cin >> caja_izda;
	cout << " Introduzca la cantidad de dinero de la caja derecha: ";	
	cin >> caja_dcha;
	
	cout << "\n Cantidades de dinero antes del intercambio: " << endl;
	cout << endl << "\t Caja izquierda: " << caja_izda << endl;
	cout << "\t Caja derecha: " << caja_dcha << endl;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Guardar la cantidad de dinero de la caja izquierda en una variable
		auxiliar.
		
		Asignar la cantidad de dinero de la caja derecha a la caja izquierda.
		
		Asignar el valor de la variable auxiliar (donde se encuentra la
		cantidad de dinero de la caja izquierda) a la caja derecha.
	*/
	
	intercambio = caja_izda;
	caja_izda = caja_dcha;
	caja_dcha = intercambio;
		
	// Salidas
	
	cout << "\n Cantidades de dinero despues del intercambio: " << endl;
	cout << endl << "\t Caja izquierda: " << caja_izda << endl;
	cout << "\t Caja derecha: " << caja_dcha << endl << endl;
		
	system("pause");
	return 0;
}
