/*
	Relación de ejercicios 1

	Ejercicio 18: Programa que calcula las horas, los minutos y los segundos
				  dentro de su rango correspondiente. Si finalmente hay mas
				  de 24 horas, el programa mostrara tambien los dias (pero no
				  los meses, ni los años).
	
	Entradas: Horas (horas),
	          Minutos (minutos),
	          Segundos (segundos).
	Salidas: Días (total_dias).,
			 Horas (total_horas),
			 Minutos (total_minutos),
			 Segundos (total_segundos).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de librería de recursos de E/S

using namespace std;

// Programa principal

int main() {				

	// Declaración de variables
	
	int horas = 0, minutos = 0, segundos = 0;							
	int calculo_horas = 0, calculo_minutos = 0;		    
	int total_dias = 0, total_horas = 0, total_minutos = 0, total_segundos = 0;	
							
	// Entradas de datos
	
	cout << " Introduzca las horas: ";									
	cin >> horas;
	cout << " Introduzca los minutos: ";
	cin >> minutos;
	cout << " Introduzca los segundos: ";
	cin >> segundos;
	
	// Cálculos
	
	calculo_minutos = (segundos / 60)  +  minutos;
	calculo_horas = (calculo_minutos / 60) + horas;
	total_dias = calculo_horas / 24;  
	
	total_segundos = segundos % 60;
	total_minutos = calculo_minutos % 60;
	total_horas = calculo_horas % 24; 
	
	// Salidas
	
	cout << endl << " Dias: " << total_dias;
	cout << endl << " Horas: " << total_horas;
	cout << endl << " Minutos: " << total_minutos;
	cout << endl << " Segundos: " << total_segundos << endl << endl;
	
	system("pause");
	return 0;
}
