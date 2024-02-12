/*
	Relación de ejercicios 4

	Ejercicio 38: Programa que, dado el centro de una circunferencia y su radio
	              y las esquinas superior izquierda e inferior derecha de un
				  rectángulo, dibuja la circunferencia y el rectángulo.
	              
	Entradas: Centro de la circunferencia (matriz[][]).
	Salidas: Valor y posición del elemento mayor de entre los mínimos 
	         de cada fila de la matriz (mayor_minimo, posicion_mayor_minimo).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <cmath>

using namespace std;

/****************************************************************************/
// Registro utilizado para representar un punto del plano (x,y)
/****************************************************************************/
struct Punto2D {
	
	int x;	// Abscisa del punto
	int y;	// Ordenada del punto
};

/****************************************************************************/
// Registro utilizado para representar un rectángulo
/****************************************************************************/
struct Rectangulo {
	
	Punto2D punto_sup_izq;		// Esquina superior izquierda del rectángulo
	Punto2D punto_inf_der;		// Esquina inferior derecha del rectángulo
};

/****************************************************************************/
// Registro utilizado para representar una circunferencia
/****************************************************************************/
struct Circunferencia {
	
	Punto2D centro;			// Centro de la circunferencia
	int radio;			// Radio de la circunferencia
};

/****************************************************************************/
// Función: EliminaUltimosSeparadores
// Recibe: Cadena (cadena).
// Devuelve: 'cadena' sin separadores finales (cadena).
/****************************************************************************/
string EliminaUltimosSeparadores(string cadena) {
	
	int longitud = cadena.length();
	
   	while( longitud > 0 && isspace(cadena.back()) ) {
		cadena.pop_back();
		longitud = cadena.length();
	}
        
	return cadena;
}

/****************************************************************************/
// Función: EliminaPrimerosSeparadores
// Recibe: Cadena (cadena).
// Devuelve: 'cadena' sin separadores iniciales (cadena).
/****************************************************************************/
string EliminaPrimerosSeparadores(string cadena) {
	
	int pos = 0;
	int longitud = cadena.length();
	
	while(pos < longitud && isspace(cadena.at(pos)) ) {
		pos++;
	}
	
	string local;
	while(pos < longitud) {
		local.push_back(cadena.at(pos));
		pos++;
	}
		
	return local;
}

/****************************************************************************/
// Función: EliminaSeparadoresInicialesyFinales
// Recibe: Cadena (cadena).
// Devuelve: 'cadena' sin separadores iniciales ni finales (cadena).
/****************************************************************************/
string EliminaSeparadoresInicialesyFinales(string cadena) {	
	return EliminaUltimosSeparadores(EliminaPrimerosSeparadores(cadena)); 
}

/****************************************************************************/
// Función: LeeEntero
// Recibe: Mensaje de texto (titulo).
// Devuelve: Número entero (entero).
/****************************************************************************/
int LeeEntero(string titulo) {
	
	string numero;
	bool es_entero = true;
	do {
		
		es_entero = true;
		
		cout << titulo;	
		getline (cin, numero);
		
		int longitud_cadena = numero.length();
		
		if(longitud_cadena > 0) {
			
			// Eliminamos los separadores iniciales y finales de 'numero'
			numero = EliminaSeparadoresInicialesyFinales(numero);

			// Eliminamos el signo de 'numero' si lo hubiera
			int i = 0;
			
			if( (numero[0] == '-') || (numero[0] == '+') )
				i = 1;
	
			while(i < longitud_cadena) {
				
				if( (numero[i] < '0') || (numero[i] > '9') )
					es_entero = false;	
					
				i++;
			}		
		}
		else
			es_entero = false;		
	}while(!es_entero);

	return ( stoi(numero) ); 
}

/****************************************************************************/
// Función: LeeEnteroEnRango
// Recibe: Mensaje de texto (titulo),
//		   Límite inferior del rango (menor),
//		   Límite superior del rango (mayor).
// Devuelve: Número entero dentro del rango [menor-mayor] (entero).
/****************************************************************************/
int LeeEnteroEnRango(string titulo, int menor, int mayor) {
	
	int entero;
	bool en_rango = false;
	
	do {
		entero = LeeEntero(titulo);
		en_rango = (entero >= menor && entero <= mayor);
	} while (!en_rango);
	
	return entero;
}

/****************************************************************************/
// Función: LeeEnteroMayor
// Recibe: Mensaje de texto (titulo),
//		   Número entero de referencia (referencia).
// Devuelve: Número entero mayor que 'referencia' (entero).
/****************************************************************************/
int LeeEnteroMayor(string titulo, int referencia) {
	
	int entero;
	bool es_mayor;
	
	do {
		entero = LeeEntero (titulo);
		es_mayor = (entero > referencia);
	} while (!es_mayor);
	
	return entero;
}

/****************************************************************************/
// Función: PuntoPerteneceAlRectangulo
// Recibe: Rectangulo (rectangulo),
//         Punto del plano (punto).
// Devuelve: True (1) si 'punto' pertenece a 'rectangulo' y False (0) si no
//           pertenece.
/****************************************************************************/
bool PuntoPerteneceAlRectangulo(Rectangulo rectangulo, Punto2D punto) {
	
	bool pertenece_al_rectangulo = false;
	
	if( ( (punto.x >= rectangulo.punto_sup_izq.x) && 
	      (punto.x <= rectangulo.punto_inf_der.x) ) && 
	    ( (punto.y >= rectangulo.punto_inf_der.y) && 
		  (punto.y <= rectangulo.punto_sup_izq.y) ) ) {
		  	
	    	pertenece_al_rectangulo = true;
	}
	    	
	return (pertenece_al_rectangulo);
}

