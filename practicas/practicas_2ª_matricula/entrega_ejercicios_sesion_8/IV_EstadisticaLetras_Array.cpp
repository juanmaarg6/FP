/*
	Relaci�n de ejercicios 4

	Ejercicio 9: Programa que, dado una secuencia de caracteres, muestra
	             el n�mero total de apariciones de cada letra, cu�ntos
	             caracteres en total se han le�do (y, de ellos, cu�ntos
	             son letras, cu�ntos son separadores y cu�ntos son otros), 
	             cu�ntas letras no han aparecido ninguna vez y cu�les son y,
	             finalmente, cu�les son las letras m�s y menos frecuentes
	             y el n�mero de veces que aparecen.
	              
	Entradas: Secuencia de caracteres, la cual se lee car�cter a
	          car�cter (caracter).
	Salidas: N�mero total de apariciones de cada letra (letras[].frecuencias),
	         N�mero total de letras le�das (total_letras),
	         N�mero total de separadores le�dos (total_separadores),
	         N�mero total de "otros" caracteres le�dos (total_otros),
	         N�mero total de caracteres le�dos (total_global),
	         N�mero de letras que no han aparecido ninguna vez 
			 (total_no_aparecen) y qu� letras son (letras_no_aparecen),
			 N�mero de veces que aparece la letra m�s frecuente 
			 (maxima_frecuencia) y qu� letra es 
			 (letras[pos_letra_mas_frecuente].letra), 
			 N�mero de veces que aparece la letra menos frecuente 
			 (minima_frecuencia) y qu� letra es 
			 (letras[pos_letra_menos_frecuente].letra).	         

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <iomanip>

using namespace std;

/****************************************************************************/
// Registro utilizado para representar una letra y su correspondiente
// frecuencia de aparici�n en un texto
/****************************************************************************/
struct FrecuenciaLetra {
	
	char letra;			// Letra del abecedario
	int frecuencia;		// Frecuencia de aparici�n de la letra
};

/****************************************************************************/
// Funci�n principal
/****************************************************************************/
int main () {	
	
	// Vectores de datos	
	const int NUM_LETRAS = 27;
	FrecuenciaLetra letras[NUM_LETRAS];
	
	const char FINALIZAR = '*';
	
	int total_letras = 0;
	int total_separadores = 0;
	int total_otros = 0;
	int total_global = 0;
	int total_no_aparecen = 0;
	string letras_no_aparecen;
	
	// Entradas de datos y C�lculos
	
	cout << " Introduzca una serie indeterminada de caracteres.";
	cout << endl;
	cout << " Escriba libremente, con espacios y saltos de linea.";
	cout << endl;
	cout << " Puede corregir. Al pulsar ENTER la linea queda validada.";
	cout << " Para terminar escriba * ";
	cout << endl << endl;
			
	// Inicializamos el vector 'letras', de forma que la letra contenida en 
	// cada posici�n del vector sea 'A', 'B', 'C', ... , 'X', 'Y', 'Z', 
	// respectivamente, y cada letra tenga una frecuencia igual a 0
	for(int i = 0; i < NUM_LETRAS; i++) {
		letras[i].letra = 'A' + i;
		letras[i].frecuencia = 0;
	}
	
	int i = 0;
	
	char caracter;
	
	bool finalizar = false;

	while(!finalizar) {
		
		// Leemos un car�cter
		caracter = cin.get();
		
		// Si no se finaliza la lectura de caracteres, es decir, si no
		// se lee '*':
		if(caracter != FINALIZAR) {
			
			// Incrementamos en 1 el n�mero de caracteres le�dos
			total_global++;
			
			if( isalpha(caracter) || isspace(caracter) ) {
				
				if( isalpha(caracter) ) {
					
					// Si el car�cter le�do es una letra, entonces 
					// incrementamos en 1 el n�mero total de letras
					// le�das
					total_letras++;
					
					// Convertimos la letra le�da a may�sculas
					caracter = toupper(caracter);
					
					// Incrementamos en 1 la frecuencia de aparici�n
					// de la letra correspondiente
					for(int i = 0; i < NUM_LETRAS; i++)
						if(caracter == letras[i].letra)
							letras[i].frecuencia++;
				}
				else {
					
					// Si el car�cter le�do es un separador, entonces 
					// incrementamos en 1 el n�mero total de separadores
					// le�dos
					total_separadores++;	
				}
			}
			else {
				
				// Si el car�cter le�do no es una letra o un separador,
				// entonces incrementamos en 1 el n�mero total de "otros" 
				// caracteres le�dos
				total_otros++;
			}
		}
		else
			finalizar = true;
		
		i++;
	}
	
	// Las letras que no aparecen en la secuencia de caracteres introducida
	// ser�n aquellas cuya frecuencia de aparici�n es igual a 0 tras
	// haberse realizado la lectura de la secuencia
	for(int i = 0; i < NUM_LETRAS; i++)
		if(letras[i].frecuencia == 0) {
			letras_no_aparecen = letras_no_aparecen + " " + letras[i].letra;
			total_no_aparecen++;
	}
	
	// C�lculo de la letra menos frecuente (sin contar las letras que
	// no aparecen)
	int pos_letra_menos_frecuente = 0;
	int minima_frecuencia = letras[0].frecuencia;
	
	for(int i = 1; i <= NUM_LETRAS; i++)
		if( (letras[i].frecuencia < minima_frecuencia) && 
		    (letras[i].frecuencia != 0) ) {
		    	
			minima_frecuencia = letras[i].frecuencia;
			pos_letra_menos_frecuente = i;
		}
		
	// C�lculo de la letra m�s frecuente (sin contar las letras que
	// no aparecen)	
	int pos_letra_mas_frecuente = 0;
	int maxima_frecuencia = letras[0].frecuencia;
	
	for(int i = 1; i <= NUM_LETRAS; i++)
		if(letras[i].frecuencia > maxima_frecuencia) {
			maxima_frecuencia = letras[i].frecuencia;
			pos_letra_mas_frecuente = i;
		}
	
	// Salidas
	
	cout << endl;
	cout << " Total letras      = " << total_letras;
	cout << endl;
	cout << " Total separadores = " << total_separadores;
	cout << endl;
	cout << " Total 'otros'     = " << total_otros;
	cout << endl << endl;
	
	cout << " Total global      = " << total_global;
	cout << endl << endl;
	
	cout << " Letras que no han aparecido: " << letras_no_aparecen;
	cout << endl;
	cout << " Numero de letras no aparecidas = " << total_no_aparecen;
	cout << endl << endl;
	
	for(int i = 0; i < NUM_LETRAS; i++)		
		if(letras[i].frecuencia != 0)
			cout << " Letra " << letras[i].letra << ": " 
			     << letras[i].frecuencia << " apariciones"
				 << endl;
	
	cout << endl;			 
	cout << " Letra menos frecuente = " 
	     << letras[pos_letra_menos_frecuente].letra
		 << ".";
	cout << " Veces que aparece = " 
	     << minima_frecuencia;
	cout << endl;
	cout << " Letras mas frecuente = " 
	     << letras[pos_letra_mas_frecuente].letra
		 << ".";
	cout << " Veces que aparece = " 
	     << maxima_frecuencia;
	
	cout << endl << endl;
	
	return 0;
}
