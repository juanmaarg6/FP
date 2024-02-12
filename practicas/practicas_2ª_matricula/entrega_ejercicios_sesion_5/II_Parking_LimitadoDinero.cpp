/*
	Relación de ejercicios 2

	Ejercicio 31: Programa que, dada la hora actual y una cantidad de dinero
				  (en euros), nos indica hasta qué hora se puede tener el
				  coche aparcado sabiendo que las tarifas del parking son
				  las siguientes:
				  
				  Desde el minuto 0 al 30: 0.0412 euros cada minuto.
				  Desde el minuto 31 al 90: 0.0370 euros cada minuto.
				  Desde el minuto 91 al 120: 0.0311 euros cada minuto.
			      Desde el minuto 121 al 660: 0.0305 euros cada minuto.
				  Desde el minuto 661 al 900: 0.0270 euros cada minuto.
				  Desde el minuto 901 hasta 24 horas máximo: 35 euros.
				  
	Entradas: Hora del tiempo de entrada (h_entrada),
			  Minuto del tiempo de entrada (min_entrada),
			  Cantidad de dinero (presupuesto).
	Salidas: Total de minutos permitidos (contador_minutos),
	         Hora del tiempo de salida (h_salida),
	         Minuto del tiempo de salida (min_salida).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusión de los recursos de E/S

using namespace std;

// Programa principal

int main() {
	
	// Declaración de constantes
	
	const int MINUTOS_EN_HORA = 60;
	const int HORAS_EN_DIA = 24;
	const int MINUTOS_EN_DIA = MINUTOS_EN_HORA * HORAS_EN_DIA;
	
	const int MINUTO_0 = 0;
	const int MINUTO_30 = 30;
	const int MINUTO_31 = 31;
	const int MINUTO_90 = 90;
	const int MINUTO_91 = 91;
	const int MINUTO_120 = 120;
	const int MINUTO_121 = 121;
	const int MINUTO_660 = 660;
	const int MINUTO_661 = 661;
	const int MINUTO_900 = 900;
	
	const int MINUTOS_ENTRE_0_Y_30 = 30;
	const int MINUTOS_ENTRE_31_Y_90 = 60;
	const int MINUTOS_ENTRE_91_Y_120 = 30;
	const int MINUTOS_ENTRE_121_Y_660 = 540;
	const int MINUTOS_ENTRE_661_Y_900 = 240;
	
	const double TARIFA_MINUTOS_0_A_30 = 0.0412;
	const double TARIFA_MINUTOS_31_A_90 = 0.0370;
	const double TARIFA_MINUTOS_91_A_120 = 0.0311;
	const double TARIFA_MINUTOS_121_A_660 = 0.0305;
	const double TARIFA_MINUTOS_661_A_900 = 0.0270;
	const double TARIFA_MINUTOS_0_A_901 =    (MINUTOS_ENTRE_0_Y_30 
										      * TARIFA_MINUTOS_0_A_30)
										   + (MINUTOS_ENTRE_31_Y_90
										      * TARIFA_MINUTOS_31_A_90)
										   + (MINUTOS_ENTRE_91_Y_120
										      * TARIFA_MINUTOS_91_A_120)
										   + (MINUTOS_ENTRE_121_Y_660
										      * TARIFA_MINUTOS_121_A_660)
										   + (MINUTOS_ENTRE_661_Y_900
										      * TARIFA_MINUTOS_661_A_900);
	
	// Declaración de variables
	
	int h_entrada = 0, min_entrada = 0;							
	double presupuesto = 0.0;
	
	// Entradas de datos
	
	cout << " Tiempo de entrada: ";
	cout << endl << endl;
	
	do {
		
		cout << "\t Hora: ";									
		cin >> h_entrada;
	}while( (h_entrada < 0) || (h_entrada > HORAS_EN_DIA) );
	
	do {
		cout << endl << "\t Minuto: ";									
		cin >> min_entrada;
	}while( (min_entrada < 0) || (min_entrada > MINUTOS_EN_HORA) );
	
	cout << endl << endl;
	
	do {
		cout << " Presupuesto (en euros): ";
		cin >> presupuesto;
	}while(presupuesto < 0);
		
	// Cálculos
	
	/*
		Algoritmo:
		
		Si 'presupuesto' es mayor que la tarifa mínima del parking que permite
		tener el coche aparcado durante 24 horas:
		
			'contador_minutos' es igual al número de minutos que hay en 
			un día (el cual son 24 horas).
			
		Si no:
		
			Mientras 'tarifa' sea menor que 'presupuesto':
			
				Actualizar la tarifa del parking según el minuto 
				correspondiente.
				Incrementar el contador de minutos.
				
		Calcular el número de horas y minutos que puede permanecer el coche
		en el parking ('total_horas' y 'total_minutos').
		
		Calcular la hora y el minuto del tiempo de salida ('h_salida' y
		'min_salida').
	*/
	
	double tarifa = 0.0;
	int contador_minutos = 0;
	
	bool tiempo_24_horas = (presupuesto >= TARIFA_MINUTOS_0_A_901);
	
	if(tiempo_24_horas)
		contador_minutos = MINUTOS_EN_DIA;
	else
		while(tarifa < presupuesto) {
			
			if(contador_minutos >= MINUTO_0 && contador_minutos <= MINUTO_30)
				tarifa += TARIFA_MINUTOS_0_A_30;
				
			if(contador_minutos >= MINUTO_31 && contador_minutos <= MINUTO_90)
				tarifa += TARIFA_MINUTOS_31_A_90;
			
			if(contador_minutos >= MINUTO_91 && contador_minutos <= MINUTO_120)
				tarifa += TARIFA_MINUTOS_91_A_120;
			
			if(contador_minutos >= MINUTO_121 && contador_minutos <= MINUTO_660)
				tarifa += TARIFA_MINUTOS_121_A_660;
				
			if(contador_minutos >= MINUTO_661 && contador_minutos <= MINUTO_900)
				tarifa += TARIFA_MINUTOS_661_A_900;
													
			contador_minutos++;	
		}	
	
	int calculo_minutos = contador_minutos;
	int calculo_horas = calculo_minutos / MINUTOS_EN_HORA;
	
	int total_minutos = calculo_minutos % MINUTOS_EN_HORA;
	int total_horas = calculo_horas % HORAS_EN_DIA; 
	
	int min_salida = (min_entrada + total_minutos) % MINUTOS_EN_HORA;
	int h_salida = (h_entrada + total_horas) % HORAS_EN_DIA;
	
	bool aniadir_una_hora = (min_entrada + total_minutos >= MINUTOS_EN_HORA);
	
	if(aniadir_una_hora)
		h_salida = (h_salida + 1) % HORAS_EN_DIA;
	
	// Salidas
	
	if(tiempo_24_horas) {
		cout << endl << " Minutos permitidos: " << contador_minutos
		     << " (" << HORAS_EN_DIA << " horas, 0 minutos)";
		cout << endl;
		cout << " Salida a las " << h_salida << ":" << min_salida
		     << " (del dia siguiente)";
		cout << endl << endl;
	}
	else {
		cout << endl << " Minutos permitidos: " << contador_minutos
		     << " (" << total_horas << " horas, " << total_minutos 
			 << " minutos)";
		cout << endl;
		cout << " Salida a las " << h_salida << ":" << min_salida;
		cout << endl << endl;
	}
	
	return 0;	
}
