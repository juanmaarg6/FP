/*
	Relación de ejercicios 6

	Ejercicio 38:	
	
	Las distancias entre un conjunto de ciudades se almacenan en una tabla 
	rectangular de datos double. En realidad se almacenan las distancias
	de los caminos directos que conectan un conjunto de ciudades. Si entre dos 
	ciudades no existe un camino directo, se almacenará un cero. Se supone que 
	la distancia de una ciudad consigo misma será cero y que las distancias son 
	simétricas.
	
	Diseñar e implementar la clase MapaDistancias para representar este tipo de 
	datos. Usar como base la clase TablaRectangular. Suponer que nunca se 
	trabajará con más de 50 ciudades.

	Proporcionar métodos que doten a la clase de funcionalidad para resolver el 
	problema que se detalla a continuación.

	Escribir un programa que lea el número de ciudades de la red, y las 
	distancias entre las ciudades (recordar que 0 indica que entre dos ciudades 
	no existe un camino directo) y rellenar adecuadamente la matriz de 
	distancias.

	A continuación, resolver las siguientes tareas, mostrando el resultando en 
	pantalla:

		a) Obtener la ciudad (su índice) con mayor número de conexiones 
		   directas.

		b) Dada una ciudad j, obtener las ciudades conectadas directamente 
		   con j.
		   Devolver el resultado en un objeto SecuenciaEnteros.
		   
		c) Dadas dos ciudades i y j para las cuales no existe un camino directo, 
		   obtener aquella ciudad intermedia z que permita hacer el trayecto 
		   entre i y j de la forma más económica posible. Es decir, se trata de 
		   encontrar una ciudad z tal que d(i; z) + d(z; j) sea mínima 
		   (d(a; b) es la distancia entre las ciudades a y b). Si dicha ciudad 
		   no existiera, se indicará expresamente.

		d) Leer una serie de valores int que representan números de ciudades 
		   (el terminador será el valor -1) e indicar si todas las ciudades 
		   tienen conexiones directas entre sí.
		   Recibir los números de ciudades en un objeto SecuenciaEnteros.
	              
	Entradas: Número de ciudades de la red (num_ciudades),
	          Distancias de los caminos directos que conectan las
			  ciudades de la red (red_ciudades).
	Salidas: Ciudad con mayor número de conexiones directas 
	         (ciudad_mayor_num_conexiones),
	         Ciudades conectadas con una ciudad dada (ciudades_conectadas),
	         Ciudad intermedia que permite hacer el trayecto entre dos
	         ciudades, las cuales no están conectadas entre sí, de la forma
	         más económicas posible (ciudad_intermedia_min_dist),
	         Comprobación de si una serie de ciudades dadas tienen conexiones
	         directas entre sí.
			 
	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <iomanip>
#include <string>

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
// Clase SecuenciaEnteros: representa una secuencia de números enteros
/***************************************************************************/
class SecuenciaEnteros {

	private:

		static const int TAMANIO = 50; // Número de casillas disponibles
		int vector_privado[TAMANIO];

		// PRE: 0 <= total_utilizados <= TAMANIO
		int total_utilizados;	// Número de casillas ocupadas

	public:

		/*******************************************************************/
		// Constructor sin argumentos
		/*******************************************************************/
		SecuenciaEnteros() : total_utilizados(0) { }

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
		// Método: Aniade()
		// Descripción: Añade un nuevo elemento al final del vector. 
		//              La adición se realiza si hay alguna casilla disponible.
		//              Si no la hay, no se hace nada
		// Recibe: Nuevo elemento a añadir al final del vector (nuevo)
		// Devuelve: -
		// PRE: total_utilizados < TAMANIO
		/*******************************************************************/
		void Aniade(int nuevo) {
			
			if(total_utilizados < TAMANIO) {
				vector_privado[total_utilizados] = nuevo;
				total_utilizados++;
			}
		}

		/*******************************************************************/
		// Método: Elimina()
		// Descripción: Eliminar el elemento de la posición dada por "indice".
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
		// Método: Elemento()
		// Descripción: Devuelve el elemento de la casilla "indice"
		// Recibe: Índice de la casilla del elemento a devolver (indice)
		// Devuelve: Elemento almacenado en la casilla "indice"
		// PRE: 0 <= indice < total_utilizados
		/*******************************************************************/
		int Elemento(int indice) {
			
			return vector_privado[indice];
		}

