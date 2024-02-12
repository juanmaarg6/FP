/*
	Relación de ejercicios 6

	Ejercicio 25:	Consideramos la clase ColeccionPuntos2D que usaremos para 
	                almacenar y gestionar una colección de datos de tipo 
					Punto2D.

					Realizamos un programa que lea del teclado un número 
					indeterminado de datos de tipo Punto2D de manera que 
					termine la lectura si el usuario escribe FIN cuando el 
					programa le pide la abscisa de un nuevo punto. Los puntos 
					leídos los almacena en un objeto ColeccionPuntos2D.

					A continuación pide los datos necesarios, y crea un objeto 
					Circunferencia, y finalmente muestra cuáles de los puntos 
					almacenados en la colección ColeccionPuntos2D está en el 
					círculo delimitado por la circunferencia.
	              
	Entradas: Colección de Puntos2D (coleccion_puntos2d),
	          Circunferencia (circunferencia).
	Salidas: Comprobación de si cada punto de "coleccion_puntos2d"
	         pertenece a "circunferencia" o no.
			 
	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <cctype>
#include <cmath>
#include <iomanip>

using namespace std;


/***************************************************************************/
const double PRECISION_SON_IGUALES = 1e-6; // 0.000001
/***************************************************************************/

/***************************************************************************/
// Función: SonIguales()
// Descripción: Función global (asociada a la constante PRECISION_SON_IGUALES)
//              que permite que dos números reales muy próximos sean 
//              considerados iguales.
// Recibe: Dos números reales (numero1, numero2)
// Devuelve: True (1) si los dos números reales se consideran iguales y
//           False (0) si no es así
/***************************************************************************/
bool SonIguales(double numero1, double numero2) {
	
	return ( fabs(numero1 - numero2) <= PRECISION_SON_IGUALES );
}

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
// Clase Punto2D: representa un punto (x,y) en el plano
/***************************************************************************/
class Punto2D {

	private:

		double x;		// Coordenada X del punto en el plano
		double y;		// Coordenada Y del punto en el plano

	public:

		/*******************************************************************/
		// Constructor sin parámetros
		/*******************************************************************/
		Punto2D() : x(0.0), y(0.0) { }

		/*******************************************************************/
		// Constructor con parámetros
		/*******************************************************************/
		Punto2D(double abscisaPunto, double ordenadaPunto) {
			
			SetCoordenadas (abscisaPunto, ordenadaPunto);
		}
		
		/*******************************************************************/
		// Método: SetCoordenadas()
		// Descripción: Establece las coordenadas de un punto del plano
		// Recibe: Abscisa del punto (abscisaPunto), 
		//         Ordenada del punto (ordenadaPunto)
		// Devuelve: -
		/*******************************************************************/
		void SetCoordenadas(double abscisaPunto, double ordenadaPunto) {
			
			x = abscisaPunto;
			y = ordenadaPunto;
		}
		
		/*******************************************************************/
		// Método: GetX()
		// Descripción: Devuelve la abscisa de un punto del plano
		// Recibe: -
		// Devuelve: Abscisa de un punto del plano (x)
		/*******************************************************************/
		double GetX() {
			
			return x;
		}
		
		/*******************************************************************/
		// Método: GetY()
		// Descripción: Devuelve la ordenada de un punto del plano
		// Recibe: -
		// Devuelve: Ordenada de un punto del plano (y)
		/*******************************************************************/
		double GetY() {
			
			return y;
		}
		
		/*******************************************************************/
		// Método: EsIgual()
		// Descripción: Comprueba si un punto del plano es igual al punto
		//              implícito
		// Recibe: Punto del plano (otro)
		// Devuelve: True (1) si los dos puntos son iguales y False (0) si
		//           no lo son
		/*******************************************************************/
		bool EsIgual(Punto2D otro) {
			
			return ( SonIguales(x, otro.x) && SonIguales(y, otro.y) );
		}
		
		/*******************************************************************/
		// Método: DistanciaEuclidea()
		// Descripción: Calcula la distancia euclídea del punto implícito 
		//              a otro punto del plano
		// Recibe: Punto del plano (otro)
		// Devuelve: Distancia euclídea entre los dos puntos.
		/*******************************************************************/
		double DistanciaEuclidea(Punto2D otro) {
			
			double dif_x = pow(x - otro.x, 2);
			double dif_y = pow(y - otro.y, 2);

			return ( sqrt(dif_x + dif_y) );
		}
		
		/*******************************************************************/
		// Método: ToString()
		// Descripción: Compone un string con las coordenadas del punto 
		//              del plano
		// Recibe: -
		// Devuelve: String con las coordenadas del punto del plano (cadena)
		/*******************************************************************/	
		string ToString () {
			
			string cadena;
			
			cadena += "[" + to_string(x) + ", " + to_string(y) + "]";
			
			return cadena;
		}
};

/***************************************************************************/
// Clase ColeccionPuntos2D: representa una colección de datos de tipo 
//                          Punto2D
/***************************************************************************/
class ColeccionPuntos2D {
	
