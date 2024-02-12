/*
	Ejercicio 42: Programa que recoge el acta de un partido
	              de baloncesto y muestra cual es el equipo
	              ganador (o si han quedado empate).
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

int main(){
	
	int dorsal, puntuacion, puntuacion_equipo_1 = 0, puntuacion_equipo_2 = 0;
	bool dorsal_equipo_1, dorsal_equipo_2, gana_equipo_1, gana_equipo_2, empate;
   
   /*
      Algoritmo:
      
      Introducir un dorsal y su puntuacion.
      
      Comprobar de que equipo es dicho dorsal.
      
      Sumar la puntuacion de dicho dorsal a su correspondiente equipo.
      
      Comprobar cual es el equipo ganador (o si han quedado empate)
      y mostrarlo en pantalla.
   */

   cout << " Introduzca el acta del partido (-1 para finalizar): ";
   cin >> dorsal;

   while(dorsal != -1){
   	cin >> puntuacion;

   	dorsal_equipo_1 = (dorsal == 1) || (dorsal == 2) || (dorsal == 3);
   	dorsal_equipo_2 = (dorsal == 4) || (dorsal == 5) || (dorsal == 6);
   	   	
   	if(dorsal_equipo_1)
   		puntuacion_equipo_1 += puntuacion;
   	else if (dorsal_equipo_2)
   		puntuacion_equipo_2 += puntuacion;
   		
   	cin >> dorsal;
	}
	
	gana_equipo_1 = puntuacion_equipo_1 > puntuacion_equipo_2;
	gana_equipo_2 = puntuacion_equipo_2 > puntuacion_equipo_1;
	empate = puntuacion_equipo_1 == puntuacion_equipo_2;
	
	if(gana_equipo_1)
		cout << "\n Resultado: Gana el Equipo 1" << endl << endl;
	else if(empate)
		cout << "\n Resultado: Empate entre ambos equipos" << endl << endl;
	else if (gana_equipo_2)
		cout << "\n Resultado: Gana el Equipo 2" << endl << endl;
   
   system("pause");
}
