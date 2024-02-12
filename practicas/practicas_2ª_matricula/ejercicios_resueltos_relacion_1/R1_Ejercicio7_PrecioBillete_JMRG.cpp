/*
	Relación de ejercicios 1

	Ejercicio 7: Programa para calcular el precio final del billete de una 
				 compañía aérea sabiendo que:
					
				 1) Se fija una tarifa base de 150 euros.
				 2) Se suman 10 céntimos por cada kilómetro de distancia
				    al destino.					  
	
	Entrada: Kilómetros de distancia al destino (kilometros).
	Salidas: Precio final del billete (precio_billete).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusión de librería de recursos de E/S

using namespace std;

// Programa principal
	
int main(){	
					
	// Declaración de constantes
	
	const int TARIFA_BASE = 150;	
	const double PRECIO_KM_ADICIONAL = 0.1;	
	
	// Declaración de variables
	
	double kilometros = 0.0;
	double precio_billete = 0.0;	 

	// Entradas de datos
	
	cout << " Introduzca el numero de kilometros al destino: ";
	cin >> kilometros;
	
	// Cálculos
	
	precio_billete = TARIFA_BASE + (kilometros * PRECIO_KM_ADICIONAL);
			
	// Salidas
	
	cout << endl;
	cout << " El billete cuesta " << precio_billete << " euros";
	cout << endl << endl;

	system("pause");
	return 0;
}
