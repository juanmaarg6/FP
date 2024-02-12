/*
	Relaci�n de ejercicios 3

	Ejercicio 22: Programa que, generado un n�mero aleatorio entre el 1 y
				  el 10, el usuario intenta adivinar el n�mero (el juego
				  da pistas al jugador de si el n�mero introducido por el 
				  jugador es menor o mayor que el n�mero a adivinar).
				  
				  Las reglas de parada son:
				  
				  	a) El jugador adivina el n�mero.
				  	b) El jugador decide abandonar (para ello, el usuario 
					   escribir� el n�mero 0).
	              
	              Una vez parado el juego, el programa le preguntar� al 
				  usuario si desea jugar otra partida o no.
				  
	Entradas: N�mero introducido por el jugador (respuesta).
	Salidas: Si el jugador ha acertado o no y, en caso de acertar, el n�mero
	         de intentos que ha realizado (numero_jugadas).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusi�n de los recursos de E/S
#include <time.h>
#include <stdlib.h>

using namespace std;

// Declaraci�n de constantes globales

const int MIN = 1;
const int MAX = 10;

const int NUM_VALORES = MAX - MIN + 1;
	
/***************************************************************************/
// Funci�n: GenerarNumeroAleatorio
// Recibe: Valor m�nimo del rango de n�meros (MIN),
//		   N�mero de valores posibles del ran (NUM_VALORES).
// Devuelve: N�mero aleatorio generado.
/***************************************************************************/
int GenerarNumeroAleatorio(int MIN, int NUM_VALORES) {
	
	int numero_aleatorio;
	
	time_t t;
	srand(time(&t));
	
	numero_aleatorio = (rand() % NUM_VALORES) + MIN;	
			
	return numero_aleatorio;	
}

/***************************************************************************/
// Funci�n: LeerRespuesta
// Recibe: Texto que etiqueta la lectura (msg).
// Devuelve: N�mero entero introducido por el usuario.
/***************************************************************************/
int LeerRespuesta(string msg) {		
	
	int respuesta;
	
	do {
		cout << msg;
		cin >> respuesta;
	}while( ( (respuesta < MIN) && (respuesta != 0) ) || respuesta > MAX);
	
	return respuesta;
}

/***************************************************************************/
// Funci�n: MostrarPista
// Recibe: Texto que etiqueta la lectura (msg).
// Devuelve: -
/***************************************************************************/
void MostrarPista(int respuesta, int numero_aleatorio) {
	
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
			   		
/***************************************************************************/
// Funci�n: LeeOpcion2Alternativas
// Recibe: Texto que etiqueta la lectura (msg).
// Devuelve: True (1) si se desea jugar otra vez y False (0) si no.
/***************************************************************************/
bool LeeOpcion2Alternativas(string msg) {
	
	bool jugar_otra_vez;
	char caracter;
	
	do {
		cout << msg;
		cin >> caracter;
	}while( (caracter != 'S') && (caracter != 's') &&
			(caracter != 'N') && (caracter != 'n') );
		
	caracter = toupper(caracter);
			
	if(caracter == 'S')
		jugar_otra_vez = true;
	if(caracter == 'N')
		jugar_otra_vez = false;	
	
	cout << endl;	
			
	return jugar_otra_vez;	
}

/***************************************************************************/
// Funci�n principal
/***************************************************************************/
int main() {

	// Declaraci�n de variables
	
	int numero_aleatorio;
	int respuesta;
	
	// Entradas de datos
		
	cout << " Se ha generado un numero aleatorio del 1 al 10."
	     << " Intente adivinarlo.";
	cout << endl << endl;
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Generar un n�mero aleatorio.
		
		Mientras el jugador no acierte el n�mero y no abandone el juego, o
		juegue otra vez:
		
			Si juega otra vez, se genera un nuevo n�mero aleatorio y se 
			reinicia 'numero_jugadas' a 0.
		
			El jugador introduce un n�mero.
			
			Si el jugador no abandona el juego:
			
				Si el n�mero introducido por el jugador es menor que el
				n�mero que tiene que adivinar, se le da una pista por
				pantalla.
				
				Si el n�mero introducido por el jugador es mayor que el
				n�mero que tiene que adivinar, se le da una pista por
				pantalla.
			
			'numero_jugadas' se incrementa en 1.
						
			Si el n�mero introducido por el jugador es igual que el
			n�mero que tiene que adivinar, se termina el juego y se
			muestra el n�mero de jugadas totales.
			
			Si el jugador decide abandonar, se termina el juego y se muestra el 
			n�mero que ten�a que adivinar y	n�mero de jugadas que llevaba.
			
			Si el jugador acierta el n�mero o abandona, se le pregunta si
			desea volver a jugar otra vez:
			
				Si el car�cter introducido por el jugador es 's' o 'S',
			    juega otra vez.
				Si el car�cter introducido por el jugador es 'n' o 'N',
				no juega otra partida.
	*/
	
	numero_aleatorio = GenerarNumeroAleatorio(MIN, NUM_VALORES);
	
	int numero_jugadas = 0;
	
	bool numero_adivinado = false;
	bool finalizar_juego = false;
	bool jugar_otra_vez = false;
		
	while( ( !(numero_adivinado) && !(finalizar_juego) ) || jugar_otra_vez ) {
		
		if(jugar_otra_vez) {
			numero_aleatorio = GenerarNumeroAleatorio(MIN, NUM_VALORES);
			numero_jugadas = 0;
		}
		
		jugar_otra_vez = false;
		
		respuesta = LeerRespuesta
		           (" Introduzca un numero entre 1 y 10 (0 para finalizar): ");
		
		numero_adivinado = (respuesta == numero_aleatorio);
		finalizar_juego = (respuesta == 0);
		
		if( !(finalizar_juego) )
			MostrarPista(respuesta, numero_aleatorio);
			
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
		
		if(numero_adivinado || finalizar_juego)
			jugar_otra_vez = LeeOpcion2Alternativas
			                 (" Desea volver a jugar? (S/N): ");
	}
	
	return 0;
}
