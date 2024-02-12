/*
	Relaci�n de ejercicios 5

	Ejercicio 35: Programa que, dada una secuencia de 10000 enteros aleatorios,
	              la ordenar� con los cuatro algoritmos de ordenaci�n
	              implementados en la clase SecuenciaEnteros y medir� el
	              tiempo empleado por cada uno de ellos haciendo uso de
	              la clase Cronometro.
	              
	Entradas: Secuencia de 10000 enteros aleatorios (sec_aleatoria).
	Salidas: Tiempo empleado por los diferentes algoritmos de ordenaci�n
	         para ordenar la secuencia (tiempo_ord_seleccion, 
			 tiempo_ord_insercion, tiempo_ord_intercambio,
	         tiempo_ord_intercambio_mejora).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <string>
#include <chrono>
#include <random>

using namespace std;

/***************************************************************************/
// Clase Cronometro:
/*
	Sirve para medir el tiempo de ejecuci�n de un conjunto de instrucciones.
	
	Hay que crear un objeto de esta clase y justo antes del conjunto de 
	instrucciones que queramos cronometrar, debemos ejecutar el 
	m�todo "Reset". Justo despu�s de las instrucciones que queremos 
	cronometrar llamaremos al m�todo "NanoSegundosTranscurridos" 
	(resp. "MiliSegundosTranscurridos") para saber el n�mero de nanosegundos 
	(resp. milisegundos) transcurridos. 
	
	El cron�metro seguir� en marcha (por lo que podremos llamar al m�todo 
	"NanoSegundosTranscurridos"  tantas veces como queramos) hasta reiniciar 
	el cron�metro (m�todo "Reset").
*/
/***************************************************************************/
class Cronometro {
	
	private:
		
	   typedef std::chrono::time_point<std::chrono::steady_clock>
	           Punto_en_el_Tiempo;
	   typedef chrono::duration <double, nano> IntervaloTiempo;
	
	   Punto_en_el_Tiempo inicio;
	   Punto_en_el_Tiempo final;

	public:
	
		/*******************************************************************/
		void Reset() { 
			inicio = chrono::steady_clock::now();
		}
		
		/*******************************************************************/
		double NanoSegundosTranscurridos() {
			final = chrono::steady_clock::now();		
			IntervaloTiempo diferencia = final - inicio;
			return (diferencia.count());
		}
		
		/*******************************************************************/
		double MiliSegundosTranscurridos() {
			final = chrono::steady_clock::now();		
			IntervaloTiempo diferencia = final - inicio;
			return (diferencia.count()/1e6);
		}
};

/***************************************************************************/
// Clase GeneradorAleatorioEnteros:
/*
	Sirve para generar n�meros aleatorios enteros en un rango de valores.
	
	Hay que crear un objeto de esta clase. Se dispone de dos constructores: 
	
	1) GeneradorAleatorioEnteros()
	   		El primero no tiene par�metros y establece que �nicamente se 
			van a generar ceros y unos (este constructor llama al segundo). 
			
	2) GeneradorAleatorioEnteros(int min, int max)
		El segundo tiene dos par�metros, "min" y "max" que delimitan el 
		rango correspondiente. 

	Finalmente, el m�todo 
	
		int Siguiente()
	
	devolver� un valor aleatorio en el rango especificado en el constructor.
*/
/***************************************************************************/
class GeneradorAleatorioEnteros {  
	
	private:
	
		mt19937 generador_mersenne;    // Mersenne twister
		uniform_int_distribution<int>  distribucion_uniforme;
		
		/*******************************************************************/
		long long Nanosec() {
			return (chrono::high_resolution_clock
			              ::now().time_since_epoch().count());
		}
	
	public:
	
		/*******************************************************************/
		GeneradorAleatorioEnteros() : GeneradorAleatorioEnteros(0, 1) { }
		
		/*******************************************************************/
		GeneradorAleatorioEnteros(int min, int max) {
		
			const int A_DESCARTAR = 70000;
			// ACM TOMS Volume 32 Issue 1, March 2006
			
			auto semilla = Nanosec();
			generador_mersenne.seed(semilla);
			generador_mersenne.discard(A_DESCARTAR);
			distribucion_uniforme = uniform_int_distribution<int> (min, max);
		}
	
		/*******************************************************************/
		int Siguiente() {
		  return (distribucion_uniforme(generador_mersenne));
		}
};

/***************************************************************************/
// Clase SecuenciaEnteros: representa una secuencia de enteros
/***************************************************************************/
class SecuenciaEnteros {
	
	private:
		
		static const int TAMANIO = 10000;   // N�mero de casillas disponibles
		int vector_privado[TAMANIO];

