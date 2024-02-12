/*
	Relación de ejercicios 2

	Ejercicio 6: Programa que, dados dos instantes de tiempo (que pueden 
	             pertenecer a dos dias consecutivos), calcula el número de 
				 segundos que hay entre los dos instantes. 
	
	Entradas: Hora del instante inicial (h_inicial),
			  Minuto del instante inicial (min_inicial),
			  Segundo del instante inicial (seg_inicial),
			  Hora del instante final (h_final),
			  Minuto del instante final (min_final),
		      Segundo del instante final (seg_final).
	Salidas: Número de segundos entre los dos instantes (total_seg).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusión de los recursos de E/S
#include <cmath>			// Inclusión de los recursos matemáticos

using namespace std;

// Programa principal

int main() {
	
	// Declaración de constantes
	
	const int SEGUNDOS_EN_MINUTO = 60;
	const int SEGUNDOS_EN_HORA = 60 * SEGUNDOS_EN_MINUTO;
	const int SEGUNDOS_EN_DIA = 24 * SEGUNDOS_EN_HORA;
	
	// Declaración de variables
	
	int h_inicial = 0, min_inicial = 0, seg_inicial = 0;							
	int h_final = 0, min_final = 0, seg_final = 0;
								
	// Entradas de datos
	
	cout << " Instante inicial: " << endl << endl;
	cout << "\t Hora: ";									
	cin >> h_inicial;
	cout << endl << "\t Minuto: ";									
	cin >> min_inicial;
	cout << endl << "\t Segundo: ";									
	cin >> seg_inicial;
	
	cout << endl << endl << " Instante final: " << endl << endl;
	cout << "\t Hora: ";									
	cin >> h_final;
	cout << endl << "\t Minuto: ";									
	cin >> min_final;
	cout << endl << "\t Segundo: ";									
	cin >> seg_final;
	
	/**********************************************************************/
	
	// ALGORITMO 1: En base a los segundos transcurridos entre los dos
	//              instantes.
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Convertir el instante inicial a segundos.
		
		Convertir el instante final a segundos.
		
		Restar el instante inicial menos el final para calcular el total de 
		segundos que hay entre ambos.
		
		Si el total de segundos calculado es menor que 0:
		
			Los instantes pertenecen a dos días consecutivos.
			
			El total de segundos pasa a ser positivo y se le suman los 
			segundos que hay en un día.
			
		Si el total de segundos calculado es mayor que 0:
		
			Los instantes pertenecen al mismo día.
			
			El total de segundos se mantiene igual.
	*/
							 	
	int seg_instante_ini = (h_inicial * SEGUNDOS_EN_HORA) 
	                    + (min_inicial * SEGUNDOS_EN_MINUTO) + seg_inicial;
	int seg_instante_fin = (h_final * SEGUNDOS_EN_HORA) 
	                    + (min_final * SEGUNDOS_EN_MINUTO) + seg_final;

	int total_seg_alg1 = seg_instante_fin - seg_instante_ini;
		
	bool dias_consecutivos_alg1 = (total_seg_alg1 < 0);
	
	cout << endl << " Algoritmo 1: En base a los segundos transcurridos entre"
         << " los dos instantes" << endl;
		     
	if(dias_consecutivos_alg1) {
		
		total_seg_alg1 = abs(total_seg_alg1);
		total_seg_alg1 = SEGUNDOS_EN_DIA - total_seg_alg1;	
		
		// Salidas (si los instantes pertenecen a dos días consecutivos)
		
		cout << endl << endl;
		cout << "\t Los instantes pertenecen a dos dias consecutivos";
		cout << endl << "\t Hay un total de " << total_seg_alg1
	         << " segundos entre los dos instantes dados" << endl << endl;
	}
	else {
		
		// Salidas (si los instantes pertenecen al mismo día)
		
		cout << endl << "\t Los instantes pertenecen al mismo dia";
		cout << endl << "\t Hay un total de " << total_seg_alg1
	         << " segundos entre los dos instantes dados" << endl << endl;
	}
	
	/**********************************************************************/
	
	// ALGORITMO 2: Comparando los valores de horas, minutos y segundos
	//              de los dos instantes.
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Calcular la diferencia de horas, minutos y segundos entre el instante
		final y el inicial.
		
		Si la diferencia de horas, minutos o segundos es menor que 0:
		
			Los instantes pertenecen a dos días consecutivos.
			
			Todas las diferencias pasan a ser positivas ya que, una o más de
			ellas, son negativas.
					
		Calcular el total de segundos de la diferencia entre ambos instantes.
		
		Si los instantes pertenecen a dias consecutivos:
		
			Sumarle al total de segundos de la diferencia entre ambos
			instantes el número de segundos que hay en un día.
			
		Si no:
		
			El total de segundos de la diferencia entre ambos instantes
			se mantiene igual.
	*/
	
	bool dias_consecutivos_alg2 = false;
	
	int diferencia_horas = h_inicial - h_final;
	int diferencia_minutos = min_inicial - min_final;
	int diferencia_segundos = seg_inicial - seg_final;


	bool diferencia_positiva = ( (diferencia_horas > 0) 
	                             || (diferencia_minutos > 0) 
	    						 || (diferencia_segundos > 0) );
	
	if(diferencia_positiva)
		dias_consecutivos_alg2 = true;
	
	int total_seg_alg2 = (diferencia_horas * SEGUNDOS_EN_HORA) 
	                     + (diferencia_minutos * SEGUNDOS_EN_MINUTO)
	                     + diferencia_segundos;
	
	cout << " Algoritmo 2: Comparando los valores de horas, minutos y segundos"
	     << " de los dos instantes" << endl;
     
	if(dias_consecutivos_alg2) {
		
		total_seg_alg2 = SEGUNDOS_EN_DIA - total_seg_alg2;
		
		// Salidas (si los instantes pertenecen a dos días consecutivos)

		cout << endl << "\t Los instantes pertenecen a dos dias consecutivos";
		cout << endl << "\t Hay un total de " << total_seg_alg2
	         << " segundos entre los dos instantes dados" << endl << endl;
	}
	else {
		
		total_seg_alg2 = abs(total_seg_alg2);
		
		// Salidas (si los instantes pertenecen al mismo día)

		cout << endl << "\t Los instantes pertenecen al mismo dia";
		cout << endl << "\t Hay un total de " << total_seg_alg2
	         << " segundos entre los dos instantes dados" << endl << endl;
	}
	
	/**********************************************************************/
	
	return 0;
}