/****************************************************************************/
// Función: PuntoPerteneceACircunferencia
// Recibe: Circunferencia (circunferencia),
//         Punto del plano (punto).
// Devuelve: True (1) si 'punto' pertenece a 'circunferencia' y False (0) si 
//           no pertenece.
/****************************************************************************/
bool PuntoPerteneceACircunferencia(Circunferencia circunferencia, 
                                   Punto2D punto) {
	
	bool pertenece_a_la_circunferencia = false;
	
	double dif_x = circunferencia.centro.x - punto.x;
	double dif_y = circunferencia.centro.y - punto.y;
	
	if( ( (dif_x * dif_x) + (dif_y * dif_y) ) <= 
	    ( circunferencia.radio * circunferencia.radio ) ) {
	    	
	    pertenece_a_la_circunferencia = true;
	}
		
	return (pertenece_a_la_circunferencia);
}

/****************************************************************************/
// Función principal
/****************************************************************************/
int main() {
	
	// Declaración de constantes
		
	const char PUNTO = '.';
	const char ASTERISCO = '*';
	const char CRUZ = 'x';
	
	// Declaración de variables
	
	// Matriz de datos
	const int MAX_FILAS = 51;
	const int MAX_COLS = 51;
	
	char tablero[MAX_FILAS][MAX_COLS];
	
	// Circunferencia
	Circunferencia circunferencia;
	
	// Rectángulo
	Rectangulo rectangulo;
	
	// Entradas de datos de la circunferencia
	
	cout << " Introduzca el centro de la circunferencia: ";
	cout << endl;
	circunferencia.centro.x = LeeEnteroEnRango("\t Coordenada x: ", 0, 
											   MAX_COLS - 1);
	circunferencia.centro.y = LeeEnteroEnRango("\t Coordenada y: ", 0, 
											   MAX_FILAS - 1);
	circunferencia.radio = LeeEnteroMayor
	                       (" Introduzca el radio de la circunferencia: ",
						    0);
	
	// Cálculos respecto a la circunferencia introducida
	
	Punto2D punto1;
	
	// Asignamos al tablero los puntos que forman la circunferencia 
	// introducida
	for(punto1.x = 0; punto1.x < MAX_FILAS; punto1.x++)
		for(punto1.y = 0; punto1.y < MAX_COLS; punto1.y++) {
		
		if( PuntoPerteneceACircunferencia(circunferencia, punto1) )	
			tablero[MAX_COLS - 1 - punto1.y][punto1.x] = ASTERISCO;
		else
			tablero[MAX_COLS - 1 - punto1.y][punto1.x] = PUNTO;
		}
	
	// Salida del tablero junto con la circunferencia introducida dibujada
	
	cout << endl << endl;
	
	for(int i = 0; i < MAX_FILAS; i++) {
		for(int j = 0; j < MAX_COLS; j++) 
			cout << tablero[i][j];
	
		cout << endl;
	}
	
	cout << endl << endl;
	
	// Entradas de datos del rectángulo
	
	cout << " Introduzca la esquina superior izquierda del rectangulo: ";
	cout << endl;
	rectangulo.punto_sup_izq.x = LeeEnteroEnRango("\t Coordenada x: ", 0, 
											      MAX_COLS - 1);
	rectangulo.punto_sup_izq.y = LeeEnteroEnRango("\t Coordenada y: ", 0, 
											      MAX_FILAS - 1);
	cout << " Introduzca la esquina inferior derecha del rectangulo: ";
	cout << endl;
	rectangulo.punto_inf_der.x = LeeEnteroEnRango("\t Coordenada x: ", 0, 
											      MAX_COLS - 1);
	rectangulo.punto_inf_der.y = LeeEnteroEnRango("\t Coordenada y: ", 0, 
											      MAX_FILAS - 1);
	
	// Cálculos respecto al rectángulo introducido
	
	Punto2D punto2;
	
	// Asignamos al tablero los puntos que forman el rectángulo 
	// introducido, destacando, si hubiera, los puntos de intersección del
	// rectángulo con la circunferencia
	for(punto2.x = 0; punto2.x < MAX_FILAS; punto2.x++)
		for(punto2.y = 0; punto2.y < MAX_COLS; punto2.y++) {
		
		if( PuntoPerteneceAlRectangulo(rectangulo, punto2) )	
			tablero[MAX_COLS - 1 - punto2.y][punto2.x] = ASTERISCO;
		
		if( PuntoPerteneceAlRectangulo(rectangulo, punto2) && 
		    PuntoPerteneceACircunferencia(circunferencia, punto2) ) {
		   
		   tablero[MAX_COLS - 1 - punto2.y][punto2.x] = CRUZ; 	
		}
			
		}
	
	// Salida del tablero junto con la circunferencia introducida y el
	// rectángulo introducido dibujados, destacando, si hubiera, los puntos de 
	// intersección del rectángulo con la circunferencia
	
	cout << endl << endl;
	
	for(int i = 0; i < MAX_FILAS; i++) {
		for(int j = 0; j < MAX_COLS; j++) 
			cout << tablero[i][j];
	
		cout << endl;
	}
	
	cout << endl << endl;		

	return 0;	
}