		/*******************************************************************/
		// Método: EstaVacia()
		// Descripción: Comprueba si la secuencia está vacía
		// Recibe: -
		// Devuelve: True (1) si la secuencia está vacía y False (0) si no
		//           lo está.
		/*******************************************************************/
		bool EstaVacia() {
			
			return (total_utilizados == 0);
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
		// Método: PosicionMinimo()
		// Descripción: Devuelve la posición del mínimo valor situado entre
		//              las posiciones [izda, dcha] de la secuencia
		// Recibe: Valor inicial del rango de posiciones de la secuencia (izda),
		//         Valor final del rango de posiciones de la secuencia (dcha)
		// Devuelve: Posición del mínimo valor situado entre las posiciones 
		//           [izda, dcha] de la secuencia
		// PRE: 0 <= izda <= dcha < total_utilizados
		/*******************************************************************/
		int PosicionMinimo(int izda, int dcha) {
			
			int posicion_minimo;
			int minimo;

			minimo = vector_privado[izda];
			posicion_minimo = izda;

			for(int i = izda; i <= dcha ; i++) {
	
				if (vector_privado[i] < minimo) {
					minimo = vector_privado[i];
					posicion_minimo = i;
				}
			}

			return posicion_minimo;
		}

		/*******************************************************************/
		// Método: PosicionMaximo()
		// Descripción: Devuelve la posición del máximo valor situado entre
		//              las posiciones [izda, dcha] de la secuencia
		// Recibe: Valor inicial del rango de posiciones de la secuencia (izda),
		//         Valor final del rango de posiciones de la secuencia (dcha)
		// Devuelve: Posición del máximo valor situado entre las posiciones 
		//           [izda, dcha] de la secuencia
		// PRE: 0 <= izda <= dcha < total_utilizados
		/*******************************************************************/
		int PosicionMaximo(int izda, int dcha) {
			
			int posicion_maximo;
			int maximo;
	
			maximo = vector_privado[izda];
			posicion_maximo = izda;
	
			for(int i = izda; i <= dcha ; i++) {
	
				if (vector_privado[i] > maximo) {
					maximo = vector_privado[i];
					posicion_maximo = i;
				}
			}
	
			return posicion_maximo;
		}

		/*******************************************************************/
		// Método: Minimo()
		// Descripción: Devuelve el mínimo valor situado entre las posiciones 
		//              [izda, dcha] de la secuencia
		// Recibe: Valor inicial del rango de posiciones de la secuencia (izda),
		//         Valor final del rango de posiciones de la secuencia (dcha)
		// Devuelve: Mínimo valor situado entre las posiciones [izda, dcha] de 
		//           la secuencia
		// PRE: 0 <= izda <= dcha < total_utilizados
		/*******************************************************************/
		int Minimo(int izda, int dcha) {
			
			return ( vector_privado[PosicionMinimo(izda, dcha)] );
		}
		
		/*******************************************************************/
		// Método: Maximo()
		// Descripción: Devuelve el máximo valor situado entre las posiciones 
		//              [izda, dcha] de la secuencia
		// Recibe: Valor inicial del rango de posiciones de la secuencia (izda),
		//         Valor final del rango de posiciones de la secuencia (dcha)
		// Devuelve: Máximo valor situado entre las posiciones [izda, dcha] de 
		//           la secuencia
		// PRE: 0 <= izda <= dcha < total_utilizados
		/*******************************************************************/
		int Maximo(int izda, int dcha) {
			
			return ( vector_privado[PosicionMaximo(izda, dcha)] );
		}

		/*******************************************************************/
		// Método: ToString()
		// Descripción: Compone un string con todos los elementos que están
		//              almacenados en la secuencia y lo devuelve.
		// Recibe: -
		// Devuelve: String con todos los elementos que están almacenados
		//           en la secuencia (cadena)
		/*******************************************************************/
		string ToString() {
		
			string cadena;
			
			for(int i = 0; i < total_utilizados; i++)
				cadena = cadena + to_string(vector_privado[i]) + " ";
				
			return cadena;
		}
};

/***************************************************************************/
// Clase SecuenciaReales: representa una secuencia de números reales
/***************************************************************************/
class SecuenciaReales {

	private:

		static const int TAMANIO = 50; // Número de casillas disponibles
		double vector_privado[TAMANIO];

		// PRE: 0 <= total_utilizados <= TAMANIO
		int total_utilizados;	// Número de casillas ocupadas

	public:

		/*******************************************************************/
		// Constructor sin argumentos
		/*******************************************************************/
		SecuenciaReales() : total_utilizados(0) { }

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
		// Método: Aniade()
		// Descripción: Añade un nuevo elemento al final del vector. 
		//              La adición se realiza si hay alguna casilla disponible.
		//              Si no la hay, no se hace nada
		// Recibe: Nuevo elemento a añadir al final del vector (nuevo)
		// Devuelve: -
		// PRE: total_utilizados < TAMANIO
		/*******************************************************************/
		void Aniade(double nuevo) {
			
			if(total_utilizados < TAMANIO) {
				vector_privado[total_utilizados] = nuevo;
				total_utilizados++;
			}
		}

		/*******************************************************************/
		// Método: Elimina()
		// Descripción: Eliminar el elemento de la posición dada por "indice".
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
		// Método: Elemento()
		// Descripción: Devuelve el elemento de la casilla "indice"
		// Recibe: Índice de la casilla del elemento a devolver (indice)
		// Devuelve: Elemento almacenado en la casilla "indice"
		// PRE: 0 <= indice < total_utilizados
		/*******************************************************************/
		double Elemento(int indice) {
			
			return vector_privado[indice];
		}

