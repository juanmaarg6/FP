/*
	Ejercicio 6: Programa para intercambiar el valor de dos variables enteras
					 (en este caso, las variables seran edades).
	
	Entradas: edad de Pedro (edad_Pedro) y edad de Juan (edad_Juan).
	Salida: edades intercambiadas, es decir, la edad introducida para Pedro
			  aparecera como la edad de Juan y viceversa.

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			//Inclusión de librería de recursos de E/S

using namespace std;

int main(){							      //Programa principal
	int edad_Pedro; 				      //Declaracion de variables
	int edad_Juan;
	
	int intercambio;		
						
	cout << "Introduzca la edad de Pedro: ";			//El usuario introduce los datos requeridos
	cin >> edad_Pedro;
	cout << "Introduzca la edad de Juan: ";	
	cin >> edad_Juan;
	
	cout << "\nInicialmente, Pedro tiene " << edad_Pedro << " años y Juan tiene " << edad_Juan << " años";		//Se muestra al usuario ambas edades sin intercambiar
	
	intercambio = edad_Pedro;			//La edad de Pedro pasa a ser almacenada en la variable auxiliar 'intercambio'
	edad_Pedro = edad_Juan;
	edad_Juan = intercambio;
		
	cout << "\nTras el intercambio, ahora Pedro tiene " << edad_Pedro << " años y Juan tiene " << edad_Juan << " años\n\n";		//Se muestra el resultado al usuario tras 
																																										//intercambiar las edades			
	
	system("pause");
}
