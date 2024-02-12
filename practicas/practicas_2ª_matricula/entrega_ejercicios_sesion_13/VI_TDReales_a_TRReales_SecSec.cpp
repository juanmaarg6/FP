/*
	Relación de ejercicios 6

	Ejercicio 52:	
	
	Escribir un método de la clase TablaDentadaReales (con secuencia de 
	secuencias) que devuelva un objeto TablaRectangularReales (con secuencia 
	de secuencias).

	El objeto devuelto tendrá tantas filas como tenga el objeto implícito, y 
	tantas columnas como columnas tenga la fila con menos columnas del objeto 
	implícito.

	Entradas: Tabla dentada de números reales (tabla_dentada).
	Salidas: Menor tabla rectangular de números reales contenida en
	         la tabla dentada de números reales (tabla_rectangular).
			 		 
	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

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
		int Posicion(double buscado, int izda, int dcha) {
			
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
		SecuenciaReales Subsecuencia(int pos_init, int num_datos) {
			
			SecuenciaReales a_devolver; // inicialmente vacía
			
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
		// Descripción: Comprueba si dos secuencias de reales son iguales.
		//              Para ello, compara la secuencia implícita con 
		//              "otra_secuencia" (secuencia explícita)
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
// Clase TablaRectangularReales: representa una tabla rectangular de 
//                               números reales
// Representación: Secuencia de secuencias de números reales
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
		// Recibe: Número de columnas que deben tener todas las filas
		//         (numero_de_columnas)
		// PRE: numero_de_columnas <= NUM_COLS
		/*******************************************************************/
		TablaRectangularReales(int numero_de_columnas) 
		              : filas_utilizadas(0), 
					    cols_utilizadas(numero_de_columnas) { }

		/*******************************************************************/
		// Constructor con argumentos
		// Recibe: Secuencia de números reales que será la primera fila
		//         de la tabla
		// El número de elementos de elementos de la secuencia es el valor
		// que se usa como "col_utilizadas"
		// PRE: primera_fila.TotalUtilizados() <= NUM_COLS
		/*******************************************************************/
		TablaRectangularReales(SecuenciaReales primera_fila)
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
		//              "SecuenciaReales")
		// Recibe: Índice de la fila a devolver (indice_fila)
		// Devuelve: Fila completa (un objeto "SecuenciaReales")
		// PRE: 0 <= indice_fila < filas_utilizadas
		/*******************************************************************/
		SecuenciaReales Fila(int indice_fila) {
			
			return ( vector_privado[indice_fila] );
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
				columna.Aniade( (vector_privado[fil]).Elemento
				                                            (indice_columna) );
	
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
		// Método: Traspuesta()
		// Descripción: Devuelve la traspuesta de la tabla rectangular (si
		//              es posible calcularse). Si no se puede calcular la
		//              traspuesta, se devuelve una matriz nula.
		// Recibe: -
		// Devuelve: Traspuesta de la tabla rectangular (traspuesta)
		// PRE: filas_utilizadas <= NUM_COLS
		// PRE: cols_utilizadas  <= NUM_FILS
		/*******************************************************************/
		TablaRectangularReales Traspuesta() {
				
		    TablaRectangularReales traspuesta; // Inicialmente vacía
				    
			if( (filas_utilizadas <= NUM_COLS) && 
			    (cols_utilizadas <= NUM_FILS) ) {
			
				// La traspuesta tiene tantas filas como columnas tiene la 
				// matriz original
	
				TablaRectangularReales solucion(filas_utilizadas);
	
	
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
		// Descripción: Inserta una fila completa (un objeto "SecuenciaReales")
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
// Clase TablaDentadaReales: representa una tabla dentada de números reales
// Representación: Secuencia de secuencias de números reales
/***************************************************************************/
class TablaDentadaReales {
	
	private:

		static const int TAMANIO = 100; // Número de casillas disponibles
		SecuenciaReales vector_privado[TAMANIO];
		
		//PRE: 0 <= total_utilizados <= TAMANIO
		int total_utilizados;	// Número de casillas ocupadas

	public:

		/*******************************************************************/
		// Constructor sin argumentos (crea una matriz nula)
		/*******************************************************************/
		TablaDentadaReales() : total_utilizados(0) { }
		
		/*******************************************************************/
		// Constructor con argumentos
		// Recibe: Secuencia de números reales que será la primera fila
		//         de la tabla
		/*******************************************************************/
		TablaDentadaReales(SecuenciaReales primera_fila) {
			
			vector_privado[0] = primera_fila;
			total_utilizados = 1;
		}

		/*******************************************************************/
		// Método: CapacidadFilas()
		// Descripción: Devuelve el número máximo de filas
		// Recibe: -
		// Devuelve: Número máximo de filas (NUM_FILS)
		/*******************************************************************/
		int CapacidadFilas() {
			
			return TAMANIO;
		}

		/*******************************************************************/
		// Método: CapacidadColumnas()
		// Descripción: Devuelve el número máximo de columnas
		// Recibe: -
		// Devuelve: Número máximo de columnas (NUM_COLS)
		/*******************************************************************/
		int CapacidadColumnas() {
			
			return ( SecuenciaReales().Capacidad() );
		}

		/*******************************************************************/
		// Método: FilasUtilizadas()
		// Descripción: Devuelve el número de filas utilizadas
		// Recibe: -
		// Devuelve: Número de filas utilizadas (total_utilizados)
		/*******************************************************************/
		int FilasUtilizadas() {
			
			return total_utilizados;
		}

		/*******************************************************************/
		// Método: ColumnasUtilizadas()
		// Descripción: Devuelve el número de columnas utilizadas en la fila
		//              "fila"
		// Recibe: Fila a devolver su número de columnas (fila)
		// Devuelve: Número de columnas utilizadas en "fila"
		// PRE: 0 <= fila < filas_utilizadas
		/*******************************************************************/
		int ColumnasUtilizadas(int fila) {
			
			return ( vector_privado[fila].TotalUtilizados() );
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
		// PRE: 0 <= columna < num_cols_utilizadas[fila]	
		/*******************************************************************/
		double Elemento(int fila, int columna) {
			
			return ( vector_privado[fila].Elemento(columna) );
		}

		/*******************************************************************/
		// Método: EstaVacia()
		// Descripción: Comprueba si la tabla está vacía
		// Recibe: -
		// Devuelve: True (1) si la tabla está vacía y False (0) si no
		//           lo está.
		/*******************************************************************/
		bool EstaVacia() {
			
			return (total_utilizados == 0);
		}
	
		/*******************************************************************/
		// Método: EliminaTodos()
		// Descripción: "Vacía" completamente la tabla
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void EliminaTodos() {
			
			total_utilizados = 0;
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
			
			return (vector_privado[indice_fila]);
		}

		/*******************************************************************/
		// Método: Aniade()
		// Descripción: Añade una fila completa (un objeto "SecuenciaReales")
		//              al final de la tabla. 
		//              La adición se realiza si hay alguna fila disponible.
		//              Si no la hay, no se hace nada
		// Recibe: Nueva fila a añadir al final de la tabla (fila_nueva)
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
		// Método: EsIgual()
		// Descripción: Comprueba si dos tablas dentadas son iguales.
		//              Para ello, compara la tabla implícita con "otra_tabla"
		//              (tabla explícita)
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
		// Método: Inserta()
		// Descripción: Inserta una fila completa (un objeto "SecuenciaReales")
		//              en una posición dada
		// Recibe: Posición que ocupará "fila_nueva" cuando se inserte en la
		//         tabla (num_fila),
		//         Fila a insertar (fila_nueva)
		// Devuelve: -
		// PRE:  filas_utilizadas < TAMANIO
		// PRE:  0 <= num_fila <= TotalUtilizados()
		//		 Si num_fila = 0, "nueva_fila" será la nueva primera fila. 
		//		 Si num_fila = TotalUtilizados(), "nueva_fila" será la nueva 
		//		 última fila (el resultado será equivalente al de "Aniade()"  
		/*******************************************************************/
		void Inserta (int num_fila, SecuenciaReales fila_nueva) {
			
			// Comprobar precondiciones
			
			if( (total_utilizados < TAMANIO) && 
				(0 <= num_fila) && (num_fila <= total_utilizados) ) {
	
				// "Desplazar" las filas hacia posiciones altas. 
				// La última fila se copia en una NUEVA FILA que ocupa la 
				// posición "filas_utilizadas", la penúltima se copia en 
				// "filas_utilizadas"-1, ... y se queda un "hueco" en 
				// la fila "num_fila ".
				// NOTA: no se modifica (todavía) "filas_utilizadas" 
				
				for(int fil = total_utilizados; fil > num_fila; fil--) 
					vector_privado[fil] = vector_privado[fil-1]; 
					
				// Copiar en el "hueco" (fila "num_fila") el contenido de 
				// la secuencia "fila_nueva"
				
				vector_privado[num_fila] = fila_nueva;
							
				total_utilizados++; // Actualización del tamaño de la tabla.
						
			}
		}

		/*******************************************************************/
		// Método: Elimina()
		// Descripción: Elimina una fila completa (un objeto "SecuenciaReales")
		//              de una posición dada
		// Recibe: Posición de la fila a eliminar (num_fila)
		// Devuelve: -
		// PRE: 0 <= num_fila < total_utilizados 
		/*******************************************************************/	
		void Elimina(int num_fila) {
				
			// Recorremos de izquierda a derecha toda las componentes 
			// que hay a la derecha de la posición a eliminar
			// Le asignamos a cada componente la que hay a su derecha

			if( (num_fila >= 0) && (num_fila < total_utilizados) ) {
	
				int tope = total_utilizados-1; // posición del último 
	    
				for(int i = num_fila ; i < tope ; i++)
					vector_privado[i] = vector_privado[i+1];

				total_utilizados--;    
			}
		}

		/*******************************************************************/
		// Método: MenorNumeroDeColumnas()
		// Descripción: Calcula y devuelve el menor número de columnas de
		//              la tabla 
		// Recibe: -
		// Devuelve: Menor número de columnas de la tabla (menor_num_columnas)
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
		// Método: MenorTablaRectangularContenida()
		// Descripción: Calcula y devuelve la menor tabla rectangular
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
		// Método: ToString()
		// Descripción: Compone un string con todos los elementos que están
		//              almacenados en la tabla y lo devuelve
		// Recibe: Texto que etiqueta la escritura (titulo)
		// Devuelve: String con todos los elementos que están almacenados
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
// Función principal
/****************************************************************************/
int main() {


	// Declaración de constantes
	
	const int MAX_FILAS = 50;
	const int MAX_COLS = 50;
	
	// Declaración de variables y objetos
	
	TablaDentadaReales tabla_dentada;
	SecuenciaReales una_fila;
		
	int numero_de_filas;
	int numero_de_elementos_por_fila;
	double elemento;
	
	// Entradas de datos

	// Tabla dentada de números reales
	
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
	
	// Guardamos el número de filas y columnas de "tabla_rectangular"
	
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
