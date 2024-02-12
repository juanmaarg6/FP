/*
	Relaci�n de ejercicios 6

	Ejercicio 52:	
	
	Escribir un m�todo de la clase TablaDentadaReales (con secuencia de 
	secuencias) que devuelva un objeto TablaRectangularReales (con secuencia 
	de secuencias).

	El objeto devuelto tendr� tantas filas como tenga el objeto impl�cito, y 
	tantas columnas como columnas tenga la fila con menos columnas del objeto 
	impl�cito.

	Entradas: Tabla dentada de n�meros reales (tabla_dentada).
	Salidas: Menor tabla rectangular de n�meros reales contenida en
	         la tabla dentada de n�meros reales (tabla_rectangular).
			 		 
	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/***************************************************************************/
// Clase SecuenciaReales: representa una secuencia de n�meros reales
/***************************************************************************/
class SecuenciaReales {

	private:

		static const int TAMANIO = 50; // N�mero de casillas disponibles
		double vector_privado[TAMANIO];

		// PRE: 0 <= total_utilizados <= TAMANIO
		int total_utilizados;	// N�mero de casillas ocupadas

	public:

		/*******************************************************************/
		// Constructor sin argumentos
		/*******************************************************************/
		SecuenciaReales() : total_utilizados(0) { }

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
		void Aniade(double nuevo) {
			
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
		double Elemento(int indice) {
			
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
		int Posicion(double buscado, int izda, int dcha) {
			
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
		// M�todo: Minimo()
		// Descripci�n: Devuelve el m�nimo valor situado entre las posiciones 
		//              [izda, dcha] de la secuencia
		// Recibe: Valor inicial del rango de posiciones de la secuencia (izda),
		//         Valor final del rango de posiciones de la secuencia (dcha)
		// Devuelve: M�nimo valor situado entre las posiciones [izda, dcha] de 
		//           la secuencia
		// PRE: 0 <= izda <= dcha < total_utilizados
		/*******************************************************************/
		double Minimo(int izda, int dcha) {
			
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
		double Maximo(int izda, int dcha) {
			
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
		SecuenciaReales Subsecuencia(int pos_init, int num_datos) {
			
			SecuenciaReales a_devolver; // inicialmente vac�a
			
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
		// Descripci�n: Comprueba si dos secuencias de reales son iguales.
		//              Para ello, compara la secuencia impl�cita con 
		//              "otra_secuencia" (secuencia expl�cita)
		// Recibe: Secuencia de reales (otra_secuencia)
		// Devuelve: True (1) si las dos secuencias son iguales y False (0) si
		//           no lo son.
		/*******************************************************************/
		bool EsIgual(SecuenciaReales otra_secuencia) {
			
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
// Clase TablaRectangularReales: representa una tabla rectangular de 
//                               n�meros reales
// Representaci�n: Secuencia de secuencias de n�meros reales
/***************************************************************************/
class TablaRectangularReales {

	private:
	
	    static const int NUM_FILS = 50; // Filas disponibles
	    static const int NUM_COLS = 50; // Columnas disponibles
	    
    	SecuenciaReales vector_privado[NUM_FILS];
	
	    // PRE: 0 <= filas_utilizadas <= NUM_FILS
	    // PRE: 0 <= col_utilizadas < NUM_COLS
	    
	    int filas_utilizadas;
	    int cols_utilizadas;

	public:

		/*******************************************************************/
		// Constructor sin argumentos (crea una matriz nula)
		/*******************************************************************/
		TablaRectangularReales(): filas_utilizadas(0), cols_utilizadas(0) { }

		/*******************************************************************/
		// Constructor con argumentos
		// Recibe: N�mero de columnas que deben tener todas las filas
		//         (numero_de_columnas)
		// PRE: numero_de_columnas <= NUM_COLS
		/*******************************************************************/
		TablaRectangularReales(int numero_de_columnas) 
		              : filas_utilizadas(0), 
					    cols_utilizadas(numero_de_columnas) { }

		/*******************************************************************/
		// Constructor con argumentos
		// Recibe: Secuencia de n�meros reales que ser� la primera fila
		//         de la tabla
		// El n�mero de elementos de elementos de la secuencia es el valor
		// que se usa como "col_utilizadas"
		// PRE: primera_fila.TotalUtilizados() <= NUM_COLS
		/*******************************************************************/
		TablaRectangularReales(SecuenciaReales primera_fila)
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
		double Elemento(int fila, int columna) {
			
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
		//              "SecuenciaReales")
		// Recibe: �ndice de la fila a devolver (indice_fila)
		// Devuelve: Fila completa (un objeto "SecuenciaReales")
		// PRE: 0 <= indice_fila < filas_utilizadas
		/*******************************************************************/
		SecuenciaReales Fila(int indice_fila) {
			
			return ( vector_privado[indice_fila] );
		}

		/*******************************************************************/
		// M�todo: Columna()
		// Descripci�n: Devuelve una columna completa (un objeto 
		//              "SecuenciaReales")
		// Recibe: �ndice de la columna a devolver (indice_columna)
		// Devuelve: Columna completa (un objeto "SecuenciaReales")
		// PRE: 0 <= indice_columna < cols_utilizadas
		/*******************************************************************/	
		SecuenciaReales Columna(int indice_columna) {
			
			SecuenciaReales columna;
	
			for(int fil = 0; fil < filas_utilizadas; fil++)
				columna.Aniade( (vector_privado[fil]).Elemento
				                                            (indice_columna) );
	
			return columna;
		}

		/*******************************************************************/
		// M�todo: Aniade()
		// Descripci�n: A�ade una fila completa (un objeto "SecuenciaReales")
		//              al final de la tabla. 
		//              La adici�n se realiza si hay alguna fila disponible.
		//              Si no la hay, no se hace nada
		// Recibe: Nueva fila a a�adir al final de la tabla (fila_nueva)
		// Devuelve: -
		// PRE:  fila_nueva.TotalUtilizados() = cols_utilizadas
		// PRE:  filas_utilizadas < NUM_FILS
		/*******************************************************************/
		void Aniade(SecuenciaReales fila_nueva) {
			
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
		bool EsIgual(TablaRectangularReales otra_tabla) {
			
			bool son_iguales = true; 
			
			if ( ( filas_utilizadas != otra_tabla.FilasUtilizadas() ) ||  
				 ( cols_utilizadas != otra_tabla.ColumnasUtilizadas() ) )		
				
				son_iguales = false;
			else {
				
				// Recorrido por filas 
		
				int fil = 0;
				
				while(fil < filas_utilizadas && !son_iguales) {
		
					SecuenciaReales una_fila = Fila(fil);
					SecuenciaReales otra_fila = otra_tabla.Fila(fil);	
					
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
		TablaRectangularReales Traspuesta() {
				
		    TablaRectangularReales traspuesta; // Inicialmente vac�a
				    
			if( (filas_utilizadas <= NUM_COLS) && 
			    (cols_utilizadas <= NUM_FILS) ) {
			
				// La traspuesta tiene tantas filas como columnas tiene la 
				// matriz original
	
				TablaRectangularReales solucion(filas_utilizadas);
	
	
				SecuenciaReales columna; // Las filas de "traspuesta" ser�n las 
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
		// Descripci�n: Inserta una fila completa (un objeto "SecuenciaReales")
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
		void Inserta(int num_fila, SecuenciaReales fila_nueva) {
			
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
		// Descripci�n: Elimina una fila completa (un objeto "SecuenciaReales")
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
		bool Contiene(double buscado) {
			
			bool encontrado = false;

			// Recorrido por filas 
	
			int fil = 0;
	
			while(fil < filas_utilizadas  && !encontrado) {
	
				SecuenciaReales una_fila = Fila(fil);
				
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
		PosicionEnMatriz PrimeraOcurrencia(double buscado) {
			
			PosicionEnMatriz posicion_dato_buscado = {-1,-1};
	      
			bool encontrado = false;
	
			// Recorrido por filas 
	
			int fil = 0;
			
			while(fil < filas_utilizadas && !encontrado) {
	
				SecuenciaReales una_fila = Fila(fil);
				
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
};


/***************************************************************************/
// Clase TablaDentadaReales: representa una tabla dentada de n�meros reales
// Representaci�n: Secuencia de secuencias de n�meros reales
/***************************************************************************/
class TablaDentadaReales {
	
	private:

		static const int TAMANIO = 100; // N�mero de casillas disponibles
		SecuenciaReales vector_privado[TAMANIO];
		
		//PRE: 0 <= total_utilizados <= TAMANIO
		int total_utilizados;	// N�mero de casillas ocupadas

	public:

		/*******************************************************************/
		// Constructor sin argumentos (crea una matriz nula)
		/*******************************************************************/
		TablaDentadaReales() : total_utilizados(0) { }
		
		/*******************************************************************/
		// Constructor con argumentos
		// Recibe: Secuencia de n�meros reales que ser� la primera fila
		//         de la tabla
		/*******************************************************************/
		TablaDentadaReales(SecuenciaReales primera_fila) {
			
			vector_privado[0] = primera_fila;
			total_utilizados = 1;
		}

		/*******************************************************************/
		// M�todo: CapacidadFilas()
		// Descripci�n: Devuelve el n�mero m�ximo de filas
		// Recibe: -
		// Devuelve: N�mero m�ximo de filas (NUM_FILS)
		/*******************************************************************/
		int CapacidadFilas() {
			
			return TAMANIO;
		}

		/*******************************************************************/
		// M�todo: CapacidadColumnas()
		// Descripci�n: Devuelve el n�mero m�ximo de columnas
		// Recibe: -
		// Devuelve: N�mero m�ximo de columnas (NUM_COLS)
		/*******************************************************************/
		int CapacidadColumnas() {
			
			return ( SecuenciaReales().Capacidad() );
		}

		/*******************************************************************/
		// M�todo: FilasUtilizadas()
		// Descripci�n: Devuelve el n�mero de filas utilizadas
		// Recibe: -
		// Devuelve: N�mero de filas utilizadas (total_utilizados)
		/*******************************************************************/
		int FilasUtilizadas() {
			
			return total_utilizados;
		}

		/*******************************************************************/
		// M�todo: ColumnasUtilizadas()
		// Descripci�n: Devuelve el n�mero de columnas utilizadas en la fila
		//              "fila"
		// Recibe: Fila a devolver su n�mero de columnas (fila)
		// Devuelve: N�mero de columnas utilizadas en "fila"
		// PRE: 0 <= fila < filas_utilizadas
		/*******************************************************************/
		int ColumnasUtilizadas(int fila) {
			
			return ( vector_privado[fila].TotalUtilizados() );
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
		// PRE: 0 <= columna < num_cols_utilizadas[fila]	
		/*******************************************************************/
		double Elemento(int fila, int columna) {
			
			return ( vector_privado[fila].Elemento(columna) );
		}

		/*******************************************************************/
		// M�todo: EstaVacia()
		// Descripci�n: Comprueba si la tabla est� vac�a
		// Recibe: -
		// Devuelve: True (1) si la tabla est� vac�a y False (0) si no
		//           lo est�.
		/*******************************************************************/
		bool EstaVacia() {
			
			return (total_utilizados == 0);
		}
	
		/*******************************************************************/
		// M�todo: EliminaTodos()
		// Descripci�n: "Vac�a" completamente la tabla
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void EliminaTodos() {
			
			total_utilizados = 0;
		}

		/*******************************************************************/
		// M�todo: Fila()
		// Descripci�n: Devuelve una fila completa (un objeto 
		//              "SecuenciaReales")
		// Recibe: �ndice de la fila a devolver (indice_fila)
		// Devuelve: Fila completa (un objeto "SecuenciaReales")
		// PRE: 0 <= indice_fila < filas_utilizadas
		/*******************************************************************/
		SecuenciaReales Fila(int indice_fila) {
			
			return (vector_privado[indice_fila]);
		}

		/*******************************************************************/
		// M�todo: Aniade()
		// Descripci�n: A�ade una fila completa (un objeto "SecuenciaReales")
		//              al final de la tabla. 
		//              La adici�n se realiza si hay alguna fila disponible.
		//              Si no la hay, no se hace nada
		// Recibe: Nueva fila a a�adir al final de la tabla (fila_nueva)
		// Devuelve: -
		// PRE: total_utilizados < TAMANIO
		/*******************************************************************/
		void Aniade(SecuenciaReales fila_nueva) {
			
			if (total_utilizados < TAMANIO) {
	
				vector_privado[total_utilizados] = fila_nueva;			
				total_utilizados++;
			}
		}

		/*******************************************************************/
		// M�todo: EsIgual()
		// Descripci�n: Comprueba si dos tablas dentadas son iguales.
		//              Para ello, compara la tabla impl�cita con "otra_tabla"
		//              (tabla expl�cita)
		// Recibe: Tabla dentada de reales (otra_tabla)
		// Devuelve: True (1) si las dos tablas son iguales y False (0) si
		//           no lo son.
		/*******************************************************************/
		bool EsIgual(TablaDentadaReales otra_tabla) {
			
			bool son_iguales = true; 
		
			if( FilasUtilizadas() != otra_tabla.FilasUtilizadas() )
				son_iguales = false;
			else {
				
				int f = 0; 
				
				while(f < FilasUtilizadas() && son_iguales) {
					
					if( ColumnasUtilizadas(f) != 
					   otra_tabla.ColumnasUtilizadas(f) ) 
					
						son_iguales = false;	
					else {
						
						int c = 0; 
						
						while(c < ColumnasUtilizadas(f) && son_iguales) {
					
							if( Elemento(f,c) != otra_tabla.Elemento(f,c) ) 
								son_iguales = false;
								
							c++;
						}
			
						f++;
					}
				}
			} 
		
			return son_iguales;
		}

		/*******************************************************************/
		// M�todo: Inserta()
		// Descripci�n: Inserta una fila completa (un objeto "SecuenciaReales")
		//              en una posici�n dada
		// Recibe: Posici�n que ocupar� "fila_nueva" cuando se inserte en la
		//         tabla (num_fila),
		//         Fila a insertar (fila_nueva)
		// Devuelve: -
		// PRE:  filas_utilizadas < TAMANIO
		// PRE:  0 <= num_fila <= TotalUtilizados()
		//		 Si num_fila = 0, "nueva_fila" ser� la nueva primera fila. 
		//		 Si num_fila = TotalUtilizados(), "nueva_fila" ser� la nueva 
		//		 �ltima fila (el resultado ser� equivalente al de "Aniade()"  
		/*******************************************************************/
		void Inserta (int num_fila, SecuenciaReales fila_nueva) {
			
			// Comprobar precondiciones
			
			if( (total_utilizados < TAMANIO) && 
				(0 <= num_fila) && (num_fila <= total_utilizados) ) {
	
				// "Desplazar" las filas hacia posiciones altas. 
				// La �ltima fila se copia en una NUEVA FILA que ocupa la 
				// posici�n "filas_utilizadas", la pen�ltima se copia en 
				// "filas_utilizadas"-1, ... y se queda un "hueco" en 
				// la fila "num_fila ".
				// NOTA: no se modifica (todav�a) "filas_utilizadas" 
				
				for(int fil = total_utilizados; fil > num_fila; fil--) 
					vector_privado[fil] = vector_privado[fil-1]; 
					
				// Copiar en el "hueco" (fila "num_fila") el contenido de 
				// la secuencia "fila_nueva"
				
				vector_privado[num_fila] = fila_nueva;
							
				total_utilizados++; // Actualizaci�n del tama�o de la tabla.
						
			}
		}

		/*******************************************************************/
		// M�todo: Elimina()
		// Descripci�n: Elimina una fila completa (un objeto "SecuenciaReales")
		//              de una posici�n dada
		// Recibe: Posici�n de la fila a eliminar (num_fila)
		// Devuelve: -
		// PRE: 0 <= num_fila < total_utilizados 
		/*******************************************************************/	
		void Elimina(int num_fila) {
				
			// Recorremos de izquierda a derecha toda las componentes 
			// que hay a la derecha de la posici�n a eliminar
			// Le asignamos a cada componente la que hay a su derecha

			if( (num_fila >= 0) && (num_fila < total_utilizados) ) {
	
				int tope = total_utilizados-1; // posici�n del �ltimo 
	    
				for(int i = num_fila ; i < tope ; i++)
					vector_privado[i] = vector_privado[i+1];

				total_utilizados--;    
			}
		}

		/*******************************************************************/
		// M�todo: MenorNumeroDeColumnas()
		// Descripci�n: Calcula y devuelve el menor n�mero de columnas de
		//              la tabla 
		// Recibe: -
		// Devuelve: Menor n�mero de columnas de la tabla (menor_num_columnas)
		/*******************************************************************/
		int MenorNumeroDeColumnas() {
			
			int menor_num_columnas = ColumnasUtilizadas(0);
			
			
			for(int i = 1; i < FilasUtilizadas(); i++) {
				
				int num_columnas = ColumnasUtilizadas(i);
				
				if(num_columnas < menor_num_columnas)
					menor_num_columnas = num_columnas;
			}
			
			return menor_num_columnas;
		}
		
		/*******************************************************************/
		// M�todo: MenorTablaRectangularContenida()
		// Descripci�n: Calcula y devuelve la menor tabla rectangular
		//              contenida en la tabla dentada
		// Recibe: -
		// Devuelve: Menor tabla rectangular contenida en la tabla dentada
		//           (tabla_rectangular)
		/*******************************************************************/	
		TablaRectangularReales MenorTablaRectangularContenida() {
		
			TablaRectangularReales tabla_rectangular( MenorNumeroDeColumnas() );
			
			for(int i = 0; i < FilasUtilizadas(); i++) {
				
				SecuenciaReales fila;
				
				for(int j = 0; j < tabla_rectangular.ColumnasUtilizadas(); j++)
					fila.Aniade( Elemento(i, j) );
					
				tabla_rectangular.Aniade(fila);
				fila.EliminaTodos();	
			}
			
			return tabla_rectangular;
		}

		/*******************************************************************/
		// M�todo: ToString()
		// Descripci�n: Compone un string con todos los elementos que est�n
		//              almacenados en la tabla y lo devuelve
		// Recibe: Texto que etiqueta la escritura (titulo)
		// Devuelve: String con todos los elementos que est�n almacenados
		//           en la secuencia (cadena)
		/*******************************************************************/	
		string ToString(string titulo) {
			
			string cad; 
			
			cad = "\n" + titulo + "\n"; 	
			cad = cad + "\n --------------------------------------\n"; 
			
			for(int fila = 0; fila < total_utilizados; fila++) {
		
				SecuenciaReales la_secuencia = Fila(fila);
				
				int num_datos = la_secuencia.TotalUtilizados();
		
				cad = cad + " Fila " + to_string(fila); 
				cad = cad + " (" + to_string(num_datos) + " datos): "; 
				cad = cad + la_secuencia.ToString() + "\n";
			}
			
			cad = cad + " --------------------------------------\n"; 
			cad = cad + "\n\n";
			
			return cad; 
	}
};

/****************************************************************************/
// Funci�n principal
/****************************************************************************/
int main() {


	// Declaraci�n de constantes
	
	const int MAX_FILAS = 50;
	const int MAX_COLS = 50;
	
	// Declaraci�n de variables y objetos
	
	TablaDentadaReales tabla_dentada;
	SecuenciaReales una_fila;
		
	int numero_de_filas;
	int numero_de_elementos_por_fila;
	double elemento;
	
	// Entradas de datos

	// Tabla dentada de n�meros reales
	
	cout << " Tabla dentada: ";
	
	do {
		cin >> numero_de_filas;
	}while(numero_de_filas > MAX_FILAS);
	
	for(int i = 0; i < numero_de_filas; i++) {
		
		do {
			cin >> numero_de_elementos_por_fila;
		}while(numero_de_elementos_por_fila > MAX_COLS);
		
		for(int j = 0; j < numero_de_elementos_por_fila; j++) {
			cin >> elemento;
			una_fila.Aniade(elemento);
		}
		
		tabla_dentada.Aniade(una_fila);
		una_fila.EliminaTodos();
	}
	
	// Mostramos la tabla dentada introducida
	
	cout << tabla_dentada.ToString(" Tabla dentada introducida: "); 	
	
	// Menor tabla tectangular contenida en la tabla tentada
	
	TablaRectangularReales tabla_rectangular;
	
	tabla_rectangular = tabla_dentada.MenorTablaRectangularContenida();
	
	// Guardamos el n�mero de filas y columnas de "tabla_rectangular"
	
	int num_filas_tabla_rectangular = tabla_rectangular.FilasUtilizadas();
	int num_cols_tabla_rectangular = tabla_rectangular.ColumnasUtilizadas();
	
	// Mostramos la menor tabla tectangular contenida en la tabla tentada
	
	cout << endl;
	cout << " Menor tabla rectangular contenida en la tabla dentada"
	     << " introducida: " << endl;	
	cout << endl;
		
	for(int i = 0; i < num_filas_tabla_rectangular; i++) {

		for(int j = 0; j < num_cols_tabla_rectangular; j++)
			cout << setw(5) << tabla_rectangular.Elemento(i,j);	

		cout << endl;
	}
	cout << endl;
	
	return 0;	
}
