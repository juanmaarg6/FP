/*
	Relación de ejercicios 1

	Ejercicio 16: Programa que, dados los kilómetros recorridos, los litros
	              de gasolina consumidos y los litros que quedan en el
	              depósito, informa sobre el consumo en km/litro, los 
	              litros/100 km y cuántos kilómetros de autonomía le restan
	              con ese nivel de consumo.		  
	
	Entradas: Kilómetros recorridos (kilometros),
	          Litros de gasolina consumidos (gasolina_consumida),
	          Litros que quedan en el depósito (gasolina_deposito).
	Salidas: Consumo en km/litro (consumo),
	         Litros consumidos cada 100 km (litros_cien_km),
	         Kilómetros restantes con ese nivel de consumo (kms_restantes).
	         

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de librería de recursos de E/S

using namespace std;

// Programa principal
	
int main() {	

	// Declaración de variables
	
	double kilometros, gasolina_consumida, gasolina_deposito;	 
	double consumo, litros_cien_kms, kms_restantes;

	// Entradas de datos
	
	cout << " Introduzca el numero de kilometros recorridos: ";
	cin >> kilometros;
	cout << " Introduzca los litros de gasolina consumidos: ";
	cin >> gasolina_consumida;
	cout << " Introduzca los litros de gasolina que quedan en el deposito: ";
	cin >> gasolina_deposito;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Dividir el numero de kilometros recorridos por la gasolina consumida
		para calcular el consumo.
		
		Dividir la gasolina consumida por el numero de kilometros recorridos
		y multiplicar el resultado por 100 para calcular el numero de litros
		consumidos cada 100 km.
		
		Multiplicar el consumo por los litros de gasolina que quedan en el
		depósito para calcular los kilómetros de autonomía restantes según
		dicho consumo.
	*/
	
	consumo = kilometros / gasolina_consumida;
	litros_cien_kms = 100 * (gasolina_consumida / kilometros);
	kms_restantes = consumo * gasolina_deposito;
			
	// Salidas
	
	cout << endl << " Consumo: " << consumo << " km/litro" << endl;
	cout << " Litros consumidos cada 100 km: " << litros_cien_kms
	     << " litros" << endl;
	cout << " Kilometros de autonomia restantes para un nivel de consumo de " 
	     << consumo << " km/litro: " << kms_restantes << " km";
	cout << endl << endl;

	system("pause");
	return 0;
}
