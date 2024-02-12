/*
	Relación de ejercicios 6

	Ejercicio 5: Ampliacion de la clase Dinero. Partimos del siguiente esquema 
	             (resultado del ejercicio 4 de la Relación de Problemas V):

				 Dinero

					- int euros; // PRE: 0 <= euros
					- int centimos; // PRE: 0 <= centimos < 100

					+ Dinero (void);
					+ Dinero (double cantidad); // PRE: 0 <= cantidad
					+ Dinero (int los_euros, int los_centimos); 
					  // PRE: 0 <= los_euros 0 <= los_centimos
					+ int GetEuros (void);
					+ int GetCentimos (void);
					+ double GetValor (void);
					+ void Incrementa (double cantidad); // PRE: 0 <= cantidad
					+ void Incrementa (int euros_suman, int centimos_suman);
					  // PRE: 0 <= euros_suman 0 <= centimos_suman
					+ string ToString (int num_casillas_euros, 
					                   char caracter_hueco);
					  // PRE: 0 <= num_casillas_euros

				 Descartamos el método:

					+ void Incrementa (int euros_suman, int centimos_suman);

				 Añadimos los métodos:

					+ Dinero Incrementa(Dinero cantidad)
						calcula y devuelve el resultado de sumar cantidad a 
						la cantidad de dinero del objeto implícito. El valor 
						de cantidad deber ser positivo.
						
					+ Dinero Decrementa(Dinero cantidad)
					+ Dinero Decrementa(double cantidad)
						calcula y devuelve el resultado de restar cantidad a 
						la cantidad de dinero del objeto implícito. El valor 
						de cantidad deber ser positivo. Si no es posible 
						realizar la resta, no se hace nada.

					+ Dinero Modifica(double cantidad)
						calcula y devuelve el resultado de sumar/restar 
						cantidad a la cantidad de dinero del objeto implícito. 
						Si no es posible realizar la resta, no se hace nada.
	              
	Entradas: Dos precios (objetos de la clase Dinero) y algunas cantidades
	          (valores numéricos reales).
	Salidas: Resultados de los nuevos métodos añadidos.

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

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
// Clase Dinero: representa cantidades monetarias expresadas en dos
//               unidades enteras: euros y céntimos
/***************************************************************************/
class Dinero {

	private:

		// PRE: 0 <= euros
		int euros;		// Número de euros

		// PRE: 0 <= centimos < 100
		int centimos;	// Número de céntimos
	
	public:

		/*******************************************************************/
		// Constructor sin parámetros
		/*******************************************************************/
		Dinero() : euros(0), centimos(0) { }
	
		/*******************************************************************/
		// Constructor con un parámetro
		// PRE: 0 <= cantidad
		/*******************************************************************/
		Dinero(double cantidad) {	
			
			if(cantidad >= 0) {
				
				euros = (cantidad * 100) / 100; 
				centimos = ( (int) (cantidad * 100) ) % 100;
			}
		}		
		
		/*******************************************************************/
		// Constructor con dos parámetros
		// PRE:  0 <= valor_euros
		// PRE:  0 <= valor_centimos
		// POST: 0 <= centimos < 100		
		/*******************************************************************/	
		Dinero(int valor_euros, int valor_centimos) {
			
			if ( (valor_euros >= 0) && (valor_centimos >= 0) ) {
				
				centimos = valor_centimos % 100;
				euros = valor_euros + (valor_centimos / 100);
			}
		}
		
		/*******************************************************************/
		// Método: SetEuros()
		// Descripción: Establece el número de euros
		// Recibe: Número de euros (valor_euros)
		// Devuelve: -
		// PRE: 0 <= valor_euros
		/*******************************************************************/
		void SetEuros(int valor_euros) {
		
			if(valor_euros >= 0)
				euros = valor_euros;	
		}
	
		/*******************************************************************/
		// Método: SetCentimos()
		// Descripción: Establece el número de céntimos
		// Recibe: Número de céntimos (valor_centimos)
		// Devuelve: -
		// PRE: 0 <= valor_centimos < 100
		/*******************************************************************/
		void SetCentimos(int valor_centimos) {
			
			if( (valor_centimos >= 0) && (valor_centimos < 100) )
				centimos = valor_centimos;	
		}
	
