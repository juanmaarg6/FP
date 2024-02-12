/*
	Relaci�n de ejercicios 6

	Ejercicio 9: Sobre la clase SecuenciaCaracteres implementamos el
				 algoritmo Counting Sort para ordenar sus valores.

					SecuenciaCaracteres CountingSort()

				 El m�todo no modificar� las componentes del vector privado 
				 sino que debe construir una secuencia nueva y devolverla.

				 El algoritmo funciona de la siguiente forma:
				
					1) 	Calcular los valores m�nimo y m�ximo del vector. 
					   	Por ejemplo, si el vector contiene 
					   
					   			c b b a b c c a g c b g c
					
					   	el m�nimo es 'a' y el m�ximo 'g'.
					   	
					2) 	Construir un vector local de frecuencias de todos 
					    los caracteres que hay entre el m�nimo y el m�ximo. 
						Con el ejemplo anterior, el vector de frecuencias ser�
				
									2 4 5 0 0 0 2

						que corresponden a las frecuencias de las letras que 
						hay entre 'a' y 'g'.

					3) Recorrer el vector de frecuencias almacenando cada 
					   car�cter tantas veces como indique su frecuencia 
					   (2 veces el 'a', cuatro veces el 'b', etc.)

								a a b b b b c c c c c g g

				 Para resolver este problema, debemos definir un segundo 
				 m�todo auxiliar:

					SecuenciaCaracteres CountingSortEntre(char min, char max)

				 Este m�todo s�lo ordena los valores de la secuencia que hay 
				 entre un car�cter izquierda y otro car�cter derecha. Por 
				 ejemplo, si izquierda es 'b' y derecha es 'g' el resultado 
				 ser�a la siguiente secuencia:

								b b b b c c c c c g g

				 Debemos llamar a este m�todo dentro de CountingSort().
	              
	Entradas: Secuencia de caracteres (secuencia).
	Salidas: Secuencia de caracteres ordenada mediante el algoritmo
	         Counting Sort (secuencia_ordenada).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>

using namespace std;

/***************************************************************************/
// Clase SecuenciaCaracteres: representa una secuencia de caracteres
/***************************************************************************/
class SecuenciaCaracteres {
	
	private:
		
		static const int TAMANIO = 50;   // N�mero de casillas disponibles
		char vector_privado[TAMANIO];

		// PRE: 0 <= total_utilizados <= TAMANIO
		int total_utilizados;           // N�mero de casillas ocupadas

	public:
				
		/*******************************************************************/
		// Constructor sin par�metros
		/*******************************************************************/
		SecuenciaCaracteres() : total_utilizados(0) { }
		
		/*******************************************************************/
		// Constructor a partir de un string
		// PRE: cadena.length() <= TAMANIO
		/*******************************************************************/
    	SecuenciaCaracteres(string cadena) 
		                   : total_utilizados( cadena.length() ) {
		                    	
			StringToSecuencia(cadena);
		}
		
		/*******************************************************************/
		// M�todo: TotalUtilizados()
		// Descripci�n: Devuelve el n�mero de casillas ocupadas
		// Recibe: -
		// Devuelve: N�mero de casillas ocupadas (total_utilizados)
		/*******************************************************************/
		int TotalUtilizados() {
			
			return total_utilizados;
		}
		
		/*******************************************************************/
		// M�todo: Capacidad()
		// Descripci�n: Devuelve el n�mero de casillas disponibles
		// Recibe: -
		// Devuelve: N�mero de casillas disponibles (TAMANIO)
		/*******************************************************************/
		int Capacidad() {
			
			return TAMANIO;
		}
		
		/*******************************************************************/
		// M�todo: EliminaTodos()
		// Descripci�n: "Vac�a" completamente la secuencia
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void EliminaTodos() {
			
			total_utilizados = 0;
		}
		
		/*******************************************************************/
		// M�todo: Aniade()
		// Descripci�n: A�ade un nuevo elemento al final del vector. 
		//              La adici�n se realiza si hay alguna casilla disponible.
		//              Si no la hay, no se hace nada
		// Recibe: Nuevo elemento a a�adir al final del vector (nuevo)
		// Devuelve: -
		// PRE: total_utilizados < TAMANIO
		/*******************************************************************/
		void Aniade(char nuevo) {
			
			if(total_utilizados < TAMANIO) {
				vector_privado[total_utilizados] = nuevo;
				total_utilizados++;
			}
		}
		
