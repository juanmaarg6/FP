/*
	Relación de ejercicios 1

	Ejercicio 39: Programa que traduce tres fórmulas matemáticas
	              a expresiones válidas en el lenguaje de C++.
	              
	Entradas: Variable x (x),
	          Variable y (y),
	          Variable h (h).
	Salidas: Fórmulas matemáticas (expresion_a, expresion_b, expresion_c).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de los recursos de E/S
#include <cmath>		// Inclusión de los recursos matemáticos		

using namespace std;

// Programa principal

int main(){	

   // Declaración de variables	
   					      
	double x = 0.0, y = 0.0, h = 0.0;		                        
	double expresion_a = 0.0, expresion_b = 0.0, expresion_c = 0.0;
	double fraccion_expresion_c = 0.0;
		
	/**********************************************************************/    
   				
   	// Entradas de datos
   	
	cout << " Primera expresion: " << endl << endl;	
	cout << "\t Introduzca el valor de la variable x: ";
	cin >> x;
	cout << "\t Introduzca el valor de la variable y: ";
	cin >> y;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Traducir la fórmula dada a una expresión válida en C++ (evitamos el
		uso de la función pow para mejorar la eficiencia del programa).
		
		Calcular el valor que toma la expresión para cierto valor de las
		variables x e y.
	*/
	
	expresion_a = (1 + ((x * x) / y)) / ((x * x * x) / (1 + y));
	
	// Salidas
	
	cout << endl << " \t El valor que toma la primera expresion para x = " << x 
	     << ", y = " << y << " es: " << expresion_a << endl << endl;
	
	/**********************************************************************/
   	
	// Entradas de datos
	
	cout << " Segunda expresion: " << endl << endl;	
	cout << "\t Introduzca el valor de la variable h: ";
	cin >> h;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Traducir la fórmula dada a una expresión válida en C++.
		
		Calcular el valor que toma la expresión para cierto valor de la
		variable h.
	*/
	
    expresion_b = (1 + (sin(h)/3.0) - (cos(h)/7.0)) / (2 * h);
	
	// Salidas
	
	cout << endl << "\t El valor que toma la segunda expresion para h = " << h 
	<< " es: " << expresion_b << endl << endl;
	
	/**********************************************************************/
   	
   	// Entradas de datos
   	
	cout << " Tercera expresion: " << endl << endl;			
	cout << "\t Introduzca el valor de la variable x: ";
	cin >> x;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Traducir la fórmula dada a una expresión válida en C++.
		
		Calcular el valor que toma la expresión para cierto valor de la
		variable x.
	*/
	
	fraccion_expresion_c = exp(x) / (x * x);
    expresion_c = sqrt(1 + (fraccion_expresion_c * fraccion_expresion_c));
	
	// Salidas
	
	cout << endl << "\t El valor que toma la tercera expresion para x = " << x 
	     << " es: " << expresion_c << endl << endl;
	
	return 0;
}
