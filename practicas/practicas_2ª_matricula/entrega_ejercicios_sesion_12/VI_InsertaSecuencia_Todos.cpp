/*
	Relaci�n de ejercicios 6

	Ejercicios 6, 7 y 8: 
	
		Ejercicio 6: Sobre la clase SecuenciaCaracteres, definimos un m�todo 
		             que inserta otra secuencia (otra) a partir de una posici�n 
					 (pos_insercion).
						
						void InsertaSecuenciaCaracteres(int pos_insercion,
													SecuenciaCaracteres otra)

					 Implementamos este m�todo utilizando un m�todo que inserta 
					 un �nico car�cter:
						
						void Inserta(int pos_insercion, char valor_nuevo)

					 Insertamos el car�cter valor_nuevo en la posici�n 
					 "pos_insercion". Tras la inserci�n, "valor_nuevo" ocupar� 
					 la posici�n "pos_insercion".

					 Tendremos que llamar a este m�todo para insertar, uno a 
					 uno, todos los caracteres de la secuencia "otra".
					 
		Ejercicio 7: Implementamos el m�todo del ejercicio 6 de una forma 
		             eficiente, sin tener que llamar al m�todo de inserci�n 
					 de un car�cter por cada car�cter que se vaya a insertar.
	              
	    Ejercicio 8: Modificamos el m�todo del ejercicio 7 de manera que ahora 
		             devuelve una nueva secuencia. La secuencia original 
					 (la impl�cita) y la secuencia "otra" no se modifican.
					 
	Entradas: Dos secuencias de caracteres (secuencia1, secuencia2),
	          Posici�n de "secuencia1" (pos_insercion)
	Salidas: Resultado de insertar "secuencia2" en "secuencia1" a partir
	         de "pos_insercion" (secuencia_insercion)

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>

using namespace std;

/***************************************************************************/
// Clase ManipuladorString: permite modificar un string
/***************************************************************************/
class ManipuladorString {
	
	private:
		
		string cadena;		// Cadena que queremos manipular
		
	public:
		
		/*******************************************************************/
		// Constructor sin par�metros
		/*******************************************************************/
		ManipuladorString() {
			
			cadena = "";
		}
		
		/*******************************************************************/
		// Constructor con par�metros
		/*******************************************************************/
		ManipuladorString(string la_cadena) : cadena(la_cadena) { }
		
		/*******************************************************************/
		// M�todo: SetCadena()
		// Descripci�n: Establece el texto que va a almacenar "cadena"
		// Recibe: Texto que va a almacenar "cadena" (la_cadena)
		// Devuelve: -
		/*******************************************************************/
		void SetCadena(string la_cadena) {
			
			cadena = la_cadena;	
		}
		
		/*******************************************************************/
		// M�todo: GetCadena()
		// Descripci�n: Devuelve el texto almacenado en "cadena"
		// Recibe: -
		// Devuelve: Texto almacenado en "cadena" (cadena)
		/*******************************************************************/
		string GetCadena() {
			
			return cadena;	
		}

		/*******************************************************************/
		// M�todo: EliminaPrimerosSeparadores()
		// Descripci�n: Elimina los caracteres separadores iniciales 
		//              de "cadena"
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void EliminaPrimerosSeparadores() {	
		
			int pos = 0;
			
			int longitud_cadena = cadena.length();
			
			while( ( pos < longitud_cadena ) && ( isspace(cadena.at(pos)) ) ) 
				pos++;
			
			cadena = cadena.substr(pos, cadena.length()-pos);
		}
		
		/*******************************************************************/
		// M�todo: EliminaUltimosSeparadores()
		// Descripci�n: Elimina los caracteres separadores finales de "cadena"
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void EliminaUltimosSeparadores() {
		
		   	while( ( cadena.length() > 0 ) && ( isspace(cadena.back()) ) )
				cadena.pop_back();
		}
		
		/*******************************************************************/
		// M�todo: EliminaSeparadoresInicialesyFinales()
		// Descripci�n: Elimina los caracteres separadores iniciales y 
		//              finales de "cadena"
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void EliminaSeparadoresInicialesyFinales() {	
		
			EliminaPrimerosSeparadores();
			EliminaUltimosSeparadores();
		}		
		
