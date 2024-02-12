/*
	Relaci�n de ejercicios 6

	Ejercicio 46:	
	
	Reescribir el ejercicio 39 (fila m�s cercana de un conjunto de filas 
	preseleccionadas) usando la clase TablaRectangularEnteros que emplea una 
	secuencia de secuencias de enteros como dato privado.

	Emplear la misma funci�n main que se us� para la soluci�n propuesta usando 
	la clase que emplea una matriz cl�sica como dato privado. Si no ha tenido 
	que cambiar nada, la clase est� bien construida.
	              
	Entradas: Tabla rectangular de n�meros enteros (matriz),
	          Filas de la matriz introducidas a comparar (filas_a_comparar),
	          Secuencia de enteros (referencia).
	Salidas: Fila de la matriz m�s cercana a la secuencia de enteros de
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
// Clase SecuenciaEnteros: representa una secuencia de n�meros enteros
/***************************************************************************/
class SecuenciaEnteros {

	private:

		static const int TAMANIO = 50; // N�mero de casillas disponibles
		int vector_privado[TAMANIO];

		// PRE: 0 <= total_utilizados <= TAMANIO
		int total_utilizados;	// N�mero de casillas ocupadas

	public:

		/*******************************************************************/
		// Constructor sin argumentos
		/*******************************************************************/
		SecuenciaEnteros() : total_utilizados(0) { }

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
		// M�todo: Aniade()
		// Descripci�n: A�ade un nuevo elemento al final del vector. 
		//              La adici�n se realiza si hay alguna casilla disponible.
		//              Si no la hay, no se hace nada
		// Recibe: Nuevo elemento a a�adir al final del vector (nuevo)
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
		// M�todo: Elimina()
		// Descripci�n: Eliminar el elemento de la posici�n dada por "indice".
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
		// M�todo: Elemento()
		// Descripci�n: Devuelve el elemento de la casilla "indice"
		// Recibe: �ndice de la casilla del elemento a devolver (indice)
		// Devuelve: Elemento almacenado en la casilla "indice"
		// PRE: 0 <= indice < total_utilizados
		/*******************************************************************/
		int Elemento(int indice) {
			
			return vector_privado[indice];
		}