		/*******************************************************************/
		// Método: EstaVacia()
		// Descripción: Comprueba si la secuencia está vacía
		// Recibe: -
		// Devuelve: True (1) si la secuencia está vacía y False (0) si no
		//           lo está.
		/*******************************************************************/
		bool EstaVacia() {
			
			return (total_utilizados == 0);
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
		// Método: PosicionMinimo()
		// Descripción: Devuelve la posición del mínimo valor situado entre
		//              las posiciones [izda, dcha] de la secuencia
		// Recibe: Valor inicial del rango de posiciones de la secuencia (izda),
		//         Valor final del rango de posiciones de la secuencia (dcha)
		// Devuelve: Posición del mínimo valor situado entre las posiciones 
		//           [izda, dcha] de la secuencia
		// PRE: 0 <= izda <= dcha < total_utilizados
		/*******************************************************************/
		int PosicionMinimo(int izda, int dcha) {
			
			int posicion_minimo;
			double minimo;

			minimo = vector_privado[izda];
			posicion_minimo = izda;

			for(int i = izda; i <= dcha ; i++) {
	
				if (vector_privado[i] < minimo) {
					minimo = vector_privado[i];
					posicion_minimo = i;
				}
			}

			return posicion_minimo;
		}

		/*******************************************************************/
		// Método: PosicionMaximo()
		// Descripción: Devuelve la posición del máximo valor situado entre
		//              las posiciones [izda, dcha] de la secuencia
		// Recibe: Valor inicial del rango de posiciones de la secuencia (izda),
		//         Valor final del rango de posiciones de la secuencia (dcha)
		// Devuelve: Posición del máximo valor situado entre las posiciones 
		//           [izda, dcha] de la secuencia
		// PRE: 0 <= izda <= dcha < total_utilizados
		/*******************************************************************/
		int PosicionMaximo(int izda, int dcha) {
			
			int posicion_maximo;
			double maximo;
	
			maximo = vector_privado[izda];
			posicion_maximo = izda;
	
			for(int i = izda; i <= dcha ; i++) {
	
				if (vector_privado[i] > maximo) {
					maximo = vector_privado[i];
					posicion_maximo = i;
				}
			}
	
			return posicion_maximo;
		}

		/*******************************************************************/
		// Método: Minimo()
		// Descripción: Devuelve el mínimo valor situado entre las posiciones 
		//              [izda, dcha] de la secuencia
		// Recibe: Valor inicial del rango de posiciones de la secuencia (izda),
		//         Valor final del rango de posiciones de la secuencia (dcha)
		// Devuelve: Mínimo valor situado entre las posiciones [izda, dcha] de 
		//           la secuencia
		// PRE: 0 <= izda <= dcha < total_utilizados
		/*******************************************************************/
		double Minimo(int izda, int dcha) {
			
			return ( vector_privado[PosicionMinimo(izda, dcha)] );
		}
		
		/*******************************************************************/
		// Método: Maximo()
		// Descripción: Devuelve el máximo valor situado entre las posiciones 
		//              [izda, dcha] de la secuencia
		// Recibe: Valor inicial del rango de posiciones de la secuencia (izda),
		//         Valor final del rango de posiciones de la secuencia (dcha)
		// Devuelve: Máximo valor situado entre las posiciones [izda, dcha] de 
		//           la secuencia
		// PRE: 0 <= izda <= dcha < total_utilizados
		/*******************************************************************/
		double Maximo(int izda, int dcha) {
			
			return ( vector_privado[PosicionMaximo(izda, dcha)] );
		}

		/*******************************************************************/
		// Método: ToString()
		// Descripción: Compone un string con todos los elementos que están
		//              almacenados en la secuencia y lo devuelve.
		// Recibe: -
		// Devuelve: String con todos los elementos que están almacenados
		//           en la secuencia (cadena)
		/*******************************************************************/
		string ToString() {
		
			string cadena;
			
			for(int i = 0; i < total_utilizados; i++)
				cadena = cadena + to_string(vector_privado[i]) + " ";
				
			return cadena;
		}
};

/***************************************************************************/
// El tipo de dato PosicionEnMatriz se emplea para guardar posiciones 	
// dentro de una matriz: se registra la pareja (fila, columna)
/***************************************************************************/
struct PosicionEnMatriz {
	int fila;
	int columna;
};

/***************************************************************************/
// Clase SecuenciaPosicionEnMatriz: representa una secuencia de posiciones
// 									(coordenadas) en una tabla bidimensional
/***************************************************************************/	
class SecuenciaPosicionEnMatriz {
	
	private:

		static const int TAMANIO = 50; // Número de casillas disponibles
		PosicionEnMatriz vector_privado[TAMANIO];
		
		//PRE: 0 <= total_utilizados <= TAMANIO
		int total_utilizados;	// Número de casillas ocupadas

	public: 
	
		/*******************************************************************/
		// Constructor sin argumentos
		/*******************************************************************/
		SecuenciaPosicionEnMatriz() : total_utilizados(0) { }

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
		// Método: Aniade()
		// Descripción: Añade un nuevo elemento al final del vector. 
		//              La adición se realiza si hay alguna casilla disponible.
		//              Si no la hay, no se hace nada
		// Recibe: Nuevo elemento a añadir al final del vector (nuevo)
		// Devuelve: -
		// PRE: total_utilizados < TAMANIO
		/*******************************************************************/
		void Aniade(PosicionEnMatriz nuevo) {
			
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
		PosicionEnMatriz Elemento(int indice) {
			
			return vector_privado[indice];
		}
};

/***************************************************************************/
// Clase MapaDistancias: representa una tabla rectangular de números reales
// Representación: Matriz "clásica"
/***************************************************************************/
class MapaDistancias {

	private:
	
	    static const int NUM_FILS = 50; // Filas disponibles
	    static const int NUM_COLS = 50; // Columnas disponibles
	    
	    double matriz_privada[NUM_FILS][NUM_COLS];
	
	    // PRE: 0 <= filas_utilizadas <= NUM_FILS
	    // PRE: 0 <= col_utilizadas < NUM_COLS
	    
	    int filas_utilizadas;
	    int cols_utilizadas;

	public:

		/*******************************************************************/
		// Constructor sin argumentos (crea una matriz nula)
		/*******************************************************************/
		MapaDistancias(): filas_utilizadas(0), cols_utilizadas(0) { }

