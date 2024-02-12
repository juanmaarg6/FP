/*
	Relaci�n de ejercicios 1

	Ejercicio 2: Programa para calcular un voltaje (en voltios), 
				 seg�n la Ley de Ohm, dados los valores de la intensidad 
				 (en amperios) y la resistencia (en ohmios).
	
	Entrada: Intensidad (intensidad), Resistencia (resistencia).
	Salidas: Voltaje (voltaje).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusi�n de librer�a de recursos de E/S

using namespace std;

// Programa principal

int main(){
	
	// Declaraci�n de variables
	
	double intensidad = 0, resistencia = 0, voltaje = 0; 				
						
	// Entradas de datos
	
	cout << " Introduzca el valor de la intensidad (en amperios): ";
	cin >> intensidad;		
	cout << " Introduzca el valor de la resistencia (en ohmios): ";
	cin >> resistencia;
			
	// C�lculos
	
	voltaje = intensidad * resistencia;
			
	// Salidas
	
	cout << endl << " El voltaje es de " << voltaje  << " voltios";
	cout << endl << endl; 
	
	system("pause");
	return 0;
}
