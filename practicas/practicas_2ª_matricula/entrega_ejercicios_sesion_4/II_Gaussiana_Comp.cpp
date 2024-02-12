/*
	Relación de ejercicios 2

	Modificación del Ejercicio 24 
	de la Relación de Ejercicios 1: Programa que, dada la media, la desviación 
									típica y un punto de abscisa de una función 
									gaussiana, muestra el valor que toma la 
									función en dicho punto de abscisa.
	
	Entradas: Media (media),
	          Desviación típica (desviacion)
	          Abscisa en la que se evaluará la función (abscisa).
	Salidas: Valor que toma la función gaussiana en x (gaussiana).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusión de los recursos de E/S
#include <cmath>		    // Inclusión de los recursos matematicos

using namespace std;

// Programa principal
  
int main() {					

	// Declaración de constantes
	
	const double PI = asin(0.5) * 6;
	
	// Declaración de variables
 		             
	double media = 0.0, desviacion = 0.0;
				
	// Entradas de datos
						
	cout << " Introduzca el valor de la media: ";
	cin >> media;
	cout << " Introduzca el valor de la desviacion tipica: ";	
	cin >> desviacion;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Si 'desviacion' es mayor que 0:
			
			Introducir el valor del punto de abscisa en el que se va a
			calcular el valor de la función gaussiana.
			
			Calcular la parte racional de la función gaussiana dada por:
			
							       1
					   -------------------------
						              ---------
						Desviación * V  2 * PI
					
			Calcular la parte exponencial de la función gaussiana dada por:
			
													
							   1      Abscisa - Media  2 
						  { - --- * (----------------)	 }				
							   2		Desviación		
						e
					
			Multiplicar la parte racional por la parte exponencial, obteniendo 
			así el valor que toma la función gaussiana en el punto de abscisa 
			dado.
			
		Si no, mostrar mensaje de error.
	*/
	
	bool datos_correctos = (desviacion > 0);
	
	if(datos_correctos) {
		
		double abscisa = 0.0, gaussiana = 0.0; 				     
		double fraccion, exponencial;
	
		cout << " Introduzca el valor de la abscisa en el que se"
		     << " va a evaluar la funcion: ";
		cin >> abscisa;
	
		fraccion = (1 / (desviacion * sqrt(2 * PI)));
		exponencial = exp(-0.5 * pow((abscisa - media) / desviacion, 2));
		gaussiana =  fraccion * exponencial;
		
		// Salidas
		
		cout << endl << " El valor que toma la funcion gaussiana en " 
		     << abscisa << " es igual a " << gaussiana << endl << endl; 
	}
	else {
		
		// Mensaje de error
		
		cout << endl << " Error: El valor de 'desviacion' es incorrecto.";
		cout << endl << "        Se requiere: 'desviacion' > 0";
		cout << endl << endl;
	}
	
	return 0;
}