		/*******************************************************************/
		// Constructor con argumentos
		// Recibe: Número de columnas que deben tener todas las filas
		//         (numero_de_columnas)
		// PRE: numero_de_columnas <= MAX_COL
		/*******************************************************************/
		MapaDistancias(int numero_de_columnas) 
		              : filas_utilizadas(0), 
					    cols_utilizadas(numero_de_columnas) { }

		/*******************************************************************/
		// Constructor con argumentos
		// Recibe: Secuencia de números reales
		// El número de elementos de elementos de la secuencia es el valor
		// que se usa como "col_utilizadas"
		//         (numero_de_columnas)
		// PRE: primera_fila.TotalUtilizados() <= MAX_COL
		/*******************************************************************/
		MapaDistancias(SecuenciaReales primera_fila)
					  : filas_utilizadas(0), 
					    cols_utilizadas( primera_fila.TotalUtilizados() ) {
		
						Aniade(primera_fila); // Actualiza "filas_utilizadas"
		}

		/*******************************************************************/
		// Método: CapacidadFilas()
		// Descripción: Devuelve el número máximo de filas
		// Recibe: -
		// Devuelve: Número máximo de filas (NUM_FILS)
		/*******************************************************************/
		int CapacidadFilas() {
			
			return NUM_FILS;
		}

		/*******************************************************************/
		// Método: CapacidadColumnas()
		// Descripción: Devuelve el número máximo de columnas
		// Recibe: -
		// Devuelve: Número máximo de columnas (NUM_COLS)
		/*******************************************************************/
		int CapacidadColumnas() {
			
			return NUM_COLS;
		}

		/*******************************************************************/
		// Método: FilasUtilizadas()
		// Descripción: Devuelve el número de filas utilizadas
		// Recibe: -
		// Devuelve: Número de filas utilizadas (filas_utilizadas)
		/*******************************************************************/
		int FilasUtilizadas() {
			
			return filas_utilizadas;
		}

		/*******************************************************************/
		// Método: ColumnasUtilizadas()
		// Descripción: Devuelve el número de columnas utilizadas
		// Recibe: -
		// Devuelve: Número de columnas utilizadas (cols_utilizadas)
		/*******************************************************************/
		int ColumnasUtilizadas() {
			
			return cols_utilizadas;
		}

		/*******************************************************************/
		// Método: Elemento()
		// Descripción: Devuelve el elemento de la casilla de coordenadas
		//              (fila, columna)
		// Recibe: Fila de la tabla (fila),
		//         Columna de la tabla (columna)
		// Devuelve: Elemento almacenado en la casilla de coordenadas
		//           (fila, columna)
		// PRE: 0 <= fila < filas_utilizadas
		// PRE: 0 <= columna < cols_utilizadas	
		/*******************************************************************/
		double Elemento(int fila, int columna) {
			
			return (matriz_privada[fila][columna]);
		}

		/*******************************************************************/
		// Método: EstaVacia()
		// Descripción: Comprueba si la tabla está vacía
		// Recibe: -
		// Devuelve: True (1) si la tabla está vacía y False (0) si no
		//           lo está.
		/*******************************************************************/
		bool EstaVacia() {
			
			return (filas_utilizadas == 0);
		}

		/*******************************************************************/
		// Método: Fila()
		// Descripción: Devuelve una fila completa (un objeto 
		//              "SecuenciaReales")
		// Recibe: Índice de la fila a devolver (indice_fila)
		// Devuelve: Fila completa (un objeto "SecuenciaReales")
		// PRE: 0 <= indice_fila < filas_utilizadas
		/*******************************************************************/
		SecuenciaReales Fila(int indice_fila) {
			
			SecuenciaReales fila;

			for(int col = 0; col < cols_utilizadas; col++)
				fila.Aniade(matriz_privada[indice_fila][col]);

			return fila;
		}

		/*******************************************************************/
		// Método: Columna()
		// Descripción: Devuelve una columna completa (un objeto 
		//              "SecuenciaReales")
		// Recibe: Índice de la columna a devolver (indice_columna)
		// Devuelve: Columna completa (un objeto "SecuenciaReales")
		// PRE: 0 <= indice_columna < cols_utilizadas
		/*******************************************************************/	
		SecuenciaReales Columna(int indice_columna) {
			
			SecuenciaReales columna;
	
			for(int fil = 0; fil < filas_utilizadas; fil++)
				columna.Aniade(matriz_privada[fil][indice_columna]);
	
			return columna;
		}

		/*******************************************************************/
		// Método: Aniade()
		// Descripción: Añade una fila completa (un objeto "SecuenciaReales")
		//              al final de la tabla. 
		//              La adición se realiza si hay alguna fila disponible.
		//              Si no la hay, no se hace nada
		// Recibe: Nueva fila a añadir al final de la tabla (fila_nueva)
		// Devuelve: -
		// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
		// PRE:  filas_utilizadas < MAX_FIL
		/*******************************************************************/
		void Aniade(SecuenciaReales fila_nueva) {
			
			int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
						
			if( (filas_utilizadas < NUM_FILS) &&
				(numero_columnas_fila_nueva == cols_utilizadas) ) {
	
				for(int col = 0; col < numero_columnas_fila_nueva; col++)
					matriz_privada[filas_utilizadas][col] = 
					                                fila_nueva.Elemento(col);
	
				filas_utilizadas++;
			}
		}

		/*******************************************************************/
		// Método: EliminaTodos()
		// Descripción: "Vacía" completamente la tabla
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void EliminaTodos() {
			
			filas_utilizadas = 0;
		}

