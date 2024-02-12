/*
	Relaci�n de ejercicios 1

	Ejercicio 7: Programa para calcular el precio final del billete de una 
				 compa��a a�rea sabiendo que:
					
				 1) Se fija una tarifa base de 150 euros.
				 2) Se suman 10 c�ntimos por cada kil�metro de distancia
				    al destino.					  
	
	Entradaa: Kil�metros de distancia al destino (kilometros).
	Salidas: Precio final del billete (precio_billete).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusi�n de librer�a de recursos de E/S

using namespace std;

// Programa principal
	
int main() {	
					
	// Declaraci�n de constantes
	
	const int TARIFA_BASE = 150;	
	const double PRECIO_KM_ADICIONAL = 0.1;	
	
	// Declaraci�n de variables
	
	double kilometros, precio_billete;

	// Entradas de datos
	
	cout << " Introduzca el numero de kilometros al destino: ";
	cin >> kilometros;
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Multiplicar el n�mero de kil�metros que hay hasta el destino por
		0.1, ya que se suman 10 c�ntimos por cada kil�metro de distancia 
		al destino. 
		
		Sumar la tarifa base de 150 euros al resultado anterior, obteniendo
		as� el precio final del billete.
	*/
	
	precio_billete = TARIFA_BASE + (kilometros * PRECIO_KM_ADICIONAL);
			
	// Salidas
	
	cout << endl;
	cout << " El billete cuesta " << precio_billete << " euros";
	cout << endl << endl;

	system("pause");
	return 0;
}
