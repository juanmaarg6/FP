/*
	Relaci�n de ejercicios 6

	Ejercicio 51:	
	
	Reescribir el ejercicio 42 de esta misma Relaci�n de Problemas, usando 
	como estructura de datos para almacenar la tabla dentada una secuencia de 
	secuencias de datos double.

	Entradas: Tabla dentada de n�meros reales (matriz).
	Salidas: Sumas de los valores de cada fila de la tabla 
	         (suma_valores_cada_grupo).
			 		 
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
		// M�todo: SumaDeCadaFila()
		// Descripci�n: Suma los valores de cada fila de la tabla
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
	
	TablaDentadaReales matriz;
	SecuenciaReales una_fila;
		
	int numero_de_grupos;
	int numero_elementos_del_grupo;
	double elemento;
	
	// Entradas de datos

	// Tabla dentada de n�meros reales
	
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
