/*
	Relaci�n de ejercicios 1

	Ejercicio 3: Programa para calcular la longitud de una circunferencia 
	             en cent�metros y el area de un c�rculo en cent�metros 
				 cuadrados.
	
	Entrada: Longitud del radio de la circunferencia (radio_circunferencia).
	Salidas: Longitud de la circunferencia (longitud_circunferencia), 
	         �rea del c�rculo (area_circulo).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusi�n de librer�a de recursos de E/S

using namespace std;

// Programa principal

int main(){

	// Declaraci�n de variables	

	double radio_circunferencia = 0.0;
	double longitud_circunferencia = 0.0;
	double area_circulo = 0.0;			
						
	// Entradas de datos
	
	cout << " Introduzca la longitud del radio (en centimetros): ";	
	cin >> radio_circunferencia;
				
	// C�lculos 
	
	area_circulo = 3.1415927 * radio_circunferencia  * radio_circunferencia;
	longitud_circunferencia  = 2 * 3.1415927 * radio_circunferencia;				 
			
	// Salidas
	
	cout << endl << " La longitud de la circunferencia es igual a " 
	     << longitud_circunferencia  << " centimetros";  
	cout << endl << " El area del circulo es igual a " << area_circulo 
	     << " centimetros cuadrados" << endl << endl;		
	
	system("pause");
	return 0;
}
