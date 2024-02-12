/*
	Relación de ejercicios 1

	Ejercicio 38: Programa que, dadas la latitud, la longitud y la altura de 
	              dos puntos terrestres, calcula la distancia sobre plano 
				  entre los dos puntos mediante la fórmula de Haversine y 
				  también calcula la distancia real entre los dos puntos.
				  
				  Los valores de latitud y longitud deben verificar
				  -90 <= latitud <= 90 y -180 <= longitud <= 180.
	              
	Entradas: Latitud de los puntos (lat_punto1_grados, lat_punto2_grados),
	          Longitud de los puntos (lon_punto1_grados, lon_punto2_grados),
	          Altura de los puntos (alt_punto1, alt_punto2).
	Salidas: Distancia sobre plano entre los puntos (distancia_plano),
			 Distancia real entre los puntos (distancia_real)

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de los recursos de E/S
#include <cmath>		// Inclusión de los recursos matemáticos
#include <algorithm> 	// Inclusión de los recursos algorítmicos

using namespace std;

// Programa principal

int main() {				
	
	// Declaración de constantes
	
	const double PI = asin(0.5) * 6;		 		
	const double GRADOS_A_RADIANES = PI / 180;	
	const double R = 6372797.560856;
   													   	   
	// Declaración de variables
	
	double lat_punto1_grados = 0.0, lat_punto2_grados = 0.0;
	double lat_punto1_radianes = 0.0, lat_punto2_radianes = 0.0;
	double lon_punto1_grados = 0.0, lon_punto2_grados = 0.0;
	double lon_punto1_radianes = 0.0, lon_punto2_radianes = 0.0;
	double alt_punto1 = 0.0, alt_punto2 = 0.0;
	double sumando1 = 0.0, sumando2 = 0.0, a = 0.0, c = 0.0;
	double distancia_plano = 0.0, distancia_real = 0.0;
	
	// Entradas de datos
	
	cout << " Introduzca el punto 1: ";
	cout << endl << endl << "\t -90 <= Latitud <= 90 (en grados): ";
	cin >> lat_punto1_grados;
	cout << "\t -180 <= Longitud <= 180 (en grados): ";
	cin >> lon_punto1_grados;
	cout << "\t Altura (en metros): ";
	cin >> alt_punto1;
	
	cout << endl << " Introduzca el punto 2: ";
	cout << endl << endl << "\t -90 <= Latitud <= 90 (en grados): ";
	cin >> lat_punto2_grados;
	cout << "\t Longitud (en grados): ";
	cin >> lon_punto2_grados;
	cout << "\t Altura (en metros): ";
	cin >> alt_punto2;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Realizar la conversión de la latitud y la longitud de grados a radianes.
		
		Calcular la distancia sobre plano entre los dos puntos usando la
		fórmula de Haversine.
		
		Calcular la distancia real entre los dos puntos usando el teorema de
		Pitágoras (se puede formar un triángulo rectángulo a partir de la 
		distancia sobre plano de los puntos, la distancia real de los puntos
		y la diferencia de las alturas).
	*/
	
	lat_punto1_radianes = lat_punto1_grados * GRADOS_A_RADIANES;
	lon_punto1_radianes = lon_punto1_grados * GRADOS_A_RADIANES;
	
	lat_punto2_radianes = lat_punto2_grados * GRADOS_A_RADIANES;
	lon_punto2_radianes = lon_punto2_grados * GRADOS_A_RADIANES;
	
	sumando1 = sin(0.5 * (lat_punto2_radianes - lat_punto1_radianes)) 
	           * sin(0.5 * (lat_punto2_radianes - lat_punto1_radianes));
	
	sumando2 = cos(lat_punto1_radianes) * cos(lat_punto2_radianes)
	           * sin(0.5 * (lon_punto2_radianes - lon_punto1_radianes)) 
	           * sin(0.5 * (lon_punto2_radianes - lon_punto1_radianes));
	
	a = sumando1 + sumando2;
	
	c = 2 * asin(min(1.0,sqrt(a)));
	
	distancia_plano = R * c;
	
	distancia_real = sqrt((distancia_plano * distancia_plano) - 
	                      (abs(alt_punto2 - alt_punto1) * 
						   abs(alt_punto2 - alt_punto1)));
	
	// Salidas
	
	cout << endl << endl << " Distancia sobre plano entre los dos puntos: " 
	     << distancia_plano << " metros";
	cout << endl << " Distancia real entre los dos puntos: " 
	     << distancia_real << " metros" << endl << endl;
	     
	return 0;
}
