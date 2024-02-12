/*
	Relaci�n de ejercicios 1

	Ejercicio 24: Programa que, dada la media, la desviaci�n t�pica y un punto
	              de abscisa de una funci�n gaussiana, muestra el valor que
	              toma la funci�n en dicho punto de abscisa.
	
	Entradas: Media (media),
	          Desviaci�n t�pica (desviacion)
	          Abscisa en la que se evaluar� la funci�n (abscisa).
	Salidas: Valor que toma la funci�n gaussiana en x (gaussiana).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusi�n de librer�a de recursos de E/S
#include <cmath>		    // Inclusi�n de librer�a de recursos matematicos

using namespace std;

// Programa principal
  
int main() {					

	// Declaraci�n de constantes
	
	const double PI = asin(0.5) * 6;
	
	// Declaraci�n de variables
 		             
	double media = 0.0, desviacion = 0.0; 				     
	double abscisa = 0.0;
	double gaussiana = 0.0;
	double fraccion = 0.0, exponencial = 0.0;
				
	// Entradas de datos
						
	cout << " Introduzca el valor de la media: ";
	cin >> media;
	cout << " Introduzca el valor de la desviacion tipica: ";	
	cin >> desviacion;
	cout << " Introduzca la abscisa en la que se va a evaluar la funcion: ";
	cin >> abscisa;
				
	// C�lculos
	
	fraccion = (1 / (desviacion * sqrt(2 * PI)));
	exponencial = exp(-0.5 * pow((abscisa - media) / desviacion, 2));
	gaussiana =  fraccion * exponencial;
			
	// Salidas
	
	cout << "\n El valor que toma la funcion gaussiana en " << abscisa
	     << " es igual a " << gaussiana << endl << endl; 
	
	system("pause");
	return 0;
}
