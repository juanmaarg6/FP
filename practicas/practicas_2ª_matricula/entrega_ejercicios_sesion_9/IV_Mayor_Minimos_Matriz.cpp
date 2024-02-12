/*
	Relaci�n de ejercicios 4

	Ejercicio 32: Programa que, dada una matriz de n�meros enteros, calcula
	              la posici�n del elemento que sea el mayor de entre los
	              m�nimos de cada fila.
	              
	Entradas: N�mero de filas de la matriz (filas),
	          N�mero de columnas de la matriz (columnas),
			  Elementos de la matriz de n�meros enteros (matriz[][]).
	Salidas: Valor y posici�n del elemento mayor de entre los m�nimos 
	         de cada fila de la matriz (mayor_minimo, posicion_mayor_minimo).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>

using namespace std;

/****************************************************************************/
// Registro utilizado para almacenar la posicion de un elemento de 
// una matriz
/****************************************************************************/
struct PosicionEnMatriz {
	
	int fila;		// Fila del elemento de la matriz
	int columna;	// Columna del elemento de la matriz
};

/****************************************************************************/
// Funci�n principal
/****************************************************************************/
int main() {
	
	// Declaraci�n de variables
	
	// Matriz de datos
	const int MAX_FILAS = 50;
	const int MAX_COLS = 50;
	int matriz[MAX_FILAS][MAX_COLS];
	
	int filas, columnas;
	
	// Entradas de datos
	
	// Dimensiones de la matriz
	do {
		cout << " Numero de filas de la matriz: ";
		cin >> filas;
	}while( (filas < 1) || (filas > MAX_FILAS) );
	   
	do {
		cout << " Numero de columnas de la matriz: ";
		cin >> columnas;
	}while( (columnas < 1) || (columnas > MAX_COLS) );

	// Datos de la matriz
	for(int i = 0; i < filas; i++)
		for(int j = 0; j < columnas; j++) {
			
			cout << " Elemento (" << i << ", " << j << ") = ";
			cin >> matriz[i][j];
		}

	// C�lculos
		
	int minimos_filas[MAX_FILAS];
	PosicionEnMatriz posiciones_minimos_filas[MAX_FILAS];
	
	int total_utilizados_minimos_filas = 0;
	
	for(int i = 0; i < filas; i++) {
		
		// Calculamos el m�nimo de cada fila y su posici�n en la matriz
		
		// El primer m�nimo de la fila 'i' est� en la columna 0
		int min_fila = matriz[i][0];
		PosicionEnMatriz pos_min_fila = {i, 0};
		
		// Recorremos toda la fila 'i' de la matriz y, si corresponde,
		// actualizamos el valor del m�nimo y su posici�n
		for(int j = 1; j < columnas; j++) 
			if(matriz[i][j] < min_fila) {
				min_fila = matriz[i][j];
				pos_min_fila = {i, j};				
			}
		
		// Almacenamos en un vector los m�nimos de cada fila y en otro vector
		// la posicion de dicho m�nimo en la matriz	
		minimos_filas[total_utilizados_minimos_filas] = min_fila;
		posiciones_minimos_filas[total_utilizados_minimos_filas] = pos_min_fila;
		
		total_utilizados_minimos_filas++;
	}
	
	// Calculamos el mayor de entre los m�nimos de cada fila y su posici�n
	// en la matriz
	
	// El mayor de entre todos los m�nimos comienza siendo el m�nimo
	// de la primera fila de la matriz (minimos_filas[0]) con su
	// posici�n en la matriz correspondiente (posiciones_minimos_filas[0])
	int mayor_minimo = minimos_filas[0];
	PosicionEnMatriz posicion_mayor_minimo = posiciones_minimos_filas[0];
	
	// Recorremos todo el vector 'minimos_filas[]' y, si corresponde,
	// actualizamos el valor del mayor de entre todos los m�nimos
	// y su posici�n
	for(int i = 0; i < total_utilizados_minimos_filas; i++) 
		if(minimos_filas[i] > mayor_minimo) {
	    	mayor_minimo = minimos_filas[i];
			posicion_mayor_minimo = posiciones_minimos_filas[i];
	    }		
		
	// Salidas
	
	cout << endl;
	cout << " Valor del mayor entre los minimos de cada fila de la matriz: " 
	     << mayor_minimo << endl;
	cout << " Posicion en la matriz del mayor entre los minimos de cada fila: "
	      << "(" << posicion_mayor_minimo.fila << "," 
		  << posicion_mayor_minimo.columna << ")";
	cout << endl << endl;
	
	return 0;	
}
