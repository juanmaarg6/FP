/*
	Relación de ejercicios 1

	Ejercicio 2: Programa para calcular un voltaje (en voltios), 
				 según la Ley de Ohm, dados los valores de la intensidad 
				 (en amperios) y la resistencia (en ohmios).
	
	Entrada: Intensidad (intensidad), Resistencia (resistencia).
	Salidas: Voltaje (voltaje).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusión de librería de recursos de E/S

using namespace std;

// Programa principal

int main(){
	
	// Declaración de variables
	
	double intensidad = 0, resistencia = 0, voltaje = 0; 				
						
	// Entradas de datos
	
	cout << " Introduzca el valor de la intensidad (en amperios): ";
	cin >> intensidad;		
	cout << " Introduzca el valor de la resistencia (en ohmios): ";
	cin >> resistencia;
			
	// Cálculos
	
	voltaje = intensidad * resistencia;
			
	// Salidas
	
	cout << endl << " El voltaje es de " << voltaje  << " voltios";
	cout << endl << endl; 
	
	system("pause");
	return 0;
}
