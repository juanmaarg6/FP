/*
	Relación de ejercicios 2

	Ejercicio 43: Programa que, dadas una secuencia de las temperaturas de 
				  días consecutivos, muestra la subsecuencia ordenada, de
				  menor a mayor, de mayor longitud.
				  
				  La secuencia finaliza cuando se introduce una temperatura
				  fuera de un rango establecido.
	              
	Entradas: Secuencia de temperaturas de días consecutivos (temperatura).
	Salidas: Posición en la que empieza la mayor subsecuencia ordenada
			 (pos_inicio_subsecuencia),
			 Longitud de la mayor subsecuencia (longitud_subsecuencia).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de los recursos de E/S

using namespace std;

// Programa principal

int main() {
	
	// Declaración de constantes
	
	const double MIN_RANGO = -90.0;
	const double MAX_RANGO = 60.0;

	// Declaración de variables
	
	int pos = 1, contador_pos = 1;
	int pos_inicio_subsecuencia = 1;
	int longitud_subsecuencia = 1, longitud = 1;
	double temperatura = 0.0, temperatura_anterior = MIN_RANGO;
	
	// Entradas de datos
	
	cout << " Introduzca la secuencia de temperaturas: ";
	cin >> temperatura;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Mientras 'temperatura' esté en el rango	correspondiente:
		
			Si 'temperatura' es mayor o igual que 'temperatura_anterior', la
			longitud de la subsecuencia aumenta.
			Si no, almacenamos la posición actual y se reinicia la longitud
			de la subsecuencia a 1.
			
			Si la subsecuencia calculada es de mayor longitud que
			la subsecuencia calculada anteriormente, se almacena la posición
			de inicio de la subsecuencia y su longitud.
			
			Leer una nueva 'temperatura' y almacenar la anterior en
			'temperatura_anterior'.
	*/
	
	bool finalizar = ( (temperatura < MIN_RANGO) || 
	                   (temperatura > MAX_RANGO) );
	                   
	while( !(finalizar) ){
		              
		if(temperatura >= temperatura_anterior && !(finalizar) )
			longitud++;
		else {
			pos = contador_pos;
			longitud = 1;
		}
		
		bool es_mayor_subsecuencia = (longitud > longitud_subsecuencia);
		                               
		if(es_mayor_subsecuencia) {
			pos_inicio_subsecuencia = pos;
			longitud_subsecuencia = longitud;
		}
		
		temperatura_anterior = temperatura;
		cin >> temperatura;
		
		contador_pos++;
						
		finalizar = ( (temperatura < MIN_RANGO) || 
		              (temperatura > MAX_RANGO) );		
	}
			
	// Salidas
	
	cout << endl << endl;
	cout << " La mayor subsecuencia ordenada de menor a mayor empieza"
	     << " en la posicion " << pos_inicio_subsecuencia << " y su longitud"
	     << " es " << longitud_subsecuencia << ".";
	cout << endl << endl;
	
	return 0;
}