		/*******************************************************************/
		// Método: SetValor()
		// Descripción: Establece el número de euros y de céntimos según el
		//              valor numérico real "cantidad"
		// Recibe: Valor numérico real (cantidad)
		// Devuelve: -
		// PRE: 0 <= cantidad
		/*******************************************************************/
		void SetValor(double cantidad) {
		
			if(cantidad >= 0) {
				
				euros = (cantidad * 100) / 100; 
				centimos = ( (int) (cantidad * 100) ) % 100;
			}
		}
		
		/*******************************************************************/
		// Método: GetEuros()
		// Descripción: Devuelve el número de euros
		// Recibe: -
		// Devuelve: Número de euros (euros)
		/*******************************************************************/
		int GetEuros() {
			
			return euros;
		}
		
		/*******************************************************************/
		// Método: GetCentimos()
		// Descripción: Devuelve el número de céntimos
		// Recibe: -
		// Devuelve: Número de céntimos (centimos)
		/*******************************************************************/
		int GetCentimos() {
			
			return centimos;
		}
		
		/*******************************************************************/
		// Método: GetValor()
		// Descripción: Devuelve el valor numérico real del objeto de la 
		//              clase Dinero
		// Recibe: -
		// Devuelve: Valor numérico real del objeto de la clase Dinero
		/*******************************************************************/
		double GetValor() {
			
			return ( euros + (centimos / 100.0) );
		}
		
		/*******************************************************************/
		// Método: Incrementa()
		// Descripción: Modifica los valores de los dos campos del objeto 
		//              de la clase Dinero sumándole los valores de los
		//              campos de otro objeto de la clase Dinero
		// Recibe: Cantidad de dinero (cantidad)
		// Devuelve: Resultado de sumarle los valores de los campos de
		//           "cantidad" a los valores de los campos del objeto 
		//           de la clase Dinero (resultado)
		// PRE: 0 <= cantidad
		/*******************************************************************/
		Dinero Incrementa(Dinero cantidad) {
			
			Dinero resultado;
			
			if(cantidad.GetValor() >= 0)
				resultado.SetValor( GetValor() + cantidad.GetValor() );
		
			return resultado;
		}
		
		/*******************************************************************/
		// Método: Incrementa()
		// Descripción: Modifica los valores de los dos campos del objeto 
		//              de la clase Dinero sumándole la cantidad dada
		//              en el valor numérico real "cantidad"
		// Recibe: Valor numérico real (cantidad)
		// Devuelve: Resultado de sumarle el valor numérico real "cantidad" 
		//           a los valores de los campos del objeto de la clase 
		//           Dinero (resultado)
		// PRE: 0 <= cantidad
		/*******************************************************************/
		Dinero Incrementa(double cantidad) {

			Dinero resultado;
			
			if(cantidad >= 0)
				resultado.SetValor( GetValor() + cantidad );
		
			return resultado;
		}
		
		/*******************************************************************/
		// Método: Decrementa()
		// Descripción: Modifica los valores de los dos campos del objeto 
		//              de la clase Dinero restándole los valores de los
		//              campos de otro objeto de la clase Dinero
		// Recibe: Cantidad de dinero (cantidad)
		// Devuelve: Resultado de restarle los valores de los campos de
		//           "cantidad" a los valores de los campos del objeto 
		//           de la clase Dinero (resultado)
		// PRE: cantidad.GetValor() <= GetValor()
		/*******************************************************************/
		Dinero Decrementa(Dinero cantidad) {
			
			Dinero resultado;
						
			if( ( GetValor() - cantidad.GetValor() ) > 0 )
				resultado.SetValor( GetValor() - cantidad.GetValor() );
			
			return resultado;
		}
		
