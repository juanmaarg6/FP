/*
	Relación de ejercicios 1

	Ejercicio 13: Programa para calcular la longitud de una circunferencia 
	             en centímetros y el area de un círculo en centímetros 
				 cuadrados.
	
	Entrada: Longitud del radio de la circunferencia (radio_circunferencia).
	Salidas: Longitud de la circunferencia (longitud_circunferencia), 
	         Área del círculo (area_circulo).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusión de librería de recursos de E/S

using namespace std;

// Programa principal

int main(){
	
	// Declaración de constantes
	
	const double PI = 3.1415927;

	// Declaración de variables	

	double radio_circunferencia = 0.0;
	double longitud_circunferencia = 0.0;
	double area_circulo = 0.0;			
						
	// Entradas de datos
	
	cout << " Introduzca la longitud del radio (en centimetros): ";	
	cin >> radio_circunferencia;
				
	// Cálculos 
	
	area_circulo = PI * radio_circunferencia  * radio_circunferencia;
	longitud_circunferencia  = 2 * PI  * radio_circunferencia;				 
			
	// Salidas
	
	cout << endl << " La longitud de la circunferencia es igual a " 
	     << longitud_circunferencia  << " centimetros";  
	cout << endl << " El area del circulo es igual a " << area_circulo 
	     << " centimetros cuadrados" << endl << endl;
		 
	/*
		Esta solución es mejor que la del ejercicio 3 porque si quisiéramos
		añadir más decimales al valor de PI, solo tendríamos que cambiar
		su valor en la constante que definimos. Si usáramos literales,
		tendríamos que cambiar el valor de PI cada vez que aparezca en 
		una expresión, siendo más díficil de modificar el programa.
	*/		
	
	system("pause");
	return 0;
}
