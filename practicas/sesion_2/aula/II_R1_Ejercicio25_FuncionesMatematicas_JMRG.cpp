/*
	Ejercicio 25: Programa que traduce tres formulas matematicas
	              a expresiones validas en el lenguaje de C++.
	
	Entradas: variables x (x), y (y), h (h).
	Salidas: tres formulas matematicas (expresion_a, expresion_b, expresion_c).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>
#include <cmath>		

using namespace std;

int main(){	
   // Declaracion de variables	
   					      
	double x, y, h;											  // Datos de entrada		                        
	double expresion_a, expresion_b, expresion_c;	  // Datos de salida
	double fraccion_expresion3;
		
   // Primera expresion	
   				
	cout << "Primera expresion\n\n";					// Entradas			
	cout << "\tIntroduzca el valor de x: ";
	cin >> x;
	cout << "\tIntroduzca el valor de y: ";
	cin >> y;
	
	expresion_a = (1 + x * x / y) / (x * x * x / (1 + y));		// Calculos
	
	cout << "\n\tEl valor que toma la primera expresion para x = " << x << ", y = " << y << " es: " << expresion_a << "\n\n";		// Salida
	
	// Segunda expresion	
   				
	cout << "Segunda expresion\n\n";					// Entradas	
	cout << "\tIntroduzca el valor de h: ";
	cin >> h;
	
   expresion_b = (1 + sin(h)/3.0 - cos(h)/7.0) / (2 * h);		// Calculos
	
	cout << "\n\tEl valor que toma la segunda expresion para h = " << h << " es: " <<expresion_b << "\n\n";			// Salida
	
	// Tercera expresion	
   				
	cout << "Tercera expresion\n\n";					// Entradas			
	cout << "\tIntroduzca el valor de x: ";
	cin >> x;
	
	fraccion_expresion3 = exp(x) / (x * x);										// Calculos
   expresion_c = sqrt(1 + fraccion_expresion3 * fraccion_expresion3);
	
	cout << "\n\tEl valor que toma la tercera expresion para x = " << x << " es: " << expresion_c << "\n\n";			// Salida
	
	system("pause");
}
