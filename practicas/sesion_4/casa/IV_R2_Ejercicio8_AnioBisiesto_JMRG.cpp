/*
   Ejercicio 8: Programa que lee un a�o e indica si es bisiesto o no.
   
					 Un a�o es bisiesto si es m�ltiplo de cuatro, pero no de cien. 
					 A excepci�n de la regla anterior, los m�ltiplos de cuatrocientos 
					 siempre son bisiestos.
                 
   C�digo fuente escrito por Juan Manuel Rodr�guez G�mez.
*/

#include<iostream>

using namespace std;

int main(){
   
   // Declaraci�n de variables
	
	int anio;
	bool bisiesto;

	// Entrada de datos
	
	cout << "Introduzca un a�o: ";							
	cin >> anio;
	
	// Variable booleana para comprobar si el a�o es bisiesto
	
	bisiesto = ((anio % 4 == 0) && (anio % 100 != 0)) || (anio % 400 == 0);
	
	// Condicionales y salida de datos
	
	if(bisiesto){
		cout << endl << "El a�o " << anio << " es bisiesto" << endl << endl;
	}
	
	else{
		cout << endl << "El a�o " << anio << " no es bisiesto" << endl << endl;
	}
	
	system("pause");
}
