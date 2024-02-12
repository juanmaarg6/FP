/*
	Ejercicio 14: Programa que tiene como entrada una matriz
					  de numeros reales y muestra dos vectores:
					  
					  1) Vector cuyas componentes son la suma
					     de los elementos de cada fila.
					     
					  2) Vector cuyas componentes son la suma
					     de los elementos de cada columna.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

// Funcion para introducir los elementos de la matriz

double IntroducirMatriz(int filas, int columnas, double Matriz[20][20]){
	cout << " Introduzca  los elementos de la matriz: \n";
		for(int i = 0; i < filas; i++){
			for(int j = 0; j < columnas; j++){
				cout << " Fila " << i << " // Columna " << j << ": ";
				cin >> Matriz[i][j];
			}
		}
		
	return 0;
}
	
// Funcion para mostrar la matriz en pantalla

double MostrarMatriz(int filas, int columnas, double Matriz[20][20]){
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++)
			cout << " " << Matriz[i][j];
		cout << "\n";
	}
	
	return 0;
}

// Funcion para hacer la suma de todos los elementos de cada fila

double SumaFilas(int filas, int columnas, double Matriz[20][20], double vector[20]){
	int i = 0;
	for(int j = 0; j < filas; j++){
		for(int k = 0; k < columnas; k++)
			vector[i] += Matriz[j][k];
		i++;
	}
	
	return vector[20];
}

// Funcion para hacer la suma de todos los elementos de cada columna

double SumaColumnas(int filas, int columnas, double Matriz[20][20], double vector[20]){
	int i = 0;
	for(int j = 0; j < columnas; j++){
		for(int k = 0; k < filas; k++)
			vector[i] += Matriz[k][j];
		i++;
	}
	
	return vector[20];
}

// Funcion principal

int main(){
	const int MAXIMA_DIMENSION = 20;
	
	double matriz_original [MAXIMA_DIMENSION][MAXIMA_DIMENSION] = {0};
	double vector_filas [MAXIMA_DIMENSION] = {0};
	double vector_columnas [MAXIMA_DIMENSION] = {0};
	
	int filas = 0, columnas = 0;
	
	/*
		Algoritmo:
		
		El usuario introduce el numero de filas y columnas de la matriz.
		
		El usuario introduce cada elemento de la matriz.
		
		Mostrar en pantalla la matriz introducida.
		
		Sumar los elementos de cada fila.
		Mostrar en pantalla el vector cuyas componentes son las sumas
		de los elementos de cada fila de la matriz.
		
		Sumar los elementos de cada columna.
		Mostrar en pantalla el vector cuyas componentes son las sumas
		de los elementos de cada columna de la matriz.
	*/
		
	cout << " Introduzca el numero de filas de la matriz: ";
	cin >> filas;
	
	cout << " Introduzca el numero de columnas de la matriz: ";
	cin >> columnas;
	
	if(filas > MAXIMA_DIMENSION || columnas > MAXIMA_DIMENSION){
		cout << "\n Error. La maxima dimension de la matriz es: " << MAXIMA_DIMENSION << "x" << MAXIMA_DIMENSION << endl << endl;
		exit(-1);
	}

	cout << endl;
	
	IntroducirMatriz(filas, columnas, matriz_original);
	
	cout << "\n La matriz introducida es:" << endl << endl;
	MostrarMatriz(filas, columnas, matriz_original);
	
	SumaFilas(filas, columnas, matriz_original, vector_filas);
	
	cout << "\n Suma de las filas: ";
	for(int i = 0; i < filas; i++)
		cout << vector_filas[i] << " ";
	
	SumaColumnas(filas, columnas, matriz_original, vector_columnas);
	
	cout << "\n Suma de las columnas: ";
	for(int j = 0; j < columnas; j++)
		cout << vector_columnas[j] << " ";
	
	cout << endl << endl;
	
	system("pause");
}
