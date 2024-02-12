/*
	Relación de ejercicios 6

	Ejercicios 6, 7 y 8: 
	
		Ejercicio 6: Sobre la clase SecuenciaCaracteres, definimos un método 
		             que inserta otra secuencia (otra) a partir de una posición 
					 (pos_insercion).
						
						void InsertaSecuenciaCaracteres(int pos_insercion,
													SecuenciaCaracteres otra)

					 Implementamos este método utilizando un método que inserta 
					 un único carácter:
						
						void Inserta(int pos_insercion, char valor_nuevo)

					 Insertamos el carácter valor_nuevo en la posición 
					 "pos_insercion". Tras la inserción, "valor_nuevo" ocupará 
					 la posición "pos_insercion".

					 Tendremos que llamar a este método para insertar, uno a 
					 uno, todos los caracteres de la secuencia "otra".
					 
		Ejercicio 7: Implementamos el método del ejercicio 6 de una forma 
		             eficiente, sin tener que llamar al método de inserción 
					 de un carácter por cada carácter que se vaya a insertar.
	              
	    Ejercicio 8: Modificamos el método del ejercicio 7 de manera que ahora 
		             devuelve una nueva secuencia. La secuencia original 
					 (la implícita) y la secuencia "otra" no se modifican.
					 
	Entradas: Dos secuencias de caracteres (secuencia1, secuencia2),
	          Posición de "secuencia1" (pos_insercion)
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
		// Constructor sin parámetros
		/*******************************************************************/
		ManipuladorString() {
			
			cadena = "";
		}
		
		/*******************************************************************/
		// Constructor con parámetros
		/*******************************************************************/
		ManipuladorString(string la_cadena) : cadena(la_cadena) { }
		
		/*******************************************************************/
		// Método: SetCadena()
		// Descripción: Establece el texto que va a almacenar "cadena"
		// Recibe: Texto que va a almacenar "cadena" (la_cadena)
		// Devuelve: -
		/*******************************************************************/
		void SetCadena(string la_cadena) {
			
			cadena = la_cadena;	
		}
		
		/*******************************************************************/
		// Método: GetCadena()
		// Descripción: Devuelve el texto almacenado en "cadena"
		// Recibe: -
		// Devuelve: Texto almacenado en "cadena" (cadena)
		/*******************************************************************/
		string GetCadena() {
			
			return cadena;	
		}

		/*******************************************************************/
		// Método: EliminaPrimerosSeparadores()
		// Descripción: Elimina los caracteres separadores iniciales 
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
		// Método: EliminaUltimosSeparadores()
		// Descripción: Elimina los caracteres separadores finales de "cadena"
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void EliminaUltimosSeparadores() {
		
		   	while( ( cadena.length() > 0 ) && ( isspace(cadena.back()) ) )
				cadena.pop_back();
		}
		
		/*******************************************************************/
		// Método: EliminaSeparadoresInicialesyFinales()
		// Descripción: Elimina los caracteres separadores iniciales y 
		//              finales de "cadena"
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void EliminaSeparadoresInicialesyFinales() {	
		
			EliminaPrimerosSeparadores();
			EliminaUltimosSeparadores();
		}		
		
		/*******************************************************************/
		// Método: CuentaPalabras()
		// Descripción: Devuelve el número de palabras que forman "cadena"
		// Recibe: -
		// Devuelve: Número de palabras que forman "cadena" (cont_palabras)
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
		// Método: ConvierteAMayusculas()
		// Descripción: Convierte todos los caracteres de "cadena" a mayúsculas
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void ConvierteAMayusculas() {
			
			int longitud_cadena = cadena.length();
			
			for(int i = 0; i < longitud_cadena; i++)
				cadena.at(i) = toupper(cadena.at(i));
		}
		
		/*******************************************************************/
		// Método: ConvierteAMinusculas()
		// Descripción: Convierte todos los caracteres de "cadena" a minúsculas
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
		// Constructor sin parámetros
		/*******************************************************************/
		Lector() : titulo("") { }
		
		/*******************************************************************/
		// Constructor con parámetros
		/*******************************************************************/
		Lector(string valor_titulo) : titulo(valor_titulo) { }	
		
		/*******************************************************************/
		// Método: SetTitulo()
		// Descripción: Establece el texto que etiqueta la lectura
		// Recibe: Texto que etiqueta la lectura (valor_titulo)
		// Devuelve: -
		/*******************************************************************/
		void SetTitulo(string valor_titulo) {
			
			titulo = valor_titulo;
		}
		
		/*******************************************************************/
		// Método: GetTitulo()
		// Descripción: Devuelve el texto que etiqueta la lectura
		// Recibe: -
		// Devuelve: Texto que etiqueta la lectura (titulo)
		/*******************************************************************/
		string GetTitulo() {
			
			return titulo;	
		}
		
		/*******************************************************************/
		// Método: LeeEntero()
		// Descripción: Lee un número entero
		// Recibe: -
		// Devuelve: Número entero (numero).
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
		// Método: LeeEnteroEnRango()
		// Descripción: Lee un número entero dentro del rango 
		//              ["menor" , "mayor"]
		// Recibe: Valor mínimo del rango (menor),
		//		   Valor máximo del rango (mayor)
		// Devuelve: Número entero dentro del rango (numero)
		/*******************************************************************/
		int LeeEnteroEnRango(int menor, int mayor) {
			
			int numero; 
			
			do {
				numero = LeeEntero();		
			}while( (numero < menor) || (numero > mayor) );
			
			return numero;	
		}
		
		/*******************************************************************/
		// Método: LeeEnteroMayorOIgual()
		// Descripción: Lee un número entero mayor o igual que "referencia"
		// Recibe: Número entero de referencia (referencia)
		// Devuelve: Número entero mayor o igual que "referencia" (numero)
		/*******************************************************************/
		int LeeEnteroMayorOIgual(int referencia) {
			
			int numero; 
			
			do {
				numero = LeeEntero();		
			}while(numero < referencia);
			
			return numero;	
		}	
		
		/*******************************************************************/
		// Método: LeeEnteroMayor()
		// Descripción: Lee un número entero mayor que "referencia"
		// Recibe: Número entero de referencia (referencia)
		// Devuelve: Número entero mayor que "referencia" (numero)
		/*******************************************************************/
		int LeeEnteroMayor(int referencia) {
			
			int numero; 
			
			do {
				numero = LeeEntero();		
			}while(numero <= referencia);
			
			return numero;	
		}
		
		/*******************************************************************/
		// Método: LeeDouble()
		// Descripción: Lee un número real
		// Recibe: -
		// Devuelve: Número real (numero).
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
		// Método: LeeDoubleEnRango()
		// Descripción: Lee un número real dentro del rango ["menor" , "mayor"]
		// Recibe: Valor mínimo del rango (menor),
		//		   Valor máximo del rango (mayor)
		// Devuelve: Número real dentro del rango (numero)
		/*******************************************************************/
		double LeeDoubleEnRango(double menor, double mayor) {
			
			double numero; 
			
			do {
				numero = LeeDouble();		
			}while( (numero < menor) || (numero > mayor) );
			
			return numero;	
		}
		
		/*******************************************************************/
		// Método: LeeDoubleMayorOIgual()
		// Descripción: Lee un número real mayor o igual que "referencia"
		// Recibe: Número real de referencia (referencia)
		// Devuelve: Número real mayor o igual que "referencia" (numero)
		/*******************************************************************/
		double LeeDoubleMayorOIgual(double referencia) {
			
			double numero; 
			
			do {
				numero = LeeDouble();		
			}while(numero < referencia);
			
			return numero;	
		}
		
		/*******************************************************************/
		// Método: LeeDoubleMayor()
		// Descripción: Lee un número real mayor que "referencia"
		// Recibe: Número real de referencia (referencia)
		// Devuelve: Número real mayor que "referencia" (numero)
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
		// Método: EsEntero()
		// Descripción: Comprueba si un número es entero.
		// Recibe: Cadena (cadena)
		// Devuelve: True (1) si "cadena" es un número entero y False (0)
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
		// Método: EsReal()
		// Descripción: Comprueba si un número es real.
		// Recibe: Cadena (cadena)
		// Devuelve: True (1) si "cadena" es un número real y False (0)
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
	
	// Posición de Secuencia 1 donde se va a insertar Secuencia 2
	
	string cadena;
	cadena += " Posicion de Secuencia 1 donde se va a insertar Secuencia 2: ";
	            
	lector_posicion.SetTitulo(cadena);
	pos_insercion = lector_posicion.LeeEnteroEnRango
	                                ( 0, secuencia1.TotalUtilizados() );
	
	// Cálculos
	
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
	// de la posición "pos_insercion"
	
	cout << " Secuencia insercion: " 
		 << secuencia_insercion.ToString() << endl;
	cout << " Tiene " << secuencia_insercion.TotalUtilizados() << " elementos.";
	cout << endl << endl; 
	
	return 0;	
}
