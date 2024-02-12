/*
	Relación de ejercicios 6

	Ejercicio 46:	
	
	Reescribir el ejercicio 39 (fila más cercana de un conjunto de filas 
	preseleccionadas) usando la clase TablaRectangularEnteros que emplea una 
	secuencia de secuencias de enteros como dato privado.

	Emplear la misma función main que se usó para la solución propuesta usando 
	la clase que emplea una matriz clásica como dato privado. Si no ha tenido 
	que cambiar nada, la clase está bien construida.
	              
	Entradas: Tabla rectangular de números enteros (matriz),
	          Filas de la matriz introducidas a comparar (filas_a_comparar),
	          Secuencia de enteros (referencia).
	Salidas: Fila de la matriz más cercana a la secuencia de enteros de
	         entre todas las filas a comparar (fila_mas_cercana).
			 
	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

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
		// Método: Posicion()
		// Descripción: Busca un valor en la secuencia, entre dos posiciones 
		//              dadas. 
		// 				Realiza una búsqueda secuencial
		// Recibe: Valor a buscar en la secuencia (buscado),
		//         Valor inicial del rango de posiciones de la secuencia (izda),
		//         Valor final del rango de posiciones de la secuencia (dcha)
		// Devuelve: Posición del elemento "buscado" (si está en la secuencia)
		//           o -1 (si no está en la secuencia)
		// PRE: 0 <= izda <= dcha < total_utilizados
		/*******************************************************************/
		int Posicion(int buscado, int izda, int dcha) {
			
			bool encontrado = false; 
			int pos = izda; 
	
			while( (pos <= dcha) && (!encontrado) ) {
	
				if(vector_privado[pos] != buscado) // Seguir buscando
					pos++;
				else // Terminar la búsqueda: éxito
					encontrado =  true;
			} 
	
			if(encontrado)
				return pos;
			else 
				return -1;
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
		// Método: Subsecuencia()
		// Descripción: Devuelve una secuencia incluida en la secuencia 
		//              implícita, que empieza en la posición "pos_init" y 
		//              tiene "num_datos" valores
		// Recibe: Posición inicial desde donde empieza la copia a la
		//         subsecuencia (pos_init),
		//         Número de valores que se copian a la subsecuencia 
		//         (num_datos)
		// Devuelve: Subsecuencia de la secuencia implícita
		// Casos: 1) Si 0 <= pos_init < total_utilizados y
		//			 pos_init+num_datos<=total_utilizados
		//			 se devuelve una subsecuencia de tamaño "num_datos"
		//		  2) Si 0 <= pos_init < total_utilizados y
		//			 pos_init+num_datos>total_utilizados, se devuelve una 
		//			 subsecuencia de tamaño total_utilizados-pos_init
		//		  3) Si pos_init < 0 o pos_init >= total_utilizados, 
		//			 se devuelve una subsecuencia vacía.
		//		  4) Si num_datos = 0, se devuelve una subsecuencia vacía.		
		/*******************************************************************/
		SecuenciaEnteros Subsecuencia(int pos_init, int num_datos) {
			
			SecuenciaEnteros a_devolver; // inicialmente vacía
			
			if( (pos_init >= 0) && (pos_init < total_utilizados) && 
			    (num_datos > 0) ) {
				
				int pos_end;
				
				if(pos_init+num_datos > total_utilizados) 
					pos_end = total_utilizados;
				else 
					pos_end = pos_init+num_datos;
				
				for(int pos = pos_init; pos < pos_end; pos++)
					a_devolver.Aniade(vector_privado[pos]);
			}
			
			return a_devolver;
		}
	
		/*******************************************************************/
		// Método: EsIgual()
		// Descripción: Comprueba si dos secuencias de enteros son iguales.
		//              Para ello, compara la secuencia implícita con 
		//              "otra_secuencia" (secuencia explícita)
		// Recibe: Secuencia de enteros (otra_secuencia)
		// Devuelve: True (1) si las dos secuencias son iguales y False (0) si
		//           no lo son.
		/*******************************************************************/
		bool EsIgual(SecuenciaEnteros otra_secuencia) {
			
			bool son_iguales = true; 
			
			if (total_utilizados != otra_secuencia.total_utilizados)
				son_iguales = false;
			else {
					
				bool sigo = true;
				int pos = 0;
				
				while( sigo && (pos < total_utilizados) ) {
		
					if( vector_privado[pos] != 
					   otra_secuencia.vector_privado[pos] ) {
					   	
						sigo = false;
						son_iguales = false;
					}
					else
						pos++; 
				}
			}
				
			return son_iguales;
		}
	
		/*******************************************************************/
		// Método: DistanciaEuclidea()
		// Descripción: Calcula la distancia euclídea entre dos vectores
		//              (objetos "SecuenciaEnteros")
		// Recibe: Objeto "SecuenciaEnteros" (otra_secuencia)
		// Devuelve: Distancia euclídea entre dos vectores 
		//           (objetos "SecuenciaEnteros")
		// PRE: total_utilizados = otra_secuencia.TotalUtilizados()
		/*******************************************************************/
		double DistanciaEuclidea(SecuenciaEnteros otra_secuencia) {
			
			int suma = 0;
			
			for(int i = 0; i < TotalUtilizados(); i++) {
				
				int dif = ( vector_privado[i] - otra_secuencia.Elemento(i) ) *
				          ( vector_privado[i] - otra_secuencia.Elemento(i) );
				          
				suma += dif;
			}
	
			return( sqrt(suma) );
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
// Clase TablaRectangularEnteros: representa una tabla rectangular de 
//                                números enteros
// Representación: Secuencia de secuencias de números enteros
/***************************************************************************/
class TablaRectangularEnteros {

	private:
	
	    static const int NUM_FILS = 50; // Filas disponibles
	    static const int NUM_COLS = 50; // Columnas disponibles
	    
    	SecuenciaEnteros vector_privado[NUM_FILS];
	
	    // PRE: 0 <= filas_utilizadas <= NUM_FILS
	    // PRE: 0 <= col_utilizadas < NUM_COLS
	    
	    int filas_utilizadas;
	    int cols_utilizadas;

	public:

		/*******************************************************************/
		// Constructor sin argumentos (crea una matriz nula)
		/*******************************************************************/
		TablaRectangularEnteros(): filas_utilizadas(0), cols_utilizadas(0) { }

		/*******************************************************************/
		// Constructor con argumentos
		// Recibe: Número de columnas que deben tener todas las filas
		//         (numero_de_columnas)
		// PRE: numero_de_columnas <= NUM_COLS
		/*******************************************************************/
		TablaRectangularEnteros(int numero_de_columnas) 
		              : filas_utilizadas(0), 
					    cols_utilizadas(numero_de_columnas) { }

		/*******************************************************************/
		// Constructor con argumentos
		// Recibe: Secuencia de números enteros que será la primera fila
		//         de la tabla
		// El número de elementos de elementos de la secuencia es el valor
		// que se usa como "col_utilizadas"
		// PRE: primera_fila.TotalUtilizados() <= NUM_COLS
		/*******************************************************************/
		TablaRectangularEnteros(SecuenciaEnteros primera_fila)
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
		int Elemento(int fila, int columna) {
			
			return ( (vector_privado[fila]).Elemento(columna) );
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
		//              "SecuenciaEnteros")
		// Recibe: Índice de la fila a devolver (indice_fila)
		// Devuelve: Fila completa (un objeto "SecuenciaEnteros")
		// PRE: 0 <= indice_fila < filas_utilizadas
		/*******************************************************************/
		SecuenciaEnteros Fila(int indice_fila) {
			
			return ( vector_privado[indice_fila] );
		}

		/*******************************************************************/
		// Método: Columna()
		// Descripción: Devuelve una columna completa (un objeto 
		//              "SecuenciaEnteros")
		// Recibe: Índice de la columna a devolver (indice_columna)
		// Devuelve: Columna completa (un objeto "SecuenciaEnteros")
		// PRE: 0 <= indice_columna < cols_utilizadas
		/*******************************************************************/	
		SecuenciaEnteros Columna(int indice_columna) {
			
			SecuenciaEnteros columna;
	
			for(int fil = 0; fil < filas_utilizadas; fil++)
				columna.Aniade( (vector_privado[fil]).Elemento
				                                            (indice_columna) );
	
			return columna;
		}

		/*******************************************************************/
		// Método: Aniade()
		// Descripción: Añade una fila completa (un objeto "SecuenciaEnteros")
		//              al final de la tabla. 
		//              La adición se realiza si hay alguna fila disponible.
		//              Si no la hay, no se hace nada
		// Recibe: Nueva fila a añadir al final de la tabla (fila_nueva)
		// Devuelve: -
		// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
		// PRE:  filas_utilizadas < NUM_FILS
		/*******************************************************************/
		void Aniade(SecuenciaEnteros fila_nueva) {
			
			int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
						
			if( (filas_utilizadas < NUM_FILS) && 
				(numero_columnas_fila_nueva == cols_utilizadas) ) {
	
				vector_privado[filas_utilizadas] = fila_nueva;
	
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
		// Descripción: Comprueba si dos tablas rectangulares son iguales.
		//              Para ello, compara la tabla implícita con "otra_tabla"
		//              (tabla explícita)
		// Recibe: Tabla rectangular de enteros (otra_tabla)
		// Devuelve: True (1) si las dos tablas son iguales y False (0) si
		//           no lo son.
		/*******************************************************************/
		bool EsIgual(TablaRectangularEnteros otra_tabla) {
			
			bool son_iguales = true; 
			
			if ( ( filas_utilizadas != otra_tabla.FilasUtilizadas() ) ||  
				 ( cols_utilizadas != otra_tabla.ColumnasUtilizadas() ) )		
				
				son_iguales = false;
			else {
				
				// Recorrido por filas 
		
				int fil = 0;
				
				while(fil < filas_utilizadas && !son_iguales) {
		
					SecuenciaEnteros una_fila = Fila(fil);
					SecuenciaEnteros otra_fila = otra_tabla.Fila(fil);	
					
					if( una_fila.EsIgual(otra_fila) )
						fil++;
					else
						son_iguales = false;
				}
			}
		
			return son_iguales;
		}

		/*******************************************************************/
		// Método: Traspuesta()
		// Descripción: Devuelve la traspuesta de la tabla rectangular (si
		//              es posible calcularse). Si no se puede calcular la
		//              traspuesta, se devuelve una matriz nula.
		// Recibe: -
		// Devuelve: Traspuesta de la tabla rectangular (traspuesta)
		// PRE: filas_utilizadas <= NUM_COLS
		// PRE: cols_utilizadas  <= NUM_FILS
		/*******************************************************************/
		TablaRectangularEnteros Traspuesta() {
				
		    TablaRectangularEnteros traspuesta; // Inicialmente vacía
				    
			if( (filas_utilizadas <= NUM_COLS) && 
			    (cols_utilizadas <= NUM_FILS) ) {
			
				// La traspuesta tiene tantas filas como columnas tiene la 
				// matriz original
	
				TablaRectangularEnteros solucion(filas_utilizadas);
	
	
				SecuenciaEnteros columna; // Las filas de "traspuesta" serán las 
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
		// Descripción: Comprueba si la tabla rectangular es simétrica.
		//              Para ello, comprueba directamente si cada componente es 
		//              igual a su simétrica, parando el recorrido cuando 
		//              encuentre una componente que no lo verifique. De esta
		//              forma, se evita el cálculo de la traspuesta y el 
		//              problema que puede surgir si no se puede calcular la 
		//              traspuesta de la matriz por problemas de capacidad
		// Recibe: -
		// Devuelve: True (1) si la tabla rectangular es simétrica y False (0)
		//           si no lo es
		// CONDICIÓN NECESARIA: La tabla rectangular debe ser una matriz 
		//                      cuadrada
		/*******************************************************************/
		bool EsSimetrica() {
		
			bool es_simetrica = true;
		
			// Si el número de filas y columnas no coinciden, no hay que seguir
			// porque la matriz no es simétrica.
			
			es_simetrica = (filas_utilizadas == cols_utilizadas);
	
			if(es_simetrica) {
			
				int f = 0; 
				
				while(f < filas_utilizadas && es_simetrica) {
					
					int c = 0; 
					
					while(c < cols_utilizadas && es_simetrica) {
				
						if( Elemento(f,c) != Elemento(c,f) ) 
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
		// Descripción: Inserta una fila completa (un objeto "SecuenciaEnteros")
		//              en una posición dada.
		// Recibe: Posición que ocupará "fila_nueva" cuando se inserte en la
		//         tabla (num_fila),
		//         Fila a insertar (fila_nueva)
		// Devuelve: -
		// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
		// PRE:  filas_utilizadas < NUM_FILS
		// PRE:  0 <= num_fila <= TotalUtilizados()
		//		 Si num_fila = 0, "nueva_fila" será la nueva primera fila. 
		//		 Si num_fila = TotalUtilizados(), "nueva_fila" será la nueva 
		//		 última fila (el resultado será equivalente al de "Aniade()" 
		/*******************************************************************/
		void Inserta(int num_fila, SecuenciaEnteros fila_nueva) {
			
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
				// NOTA: no se modifica (todavía) "filas_utilizadas" 
				
				for(int fil = filas_utilizadas; fil > num_fila; fil--) 			
					vector_privado[fil] = vector_privado[fil-1];
				
				// Copiar en el "hueco" (fila "num_fila") el contenido de 
				// la secuencia "fila_nueva"
				
				vector_privado[num_fila] = fila_nueva;	
				
				filas_utilizadas++; // Actualización del tamaño de la tabla.
			}
		}

		/*******************************************************************/
		// Método: Elimina()
		// Descripción: Elimina una fila completa (un objeto "SecuenciaEnteros")
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
				
				for(int fil = num_fila; fil < filas_utilizadas-1; fil++) 
					vector_privado[fil] = vector_privado[fil+1];
				
				filas_utilizadas--; // Actualización del tamaño de la tabla.
			}
		}	

		/*******************************************************************/
		// Método: Contiene()
		// Descripción: Comprueba si la tabla rectangular contiene el valor
		//              "buscado"
		// Recibe: Valor a buscar en la tabla rectangular (buscado)
		// Devuelve: True (1) si la tabla rectangular contiene el valor
		//           "buscado" y False (0) si no lo contiene.
		/*******************************************************************/
		bool Contiene(int buscado) {
			
			bool encontrado = false;

			// Recorrido por filas 
	
			int fil = 0;
	
			while(fil < filas_utilizadas  && !encontrado) {
	
				SecuenciaEnteros una_fila = Fila(fil);
				
				int pos_buscado = 
				            una_fila.Posicion(buscado, 0, cols_utilizadas-1);
	
				if(pos_buscado != -1) 
					encontrado = true;
				else 
					fil++; 
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
		// Recibe: Valor a buscar en la tabla rectangular (buscado)
		// Devuelve: Posición del valor "buscado" en la tabla rectangular
		//           (posicion_dato_buscado). En caso de no encontrarse,
		//           se devuelve {-1,-1}
		/*******************************************************************/
		PosicionEnMatriz PrimeraOcurrencia(int buscado) {
			
			PosicionEnMatriz posicion_dato_buscado = {-1,-1};
	      
			bool encontrado = false;
	
			// Recorrido por filas 
	
			int fil = 0;
			
			while(fil < filas_utilizadas && !encontrado) {
	
				SecuenciaEnteros una_fila = Fila(fil);
				
				int pos_buscado = 
							una_fila.Posicion(buscado, 0, cols_utilizadas-1);
	
				if(pos_buscado != -1) {
					encontrado = true;
					posicion_dato_buscado.fila = fil;
					posicion_dato_buscado.columna = pos_buscado;		
				}
				else 
					fil++; 
	
			} 
	      
			return posicion_dato_buscado;
		} 
		
		/*******************************************************************/
		// Método: FilaMasCercana()
		// Descripción: Busca y devuelve la fila de la matriz que más se 
		//              parece a un vector de enteros (objeto 
		//              "SecuenciaEnteros"). La búsqueda se realiza sobre
		//              un conjunto seleccionado de filas de la tabla, el
		//              cual está almacenado en un objeto "SecuenciaEnteros".
		//              
		//              La similitud entre dos vectores viene dada por la
		//              distancia euclídea entre ambos
		// Recibe: Vector de enteros (referencia),
		//         Índices de filas de la tabla (filas_a_comparar)
		// Devuelve: Fila de la matriz que más se parece a "referencia"
		/*******************************************************************/
		int FilaMasCercana(SecuenciaEnteros referencia, 
		                   SecuenciaEnteros filas_a_comparar) { 
		
			int fila_mas_cercana = 0;
			
			double dist_euclidea_minima = referencia.DistanciaEuclidea(
			                        	Fila( filas_a_comparar.Elemento(0) ) );
			
			for(int i = 1; i < filas_a_comparar.TotalUtilizados(); i++) {
				
				SecuenciaEnteros fila_a_comparar = 	
				                        Fila( filas_a_comparar.Elemento(i) );
				
				double dist_euclidea = 
				               referencia.DistanciaEuclidea(fila_a_comparar);
				
				if(dist_euclidea < dist_euclidea_minima) {
					dist_euclidea_minima = dist_euclidea;
					fila_mas_cercana = filas_a_comparar.Elemento(i);
				}
			}
			
			return fila_mas_cercana;
		}	
};

/***************************************************************************/
// Función principal
/***************************************************************************/
int main() {

	// Declaración de constantes
	
	const int MAX_FILAS = 50;
	const int MAX_COLS = 50;
	
	const int TERMINADOR = -1;
	
	// Declaración de variables y objetos
	
	int num_filas_matriz;
	int num_cols_matriz;
	int elemento_matriz;
	
	Lector lector_enteros;
	
	// Entradas de datos
	
	// Dimensiones de la matriz
	
	lector_enteros.SetTitulo(" Numero de filas de la matriz: ");
	num_filas_matriz = lector_enteros.LeeEnteroEnRango(1, MAX_FILAS);
	
	lector_enteros.SetTitulo(" Numero de columnas de la matriz: ");
	num_cols_matriz = lector_enteros.LeeEnteroEnRango(1, MAX_COLS);
	
	lector_enteros.SetTitulo("");

	TablaRectangularEnteros matriz(num_cols_matriz);
	
	SecuenciaEnteros una_fila;
	
	// Elementos de la matriz
	
	cout << " Elementos de la matriz: ";
	cout << endl << endl;
	
	for(int i = 0; i < num_filas_matriz; i++) {
		for(int j = 0; j < num_cols_matriz; j++) {
						
			cout << "\t Fila " << i << ", Columna " << j << ": ";
			elemento_matriz = lector_enteros.LeeEntero();
			
			una_fila.Aniade(elemento_matriz);
		}
				
		matriz.Aniade(una_fila);
		
		una_fila.EliminaTodos();
	}
	
	// Mostramos la matriz introducida
	
	cout << endl;
	cout << " Matriz introducida: " << endl;	
	cout << endl;
		
	for(int i = 0; i < num_filas_matriz; i++) {

		for(int j = 0; j < num_cols_matriz; j++)
			cout << setw(3) << matriz.Elemento(i,j);	

		cout << endl;
	}
	cout << endl;
	
	// Secuencia de filas a comparar
	
	SecuenciaEnteros filas_a_comparar;
	
	int elemento_filas_a_comparar;
	int i = 1;
	
	cout << " Filas a comparar (-1 para finalizar): ";
	cout << endl << endl;
		
	do {
		
		cout << "\t Fila " << i << " a comparar: ";
		elemento_filas_a_comparar = lector_enteros.LeeEnteroEnRango
		                                    (TERMINADOR, num_filas_matriz-1);
		
		if(elemento_filas_a_comparar != TERMINADOR) {                
			filas_a_comparar.Aniade(elemento_filas_a_comparar);
			i++;
		}
			
	}while(elemento_filas_a_comparar != TERMINADOR);

	// Mostramos la secuencia de filas a comparar
	
	cout << endl;
	cout << " Filas a comparar introducidas: " << filas_a_comparar.ToString();
	cout << endl << endl;
	
	// Secuencia de enteros
	
	SecuenciaEnteros referencia;
	
	int elemento_referencia;
	
	cout << " Secuencia de enteros: ";
	cout << endl << endl;
	
	for(int i = 1; i <= num_cols_matriz; i++) {
		
		cout << "\t Entero " << i << " de la secuencia: ";
		
		elemento_referencia = lector_enteros.LeeEntero();
		                                               
		referencia.Aniade(elemento_referencia);
	}
	
	// Mostramos la secuencia de enteros
	
	cout << endl;
	cout << " Secuencia de enteros introducida: " 
	     << referencia.ToString();
	cout << endl << endl;
	
	// Calculamos y mostramos la fila más cercana a "referencia" según
	// las filas almacenadas en "filas_a_comparar"
	
	int fila_mas_cercana = matriz.FilaMasCercana(referencia, filas_a_comparar);
	
	cout << " Fila de la matriz mas cercana a la secuencia de enteros"
	     << " introducida: " << fila_mas_cercana;
	cout << endl << endl;
	
	return 0;	
}
