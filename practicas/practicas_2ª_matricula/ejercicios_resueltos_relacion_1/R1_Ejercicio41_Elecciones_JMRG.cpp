/*
	Relación de ejercicios 1

	Ejercicio 32: Programa que, dados los votos de unas elecciones, se 
	              distinguen varios casos mediante expresiones lógicas.
	              
	Entradas: Número total de votos registrados (votos_emitidos),
	          Número total de votos presenciales (votos_presenciales),
	          Número total de votos por correo (votos_correo),
	          Número de votos registrados que son válidos (votos_validos),
	          Número de votos registrados que son nulos (votos_nulos),
	          Número de votos válidos por correo (votos_validos_correo),
	          Número de votos válidos presenciales (votos_validos_presenciales),
	          Número de votos válidos que reciben cada una de las opciones
	          electorales (votos_A, votos_B, votos_C).
	Salidas: Resultados de las diferentes situaciones presentadas (situacion_a,
	         situacion_b, situacion_c, situacion_d, situacion_e, situacion_f,
	         situacion_g, situacion_h, situacion_i, situacion_j, situacion_k,
	         situacion_l, situacion_m, situacion_n, situacion_enie, situacion_o,
	         situacion_p, situacion_q, situacion_r).
	            
	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>		// Inclusión de los recursos de E/S
#include <cmath>		// Inclusión de los recursos matemáticos

using namespace std;

// Programa principal

int main() {				
	
	// Declaración de constantes
	
	const int VOTANTES = 100000;
	
	// Declaración de variables
	
	int abstenciones = 0;
	int votos_emitidos = 0;
	int votos_presenciales = 0, votos_correo = 0;
	int votos_validos = 0, votos_nulos = 0;
	int votos_validos_correo = 0, votos_validos_presenciales = 0;
	int votos_nulos_correo = 0, votos_nulos_presenciales = 0;
	int votos_A = 0, votos_B = 0, votos_C = 0;
	
	// Entradas de datos
	
	cout << " Introduzca el numero total de votos registrados: ";
	cin >> votos_emitidos;
	
	cout << " Introduzca el numero total de votos presenciales: ";
	cin >> votos_presenciales;
	cout << " Introduzca el numero total de votos por correo: ";
	cin >> votos_correo;
	
	cout << " Introduzca el numero total de votos registrados validos: ";
	cin >> votos_validos;
	cout << " Introduzca el numero total de votos registrados nulos: ";
	cin >> votos_nulos;
	
	cout << " Introduzca el numero total de votos validos por correo: ";
	cin >> votos_validos_correo;
	cout << " Introduzca el numero total de votos validos presenciales: ";
	cin >> votos_validos_presenciales;
	
	cout << " Introduzca el numero total de votos que ha recibido la"
	     << " opcion A: ";
	cin >> votos_A;
	cout << " Introduzca el numero total de votos que ha recibido la"
	     << " opcion B: ";
	cin >> votos_B;
	cout << " Introduzca el numero total de votos que ha recibido la"
	     << " opcion C: ";
	cin >> votos_C;
	
	// Cálculos
	
	abstenciones = VOTANTES - votos_emitidos;
	votos_nulos_correo = votos_correo - votos_validos_correo;
	votos_nulos_presenciales = votos_presenciales - votos_validos_presenciales;

	/**********************************************************************/
    
    // SITUACIÓN A: El número de votos emitidos totales es mayor que el número 
	// de votantes.
	
	bool situacion_a = (votos_emitidos > VOTANTES);
	
	/**********************************************************************/
	
    // SITUACIÓN B: El número de votos válidos no es igual a la suma de los 
	// votos recibidos por las tres opciones.
	
	bool situacion_b = ( votos_validos != (votos_A + votos_B + votos_C) );
	
	/**********************************************************************/
	
    // SITUACIÓN C: El número de votos registrados es igual a la suma de los 
	// votos válidos y nulos.
	
	bool situacion_c = ( votos_emitidos == (votos_validos + votos_nulos) );
	
	/**********************************************************************/	
	
    // SITUACIÓN D: Gana la opción A.
	
	bool situacion_d = ( (votos_A > votos_B) && (votos_A > votos_B) );
	
	/**********************************************************************/
	
    // SITUACIÓN E: Gana la opción B.
	
	bool situacion_e = ( (votos_B > votos_A) && (votos_B > votos_C) );
	
	/**********************************************************************/
	
    // SITUACIÓN F: Gana la opción C.
	
	bool situacion_f = ( (votos_C > votos_A) && (votos_C > votos_B) );
	
	/**********************************************************************/
	
    // SITUACIÓN G: Empatan dos opciones.
	
	bool situacion_g = ( (votos_A == votos_B) || (votos_A == votos_C) 
	                     || (votos_B == votos_C) );
	
	/**********************************************************************/
	
    // SITUACIÓN H: Hay un empate técnico entre las opciones A y B. Definimos 
	// que ocurre un empate técnico cuando la diferencia entre los dos valores 
	// es menor que el 5% de su suma.
	
	bool situacion_h = ( abs(votos_A - votos_B) < 
	                   ( 0.05 * (votos_A - votos_B) ) );
	
	/**********************************************************************/
	
    // SITUACIÓN I: La opción A obtiene mayoría absoluta.
	
	bool situacion_i = ( votos_A >= ceil( (votos_emitidos / 2) + 1) );
	
	/**********************************************************************/
	
    // SITUACIÓN J: Hay una coalición de dos opciones que obtiene mayoría 
	// absoluta.
	
	bool situacion_j = ( (votos_A + votos_B) >= ceil( (votos_emitidos / 2) + 1) 
					|| (votos_A + votos_C) >= ceil( (votos_emitidos / 2) + 1)
					|| (votos_B + votos_C) >= ceil( (votos_emitidos / 2) + 1) );
	
	/**********************************************************************/
	
    // SITUACIÓN K: La coalición A-C obtiene mayoría absoluta.
	
	bool situacion_k = ((votos_A + votos_C) >= ceil( (votos_emitidos / 2) + 1));
	
	/**********************************************************************/
	
    // SITUACIÓN L: La opción B obtiene menos de 3% de los votos válidos
	// registrados.
	
	bool situacion_l = ( votos_B < (0.03 * votos_validos) );
	
	/**********************************************************************/
	
    // SITUACIÓN M: La participación es mayor que el 75% del censo de votantes.
	
	bool situacion_m = ( votos_emitidos > (0.75 * VOTANTES) );
	
	/**********************************************************************/
	
    // SITUACIÓN N: Queremos saber si la opción A puede gobernar "sólo o en 
	// compañía de otros" (esto se traduce en que ni la opción B, ni la
	// opción C, ni la coalición B-C, obtengan mayoría absoluta).
	
	bool situacion_n = !( votos_B >= ceil( (votos_emitidos / 2) + 1) )
	            && !( votos_C >= ceil( (votos_emitidos / 2) + 1) )
				&& !( (votos_B + votos_C) >= ceil( (votos_emitidos / 2) + 1) );
	
	/**********************************************************************/
	
    // SITUACIÓN Ñ: El número de votos nulos ó el número de abstenciones es 
	// mayor que el número de votos válidos.
	
	bool situacion_enie = ( (votos_nulos > votos_validos) 
	                    ||  (abstenciones > votos_validos) );
	
	/**********************************************************************/
	
    // SITUACIÓN O: El número de votos nulos y el número de abstenciones es 
	// mayor que el número de votos válidos, pero las abstenciones no son 
	// mayores que los votos nulos.
	
	bool situacion_o = ( ( (votos_nulos > votos_validos) 
	                    &&  (abstenciones > votos_validos) )
						&& !(abstenciones > votos_nulos) );
	
	/**********************************************************************/
	
    // SITUACIÓN P: El número de votos por correo es mayor que el 20% de los 
	// votos presenciales o el número de abstenciones.
	
	bool situacion_p = ( ( votos_correo > (0.20 * votos_presenciales) ) 
	                    || ( votos_correo > abstenciones ) );
	
	/**********************************************************************/
	
    // SITUACIÓN Q: El número de votos nulos por correo es mayor que el número 
	// de votos nulos presenciales.
	
	bool situacion_q = (votos_nulos_correo > votos_nulos_presenciales);
	
	/**********************************************************************/
	
    // SITUACIÓN R: El número de votos nulos por correo es mayor que el número 
	// de votos válidos por correo.
	
	bool situacion_r = (votos_nulos_correo > votos_validos_correo);
	
	/**********************************************************************/
	
	// Salidas
	
	cout << endl;
	cout << " A) El numero de votos emitidos totales es mayor que el numero"
	     << " de votantes: " << situacion_a << endl;
	cout << " B) El numero de votos validos no es igual a la suma de los votos"
	     << " recibidos por las tres opciones: " << situacion_b << endl;
	cout << " C) El numero de votos registrados es igual a la suma de los"
	     << " votos validos y nulos: " << situacion_c << endl;		 
	cout << " D) Gana la opcion A: " << situacion_d << endl;		 
	cout << " E) Gana la opcion B: " << situacion_e << endl;		 
	cout << " F) Gana la opcion C: " << situacion_f << endl;		 
	cout << " G) Empatan dos opciones: " << situacion_g << endl;		 
	cout << " H) Hay un empate tecnico entre las opciones A y B: "
	     << situacion_h << endl;
	cout << " I) La opcion A obtiene mayoria absoluta: " << situacion_i 
	     << endl;
	cout << " J) Hay una coalicion de dos opciones que obtiene mayoria"
	     << " absoluta: " << situacion_j << endl;	
	cout << " K) La coalicion A-C obtiene mayoria absoluta: " 
	     << situacion_k << endl;	     
	cout << " L) La opcion B obtiene menos de 3% de los votos validos" 
	     << " registrados: " << situacion_l << endl;	
	cout << " M) La participacion es mayor que el 75% del censo de votantes: " 
	     << situacion_m << endl;
	cout << " N) Queremos saber si la opcion A puede gobernar 'solo o en" 
	     << " compania de otros': " << situacion_n << endl;		 	
	cout << " ENIE) El numero de votos nulos o el numero de abstenciones es"
	     << " mayor que el numero de votos validos. " << situacion_enie << endl;
	cout << " O) El numero de votos nulos y el numero de abstenciones es mayor"
	     << " que el numero de votos validos, pero las abstenciones no son"
		 << " mayores que los votos nulos: " << situacion_o << endl;			 	
	cout << " P) El numero de votos por correo es mayor que el 20% de los"
	     << " votos presenciales o el numero de abstenciones: " 
		 << situacion_p << endl;		 
	cout << " Q) El numero de votos nulos por correo es mayor que el numero"
	     << " de votos nulos presenciales: " << situacion_q << endl;			 
	cout << " R) El numero de votos nulos por correo es mayor que el numero"
	     << " de votos validos por correo: " << situacion_r << endl;		 
		 
	return 0;	
}
