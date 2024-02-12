/*
	Relación de ejercicios 6

	Ejercicio 42:	
	
	Se desea crear una matriz dentada de valores reales leyendo sus valores 
	de la entrada estándar y realizar algunos cálculos con ella.

	Todos los valores necesarios (número de grupos, número de datos de cada 
	grupo y los valores de cada grupo) se introducen en una sola línea.

	Por ejemplo, una línea de entrada podría ser la siguiente:
		
		3 2 3.1 0.4 5 1.0 1.0 1.0 1.0 1.0 2 5.2 4.7

	Se puede observar que se distinguen tres grupos de datos (lo indica el 
	primer número (int) de la línea). Cada grupo empieza por un valor (int) 
	que indica el número de elementos que lo componen (en el ejemplo, los 
	grupos tienen dos, cinco y dos elementos, respectivamente). A continuación 
	de este valor se encentran tantos valores (double) como indique el valor 
	entero que encabeza cada grupo.

	En el ejemplo, el primer grupo contendrá los valores 3.1 y 0.4, el segundo 
	1.0, 1.0, 1.0, 1.0 y 1.0 y el tercero 5.2 y 4.7.

	Escribir un programa que escriba en la salida estándar la suma de los 
	valores de cada grupo.

	Por ejemplo, en el caso anterior, debería escribir: 3.5, 5.0 y 9.9

	Implementar la clase TablaDentadaReales usando como dato privado una matriz
	clásica de datos double.

	Entradas: Tabla dentada de números reales (matriz).
	Salidas: Sumas de los valores de cada fila de la tabla 
	         (suma_valores_cada_grupo).
			 		 
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
// Clase TablaDentadaReales: representa una tabla dentada de números reales
// Representación: Matriz "clásica"
/***************************************************************************/
class TablaDentadaReales {
	
	private:

	    static const int NUM_FILS = 50;  // Filas disponibles
	    static const int NUM_COLS = 40;  // Columnas disponibles
	
	    double matriz_privada[NUM_FILS][NUM_COLS];
	
	    // PRE: 0 <= filas_utilizadas <= NUM_FILS
	
	    int filas_utilizadas;
	
	    // PRE: 0 <= num_cols_utilizadas[i] <= NUM_COLS
	    //      para i=0,1,...,filas_utilizadas-1
	    // Número de columnas ocupadas en cada fila
	
	    int num_cols_utilizadas[NUM_FILS] = {0};

	public:

		/*******************************************************************/
		// Constructor sin argumentos (crea una matriz nula)
		/*******************************************************************/
		TablaDentadaReales() : filas_utilizadas(0) { }