		/*******************************************************************/
		// Método: EsIgual()
		// Descripción: Comprueba si dos mapas de distancias son iguales.
		//              Para ello, compara el mapa implícito con "otro_mapa"
		//              (mapa explícito)
		// Recibe: Mapa de distancias (otro_mapa)
		// Devuelve: True (1) si los dos mapas son iguales y False (0) si
		//           no lo son.
		/*******************************************************************/
		bool EsIgual(MapaDistancias otro_mapa) {
			
			bool son_iguales = true; 
			
			if ( ( filas_utilizadas != otro_mapa.FilasUtilizadas() ) ||  
				 ( cols_utilizadas != otro_mapa.ColumnasUtilizadas() ) )		
				
				son_iguales = false;
			else {
				
				int f = 0; 
				
				while(f < filas_utilizadas && son_iguales) {
					
					int c = 0; 
					
					while(c < cols_utilizadas && son_iguales) {
				
						if( matriz_privada[f][c] != otro_mapa.Elemento(f,c) ) 
							son_iguales = false;
							
						c++;
					}
		
					f++;
				}
			}
		
			return son_iguales;
		}

		/*******************************************************************/
		// Método: Traspuesta()
		// Descripción: Devuelve la traspuesta del mapa de distancias (si
		//              es posible calcularse). Si no se puede calcular la
		//              traspuesta, se devuelve una matriz nula.
		// Recibe: -
		// Devuelve: Traspuesta del mapa de distancias (traspuesta)
		// PRE: filas_utilizadas <= MAX_COL
		// PRE: cols_utilizadas  <= MAX_FIL
		/*******************************************************************/
		MapaDistancias Traspuesta() {
				
		    MapaDistancias traspuesta; // Inicialmente vacía
			
			if( (filas_utilizadas <= NUM_COLS) && 
			    (cols_utilizadas  <= NUM_FILS) ) {
			
				// La traspuesta tiene tantas filas como columnas tiene la
				// matriz original
		
				MapaDistancias solucion(filas_utilizadas);
		
		
				SecuenciaReales columna; // Las filas de "traspuesta" serán las
										 // columnas de la tabla implícita
		
				for(int col = 0; col < cols_utilizadas; col++) {
					columna = Columna(col);
					solucion.Aniade(columna);
				}
				
				traspuesta = solucion;
			} 
	
			return traspuesta;
		}			
	

		/*******************************************************************/
		// Método: EsSimetrica()
		// Descripción: Comprueba si el mapa de distancias es simétrico. 
		//              Para ello, comprueba directamente si cada componente es 
		//              igual a su simétrica, parando el recorrido cuando 
		//              encuentre una componente que no lo verifique. De esta
		//              forma, se evita el cálculo de la traspuesta y el 
		//              problema que puede surgir si no se puede calcular la 
		//              traspuesta de la matriz por problemas de capacidad
		// Recibe: -
		// Devuelve: True (1) si el mapa de distancias es simétrico y False (0)
		//           si no lo es
		// CONDICIÓN NECESARIA: El mapa de distancias debe ser una matriz 
		//                      cuadrada
		/*******************************************************************/
		bool EsSimetrica() {
		
			bool es_simetrica = true;
	
			// Si el número de filas y columnas no coinciden, no hay que seguir
			// porque el mapa de distancias no es simétrico.
	
			es_simetrica = (filas_utilizadas == cols_utilizadas);
	
			if(es_simetrica) {
	
				int f = 0;
	
				while(f < filas_utilizadas && es_simetrica) {
	
					int c = 0;
	
					while(c < cols_utilizadas && es_simetrica) {
	
						if(matriz_privada[f][c] != matriz_privada[c][f])
							es_simetrica = false;
	
						c++;
					}
	
					f++;
				}
			}
	
			return es_simetrica;
		}

		/*******************************************************************/
		// Método: Inserta()
		// Descripción: Inserta una fila completa (un objeto "SecuenciaReales")
		//              en una posición dada.
		// Recibe: Posición que ocupará "fila_nueva" cuando se inserte en el
		//         mapa de distancias (num_fila),
		//         Fila a insertar (fila_nueva)
		// Devuelve: -
		// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
		// PRE:  filas_utilizadas < MAX_FIL
		// PRE:  0 <= num_fila <= TotalUtilizados()
		//		 Si num_fila = 0, "nueva_fila" será la nueva primera fila. 
		//		 Si num_fila = TotalUtilizados(), "nueva_fila" será la nueva 
		//		 última fila (el resultado será equivalente al de "Aniade()" 
		/*******************************************************************/
		void Inserta(int num_fila, SecuenciaReales fila_nueva) {
			
			int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
						
			// Comprobar precondiciones
			
			if( (filas_utilizadas < NUM_FILS) &&
				(numero_columnas_fila_nueva == cols_utilizadas) && 
				(0<=num_fila) && (num_fila <=filas_utilizadas) ) {
	
				// "Desplazar" las filas hacia posiciones altas. 
				// La última fila se copia en una NUEVA FILA que ocupa la 
				// posición "filas_utilizadas", la penúltima se copia en 
				// "filas_utilizadas"-1, ... y se queda un "hueco" en 
				// la fila "num_fila ".
				// NOTA: No se modifica (todavía) "filas_utilizadas" 
				
				for(int fil = filas_utilizadas; fil > num_fila; fil--)
					for(int col = 0; col < numero_columnas_fila_nueva; col++)
						matriz_privada[fil][col] = matriz_privada[fil-1][col];
				
				// Copiar en el "hueco" (fila "num_fila") el contenido de 
				// la secuencia "fila_nueva"
				
				for(int col = 0; col < numero_columnas_fila_nueva; col++)
					matriz_privada[num_fila][col] = fila_nueva.Elemento(col);	
				
				filas_utilizadas++; // Actualización del tamaño de la tabla.
			}
		}

