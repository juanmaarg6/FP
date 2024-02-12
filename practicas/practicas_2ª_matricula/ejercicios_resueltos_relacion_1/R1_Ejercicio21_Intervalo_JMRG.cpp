/*
	Relación de ejercicios 1

	Ejercicio 21: Programa que, dados los datos de un intervalo, muestra
				  dicho intervalo.
	
	Entradas: Tipo de intervalo por la izquierda (caracter_izda),
			  Cota inferior del intervalo (cota_inferior),
			  Separador de los valores minimo y maximo (coma),
			  Cota superior del intervalo (cota_superior),
			  Tipo de intervalo por la derecha (caracter_dcha).
	Salidas: Intervalo (caracter_izda, cota_inferior, coma, cota_superior, 
	                    caracter_dcha).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de librería de recursos de E/S

using namespace std;

// Programa principal

int main() {				

	// Declaración de variables
	
	char caracter_izda = 'a', caracter_dcha = 'a';
	double cota_inferior = 0, cota_superior = 0;
	char coma = 'a';
							
	// Entradas de datos
	
	cout << " Introduzca un caracter que represente el tipo de intervalo"
		 << " por la izquierda ('[' o '('): ";
	cin >> caracter_izda;
	cout << " Introduzca la cota inferior del intervalo: ";
	cin >> cota_inferior;
	cout << " Introduzcar el caracter ',' como separador de las dos cotas"
	     << " del intervalo: ";
	cin >> coma;
	cout << " Introduzca la cota superior del intervalo: ";
	cin >> cota_superior;
	cout << " Introduzca un caracter que represente el tipo de intervalo"
		 << " por la derecha (']' o ')'): ";
	cin >> caracter_dcha;
	
	// Salidas
	
	cout << endl << " Intervalo: " << caracter_izda << cota_inferior
	     << coma << cota_superior << caracter_dcha << endl << endl;
	
	system("pause");
	return 0;
}