		/*******************************************************************/
		// Constructor con argumentos
		// Recibe: Secuencia de números reales que será la primera fila
		//         de la tabla
		/*******************************************************************/
		TablaDentadaReales(SecuenciaReales primera_fila) : filas_utilizadas(0) {
			
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
		// Descripción: Devuelve el número de columnas utilizadas en la fila
		//              "fila"
		// Recibe: Fila a devolver su número de columnas (fila)
		// Devuelve: Número de columnas utilizadas en "fila"
		// PRE: 0 <= fila < filas_utilizadas
		/*******************************************************************/
		int ColumnasUtilizadas(int fila) {
			
			return ( num_cols_utilizadas[fila] );
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
		// Método: EliminaTodos()
		// Descripción: "Vacía" completamente la tabla
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void EliminaTodos() {
			
			filas_utilizadas = 0;
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
			
			SecuenciaReales la_fila;
					
			int num_columnas = num_cols_utilizadas[indice_fila];
				
			for(int c = 0; c < num_columnas; c++) 
				la_fila.Aniade( matriz_privada[indice_fila][c] );
			
			return la_fila;
		}

		/*******************************************************************/
		// Método: Aniade()
		// Descripción: Añade una fila completa (un objeto "SecuenciaReales")
		//              al final de la tabla. 
		//              La adición se realiza si hay alguna fila disponible.
		//              Si no la hay, no se hace nada
		// Recibe: Nueva fila a añadir al final de la tabla (fila_nueva)
		// Devuelve: -
		// PRE:  fila_nueva.TotalUtilizados() <= NUM_COLS
		// PRE:  filas_utilizadas < NUM_FILS
		/*******************************************************************/
		void Aniade(SecuenciaReales fila_nueva) {
			
			int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
						
			if( (filas_utilizadas < NUM_FILS) &&
				(numero_columnas_fila_nueva <= NUM_COLS) ) {
	
				for(int c = 0; c < numero_columnas_fila_nueva; c++) 
					matriz_privada[filas_utilizadas][c] = 
					                                    fila_nueva.Elemento(c);
	
				num_cols_utilizadas[filas_utilizadas] = 
				                                    numero_columnas_fila_nueva;
				
				filas_utilizadas++;
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
			
			if( filas_utilizadas != otra_tabla.FilasUtilizadas() )
				son_iguales = false;
			else {
				
				int f = 0; 
				
				while(f < filas_utilizadas && son_iguales) {
					
					if(num_cols_utilizadas[f] != 
					   otra_tabla.ColumnasUtilizadas(f) ) 
					
						son_iguales = false;	
					else {
						
						int c = 0; 
						
						while(c < num_cols_utilizadas[f] && son_iguales) {
					
							if( matriz_privada[f][c] != 
							    otra_tabla.Elemento(f,c) ) 
							    
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
		// PRE:  fila_nueva.TotalUtilizados() <= NUM_COLS
		// PRE:  filas_utilizadas <= NUM_FILS
		// PRE:  0 <= num_fila <= TotalUtilizados()
		//		 Si num_fila = 0, "nueva_fila" será la nueva primera fila. 
		//		 Si num_fila = TotalUtilizados(), "nueva_fila" será la nueva 
		//		 última fila (el resultado será equivalente al de "Aniade()"  
		/*******************************************************************/
		void Inserta (int num_fila, SecuenciaReales fila_nueva) {
			
			int numero_columnas_fila_nueva = fila_nueva.TotalUtilizados();
					
			// Comprobar precondiciones
		
			if( (filas_utilizadas < NUM_FILS) &&
			    (numero_columnas_fila_nueva <= NUM_COLS) &&
			    (0<=num_fila) && (num_fila <=filas_utilizadas) ) {

				// "Desplazar" las filas hacia posiciones altas. 
				// La última fila se copia en una NUEVA FILA que ocupa la 
				// posición "filas_utilizadas", la penúltima se copia en 
				// "filas_utilizadas"-1, ... y se queda un "hueco" en 
				// la fila "num_fila ".
				// NOTA: no se modifica (todavía) "filas_utilizadas" 
			
				for(int fil = filas_utilizadas; fil > num_fila; fil--) {	
				
					int num_columnas = num_cols_utilizadas[fil-1];
						
					for(int c = 0; c < num_columnas; c++) 
						matriz_privada[fil][c] = matriz_privada[fil-1][c]; 
						
					num_cols_utilizadas[fil] = num_cols_utilizadas[fil-1];
				}
					
				// Copiar en el "hueco" (fila "num_fila") el contenido de 
				// la secuencia "fila_nueva"
			
				for(int c = 0; c < numero_columnas_fila_nueva; c++) 
					matriz_privada[num_fila][c] = fila_nueva.Elemento(c);
			
				num_cols_utilizadas[num_fila] = numero_columnas_fila_nueva;
			
				filas_utilizadas++; // Actualización del tamaño de la tabla.
			}
		}

		/*******************************************************************/
		// Método: Elimina()
		// Descripción: Elimina una fila completa (un objeto "SecuenciaReales")
		//              de una posición dada
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
				
					int num_columnas = num_cols_utilizadas[fil+1];
						
					for(int c = 0; c < num_columnas; c++) 
						matriz_privada[fil][c] = matriz_privada[fil+1][c];
						
					num_cols_utilizadas[fil] = num_cols_utilizadas[fil+1];
				}
			
				filas_utilizadas--; // Actualización del tamaño de la tabla.
			}
		}

		/*******************************************************************/
		// Método: SumaDeCadaFila()
		// Descripción: Suma los valores de cada fila de la tabla
		// Recibe: -
		// Devuelve: Sumas de los valores de cada fila de la tabla almacenadas
		//           en un objeto "SecuenciaReales" (suma_cada_fila)
		/*******************************************************************/
		SecuenciaReales SumaDeCadaFila() {
			
			SecuenciaReales suma_cada_fila;
			
			
			for(int i = 0; i < FilasUtilizadas(); i++) {
				
				double suma = 0.0;
	
				for(int j = 0; j < ColumnasUtilizadas(i); j++) 
					suma += Elemento(i, j);
								
				suma_cada_fila.Aniade(suma);
			}
			
			return suma_cada_fila;
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
			
			for(int fila = 0; fila < filas_utilizadas; fila++) {
		
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
	
	TablaDentadaReales matriz;
	SecuenciaReales una_fila;
		
	int numero_de_grupos;
	int numero_elementos_del_grupo;
	double elemento;
	
	// Entradas de datos

	// Tabla dentada de números reales
	
	cout << " Tabla dentada: ";
	
	do {
		cin >> numero_de_grupos;
	}while(numero_de_grupos > MAX_FILAS);
	
	for(int i = 0; i < numero_de_grupos; i++) {
		
		do {
			cin >> numero_elementos_del_grupo;
		}while(numero_elementos_del_grupo > MAX_COLS);
		
		for(int j = 0; j < numero_elementos_del_grupo; j++) {
			cin >> elemento;
			una_fila.Aniade(elemento);
		}
		
		matriz.Aniade(una_fila);
		una_fila.EliminaTodos();
	}
	
	// Mostramos la tabla dentada introducida
	
	cout << matriz.ToString(" Tabla dentada introducida: "); 	
	
	// Calculamos las sumas de los valores de cada grupo
	
	SecuenciaReales suma_valores_cada_grupo;
	
	suma_valores_cada_grupo = matriz.SumaDeCadaFila();
	
	// Mostramos las sumas de los valores de cada grupo
	
	cout << " Suma de los valores de cada fila de la tabla: "
	     << suma_valores_cada_grupo.ToString();
	cout << endl << endl;
	
	return 0;	
}