		/*******************************************************************/
		// M�todo: CuentaPalabras()
		// Descripci�n: Devuelve el n�mero de palabras que forman "cadena"
		// Recibe: -
		// Devuelve: N�mero de palabras que forman "cadena" (cont_palabras)
		/*******************************************************************/
		int CuentaPalabras() {
			
			ManipuladorString manip_local(cadena);
			manip_local.EliminaSeparadoresInicialesyFinales();
			string cadena_limpia = manip_local.GetCadena();
			
			int cont_palabras = 0;
			int longitud_cadena = cadena_limpia.length();
			
			if(longitud_cadena > 0) {				
				
				if( isalnum(cadena_limpia.at(0)) )
		   			cont_palabras++;
		
				for (int i = 1; i < longitud_cadena; i++)
		   			if( (isalnum(cadena_limpia.at(i)) ) && 
					    (!isalnum(cadena_limpia.at(i-1))) )
		       			cont_palabras++;
		    }
		    
		    return cont_palabras;
        }

		/*******************************************************************/
		// M�todo: ConvierteAMayusculas()
		// Descripci�n: Convierte todos los caracteres de "cadena" a may�sculas
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void ConvierteAMayusculas() {
			
			int longitud_cadena = cadena.length();
			
			for(int i = 0; i < longitud_cadena; i++)
				cadena.at(i) = toupper(cadena.at(i));
		}
		
		/*******************************************************************/
		// M�todo: ConvierteAMinusculas()
		// Descripci�n: Convierte todos los caracteres de "cadena" a min�sculas
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void ConvierteAMinusculas() {
			
			int longitud_cadena = cadena.length();
			
			for(int pos = 0; pos < longitud_cadena; pos++)
				cadena.at(pos) = tolower(cadena.at(pos));
		}
};

/***************************************************************************/
// Clase Lector: representa una lectura etiquetada de datos int y double
/***************************************************************************/
class Lector {
	
	private:
		
		string titulo;		// Texto que etiqueta la lectura
		
	public:
		
		/*******************************************************************/
		// Constructor sin par�metros
		/*******************************************************************/
		Lector() : titulo("") { }
		
		/*******************************************************************/
		// Constructor con par�metros
		/*******************************************************************/
		Lector(string valor_titulo) : titulo(valor_titulo) { }	
		
		/*******************************************************************/
		// M�todo: SetTitulo()
		// Descripci�n: Establece el texto que etiqueta la lectura
		// Recibe: Texto que etiqueta la lectura (valor_titulo)
		// Devuelve: -
		/*******************************************************************/
		void SetTitulo(string valor_titulo) {
			
			titulo = valor_titulo;
		}
		
		/*******************************************************************/
		// M�todo: GetTitulo()
		// Descripci�n: Devuelve el texto que etiqueta la lectura
		// Recibe: -
		// Devuelve: Texto que etiqueta la lectura (titulo)
		/*******************************************************************/
		string GetTitulo() {
			
			return titulo;	
		}
		
		/*******************************************************************/
		// M�todo: LeeEntero()
		// Descripci�n: Lee un n�mero entero
		// Recibe: -
		// Devuelve: N�mero entero (numero).
		/*******************************************************************/
		int LeeEntero() {
			
			string cadena;
			
			do {
				
				cout << titulo;
				getline(cin, cadena);
				
			}while( !EsEntero(cadena) );
			
			return ( stoi(cadena) ); 
		}
		
		/*******************************************************************/
		// M�todo: LeeEnteroEnRango()
		// Descripci�n: Lee un n�mero entero dentro del rango 
		//              ["menor" , "mayor"]
		// Recibe: Valor m�nimo del rango (menor),
		//		   Valor m�ximo del rango (mayor)
		// Devuelve: N�mero entero dentro del rango (numero)
		/*******************************************************************/
		int LeeEnteroEnRango(int menor, int mayor) {
			
			int numero; 
			
			do {
				numero = LeeEntero();		
			}while( (numero < menor) || (numero > mayor) );
			
			return numero;	
		}
		
