/*
	Relación de ejercicios 4

	Ejercicio 9: Programa que, dado una secuencia de caracteres, muestra
	             el número total de apariciones de cada letra, cuántos
	             caracteres en total se han leído (y, de ellos, cuántos
	             son letras, cuántos son separadores y cuántos son otros), 
	             cuántas letras no han aparecido ninguna vez y cuáles son y,
	             finalmente, cuáles son las letras más y menos frecuentes
	             y el número de veces que aparecen.
	              
	Entradas: Secuencia de caracteres, la cual se lee carácter a
	          carácter (caracter).
	Salidas: Número total de apariciones de cada letra (letras[].frecuencias),
	         Número total de letras leídas (total_letras),
	         Número total de separadores leídos (total_separadores),
	         Número total de "otros" caracteres leídos (total_otros),
	         Número total de caracteres leídos (total_global),
	         Número de letras que no han aparecido ninguna vez 
			 (total_no_aparecen) y qué letras son (letras_no_aparecen),
			 Número de veces que aparece la letra más frecuente 
			 (maxima_frecuencia) y qué letra es 
			 (letras[pos_letra_mas_frecuente].letra), 
			 Número de veces que aparece la letra menos frecuente 
			 (minima_frecuencia) y qué letra es 
			 (letras[pos_letra_menos_frecuente].letra).	         

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <iomanip>

using namespace std;

/****************************************************************************/
// Registro utilizado para representar una letra y su correspondiente
// frecuencia de aparición en un texto
/****************************************************************************/
struct FrecuenciaLetra {
	
	char letra;			// Letra del abecedario
	int frecuencia;		// Frecuencia de aparición de la letra
};

/****************************************************************************/
// Función principal
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
	
	// Entradas de datos y Cálculos
	
	cout << " Introduzca una serie indeterminada de caracteres.";
	cout << endl;
	cout << " Escriba libremente, con espacios y saltos de linea.";
	cout << endl;
	cout << " Puede corregir. Al pulsar ENTER la linea queda validada.";
	cout << " Para terminar escriba * ";
	cout << endl << endl;
			
	// Inicializamos el vector 'letras', de forma que la letra contenida en 
	// cada posición del vector sea 'A', 'B', 'C', ... , 'X', 'Y', 'Z', 
	// respectivamente, y cada letra tenga una frecuencia igual a 0
	for(int i = 0; i < NUM_LETRAS; i++) {
		letras[i].letra = 'A' + i;
		letras[i].frecuencia = 0;
	}
	
	int i = 0;
	
	char caracter;
	
	bool finalizar = false;

	while(!finalizar) {
		
		// Leemos un carácter
		caracter = cin.get();
		
		// Si no se finaliza la lectura de caracteres, es decir, si no
		// se lee '*':
		if(caracter != FINALIZAR) {
			
			// Incrementamos en 1 el número de caracteres leídos
			total_global++;
			
			if( isalpha(caracter) || isspace(caracter) ) {
				
				if( isalpha(caracter) ) {
					
					// Si el carácter leído es una letra, entonces 
					// incrementamos en 1 el número total de letras
					// leídas
					total_letras++;
					
					// Convertimos la letra leída a mayúsculas
					caracter = toupper(caracter);
					
					// Incrementamos en 1 la frecuencia de aparición
					// de la letra correspondiente
					for(int i = 0; i < NUM_LETRAS; i++)
						if(caracter == letras[i].letra)
							letras[i].frecuencia++;
				}
				else {
					
					// Si el carácter leído es un separador, entonces 
					// incrementamos en 1 el número total de separadores
					// leídos
					total_separadores++;	
				}
			}
			else {
				
				// Si el carácter leído no es una letra o un separador,
				// entonces incrementamos en 1 el número total de "otros" 
				// caracteres leídos
				total_otros++;
			}
		}
		else
			finalizar = true;
		
		i++;
	}
	
	// Las letras que no aparecen en la secuencia de caracteres introducida
	// serán aquellas cuya frecuencia de aparición es igual a 0 tras
	// haberse realizado la lectura de la secuencia
	for(int i = 0; i < NUM_LETRAS; i++)
		if(letras[i].frecuencia == 0) {
			letras_no_aparecen = letras_no_aparecen + " " + letras[i].letra;
			total_no_aparecen++;
	}
	
	// Cálculo de la letra menos frecuente (sin contar las letras que
	// no aparecen)
	int pos_letra_menos_frecuente = 0;
	int minima_frecuencia = letras[0].frecuencia;
	
	for(int i = 1; i <= NUM_LETRAS; i++)
		if( (letras[i].frecuencia < minima_frecuencia) && 
		    (letras[i].frecuencia != 0) ) {
		    	
			minima_frecuencia = letras[i].frecuencia;
			pos_letra_menos_frecuente = i;
		}
		
	// Cálculo de la letra más frecuente (sin contar las letras que
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
