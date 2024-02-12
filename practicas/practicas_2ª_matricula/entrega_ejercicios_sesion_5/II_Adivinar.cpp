/*
	Relación de ejercicios 2

	Ejercicio 49: Programa que, generado un número aleatorio entre el 1 y
				  el 10, el usuario intenta adivinar el número (el juego
				  da pistas al jugador de si el número introducido por el 
				  jugador es menor o mayor que el número a adivinar).
				  
				  Las reglas de parada son:
				  
				  	a) El jugador adivina el número.
				  	b) El jugador decide abandonar (para ello, el usuario 
					   escribirá el número 0).
	              
	Entradas: Número introducido por el jugador (respuesta).
	Salidas: Si el jugador ha acertado o no y, en caso de acertar, el número
	         de intentos que ha realizado (numero_jugadas).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de los recursos de E/S
#include <time.h>
#include <stdlib.h>

using namespace std;

// Programa principal

int main() {
	
	// Declaración de constantes
	
	const int MIN = 1;
	const int MAX = 10;
	
	const int NUM_VALORES = MAX - MIN + 1;

	// Declaración de variables
	
	time_t t;
	srand(time(&t));
	
	int numero_aleatorio = 0;
	int respuesta = 0;
	
	// Entradas de datos
		
	cout << " Se ha generado un numero aleatorio del 1 al 10."
	     << " Intente adivinarlo.";
	cout << endl << endl;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Generar un número aleatorio.
		
		Mientras el jugador no acierte el número o no abandone el juego:
		
			El jugador introduce un número.
			
			Si el jugador no ha abandonado el juego:
			
				Si el número introducido por el jugador es menor que el
				número que tiene que adivinar, se le da una pista por
				pantalla y 'numero_jugadas' se incrementa en 1.
				
				Si el número introducido por el jugador es mayor que el
				número que tiene que adivinar, se le da una pista por
				pantalla y 'numero_jugadas' se incrementa en 1.
				
				Si el número introducido por el jugador es igual que el
				número que tiene que adivinar, se termina el juego y se
				muestra el número de jugadas totales.
				
			Si no, se termina el juego y se muestra el número de jugadas
			que llevaba el jugador.
	*/
	
	numero_aleatorio = (rand() % NUM_VALORES) + MIN;
	
	int numero_jugadas = 1;
	bool no_acertado = true;
	bool no_finalizar = true;
	
	while(no_acertado && no_finalizar) {
		
		cout << " Introduzca un numero entre 1 y 10 (0 para finalizar): ";
		cin >> respuesta;
		
		no_acertado = (respuesta != numero_aleatorio);
		no_finalizar = (respuesta != 0);
		
		if(no_finalizar) {
			
			if(respuesta < numero_aleatorio) {
				
				cout << endl;
	   			cout << "\t El numero es mayor que " << respuesta;
	   			cout << endl << endl;
	   			numero_jugadas++;
	   		}
	   		
			if(respuesta > numero_aleatorio) {
				
				cout << endl;
	   	    	cout << "\t El numero es menor que " << respuesta;
	   	    	cout << endl << endl;
	   			numero_jugadas++;
	   	    }
	   	
		   	if(respuesta == numero_aleatorio){
		   		
				// Salidas
				
				cout << endl << endl;
	   	    	cout << " Has acertado. El numero buscado era "
				     << numero_aleatorio << ".";
				cout << endl;
				cout << " Has jugado " << numero_jugadas << " jugadas.";     
				cout << endl << endl;
			}
		}
		else {
			
			// Salidas
			
			cout << endl << endl;
   	    	cout << " Has abandonado. El numero buscado era "
			     << numero_aleatorio << ".";
			cout << endl;
			cout << " Has jugado " << numero_jugadas << " jugadas.";     
			cout << endl << endl;	
		}
	}
	
	return 0;
}
