/*
	Relación de ejercicios 2

	Ejercicio 16: Programa que, dados los tiempos de entrada y de salida de un
				  vehículo en un parking, calcula la tarifa final en euros
				  a cobrar sabiendo que:
	
	Entradas: Hora del tiempo de entrada (h_entrada),
			  Minuto del tiempo de entrada (min_entrada),
			  Segundo del tiempo de entrada (seg_entrada),
			  Hora del tiempo de salida (h_salida),
			  Minuto del tiempo de salida (min_salida),
		      Segundo del tiempo de salida (seg_salida).
	Salidas: Tarifa final en euros (tarifa_final).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusión de los recursos de E/S

using namespace std;

// Programa principal

int main() {
	
	// Declaración de constantes
	
	const int SEGUNDOS_EN_MINUTO = 60;
	const int MINUTOS_EN_SEGUNDOS = 1 / SEGUNDOS_EN_MINUTO;
	const int MINUTOS_EN_HORA = 60;
	const int MINUTOS_EN_DIA = 24 * MINUTOS_EN_HORA;
	
	const int MINUTO_0 = 0;
	const int MINUTO_30 = 30;
	const int MINUTO_31 = 31;
	const int MINUTO_90 = 90;
	const int MINUTO_91 = 91;
	const int MINUTO_120 = 120;
	const int MINUTO_121 = 121;
	const int MINUTO_660 = 660;
	const int MINUTO_661 = 661;
	const int MINUTO_3600 = 3600;
	
	const int MINUTOS_ENTRE_0_Y_30 = 30;
	const int MINUTOS_ENTRE_31_Y_90 = 60;
	const int MINUTOS_ENTRE_91_Y_120 = 30;
	
	const double TARIFA_MINUTOS_0_A_30 = 0.0412;
	const double TARIFA_MINUTOS_31_A_90 = 0.0370;
	const double TARIFA_MINUTOS_91_A_120 = 0.0311;
	const double TARIFA_MINUTOS_121_A_660 = 0.0305;
	const double TARIFA_MINUTOS_661_A_3600 = 24;

	// Declaración de variables
	
	int h_entrada = 0, min_entrada = 0, seg_entrada = 0;							
	int h_salida = 0, min_salida = 0, seg_salida = 0;
	double tarifa_final = 0.0;
	
	// Entradas de datos
	
	cout << " Tiempo de entrada: " << endl << endl;
	cout << "\t Hora: ";									
	cin >> h_entrada;
	cout << endl << "\t Minuto: ";									
	cin >> min_entrada;
	cout << endl << "\t Segundo: ";									
	cin >> seg_entrada;
	
	cout << endl << endl << " Tiempo de salida: " << endl << endl;
	cout << "\t Hora: ";									
	cin >> h_salida;
	cout << endl << "\t Minuto: ";									
	cin >> min_salida;
	cout << endl << "\t Segundo: ";									
	cin >> seg_salida;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Calcular los minutos del tiempo de entrada y de salida.
		
		Comprobar si los tiempos dados pertenecen a dias diferentes y 
		calcular el total de minutos que hay entre ambos tiempos.
		
		Calcular la tarifa final del parking.
	*/
	
	int min_tiempo_entrada = (h_entrada * MINUTOS_EN_HORA)
	                          + min_entrada 
							  + (seg_entrada * MINUTOS_EN_SEGUNDOS);
							  
	int min_tiempo_salida = (h_salida * MINUTOS_EN_HORA)
	                          + min_salida
							  + (seg_salida * MINUTOS_EN_SEGUNDOS);
	
	int total_min = 0;
	bool dias_diferentes = (min_tiempo_salida <= min_tiempo_entrada);
	
	if(dias_diferentes)	  
		total_min = MINUTOS_EN_DIA - (min_tiempo_entrada - min_tiempo_salida);
	else
		total_min = min_tiempo_salida - min_tiempo_entrada;
			
	if(total_min >= MINUTO_0 && total_min <= MINUTO_30)
		tarifa_final = total_min * TARIFA_MINUTOS_0_A_30;

	
	if(total_min >= MINUTO_31 && total_min <= MINUTO_90)
		tarifa_final = MINUTOS_ENTRE_0_Y_30 * TARIFA_MINUTOS_0_A_30 
		               + (total_min - MINUTO_30) * TARIFA_MINUTOS_31_A_90;
	
	if(total_min >= MINUTO_91 && total_min <= MINUTO_120)
		tarifa_final = MINUTOS_ENTRE_0_Y_30 * TARIFA_MINUTOS_0_A_30 
		               + MINUTOS_ENTRE_31_Y_90 * TARIFA_MINUTOS_31_A_90
					   + (total_min - MINUTO_90) * TARIFA_MINUTOS_91_A_120;
	
	if(total_min >= MINUTO_121 && total_min <= MINUTO_660)
		tarifa_final = MINUTOS_ENTRE_0_Y_30 * TARIFA_MINUTOS_0_A_30 
		               + MINUTOS_ENTRE_31_Y_90 * TARIFA_MINUTOS_31_A_90
					   + MINUTOS_ENTRE_91_Y_120 * TARIFA_MINUTOS_91_A_120
					   + (total_min - MINUTO_120) * TARIFA_MINUTOS_121_A_660;
	
	if(total_min >= MINUTO_661 && total_min <= MINUTO_3600)
		tarifa_final = TARIFA_MINUTOS_661_A_3600;	
					   	
	// Salidas
	
	cout << endl << endl << " Tarifa final: " << tarifa_final << " euros";
	cout << endl << endl;
	
	return 0;	
}
