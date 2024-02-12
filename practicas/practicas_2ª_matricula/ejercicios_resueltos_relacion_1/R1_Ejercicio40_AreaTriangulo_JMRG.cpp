/*
	Relaci�n de ejercicios 1
	
	Ejercicio 40: Programa que, dados dos lados de un tri�ngulo y el �ngulo
	              que forman entre ellos, calcula el �rea de dicho tri�ngulo.
	
	Entradas: Lados del tri�ngulo (lado_a, lado_b),
	          �ngulo que forman los lados (angulo_grados).
	Salidas: �rea del tri�ngulo (area).

	C�digo fuente escrito por Juan Manuel Rodr�guez G�mez.
*/


#include <iostream>		// Inclusi�n de los recursos de E/S
#include <cmath>		// Inclusi�n de los recursos matem�ticos

using namespace std;

// Programa principal

int main() {				
	
	// Declaraci�n de constantes
	
	const double PI = asin(0.5) * 6;		 		
	const double GRADOS_A_RADIANES = PI / 180;	
   													   	   
	// Declaraci�n de variables
	
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
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Realizar la conversi�n del �ngulo de grados a radianes.
		
		Nombramos a los lados del tri�ngulo a, b y c, y consideramos que h es 
		la altura sobre el lado a. Consideramos �nicamente el �ngulo o
		delimitado por los lados a y b. Por la definici�n de seno, 
		sin(o) = h / b, o sea, h = b * sin(o). Aplicando la f�rmula del �rea
		del tri�ngulo tenemos que A = (1 / 2) * a * h y sustituyendo en
        la f�rmula del �rea el valor de h tenemos que:
							
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
