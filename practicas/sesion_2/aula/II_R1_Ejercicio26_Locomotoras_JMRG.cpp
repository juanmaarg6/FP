/*
	Ejercicio 26: Programa que calcula la distancia que ha recorrido
	              cada uno de los dos trenes antes de impactar entre ellos.
	
	Entradas: distancia entre los puntos iniciales de partida (distancia_inicial), 
            velocidad de la primera locomotora (velocidad_1) y velocidad de la
            segunda locomotora (velocidad_2).
	Salidas: distancia recorrida por la primera locomotora (distancia_1) y distancia
	         recorridad por la segunda locomotora (distancia_2).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>	

using namespace std;

int main(){	
   //Declaracion de variables	
   					      
	double distancia_inicial, velocidad_1, velocidad_2;			// Datos de entrada
	double tiempo;                                              //Variable necesaria para calcular la distancia recorrida por cada locomotora
	double distancia_1, distancia_2;		                        // Datos de salida
	
   //Entradas	
   					
	cout << "Introduzca la distancia que separa los puntos iniciales de partida (en metros): ";	
	cin >> distancia_inicial;
	cout << "Introduzca la velocidad de la primera locomotora (en metros/segundo): ";		
	cin >> velocidad_1;
	cout << "Introduzca la velocidad de la segunda locomotora (en metros/segundo): ";		
	cin >> velocidad_2;
	
	//Calculos
	
   tiempo = distancia_inicial / (velocidad_1 + velocidad_2);
   
   distancia_1 = velocidad_1 * tiempo;
   distancia_2 = velocidad_2 * tiempo;
   	
	//Salidas
	
	cout << "\nLa primera locomotora recorrio " << distancia_1 << " metros antes del impacto";
	cout << "\nLa segunda locomotora recorrio " << distancia_2 << " metros antes del impacto\n\n";
	
	system("pause");
}
