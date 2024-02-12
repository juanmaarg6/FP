/*
	Relación de ejercicios 1

	Ejercicio 8: Programa para calcular el precio final del billete de una 
				 compañía aérea sabiendo que:
					
				 1) Se fija una tarifa base de 150 euros.
				 2) Se suman 10 céntimos por cada kilómetro de distancia 
				    al destino.
				 3) Finalmente, se aplica un descuento al precio final 
				    del billete.					  
	
	Entradas: Kilómetros de distancia al destino (kilometros), 
	         Porcentaje de descuento (descuento).
	Salidas: Precio final del billete (precio_final).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusión de librería de recursos de E/S

using namespace std;

// Programa principal

int main() {	
					
	// Declaración de constantes
	
	const int TARIFA_BASE = 150;	
	const double PRECIO_KM_ADICIONAL = 0.1;	
		
	// Declaración de variables
		        
	double kilometros, precio_billete, descuento, precio_final;

	// Entradas de datos
	
	cout << " Introduzca el numero de kilometros al destino: ";
	cin >> kilometros;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Multiplicar el número de kilómetros que hay hasta el destino por
		0.1, ya que se suman 10 céntimos por cada kilómetro de distancia 
		al destino. 
		
		Sumar la tarifa base de 150 euros al resultado anterior, obteniendo
		así el precio final del billete sin el descuento aplixado.
	*/
	
	precio_billete = TARIFA_BASE + (kilometros * PRECIO_KM_ADICIONAL);
			
	// Salidas
	
	cout << endl;
	cout << " Sin aplicar el descuento, el precio del billete es de " 
	     << precio_billete << " euros" << endl;
	
	// Entradas de datos

	cout << endl << " Introduzca un porcentaje de descuento: ";
	cin >> descuento;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Multiplicar el precio del billete por el descuento introducido y
		restar el resultado al precio del billete original, obteniendo así
		el precio final del billete con el descuento aplicado.
	*/
	
	precio_final = precio_billete - precio_billete * (descuento / 100);
	
	// Salidas
	
	cout << endl << " Tras aplicar el descuento, el precio del billete es de " 
	     << precio_final << " euros" << endl << endl;

	system("pause");
	return 0;
}