		/*******************************************************************/
		// M�todo: Elemento()
		// Descripci�n: Devuelve el elemento de la casilla "indice"
		// Recibe: �ndice de la casilla del elemento a devolver (indice)
		// Devuelve: Elemento almacenado en la casilla "indice"
		// PRE: 0 <= indice < total_utilizados
		/*******************************************************************/
		char Elemento(int indice) {
			
			return vector_privado[indice];
		}
		
		/*******************************************************************/
		// M�todo: Modifica()
		// Descripci�n: Cambia el contenido de la casilla "indice" por el valor
		//              dado en "nuevo". El tama�o de la secuencia no cambia
		// Recibe: �ndice de la casilla del elemento a cambiar (indice),
		//         Nuevo valor del elemento de la casilla "indice" (nuevo)
		// Devuelve: -
		// PRE: 0 <= indice < total_utilizados
		/*******************************************************************/
		void Modifica(int indice, char nuevo) {
			
			if( (indice >= 0) && (indice < total_utilizados) )
				vector_privado[indice] = nuevo;
		}
		
		/*******************************************************************/
		// M�todo: Elimina()
		// Descripci�n: Eliminar el car�cter de la posici�n dada por "indice".
		//              Realiza un borrado f�sico (desplazamiento 
		//              y sustituci�n)
		// Recibe: �ndice de la casilla del elemento a eliminar (indice)
		// Devuelve: -
		// PRE: 0 <= indice < total_utilizados
		/*******************************************************************/
		void Elimina(int indice) {
			
			if( (indice >= 0) && (indice < total_utilizados) ) {
				
				int tope = total_utilizados - 1;
				
				for(int i = indice ; i < tope ; i++) {
					vector_privado[i] = vector_privado[i+1];
					total_utilizados--;
				}
			}
		}
		
		/*******************************************************************/
		// M�todo: Inserta()
		// Descripci�n: Inserta el car�cter "nuevo" en la posici�n dada por 
		//              "indice". Desplaza todos los caracteres una posici�n 
		//              a la derecha antes de copiar en "indice" el valor 
		//              "nuevo"
		// Recibe: �ndice de la casilla del elemento a insertar (indice),
		//         Valor del elemento a insertar (nuevo)
		// Devuelve: -
		// PRE: 0 <= indice < total_utilizados
		/*******************************************************************/
		void Inserta(int indice, char nuevo) {
			
			if( (total_utilizados < TAMANIO) && (indice >= 0) && 
			     (indice < total_utilizados) ) {
		
				for(int i = total_utilizados ; i > indice ; i--)
					vector_privado[i] = vector_privado[i-1];
		
				vector_privado[indice] = nuevo;
				total_utilizados++;
			}
		}
		
		/*******************************************************************/
		// M�todo: EliminaOcurrencias()
		// Descripci�n: Elimina todas las apariciones que hay del 
		//              car�cter "a_borrar" en la secuencia
		// Recibe: Car�cter a borrar de la secuencia (a_borrar)
		// Devuelve: -
		/*******************************************************************/
		void EliminaOcurrencias(char a_borrar) {
			
		   	int posicion_escritura = 0;
			int posicion_lectura = 0;
		   	
			bool borrar = false;	
				
			int copia_total_utilizados = TotalUtilizados();
				
			while(posicion_lectura < copia_total_utilizados) {
				
				borrar = (vector_privado[posicion_lectura] == a_borrar);
	
				vector_privado[posicion_escritura] = 
				                             vector_privado[posicion_lectura];
				
				if(borrar) {	
				
					posicion_lectura++;	
					total_utilizados--;				
				}
				else{
					
					posicion_escritura++;
					posicion_lectura++;
				}
			}
		}
		
