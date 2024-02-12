/*
	Ejercicio 9: Programa que calcula las horas, los minutos y los segundos
					 dentro de su rango correspondiente. Si finalmente hay mas
					 de 24 horas, el programa mostrara tambien los dias (pero no
					 los meses)
	
	Entradas: horas (horas), minutos (minutos) y segundos (segundos).
	Salidas: dias (calculo_dias), horas (total_horas), minutos (total_minutos) y
				segundos (total_segundos) en sus rangos correspondientes.

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>	

using namespace std;

int main(){							      
	int horas, minutos, segundos;												// Datos de entrada
	int calculo_dias, calculo_horas, calculo_minutos;		         // Variables auxiliares
	int total_horas, total_minutos, total_segundos;		            // Datos de salida
							
	cout << "Introduzca las horas: ";				   // El usuario introduce los datos requeridos										
	cin >> horas;
	cout << "Introduzca los minutos: ";
	cin >> minutos;
	cout << "Introduzca los segundos: ";
	cin >> segundos;
	
   calculo_minutos = segundos / 60  +  minutos;	   // Calcula el total de dias, horas y minutos
   calculo_horas = calculo_minutos / 60 + horas;
   calculo_dias = calculo_horas / 24;  
   
   total_segundos = segundos % 60;				      // Se almacena el resto de la division
   total_minutos  = calculo_minutos % 60;
   total_horas   = calculo_horas % 24; 
   
   cout << "\nDias: " << calculo_dias;				   // Se muestran al usuario los resultados
   cout << "\nHoras: " << total_horas;
   cout << "\nMinutos: " << total_minutos;
   cout << "\nSegundos: " << total_segundos << "\n\n";
   
	system("pause");
}
