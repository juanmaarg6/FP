/*
	Relación de ejercicios 1

	Ejercicio 24: Programa que, dada la media, la desviación típica y un punto
	              de abscisa de una función gaussiana, muestra el valor que
	              toma la función en dicho punto de abscisa.
	
	Entradas: Media (media),
	          Desviación típica (desviacion)
	          Abscisa en la que se evaluará la función (abscisa).
	Salidas: Valor que toma la función gaussiana en x (gaussiana).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusión de librería de recursos de E/S
#include <cmath>		    // Inclusión de librería de recursos matematicos

using namespace std;

// Programa principal
  
int main() {					

	// Declaración de constantes
	
	const double PI = asin(0.5) * 6;
	
	// Declaración de variables
 		             
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
				
	// Cálculos
	
	fraccion = (1 / (desviacion * sqrt(2 * PI)));
	exponencial = exp(-0.5 * pow((abscisa - media) / desviacion, 2));
	gaussiana =  fraccion * exponencial;
			
	// Salidas
	
	cout << "\n El valor que toma la funcion gaussiana en " << abscisa
	     << " es igual a " << gaussiana << endl << endl; 
	
	system("pause");
	return 0;
}