		/*******************************************************************/
		// M�todo: EliminaExcesoBlancos()
		// Descripci�n: Elimina el exceso de caracteres en blanco de la
		//              secuencia
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void EliminaExcesoBlancos() {
			
		   	int posicion_escritura = 0;
			int posicion_lectura = 0;
		   	
			bool borrar = false;	
				
			int copia_total_utilizados = TotalUtilizados();
				
			while(posicion_lectura < copia_total_utilizados-1) {
				
				borrar = (vector_privado[posicion_lectura] == ' ') &&
				         (vector_privado[posicion_lectura+1] == ' ');
	
				vector_privado[posicion_escritura] = 
				                             vector_privado[posicion_lectura];
				
				if(borrar) {	
				
					posicion_lectura++;	
					total_utilizados--;				
				}
				else{
					
					posicion_escritura++;
					posicion_lectura++;
				}
			}
			
			vector_privado[posicion_escritura] = 
                             vector_privado[posicion_lectura];
		}
		
		/*******************************************************************/
		// M�todo: InsertaSecuenciaCaracteres()
		// Descripci�n: Inserta la secuencia "otra" en la secuencia impl�cita
		//              a partir de la posici�n "pos_insercion"
		// Recibe: Posici�n donde se va a insertar la secuencia 
		//         (pos_insercion),
		//         Secuencia a insertar (otra)
		// Devuelve: Secuencia resultante tras insertar la secuencia "otra" 
		//           en la secuencia impl�cita a partir de la posici�n 
		//           "pos_insercion" (sec)
		// PRE: 0 <= pos_insercion <= total_utilizados
		/*******************************************************************/
		SecuenciaCaracteres InsertaSecuenciaCaracteres(int pos_insercion, 
		                                SecuenciaCaracteres otra) {
		    
		    SecuenciaCaracteres sec;
		    
		    if( (pos_insercion >= 0) && (pos_insercion <= total_utilizados) ) {
		    
			    sec.total_utilizados = total_utilizados + 
				                       otra.total_utilizados;
			 	
				int contador1 = 0;
			    int contador2 = 0;
			    
			    for(int i = 0; i < sec.total_utilizados; i++) {
			    			    	
					if(i < pos_insercion) {
						sec.vector_privado[i] = vector_privado[contador2];
						contador2++;
					}
						
					if( (i >= pos_insercion) && 
					    (i < pos_insercion + otra.total_utilizados) ) {
						sec.vector_privado[i] = otra.vector_privado[contador1];	
						contador1++;
					}
						
					if(i >= pos_insercion + otra.total_utilizados) {
						sec.vector_privado[i] = vector_privado[contador2];
						contador2++;
					}
			    }
			}
			
			return sec;                     	
		}
		
		/*******************************************************************/
		// M�todo: MinimoCaracter()
		// Descripci�n: Devuelve el m�nimo car�cter de una secuencia de 
		//              caracteres
		// Recibe: -
		// Devuelve: M�nimo car�cter de una secuencia de caracteres
		//           (minimo_caracter)
		/*******************************************************************/
		char MinimoCaracter() {
			
			char minimo_caracter = vector_privado[0];
			
			for(int i = 1; i < total_utilizados; i++)
				if(vector_privado[i] < minimo_caracter)
					minimo_caracter = vector_privado[i];
					
			return minimo_caracter;
		}
		
		/*******************************************************************/
		// M�todo: MaximoCaracter()
		// Descripci�n: Devuelve el m�ximo car�cter de una secuencia de 
		//              caracteres
		// Recibe: -
		// Devuelve: M�ximo car�cter de una secuencia de caracteres
		//           (maximo_caracter)
		/*******************************************************************/
		char MaximoCaracter() {
			
			char maximo_caracter = vector_privado[0];
			
			for(int i = 1; i < total_utilizados; i++)
				if(vector_privado[i] > maximo_caracter)
					maximo_caracter = vector_privado[i];
					
			return maximo_caracter;
		}
		
