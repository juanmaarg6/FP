/*
	Ejercicio 27: Programa que calcula el area de un triangulo a partir de
	              dos de sus lados y el angulo que forman entre ellos.
	
	Entradas: lados del triangulo (lado_a, lado_b) y angulo que forman entre ellos
	          (angulo).
	Salida: area del triangulo (area).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>
#include <cmath>	

using namespace std;

int main(){	
   //Declaracion de variables	
   
	double lado_a, lado_b, angulo;			// Datos de entrada
	double area;		                     // Datos de salida
	
	const double PI = 3.141593;					      

   //Entradas	
   					
	cout << "Introduzca la longitud del primer lado del triangulo (en cm): ";	
	cin >> lado_a;
	cout << "Introduzca la longitud del segundo lado del triangulo (en cm): ";		
	cin >> lado_b;
	cout << "Introduzca el angulo que forman los dos lados (en grados): ";		
	cin >> angulo;
	
	//Calculos
	
	angulo = (angulo * 2 * PI) / 360;
   area = 0.5 * lado_a * lado_b * sin(angulo);
   	
	//Salidas
	
	cout << "\nEl area del triangulo es de " << area << " centimetros cuadrados\n\n";
	
	system("pause");
}