		/*******************************************************************/
		// Método: Elimina()
		// Descripción: Elimina una fila completa (un objeto "SecuenciaReales")
		//              de una posición dada.
		// Recibe: Posición de la fila a eliminar (num_fila)
		// Devuelve: -
		// PRE:  0 <= num_fila < TotalUtilizados()
		/*******************************************************************/
		void Elimina(int num_fila) {
				
			// Comprobar precondiciones
			
			if( (0 <= num_fila) && (num_fila <= filas_utilizadas) ) {
	
				// "Desplazar" las filas hacia posiciones bajas. 
				// En la posición "num_fila" se copia la que está en la 
				// posición siguiente ("num_fila"+1), en su lugar se copia que 
				// está en "num_fila"+2, ... y en la posición 
				// "total_utilizados"-2 se copia la de "total_utilizados"-1. 
				
				for(int fil = num_fila; fil < filas_utilizadas-1; fil++) {
				
					int num_columnas = cols_utilizadas;
						
					for(int c = 0; c < num_columnas; c++) 
						matriz_privada[fil][c] = matriz_privada[fil+1][c];
				}
				
				filas_utilizadas--; // Actualización del tamaño de la tabla.
			}
		}	

		/*******************************************************************/
		// Método: Contiene()
		// Descripción: Comprueba si el mapa de distancias contiene el valor
		//              "buscado"
		// Recibe: Valor a buscar en el mapa de distancias (buscado)
		// Devuelve: True (1) si el mapa de distancias contiene el valor
		//           "buscado" y False (0) si no lo contiene.
		/*******************************************************************/
		bool Contiene(double buscado) {
			
			bool encontrado = false;
	
			// Recorrido por columnas 
	
			int col = 0;
	
			while (col < cols_utilizadas && !encontrado) {
	
				int fil = 0;
	
				while (fil < filas_utilizadas && !encontrado) {
	
					if(matriz_privada[fil][col] == buscado)
						encontrado = true;
					
					fil++;
				}
	
				col++; 
			}
	
			return encontrado;
		}

		/*******************************************************************/
		// Método: PrimeraOcurrencia()
		// Descripción: Encuentra un dato en la matriz y devuelve su posición.
		// 				El valor devuelto contiene información acerca de la 
		//				posición (fila y columna) de "buscado".  
		// 				En el caso de que no esté contendrá {-1,-1}. 
		//				La consulta de la fila y la columna se delega en los 
		//				métodos de la clase "PosicionEnMatriz" 
		// Recibe: Valor a buscar en el mapa de distancias (buscado)
		// Devuelve: Posición del valor "buscado" en el mapa de distancias
		//           (posicion_dato_buscado). En caso de no encontrarse,
		//           se devuelve {-1,-1}
		/*******************************************************************/
		PosicionEnMatriz PrimeraOcurrencia(double buscado) {
			
			PosicionEnMatriz posicion_dato_buscado = {-1,-1};
	      
			bool encontrado = false;
	
			// Recorrido por filas 
	
			for(int i = 0; i < filas_utilizadas && !encontrado ; i++)
				for(int j = 0; j < cols_utilizadas && !encontrado; j++)
					if(matriz_privada[i][j] == buscado) {
						encontrado = true;
						posicion_dato_buscado.fila = i;
						posicion_dato_buscado.columna = j;
					}
		      
			return posicion_dato_buscado;
		} 

		/*******************************************************************/
		// Método: NumeroConexionesDirectas()
		// Descripción: Calcula el número de conexiones directas de una
		//              ciudad del mapa de distancias
		// Recibe: Indice de una ciudad del mapa de distancias (ciudad)
		// Devuelve: Número de conexiones directas de la ciudad del
		//           mapa de distancias (num_conexiones_directas)
		/*******************************************************************/
		int NumeroConexionesDirectas(int ciudad) {
			
			int num_conexiones_directas = 0;
			
			for(int j = 0; j < cols_utilizadas; j++)
				if(matriz_privada[ciudad][j] != 0)
					num_conexiones_directas++;
			
			return num_conexiones_directas;
		}

		/*******************************************************************/
		// Método: MayorNumeroConexionesDirectas()
		// Descripción: Calcula la ciudad del mapa de distancias con el mayor 
		//              número de conexiones directas
		// Recibe: -
		// Devuelve: Ciudad del mapa de distancias con el mayor número de 
		//           conexiones directas (ciudad_mayor_num_conex_directas)
		/*******************************************************************/
		int MayorNumeroConexionesDirectas() {
		
			int ciudad_mayor_num_conex_directas = 0;
			int mayor_num_conexiones_directas = 0;
			
			for(int i = 0; i < filas_utilizadas; i++) {
				
				int num_conexiones_directas = NumeroConexionesDirectas(i);
				
				if(num_conexiones_directas > mayor_num_conexiones_directas) {
					mayor_num_conexiones_directas = num_conexiones_directas;
					ciudad_mayor_num_conex_directas = i+1;
				}
			}
				
			return ciudad_mayor_num_conex_directas;
		}

