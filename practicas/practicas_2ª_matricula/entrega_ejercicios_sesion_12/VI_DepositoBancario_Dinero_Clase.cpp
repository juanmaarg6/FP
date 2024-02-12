/*
	Relaci�n de ejercicios 6

	Ejercicio 19: En el ejercicio 11 de la Relaci�n de Problemas V construimos 
				  la clase DepositoBancario. En ese momento el capital se 
				  represent� con un dato double pero ahora parece m�s razonable 
				  representarlo con un dato de la clase Dinero (ver ejercicio 5 
				  de la relaci�n de problemas VI). Por tanto, la clase
				  DepositoBancario quedar�a de la siguiente forma:
				  
					class DepositoBancario {
						
						private:
							
							Dinero capital; // PRE: 0 < capital.GetValor()
							double interes; // PRE: 0 < interes <= 100
					
						public:
							......
					};
					
				  Reescribimos la clase DepositoBancario y la soluci�n del 
				  ejercicio 11 de la Relaci�n de Problemas V.
	              
	Entradas: Capital (capital),
	          Inter�s (interes),
	          N�mero por el cual quisiera el cliente multiplicar su
	          capital actual (multiplicar_capital).
	Salidas: N�meros de a�os que tienen que pasar para que el cliente
	         obtenga un capital mayor o igual que "multiplicar_capital"
	         veces su capital actual (anios),
	         Capital resultante tras esos a�os.

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
// Clase Dinero: representa cantidades monetarias expresadas en dos
//               unidades enteras: euros y c�ntimos
/***************************************************************************/
class Dinero {

	private:

		// PRE: 0 <= euros
		int euros;		// N�mero de euros

		// PRE: 0 <= centimos < 100
		int centimos;	// N�mero de c�ntimos
	
	public:

		/*******************************************************************/
		// Constructor sin par�metros
		/*******************************************************************/
		Dinero() : euros(0), centimos(0) { }
	
		/*******************************************************************/
		// Constructor con un par�metro
		// PRE: 0 <= cantidad
		/*******************************************************************/
		Dinero(double cantidad) {	
			
			if(cantidad >= 0) {
				
				euros = (cantidad * 100) / 100; 
				centimos = ( (int) (cantidad * 100) ) % 100;
			}
		}		
		
		/*******************************************************************/
		// Constructor con dos par�metros
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
		// M�todo: SetEuros()
		// Descripci�n: Establece el n�mero de euros
		// Recibe: N�mero de euros (valor_euros)
		// Devuelve: -
		// PRE: 0 <= valor_euros
		/*******************************************************************/
		void SetEuros(int valor_euros) {
		
			if(valor_euros >= 0)
				euros = valor_euros;	
		}
	
		/*******************************************************************/
		// M�todo: SetCentimos()
		// Descripci�n: Establece el n�mero de c�ntimos
		// Recibe: N�mero de c�ntimos (valor_centimos)
		// Devuelve: -
		// PRE: 0 <= valor_centimos < 100
		/*******************************************************************/
		void SetCentimos(int valor_centimos) {
			
			if( (valor_centimos >= 0) && (valor_centimos < 100) )
				centimos = valor_centimos;	
		}
	
		/*******************************************************************/
		// M�todo: SetValor()
		// Descripci�n: Establece el n�mero de euros y de c�ntimos seg�n el
		//              valor num�rico real "cantidad"
		// Recibe: Valor num�rico real (cantidad)
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
		// M�todo: GetEuros()
		// Descripci�n: Devuelve el n�mero de euros
		// Recibe: -
		// Devuelve: N�mero de euros (euros)
		/*******************************************************************/
		int GetEuros() {
			
			return euros;
		}
		
		/*******************************************************************/
		// M�todo: GetCentimos()
		// Descripci�n: Devuelve el n�mero de c�ntimos
		// Recibe: -
		// Devuelve: N�mero de c�ntimos (centimos)
		/*******************************************************************/
		int GetCentimos() {
			
			return centimos;
		}
		
		/*******************************************************************/
		// M�todo: GetValor()
		// Descripci�n: Devuelve el valor num�rico real del objeto de la 
		//              clase Dinero
		// Recibe: -
		// Devuelve: Valor num�rico real del objeto de la clase Dinero
		/*******************************************************************/
		double GetValor() {
			
			return ( euros + (centimos / 100.0) );
		}
		
