/*
	Relación de ejercicios 1

	Ejercicio 23: Programa que, dadas las alturas de tres personas en cm,
	              calcula la media aritmética muestral y la desviación
				  típica muestral.
	
	Entradas: Alturas de las tres personas en cm (altura1, altura2, altura3).
	Salidas: Media aritmética muestral (media),
	         Desviación típica muestral (desviacion).
	         

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>		// Inclusión de librería de recursos de E/S
#include <cmath>		// Inclusión de librería de recursos matematicos	

using namespace std;

// Programa principal

int main() {	

	// Declaración de variables	
						      
	double altura1, altura2, altura3;
	double sumando1, sumando2, sumando3, argumento_raiz;
	double media, desviacion;			
	
	// Entradas de datos
	
	cout << " Introduzca la primera altura (en cm): ";
	cin >> altura1;
	cout << " Introduzca la segunda altura (en cm): ";	
	cin >> altura2;
	cout << " Introduzca la tercera altura (en cm): ";	
	cin >> altura3;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Sumar las tres alturas y dividir el resultado de la suma por el 
		número de personas (3 en este caso), obteniendo así la media.
		
		Calcular la diferencia de cada altura menos la media, elevando el
		resultado al cuadrado. Sumar los tres resultados anteriores y dividir 
		el resultado de la suma por el número de personas (3 en este caso).
		Aplicarle una raíz cuadrada al último resultado calculado, obteniendo
		así la desviación.
	*/
	
	media = (altura1 + altura2 + altura3) / 3;
	sumando1 = pow(altura1 - media,2);
	sumando2 = pow(altura2 - media,2);
	sumando3 = pow(altura3 - media,2);
	argumento_raiz = (sumando1 + sumando2 + sumando3) / 3;
	desviacion = sqrt(argumento_raiz);

	// Salidas
	
	cout << endl << " Media aritmetica: " << media << " cm" << endl;
	cout << " Desviacion tipica: " << desviacion << " cm" << endl << endl;
	
	system("pause");
	return 0;
}
