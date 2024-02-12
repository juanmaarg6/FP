/*
	Relación de ejercicios 5

	Ejercicio 21: Programa que va leyendo caracteres hasta encontrar un punto
                  '.'. Luego muestra las letras mayúsculas que aparecen en
				  la secuencia de caracteres y el número de veces que aparece 
				  cada mayúscula.
	              
	Entradas: Secuencia de caracteres, la cual se lee carácter a
	          carácter (caracter).
	Salidas: Número de apariciones de cada mayúscula en la secuencia
	         de caracteres.

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>

using namespace std;

/***************************************************************************/
// Clase ContadorMayusculas: permite contar las mayúsculas de una secuencia
//                           de caracteres
/***************************************************************************/
class ContadorMayusculas {

	private:
	
		static const int MAX_LETRAS = 26;	// No incluimos la letra 'Ñ'
		
		int apariciones[MAX_LETRAS]; // Número de apariciones de cada mayúscula
		                             // en la secuencia de caracteres
		char mayusculas[MAX_LETRAS]; // Mayúsculas que aparecen en la
		                             // secuencia de caracteres
		                                    
		// PRE: 0 <= total_utilizados <= MAX_LETRAS
		int total_utilizados;		 // Número total de mayúsculas que
		                             // aparecen en el texto
	
	public:
	
		static const char LETRA_A;	// Letra mayúscula 'A'
		static const char LETRA_Z;  // Letra mayúscula 'Z'
		
		/*******************************************************************/
		// Constructor sin parámetros
		/*******************************************************************/
		ContadorMayusculas() : apariciones{0}, total_utilizados(0) { }
		
		/*******************************************************************/
		// Método: IncrementaCuenta()
		// Descripción: Aumenta en 1 el número de apariciones de una
		//              letra mayúscula dada
		// Recibe: Letra mayúscula (mayuscula)
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
		// Método: CuantasHay()
		// Descripción: Muestra el número de apariciones de una letra mayúscula
		//              dada
		// Recibe: Letra mayúscula (mayuscula)
		// Devuelve: -
		// PRE: LETRA_A <= mayuscula <= LETRA_Z
		/*******************************************************************/
		int CuantasHay(char mayuscula) {
			
	    	return(apariciones[mayuscula - LETRA_A]);
		}
	
		/*******************************************************************/
		// Método: ToString()
		// Descripción: Compone un string con todas las mayúsculas encontradas
		//              en la secuencia de caracteres introducida junto a sus
		//              respectivas apariciones
		// Recibe: -
		// Devuelve: String con todas las mayúsculas encontradas en la 
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
// Función: EsMayuscula()
// Descripción: Comprueba si un carácter es una letra mayúscula
// Recibe: Carácter a comprobar si es una letra mayúscula (caracter)
// Devuelve: True (1) si "caracter" es una letra mayúscula y False (0) 
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
// Función principal
/***************************************************************************/
int main() {
    
	//Declaración de constantes
	
	const char FINALIZAR = '.';
	
	//Declaración de objetos
	
	ContadorMayusculas mayusculas;

	// Entradas de datos y Cálculos
	
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
		
		// Leemos el siguiente carácter
		caracter = cin.get();
        
        // Comprobamos si el carácter leído es '.'
        // En tal caso, finalizamos la lectura
		finalizar = (caracter == FINALIZAR);
	}
	
	// Salidas
	
	cout << mayusculas.ToString();
	cout << endl << endl;
	
	return 0;
}