		/*******************************************************************/
		// Método: EstanConectadas()
		// Descripción: Comprueba si dos ciudades del mapa de distancias están
		//              conectadas
		// Recibe: Índice de una ciudad del mapa de distancias 
		//         (ciudad1),
		//         Índice de otra ciudad del mapa de distancias 
		//         (ciudad2)
		// Devuelve: True (1) si "ciudad1" y "ciudad2" están conectadas y 
		//           False (0) si no lo están
		/*******************************************************************/
		bool EstanConectadas(int ciudad1, int ciudad2) {
			
			bool conectadas = 
			        (matriz_privada[ciudad1-1][ciudad2-1] != 0);
			
			return conectadas;	
		}
	
		/*******************************************************************/
		// Método: CiudadesConectadas()
		// Descripción: Calcula las ciudades que están conectadas directamente
		//              con una ciudad dada
		// Recibe: Índice de una ciudad del mapa de distancias (ciudad)
		// Devuelve: Ciudades que están conectadas directamente con "ciudad".
		//           Dichas ciudades se almacenaran en un objeto 
		//           "SecuenciaEnteros"  (ciudades_conectadas)
		/*******************************************************************/
		SecuenciaEnteros CiudadesConectadas(int ciudad) {
			
			SecuenciaEnteros ciudades_conectadas;
						
			for(int j = 0; j < cols_utilizadas; j++) {
				
				if( EstanConectadas(ciudad, j+1) ) 
					ciudades_conectadas.Aniade(j+1);
			}
			
			return ciudades_conectadas;
		}

		/*******************************************************************/
		// Método: EsCiudadIntermedia()
		// Descripción: Comprueba si una ciudad es intermedia a dos ciudades
		//              del mapa de distancias
		// Recibe: Índice de una ciudad del mapa de distancias (ciudad1),
		//         Índice de otra ciudad del mapa de distancias (ciudad2),
		//         Índice de la ciudad del mapa de distancias a comprobar
		//         si es intermedia entre las dos ciudades dadas
		//         (ciudad_intermedia)
		// Devuelve: True (1) si "ciudad_intermedia" es una ciudad
		//           intermedia entre "ciudad1" y "ciudad2"
		//           y False (0) si no lo es
		/*******************************************************************/
		bool EsCiudadIntermedia(int ciudad1, int ciudad2, 
		                        int ciudad_intermedia) {
			
			return ( (matriz_privada[ciudad1][ciudad_intermedia] != 0) && 
				     (matriz_privada[ciudad2][ciudad_intermedia] != 0) );	
		}

		/*******************************************************************/
		// Método: CiudadIntermediaMasEconomica()
		// Descripción: Calcula aquella ciudad intermedia que permite hacer el 
		//              trayecto entre "ciudad1" y "ciudad2" de la forma
		//              más económica posible. Es decir, encuentra una ciudad 
		//              "ciudad_dist_minima" tal que 
		//              d(ciudad; ciudad_dist_minima) + 
		//              d(ciudad_dist_minima; ciudad2) sea mínima 
		//              (d(a; b) es la distancia entre las ciudades a y b)
		// Recibe: Índice de una ciudad del mapa de distancias (ciudad1),
		//         Índice de otra ciudad del mapa de distancias (ciudad2)
		// Devuelve: Índice de aquella ciudad intermedia que permite hacer el 
		//           trayecto entre "ciudad1" y "ciudad2" de la forma
		//           más económica posible (ciudad_dist_minima)
		/*******************************************************************/
		int CiudadIntermediaMasEconomica(int ciudad1, int ciudad2) {
			
			int ciudad_dist_minima = 0;
			
			SecuenciaEnteros ciudades_intermedias;
									
			for(int j = 0; j < cols_utilizadas; j++)
				if( EsCiudadIntermedia(ciudad1-1, ciudad2-1, j) )
					ciudades_intermedias.Aniade(j+1);
					
			double distancia_minima = 
			    matriz_privada[ciudad1-1][ciudades_intermedias.Elemento(0)-1] + 
				matriz_privada[ciudades_intermedias.Elemento(0)-1][ciudad2-1];
			
			for(int i = 1; i < ciudades_intermedias.TotalUtilizados(); i++) {
				
				double distancia = matriz_privada[ciudad1-1][i] + 
				                   matriz_privada[i][ciudad2-1];
				
				if(distancia < distancia_minima) {
					distancia_minima = distancia;
					ciudad_dist_minima = ciudades_intermedias.Elemento(i);	
				}
			}
			
			return ciudad_dist_minima;
		}
		
