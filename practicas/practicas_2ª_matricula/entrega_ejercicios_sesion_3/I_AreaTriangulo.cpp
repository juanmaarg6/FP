/*
	Relación de ejercicios 1
	
	Ejercicio 40: Programa que, dados dos lados de un triángulo y el ángulo
	              que forman entre ellos, calcula el área de dicho triángulo.
	
	Entradas: Lados del triángulo (lado_a, lado_b),
	          Ángulo que forman los lados (angulo_grados).
	Salidas: Área del triángulo (area).

	Código fuente escrito por Juan Manuel Rodríguez Gómez.
*/


#include <iostream>		// Inclusión de los recursos de E/S
#include <cmath>		// Inclusión de los recursos matemáticos

using namespace std;

// Programa principal

int main() {				
	
	// Declaración de constantes
	
	const double PI = asin(0.5) * 6;		 		
	const double GRADOS_A_RADIANES = PI / 180;	
   													   	   
	// Declaración de variables
	
	double lado_a = 0.0, lado_b = 0.0;
	double angulo_grados = 0.0, angulo_radianes = 0.0;
	double area = 0.0;
	
	// Entradas de datos
	
	cout << " Introduzca la longitud del primer lado del triangulo (en cm): ";	
	cin >> lado_a;
	cout << " Introduzca la longitud del segundo lado del triangulo (en cm): ";		
	cin >> lado_b;
	cout << " Introduzca el angulo que forman los dos lados (en grados): ";		
	cin >> angulo_grados;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Realizar la conversión del ángulo de grados a radianes.
		
		Nombramos a los lados del triángulo a, b y c, y consideramos que h es 
		la altura sobre el lado a. Consideramos únicamente el ángulo o
		delimitado por los lados a y b. Por la definición de seno, 
		sin(o) = h / b, o sea, h = b * sin(o). Aplicando la fórmula del área
		del triángulo tenemos que A = (1 / 2) * a * h y sustituyendo en
        la fórmula del área el valor de h tenemos que:
							
							  1
						 A = --- * a * b * sin(o)
							  2
	*/
	
	angulo_radianes = angulo_grados * GRADOS_A_RADIANES;
	area = 0.5 * lado_a * lado_b * sin(angulo_radianes);
	
	// Salidas
	
	cout << endl << " El area del triangulo es de " << area
	     << " centimetros cuadrados" << endl << endl;
	     
	return 0;
}
