/*
	Relación de ejercicios 1

	Ejercicio 15: Programa que, dada una longitud en metros, muestra la
	              longitud equivalente en pulgadas, pies, yardas y millas.
	
	Entradas: Longitud en metros (metros).
	Salidas: Longitud en pulgadas (pulgadas),
		     Longitud en pies (pies),
		     Longitud en yardas (yardas),
			 Longitud en pulgadas (millas).
			 
	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusión de librería de recursos de E/S

using namespace std;

// Programa principal

int main() {
	
	// Declaración de constantes
	
	const double METROS_A_PULGADAS = 0.0254;
	const double METROS_A_PIES = 0.3048;
	const double METROS_A_YARDAS = 0.9144;
	const double METROS_A_MILLAS = 1609.344;

	// Declaración de variables	

	double metros = 0.0;
	double pulgadas = 0.0;
	double pies = 0.0;
	double yardas = 0.0;	
	double millas = 0.0;
	
	// Entradas de datos
	
	cout << " Introduzca una longitud (en metros): ";	
	cin >> metros;
				
	// Cálculos 
	
	pulgadas = metros / METROS_A_PULGADAS;			 
	pies = metros / METROS_A_PIES;
	yardas = metros / METROS_A_YARDAS;
	millas = metros / METROS_A_MILLAS;
	
	// Salidas
	
	cout << endl << " " << metros << " metros equivalen a: " << endl << endl;
	cout << "\t Pulgadas: " << pulgadas << " pulgadas" << endl;
	cout << "\t Pies: " << pies << " pies" << endl;
	cout << "\t Yardas: " << yardas << " yardas" << endl;
	cout << "\t Millas: " << millas << " millas" << endl << endl;
	
	system("pause");
	return 0;
}
