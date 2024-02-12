/*
	Relaci�n de ejercicios 6

	Ejercicio 25:	Consideramos la clase ColeccionPuntos2D que usaremos para 
	                almacenar y gestionar una colecci�n de datos de tipo 
					Punto2D.

					Realizamos un programa que lea del teclado un n�mero 
					indeterminado de datos de tipo Punto2D de manera que 
					termine la lectura si el usuario escribe FIN cuando el 
					programa le pide la abscisa de un nuevo punto. Los puntos 
					le�dos los almacena en un objeto ColeccionPuntos2D.

					A continuaci�n pide los datos necesarios, y crea un objeto 
					Circunferencia, y finalmente muestra cu�les de los puntos 
					almacenados en la colecci�n ColeccionPuntos2D est� en el 
					c�rculo delimitado por la circunferencia.
	              
	Entradas: Colecci�n de Puntos2D (coleccion_puntos2d),
	          Circunferencia (circunferencia).
	Salidas: Comprobaci�n de si cada punto de "coleccion_puntos2d"
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
// Funci�n: SonIguales()
// Descripci�n: Funci�n global (asociada a la constante PRECISION_SON_IGUALES)
//              que permite que dos n�meros reales muy pr�ximos sean 
//              considerados iguales.
// Recibe: Dos n�meros reales (numero1, numero2)
// Devuelve: True (1) si los dos n�meros reales se consideran iguales y
//           False (0) si no es as�
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
// Clase Punto2D: representa un punto (x,y) en el plano
/***************************************************************************/
class Punto2D {

	private:

		double x;		// Coordenada X del punto en el plano
		double y;		// Coordenada Y del punto en el plano

	public:

		/*******************************************************************/
		// Constructor sin par�metros
		/*******************************************************************/
		Punto2D() : x(0.0), y(0.0) { }

		/*******************************************************************/
		// Constructor con par�metros
		/*******************************************************************/
		Punto2D(double abscisaPunto, double ordenadaPunto) {
			
			SetCoordenadas (abscisaPunto, ordenadaPunto);
		}
		
		/*******************************************************************/
		// M�todo: SetCoordenadas()
		// Descripci�n: Establece las coordenadas de un punto del plano
		// Recibe: Abscisa del punto (abscisaPunto), 
		//         Ordenada del punto (ordenadaPunto)
		// Devuelve: -
		/*******************************************************************/
		void SetCoordenadas(double abscisaPunto, double ordenadaPunto) {
			
			x = abscisaPunto;
			y = ordenadaPunto;
		}
		
		/*******************************************************************/
		// M�todo: GetX()
		// Descripci�n: Devuelve la abscisa de un punto del plano
		// Recibe: -
		// Devuelve: Abscisa de un punto del plano (x)
		/*******************************************************************/
		double GetX() {
			
			return x;
		}
		
		/*******************************************************************/
		// M�todo: GetY()
		// Descripci�n: Devuelve la ordenada de un punto del plano
		// Recibe: -
		// Devuelve: Ordenada de un punto del plano (y)
		/*******************************************************************/
		double GetY() {
			
			return y;
		}
		
		/*******************************************************************/
		// M�todo: EsIgual()
		// Descripci�n: Comprueba si un punto del plano es igual al punto
		//              impl�cito
		// Recibe: Punto del plano (otro)
		// Devuelve: True (1) si los dos puntos son iguales y False (0) si
		//           no lo son
		/*******************************************************************/
		bool EsIgual(Punto2D otro) {
			
			return ( SonIguales(x, otro.x) && SonIguales(y, otro.y) );
		}
		
		/*******************************************************************/
		// M�todo: DistanciaEuclidea()
		// Descripci�n: Calcula la distancia eucl�dea del punto impl�cito 
		//              a otro punto del plano
		// Recibe: Punto del plano (otro)
		// Devuelve: Distancia eucl�dea entre los dos puntos.
		/*******************************************************************/
		double DistanciaEuclidea(Punto2D otro) {
			
			double dif_x = pow(x - otro.x, 2);
			double dif_y = pow(y - otro.y, 2);

			return ( sqrt(dif_x + dif_y) );
		}
		
		/*******************************************************************/
		// M�todo: ToString()
		// Descripci�n: Compone un string con las coordenadas del punto 
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
// Clase ColeccionPuntos2D: representa una colecci�n de datos de tipo 
//                          Punto2D
/***************************************************************************/
class ColeccionPuntos2D {
	
	private:
		
		static const int TAMANIO = 50;		// N�mero de casillas disponibles
		Punto2D vector_privado[TAMANIO];
		
		// PRE: 0 <= total_utilizados <= TAMANIO
		int total_utilizados;           // N�mero de casillas ocupadas
				
	public:
		
