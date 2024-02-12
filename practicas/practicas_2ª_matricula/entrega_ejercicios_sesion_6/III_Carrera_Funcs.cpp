/*
	Relación de ejercicios 3

	Ejercicio 14: Programa que, dada la hora inicial de una carrera y la
				  distancia de la misma, muestra, según el dorsal introducido
				  y la hora de llegada de dicho dorsal, el tiempo que ha
				  empleado en completar la carrera y su ritmo.
	              
	Entradas: Hora inicial de la carrera (h_inicial_carrera, 
			  min_inicial_carrera, seg_inicial_carrera),
			  Distancia de la carrera (distancia),
			  Dorsal del corredor (dorsal),
			  Hora de llegada del corredor (h_llegada_corredor, 
			  min_llegada_corredor, seg_llegada_corredor).
	Salidas: Segundos que ha tardado el corredor en completar la carrera
			 (total_seg_llegada_corredor),
			 Minutos que ha tardado el corredor en completar la carrera
			 (total_min_llegada_corredor),
			 Velocidad del corredor (velocidad),
			 Ritmo del corredor (ritmo, minutos_ritmo, segundos_ritmo).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de los recursos de E/S
#include <iomanip>		// Inclusión de los recursos de modificación de E/S
#include <string>		// Inclusión de los recursos del tipo de dato string

using namespace std;

// Declaración de constantes globales

const int SEGUNDOS_EN_MINUTO = 60;
const int MINUTOS_EN_HORA = 60;
const int HORAS_EN_DIA = 24;
	
const int SEGUNDOS_EN_HORA = SEGUNDOS_EN_MINUTO * MINUTOS_EN_HORA;
const int SEGUNDOS_EN_DIA = SEGUNDOS_EN_HORA * HORAS_EN_DIA;
	
/***************************************************************************/
// Función: LeerHoraInicioCarrera
// Recibe: Texto que etiqueta la lectura (msg).
// Devuelve: Hora de inicio de la carrera.
/***************************************************************************/
int LeerHoraInicioCarrera(string msg) {
	
	int hora;
	
	do {
		
		cout << msg;
		cin >> hora;
	}while( (hora < 0) || (hora > HORAS_EN_DIA) );
	
	return hora;		
}

/***************************************************************************/
// Función: LeerMinutoInicioCarrera
// Recibe: Texto que etiqueta la lectura (msg).
// Devuelve: Minuto de inicio de la carrera.
/***************************************************************************/
int LeerMinutoInicioCarrera(string msg) {
	
	int minuto;
	
	do {
		
		cout << msg;
		cin >> minuto;
	}while( (minuto < 0) || (minuto > MINUTOS_EN_HORA) );
	
	return minuto;
}

/***************************************************************************/
// Función: LeerSegundoInicioCarrera
// Recibe: Texto que etiqueta la lectura (msg).
// Devuelve: Segundo de inicio de la carrera.
/***************************************************************************/
int LeerSegundoInicioCarrera(string msg) {
	
	int segundo;
	
	do {
		
		cout << msg;
		cin >> segundo;
	}while( (segundo < 0) || (segundo > SEGUNDOS_EN_MINUTO) );
	
	return segundo;
}

/***************************************************************************/
// Función: LeerDistanciaCarrera
// Recibe: Texto que etiqueta la lectura (msg).
// Devuelve: Distancia de la carrera.
/***************************************************************************/
double LeerDistanciaCarrera(string msg) {
	
	double distancia;
	
	do {
		
		cout << msg;
		cin >> distancia;
	}while(distancia <= 0);
	
	return distancia;
}

/***************************************************************************/
// Función: LeerHoraLlegadaCorredor
// Recibe: Texto que etiqueta la lectura (msg),
//		   Hora de llegada del corredor anterior (h_llegada_corredor_anterior).
// Devuelve: Hora de llegada del corredor.
/***************************************************************************/
int LeerHoraLlegadaCorredor(string msg, int h_llegada_corredor_anterior) {
	
	int h_llegada_corredor;
	
	do {
		
		cout << msg;
		cin >> h_llegada_corredor;
	}while( (h_llegada_corredor < 0) || 
	        (h_llegada_corredor > HORAS_EN_DIA) ||
			(h_llegada_corredor < h_llegada_corredor_anterior) );
	
	return h_llegada_corredor;
}

