/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// PRUEBA 02 - TIPO A
//
/***************************************************************************/

#include<iostream>
#include <iomanip>
#include <string>
#include<ctime>
#include<cstdlib>
#include<cctype>
using namespace std;
	
/***************************************************************************/
/***************************************************************************/

struct IntentosNumero {
	int numero;
	int intentos;
};

/***************************************************************************/
/***************************************************************************/

int main()
{		
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	
    //.......................................................................
	// Para generar números aleatorios

	const int NUM_FILAS = 5;  // Núm. valores posibles
	const int NUM_COLS  = 5;  // Núm. valores posibles
	
	const int NUM_DATOS_LINEA = 10; // Para la presentación de datos
	
	
	// COMPLETAR
	
	const int MIN_VALOR = 1;
	const int MAX_VALOR = NUM_FILAS * NUM_COLS ;
	
	int matriz[NUM_FILAS][NUM_COLS] = {};
	
	// Inicializa el generador de números aleatorios con el reloj del 
	// sistema  (hora actual)
	time_t t;
	srand ((int) time(&t)); 
	
	// RELLENAR MATRIZ
			
	IntentosNumero numeros[NUM_FILAS * NUM_COLS] = { {0, 0} };
	int utiles_numeros = 0;
	
	int valor = MIN_VALOR;
	int cont_total = 0;
	
	while(valor <=  MAX_VALOR) {
		
		numeros[utiles_numeros].numero = valor;
		valor++;
		utiles_numeros++;
	}
	
	int i = 0;
		
	while(i < utiles_numeros) {
		
		int numero = numeros[i].numero;
						
		int f_aleatoria = rand() % NUM_FILAS;
		int c_aleatoria = rand() % NUM_COLS;
		
		bool casilla_libre = (matriz[f_aleatoria][c_aleatoria] == 0);
		
		if(casilla_libre) {
			matriz[f_aleatoria][c_aleatoria] = numero;
			numeros[i].intentos++;
			i++;
		}
		else
			numeros[i].intentos++;
		
		cont_total++;
	}
	
	double media = double(cont_total) / MAX_VALOR;

	/* 
		Recuerde que la ejecución de
		
			int valor = rand() % NUM; 

	  	genera un num. aleatorio   0 <= valor < NUM
	*/
			
				
	// MOSTRAR INTENTOS

	cout << endl; 
	cout << "Intentos para alojar los valores: " << endl; 
	cout << endl; 

	//.............. COMPLETAR
	
	for(int i = 0; i < utiles_numeros; i++) {
		cout << setw(5) << numeros[i].intentos;
		
		if( ( (i+1) % NUM_DATOS_LINEA) == 0)
			cout << endl;
	}
	
	cout << endl << endl;
	
	// MOSTRAR RESUMEN
	
	cout << endl; 
	cout << "Intentos totales:  " << setw(5) << cont_total << endl; 
	cout << "Media: " << setw(6) << setprecision(2) << media << endl; 
	cout << endl; 

	//.............. COMPLETAR
	

	// MOSTRAR MATRIZ

	cout << endl; 
	cout << "Matriz de valores: " << endl; 
	cout << endl; 
	
	for(int i = 0; i < NUM_FILAS; i++) {
		for(int j = 0; j < NUM_COLS; j++)
			cout << setw(5) << matriz[i][j];
		
		cout << endl;
	}
	
	//.............. COMPLETAR

	return 0;	
}

/***************************************************************************/
/***************************************************************************/
