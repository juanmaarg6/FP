/*
	Ejercicio 7: Programa que calcula la media aritmetica muestral y la desviacion
					 tipica muestral de las alturas de tres personas.
	
	Entradas: alturas de las tres personas (altura1, altura2, altura3).
	Salidas: media aritmetica muestral (media) y desviacion tipica muestral (desviacion)
			   de las tres alturas.

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>	
#include <cmath>	

using namespace std;

int main(){							      
	double altura1, altura2, altura3;			// Datos de entrada
	double argumento_raiz;						   // Variable para almacenar el argumento de la raiz de la desviacion tipica
	double media, desviacion;			     	   // Datos de salida
							
	cout << "Introduzca la primera altura (en cm): ";			//El usuario introduce los datos requeridos
	cin >> altura1;
	cout << "Introduzca la segunda altura (en cm): ";	
	cin >> altura2;
	cout << "Introduzca la tercera altura (en cm): ";	
	cin >> altura3;
	
	media = (altura1 + altura2 + altura3) / 3;		 																	// Se realizan los calculos.
	argumento_raiz = (pow(altura1 - media,2) + pow(altura2 - media,2) + pow(altura3 - media,2)) / 3;
	desviacion = sqrt(argumento_raiz);

	cout << "\nMedia aritmetica: " << media;		                       //Se muestra al usuario los resultados de la media
	cout << "\nDesviacion tipica: " << desviacion << "\n\n";	           // y la desviacion
	
	system("pause");
}
