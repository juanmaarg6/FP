/*
	Relaci�n de ejercicios 5

	Ejercicio 21: Programa que va leyendo caracteres hasta encontrar un punto
                  '.'. Luego muestra las letras may�sculas que aparecen en
				  la secuencia de caracteres y el n�mero de veces que aparece 
				  cada may�scula.
	              
	Entradas: Secuencia de caracteres, la cual se lee car�cter a
	          car�cter (caracter).
	Salidas: N�mero de apariciones de cada may�scula en la secuencia
	         de caracteres.

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>

using namespace std;

/***************************************************************************/
// Clase ContadorMayusculas: permite contar las may�sculas de una secuencia
//                           de caracteres
/***************************************************************************/
class ContadorMayusculas {

	private:
	
		static const int MAX_LETRAS = 26;	// No incluimos la letra '�'
		
		int apariciones[MAX_LETRAS]; // N�mero de apariciones de cada may�scula
		                             // en la secuencia de caracteres
		char mayusculas[MAX_LETRAS]; // May�sculas que aparecen en la
		                             // secuencia de caracteres
		                                    
		// PRE: 0 <= total_utilizados <= MAX_LETRAS
		int total_utilizados;		 // N�mero total de may�sculas que
		                             // aparecen en el texto
	
	public:
	
		static const char LETRA_A;	// Letra may�scula 'A'
		static const char LETRA_Z;  // Letra may�scula 'Z'
		
		/*******************************************************************/
		// Constructor sin par�metros
		/*******************************************************************/
		ContadorMayusculas() : apariciones{0}, total_utilizados(0) { }
		
		/*******************************************************************/
		// M�todo: IncrementaCuenta()
		// Descripci�n: Aumenta en 1 el n�mero de apariciones de una
		//              letra may�scula dada
		// Recibe: Letra may�scula (mayuscula)
		// Devuelve: -
		// PRE: LETRA_A <= mayuscula <= LETRA_Z
		/*******************************************************************/
		void IncrementaCuenta(char mayuscula) {
			
			if( (mayuscula >= LETRA_A) && (mayuscula <= LETRA_Z) ) {
				
				apariciones[mayuscula - LETRA_A] += 1;
	   		    
	   		    if(apariciones[mayuscula - LETRA_A] == 1) {
	   		    	mayusculas[total_utilizados] = mayuscula;
	   		    	total_utilizados++;
	            }
			}	    
		}
		
		/*******************************************************************/
		// M�todo: CuantasHay()
		// Descripci�n: Muestra el n�mero de apariciones de una letra may�scula
		//              dada
		// Recibe: Letra may�scula (mayuscula)
		// Devuelve: -
		// PRE: LETRA_A <= mayuscula <= LETRA_Z
		/*******************************************************************/
		int CuantasHay(char mayuscula) {
			
	    	return(apariciones[mayuscula - LETRA_A]);
		}
	
		/*******************************************************************/
		// M�todo: ToString()
		// Descripci�n: Compone un string con todas las may�sculas encontradas
		//              en la secuencia de caracteres introducida junto a sus
		//              respectivas apariciones
		// Recibe: -
		// Devuelve: String con todas las may�sculas encontradas en la 
		//           secuencia de caracteres introducida junto a sus
		//           respectivas apariciones (cadena)
		/*******************************************************************/
		string ToString() {
			
			string cadena;
			
			for(int i = 0; i < total_utilizados; i++)
			    cadena = cadena + "\n" + " Letra " + mayusculas[i]
				         + ": " + to_string( CuantasHay( mayusculas[i] ) ) 
						 + " apariciones";
			
			return cadena;
		}
};

const char ContadorMayusculas::LETRA_A = 'A';
const char ContadorMayusculas::LETRA_Z = 'Z';

/*******************************************************************/
// Funci�n: EsMayuscula()
// Descripci�n: Comprueba si un car�cter es una letra may�scula
// Recibe: Car�cter a comprobar si es una letra may�scula (caracter)
// Devuelve: True (1) si "caracter" es una letra may�scula y False (0) 
//           si no lo es
/*******************************************************************/
bool EsMayuscula(char caracter) {
	
	const char MAYUSCULA_A = 'A';
	const char MAYUSCULA_Z = 'Z';
	
	bool es_mayuscula = ( (caracter >= MAYUSCULA_A) && 
	                      (caracter <= MAYUSCULA_Z) );
	
	return es_mayuscula;
}

/***************************************************************************/
// Funci�n principal
/***************************************************************************/
int main() {
    
	//Declaraci�n de constantes
	
	const char FINALIZAR = '.';
	
	//Declaraci�n de objetos
	
	ContadorMayusculas mayusculas;

	// Entradas de datos y C�lculos
	
	cout << " Introduzca una serie indeterminada de caracteres.";
	cout << endl;
	cout << " Escriba libremente, con espacios y saltos de linea.";
	cout << endl;
	cout << " Puede corregir. Al pulsar ENTER la linea queda validada.";
	cout << " Para terminar escriba . ";
	cout << endl << endl;
		
	char caracter;	
	
	bool finalizar = false;
	
	// Lectura adelantada
	
	caracter = cin.get();

	while(!finalizar) {
		
		if(!finalizar)
			if( EsMayuscula(caracter) )
		    	mayusculas.IncrementaCuenta(caracter);
		
		// Leemos el siguiente car�cter
		caracter = cin.get();
        
        // Comprobamos si el car�cter le�do es '.'
        // En tal caso, finalizamos la lectura
		finalizar = (caracter == FINALIZAR);
	}
	
	// Salidas
	
	cout << mayusculas.ToString();
	cout << endl << endl;
	
	return 0;
}
