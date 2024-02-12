/*
	Relación de ejercicios 4

	Ejercicio 22: Programa que, dadas una secuencia de las temperaturas de 
				  días consecutivos, muestra la subsecuencia ordenada, de
				  menor a mayor, de mayor longitud.
				  
				  La secuencia finaliza cuando se introduce una temperatura
				  fuera de un rango establecido.
	              
	Entradas: Secuencia de temperaturas de días consecutivos
	          almacenada en un vector (vector_temperaturas).
	Salidas: Posición en la que empieza la mayor subsecuencia ordenada
			 (pos_inicial_mayor_subsecuencia),
			 Longitud de la mayor subsecuencia (longitud_mayor_subsecuencia).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main () {	
	
	// Vector de datos
	const int TAMANIO = 100; 
	double vector_temperaturas[TAMANIO];
	int total_utilizados = 0;
		
	double temperatura;
	int pos_inicial_nueva_subsecuencia = 0, longitud_nueva_subsecuencia = 1;
	int pos_inicial_mayor_subsecuencia = 0, longitud_mayor_subsecuencia = 1;
	
	// Entradas de datos 
	
	cout << " Introduzca las temperaturas (-1 para finalizar): ";
	
	cout << endl << endl;
	cout << "\t Temperatura numero " << setw(5) << total_utilizados+1 
	     << ": ";
	cin >> temperatura;
				
	while( (temperatura != -1) && (total_utilizados < TAMANIO) ) {
		
		vector_temperaturas[total_utilizados] = temperatura;
		total_utilizados++;
		
		cout << "\t Temperatura numero " << setw(5) << total_utilizados+1 
	         << ": ";
		cin >> temperatura;
	}
	
	cout << endl;
	cout << " Se han introducido " << setw(5) << total_utilizados 
	     << " temperaturas.";
	cout << endl;
		
	// Cálculos
	
	for(int i = 1; i <= total_utilizados; i++) {
		
		// Si la temperatura de una determinada posicion de la secuencia
		// de temperaturas, es mayor que la anterior, entonces la longitud
		// de la subsecuencia ordenada de menor a mayor se 
		// incrementa en 1
		if(vector_temperaturas[i] >= vector_temperaturas[i-1])
			longitud_nueva_subsecuencia++;
		// Si la temperatura de una determinada posicion de la secuencia
		// de temperaturas, es menor que la anterior, entonces se inicia 
		// una nueva subsecuencia de forma que la longitud de dicha
		// subsecuencia vuelve a ser 1 y su posición inicial es la
		// posición correspondiente de la secuencia
		else {
			pos_inicial_nueva_subsecuencia = i;
			longitud_nueva_subsecuencia = 1;
		}
		
		// Comprobamos si la nueva subsecuencia calculada anteriormente
		// es la mayor de todas
		bool es_mayor_subsecuencia = (longitud_nueva_subsecuencia > 
		                              longitud_mayor_subsecuencia);
		                               
		if(es_mayor_subsecuencia) {
			pos_inicial_mayor_subsecuencia = pos_inicial_nueva_subsecuencia;
			longitud_mayor_subsecuencia = longitud_nueva_subsecuencia;
		}	
	}
	
	// Salidas
	
	if(total_utilizados == 0) {
		
		cout << endl;
		cout << " Al no introducirse ninguna temperatura, no existe"
		     << " ninguna subsecuencia ordenada de menor a mayor.";
	}
		
	if(total_utilizados > 0) {
		
		for(int i = 0; i < total_utilizados; i++) {
			
			cout << endl;
			cout << " Casilla " << setw(5) << i << ": " 
			     << vector_temperaturas[i];
		}
			
		cout << endl << endl;
		
		cout << " La mayor subsecuencia ordenada de menor a mayor empieza"
		     << " en la posicion " << pos_inicial_mayor_subsecuencia 
			 << " y su longitud" << " es " << longitud_mayor_subsecuencia 
			 << ".";
	}
		 
	cout << endl << endl;
	
	return 0;
}