		/*******************************************************************/
		// Método: Decrementa()
		// Descripción: Modifica los valores de los dos campos del objeto 
		//              de la clase Dinero restándole la cantidad dada
		//              en el valor numérico real "cantidad"
		// Recibe: Valor numérico real (cantidad)
		// Devuelve: Resultado de restarle el valor numérico real "cantidad" 
		//           a los valores de los campos del objeto de la clase 
		//           Dinero (resultado)
		// PRE: cantidad <= GetValor()
		/*******************************************************************/
		Dinero Decrementa(double cantidad) {
		
			Dinero resultado;
				
			if( (GetValor() - cantidad) > 0 )
				resultado.SetValor(GetValor() - cantidad);
		
			return resultado;
		}

		/*******************************************************************/
		// Método: Modifica()
		// Descripción: Modifica los valores de los dos campos del objeto 
		//              de la clase Dinero sumándole/restándole la cantidad 
		//              dada en el valor numérico real "cantidad"
		// Recibe: Valor numérico real (cantidad)
		// Devuelve: Resultado de sumarle/restarle el valor numérico real 
		//           "cantidad" a los valores de los campos del objeto de 
		//           la clase Dinero (resultado)
		/*******************************************************************/
		Dinero Modifica(double cantidad) {
			
			Dinero resultado;
						
			if(cantidad < 0)
				resultado = Decrementa( -(cantidad) );
			else
				resultado = Incrementa(cantidad);
				
			return resultado;
		}
		
		/*******************************************************************/
		// Método: EsMayor()
		// Descripción: Comprueba si un objeto de la clase Dinero es mayor
		//              que otro objeto de la clase Dinero
		// Recibe: Cantidad de dinero (otro)
		// Devuelve: True (1) si el objeto de la clase Dinero es mayor que
		//           "otro" y False (0) si no lo es 
		/*******************************************************************/
		bool EsMayor(Dinero otro) {
			
			return ( GetValor() > otro.GetValor() );
		}
		
		/*******************************************************************/
		// Método: EsMayor()
		// Descripción: Comprueba si un objeto de la clase Dinero es mayor
		//              que el valor numérico real "cantidad"
		// Recibe: Valor numérico real (cantidad)
		// Devuelve: True (1) si el objeto de la clase Dinero es mayor que
		//           "cantidad" y False (0) si no lo es 
		/*******************************************************************/
		bool EsMayor(double cantidad) {
						
			return ( GetValor() > cantidad );
		}
		
		/*******************************************************************/
		// Método: EsMenor()
		// Descripción: Comprueba si un objeto de la clase Dinero es menor
		//              que otro objeto de la clase Dinero
		// Recibe: Cantidad de dinero (otro)
		// Devuelve: True (1) si el objeto de la clase Dinero es menor que
		//           "otro" y False (0) si no lo es 
		/*******************************************************************/	
		bool EsMenor(Dinero otro) {
				
			return ( GetValor() < otro.GetValor() );
		}
	
		/*******************************************************************/
		// Método: EsMenor()
		// Descripción: Comprueba si un objeto de la clase Dinero es menor
		//              que el valor numérico real "cantidad"
		// Recibe: Valor numérico real (cantidad)
		// Devuelve: True (1) si el objeto de la clase Dinero es menor que
		//           "cantidad" y False (0) si no lo es 
		/*******************************************************************/
		bool EsMenor(double cantidad) {
					
			return ( GetValor() < cantidad );
		}
		
		/*******************************************************************/
		// Método: EsIgual()
		// Descripción: Comprueba si un objeto de la clase Dinero es igual
		//              que otro objeto de la clase Dinero
		// Recibe: Cantidad de dinero (otro)
		// Devuelve: True (1) si el objeto de la clase Dinero es igual que
		//           "otro" y False (0) si no lo es 
		/*******************************************************************/
		bool EsIgual(Dinero otro) {
			
			return ( SonIguales( GetValor(), otro.GetValor() ) );
		}
		
		/*******************************************************************/
		// Método: EsIgual()
		// Descripción: Comprueba si un objeto de la clase Dinero es igual
		//              que el valor numérico real "cantidad"
		// Recibe: Valor numérico real (cantidad)
		// Devuelve: True (1) si el objeto de la clase Dinero es igual que
		//           "cantidad" y False (0) si no lo es 
		/*******************************************************************/
		bool EsIgual(double cantidad) {
			
			return ( SonIguales( GetValor(), cantidad ) );
		}
		
