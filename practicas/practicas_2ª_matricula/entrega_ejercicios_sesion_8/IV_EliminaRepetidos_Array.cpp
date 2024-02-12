/*
	Relación de ejercicios 4

	Ejercicio 13, Apartado c): Programa que, dado un vector de números 
	                           enteros, elimina los valores repetidos
	                           de dicho vector.
	                           
	                           Para ello usa dos apuntadores, 'posicion_lectura'
							   y 'posicion_escritura', que nos van indicando, 
							   en cada momento, la componente que se está 
							   leyendo y el sitio dónde tiene que escribirse.
	              
	Entradas: Secuencia de números enteros almacenada en un vector (datos).
	Salidas: Secuencia de números enteros sin valores repetidos almacenada
	         en un vector de copia (copia_datos).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	
	// Vector de datos
	const int MAX_DATOS = 50; 
	int datos[MAX_DATOS];
	
	int total_utilizados = 0;	

	// Entradas de datos 
	
	bool sigo = true; 
	int dato; 
	
	cout << " Introduzca una secuencia de numeros enteros" 
	     << " (-1 para finalizar): ";
	     
	cin >> dato;
	
	while( (dato >= 0) && (sigo) ) {

		datos[total_utilizados]	= dato;
		total_utilizados++;

		if (total_utilizados == MAX_DATOS) 
			sigo = false;
		else 
			cin >> dato;
	}
	
	// Copia de los datos originales en dos vectores para trabajar sobre 
	// los nuevos vectores y no perder los datos originales
	
	int copia_datos[MAX_DATOS];
	int total_utilizados_copia = 0;	

	for(int i = 0; i < total_utilizados; i++) 
		copia_datos[i] = datos[i];
		
	total_utilizados_copia = total_utilizados;
	
	// Se muestran los datos originales
	
	cout << endl;
	cout << "--------------------------------------------------------";
	cout << endl << endl;	
 	cout << " Datos originales: " << "(" << total_utilizados 
	     << " datos): ";	
	cout << endl << endl << "\t";
	for(int i = 0; i < total_utilizados; i++) 
		cout << datos[i] << "  "; 
	cout << endl;
	
	cout << endl;
	cout << "--------------------------------------------------------";
	cout << endl << endl;
	
	// Se muestran los datos del vector de copia antes de procesarlos 
	
	cout << endl;
	cout << "--------------------------------------------------------";
	cout << endl << endl;
 	cout << " Copia del vector antes de eliminar repetidos "
	     << " (" << total_utilizados_copia << " datos):";	
	cout << endl << endl << "\t";
	for(int i = 0; i < total_utilizados_copia; i++) 
		cout << copia_datos[i] << "  "; 
	cout << endl;
	
	// Algoritmo de eliminación de valores repetidos del vector
	
	int posicion_lectura = 1;
	int posicion_escritura = 1;
	
	copia_datos[0] = datos[0];
	
	while(posicion_lectura < total_utilizados_copia) {
		
		bool repetido = false;
		
		// Obtenemos el valor de la casilla del vector
		int elemento = copia_datos[posicion_lectura]; 
		
		// Comprobamos si está repetido y, para ello, recorremos
		// el vector 'copia_datos' hasta 'posicion_escritura'
		for(int i = 0; i < posicion_escritura && repetido == false; i++)
			if(copia_datos[i] == elemento)
				repetido = true;
		
		// Si no está repetido, añadimos dicho elemento al final
		// del vector 'copia_datos' e incrementamos 'posicion_escritura'
		// en 1
		if(!repetido) {
			copia_datos[posicion_escritura] = elemento;
			posicion_escritura++;
		}
		
		// Se pasa a leer el valor de la siguiente casilla del vector
		posicion_lectura++;
	}
	
	total_utilizados_copia = posicion_escritura;
	
	// Se muestran los datos del vector de copia después de procesarlos 
	
	cout << endl;	
 	cout << " Copia del vector despues de eliminar repetidos "
	     << " (" << total_utilizados_copia << " datos):";
	cout << endl << endl << "\t";
	for(int i = 0; i < total_utilizados_copia; i++) 
		cout << copia_datos[i] << "  "; 
	cout << endl;
	
	cout << endl;	
	cout << "--------------------------------------------------------";
	cout << endl << endl;
	
	return 0;
}
