/*
	Relaci�n de ejercicios 1

	Ejercicio 8: Programa para calcular el precio final del billete de una 
				 compa��a a�rea sabiendo que:
					
				 1) Se fija una tarifa base de 150 euros.
				 2) Se suman 10 c�ntimos por cada kil�metro de distancia 
				    al destino.
				 3) Finalmente, se aplica un descuento al precio final 
				    del billete.					  
	
	Entrada: Kil�metros de distancia al destino (kilometros), 
	         Porcentaje de descuento (descuento).
	Salidas: Precio final del billete (precio_final).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusi�n de librer�a de recursos de E/S

using namespace std;

// Programa principal

int main(){	
					
	// Declaraci�n de constantes
	
	const int TARIFA_BASE = 150;	
	const double PRECIO_KM_ADICIONAL = 0.1;	
		
	// Declaraci�n de variables
		        
	double kilometros = 0.0;
	double precio_billete = 0.0;
	double descuento = 0.0;
	double precio_final = 0.0;

	// Entradas de datos
	
	cout << " Introduzca el numero de kilometros al destino: ";
	cin >> kilometros;
	
	// C�lculos
	
	precio_billete = TARIFA_BASE + (kilometros * PRECIO_KM_ADICIONAL);
			
	// Salidas
	
	cout << endl;
	cout << " Sin aplicar el descuento, el precio del billete es de " 
	     << precio_billete << " euros" << endl;
	
	// Entradas de datos

	cout << endl << " Introduzca un porcentaje de descuento: ";
	cin >> descuento;
	
	// C�lculos
	
	precio_final = precio_billete - precio_billete * (descuento / 100);
	
	// Salidas
	
	cout << endl << " Tras aplicar el descuento, el precio del billete es de " 
	     << precio_final << " euros" << endl << endl;

	system("pause");
	return 0;
}
