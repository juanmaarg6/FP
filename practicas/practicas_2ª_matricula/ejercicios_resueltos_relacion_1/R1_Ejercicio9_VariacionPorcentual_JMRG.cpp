/*
	Relaci�n de ejercicios 1

	Ejercicio 9: Programa para calcular la variaci�n porcentual mediante 
				 la siguiente f�rmula: 
					
				                        valor final - valor inicial
				 		VP = abs (100 * ---------------------------)					  
	                                           valor inicial
	                                           
	Entrada: Valor inicial del producto (valor_inicial), 
	         Valor final del producto (valor_final).
	Salidas: Variaci�n porcentual del producto (var_porcentual).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusi�n de librer�a de recursos de E/S
#include <cmath>		    // Inclusi�n de librer�a de recursos matem�ticos

using namespace std;

// Programa principal
	
int main(){	
					
	// Declaraci�n de variables	
	
	double valor_inicial = 0.0;
	double valor_final = 0.0;
	double var_porcentual = 0.0;	 

	// Entradas de datos
	
	cout << " Introduzca el valor inicial del producto: ";
	cin >> valor_inicial;
	cout << " Introduzca el valor final del producto: ";
	cin >> valor_final;
	
	// C�lculos
	
	var_porcentual = abs(100 * (valor_final - valor_inicial) / valor_inicial);
			
	// Salidas
	
	cout << endl;
	cout << " La variacion porcentual del producto es de un " 
	     << var_porcentual << " %" << endl << endl;

	system("pause");
	return 0;
}