		/*******************************************************************/
		// Método: Diferencia()
		// Descripción: Calcula la diferencia entre la cantidad de dinero de
		//              un objeto de la clase Dinero y otro objeto de la
		//              clase Dinero
		// Recibe: Cantidad de dinero (otro)
		// Devuelve: Diferencia entre la cantidad de dinero de un objeto de 
		//           la clase Dinero y "otro" (resultado)
		// PRE: otro.GetValor() <= GetValor()
		/*******************************************************************/
		Dinero Diferencia(Dinero otro) {
			
			Dinero resultado;
			
			if( EsMayor(otro) )
				resultado.SetValor( GetValor() - otro.GetValor() );
				
			return resultado;
		}
	
		/*******************************************************************/
		// Método: Diferencia()
		// Descripción: Calcula la diferencia entre la cantidad de dinero de
		//              un objeto de la clase Dinero y el valor numérico real
		//              "cantidad"
		// Recibe: Valor numérico real (cantidad)
		// Devuelve: Diferencia entre la cantidad de dinero de un objeto de 
		//           la clase Dinero y "cantidad" (resultado)
		// PRE: cantidad <= GetValor()
		/*******************************************************************/
		Dinero Diferencia(double cantidad) {
			
			Dinero resultado;
			
			if( EsMayor(cantidad) )
				resultado.SetValor( GetValor() - cantidad );
				
			return resultado;
		}
		
		/*******************************************************************/
		// Método: ToString()
		// Descripción: Representa en forma de cadena los valores de un 
		//              objeto de la clase Dinero
		// Recibe: Número de casillas con el que queremos formatear el 
		//         valor de los euros (num_casillas_euros),
		//         Carácter con el que se rellenaran las casillas si 
		//         el número de casillas es mayor que el número de 
		//         dígitos (caracter_hueco) 
		// Devuelve: String con la representación textual de un objeto
		//           de la clase Dinero (cadena)
		// PRE: 0 <= num_casillas_euros
		/*******************************************************************/
		string ToString(int num_casillas_euros, char caracter_hueco) {

			string cadena; 
	
			int num_digitos; 
			int num_huecos;
			
			num_digitos = NumDigitos(euros); 
			
			if(num_casillas_euros < num_digitos) 
				num_casillas_euros=num_digitos; 
				
			num_huecos = num_casillas_euros-num_digitos; 
			
			for(int i = 0; i < num_huecos; i++) 
				cadena += caracter_hueco;
			
			cadena += to_string(euros) + ",";
			
			if(centimos < 10) 
				cadena = cadena + "0";
				
			cadena = cadena + to_string(centimos) + " euros";
		
			return cadena;
		}
	
	private: 

		/*******************************************************************/
		// Método: IncrementaEuros()
		// Descripción: Modifica el valor del campo "euros" del objeto 
		//              de la clase Dinero sumándole la cantidad dada
		//              en el valor numérico "euros_a_sumar"
		// Recibe: Euros a sumar (euros_a_sumar)
		// Devuelve: -
		// PRE: 0 <= euros_a_sumar
		/*******************************************************************/
		void IncrementaEuros(int euros_a_sumar) {
			
			if(euros_a_sumar >= 0)
				euros += euros_a_sumar;
		}
		
		/*******************************************************************/
		// Método: IncrementaCentimos()
		// Descripción: Modifica el valor del campo "centimos" del objeto 
		//              de la clase Dinero sumándole la cantidad dada
		//              en el valor numérico "centimos_a_sumar". Si 
		//              "centimos_suman" es mayor o igual que 100 ajusta su 
		//              valor para garantizar la validez del campo 
		//              "centimos" (entre 0 y 99) y actualiza el valor del 
		//              campo "euros".
		// Recibe: Céntimos a sumar (centimos_a_sumar)
		// Devuelve: -
		// PRE: 0 <= centimos_a_sumar
		/*******************************************************************/		 
		void IncrementaCentimos(int centimos_a_sumar) {
			
			if(centimos_a_sumar >= 0) {
				
				int total_centimos = centimos + centimos_a_sumar;
				
				centimos = total_centimos % 100;
				euros = euros + (total_centimos / 100);
			}
		}
		
