/*
	Relaci�n de ejercicios 1

	Ejercicio 23: Programa que, dadas las alturas de tres personas en cm,
	              calcula la media aritm�tica muestral y la desviaci�n
				  t�pica muestral.
	
	Entradas: Alturas de las tres personas en cm (altura1, altura2, altura3).
	Salidas: Media aritm�tica muestral (media),
	         Desviaci�n t�pica muestral (desviacion).
	         

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>		// Inclusi�n de librer�a de recursos de E/S
#include <cmath>		// Inclusi�n de librer�a de recursos matematicos	

using namespace std;

// Programa principal

int main() {	

	// Declaraci�n de variables	
						      
	double altura1 = 0.0, altura2 = 0.0, altura3 = 0.0;
	double sumando1 = 0.0, sumando2 = 0.0, sumando3 = 0.0;
	double argumento_raiz = 0.0;		
	double media = 0.0, desviacion = 0.0;			
	
	// Entradas de datos
	
	cout << " Introduzca la primera altura (en cm): ";
	cin >> altura1;
	cout << " Introduzca la segunda altura (en cm): ";	
	cin >> altura2;
	cout << " Introduzca la tercera altura (en cm): ";	
	cin >> altura3;
	
	// C�lculos
	
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
