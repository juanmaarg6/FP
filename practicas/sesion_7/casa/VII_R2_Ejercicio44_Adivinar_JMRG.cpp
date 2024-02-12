/*
	Ejercicio 44: Programa que genera un numero aleatorio
	              y el usuario intenta adivinarlos mientras
	              recibe pistas por parte del programa.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
	
	int numero_aleatorio, respuesta, intentos, numero_respuestas;
   
   /*
      Algoritmo:
      
      Generar un numero aleatorio.
      
      Hacer que el usuario introduzca el numero de intentos que
      quiere jugar.
      
      El usuario va introduciendo numeros y el programa le dice
      si esta por debajo o por encima del numero que tiene
      que adivinar.
      
      Si el usuario acierta, este ha ganado el juego
		y se detiene el programa
   */
   
   srand(time(NULL));
   numero_aleatorio = 1+ rand()%51;

   
   cout << " Se ha generado un numero aleatorio del 1 al 50. Intente adivinarlo" << endl;
   cout << " Numero de intentos: ";
   cin >> intentos;
   cout << endl;
   
   while(numero_respuestas != intentos){
   	cout << " Introduzca un numero: ";
   	cin >> respuesta;
   	
   	if(respuesta < numero_aleatorio)
   		cout << " El numero introducido esta por debajo del numero a adivinar" << endl << endl;
   	else if(respuesta > numero_aleatorio)
   	   cout << " El numero introducido esta por encima del numero a adivinar" << endl << endl;
   	else if(respuesta == numero_aleatorio){
   	   cout << " Felicidades. Has acertado." << endl;
   	   exit(-1);
   	}
   	   
   	numero_respuestas++;
   }
	
   system("pause");
}