		/*******************************************************************/
		// Método: NumDigitos()
		// Descripción: Calcula y devuelve el número de dígitos de un número
		//              entero
		// Recibe: Número entero (numero)
		// Devuelve: Número de dígitos de "numero" (num_digitos)
		/*******************************************************************/		
		int NumDigitos(int numero) {
			
			int	num_digitos = 1; 
			 
			while ( (numero / 10) > 0) {
				numero /= 10; 
				num_digitos++;
			}
			
			return num_digitos; 
		}	
};

/***************************************************************************/
// Función principal
/***************************************************************************/
int main() {
	
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	// Declaración de variables y objetos
	
	Lector lector_dinero, lector_cantidad;
	int euros1, centimos1, euros2, centimos2;
	
	// Entradas de datos
	
	cout << " Introduzca un precio: " << endl << endl;
	lector_dinero.SetTitulo(" \t Euros: ");
	euros1 = lector_dinero.LeeEnteroMayorOIgual(0);
	lector_dinero.SetTitulo(" \t Centimos: ");
	centimos1 = lector_dinero.LeeEnteroMayorOIgual(0);
	
	cout << endl;
	cout << " Introduzca otro precio: " << endl << endl;
	lector_dinero.SetTitulo(" \t Euros: ");
	euros2 = lector_dinero.LeeEnteroMayorOIgual(0);
	lector_dinero.SetTitulo(" \t Centimos: ");
	centimos2 = lector_dinero.LeeEnteroMayorOIgual(0);
	
	// Creación de objetos de la clase Dinero
	
	Dinero precio1(euros1, centimos1);
	cout << endl;
	cout << " Precio 1: " << precio1.ToString(4,'#') << endl;
	
	Dinero precio2(euros2, centimos2);
	cout << " Precio 2: " << precio2.ToString(4,'#') << endl;
	cout << endl;
	
	// Cálculos y Salidas
	
	// Métodos Incrementa de la clase Dinero
	
	Dinero incremento_dinero, incremento_cantidad;
	double inc_cantidad;
	
	cout << " Metodos Incrementa: " << endl;
	
	incremento_dinero = precio1.Incrementa(precio2);
	
	cout << endl;
	cout << "\t Resultado de incrementar Precio 2 a Precio 1: " 
	     << incremento_dinero.ToString(4,'#') << endl;
	
	cout << endl;
	lector_cantidad.SetTitulo("\t Introduzca una cantidad: ");
	inc_cantidad = lector_cantidad.LeeDouble();
	
	incremento_cantidad = precio1.Incrementa(inc_cantidad);
	
	cout << "\t Resultado de incrementar la cantidad introducida a Precio 1: " 
         << incremento_cantidad.ToString(4,'#') << endl;
	
	// Métodos Decrementa de la clase Dinero

	Dinero decremento_dinero, decremento_cantidad;
	double dec_cantidad;
	
	cout << endl;
	cout << " Metodos Decrementa: " << endl;
	
	decremento_dinero = precio1.Decrementa(precio2);
	
	cout << endl;
	cout << "\t Resultado de decrementar Precio 2 a Precio 1: " 
	     << decremento_dinero.ToString(4,'#') << endl;
	
	cout << endl;
	lector_cantidad.SetTitulo("\t Introduzca una cantidad: ");
	dec_cantidad = lector_cantidad.LeeDouble();
		
	decremento_cantidad = precio1.Decrementa(dec_cantidad);
	
	cout << "\t Resultado de decrementar la cantidad introducida a Precio 1: " 
         << decremento_cantidad.ToString(4,'#') << endl;

	// Método Modifica de la clase Dinero

	Dinero modificacion_cantidad;
	double mod_cantidad;
	
	cout << endl;
	cout << " Metodo Modifica: " << endl;
	
	cout << endl;
	lector_cantidad.SetTitulo("\t Introduzca una cantidad: ");
	mod_cantidad = lector_cantidad.LeeDouble();
	
	modificacion_cantidad = precio1.Modifica(mod_cantidad);
	
	cout << "\t Resultado de modificar Precio 1 segun la cantidad introducida: " 
         << modificacion_cantidad.ToString(4,'#') << endl;
	
	// Métodos EsMayor de la clase Dinero
	
	bool es_mayor_dinero, es_mayor_cantidad;
	int mayor_cantidad;
	
	cout << endl;
	cout << " Metodos EsMayor: " << endl;
	
	es_mayor_dinero = precio1.EsMayor(precio2);
	
	cout << endl;
	
	if(es_mayor_dinero)
		cout << "\t Precio 1 es mayor que Precio 2";
	else
		cout << "\t Precio 1 no es mayor que Precio 2";
			
	cout << endl << endl;
	lector_cantidad.SetTitulo("\t Introduzca una cantidad: ");
	mayor_cantidad = lector_cantidad.LeeDouble();
	
	es_mayor_cantidad = precio1.EsMayor(mayor_cantidad);
	
	if(es_mayor_cantidad)
		cout << "\t Precio 1 es mayor que la cantidad introducida";
	else
		cout << "\t Precio 1 no es mayor que la cantidad introducida";
	
	cout << endl;
	
	// Métodos EsMenor de la clase Dinero
	
	bool es_menor_dinero, es_menor_cantidad;
	int menor_cantidad;
	
	cout << endl;
	cout << " Metodos EsMenor: " << endl;
	
	es_menor_dinero = precio1.EsMenor(precio2);
	
	cout << endl;
	
	if(es_menor_dinero)
		cout << "\t Precio 1 es menor que Precio 2";
	else
		cout << "\t Precio 1 no es menor que Precio 2";
			
	cout << endl << endl;
	lector_cantidad.SetTitulo("\t Introduzca una cantidad: ");
	menor_cantidad = lector_cantidad.LeeDouble();
	
	es_menor_cantidad = precio1.EsMayor(menor_cantidad);
	
	if(es_menor_cantidad)
		cout << "\t Precio 1 es menor que la cantidad introducida";
	else
		cout << "\t Precio 1 no es menor que la cantidad introducida";
		
	cout << endl;
	
	// Métodos EsIgual de la clase Dinero
	
	bool es_igual_dinero, es_igual_cantidad;
	double igual_cantidad;
	
	cout << endl;
	cout << " Metodos EsIgual: " << endl;
	
	es_igual_dinero = precio1.EsIgual(precio2);
	
	cout << endl;
	
	if(es_igual_dinero)
		cout << "\t Precio 1 es igual que Precio 2";
	else
		cout << "\t Precio 1 no es igual que Precio 2";
			
	cout << endl << endl;
	lector_cantidad.SetTitulo("\t Introduzca una cantidad: ");
	igual_cantidad = lector_cantidad.LeeDouble();
	
	es_igual_cantidad = precio1.EsIgual(igual_cantidad);
	
	if(es_igual_cantidad)
		cout << "\t Precio 1 es igual que la cantidad introducida";
	else
		cout << "\t Precio 1 no es igual que la cantidad introducida";
		
	cout << endl;
		
	// Métodos Diferencia de la clase Dinero
	
	Dinero diferencia_dinero, diferencia_cantidad;
	double dif_cantidad;
	
	cout << endl;
	cout << " Metodos Diferencia: " << endl;
	
	diferencia_dinero = precio1.Diferencia(precio2);
	
	cout << endl;
	cout << "\t Diferencia entre Precio 1 y Precio 2: " 
	     << diferencia_dinero.ToString(4,'#') << endl;
	
	cout << endl;
	lector_cantidad.SetTitulo("\t Introduzca una cantidad: ");
	dif_cantidad = lector_cantidad.LeeDouble();
	
	diferencia_cantidad = precio1.Diferencia(dif_cantidad);
	
	cout << "\t Diferencia entre Precio 1 y la cantidad introducida: " 
         << diferencia_cantidad.ToString(4,'#') << endl;
         
    cout << endl;
         
	return 0;
}