		/*******************************************************************/
		// Método: SecuenciaCiudadesConectada()
		// Descripción: Comprueba si todas las ciudades de una secuencia de
		//				ciudades del mapa de distancias dada tienen conexiones
		//              directas entre sí
		// Recibe: Secuencia de ciudades del mapa de distancias (sec_ciudades)
		// Devuelve: True (1) si todas las ciudades tienen conexiones directas
		//           entre sí y False (0) si no las tienen.
		/*******************************************************************/
		bool SecuenciaCiudadesConectada(SecuenciaEnteros sec_ciudades) {
			
			bool hay_conexion_directa = true;
			int i = 0;
			
			while( ( i < sec_ciudades.TotalUtilizados()-1 ) && 
			        hay_conexion_directa) {
			
				int ciudad_referencia = sec_ciudades.Elemento(i);
				
				int j = i + 1;
				
				while( ( j < sec_ciudades.TotalUtilizados() ) && 
				        hay_conexion_directa) {
				
					int otra_ciudad = sec_ciudades.Elemento(j);				
													
					if( !EstanConectadas(ciudad_referencia, otra_ciudad) )
						hay_conexion_directa = false;
						 
					j++;
				}
				
				i++;
			}
			
			return hay_conexion_directa;
		}
};

/****************************************************************************/
// Función principal
/****************************************************************************/
int main() {
	
	// Declaración de constantes
	
	const int MAX_CIUDADES = 50;
	
	// Declaración de variables y objetos
		
	int num_ciudades;
	
	Lector lector_numeros;
	
	// Entradas de datos
		
	// Lectura del número de ciudades de la red
	
	lector_numeros.SetTitulo(" Numero de ciudades de la red: ");
	num_ciudades = lector_numeros.LeeEnteroEnRango(2, MAX_CIUDADES);
	
	// Declaración de la red de ciudades (objeto de la clase "MapaDistancias")
	
	MapaDistancias red_ciudades(num_ciudades);

	// Lectura de las distancias entre las ciudades
	
	SecuenciaReales distancias_ciudades;
	
	lector_numeros.SetTitulo("");

	cout << " Distancias entre las ciudades (en km): ";
	cout << endl << endl;
	
	for(int i = 0; i < num_ciudades; i++) {
		for(int j = 0; j < num_ciudades; j++) {
			
			double distancia;
			
			if(i == j)
				distancias_ciudades.Aniade(0.0);
			else if(j < i)
				distancias_ciudades.Aniade( red_ciudades.Elemento(j,i)  );
			else {
				
				do {
					string msg = "\t Distancia de la ciudad " + 
					                to_string(i+1) + " a la ciudad " + 
									to_string(j+1) + ": ";					
					cout << msg;
					distancia = lector_numeros.LeeDoubleMayorOIgual(0);
				}while(distancia < 0);
				
				distancias_ciudades.Aniade(distancia);
			}
		}
				
		red_ciudades.Aniade(distancias_ciudades);
		distancias_ciudades.EliminaTodos();
	}
	
	// Mostrar los datos de la red de ciudades
	
	cout << endl;
	cout << " Red de ciudades: " << endl;	
	cout << endl;
		
	for(int i = 0; i < num_ciudades; i++) {
		
		for(int j = 0; j < num_ciudades; j++)
			cout << setw(5) << red_ciudades.Elemento(i, j);	

		cout << endl;
	}
	cout << endl;
	
	// Cálculos y Salidas
	
	// APARTADO A)
	
	int ciudad_mayor_num_conexiones = 
	                             red_ciudades.MayorNumeroConexionesDirectas();
	                             
	cout << " Ciudad con el mayor numero de conexiones: " 
	     << ciudad_mayor_num_conexiones;
	cout << endl << endl;

	// APARTADO B)
	
	SecuenciaEnteros ciudades_conectadas;
	
	int ciudad;
	
	lector_numeros.SetTitulo(" Introduzca el indice de una ciudad: ");
	ciudad = lector_numeros.LeeEnteroEnRango(1, num_ciudades);
	
	ciudades_conectadas = red_ciudades.CiudadesConectadas(ciudad);
	
	cout << " La ciudad " << ciudad << " tiene conexiones directas con"
	     << " las siguientes ciudades: " << ciudades_conectadas.ToString()
		 << endl << endl;
	     
	// APARTADO C)
	
	int ciudad1;
	int ciudad2;
	
	lector_numeros.SetTitulo(" Introduzca el indice de una ciudad: ");
	ciudad1 = lector_numeros.LeeEnteroEnRango(1, num_ciudades);

	lector_numeros.SetTitulo(" Introduzca el indice de otra ciudad: ");
	ciudad2 = lector_numeros.LeeEnteroEnRango(1, num_ciudades);
	
	bool estan_conectadas = red_ciudades.EstanConectadas(ciudad1, ciudad2);
	
	if(!estan_conectadas) {
		
		int ciudad_intermedia_min_dist = 
		        red_ciudades.CiudadIntermediaMasEconomica(ciudad1, ciudad2);
		        
		cout << " Para ir desde la ciudad " << ciudad1 << " hasta la ciudad " 
		     << ciudad2 << " de la forma mas economica posible, se debe pasar"
			 << " por la ciudad " << ciudad_intermedia_min_dist;
	}
	else 
		cout << " Las ciudades " << ciudad1 << " y " << ciudad2 << " estan"
		     << " conectadas directamente, luego no existe ninguna ciudad"
			 << " intermedia que las conecte";
	
	lector_numeros.SetTitulo("");
	
	cout << endl << endl;

	// APARTADO D)
	
	const int TERMINADOR = -1;
	
	int ciudad_secuencia;
	SecuenciaEnteros secuencia_ciudades;
	
	cout << " Secuencia de ciudades (-1 para finalizar): ";
	cin >> ciudad_secuencia;
	
	while(ciudad_secuencia != TERMINADOR) {
			
		secuencia_ciudades.Aniade(ciudad_secuencia);
			
		cin >> ciudad_secuencia;
	}
		
	if(secuencia_ciudades.TotalUtilizados() != 0) {
		if( red_ciudades.SecuenciaCiudadesConectada(secuencia_ciudades) )
			cout << " Todas las ciudades introducidas tienen conexiones"
			     << " directas entre si";
		else
			cout << " No todas las ciudades introducidas tienen conexiones"
			     << " directas entre si";
	}
	else
		cout << " No se ha introducido ninguna secuencia de ciudades";		
		
	cout << endl << endl; 
	
	return 0;
}