/***************************************************************************/
// Función: LeerMinutoLlegadaCorredor
// Recibe: Texto que etiqueta la lectura (msg),
//		   Hora de llegada del corredor (h_llegada_corredor),
//		   Hora de llegada del corredor anterior (h_llegada_corredor_anterior),
//		   Minuto de llegada del corredor anterior 
//		   (min_llegada_corredor_anterior).
// Devuelve: Minuto de llegada del corredor.
/***************************************************************************/
int LeerMinutoLlegadaCorredor(string msg, int h_llegada_corredor, 
                              int h_llegada_corredor_anterior, 
							  int min_llegada_corredor_anterior) {
	
	int min_llegada_corredor;
	
	do {
		
		cout << msg;
		cin >> min_llegada_corredor;
	}while( (min_llegada_corredor < 0) || 
	        (min_llegada_corredor > MINUTOS_EN_HORA) ||
			( (min_llegada_corredor < min_llegada_corredor_anterior) 
			&& (h_llegada_corredor <= h_llegada_corredor_anterior) ) );	
	
	return min_llegada_corredor;
}

/***************************************************************************/
// Función: LeerSegundoLlegadaCorredor
// Recibe: Texto que etiqueta la lectura (msg),
//		   Hora de llegada del corredor (h_llegada_corredor),
//		   Hora de llegada del corredor anterior (h_llegada_corredor_anterior),
//		   Minuto de llegada del corredor (min_llegada_corredor),
//		   Minuto de llegada del corredor anterior
//         (min_llegada_corredor_anterior),
//		   Segundo de llegada del corredor anterior 
//         (seg_llegada_corredor_anterior).
// Devuelve: Segundo de llegada del corredor.
/***************************************************************************/
int LeerSegundoLlegadaCorredor(string msg, int h_llegada_corredor, 
                               int h_llegada_corredor_anterior, 
							   int min_llegada_corredor, 
							   int min_llegada_corredor_anterior, 
							   int seg_llegada_corredor_anterior) {
							   	
	int seg_llegada_corredor;
	
	do {
		
		cout << msg;
		cin >> seg_llegada_corredor;
	}while( (seg_llegada_corredor < 0) || 
	        (seg_llegada_corredor > SEGUNDOS_EN_MINUTO) ||
			( (seg_llegada_corredor <= seg_llegada_corredor_anterior) 
			&& (min_llegada_corredor <= min_llegada_corredor_anterior) 
			&& (h_llegada_corredor <= h_llegada_corredor_anterior) ) );
	
	return seg_llegada_corredor;
}

/***************************************************************************/
// Función: CalcularTotalSegundos
// Recibe: Hora de llegada del corredor (h_llegada_corredor),
//		   Minuto de llegada del corredor (min_llegada_corredor),
//		   Segundo de llegada del corredor (seg_llegada_corredor),
//		   Hora de inicio de la carrera (h_inicial_carrera),
//		   Minuto inicial de la carrera (min_inicial_carrera).
// Devuelve: Total de segundos que ha tardado el corredor en llegar a la meta.
/***************************************************************************/

int CalcularTotalSegundos(int h_llegada_corredor, int min_llegada_corredor, 
                  	 int seg_llegada_corredor, int h_inicial_carrera, 
				  	 int min_inicial_carrera) {

	int total_seg;
	
	total_seg = ( (h_llegada_corredor - h_inicial_carrera)
		        	* SEGUNDOS_EN_HORA )
				+ ( (min_llegada_corredor - min_inicial_carrera)
		        	* SEGUNDOS_EN_MINUTO)
				+ seg_llegada_corredor;
			
	bool dias_consecutivos = (total_seg < 0);
			
	if(dias_consecutivos) {
			
		total_seg = abs(total_seg);
		total_seg = SEGUNDOS_EN_DIA - total_seg;	
	}
	
	return total_seg;				  	 	
}

/***************************************************************************/
// Función: CalcularTotalMinutos
// Recibe: Total de segundos que ha tardado el corredor en llegar a la meta
//         (total_seg).
// Devuelve: Total de minutos que ha tardado el corredor en llegar a la meta.
/***************************************************************************/

double CalcularTotalMinutos(int total_seg) {

	double total_min;
	
	total_min = double(total_seg) / SEGUNDOS_EN_MINUTO;
				
	return total_min;				  	 	
}

