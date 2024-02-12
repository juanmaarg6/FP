/*
	Relación de ejercicios 2

	Ejercicio 44: Programa que, dada la hora inicial de una carrera y la
				  distancia de la misma, muestra, según el dorsal introducido
				  y la hora de llegada de dicho dorsal, el tiempo que ha
				  empleado en completar la carrera y su ritmo.
				  
				  La secuencia finaliza cuando se introduce una temperatura
				  fuera de un rango establecido.
	              
	Entradas: Hora inicial de la carrera (h_inicial_carrera, 
			  min_inicial_carrera, seg_inicial_carrera),
			  Distancia de la carrera (distancia_carrera),
			  Dorsal del corredor (dorsal),
			  Hora de llegada del corredor (h_llegada_corredor, 
			  min_llegada_corredor, seg_llegada_corredor).
	Salidas: Segundos que ha tardado el corredor en completar la carrera
			 (total_seg_llegada_corredor),
			 Minutos que ha tardado el corredor en completar la carrera
			 (total_min_llegada_corredor),
			 Velocidad del corredor (velocidad),
			 Ritmo del corredor (ritmo).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de los recursos de E/S
#include <iomanip>		// Inclusión de los recursos de modificación de E/S
#include <string>		// Inclusión de los recursos del tipo de dato string

using namespace std;

// Programa principal

int main() {
	
	cout.setf (ios::fixed);
	cout.setf (ios::showpoint);
	
	// Declaración de constantes
	
	const string SEPARADOR = "------------------------------";
	
	const int SEGUNDOS_EN_MINUTO = 60;
	const int MINUTOS_EN_HORA = 60;
	const int HORAS_EN_DIA = 24;
	
	const int SEGUNDOS_EN_HORA = SEGUNDOS_EN_MINUTO * MINUTOS_EN_HORA;
	const int SEGUNDOS_EN_DIA = SEGUNDOS_EN_HORA * HORAS_EN_DIA;

	// Declaración de variables
	
	int h_inicial_carrera = 0;
	int min_inicial_carrera = 0;
	int seg_inicial_carrera = 0;
	double distancia_carrera = 0.0;
	
	// Entradas de datos
	
	cout << " Introduzca la hora de inicio de la carrera: ";
	cout << endl << endl;
	
	do {
		
		cout << "\t Hora: ";
		cin >> h_inicial_carrera;
	}while( (h_inicial_carrera < 0) || (h_inicial_carrera > HORAS_EN_DIA) );
		
	do {
		
		cout << "\t Minuto: ";
		cin >> min_inicial_carrera;
	}while( (min_inicial_carrera < 0) || 
	        (min_inicial_carrera > MINUTOS_EN_HORA) );
		
	do {
		
		cout << "\t Segundo: ";
		cin >> seg_inicial_carrera;
	}while( (seg_inicial_carrera < 0) || 
	        (seg_inicial_carrera > SEGUNDOS_EN_MINUTO) );
	
	cout << endl;
	
	do {
		cout << " Introduzca la distancia de la carrera (en km): ";
		cin >> distancia_carrera;
	}while(distancia_carrera <= 0);
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Introducir el dorsal del corredor y su hora de llegada.
		
		Comprobar que el dorsal del corredor actual sea diferente al del
		corredor anterior y también que su hora de llegada sea mayor.
		
		Mientras el dorsal del corredor sea un número positivo:
			
			Calcular el total de segundos, el total de minutos y el total
			de horas que ha tardado el corredor en completar la carrera 
			('total_seg', 'total_min' y 'total_h').
			
			Calcular la velocidad del corredor ('velocidad').
			
			Calcular el ritmo del corredor ('ritmo').			
	*/
	
	int h_llegada_corredor = 0;
	int min_llegada_corredor = 0;
	int seg_llegada_corredor = 0;
	int h_llegada_corredor_anterior = 0;
	int min_llegada_corredor_anterior = 0;
	int seg_llegada_corredor_anterior = 0;
	
	int dorsal = 0;
	int dorsal_anterior = 0;
	
	bool dorsal_positivo = true;
	
	while(dorsal_positivo) {
		
		cout << endl;
		cout << SEPARADOR;	
		cout << endl << endl;
		
		do {
			cout << " Dorsal: ";
			cin >> dorsal;
		}while(dorsal == dorsal_anterior);
		
		dorsal_positivo = (dorsal >= 0);
		
		if(dorsal_positivo) {
			cout << endl;
			cout << "\t Introduzca la hora de llegada del corredor: ";
			cout << endl << endl;
		
			do {
				
				cout << "\t\t Hora: ";
				cin >> h_llegada_corredor;
			}while( (h_llegada_corredor < 0) || 
			        (h_llegada_corredor > HORAS_EN_DIA) ||
					(h_llegada_corredor < h_llegada_corredor_anterior) );
			
			do {
				
				cout << "\t\t Minuto: ";
				cin >> min_llegada_corredor;
			}while( (min_llegada_corredor < 0) || 
			        (min_llegada_corredor > MINUTOS_EN_HORA) ||
					( (min_llegada_corredor < min_llegada_corredor_anterior) 
					&& (h_llegada_corredor <= h_llegada_corredor_anterior) ) );		
					
			do {
				
				cout << "\t\t Segundo: ";
				cin >> seg_llegada_corredor;
			}while( (seg_llegada_corredor < 0) || 
			        (seg_llegada_corredor > SEGUNDOS_EN_MINUTO) ||
					( (seg_llegada_corredor < seg_llegada_corredor_anterior) 
					&& (min_llegada_corredor <= min_llegada_corredor_anterior) 
					&& (h_llegada_corredor <= h_llegada_corredor_anterior) ) );
							 
			int total_seg = ( (h_llegada_corredor - h_inicial_carrera)
			              * SEGUNDOS_EN_HORA )
						+ ( (min_llegada_corredor - min_inicial_carrera)
			              * SEGUNDOS_EN_MINUTO)
						+ seg_llegada_corredor;
			
			bool dias_consecutivos = (total_seg < 0);
			
			if(dias_consecutivos) {
			
				total_seg = abs(total_seg);
				total_seg = SEGUNDOS_EN_DIA - total_seg;	
			}
				
			double total_min = double(total_seg) / SEGUNDOS_EN_MINUTO;
			
			double total_h = total_min / MINUTOS_EN_HORA;
			
			double velocidad = distancia_carrera / total_h;
			
			double ritmo = total_min / distancia_carrera;
			int minutos_ritmo = ritmo;
			int segundos_ritmo = (ritmo - minutos_ritmo) * SEGUNDOS_EN_MINUTO;
			
			h_llegada_corredor_anterior = h_llegada_corredor;
			min_llegada_corredor_anterior = min_llegada_corredor;
			seg_llegada_corredor_anterior = seg_llegada_corredor;
			
			dorsal_anterior = dorsal;
		
			// Salidas
			
			cout << endl;	  
			cout << "\t Segundos totales: " << total_seg;
		    
		    cout << endl;	  
			cout << "\t Minutos totales: " << setprecision(3) << total_min;
			
			cout << endl << endl;
			cout << "\t Velocidad: " << setprecision(3) << velocidad
			     << " km/h";
			     
			cout << endl;
			cout << "\t Ritmo: " << minutos_ritmo << ":" << segundos_ritmo 
			     << " / km" << " (" << setprecision(2) << ritmo 
				 << " minutos/km)";
		}
	}
	
	return 0;
}