		/*******************************************************************/
		// M�todo: CountingSortEntre()
		// Descripci�n: Ordena aquellos valores de una secuencia que se
		//              encuentran entre "min" y "max"
		// Recibe: Rango de caracteres que se van a ordenar en la secuencia
		//         (min, max)
		// Devuelve: Secuencia cuyos valores entre "min" y "max" est�n 
		//           ordenados (subsecuencia_ordenada)
		/*******************************************************************/
		SecuenciaCaracteres CountingSortEntre(char min, char max) {
			
			SecuenciaCaracteres subsecuencia_ordenada;
			
			const int NUM_LETRAS = 'Z' - 'A' + 1;
			int frecuencias[NUM_LETRAS] = {0};
			int total_utilizados_frecuencia = 0;
			
			char caracter;
			
			while(caracter < max) {
				
				caracter = min + total_utilizados_frecuencia;
								
				for(int i = 0; i < total_utilizados; i++)
					if(vector_privado[i] == caracter)
						frecuencias[total_utilizados_frecuencia]++;
				
				total_utilizados_frecuencia++;
			}

			int contador_letras = 0;
			
			for(int i = 0; i < total_utilizados_frecuencia; i++) {
				
				int contador = 0;

				char caracter = min + contador_letras;
								
				while(contador < frecuencias[i]) {
					
					subsecuencia_ordenada.vector_privado
					[subsecuencia_ordenada.total_utilizados] = caracter;
					
					subsecuencia_ordenada.total_utilizados++;
					contador++;
				}
								
				contador_letras++;
			}
						
			return subsecuencia_ordenada;
		}
		
		/*******************************************************************/
		// M�todo: CountingSort()
		// Descripci�n: Ordena todos los valores de una secuencia
		// Recibe: -
		// Devuelve: Secuencia ordenada (secuencia_ordenada)
		/*******************************************************************/
		SecuenciaCaracteres CountingSort() {
			
			SecuenciaCaracteres secuencia_ordenada;
			
			char min_caracter = MinimoCaracter();
			char max_caracter = MaximoCaracter();
						
			secuencia_ordenada = CountingSortEntre(min_caracter, max_caracter);
							
			return secuencia_ordenada;
		}
		
		/*******************************************************************/
		// M�todo: StringToSecuencia()
		// Descripci�n: Convierte un string en una secuencia de caracteres
		// Recibe: String a convertir en una secuencia de caracteres (cadena)
		// Devuelve: -
		// PRE: cadena.length() <= TAMANIO
		/*******************************************************************/	
		void StringToSecuencia(string cadena) {
			
			total_utilizados = cadena.length();
			
			for(int i = 0; i < total_utilizados; i++)
				vector_privado[i] = cadena.at(i);
		}
		
		/*******************************************************************/
		// M�todo: ToString()
		// Descripci�n: Compone un string con todos los caracteres que est�n
		//              almacenados en la secuencia y lo devuelve.
		// Recibe: -
		// Devuelve: String con todos los car�cteres que est�n almacenados
		//           en la secuencia (cadena)
		/*******************************************************************/
		string ToString() {
			
			string cadena;
			
			cadena += "{";
			
			for(int i = 0; i < total_utilizados; i++) {
				cadena = cadena + "'" + vector_privado[i] + "'";
				
				if(i != (total_utilizados - 1) )
					cadena = cadena + ", ";
			}
		
			cadena += "}";

			return cadena;
		}
};

/***************************************************************************/
// Funci�n principal
/***************************************************************************/
int main() {
	
	// Declaraci�n de variables y objetos
	
	string cadena;

	SecuenciaCaracteres secuencia;
	
	// Entradas de datos
	
	do{
		
		cout << " Introduzca una secuencia de caracteres: ";
		getline(cin, cadena);
		
	}while(secuencia.Capacidad() < cadena.length() );
	
	secuencia.StringToSecuencia(cadena);

	// C�lculos
	
	SecuenciaCaracteres secuencia_ordenada = secuencia.CountingSort();

	// Salidas
	
	cout << endl;
	cout << " Secuencia: " 
		 << secuencia.ToString() << endl;
	cout << " Tiene " << secuencia.TotalUtilizados() << " elementos.";
	cout << endl << endl; 
	
	cout << endl;
	cout << " Secuencia ordenada: " 
		 << secuencia_ordenada.ToString() << endl;
	cout << " Tiene " << secuencia_ordenada.TotalUtilizados() << " elementos.";
	cout << endl << endl; 
	
	return 0;	
}