		/*******************************************************************/
		// M�todo: LeeEnteroMayorOIgual()
		// Descripci�n: Lee un n�mero entero mayor o igual que "referencia"
		// Recibe: N�mero entero de referencia (referencia)
		// Devuelve: N�mero entero mayor o igual que "referencia" (numero)
		/*******************************************************************/
		int LeeEnteroMayorOIgual(int referencia) {
			
			int numero; 
			
			do {
				numero = LeeEntero();		
			}while(numero < referencia);
			
			return numero;	
		}	
		
		/*******************************************************************/
		// M�todo: LeeEnteroMayor()
		// Descripci�n: Lee un n�mero entero mayor que "referencia"
		// Recibe: N�mero entero de referencia (referencia)
		// Devuelve: N�mero entero mayor que "referencia" (numero)
		/*******************************************************************/
		int LeeEnteroMayor(int referencia) {
			
			int numero; 
			
			do {
				numero = LeeEntero();		
			}while(numero <= referencia);
			
			return numero;	
		}
		
		/*******************************************************************/
		// M�todo: LeeDouble()
		// Descripci�n: Lee un n�mero real
		// Recibe: -
		// Devuelve: N�mero real (numero).
		/*******************************************************************/
		double LeeDouble() {
			
			string cadena;
			
			do {
				
				cout << titulo;
				getline(cin, cadena);
				
			}while( !EsReal(cadena) );
			
			return ( stod(cadena) ); 
		}
		
		/*******************************************************************/
		// M�todo: LeeDoubleEnRango()
		// Descripci�n: Lee un n�mero real dentro del rango ["menor" , "mayor"]
		// Recibe: Valor m�nimo del rango (menor),
		//		   Valor m�ximo del rango (mayor)
		// Devuelve: N�mero real dentro del rango (numero)
		/*******************************************************************/
		double LeeDoubleEnRango(double menor, double mayor) {
			
			double numero; 
			
			do {
				numero = LeeDouble();		
			}while( (numero < menor) || (numero > mayor) );
			
			return numero;	
		}
		
		/*******************************************************************/
		// M�todo: LeeDoubleMayorOIgual()
		// Descripci�n: Lee un n�mero real mayor o igual que "referencia"
		// Recibe: N�mero real de referencia (referencia)
		// Devuelve: N�mero real mayor o igual que "referencia" (numero)
		/*******************************************************************/
		double LeeDoubleMayorOIgual(double referencia) {
			
			double numero; 
			
			do {
				numero = LeeDouble();		
			}while(numero < referencia);
			
			return numero;	
		}
		
		/*******************************************************************/
		// M�todo: LeeDoubleMayor()
		// Descripci�n: Lee un n�mero real mayor que "referencia"
		// Recibe: N�mero real de referencia (referencia)
		// Devuelve: N�mero real mayor que "referencia" (numero)
		/*******************************************************************/
		double LeeDoubleMayor(double referencia) {
			
			double numero; 
			
			do {
				numero = LeeDouble();		
			}while(numero <= referencia);
			
			return numero;	
		}
				
	private:
		
		/*******************************************************************/
		// M�todo: EsEntero()
		// Descripci�n: Comprueba si un n�mero es entero.
		// Recibe: Cadena (cadena)
		// Devuelve: True (1) si "cadena" es un n�mero entero y False (0)
		//           si no lo es
		/*******************************************************************/
		bool EsEntero(string cadena) {
			
			ManipuladorString m(cadena);
			m.EliminaSeparadoresInicialesyFinales();
			cadena = m.GetCadena();
			
			bool es_entero = true;
			int longitud_cadena = cadena.length();
			
			if(longitud_cadena == 0)
				es_entero = false;
			else {
				
				int pos;
				
				if( (cadena.at(0) == '-') || (cadena.at(0) == '+') )
					pos = 1;	
				else
					pos = 0;
					
				while( (pos < longitud_cadena) && es_entero) {
				
					if( !isdigit(cadena.at(pos)) )
						es_entero = false;
					else
						pos++;
				}
			}
			
			return es_entero;
		}
		
