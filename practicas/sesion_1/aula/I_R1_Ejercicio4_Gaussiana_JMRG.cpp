/*
	Ejercicio 4: Programa para calcular el valor de una funcion gaussiana en un punto
	             de abscisa x, dados sus parametros (media y desviacion tipica).
	
	Entradas: parametros de la funcion (media, desviacion) y punto de abscisa en el
	          que se va a evaluar la funcion (x).
	Salida: valor que toma la funcion gaussiana en x (gaussiana)

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			//Inclusión de librería de recursos de E/S
#include <cmath>		      //Inclusión de librería de recursos matematicos

using namespace std;

int main(){							               //Programa principal
	double media, desviacion; 				      //Declaracion de variables
	double x;
	double gaussiana;
	
	const double PI = 3.1415927;
				
						
	cout << "Introduzca el valor de la media: ";			//El usuario introduce los datos requeridos
	cin >> media;
	cout << "Introduzca el valor de la desviacion tipica: ";	
	cin >> desviacion;
	cout << "Introduzca el valor del punto de abscisa en el que se va a evaluar la funcion: ";
	cin >> x;
				
	gaussiana = (1 / (desviacion * sqrt(2 * PI))) * exp(-0.5 * pow((x - media) / desviacion, 2));		 //Se calcula el resultado
			
	cout << "\nEl valor que toma la funcion gaussiana en " << x << " es igual a " << gaussiana << "\n\n";  	    //Se muestra el resultado al usuario
	
	system("pause");
}
