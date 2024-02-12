/*
	Relaci�n de ejercicios 2

	Ejercicio 5: Programa para calcular el precio final del billete de una 
				 compa��a a�rea sabiendo que:
					
				 1) Se fija una tarifa base de 150 euros.
				 2) Si el destino est� a menos de 300 kil�metros, el precio 
				    final del billete es la tarifa base.
				 3) Si el destino est� a m�s de 300 kil�metros, se suman 10 
				    c�ntimos por cada kil�metro de distancia al destino.
				 4) Se aplica un primer descuento del 2%  si el trayecto
				    es mayor de 700 kil�metros.
			     5) Si el n�mero de puntos de la tarjeta de fidelizaci�n del
				    cliente es mayor de 100, se aplica un descuento del 3% y
					si es mayor de 200, se aplica un descuento del 4%.
				 6) Los dos descuentos anteriores son independientes y
				    acumulables.				  
	
	Entrada: Kil�metros de distancia al destino (kilometros).
	Salidas: Precio final del billete (precio_billete).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusi�n de los recursos de E/S

using namespace std;

// Programa principal
	
int main(){	
					
	// Declaraci�n de constantes
	
	const int TARIFA_BASE = 150;
	const int KM_LIMITE = 300;	
	const int PRIMER_DESCUENTO = 2;
	const int SEGUNDO_DESCUENTO = 3;
	const int TERCER_DESCUENTO = 4;
	const int KM_LIMITE_PRIMER_DESCUENTO = 700;
	const int PUNTOS_SEGUNDO_DESCUENTO = 100;
	const int PUNTOS_TERCER_DESCUENTO = 200;
	const double PRECIO_KM_ADICIONAL = 0.1;	
	
	// Declaraci�n de variables
	
	double kilometros = 0.0;
	int puntos_tarjeta = 0;
	double precio_billete = 0.0;
	int descuento_final = 0;	 
	double precio_final = 0.0;
	
	// Entradas de datos
	
	cout << " Introduzca el numero de kilometros al destino: ";
	cin >> kilometros;
	cout << " Introduzca el numero de puntos de la tarjeta de fidelizacion"
	     << " del cliente: ";
	cin >> puntos_tarjeta;
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Si el destino est� a menos de 300 kil�metros:
		
			El precio del billete es la tarifa base.
			
		Si no:
		
			El precio del billete es la tarifa base m�s 10 c�ntimos
			por cada kil�metro de distancia al destino (a partir del
			kil�metro 300).
			
		Si el destino est� a m�s de 700 kil�metros, se acumula un descuento
		del 2 %.
		
		Si el n�mero de puntos de la tarjeta de fidelizaci�n del cliente es
		mayor que 100 (y menor que 200), se acumula un descuento del 3 %.
		
		Si el n�mero de puntos de la tarjeta de fidelizaci�n del cliente es
		mayor que 200, se acumula un descuento del 4 %.
		
		Se calcula el precio final del billete aplic�ndole el descuento
		acumulado.
	*/
	
	bool menos_de_300km = (kilometros < KM_LIMITE);
	
	if(menos_de_300km)
		precio_billete = TARIFA_BASE;
	else
		precio_billete = TARIFA_BASE 
		                 + ((kilometros - KM_LIMITE) * PRECIO_KM_ADICIONAL);
	
	bool mas_de_700km = (kilometros > KM_LIMITE_PRIMER_DESCUENTO);
	         
	if(mas_de_700km)
		descuento_final +=  PRIMER_DESCUENTO;
		               
	bool mas_de_100_puntos = ( (puntos_tarjeta > PUNTOS_SEGUNDO_DESCUENTO)
	                          && (puntos_tarjeta < PUNTOS_TERCER_DESCUENTO) );
	                          
	if(mas_de_100_puntos)
		descuento_final +=  SEGUNDO_DESCUENTO;
		
	bool mas_de_200_puntos = (puntos_tarjeta > PUNTOS_TERCER_DESCUENTO);
	                          
	if(mas_de_200_puntos)
		descuento_final +=  TERCER_DESCUENTO;
	
	precio_final = precio_billete 
	               - ( precio_billete * (descuento_final / 100) );

	// Salidas
	
	cout << endl << " Tras aplicar un descuento del " << descuento_final 
	     << " %, el precio del billete es de " << precio_final << " euros" 
		 << endl << endl;

	return 0;
}