		/*******************************************************************/
		// M�todo: Incrementa()
		// Descripci�n: Modifica los valores de los dos campos del objeto 
		//              de la clase Dinero sum�ndole los valores de los
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
		// M�todo: Incrementa()
		// Descripci�n: Modifica los valores de los dos campos del objeto 
		//              de la clase Dinero sum�ndole la cantidad dada
		//              en el valor num�rico real "cantidad"
		// Recibe: Valor num�rico real (cantidad)
		// Devuelve: Resultado de sumarle el valor num�rico real "cantidad" 
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
		// M�todo: Decrementa()
		// Descripci�n: Modifica los valores de los dos campos del objeto 
		//              de la clase Dinero rest�ndole los valores de los
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
		// M�todo: Decrementa()
		// Descripci�n: Modifica los valores de los dos campos del objeto 
		//              de la clase Dinero rest�ndole la cantidad dada
		//              en el valor num�rico real "cantidad"
		// Recibe: Valor num�rico real (cantidad)
		// Devuelve: Resultado de restarle el valor num�rico real "cantidad" 
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
		// M�todo: Modifica()
		// Descripci�n: Modifica los valores de los dos campos del objeto 
		//              de la clase Dinero sum�ndole/rest�ndole la cantidad 
		//              dada en el valor num�rico real "cantidad"
		// Recibe: Valor num�rico real (cantidad)
		// Devuelve: Resultado de sumarle/restarle el valor num�rico real 
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
		// M�todo: EsMayor()
		// Descripci�n: Comprueba si un objeto de la clase Dinero es mayor
		//              que otro objeto de la clase Dinero
		// Recibe: Cantidad de dinero (otro)
		// Devuelve: True (1) si el objeto de la clase Dinero es mayor que
		//           "otro" y False (0) si no lo es 
		/*******************************************************************/
		bool EsMayor(Dinero otro) {
			
			return ( GetValor() > otro.GetValor() );
		}
		
		/*******************************************************************/
		// M�todo: EsMayor()
		// Descripci�n: Comprueba si un objeto de la clase Dinero es mayor
		//              que el valor num�rico real "cantidad"
		// Recibe: Valor num�rico real (cantidad)
		// Devuelve: True (1) si el objeto de la clase Dinero es mayor que
		//           "cantidad" y False (0) si no lo es 
		/*******************************************************************/
		bool EsMayor(double cantidad) {
						
			return ( GetValor() > cantidad );
		}
		
		/*******************************************************************/
		// M�todo: EsMenor()
		// Descripci�n: Comprueba si un objeto de la clase Dinero es menor
		//              que otro objeto de la clase Dinero
		// Recibe: Cantidad de dinero (otro)
		// Devuelve: True (1) si el objeto de la clase Dinero es menor que
		//           "otro" y False (0) si no lo es 
		/*******************************************************************/	
		bool EsMenor(Dinero otro) {
				
			return ( GetValor() < otro.GetValor() );
		}
	
		/*******************************************************************/
		// M�todo: EsMenor()
		// Descripci�n: Comprueba si un objeto de la clase Dinero es menor
		//              que el valor num�rico real "cantidad"
		// Recibe: Valor num�rico real (cantidad)
		// Devuelve: True (1) si el objeto de la clase Dinero es menor que
		//           "cantidad" y False (0) si no lo es 
		/*******************************************************************/
		bool EsMenor(double cantidad) {
					
			return ( GetValor() < cantidad );
		}
		
		/*******************************************************************/
		// M�todo: EsIgual()
		// Descripci�n: Comprueba si un objeto de la clase Dinero es igual
		//              que otro objeto de la clase Dinero
		// Recibe: Cantidad de dinero (otro)
		// Devuelve: True (1) si el objeto de la clase Dinero es igual que
		//           "otro" y False (0) si no lo es 
		/*******************************************************************/
		bool EsIgual(Dinero otro) {
			
			return ( SonIguales( GetValor(), otro.GetValor() ) );
		}
		
