/*
	Relaci�n de ejercicios 5

	Ejercicio 30: Programa que, dada una secuencia de caracteres y un caracter,
	              muestra la secuencia de caracteres tras eliminar de ella las 
	              apariciones del caracter introducido
	              
	Entradas: Secuencia de caracteres (secuencia).
	Salidas: Secuencia de caracteres sin las apariciones del caracter
	         introducido (copia_secuencia).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <string>

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
		//         Valor del elemento a insertar (valor_nuevo)
		// Devuelve: -
		// PRE: 0 <= indice < total_utilizados
		/*******************************************************************/
		void Inserta(int indice, char valor_nuevo) {
			
			if( (total_utilizados < TAMANIO) && (indice >= 0) && 
			     (indice < total_utilizados) ) {
		
				for(int i = total_utilizados ; i > indice ; i--)
					vector_privado[i] = vector_privado[i-1];
		
				vector_privado[indice] = valor_nuevo;
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
		
	// Introducir un string "cadena y convertirlo a una secuencia de caracteres
	// "sec"
	
	do{
		
		cout << " Introduzca una secuencia de caracteres: ";
		getline(cin, cadena);
		
	}while(secuencia.Capacidad() < cadena.length() );
	
	secuencia.StringToSecuencia(cadena);
	
	// Introducir el car�cter a borrar de la secuencia
	
	char letra_a_borrar;
	cout << " Introduzca el caracter a eliminar de la secuencia: ";
	cin >> letra_a_borrar;
	
	// Mostrar el contenido de la secuencia original

	cout << endl;
	cout << " Secuencia original: " << secuencia.ToString() << endl;
	cout << " Tiene " << secuencia.TotalUtilizados() << " elementos.";
	cout << endl << endl;
	
	// Copiar la secuencia original en "copia"
	
	SecuenciaCaracteres copia_secuencia; 
	
	int tope = secuencia.TotalUtilizados();
	for(int i = 0; i < tope; i++)
		copia_secuencia.Aniade( secuencia.Elemento(i) );
	
	// Eliminar el caracter "letra_a_borrar" de "copia"
	
	copia_secuencia.EliminaOcurrencias(letra_a_borrar);
	
	// Mostrar el contenido de la secuencia modificada

	cout << endl;
	cout << " Secuencia modificada (tras eliminar todas las apariciones del"
	     << " caracter " << letra_a_borrar << "): " 
		 << copia_secuencia.ToString() << endl;
	cout << " Tiene " << copia_secuencia.TotalUtilizados() << " elementos.";
	cout << endl << endl; 
		
	return 0;	
}
