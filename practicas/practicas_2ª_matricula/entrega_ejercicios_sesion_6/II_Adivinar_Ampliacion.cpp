/*
	Relación de ejercicios 2

	Ejercicio 55: Programa que, generado un número aleatorio entre el 1 y
				  el 10, el usuario intenta adivinar el número (el juego
				  da pistas al jugador de si el número introducido por el 
				  jugador es menor o mayor que el número a adivinar).
				  
				  Las reglas de parada son:
				  
				  	a) El jugador adivina el número.
				  	b) El jugador decide abandonar (para ello, el usuario 
					   escribirá el número 0).
	              
	              Una vez parado el juego, el programa le preguntará al 
				  usuario si desea jugar otra partida o no.
				  
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
	
	int numero_aleatorio;
	int respuesta;
	
	// Entradas de datos
		
	cout << " Se ha generado un numero aleatorio del 1 al 10."
	     << " Intente adivinarlo.";
	cout << endl << endl;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Generar un número aleatorio.
		
		Mientras el jugador no acierte el número y no abandone el juego, o
		juegue otra vez:
		
			Si juega otra vez, se genera un nuevo número aleatorio y se 
			reinicia 'numero_jugadas' a 0.
		
			El jugador introduce un número.
			
			Si el jugador no abandona el juego:
			
				Si el número introducido por el jugador es menor que el
				número que tiene que adivinar, se le da una pista por
				pantalla.
				
				Si el número introducido por el jugador es mayor que el
				número que tiene que adivinar, se le da una pista por
				pantalla.
			
			'numero_jugadas' se incrementa en 1.
						
			Si el número introducido por el jugador es igual que el
			número que tiene que adivinar, se termina el juego y se
			muestra el número de jugadas totales.
			
			Si el jugador decide abandonar, se termina el juego y se muestra el 
			número que tenía que adivinar y	número de jugadas que llevaba.
			
			Si el jugador acierta el número o abandona, se le pregunta si
			desea volver a jugar otra vez:
			
				Si el carácter introducido por el jugador es 's' o 'S',
			    juega otra vez.
				Si el carácter introducido por el jugador es 'n' o 'N',
				no juega otra partida.
	*/
	
	numero_aleatorio = (rand() % NUM_VALORES) + MIN;
	
	int numero_jugadas = 0;
	
	bool numero_adivinado = false;
	bool finalizar_juego = false;
	bool jugar_otra_vez = false;
	
	char caracter;
	
	while( ( !(numero_adivinado) && !(finalizar_juego) ) || jugar_otra_vez ) {
		
		if(jugar_otra_vez) {
			numero_aleatorio = (rand() % NUM_VALORES) + MIN;
			numero_jugadas = 0;
		}
		
		jugar_otra_vez = false;
		
		do {
			cout << " Introduzca un numero entre 1 y 10 (0 para finalizar): ";
			cin >> respuesta;
		}while( ( (respuesta < MIN) && (respuesta != 0) ) || respuesta > MAX);
		
		numero_adivinado = (respuesta == numero_aleatorio);
		finalizar_juego = (respuesta == 0);
		
		if( !(finalizar_juego) ) {
			
			if(respuesta < numero_aleatorio) {
				
				cout << endl;
	   			cout << "\t El numero es mayor que " << respuesta;
	   			cout << endl << endl;
	   		}
	   		
			if(respuesta > numero_aleatorio) {
				
				cout << endl;
	   	    	cout << "\t El numero es menor que " << respuesta;
	   	    	cout << endl << endl;
	   	    }
		}
		
		numero_jugadas++;
		
		// Salidas
		
		if(numero_adivinado){
	   					
			cout << endl << endl;
   	    	cout << " Has acertado. El numero buscado era "
			     << numero_aleatorio << ".";
			cout << endl;
			cout << " Has jugado " << numero_jugadas << " jugadas.";     
			cout << endl << endl;
		}
		
		if(finalizar_juego) {
			
			cout << endl << endl;
   	    	cout << " Has abandonado. El numero buscado era "
			     << numero_aleatorio << ".";
			cout << endl;
			cout << " Has jugado " << numero_jugadas << " jugadas.";     
			cout << endl << endl;
		}
		
		if(numero_adivinado || finalizar_juego) {
			
			do {
				cout << " Desea volver a jugar? (S/N): ";
				cin >> caracter;
			}while( (caracter != 'S') && (caracter != 's') &&
			       (caracter != 'N') && (caracter != 'n') );
		
			caracter = toupper(caracter);
			
			if(caracter == 'S')
				jugar_otra_vez = true;
			if(caracter == 'N')
				jugar_otra_vez = false;	
			
			cout << endl;	
		}
	}
	
	return 0;
}