		/*******************************************************************/
		// M�todo: EsIgual()
		// Descripci�n: Comprueba si un objeto de la clase Dinero es igual
		//              que el valor num�rico real "cantidad"
		// Recibe: Valor num�rico real (cantidad)
		// Devuelve: True (1) si el objeto de la clase Dinero es igual que
		//           "cantidad" y False (0) si no lo es 
		/*******************************************************************/
		bool EsIgual(double cantidad) {
			
			return ( SonIguales( GetValor(), cantidad ) );
		}
		
		/*******************************************************************/
		// M�todo: Diferencia()
		// Descripci�n: Calcula la diferencia entre la cantidad de dinero de
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
		// M�todo: Diferencia()
		// Descripci�n: Calcula la diferencia entre la cantidad de dinero de
		//              un objeto de la clase Dinero y el valor num�rico real
		//              "cantidad"
		// Recibe: Valor num�rico real (cantidad)
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
		// M�todo: ToString()
		// Descripci�n: Representa en forma de cadena los valores de un 
		//              objeto de la clase Dinero
		// Recibe: N�mero de casillas con el que queremos formatear el 
		//         valor de los euros (num_casillas_euros),
		//         Car�cter con el que se rellenaran las casillas si 
		//         el n�mero de casillas es mayor que el n�mero de 
		//         d�gitos (caracter_hueco) 
		// Devuelve: String con la representaci�n textual de un objeto
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
		// M�todo: IncrementaEuros()
		// Descripci�n: Modifica el valor del campo "euros" del objeto 
		//              de la clase Dinero sum�ndole la cantidad dada
		//              en el valor num�rico "euros_a_sumar"
		// Recibe: Euros a sumar (euros_a_sumar)
		// Devuelve: -
		// PRE: 0 <= euros_a_sumar
		/*******************************************************************/
		void IncrementaEuros(int euros_a_sumar) {
			
			if(euros_a_sumar >= 0)
				euros += euros_a_sumar;
		}
		
		/*******************************************************************/
		// M�todo: IncrementaCentimos()
		// Descripci�n: Modifica el valor del campo "centimos" del objeto 
		//              de la clase Dinero sum�ndole la cantidad dada
		//              en el valor num�rico "centimos_a_sumar". Si 
		//              "centimos_suman" es mayor o igual que 100 ajusta su 
		//              valor para garantizar la validez del campo 
		//              "centimos" (entre 0 y 99) y actualiza el valor del 
		//              campo "euros".
		// Recibe: C�ntimos a sumar (centimos_a_sumar)
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
		// M�todo: NumDigitos()
		// Descripci�n: Calcula y devuelve el n�mero de d�gitos de un n�mero
		//              entero
		// Recibe: N�mero entero (numero)
		// Devuelve: N�mero de d�gitos de "numero" (num_digitos)
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
// Clase DepositoBancario: sirve para simular pr�stamos
/***************************************************************************/
class DepositoBancario {
	
	private:
		
		// PRE: 0 <= capital.GetValor()
		Dinero capital; 
		
		// PRE: 0 < interes <= 100
		double interes; 
		
	public:
		
		/*******************************************************************/
		// Constructor sin par�metros
		/*******************************************************************/
		DepositoBancario() : capital( Dinero(0) ), interes(0) { };
		
		/*******************************************************************/
		// Constructor con par�metros
		/*******************************************************************/
		DepositoBancario(Dinero valor_capital, double valor_interes) 
		                : capital(valor_capital), interes(valor_interes) { }
		
		/*******************************************************************/
		// M�todo: GetCapital()
		// Descripci�n: Devuelve el capital
		// Recibe: -
		// Devuelve: Capital (capital)
		/*******************************************************************/
		Dinero GetCapital() {
			
			return capital;	
		}
		
		/*******************************************************************/
		// M�todo: GetInteres()
		// Descripci�n: Devuelve el inter�s
		// Recibe: -
		// Devuelve: Inter�s (interes)
		/*******************************************************************/
		Dinero GetInteres() {
			
			return interes;	
		}
            