		/*******************************************************************/
		// M�todo: EstaVacia()
		// Descripci�n: Comprueba si la secuencia est� vac�a
		// Recibe: -
		// Devuelve: True (1) si la secuencia est� vac�a y False (0) si no
		//           lo est�.
		/*******************************************************************/
		bool EstaVacia() {
			
			return (total_utilizados == 0);
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
		// M�todo: Posicion()
		// Descripci�n: Busca un valor en la secuencia, entre dos posiciones 
		//              dadas. 
		// 				Realiza una b�squeda secuencial
		// Recibe: Valor a buscar en la secuencia (buscado),
		//         Valor inicial del rango de posiciones de la secuencia (izda),
		//         Valor final del rango de posiciones de la secuencia (dcha)
		// Devuelve: Posici�n del elemento "buscado" (si est� en la secuencia)
		//           o -1 (si no est� en la secuencia)
		// PRE: 0 <= izda <= dcha < total_utilizados
		/*******************************************************************/
		int Posicion(int buscado, int izda, int dcha) {
			
			bool encontrado = false; 
			int pos = izda; 
	
			while( (pos <= dcha) && (!encontrado) ) {
	
				if(vector_privado[pos] != buscado) // Seguir buscando
					pos++;
				else // Terminar la b�squeda: �xito
					encontrado =  true;
			} 
	
			if(encontrado)
				return pos;
			else 
				return -1;
		}
	
		/*******************************************************************/
		// M�todo: PosicionMinimo()
		// Descripci�n: Devuelve la posici�n del m�nimo valor situado entre
		//              las posiciones [izda, dcha] de la secuencia
		// Recibe: Valor inicial del rango de posiciones de la secuencia (izda),
		//         Valor final del rango de posiciones de la secuencia (dcha)
		// Devuelve: Posici�n del m�nimo valor situado entre las posiciones 
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
		// M�todo: PosicionMaximo()
		// Descripci�n: Devuelve la posici�n del m�ximo valor situado entre
		//              las posiciones [izda, dcha] de la secuencia
		// Recibe: Valor inicial del rango de posiciones de la secuencia (izda),
		//         Valor final del rango de posiciones de la secuencia (dcha)
		// Devuelve: Posici�n del m�ximo valor situado entre las posiciones 
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
		// M�todo: Minimo()
		// Descripci�n: Devuelve el m�nimo valor situado entre las posiciones 
		//              [izda, dcha] de la secuencia
		// Recibe: Valor inicial del rango de posiciones de la secuencia (izda),
		//         Valor final del rango de posiciones de la secuencia (dcha)
		// Devuelve: M�nimo valor situado entre las posiciones [izda, dcha] de 
		//           la secuencia
		// PRE: 0 <= izda <= dcha < total_utilizados
		/*******************************************************************/
		int Minimo(int izda, int dcha) {
			
			return ( vector_privado[PosicionMinimo(izda, dcha)] );
		}
		
		/*******************************************************************/
		// M�todo: Maximo()
		// Descripci�n: Devuelve el m�ximo valor situado entre las posiciones 
		//              [izda, dcha] de la secuencia
		// Recibe: Valor inicial del rango de posiciones de la secuencia (izda),
		//         Valor final del rango de posiciones de la secuencia (dcha)
		// Devuelve: M�ximo valor situado entre las posiciones [izda, dcha] de 
		//           la secuencia
		// PRE: 0 <= izda <= dcha < total_utilizados
		/*******************************************************************/
		int Maximo(int izda, int dcha) {
			
			return ( vector_privado[PosicionMaximo(izda, dcha)] );
		}

		/*******************************************************************/
		// M�todo: Subsecuencia()
		// Descripci�n: Devuelve una secuencia incluida en la secuencia 
		//              impl�cita, que empieza en la posici�n "pos_init" y 
		//              tiene "num_datos" valores
		// Recibe: Posici�n inicial desde donde empieza la copia a la
		//         subsecuencia (pos_init),
		//         N�mero de valores que se copian a la subsecuencia 
		//         (num_datos)
		// Devuelve: Subsecuencia de la secuencia impl�cita
		// Casos: 1) Si 0 <= pos_init < total_utilizados y
		//			 pos_init+num_datos<=total_utilizados
		//			 se devuelve una subsecuencia de tama�o "num_datos"
		//		  2) Si 0 <= pos_init < total_utilizados y
		//			 pos_init+num_datos>total_utilizados, se devuelve una 
		//			 subsecuencia de tama�o total_utilizados-pos_init
		//		  3) Si pos_init < 0 o pos_init >= total_utilizados, 
		//			 se devuelve una subsecuencia vac�a.
		//		  4) Si num_datos = 0, se devuelve una subsecuencia vac�a.		
		/*******************************************************************/
		SecuenciaEnteros Subsecuencia(int pos_init, int num_datos) {
			
			SecuenciaEnteros a_devolver; // inicialmente vac�a
			
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
		// M�todo: EsIgual()
		// Descripci�n: Comprueba si dos secuencias de enteros son iguales.
		//              Para ello, compara la secuencia impl�cita con 
		//              "otra_secuencia" (secuencia expl�cita)
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
		// M�todo: DistanciaEuclidea()
		// Descripci�n: Calcula la distancia eucl�dea entre dos vectores
		//              (objetos "SecuenciaEnteros")
		// Recibe: Objeto "SecuenciaEnteros" (otra_secuencia)
		// Devuelve: Distancia eucl�dea entre dos vectores 
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
		// M�todo: ToString()
		// Descripci�n: Compone un string con todos los elementos que est�n
		//              almacenados en la secuencia y lo devuelve.
		// Recibe: -
		// Devuelve: String con todos los elementos que est�n almacenados
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

		static const int TAMANIO = 50; // N�mero de casillas disponibles
		PosicionEnMatriz vector_privado[TAMANIO];
		
		//PRE: 0 <= total_utilizados <= TAMANIO
		int total_utilizados;	// N�mero de casillas ocupadas

	public: 
	
		/*******************************************************************/
		// Constructor sin argumentos
		/*******************************************************************/
		SecuenciaPosicionEnMatriz() : total_utilizados(0) { }

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
		// M�todo: Aniade()
		// Descripci�n: A�ade un nuevo elemento al final del vector. 
		//              La adici�n se realiza si hay alguna casilla disponible.
		//              Si no la hay, no se hace nada
		// Recibe: Nuevo elemento a a�adir al final del vector (nuevo)
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
		// M�todo: Elemento()
		// Descripci�n: Devuelve el elemento de la casilla "indice"
		// Recibe: �ndice de la casilla del elemento a devolver (indice)
		// Devuelve: Elemento almacenado en la casilla "indice"
		// PRE: 0 <= indice < total_utilizados
		/*******************************************************************/
		PosicionEnMatriz Elemento(int indice) {
			
			return vector_privado[indice];
		}
};

/***************************************************************************/
// Clase TablaRectangularEnteros: representa una tabla rectangular de 
//                                n�meros enteros
// Representaci�n: Secuencia de secuencias de n�meros enteros
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
		// Recibe: N�mero de columnas que deben tener todas las filas
		//         (numero_de_columnas)
		// PRE: numero_de_columnas <= NUM_COLS
		/*******************************************************************/
		TablaRectangularEnteros(int numero_de_columnas) 
		              : filas_utilizadas(0), 
					    cols_utilizadas(numero_de_columnas) { }

		/*******************************************************************/
		// Constructor con argumentos
		// Recibe: Secuencia de n�meros enteros que ser� la primera fila
		//         de la tabla
		// El n�mero de elementos de elementos de la secuencia es el valor
		// que se usa como "col_utilizadas"
		// PRE: primera_fila.TotalUtilizados() <= NUM_COLS
		/*******************************************************************/
		TablaRectangularEnteros(SecuenciaEnteros primera_fila)
					  : filas_utilizadas(0), 
					    cols_utilizadas( primera_fila.TotalUtilizados() ) {
		
						Aniade(primera_fila); // Actualiza "filas_utilizadas"
		}

		/*******************************************************************/
		// M�todo: CapacidadFilas()
		// Descripci�n: Devuelve el n�mero m�ximo de filas
		// Recibe: -
		// Devuelve: N�mero m�ximo de filas (NUM_FILS)
		/*******************************************************************/
		int CapacidadFilas() {
			
			return NUM_FILS;
		}

		/*******************************************************************/
		// M�todo: CapacidadColumnas()
		// Descripci�n: Devuelve el n�mero m�ximo de columnas
		// Recibe: -
		// Devuelve: N�mero m�ximo de columnas (NUM_COLS)
		/*******************************************************************/
		int CapacidadColumnas() {
			
			return NUM_COLS;
		}

		/*******************************************************************/
		// M�todo: FilasUtilizadas()
		// Descripci�n: Devuelve el n�mero de filas utilizadas
		// Recibe: -
		// Devuelve: N�mero de filas utilizadas (filas_utilizadas)
		/*******************************************************************/
		int FilasUtilizadas() {
			
			return filas_utilizadas;
		}

		/*******************************************************************/
		// M�todo: ColumnasUtilizadas()
		// Descripci�n: Devuelve el n�mero de columnas utilizadas
		// Recibe: -
		// Devuelve: N�mero de columnas utilizadas (cols_utilizadas)
		/*******************************************************************/
		int ColumnasUtilizadas() {
			
			return cols_utilizadas;
		}

		/*******************************************************************/
		// M�todo: Elemento()
		// Descripci�n: Devuelve el elemento de la casilla de coordenadas
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
		// M�todo: EstaVacia()
		// Descripci�n: Comprueba si la tabla est� vac�a
		// Recibe: -
		// Devuelve: True (1) si la tabla est� vac�a y False (0) si no
		//           lo est�.
		/*******************************************************************/
		bool EstaVacia() {
			
			return (filas_utilizadas == 0);
		}

		/*******************************************************************/
		// M�todo: Fila()
		// Descripci�n: Devuelve una fila completa (un objeto 
		//              "SecuenciaEnteros")
		// Recibe: �ndice de la fila a devolver (indice_fila)
		// Devuelve: Fila completa (un objeto "SecuenciaEnteros")
		// PRE: 0 <= indice_fila < filas_utilizadas
		/*******************************************************************/
		SecuenciaEnteros Fila(int indice_fila) {
			
			return ( vector_privado[indice_fila] );
		}

		/*******************************************************************/
		// M�todo: Columna()
		// Descripci�n: Devuelve una columna completa (un objeto 
		//              "SecuenciaEnteros")
		// Recibe: �ndice de la columna a devolver (indice_columna)
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
		// M�todo: Aniade()
		// Descripci�n: A�ade una fila completa (un objeto "SecuenciaEnteros")
		//              al final de la tabla. 
		//              La adici�n se realiza si hay alguna fila disponible.
		//              Si no la hay, no se hace nada
		// Recibe: Nueva fila a a�adir al final de la tabla (fila_nueva)
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
		// M�todo: EliminaTodos()
		// Descripci�n: "Vac�a" completamente la tabla
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void EliminaTodos() {
			
			filas_utilizadas = 0;
		}

		/*******************************************************************/
		// M�todo: EsIgual()
		// Descripci�n: Comprueba si dos tablas rectangulares son iguales.
		//              Para ello, compara la tabla impl�cita con "otra_tabla"
		//              (tabla expl�cita)
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
		// M�todo: Traspuesta()
		// Descripci�n: Devuelve la traspuesta de la tabla rectangular (si
		//              es posible calcularse). Si no se puede calcular la
		//              traspuesta, se devuelve una matriz nula.
		// Recibe: -
		// Devuelve: Traspuesta de la tabla rectangular (traspuesta)
		// PRE: filas_utilizadas <= NUM_COLS
		// PRE: cols_utilizadas  <= NUM_FILS
		/*******************************************************************/
		TablaRectangularEnteros Traspuesta() {
				
		    TablaRectangularEnteros traspuesta; // Inicialmente vac�a
				    
			if( (filas_utilizadas <= NUM_COLS) && 
			    (cols_utilizadas <= NUM_FILS) ) {
			
				// La traspuesta tiene tantas filas como columnas tiene la 
				// matriz original
	
				TablaRectangularEnteros solucion(filas_utilizadas);
	
	
				SecuenciaEnteros columna; // Las filas de "traspuesta" ser�n las 
									      // columnas de la tabla impl�cita 
	
				for(int col = 0; col < cols_utilizadas; col++) {
					columna = Columna(col);
					solucion.Aniade(columna); 
				}
				
				traspuesta = solucion;
			} 
	
			return traspuesta;
		}			
	

		/*******************************************************************/
		// M�todo: EsSimetrica()
		// Descripci�n: Comprueba si la tabla rectangular es sim�trica.
		//              Para ello, comprueba directamente si cada componente es 
		//              igual a su sim�trica, parando el recorrido cuando 
		//              encuentre una componente que no lo verifique. De esta
		//              forma, se evita el c�lculo de la traspuesta y el 
		//              problema que puede surgir si no se puede calcular la 
		//              traspuesta de la matriz por problemas de capacidad
		// Recibe: -
		// Devuelve: True (1) si la tabla rectangular es sim�trica y False (0)
		//           si no lo es
		// CONDICI�N NECESARIA: La tabla rectangular debe ser una matriz 
		//                      cuadrada
		/*******************************************************************/
		bool EsSimetrica() {
		
			bool es_simetrica = true;
		
			// Si el n�mero de filas y columnas no coinciden, no hay que seguir
			// porque la matriz no es sim�trica.
			
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
		// M�todo: Inserta()
		// Descripci�n: Inserta una fila completa (un objeto "SecuenciaEnteros")
		//              en una posici�n dada.
		// Recibe: Posici�n que ocupar� "fila_nueva" cuando se inserte en la
		//         tabla (num_fila),
		//         Fila a insertar (fila_nueva)
		// Devuelve: -
		// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
		// PRE:  filas_utilizadas < NUM_FILS
		// PRE:  0 <= num_fila <= TotalUtilizados()
		//		 Si num_fila = 0, "nueva_fila" ser� la nueva primera fila. 
		//		 Si num_fila = TotalUtilizados(), "nueva_fila" ser� la nueva 
		//		 �ltima fila (el resultado ser� equivalente al de "Aniade()" 
		/*******************************************************************/
		void Inserta(int num_fila, SecuenciaEnteros fila_nueva) {
			
			int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
						
			// Comprobar precondiciones
			
			if( (filas_utilizadas < NUM_FILS) && 
				(numero_columnas_fila_nueva == cols_utilizadas) && 
				(0<=num_fila) && (num_fila <=filas_utilizadas) ) {
	
				// "Desplazar" las filas hacia posiciones altas. 
				// La �ltima fila se copia en una NUEVA FILA que ocupa la 
				// posici�n "filas_utilizadas", la pen�ltima se copia en 
				// "filas_utilizadas"-1, ... y se queda un "hueco" en 
				// la fila "num_fila ".
				// NOTA: no se modifica (todav�a) "filas_utilizadas" 
				
				for(int fil = filas_utilizadas; fil > num_fila; fil--) 			
					vector_privado[fil] = vector_privado[fil-1];
				
				// Copiar en el "hueco" (fila "num_fila") el contenido de 
				// la secuencia "fila_nueva"
				
				vector_privado[num_fila] = fila_nueva;	
				
				filas_utilizadas++; // Actualizaci�n del tama�o de la tabla.
			}
		}

		/*******************************************************************/
		// M�todo: Elimina()
		// Descripci�n: Elimina una fila completa (un objeto "SecuenciaEnteros")
		//              de una posici�n dada.
		// Recibe: Posici�n de la fila a eliminar (num_fila)
		// Devuelve: -
		// PRE:  0 <= num_fila < TotalUtilizados()
		/*******************************************************************/
		void Elimina(int num_fila) {
				
			// Comprobar precondiciones
			
			if( (0 <= num_fila) && (num_fila <= filas_utilizadas) ) {
	
				// "Desplazar" las filas hacia posiciones bajas. 
				// En la posici�n "num_fila" se copia la que est� en la 
				// posici�n siguiente ("num_fila"+1), en su lugar se copia que 
				// est� en "num_fila"+2, ... y en la posici�n 
				// "total_utilizados"-2 se copia la de "total_utilizados"-1. 
				
				for(int fil = num_fila; fil < filas_utilizadas-1; fil++) 
					vector_privado[fil] = vector_privado[fil+1];
				
				filas_utilizadas--; // Actualizaci�n del tama�o de la tabla.
			}
		}	

		/*******************************************************************/
		// M�todo: Contiene()
		// Descripci�n: Comprueba si la tabla rectangular contiene el valor
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
		// M�todo: PrimeraOcurrencia()
		// Descripci�n: Encuentra un dato en la matriz y devuelve su posici�n.
		// 				El valor devuelto contiene informaci�n acerca de la 
		//				posici�n (fila y columna) de "buscado".  
		// 				En el caso de que no est� contendr� {-1,-1}. 
		//				La consulta de la fila y la columna se delega en los 
		//				m�todos de la clase "PosicionEnMatriz" 
		// Recibe: Valor a buscar en la tabla rectangular (buscado)
		// Devuelve: Posici�n del valor "buscado" en la tabla rectangular
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
		// M�todo: FilaMasCercana()
		// Descripci�n: Busca y devuelve la fila de la matriz que m�s se 
		//              parece a un vector de enteros (objeto 
		//              "SecuenciaEnteros"). La b�squeda se realiza sobre
		//              un conjunto seleccionado de filas de la tabla, el
		//              cual est� almacenado en un objeto "SecuenciaEnteros".
		//              
		//              La similitud entre dos vectores viene dada por la
		//              distancia eucl�dea entre ambos
		// Recibe: Vector de enteros (referencia),
		//         �ndices de filas de la tabla (filas_a_comparar)
		// Devuelve: Fila de la matriz que m�s se parece a "referencia"
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
// Funci�n principal
/***************************************************************************/
int main() {

	// Declaraci�n de constantes
	
	const int MAX_FILAS = 50;
	const int MAX_COLS = 50;
	
	const int TERMINADOR = -1;
	
	// Declaraci�n de variables y objetos
	
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
	
	// Calculamos y mostramos la fila m�s cercana a "referencia" seg�n
	// las filas almacenadas en "filas_a_comparar"
	
	int fila_mas_cercana = matriz.FilaMasCercana(referencia, filas_a_comparar);
	
	cout << " Fila de la matriz mas cercana a la secuencia de enteros"
	     << " introducida: " << fila_mas_cercana;
	cout << endl << endl;
	
	return 0;	
}