	private:
		
		static const int TAMANIO = 50;		// Número de casillas disponibles
		Punto2D vector_privado[TAMANIO];
		
		// PRE: 0 <= total_utilizados <= TAMANIO
		int total_utilizados;           // Número de casillas ocupadas
				
	public:
		
		/*******************************************************************/
		// Constructor sin parámetros
		/*******************************************************************/
		ColeccionPuntos2D() : total_utilizados(0) { }
				
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
		// Descripción: "Vacía" completamente la colección
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
		void Aniade(Punto2D nuevo) {
			
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
		Punto2D Elemento(int indice) {
			
			return vector_privado[indice];
		}
		
		/*******************************************************************/
		// Método: Modifica()
		// Descripción: Cambia el contenido de la casilla "indice" por el 
		//              valor dado en "nuevo". El tamaño de la colección no 
		//              cambia
		// Recibe: Índice de la casilla del elemento a cambiar (indice),
		//         Nuevo valor del elemento de la casilla "indice" (nuevo)
		// Devuelve: -
		// PRE: 0 <= indice < total_utilizados
		/*******************************************************************/
		void Modifica(int indice, Punto2D nuevo) {
			
			if( (indice >= 0) && (indice < total_utilizados) )
				vector_privado[indice] = nuevo;
		}
		
		/*******************************************************************/
		// Método: Elimina()
		// Descripción: Eliminar el punto de la posición dada por "indice".
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
		// Descripción: Inserta el punto "nuevo" en la posición dada por 
		//              "indice". Desplaza todos los caracteres una posición 
		//              a la derecha antes de copiar en "indice" el valor 
		//              "nuevo"
		// Recibe: Índice de la casilla del elemento a insertar (indice),
		//         Valor del elemento a insertar (nuevo)
		// Devuelve: -
		// PRE: 0 <= indice < total_utilizados
		/*******************************************************************/
		void Inserta(int indice, Punto2D nuevo) {
			
			if( (total_utilizados < TAMANIO) && (indice >= 0) && 
			     (indice < total_utilizados) ) {
		
				for(int i = total_utilizados ; i > indice ; i--)
					vector_privado[i] = vector_privado[i-1];
		
				vector_privado[indice] = nuevo;
				total_utilizados++;
			}
		}
		
		/*******************************************************************/
		// Método: ToString()
		// Descripción: Compone un string con todos los puntos que están
		//              almacenados en la colección y lo devuelve.
		// Recibe: -
		// Devuelve: String con todos los puntos que están almacenados
		//           en la colección (cadena)
		/*******************************************************************/
		string ToString() {
			
			string cadena;
						
			for(int i = 0; i < total_utilizados; i++) 
				cadena = cadena + " [" + to_string( Elemento(i).GetX() )
				                + ", " + to_string( Elemento(i).GetY() ) + "]" 
								+ "\n";

			return cadena;
		}	
};

/***************************************************************************/
// Clase Circunferencia: representa una circunferencia en el plano
/***************************************************************************/
class Circunferencia {
	
	private:
	
		static const double PI;		
		
		Punto2D centro;		// Centro de la circunferencia
		
		// PRE: 0 < radio
		double radio;		// Radio de la circunferencia

	public:
		
		/*******************************************************************/
		// Constructor sin parámetros
		/*******************************************************************/
		Circunferencia() : centro( Punto2D(0.0, 0.0) ), radio(1.0) { }
		
		/*******************************************************************/
		// Constructor con parámetros
		/*******************************************************************/
		Circunferencia(Punto2D valor_centro, double valor_radio) 
		              : centro (valor_centro), radio(valor_radio) { } 
		              
		/*******************************************************************/
		// Método: SetCentro()
		// Descripción: Establece el centro de la circunferencia
		// Recibe: Centro de la circunferencia (valor_centro)
		// Devuelve: -
		/*******************************************************************/
		void SetCentro(Punto2D valor_centro) {
			
			centro.SetCoordenadas( valor_centro.GetX(), valor_centro.GetY() );
		}
		
		/*******************************************************************/
		// Método: SetRadio()
		// Descripción: Establece el radio de la circunferencia
		// Recibe: Radio de la circunferencia (valor_radio)
		// Devuelve: -
		// PRE: 0 < valor_radio
		/*******************************************************************/
		void SetRadio(double valor_radio) {
			
			radio = valor_radio;
		}
		
		/*******************************************************************/
		// Método: GetCentro()
		// Descripción: Devuelve el centro de la circunferencia
		// Recibe: -
		// Devuelve: Centro de la circunferencia (centro)
		/*******************************************************************/
		Punto2D GetCentro() {
			
			return centro;
		}
		
		/*******************************************************************/
		// Método: GetRadio()
		// Descripción: Devuelve el radio de la circunferencia
		// Recibe: -
		// Devuelve: Radio de la circunferencia (radio)
		/*******************************************************************/
		double GetRadio() {
			
			return radio;
		}
		