    	/*******************************************************************/
		// M�todo: CapitalTrasAnios()
		// Descripci�n: Calcula el capital resultante tras aplicarle el
		//              interes durante un n�mero de a�os dado.
		// Recibe: N�mero de a�os (anios)
		// Devuelve: Capital tras aplicar durante "anios" a�os el interes 
		//           (resultado)
		/*******************************************************************/
		Dinero CapitalTrasAnios(int anios) {
			
			Dinero resultado;
			
			resultado.SetEuros( capital.GetEuros() );
			resultado.SetCentimos( capital.GetCentimos() );
			
			double valor_resultado = resultado.GetValor();
			
			for(int i = 1; i <= anios; i++) {
				
				valor_resultado *= ( 1 + (interes / 100) );
			}
			
			resultado.SetValor(valor_resultado);
			
			return resultado;
		}
		
		/*******************************************************************/
		// M�todo: AniosHastaMultiplicarCapital()
		// Descripci�n: Calcula el numero de a�os que han de pasar para
		//              obtener un m�ltiplo del capital que se tiene
		//              actualmente tras aplicarle el interes.
		// Recibe: N�mero por el cual queremos multiplicar el
		//         capital actual (multiplo_capital)
		// Devuelve: N�mero de a�os que han de pasar para obtener
		//           "multiplo_capital * capital.GetValor()" (anios)
		/*******************************************************************/
		int AniosHastaMultiplicarCapital(double multiplo_capital) {
			
			int anios = 0;
						
			double valor_capital = capital.GetValor();
			
			while(valor_capital < (multiplo_capital * capital.GetValor() ) ) {
			     	
				valor_capital *= ( 1 + (interes / 100) );
				
			    anios++;
			}
			
			return anios;
		}
		
		/*******************************************************************/
		// M�todo: ToString()
		// Descripci�n: Representa en forma de cadena los valores de un 
		//              objeto de la clase DepositoBancario
		// Recibe: -
		// Devuelve: String con la representaci�n textual de un objeto
		//           de la clase DepositoBancario (cadena)
		/*******************************************************************/
		string ToString() {

			string cadena; 
	
			cadena = cadena + "\t Capital: " + "\n\n"
			                + "\t\t Euros: " + to_string(capital.GetEuros() ) 
							+ "\n" 
							+ "\t\t Centimos: " 
							+ to_string(capital.GetCentimos() ) + "\n\n"
							+ "\t Interes: " + to_string(interes) + " %" + "\n";
		
			return cadena;
		}
};

/***************************************************************************/
// Funci�n principal
/***************************************************************************/
int main() {
	
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	// Declaraci�n de variables y objetos
	
	Lector lector_deposito_bancario;
	int euros, centimos;
	double interes;
	
	// Entradas de datos
	
	// Capital
	
	cout << " Introduzca un precio: " << endl << endl;
	lector_deposito_bancario.SetTitulo(" \t Euros: ");
	euros = lector_deposito_bancario.LeeEnteroMayorOIgual(0);
	lector_deposito_bancario.SetTitulo(" \t Centimos: ");
	centimos = lector_deposito_bancario.LeeEnteroMayorOIgual(0);
	
	Dinero capital(euros, centimos);
	
	// Inter�s
	
	cout << endl;
	lector_deposito_bancario.SetTitulo(" Introduzca un interes (0-100]: ");
	interes = lector_deposito_bancario.LeeDoubleMayor(0);
	
	// Dep�sito Bancario
	
	DepositoBancario deposito(capital, interes);
	
	cout << endl;
	cout << " Deposito bancario: " << endl << endl;
	cout << deposito.ToString() << endl << endl;

	// C�lculos y Salidas
		
	// M�todo AniosHastaMultiplicarCapital de la clase DepositoBancario
	
	int multiplicar_capital;
	
	lector_deposito_bancario.SetTitulo
	                        (" Por cuanto quisiera multiplicar su capital?: ");
	multiplicar_capital = lector_deposito_bancario.LeeDoubleMayorOIgual(1.0);
	
	int anios = deposito.AniosHastaMultiplicarCapital(multiplicar_capital);
	
	cout << endl;
	cout << "\t Tienen que pasar " << anios << " anios para tener un capital"
	     << " mayor (o igual) que " << multiplicar_capital << " veces su"
		 << " capital actual" << endl << endl;
	
	// M�todo CapitalTrasAnios de la clase DepositoBancario

	cout << "\t El capital resultante tras esos " << anios << " anios seria"
	     << " igual a " << deposito.CapitalTrasAnios(anios).ToString(4, '#') 
	     << " euros";
	
	cout << endl << endl;
         
	return 0;
}
