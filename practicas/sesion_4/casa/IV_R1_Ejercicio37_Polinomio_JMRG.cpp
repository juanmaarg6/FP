/*
   Ejercicio 37: Programa que permite representar polinomios de grado máximo 3.
   				  Este programa:
   
					  a) Inicializa un polinomio a partir de los coeficientes introducidos por
					     el usuario.
					  b) Suma dos polinomios de grado máximo 3.
					  c) Evalúa un polinomio en un punto x.
					  
					  Un polinomio de grado máximo 3 se representa: a_3 * x^3 + a_2 * x^2 + a_1 * x + a_0
					   
                 
   Código fuente escrito por Juan Manuel Rodríguez Gómez.
*/

#include<iostream>

using namespace std;

// Creación de un nuevo tipo de dato

struct PolinomioGrado3{
	int a_3, a_2, a_1, a_0;
   int b_3, b_2, b_1, b_0;
	int punto_x;
};

// Función principal

int main(){
   
   // Declaración de variables
	
	PolinomioGrado3 polinomio;
	const string SEPARADOR = "\n\n----------------------------------------\n\n";
	
	/*
	*************************
	      APARTADO A)
	*************************
	
	Inicialización de un polinomio a partir de los coeficientes introducidos por el usuario.
	*/

	// Entrada de datos (coeficientes del primer polinomio)
	
	cout << " Un polinomio de grado máximo 3 se representa: a_3 * x^3 + a_2 * x^2 + a_1 * x + a_0" << endl;	
	cout << "\n Introduzca el coeficiente a_3: ";
	cin >> polinomio.a_3;
	cout << " Introduzca el coeficiente a_2: ";
	cin >> polinomio.a_2;
	cout << " Introduzca el coeficiente a_1: ";
	cin >> polinomio.a_1;
	cout << " Introduzca el coeficiente a_0: ";
	cin >> polinomio.a_0;
	
	// Salida de datos (primer polinomio)
	
	cout << "\n El primer polinomio introducido es: " << polinomio.a_3 << "x^3 + " << polinomio.a_2 << "x^2 + " << polinomio.a_1 << "x + " << polinomio.a_0;
	cout << SEPARADOR;	
	
	/*
	*************************
	      APARTADO B)
	*************************
	
	Suma de dos polinomios.
	*/
	
	// Entrada de datos (coeficientes del segundo polinomio)
	
	cout << " Va a introducir otro polinomio de grado máximo 3 de la forma: b_3 * x^3 + b_2 * x^2 + b_1 * x + b_0" << endl;
	cout << "\n Introduzca el coeficiente b_3: ";
	cin >> polinomio.b_3;
	cout << " Introduzca el coeficiente b_2: ";
	cin >> polinomio.b_2;
	cout << " Introduzca el coeficiente b_1: ";
	cin >> polinomio.b_1;
	cout << " Introduzca el coeficiente b_0: ";
	cin >> polinomio.b_0;
	
	// Salida de datos (segundo polinomio)
	
	cout << "\n El segundo polinomio introducido es: " << polinomio.b_3 << "x^3 + " << polinomio.b_2 << "x^2 + " << polinomio.b_1 << "x + " << polinomio.b_0;
	cout << SEPARADOR;
	
	// Suma de los dos polinomios introducidos por el usuario
	
	cout << " Suma de los dos polinomios anteriores: " << endl;
	
	int suma_x3 = polinomio.a_3 + polinomio.b_3;		// Se realiza la suma "a_3 + b_3" y se almacena en la variable suma_x3
	int suma_x2 = polinomio.a_2 + polinomio.b_2;		// Se realiza la suma "a_2 + b_2" y se almacena en la variable suma_x2
	int suma_x1 = polinomio.a_1 + polinomio.b_1;    // ...
	int suma_x0 = polinomio.a_0 + polinomio.b_0;
	
	// Salida de datos (suma de los dos polinomios)
	
	cout << "\n\t (" << polinomio.a_3 << "x^3 + " << polinomio.a_2 << "x^2 + " << polinomio.a_1 << "x + " << polinomio.a_0 << ") + (" << polinomio.b_3 << "x^3 + " << polinomio.b_2 << "x^2 + " << polinomio.b_1 << "x + " << polinomio.b_0 << ") = " << suma_x3 << "x^3 + " << suma_x2 << "x^2 + " << suma_x1 << "x + " << suma_x0; 
	cout << SEPARADOR;
	
	/*
	*************************
	      APARTADO C)
	*************************
	
	Evaluación de un polinomio en un punto x.
	*/	
	
	// Entrada de datos (punto x en el que se va a evaluar el polinomio)
	
	cout << " Introduzca el punto x en el que se va a evaluar el polinomio " << polinomio.a_3 << "x^3 + " << polinomio.a_2 << "x^2 + " << polinomio.a_1 << "x + " << polinomio.a_0 << ": ";
	cin >> polinomio.punto_x;
	
	int evaluacion_x3 = polinomio.a_3 * polinomio.punto_x * polinomio.punto_x * polinomio.punto_x;		// Se evalúa el término "a_3 * x^3" para el valor de x introducido por el usuario
	int evaluacion_x2 = polinomio.a_2 * polinomio.punto_x * polinomio.punto_x;								   // Se evalúa el término "a_2 * x^2" para el valor de x introducido por el usuario
	int evaluacion_x1 = polinomio.a_1 * polinomio.punto_x;															// ...
	
	int evaluacion_total = evaluacion_x3 + evaluacion_x2 + evaluacion_x1 + polinomio.a_0;				   // Se calcula el valor que toma el polinomio para dicho valor de x mediante
																																		// la suma de las evaluaciones anteriores más el término independiente del polinomio
	
	// Salida de datos (valor que toma el polinomio evaluado para el valor de x introducido por el usuario)
	
	cout << "\n Para x = " << polinomio.punto_x << " el polinomio toma el valor: " << evaluacion_total << endl << endl;
	
	system("pause"); 
}
