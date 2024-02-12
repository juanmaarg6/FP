/*
	Relaci�n de ejercicios 1

	Ejercicio 16: Programa que, dados los kil�metros recorridos, los litros
	              de gasolina consumidos y los litros que quedan en el
	              dep�sito, informa sobre el consumo en km/litro, los 
	              litros/100 km y cu�ntos kil�metros de autonom�a le restan
	              con ese nivel de consumo.		  
	
	Entradas: Kil�metros recorridos (kilometros),
	          Litros de gasolina consumidos (gasolina_consumida),
	          Litros que quedan en el dep�sito (gasolina_deposito).
	Salidas: Consumo en km/litro (consumo),
	         Litros consumidos cada 100 km (litros_cien_km),
	         Kil�metros restantes con ese nivel de consumo (kms_restantes).
	         

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusi�n de librer�a de recursos de E/S

using namespace std;

// Programa principal
	
int main() {	

	// Declaraci�n de variables
	
	double kilometros = 0.0;
	double gasolina_consumida = 0.0;	 
	double gasolina_deposito = 0.0;	 
	double consumo = 0.0;
	double litros_cien_kms = 0.0;
	double kms_restantes;

	// Entradas de datos
	
	cout << " Introduzca el numero de kilometros recorridos: ";
	cin >> kilometros;
	cout << " Introduzca los litros de gasolina consumidos: ";
	cin >> gasolina_consumida;
	cout << " Introduzca los litros de gasolina que quedan en el deposito: ";
	cin >> gasolina_deposito;
	
	// C�lculos
	
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