		// PRE: 0 <= total_utilizados <= TAMANIO
		int total_utilizados;           	// N�mero de casillas ocupadas

		/*******************************************************************/
		// M�todo: IntercambiaComponentesEnPosiciones()
		// Descripci�n: Intercambia las componentes situadas en las casillas
		//              "pos_izda" y "pos_dcha" de la secuencia
		// Recibe: �ndice de las casillas de la secuencia a intercambia
		//         (pos_izda, pos_dcha)
		// Devuelve: -
		/*******************************************************************/
		void IntercambiaComponentesEnPosiciones(int pos_izda, int pos_dcha) {
			
			int intercambia;
			
			intercambia = vector_privado[pos_izda];
			vector_privado[pos_izda] = vector_privado[pos_dcha];
			vector_privado[pos_dcha] = intercambia;
		}
		
	public:
				
		/*******************************************************************/
		// Constructor sin par�metros
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
		void Aniade(int nuevo) {
			
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
		void Modifica(int indice, int nuevo) {
			
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
		// Descripci�n: Inserta el n�mero entero "nuevo" en la posici�n dada +
		//              por "indice". Desplaza todos los n�meros enteros
		//              una posici�n a la derecha antes de copiar en "indice" 
		//              el valor "nuevo"
		// Recibe: �ndice de la casilla del elemento a insertar (indice),
		//         Valor del elemento a insertar (valor_nuevo)
		// Devuelve: -
		// PRE: 0 <= indice < total_utilizados
		/*******************************************************************/
		void Inserta(int indice, int valor_nuevo) {
			
			if( (total_utilizados < TAMANIO) && (indice >= 0) && 
			     (indice < total_utilizados) ) {
		
				for(int i = total_utilizados ; i > indice ; i--)
					vector_privado[i] = vector_privado[i-1];
		
				vector_privado[indice] = valor_nuevo;
				total_utilizados++;
			}
		}
				
		/*******************************************************************/
		// M�todo: PosicionMinimoEntre()
		// Descripci�n: Devuelve la posici�n en la secuencia del elemento
		//              m�nimo que se encuentre entre "izda" y "dcha"
		// Recibe: Extremos del rango de casillas en las cuales queremos 
		//         encontrar la posici�n del elemento m�nimo (izda, dcha).
		// Devuelve: Posici�n en la secuencia del elemento m�nimo 
		//           situado entre "izda" y "dcha" (posicion_minimo)
		// PRE: 0 <= izda <= dcha < total_utilizados
		/*******************************************************************/
		int PosicionMinimoEntre(int izda, int dcha){
			
			int posicion_minimo = -1;
			int minimo;
			
			minimo = vector_privado[izda];
			posicion_minimo = izda;
		
			for(int i = izda+1; i <= dcha; i++)
				if(vector_privado[i] < minimo) {
					minimo = vector_privado[i];
					posicion_minimo = i;
				}
			
			return posicion_minimo;
		}
		
		/*******************************************************************/
		// M�todo: OrdenaSeleccion()
		// Descripci�n: Ordena la secuencia de enteros mediante el algoritmo
		//              de ordenaci�n por selecci�n
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void OrdenaSeleccion() {
			
			int pos_min;
			
			for(int izda = 0; izda < total_utilizados; izda++){
				pos_min = PosicionMinimoEntre(izda, total_utilizados-1);
				IntercambiaComponentesEnPosiciones(izda, pos_min);
			}
		}
		
		/*******************************************************************/
		// M�todo: OrdenaInsercion()
		// Descripci�n: Ordena la secuencia de enteros mediante el algoritmo
		//              de ordenaci�n por inserci�n
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void OrdenaInsercion() {
		
			int izda, i;
			int a_desplazar;

			for(izda = 1; izda < total_utilizados; izda++) {
				a_desplazar = vector_privado[izda];
	
				for(i = izda; i > 0 && a_desplazar < vector_privado[i-1]; i--)
					vector_privado[i] = vector_privado[i-1];
			
				vector_privado[i] = a_desplazar;
			}
		}
		
		/*******************************************************************/
		// M�todo: OrdenaIntercambio()
		// Descripci�n: Ordena la secuencia de enteros mediante una primera
		//              aproximaci�n del algoritmo de ordenaci�n por burbuja
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void OrdenaIntercambio() {
		
			int izda, i;
			
			for(izda = 0; izda < total_utilizados; izda++)
				for(i = total_utilizados-1 ; i > izda ; i--)
					if(vector_privado[i] < vector_privado[i-1])
						IntercambiaComponentesEnPosiciones(i, i-1);
		}
		
		/*******************************************************************/
		// M�todo: OrdenaIntercambioMejora()
		// Descripci�n: Ordena la secuencia de enteros mediante una segunda
		//              aproximaci�n del algoritmo de ordenaci�n por burbuja
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void OrdenaIntercambioMejora() {
			
			int izda, i;
			bool cambio;

			cambio = true;
			
			for(izda = 0; izda < total_utilizados && cambio; izda++) {
				
				cambio = false;
				
				for(i = total_utilizados-1; i > izda; i--)
					if(vector_privado[i] < vector_privado[i-1]) {
						IntercambiaComponentesEnPosiciones(i, i-1);
						cambio = true;
					}
			}
		}
		
		/*******************************************************************/
		// M�todo: ToString()
		// Descripci�n: Compone un string con todos los enteros que est�n
		//              almacenados en la secuencia y lo devuelve.
		// Recibe: -
		// Devuelve: String con todos los car�cteres que est�n almacenados
		//           en la secuencia (cadena)
		/*******************************************************************/
		string ToString() {
			
	    	string cadena;

        	for (int i=0; i<total_utilizados; i++)
            	cadena = cadena + to_string(vector_privado[i]) + " ";

        	return cadena;
    	}
};

/***************************************************************************/
// Funci�n principal
/***************************************************************************/
int main() {
		
	// Declaraci�n de variables y objetos
	
	Cronometro cronometro;
	
	GeneradorAleatorioEnteros generador_enteros_aleatorios(0, 10000);
	
	SecuenciaEnteros sec_aleatoria, sec_aleatoria_copia;
	
	int tiempo_ord_seleccion, tiempo_ord_insercion, tiempo_ord_intercambio,
	    tiempo_ord_intercambio_mejora;
	
	// C�lculos
	
	// Generar una secuencia de 10000 n�meros aleatorios comprendidos entre
	// 0 y 10000
	
	for(int i = 0; i < sec_aleatoria.Capacidad(); i++)
		sec_aleatoria.Aniade( generador_enteros_aleatorios.Siguiente() );
	
	// Hacemos una copia de la secuencia aleatoria generada
	
	sec_aleatoria_copia = sec_aleatoria;
	
	// Ordenar la secuencia mediante el algoritmo de ordenaci�n por selecci�n
	
	cronometro.Reset();
	
	sec_aleatoria.OrdenaSeleccion();
	
	tiempo_ord_seleccion = cronometro.MiliSegundosTranscurridos();
	
	// Asignar a la secuencia aleatoria ordenada la secuencia aleatoria
	// original, es decir, sin ordenar
	
	sec_aleatoria = sec_aleatoria_copia;
	
	// Ordenar la secuencia mediante el algoritmo de ordenaci�n por inserci�n
	
	cronometro.Reset();

	sec_aleatoria.OrdenaInsercion();
	
	tiempo_ord_insercion = cronometro.MiliSegundosTranscurridos();
	
	// Asignar a la secuencia aleatoria ordenada la secuencia aleatoria
	// original, es decir, sin ordenar
	
	sec_aleatoria = sec_aleatoria_copia;
	
	// Ordenar la secuencia mediante la primera aproximaci�n del algoritmo de 
	// ordenaci�n por burbuja
	
	cronometro.Reset();

	sec_aleatoria.OrdenaIntercambio();

	tiempo_ord_intercambio = cronometro.MiliSegundosTranscurridos();
	
	// Asignar a la secuencia aleatoria ordenada la secuencia aleatoria
	// original, es decir, sin ordenar
	
	sec_aleatoria = sec_aleatoria_copia;
	
	// Ordenar la secuencia mediante la segunda aproximaci�n del algoritmo de 
	// ordenaci�n por burbuja

	cronometro.Reset();

	sec_aleatoria.OrdenaIntercambioMejora();
	
	tiempo_ord_intercambio_mejora = cronometro.MiliSegundosTranscurridos();
	
	// Salidas
	
	cout << " Milisegundos transcurridos en la ejecucion de cada algoritmo"
	     << " de ordenacion: ";
	cout << endl << endl;
	cout << "\t Ordenacion por seleccion: " << tiempo_ord_seleccion;
	cout << endl;
	cout << "\t Ordenacion por insercion: " << tiempo_ord_insercion;
	cout << endl;
	cout << "\t Ordenacion por burbuja (primera aproximacion): " 
	     << tiempo_ord_intercambio;
	cout << endl;
	cout << "\t Ordenacion por burbuja (segunda aproximacion): " 
	     << tiempo_ord_intercambio_mejora;
	cout << endl << endl;
	
	cout << " Se puede apreciar que el algoritmo mas eficiente es el"
	     << " algoritmo de ordenacion por insercion";
	cout << endl << endl;

	return 0;
}
