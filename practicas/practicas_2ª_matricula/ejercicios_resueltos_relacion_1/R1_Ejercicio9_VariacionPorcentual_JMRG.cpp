/*
	Relación de ejercicios 1

	Ejercicio 9: Programa para calcular la variación porcentual mediante 
				 la siguiente fórmula: 
					
				                        valor final - valor inicial
				 		VP = abs (100 * ---------------------------)					  
	                                           valor inicial
	                                           
	Entrada: Valor inicial del producto (valor_inicial), 
	         Valor final del producto (valor_final).
	Salidas: Variación porcentual del producto (var_porcentual).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusión de librería de recursos de E/S
#include <cmath>		    // Inclusión de librería de recursos matemáticos

using namespace std;

// Programa principal
	
int main(){	
					
	// Declaración de variables	
	
	double valor_inicial = 0.0;
	double valor_final = 0.0;
	double var_porcentual = 0.0;	 

	// Entradas de datos
	
	cout << " Introduzca el valor inicial del producto: ";
	cin >> valor_inicial;
	cout << " Introduzca el valor final del producto: ";
	cin >> valor_final;
	
	// Cálculos
	
	var_porcentual = abs(100 * (valor_final - valor_inicial) / valor_inicial);
			
	// Salidas
	
	cout << endl;
	cout << " La variacion porcentual del producto es de un " 
	     << var_porcentual << " %" << endl << endl;

	system("pause");
	return 0;
}
