/*
   Ejercicio 8: Programa que lee un año e indica si es bisiesto o no.
   
					 Un año es bisiesto si es múltiplo de cuatro, pero no de cien. 
					 A excepción de la regla anterior, los múltiplos de cuatrocientos 
					 siempre son bisiestos.
                 
   Código fuente escrito por Juan Manuel Rodríguez Gómez.
*/

#include<iostream>

using namespace std;

int main(){
   
   // Declaración de variables
	
	int anio;
	bool bisiesto;

	// Entrada de datos
	
	cout << "Introduzca un año: ";							
	cin >> anio;
	
	// Variable booleana para comprobar si el año es bisiesto
	
	bisiesto = ((anio % 4 == 0) && (anio % 100 != 0)) || (anio % 400 == 0);
	
	// Condicionales y salida de datos
	
	if(bisiesto){
		cout << endl << "El año " << anio << " es bisiesto" << endl << endl;
	}
	
	else{
		cout << endl << "El año " << anio << " no es bisiesto" << endl << endl;
	}
	
	system("pause");
}
