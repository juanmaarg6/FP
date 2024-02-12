/*
	Relación de ejercicios 1

	Ejercicio 33: Programa que, dado el costo de un vehículo, el porcentaje
	              de ganancia del vendedor y el IVA aplicable, calcula el
	              precio final del automóvil.
	              
	Entradas: Precio del automóvil (precio_automovil).
	Salidas: Precio final del automóvil (precio_final_automovil).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de los recursos de E/S

using namespace std;

// Programa principal

int main() {				
	
	// Declaración de constantes
	
	const double GANANCIA_VENDEDOR = 0.20;
	const double IVA = 0.16;
   													   	   
	// Declaración de variables
	
	double precio_automovil = 0.0, precio_final_automovil = 0.0;
							
	// Entradas de datos
	
	cout << " Introduzca el precio del automovil en euros: ";
	cin >> precio_automovil;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Sumar el precio del automóvil más el porcentaje de ganancias del 
		vendedor aplicado al automóvil más el IVA aplicado al automóvil.
		De esta forma se obtiene el precio final del automóvil.
	*/
	
	precio_final_automovil = precio_automovil + 
	                        (precio_automovil * GANANCIA_VENDEDOR) + 
							(precio_automovil * IVA);
	
	// Salidas
	
	cout << endl << " Tras aplicar el porcentaje de ganancia del vendedor y el" 
	     << " IVA, el precio final del automovil es: " << precio_final_automovil
	     << " euros" << endl << endl;
	
	return 0;
}
