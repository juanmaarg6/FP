/*
	Relación de ejercicios 4

	Ejercicio 36: Programa que, dada una matriz con las distancias de
	              caminos directos que conectan un conjunto de ciudades:
	              
	              a) Obtiene la ciudad (su índice) con mayor número de 
				     conexiones directas.
				     
				  b) Dada una ciudad, obtiene las ciudades conectadas 
				     directamente con dicha ciudad.
				     
				  c) Dadas dos ciudades i y j para las cuales no existe un 
				     camino directo, obtiene aquella ciudad intermedia z que 
					 permita hacer el trayecto entre i y j de la forma
					 más económica posible. Es decir, se trata de encuentra una 
					 ciudad z tal que d(i; z) + d(z; j) sea mínima 
					 (d(a; b) es la distancia entre las ciudades a y b). Si
					 dicha ciudad no existiera, se indica expresamente.
					 
				  d) Lee una serie de valores int que representan números de 
				     ciudades (el terminador será el valor -1) e indica si 
					 todas las ciudades tienen conexiones directas entre sí.
	              
	Entradas: Número de ciudades de la red (num_ciudades),
	          Distancias de los caminos directos que conectan las
			  ciudades de la red (red_ciudades[][]).
	Salidas: Ciudad con mayor número de conexiones directas 
	         (ciudad_mayor_num_conexiones),
	         Ciudades conectadas con una ciudad dada,
	         Ciudad intermedia que permite hacer el trayecto entre dos
	         ciudades, las cuales no están conectadas entre sí, de la forma
	         más económicas posible (),
	         Comprobación de si una serie de ciudades dadas tienen conexiones
	         directas entre sí ().

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>

using namespace std;

/****************************************************************************/
// Función principal
/****************************************************************************/
int main() {
	
	// Declaración de variables
	
	// Matriz de datos
	const int MAX_FILAS = 50;
	const int MAX_COLS = 50;
	
	double red_ciudades[MAX_FILAS][MAX_COLS];
	
	// Número de ciudades de la red
	int num_ciudades;
	
	// Entradas de datos
	
	// Lectura del número de ciudades de la red
	do {
		cout << " Numero de ciudades de la red: ";
		cin >> num_ciudades;
	}while( (num_ciudades < 0) || (num_ciudades > MAX_COLS) );
	
	// Lectura de las distancias entre las ciudades
	
	double distancia;
	int inicio = 1;
	
	cout << " Distancias entre las ciudades (en km): ";
	cout << endl << endl;
	
	for(int i = 0; i < num_ciudades; i++) {
		for(int j = inicio; j < num_ciudades; j++) {
				
				if(i == j)
					red_ciudades[i][j] = 0;
				else {
					string msg = "\t Distancia de la ciudad " + 
					                to_string(i+1) + " a la ciudad " + 
									to_string(j+1) + ": ";					
					cout << msg;
					cin >> distancia;
					
					red_ciudades[i][j] = distancia;
					red_ciudades[j][i] = red_ciudades[i][j];
				}
		}
		inicio++;
	}
	
    /**********************************************************************/   		
	// 							Apartado a)                               //
    /**********************************************************************/  
	
	// Cálculos
			
	int num_conexiones = 0, mayor_num_conexiones = 0;
	int ciudad_mayor_num_conexiones = 0;
	
	for(int i = 0; i < num_ciudades; i++) {
		
		num_conexiones = 0;
		
		// Calculamos el número de conexiones de una ciudad con el resto
		for(int j = 0; j < num_ciudades; j++)
			if(red_ciudades[i][j] != 0)
				num_conexiones++;
		
		// Si el número de conexiones de dicha ciudad es mayor que el de
		// otra ciudad, entonces dicha ciudad pasa a ser la ciudad con el
		// mayor número de conexiones directas
		if(num_conexiones > mayor_num_conexiones) {
			mayor_num_conexiones = num_conexiones;
			ciudad_mayor_num_conexiones = i+1;
		}
	}
		
	// Salidas
	
	cout << endl << endl;
	cout << " Ciudad con mayor numero de conexiones directas: " 
	     << ciudad_mayor_num_conexiones;
	cout << endl;
	cout << " Numero de conexiones directas de la ciudad " 
	     << ciudad_mayor_num_conexiones << ": " << mayor_num_conexiones;
	cout << endl << endl;
	
    /**********************************************************************/   		
	// 							Apartado b)                               //
    /**********************************************************************/  
	
	// Cálculos
	
	int ciudad;
	int conexiones_ciudad[MAX_FILAS];
	int utiles_conexiones_ciudad = 0;
	
	do {
		cout << " Indice de una ciudad: ";
		cin >> ciudad;
	}while( (ciudad < 1) || (ciudad > num_ciudades) );
	
	// Para dicha ciudad introducidad, consultamos en la matriz 
	// 'red_ciudades' las conexiones que tiene con respecto al resto
	// de ciudades
	for(int j = 0; j < num_ciudades; j++)
		if(red_ciudades[ciudad-1][j] != 0) {
			conexiones_ciudad[utiles_conexiones_ciudad] = j + 1;
			utiles_conexiones_ciudad++;
		}
		
	// Salidas
	
	cout << " La ciudad " << ciudad << " tiene conexiones directas con"
	     << " las siguientes ciudades: ";

	for(int i = 0; i < utiles_conexiones_ciudad; i++)
		cout << conexiones_ciudad[i] << " ";

	cout << endl << endl;
	
    /**********************************************************************/   		
	// 							Apartado c)                               //
    /**********************************************************************/ 
	
	// Cálculos
	
	int ciudad1, ciudad2;
	
	do {
		cout << " Indice de una ciudad: ";
		cin >> ciudad1;
	}while( (ciudad1 < 1) || (ciudad1 > num_ciudades) );
	
	do {
		cout << " Indice de otra ciudad: ";
		cin >> ciudad2;
	}while( (ciudad2 < 1) || (ciudad2 > num_ciudades) );
	
	// Comprobamos que las dos ciudades introducidas no están conectadas
	// directamente
	bool no_estan_conectadas = (red_ciudades[ciudad1-1][ciudad2-1] == 0);
	
	int ciudad_distancia_minima;
	double distancia_minima;
	
	if(no_estan_conectadas) {
		
		// Almacenamos en un array las ciudades intermedias de 'ciudad1' y
		// 'ciudad2'
		int ciudades_intermedias[MAX_FILAS]; 
		int util_ciudades_intermedias = 0; 
		
		bool es_intermedia = false;
		
		for (int j = 0; j < num_ciudades; j++) {
			
			// Una ciudad es intermedia entre 'ciudad1' y 'ciudad2' si
			// las distancias de dicha ciudad a las otras dos ciudades
			// son distintas de cero
			es_intermedia = ( (red_ciudades[ciudad1-1][j] != 0) && 
			                  (red_ciudades[ciudad2-1][j] != 0) );
			                  
			if(es_intermedia) {
				ciudades_intermedias[util_ciudades_intermedias] = j + 1;
				util_ciudades_intermedias++;
			}
		}	
		
		// Inicializamos 'distancia_minima' como la suma de todas las
		// distancias entre ciudades, para así garantizar que podremos
		// encontrar una distancia menor que esta en el trayecto
		// 'ciudad1' --> Ciudad intermedia buscada --> 'ciudad2'
		for(int i = 0; i < num_ciudades; i++)
			for(int j = i+1; j < num_ciudades; j++)	
				distancia_minima += red_ciudades[i][j];
		
		// Calculamos la ciudad intermedia de 'ciudad1' y 'ciudad2' que
		// haga mínima la distancia del trayecto 'ciudad1' -->
		// --> Ciudad intermedia buscada --> 'ciudad2'
		for(int i = 0; i < util_ciudades_intermedias; i++) {
			
			double distancia_actual = 
			            red_ciudades[ciudad1-1][ciudades_intermedias[i]-1] + 
			            red_ciudades[ciudad2-1][ciudades_intermedias[i]-1];
						
			if(distancia_actual < distancia_minima) {
				distancia_minima = distancia_actual;
				ciudad_distancia_minima = ciudades_intermedias[i];				
			}	
		}
	}
	
	// Salidas
	
	if(no_estan_conectadas) {
		cout << " Para ir desde la ciudad " << ciudad1 << " hasta la ciudad " 
		     << ciudad2 << " de la forma mas economica posible, se debe pasar"
			 << " por la ciudad " << ciudad_distancia_minima;
		cout << endl;
		cout << " La distancia recorrida seria de " << distancia_minima 
		     << " km";
	}
	else 
		cout << " Las ciudades " << ciudad1 << " y " << ciudad2 << " estan"
		     << " conectadas directamente, luego no existe ninguna ciudad"
			 << " intermedia que las conecte";
		
	cout << endl << endl;
	
    /**********************************************************************/   		
	// 							Apartado d)                               //
    /**********************************************************************/ 
	
	// Cálculos
	
	int secuencia_ciudades[MAX_FILAS];
	int utiles_secuencia_ciudades = 0;
	
	int nueva_ciudad;
	bool finalizar;
		
	bool hay_conexion_directa = true;

	cout << " Secuencia de ciudades (-1 para finalizar): ";
	
	// Almacenamos en un array la secuencia de ciudades introducidas	
	do {
		
		cin >> nueva_ciudad;
	
		
		if(nueva_ciudad != -1) {
			secuencia_ciudades[utiles_secuencia_ciudades] = nueva_ciudad;
			utiles_secuencia_ciudades++;
		}
			
		finalizar = (nueva_ciudad == -1);
		
	}while(!finalizar);
		
	// Comprobamos para cada ciudad de la secuencia introducidad, que 
	// dicha ciudad está conectada con el resto de ciudades de la secuencia
	for(int i = 0; i < utiles_secuencia_ciudades && hay_conexion_directa; i++) {
		
		int ciudad_referencia = secuencia_ciudades[i] - 1;
		
		for(int j = i+1; j < utiles_secuencia_ciudades && hay_conexion_directa; 
		    j++) {
			
			int otra_ciudad = secuencia_ciudades[j] - 1;
			
			if(red_ciudades[ciudad_referencia][otra_ciudad] == 0)
				 hay_conexion_directa = false;
		}
	}
		
	// Salidas
	
	if(utiles_secuencia_ciudades != 0) {
		if(hay_conexion_directa)
			cout << " Todas las ciudades introducidas tienen conexiones directas"
			     << " entre si";
		else
			cout << " No todas las ciudades introducidas tienen conexiones"
			     << " directas entre si";
	}
	else
		cout << " No se ha introducido ninguna secuencia de ciudades";
		
	cout << endl << endl;

	return 0;	
}
