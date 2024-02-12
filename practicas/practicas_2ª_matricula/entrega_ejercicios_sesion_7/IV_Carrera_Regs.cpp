/*
	Relación de ejercicios 4

	Ejercicio 6: Programa que, dada la hora inicial de una carrera y la
				  distancia de la misma, muestra, según el dorsal introducido
				  y la hora de llegada de dicho dorsal, el tiempo que ha
				  empleado en completar la carrera y su ritmo.
	              
	Entradas: Hora inicial de la carrera (instante_inicial_carrera)
			  Distancia de la carrera (distancia),
			  Dorsal del corredor (dorsal),
			  Hora de llegada del corredor (instante_llegada_corredor)
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

// Declaración de constantes globales

const int SEGUNDOS_EN_MINUTO = 60;
const int MINUTOS_EN_HORA = 60;
const int HORAS_EN_DIA = 24;
	
const int SEGUNDOS_EN_HORA = SEGUNDOS_EN_MINUTO * MINUTOS_EN_HORA;
const int SEGUNDOS_EN_DIA = SEGUNDOS_EN_HORA * HORAS_EN_DIA;

// Registro utilizado para representar un instante de tiempo
struct Instante {
	int hora;		// Hora del instante de tiempo
	int minuto;     // Minutos del instante de tiempo
	int segundo;    // Segundos del instante de tiempo
};

struct Ritmo {
	int minuto;		// Minutos del ritmo del corredor
	int segundo;    // Segundos del ritmo del corredor
};

/***************************************************************************/
// Función: LeerInstanteInicioCarrera
// Recibe: -
// Devuelve: Instante de inicio de la carrera.
/***************************************************************************/
Instante LeerInstanteInicioCarrera() {
	
	Instante instante_inicio_carrera;
	
	do {
		cout << "\t Hora: ";
		cin >> instante_inicio_carrera.hora;
	}while( (instante_inicio_carrera.hora < 0) || 
	        (instante_inicio_carrera.hora > HORAS_EN_DIA) );
	
	do {
		cout << "\t Minuto: ";
		cin >> instante_inicio_carrera.minuto;
	}while( (instante_inicio_carrera.minuto < 0) || 
	        (instante_inicio_carrera.minuto > MINUTOS_EN_HORA) );
	
	do {
		cout << "\t Segundo: ";
		cin >> instante_inicio_carrera.segundo;
	}while( (instante_inicio_carrera.segundo < 0) || 
	        (instante_inicio_carrera.segundo > SEGUNDOS_EN_MINUTO) );
	
	return instante_inicio_carrera;		
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
// Función: LeerInstanteLlegadaCorredor
// Recibe: Instante de llegada del corredor anterior 
//        (instante_llegada_corredor_ant).
// Devuelve: Instante de llegada del corredor.
/***************************************************************************/
Instante LeerInstanteLlegadaCorredor(Instante instante_llegada_corredor_ant) {
	
	Instante instante_llegada_corredor;
	
	do {
		cout << "\t\t Hora: ";
		cin >> instante_llegada_corredor.hora;
	}while( (instante_llegada_corredor.hora < 0) || 
	        (instante_llegada_corredor.hora > HORAS_EN_DIA) ||
			(instante_llegada_corredor.hora < 
			 instante_llegada_corredor_ant.hora) );
	
	do {
		cout << "\t\t Minuto: ";
		cin >> instante_llegada_corredor.minuto;
	}while( (instante_llegada_corredor.minuto < 0) || 
	        (instante_llegada_corredor.minuto > MINUTOS_EN_HORA) ||
			( (instante_llegada_corredor.minuto < 
			   instante_llegada_corredor_ant.minuto) && 
			  (instante_llegada_corredor.hora <= 
			   instante_llegada_corredor_ant.hora) ) );
			
	do {
		cout << "\t\t Segundo: ";
		cin >> instante_llegada_corredor.segundo;
	}while( (instante_llegada_corredor.segundo < 0) || 
	        (instante_llegada_corredor.segundo > SEGUNDOS_EN_MINUTO) ||
			( (instante_llegada_corredor.segundo <= 
			   instante_llegada_corredor_ant.segundo) && 
			  (instante_llegada_corredor.minuto <= 
			   instante_llegada_corredor_ant.minuto) && 
			  (instante_llegada_corredor.hora <= 
			   instante_llegada_corredor_ant.hora) ) );
	
	return instante_llegada_corredor;
}

/***************************************************************************/
// Función: CalcularTotalSegundos
// Recibe: Instante de llegada del corredor (instante_llegada_corredor),
//		   Instante de inicio de la carrera (instante_inicial_carrera).
// Devuelve: Total de segundos que ha tardado el corredor en llegar a la meta.
/***************************************************************************/
int CalcularTotalSegundos(Instante instante_llegada_corredor,
                          Instante instante_inicial_carrera) {

	int total_seg;
	
	total_seg = ( (instante_llegada_corredor.hora - 
	               instante_inicial_carrera.hora)
		          * SEGUNDOS_EN_HORA )
				+ ( (instante_llegada_corredor.minuto - 
				     instante_inicial_carrera.minuto)
		            * SEGUNDOS_EN_MINUTO)
				+ instante_llegada_corredor.segundo;
			
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
Ritmo CalcularRitmo(int total_seg, double distancia) {
	
	Ritmo ritmo;
	
	double total_min = CalcularTotalMinutos(total_seg);

	ritmo.minuto = (total_min / distancia);
	ritmo.segundo = ( (total_min / distancia) - ritmo.minuto ) 
	                * SEGUNDOS_EN_MINUTO;
				
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
	
	Instante instante_inicial_carrera;
	double distancia;
	
	// Entradas de datos
	
	cout << " Hora de inicio de la carrera: ";
	cout << endl << endl;
	
	instante_inicial_carrera = LeerInstanteInicioCarrera();
	
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
	
	Instante instante_llegada_corredor;
	Instante instante_llegada_corredor_ant = {instante_inicial_carrera.hora, 
	                                          instante_inicial_carrera.minuto,
											  instante_inicial_carrera.segundo};
	
	int dorsal;
	int dorsal_anterior = 0;
	
	bool dorsal_positivo = true;
	
	int total_seg = 0;
	double total_min = 0.0;
	
	Ritmo ritmo;
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
		
			instante_llegada_corredor = LeerInstanteLlegadaCorredor
			                            (instante_llegada_corredor_ant);
			
			total_seg = CalcularTotalSegundos
			            (instante_llegada_corredor, instante_inicial_carrera);
			
			total_min = CalcularTotalMinutos(total_seg);
			
			ritmo = CalcularRitmo(total_seg, distancia);
						
			velocidad = CalcularVelocidad(total_min, distancia);
			
			instante_llegada_corredor_ant.hora = 
			                                instante_llegada_corredor.hora;
			instante_llegada_corredor_ant.minuto = 
			                                instante_llegada_corredor.minuto;
			instante_llegada_corredor_ant.segundo = 
											instante_llegada_corredor.segundo;
			
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
			cout << "\t Ritmo: " << ritmo.minuto << ":" << ritmo.segundo 
			     << " / km";
			cout << endl;
		}
	}
	
	return 0;
}
