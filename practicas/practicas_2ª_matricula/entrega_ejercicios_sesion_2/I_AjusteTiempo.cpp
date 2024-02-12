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
	
	int horas, minutos, segundos;							
	int calculo_horas, calculo_minutos;		    
	int total_dias, total_horas, total_minutos, total_segundos;	
							
	// Entradas de datos
	
	cout << " Introduzca las horas: ";									
	cin >> horas;
	cout << " Introduzca los minutos: ";
	cin >> minutos;
	cout << " Introduzca los segundos: ";
	cin >> segundos;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Pasar los segundos introducidos a minutos y sumarlos a los minutos
		introducidos.
		
		Pasar el total de minutos calculados anteriormente a horas y 
		sumarlas a las horas introducidas.
		
		Pasar el total de horas calculadas anteriormente a días.
		
		Calcular el total de segundos, minutos y horas.
	*/
	
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