		/*******************************************************************/
		// Constructor sin par�metros
		/*******************************************************************/
		ColeccionPuntos2D() : total_utilizados(0) { }
				
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
		// Descripci�n: "Vac�a" completamente la colecci�n
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
		void Aniade(Punto2D nuevo) {
			
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
		Punto2D Elemento(int indice) {
			
			return vector_privado[indice];
		}
		
		/*******************************************************************/
		// M�todo: Modifica()
		// Descripci�n: Cambia el contenido de la casilla "indice" por el 
		//              valor dado en "nuevo". El tama�o de la colecci�n no 
		//              cambia
		// Recibe: �ndice de la casilla del elemento a cambiar (indice),
		//         Nuevo valor del elemento de la casilla "indice" (nuevo)
		// Devuelve: -
		// PRE: 0 <= indice < total_utilizados
		/*******************************************************************/
		void Modifica(int indice, Punto2D nuevo) {
			
			if( (indice >= 0) && (indice < total_utilizados) )
				vector_privado[indice] = nuevo;
		}
		
		/*******************************************************************/
		// M�todo: Elimina()
		// Descripci�n: Eliminar el punto de la posici�n dada por "indice".
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
		// Descripci�n: Inserta el punto "nuevo" en la posici�n dada por 
		//              "indice". Desplaza todos los caracteres una posici�n 
		//              a la derecha antes de copiar en "indice" el valor 
		//              "nuevo"
		// Recibe: �ndice de la casilla del elemento a insertar (indice),
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
		// M�todo: ToString()
		// Descripci�n: Compone un string con todos los puntos que est�n
		//              almacenados en la colecci�n y lo devuelve.
		// Recibe: -
		// Devuelve: String con todos los puntos que est�n almacenados
		//           en la colecci�n (cadena)
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
		// Constructor sin par�metros
		/*******************************************************************/
		Circunferencia() : centro( Punto2D(0.0, 0.0) ), radio(1.0) { }
		
		/*******************************************************************/
		// Constructor con par�metros
		/*******************************************************************/
		Circunferencia(Punto2D valor_centro, double valor_radio) 
		              : centro (valor_centro), radio(valor_radio) { } 
		              
		/*******************************************************************/
		// M�todo: SetCentro()
		// Descripci�n: Establece el centro de la circunferencia
		// Recibe: Centro de la circunferencia (valor_centro)
		// Devuelve: -
		/*******************************************************************/
		void SetCentro(Punto2D valor_centro) {
			
			centro.SetCoordenadas( valor_centro.GetX(), valor_centro.GetY() );
		}
		
		/*******************************************************************/
		// M�todo: SetRadio()
		// Descripci�n: Establece el radio de la circunferencia
		// Recibe: Radio de la circunferencia (valor_radio)
		// Devuelve: -
		// PRE: 0 < valor_radio
		/*******************************************************************/
		void SetRadio(double valor_radio) {
			
			radio = valor_radio;
		}
		
		/*******************************************************************/
		// M�todo: GetCentro()
		// Descripci�n: Devuelve el centro de la circunferencia
		// Recibe: -
		// Devuelve: Centro de la circunferencia (centro)
		/*******************************************************************/
		Punto2D GetCentro() {
			
			return centro;
		}
		
		/*******************************************************************/
		// M�todo: GetRadio()
		// Descripci�n: Devuelve el radio de la circunferencia
		// Recibe: -
		// Devuelve: Radio de la circunferencia (radio)
		/*******************************************************************/
		double GetRadio() {
			
			return radio;
		}
		
		/*******************************************************************/
		// M�todo: GetDiametro()
		// Descripci�n: Calcula y devuelve el di�metro de la circunferencia
		// Recibe: -
		// Devuelve: Di�metro de la circunferencia (diametro)
		/*******************************************************************/
		double GetDiametro() {
			
			double diametro = 2 * radio;
			
			return diametro;
		}
		
		/*******************************************************************/
		// M�todo: Longitud()
		// Descripci�n: Calcula la longitud de la circunferencia
		// Recibe: -
		// Devuelve: Longitud de la circunferencia (longitud)
		/*******************************************************************/
		double Longitud() {
			
			double longitud = 2 * PI * radio;
			
			return longitud;
		}
		
		/*******************************************************************/
		// M�todo: Area()
		// Descripci�n: Calcula el area de la circunferencia
		// Recibe: -
		// Devuelve: Area de la circunferencia (area)
		/*******************************************************************/
		double Area() {
			
			double area = PI * radio * radio;
			
			return area;
		}

		/*******************************************************************/
		// M�todo: Contiene()
		// Descripci�n: Comprueba si un punto del plano est� contenido en
		//              la circunferencia. Un punto P(x, y) est� dentro de 
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
		// M�todo: ToString()
		// Descripci�n: Compone un string con el centro y el radio de la
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
// Funci�n principal
/***************************************************************************/
int main() {
	
    cout.setf(ios::fixed);        // Notaci�n de punto fijo para los reales
    cout.setf(ios::showpoint);    // Mostrar siempre decimales 
    
    // Declaraci�n de constantes
    
    const string FINALIZAR = "FIN";
    
    // Declaraci�n de variables y objetos
    
    string abscisa_x, ordenada_y;
    
    ColeccionPuntos2D coleccion_puntos2d;
    
    // Entradas de datos
    
    // Colecci�n de Puntos2D
    
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
				
		// C�lculos y Salidas
		
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
