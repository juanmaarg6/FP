/*
	Relaci�n de ejercicios 2

	Modificaci�n del Ejercicio 24 
	de la Relaci�n de Ejercicios 1: Programa que, dada la media, la desviaci�n 
									t�pica y un punto de abscisa de una funci�n 
									gaussiana, muestra el valor que toma la 
									funci�n en dicho punto de abscisa.
	
	Entradas: Media (media),
	          Desviaci�n t�pica (desviacion)
	          Abscisa en la que se evaluar� la funci�n (abscisa).
	Salidas: Valor que toma la funci�n gaussiana en x (gaussiana).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusi�n de los recursos de E/S
#include <cmath>		    // Inclusi�n de los recursos matematicos

using namespace std;

// Programa principal
  
int main() {					

	// Declaraci�n de constantes
	
	const double PI = asin(0.5) * 6;
	
	// Declaraci�n de variables
 		             
	double media = 0.0, desviacion = 0.0;
				
	// Entradas de datos
						
	cout << " Introduzca el valor de la media: ";
	cin >> media;
	cout << " Introduzca el valor de la desviacion tipica: ";	
	cin >> desviacion;
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Si 'desviacion' es mayor que 0:
			
			Introducir el valor del punto de abscisa en el que se va a
			calcular el valor de la funci�n gaussiana.
			
			Calcular la parte racional de la funci�n gaussiana dada por:
			
							       1
					   -------------------------
						              ---------
						Desviaci�n * V  2 * PI
					
			Calcular la parte exponencial de la funci�n gaussiana dada por:
			
													
							   1      Abscisa - Media  2 
						  { - --- * (----------------)	 }				
							   2		Desviaci�n		
						e
					
			Multiplicar la parte racional por la parte exponencial, obteniendo 
			as� el valor que toma la funci�n gaussiana en el punto de abscisa 
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