		/*******************************************************************/
		// M�todo: EsReal()
		// Descripci�n: Comprueba si un n�mero es real.
		// Recibe: Cadena (cadena)
		// Devuelve: True (1) si "cadena" es un n�mero real y False (0)
		//           si no lo es
		/*******************************************************************/
		bool EsReal(string cadena) {
			
			ManipuladorString m(cadena);
			m.EliminaSeparadoresInicialesyFinales();
			cadena = m.GetCadena();
			
			bool es_real = true;
			int longitud_cadena = cadena.length();
			
			if(longitud_cadena == 0)
				es_real = false;
			else {
				
				int pos;
				
				if( (cadena.at(0) == '-') || (cadena.at(0) == '+') )
					pos = 1;	
				else
					pos = 0;
					
				bool encontrado_un_punto = false;
				
				while( (pos < longitud_cadena) && es_real) {
					
					char c = cadena.at(pos);
					
					if( !isdigit(c) ) {
						
						if(c == '.') {
							
							if(encontrado_un_punto)	
								es_real = false;
							else
								encontrado_un_punto = true;
						}
						else
							es_real = false;
					}
					
					pos++;
				}
			}
			
			return es_real;
		}
};

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
			 	
				int pos_sec_implicita = 0;
			    int pos_sec_otra = 0;
			    
			    for(int i = 0; i < sec.total_utilizados; i++) {
			    			    	
					if(i < pos_insercion) {
						
						sec.vector_privado[i] = 
						                    vector_privado[pos_sec_implicita];
						                    
						pos_sec_implicita++;
					}
						
					if( (i >= pos_insercion) && 
					    (i < pos_insercion + otra.total_utilizados) ) {
					    	
						sec.vector_privado[i] = 
						                    otra.vector_privado[pos_sec_otra];	
						                    
						pos_sec_otra++;
					}
						
					if(i >= pos_insercion + otra.total_utilizados) {
						
						sec.vector_privado[i] = 
						                    vector_privado[pos_sec_implicita];
						                    
						pos_sec_implicita++;
					}
			    }
			}
			
			return sec;                     	
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
	
	string cadena1, cadena2;
	
	Lector lector_posicion;
	
	SecuenciaCaracteres secuencia1, secuencia2;
	int pos_insercion;
	
	// Entradas de datos
	
	// Secuencia 1
	
	do{
		
		cout << " Introduzca una secuencia de caracteres: ";
		getline(cin, cadena1);
		
	}while(secuencia1.Capacidad() < cadena1.length() );
	
	secuencia1.StringToSecuencia(cadena1);
	
	// Secuencia 2
	
	do{
		
		cout << " Introduzca otra secuencia de caracteres: ";
		getline(cin, cadena2);
		
	}while(secuencia2.Capacidad() < cadena2.length() );
	
	secuencia2.StringToSecuencia(cadena2);
	
	// Posici�n de Secuencia 1 donde se va a insertar Secuencia 2
	
	string cadena;
	cadena += " Posicion de Secuencia 1 donde se va a insertar Secuencia 2: ";
	            
	lector_posicion.SetTitulo(cadena);
	pos_insercion = lector_posicion.LeeEnteroEnRango
	                                ( 0, secuencia1.TotalUtilizados() );
	
	// C�lculos
	
	SecuenciaCaracteres secuencia_insercion;
	
	secuencia_insercion = secuencia1.InsertaSecuenciaCaracteres
	                                 (pos_insercion, secuencia2);
	
	// Salidas
	
	// Secuencia 1
	
	cout << endl;
	cout << " Secuencia 1: " 
		 << secuencia1.ToString() << endl;
	cout << " Tiene " << secuencia1.TotalUtilizados() << " elementos.";
	cout << endl << endl; 
	
	// Secuencia 2
	
	cout << endl;
	cout << " Secuencia 2: " 
		 << secuencia2.ToString() << endl;
	cout << " Tiene " << secuencia2.TotalUtilizados() << " elementos.";
	cout << endl << endl; 
	cout << endl;
	
	// Secuencia resultado de insertar Secuencia 2 en Secuencia 1 a partir
	// de la posici�n "pos_insercion"
	
	cout << " Secuencia insercion: " 
		 << secuencia_insercion.ToString() << endl;
	cout << " Tiene " << secuencia_insercion.TotalUtilizados() << " elementos.";
	cout << endl << endl; 
	
	return 0;	
}