/***************************************************************************/
// Función: CalcularRitmo
// Recibe: Total de segundos que ha tardado el corredor en llegar a la meta
//		   (total_seg),
//		   Distancia de la carrera (distancia).
// Devuelve: Ritmo del corredor.
/***************************************************************************/
double CalcularRitmo(int total_seg, double distancia) {
	
	double ritmo;
				
	double total_min = CalcularTotalMinutos(total_seg);
	
	ritmo = total_min / distancia;
	
	return ritmo;
}

/***************************************************************************/
// Función: CalcularVelocidad
// Recibe: Total de minutos que ha tardado el corredor en llegar a la meta
//		   (total_min),
//		   Distancia de la carrera (distancia).
// Devuelve: Velocidad del corredor.
/***************************************************************************/
double CalcularVelocidad(double total_min, double distancia) {
	
	double velocidad;
	
	double total_h = total_min / MINUTOS_EN_HORA;
	
	velocidad = distancia / total_h;
	
	return velocidad;
}

/***************************************************************************/
// Función principal
/***************************************************************************/
int main() {
	
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 
	
	// Declaración de constantes
	
	const string SEPARADOR = "------------------------------";

	// Declaración de variables
	
	int h_inicial_carrera;
	int min_inicial_carrera;
	int seg_inicial_carrera;
	double distancia;
	
	// Entradas de datos
	
	cout << " Hora de inicio de la carrera: ";
	cout << endl << endl;
	
	h_inicial_carrera = LeerHoraInicioCarrera("\t Hora: ");
	min_inicial_carrera = LeerMinutoInicioCarrera("\t Minuto: ");
	seg_inicial_carrera = LeerSegundoInicioCarrera("\t Segundo: ");
	
	cout << endl;
	
	distancia = LeerDistanciaCarrera(" Distancia de la carrera (en km): ");
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Introducir el dorsal del corredor y su hora de llegada.
		
		Comprobar que el dorsal del corredor actual sea diferente al del
		corredor anterior y también que su hora de llegada sea mayor.
		
		Mientras el dorsal del corredor sea un número positivo:
			
			Calcular el total de segundos, el total de minutos que ha tardado 
			el corredor en completar la carrera ('total_seg', 'total_min').
			
			Calcular la velocidad del corredor ('velocidad').
			
			Calcular el ritmo del corredor ('ritmo').			
			
			Mostrar los resultados.
	*/
	
	int h_llegada_corredor;
	int min_llegada_corredor;
	int seg_llegada_corredor;
	int h_llegada_corredor_anterior = 0;
	int min_llegada_corredor_anterior = 0;
	int seg_llegada_corredor_anterior = 0;
	
	int dorsal;
	int dorsal_anterior = 0;
	
	bool dorsal_positivo = true;
	
	int total_seg = 0;
	double total_min = 0.0;
	
	double ritmo = 0.0;
	double velocidad = 0.0;
	
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
			cout << "\t Hora de llegada del corredor: ";
			cout << endl << endl;
		
			h_llegada_corredor = LeerHoraLlegadaCorredor
			                     ("\t\t Hora: ", h_llegada_corredor_anterior);
			min_llegada_corredor = LeerMinutoLlegadaCorredor
			                       ("\t\t Minuto: ",  h_llegada_corredor, 
									 h_llegada_corredor_anterior,
									 min_llegada_corredor_anterior);
			seg_llegada_corredor = LeerSegundoLlegadaCorredor
			                       ("\t\t Segundo: ", h_llegada_corredor, 
								    h_llegada_corredor_anterior, 
									min_llegada_corredor, 
									min_llegada_corredor_anterior, 
									seg_llegada_corredor_anterior);
			
			total_seg = CalcularTotalSegundos
			            (h_llegada_corredor, min_llegada_corredor, 
                  		 seg_llegada_corredor, h_inicial_carrera, 
				  	 	 min_inicial_carrera);
			
			total_min = CalcularTotalMinutos(total_seg);
			
			ritmo = CalcularRitmo(total_seg, distancia);
				  	 
			int minutos_ritmo = ritmo;
			int segundos_ritmo = (ritmo - minutos_ritmo) * SEGUNDOS_EN_MINUTO;
						
			velocidad = CalcularVelocidad(total_min, distancia);
			
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
			cout << endl;
		}
	}
	
	return 0;
}