		/*******************************************************************/
		// Método: GetDiametro()
		// Descripción: Calcula y devuelve el diámetro de la circunferencia
		// Recibe: -
		// Devuelve: Diámetro de la circunferencia (diametro)
		/*******************************************************************/
		double GetDiametro() {
			
			double diametro = 2 * radio;
			
			return diametro;
		}
		
		/*******************************************************************/
		// Método: Longitud()
		// Descripción: Calcula la longitud de la circunferencia
		// Recibe: -
		// Devuelve: Longitud de la circunferencia (longitud)
		/*******************************************************************/
		double Longitud() {
			
			double longitud = 2 * PI * radio;
			
			return longitud;
		}
		
		/*******************************************************************/
		// Método: Area()
		// Descripción: Calcula el area de la circunferencia
		// Recibe: -
		// Devuelve: Area de la circunferencia (area)
		/*******************************************************************/
		double Area() {
			
			double area = PI * radio * radio;
			
			return area;
		}

		/*******************************************************************/
		// Método: Contiene()
		// Descripción: Comprueba si un punto del plano está contenido en
		//              la circunferencia. Un punto P(x, y) está dentro de 
		//              una circunferencia con centro C(x_0, y_0) y radio r 
		//              si DistaciaEuclidea(P, C) <= r
		// Recibe: Punto del plano (punto)
		// Devuelve: True (1) si la circunferencia contiene al punto y
		//           False (0) si no lo contiene
		/*******************************************************************/
		bool Contiene(Punto2D punto) {
			
			Punto2D el_centro = GetCentro();
			
			double distancia = el_centro.DistanciaEuclidea(punto);
			
			bool punto_pertenece_a_circunferencia = (distancia <= radio);
			
			return punto_pertenece_a_circunferencia;
		}
		
		/*******************************************************************/
		// Método: ToString()
		// Descripción: Compone un string con el centro y el radio de la
		//              circunferencia
		// Recibe: -
		// Devuelve: String con el centro y el radio de la circunferencia
		//           (cadena)
		/*******************************************************************/
		string ToString() {
			
			string cadena;
			
			cadena = cadena + "\t Centro =  " 
			                + centro.ToString() + "\n" 
							+ "\t Radio = " + to_string(radio);
					 
			return cadena;
		}
};

/***************************************************************************/
const double Circunferencia :: PI = 3.1415926;
/***************************************************************************/

/***************************************************************************/
// Función principal
/***************************************************************************/
int main() {
	
    cout.setf(ios::fixed);        // Notación de punto fijo para los reales
    cout.setf(ios::showpoint);    // Mostrar siempre decimales 
    
    // Declaración de constantes
    
    const string FINALIZAR = "FIN";
    
    // Declaración de variables y objetos
    
    string abscisa_x, ordenada_y;
    
    ColeccionPuntos2D coleccion_puntos2d;
    
    // Entradas de datos
    
    // Colección de Puntos2D
    
    int i = 1;
    bool finalizar = false;
    
    cout << " Coleccion de Puntos2D: " << endl << endl;
    
    while(!finalizar) {
    	
	    cout << "\t Punto " << i << ": " << endl << endl;
	    cout << "\t\t Coordenada X del punto (FIN para finalizar): ";
	    getline(cin, abscisa_x);
	    
	    finalizar = (abscisa_x == FINALIZAR);
	    
	    if(!finalizar) {
	    	
		    cout << "\t\t Coordenada Y del punto: ";
		    getline(cin, ordenada_y);
		    
		    Punto2D punto( stod(abscisa_x), stod(ordenada_y) );
		    
		    coleccion_puntos2d.Aniade(punto);
		    
		    i++;
		}
		
		cout << endl;
	}
	
	// Circunferencia
	
	if(coleccion_puntos2d.TotalUtilizados() > 0) {
		
		double radio; 
		double centro_x, centro_y;
		
		Lector lector_circunferencia;
				
		cout << endl;
		cout << " Circunferencia: " << endl << endl;
		lector_circunferencia.SetTitulo("\t Coordenada X del centro: ");
		centro_x = lector_circunferencia.LeeDouble(); 
	
		lector_circunferencia.SetTitulo("\t Coordenada Y del centro: ");
		centro_y = lector_circunferencia.LeeDouble(); 
	
		Punto2D centro(centro_x, centro_y);
				
		lector_circunferencia.SetTitulo("\t Radio: ");
		radio = lector_circunferencia.LeeDoubleMayor(0);
		
		Circunferencia circunferencia(centro, radio); 
				
		// Cálculos y Salidas
		
		cout << endl;
		
		for(int i = 0; i < coleccion_puntos2d.TotalUtilizados(); i++) {
			
			if( circunferencia.Contiene( coleccion_puntos2d.Elemento(i) ) )
				cout << " El punto " 
				     << coleccion_puntos2d.Elemento(i).ToString() 
					 << " SI pertenece a la circunferencia" << endl;
			else
				cout << " El punto " 
				     << coleccion_puntos2d.Elemento(i).ToString() 
					 << " NO pertenece a la circunferencia" << endl;
		}
		
		cout << endl;	
	}
        
    return 0;
}
