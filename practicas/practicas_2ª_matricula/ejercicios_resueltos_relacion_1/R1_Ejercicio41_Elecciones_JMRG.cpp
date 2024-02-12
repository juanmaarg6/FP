/*
	Relaci�n de ejercicios 1

	Ejercicio 32: Programa que, dados los votos de unas elecciones, se 
	              distinguen varios casos mediante expresiones l�gicas.
	              
	Entradas: N�mero total de votos registrados (votos_emitidos),
	          N�mero total de votos presenciales (votos_presenciales),
	          N�mero total de votos por correo (votos_correo),
	          N�mero de votos registrados que son v�lidos (votos_validos),
	          N�mero de votos registrados que son nulos (votos_nulos),
	          N�mero de votos v�lidos por correo (votos_validos_correo),
	          N�mero de votos v�lidos presenciales (votos_validos_presenciales),
	          N�mero de votos v�lidos que reciben cada una de las opciones
	          electorales (votos_A, votos_B, votos_C).
	Salidas: Resultados de las diferentes situaciones presentadas (situacion_a,
	         situacion_b, situacion_c, situacion_d, situacion_e, situacion_f,
	         situacion_g, situacion_h, situacion_i, situacion_j, situacion_k,
	         situacion_l, situacion_m, situacion_n, situacion_enie, situacion_o,
	         situacion_p, situacion_q, situacion_r).
	            
	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>		// Inclusi�n de los recursos de E/S
#include <cmath>		// Inclusi�n de los recursos matem�ticos

using namespace std;

// Programa principal

int main() {				
	
	// Declaraci�n de constantes
	
	const int VOTANTES = 100000;
	
	// Declaraci�n de variables
	
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
	
	// C�lculos
	
	abstenciones = VOTANTES - votos_emitidos;
	votos_nulos_correo = votos_correo - votos_validos_correo;
	votos_nulos_presenciales = votos_presenciales - votos_validos_presenciales;

	/**********************************************************************/
    
    // SITUACI�N A: El n�mero de votos emitidos totales es mayor que el n�mero 
	// de votantes.
	
	bool situacion_a = (votos_emitidos > VOTANTES);
	
	/**********************************************************************/
	
    // SITUACI�N B: El n�mero de votos v�lidos no es igual a la suma de los 
	// votos recibidos por las tres opciones.
	
	bool situacion_b = ( votos_validos != (votos_A + votos_B + votos_C) );
	
	/**********************************************************************/
	
    // SITUACI�N C: El n�mero de votos registrados es igual a la suma de los 
	// votos v�lidos y nulos.
	
	bool situacion_c = ( votos_emitidos == (votos_validos + votos_nulos) );
	
	/**********************************************************************/	
	
    // SITUACI�N D: Gana la opci�n A.
	
	bool situacion_d = ( (votos_A > votos_B) && (votos_A > votos_B) );
	
	/**********************************************************************/
	
    // SITUACI�N E: Gana la opci�n B.
	
	bool situacion_e = ( (votos_B > votos_A) && (votos_B > votos_C) );
	
	/**********************************************************************/
	
    // SITUACI�N F: Gana la opci�n C.
	
	bool situacion_f = ( (votos_C > votos_A) && (votos_C > votos_B) );
	
	/**********************************************************************/
	
    // SITUACI�N G: Empatan dos opciones.
	
	bool situacion_g = ( (votos_A == votos_B) || (votos_A == votos_C) 
	                     || (votos_B == votos_C) );
	
	/**********************************************************************/
	
    // SITUACI�N H: Hay un empate t�cnico entre las opciones A y B. Definimos 
	// que ocurre un empate t�cnico cuando la diferencia entre los dos valores 
	// es menor que el 5% de su suma.
	
	bool situacion_h = ( abs(votos_A - votos_B) < 
	                   ( 0.05 * (votos_A - votos_B) ) );
	
	/**********************************************************************/
	
    // SITUACI�N I: La opci�n A obtiene mayor�a absoluta.
	
	bool situacion_i = ( votos_A >= ceil( (votos_emitidos / 2) + 1) );
	
	/**********************************************************************/
	
    // SITUACI�N J: Hay una coalici�n de dos opciones que obtiene mayor�a 
	// absoluta.
	
	bool situacion_j = ( (votos_A + votos_B) >= ceil( (votos_emitidos / 2) + 1) 
					|| (votos_A + votos_C) >= ceil( (votos_emitidos / 2) + 1)
					|| (votos_B + votos_C) >= ceil( (votos_emitidos / 2) + 1) );
	
	/**********************************************************************/
	
    // SITUACI�N K: La coalici�n A-C obtiene mayor�a absoluta.
	
	bool situacion_k = ((votos_A + votos_C) >= ceil( (votos_emitidos / 2) + 1));
	
	/**********************************************************************/
	
    // SITUACI�N L: La opci�n B obtiene menos de 3% de los votos v�lidos
	// registrados.
	
	bool situacion_l = ( votos_B < (0.03 * votos_validos) );
	
	/**********************************************************************/
	
    // SITUACI�N M: La participaci�n es mayor que el 75% del censo de votantes.
	
	bool situacion_m = ( votos_emitidos > (0.75 * VOTANTES) );
	
	/**********************************************************************/
	
    // SITUACI�N N: Queremos saber si la opci�n A puede gobernar "s�lo o en 
	// compa��a de otros" (esto se traduce en que ni la opci�n B, ni la
	// opci�n C, ni la coalici�n B-C, obtengan mayor�a absoluta).
	
	bool situacion_n = !( votos_B >= ceil( (votos_emitidos / 2) + 1) )
	            && !( votos_C >= ceil( (votos_emitidos / 2) + 1) )
				&& !( (votos_B + votos_C) >= ceil( (votos_emitidos / 2) + 1) );
	
	/**********************************************************************/
	
    // SITUACI�N �: El n�mero de votos nulos � el n�mero de abstenciones es 
	// mayor que el n�mero de votos v�lidos.
	
	bool situacion_enie = ( (votos_nulos > votos_validos) 
	                    ||  (abstenciones > votos_validos) );
	
	/**********************************************************************/
	
    // SITUACI�N O: El n�mero de votos nulos y el n�mero de abstenciones es 
	// mayor que el n�mero de votos v�lidos, pero las abstenciones no son 
	// mayores que los votos nulos.
	
	bool situacion_o = ( ( (votos_nulos > votos_validos) 
	                    &&  (abstenciones > votos_validos) )
						&& !(abstenciones > votos_nulos) );
	
	/**********************************************************************/
	
    // SITUACI�N P: El n�mero de votos por correo es mayor que el 20% de los 
	// votos presenciales o el n�mero de abstenciones.
	
	bool situacion_p = ( ( votos_correo > (0.20 * votos_presenciales) ) 
	                    || ( votos_correo > abstenciones ) );
	
	/**********************************************************************/
	
    // SITUACI�N Q: El n�mero de votos nulos por correo es mayor que el n�mero 
	// de votos nulos presenciales.
	
	bool situacion_q = (votos_nulos_correo > votos_nulos_presenciales);
	
	/**********************************************************************/
	
    // SITUACI�N R: El n�mero de votos nulos por correo es mayor que el n�mero 
	// de votos v�lidos por correo.
	
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
