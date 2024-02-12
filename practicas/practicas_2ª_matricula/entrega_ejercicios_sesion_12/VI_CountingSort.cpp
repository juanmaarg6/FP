/*
	Relación de ejercicios 6

	Ejercicio 9: Sobre la clase SecuenciaCaracteres implementamos el
				 algoritmo Counting Sort para ordenar sus valores.

					SecuenciaCaracteres CountingSort()

				 El método no modificará las componentes del vector privado 
				 sino que debe construir una secuencia nueva y devolverla.

				 El algoritmo funciona de la siguiente forma:
				
					1) 	Calcular los valores mínimo y máximo del vector. 
					   	Por ejemplo, si el vector contiene 
					   
					   			c b b a b c c a g c b g c
					
					   	el mínimo es 'a' y el máximo 'g'.
					   	
					2) 	Construir un vector local de frecuencias de todos 
					    los caracteres que hay entre el mínimo y el máximo. 
						Con el ejemplo anterior, el vector de frecuencias será
				
									2 4 5 0 0 0 2

						que corresponden a las frecuencias de las letras que 
						hay entre 'a' y 'g'.

					3) Recorrer el vector de frecuencias almacenando cada 
					   carácter tantas veces como indique su frecuencia 
					   (2 veces el 'a', cuatro veces el 'b', etc.)

								a a b b b b c c c c c g g

				 Para resolver este problema, debemos definir un segundo 
				 método auxiliar:

					SecuenciaCaracteres CountingSortEntre(char min, char max)

				 Este método sólo ordena los valores de la secuencia que hay 
				 entre un carácter izquierda y otro carácter derecha. Por 
				 ejemplo, si izquierda es 'b' y derecha es 'g' el resultado 
				 sería la siguiente secuencia:

								b b b b c c c c c g g

				 Debemos llamar a este método dentro de CountingSort().
	              
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
		
		static const int TAMANIO = 50;   // Número de casillas disponibles
		char vector_privado[TAMANIO];

		// PRE: 0 <= total_utilizados <= TAMANIO
		int total_utilizados;           // Número de casillas ocupadas

	public:
				
		/*******************************************************************/
		// Constructor sin parámetros
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
		// Método: TotalUtilizados()
		// Descripción: Devuelve el número de casillas ocupadas
		// Recibe: -
		// Devuelve: Número de casillas ocupadas (total_utilizados)
		/*******************************************************************/
		int TotalUtilizados() {
			
			return total_utilizados;
		}
		
		/*******************************************************************/
		// Método: Capacidad()
		// Descripción: Devuelve el número de casillas disponibles
		// Recibe: -
		// Devuelve: Número de casillas disponibles (TAMANIO)
		/*******************************************************************/
		int Capacidad() {
			
			return TAMANIO;
		}
		
		/*******************************************************************/
		// Método: EliminaTodos()
		// Descripción: "Vacía" completamente la secuencia
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void EliminaTodos() {
			
			total_utilizados = 0;
		}
		
		/*******************************************************************/
		// Método: Aniade()
		// Descripción: Añade un nuevo elemento al final del vector. 
		//              La adición se realiza si hay alguna casilla disponible.
		//              Si no la hay, no se hace nada
		// Recibe: Nuevo elemento a añadir al final del vector (nuevo)
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
		// Método: Elemento()
		// Descripción: Devuelve el elemento de la casilla "indice"
		// Recibe: Índice de la casilla del elemento a devolver (indice)
		// Devuelve: Elemento almacenado en la casilla "indice"
		// PRE: 0 <= indice < total_utilizados
		/*******************************************************************/
		char Elemento(int indice) {
			
			return vector_privado[indice];
		}
		
		/*******************************************************************/
		// Método: Modifica()
		// Descripción: Cambia el contenido de la casilla "indice" por el valor
		//              dado en "nuevo". El tamaño de la secuencia no cambia
		// Recibe: Índice de la casilla del elemento a cambiar (indice),
		//         Nuevo valor del elemento de la casilla "indice" (nuevo)
		// Devuelve: -
		// PRE: 0 <= indice < total_utilizados
		/*******************************************************************/
		void Modifica(int indice, char nuevo) {
			
			if( (indice >= 0) && (indice < total_utilizados) )
				vector_privado[indice] = nuevo;
		}
		
		/*******************************************************************/
		// Método: Elimina()
		// Descripción: Eliminar el carácter de la posición dada por "indice".
		//              Realiza un borrado físico (desplazamiento 
		//              y sustitución)
		// Recibe: Índice de la casilla del elemento a eliminar (indice)
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
		// Método: Inserta()
		// Descripción: Inserta el carácter "nuevo" en la posición dada por 
		//              "indice". Desplaza todos los caracteres una posición 
		//              a la derecha antes de copiar en "indice" el valor 
		//              "nuevo"
		// Recibe: Índice de la casilla del elemento a insertar (indice),
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
		// Método: EliminaOcurrencias()
		// Descripción: Elimina todas las apariciones que hay del 
		//              carácter "a_borrar" en la secuencia
		// Recibe: Carácter a borrar de la secuencia (a_borrar)
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
		// Método: EliminaExcesoBlancos()
		// Descripción: Elimina el exceso de caracteres en blanco de la
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
		// Método: InsertaSecuenciaCaracteres()
		// Descripción: Inserta la secuencia "otra" en la secuencia implícita
		//              a partir de la posición "pos_insercion"
		// Recibe: Posición donde se va a insertar la secuencia 
		//         (pos_insercion),
		//         Secuencia a insertar (otra)
		// Devuelve: Secuencia resultante tras insertar la secuencia "otra" 
		//           en la secuencia implícita a partir de la posición 
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
		// Método: MinimoCaracter()
		// Descripción: Devuelve el mínimo carácter de una secuencia de 
		//              caracteres
		// Recibe: -
		// Devuelve: Mínimo carácter de una secuencia de caracteres
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
		// Método: MaximoCaracter()
		// Descripción: Devuelve el máximo carácter de una secuencia de 
		//              caracteres
		// Recibe: -
		// Devuelve: Máximo carácter de una secuencia de caracteres
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
		// Método: CountingSortEntre()
		// Descripción: Ordena aquellos valores de una secuencia que se
		//              encuentran entre "min" y "max"
		// Recibe: Rango de caracteres que se van a ordenar en la secuencia
		//         (min, max)
		// Devuelve: Secuencia cuyos valores entre "min" y "max" están 
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
		// Método: CountingSort()
		// Descripción: Ordena todos los valores de una secuencia
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
		// Método: StringToSecuencia()
		// Descripción: Convierte un string en una secuencia de caracteres
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
		// Método: ToString()
		// Descripción: Compone un string con todos los caracteres que están
		//              almacenados en la secuencia y lo devuelve.
		// Recibe: -
		// Devuelve: String con todos los carácteres que están almacenados
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
// Función principal
/***************************************************************************/
int main() {
	
	// Declaración de variables y objetos
	
	string cadena;

	SecuenciaCaracteres secuencia;
	
	// Entradas de datos
	
	do{
		
		cout << " Introduzca una secuencia de caracteres: ";
		getline(cin, cadena);
		
	}while(secuencia.Capacidad() < cadena.length() );
	
	secuencia.StringToSecuencia(cadena);

	// Cálculos
	
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
