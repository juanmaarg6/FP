/*
	Relaci�n de ejercicios 1

	Ejercicio 20: Programa que, dado el ritmo de un atleta, muestra la
				  velocidad y, dada la velocidad de un atleta, muestra el
				  ritmo.
	
	Entradas: Ritmo del atleta (minutos1, segundos1),
	          Velocidad del atleta (velocidad2).
	Salidas: Velocidad del atleta seg�n su ritmo (velocidad1),
			 Ritmo del atleta seg�n su velocidad (minutos2, segundos2).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusi�n de librer�a de recursos de E/S

using namespace std;

// Programa principal

int main() {				

	// Declaraci�n de variables
	
	int minutos1, segundos1, minutos2, segundos2;
	double calculo_segs_un_km1;
	int calculo_segs_un_km2;
	double velocidad1, velocidad2;
							
	// Entradas de datos
	
	cout << " Programa 1: Dado el ritmo de un atleta muestra su velocidad";
	cout << endl << endl << "\t Introduzca el ritmo del atleta: " << endl;							
	cout << endl << "\t\t Minutos: ";
	cin >> minutos1;
	cout << "\t\t Segundos: ";
	cin >> segundos1;
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Convertir el ritmo del atleta en minutos y segundos por kil�metro a
		segundos por kil�metro.
		
		Dividir 3600 segundos (equivale a 1 hora) por el ritmo del atleta en 
		segundos por kil�metro, obteniendo as� la velocidad del atleta en
		kil�metros por hora. 
	*/
	
	calculo_segs_un_km1 = (minutos1 * 60) + segundos1;
	velocidad1 = 3600 / calculo_segs_un_km1;
	
	// Salidas
	
	cout << endl << "\t Velocidad del atleta: " << velocidad1 << " km/h";
	cout << endl << endl;
	
	// Entradas de datos
	
	cout << " Programa 2: Dada la velocidad de un atleta muestra su ritmo";
	cout << endl << endl << "\t Introduzca la velocidad del atleta: ";
	cin >> velocidad2;
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Dividir 3600 segundos (equivale a 1 hora) por la velocidad del atleta 
		en kil�metros por hora, obteniendo as� cu�ntos segundos tarda el 
		atleta en recorrer un kil�metro.
		
		Expresar el total de segundos que tarda el atleta en recorrer un 
		kil�metro en minutos por segundo, obteniendo as� el ritmo del atleta.
	*/
	
	calculo_segs_un_km2 = 3600 / velocidad2;
	minutos2 = calculo_segs_un_km2 / 60;
	segundos2 = calculo_segs_un_km2 % 60;

	// Salidas
	
	cout << endl << "\t Ritmo del atleta: " << minutos2 << " minutos y "
	     << segundos2 << " segundos" << endl << endl; 
	
	system("pause");
	return 0;
}
