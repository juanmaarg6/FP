/*
	Relación de ejercicios 5

	Ejercicio 4: Programa que calcula el precio final de un producto a partir 
	             de su precio inicial, de un incremento fijo mensual y de 
				 un número de meses. El programa irá mostrando, mes a mes, 
				 el precio del producto.
				 
				 Para ello se hace uso de la clase Dinero.
	              
	Entradas: Precio inicial del producto (euros_producto_inicial, 
	          centimos_producto_inicial),
	          Numero de meses (meses)
	Salidas: Precio mensual del producto (precio_mensual),
	         Precio final del producto (precio_final).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <string>

using namespace std;

/***************************************************************************/
// Clase Dinero: representa una cantidad de dinero dada en euros y 
//               céntimos.
/***************************************************************************/
class Dinero {
	
	private:
		
		// PRE: euros >= 0, centimos >= 0
		int euros;			// Euros de la cantidad de dinero
		int centimos;		// Céntimos de la cantidad de dinero
		
		/*******************************************************************/
		// Método: AjustarDinero()
		// Descripción: Ajusta la cantidad de dinero dada si centimos >= 100
		// Recibe: -
		// Devuelve: -
		/*******************************************************************/
		void AjustarDinero() {
					
			int total_centimos = CalcularTotalCentimos();
			
			CalcularCantidadDeDinero(total_centimos);
		}
		
	public:
		
		/*******************************************************************/
		// Constructor sin parámetros
		/*******************************************************************/
		Dinero() {
			
			euros = 0;
			centimos = 0;
		}
		
		/*******************************************************************/
		// Constructor con parámetros
		// PRE: valor_euros >= 0, valor_centimos >= 0
		/*******************************************************************/
		Dinero(int valor_euros, int valor_centimos)
		      : euros(valor_euros), centimos(valor_centimos) {
			
			AjustarDinero();
		}
		
		/*******************************************************************/
		// Método: SetEuros()
		// Descripción: Establece los euros de una cantidad de dinero
		// Recibe: Euros de una cantidad de dinero (valor_euros)
		// Devuelve: -
		// PRE: valor_euros >= 0
		/*******************************************************************/
		void SetEuros(int valor_euros) {
			
			euros = valor_euros;
			
			AjustarDinero();
		}
		
		/*******************************************************************/
		// Método: SetCentimos()
		// Descripción: Establece los céntimos de una cantidad de dinero
		// Recibe: céntimos de una cantidad de dinero (valor_centimos)
		// Devuelve: -
		// PRE: valor_centimos >= 0
		/*******************************************************************/
		void SetCentimos(int valor_centimos) {
		
			centimos = valor_centimos;	
			
			AjustarDinero();
		}
		
		/*******************************************************************/
		// Método: GetEuros()
		// Descripción: Devuelve los euros de una cantidad de dinero
		// Recibe: -
		// Devuelve: Euros de una cantidad de dinero (euros)
		/*******************************************************************/
		int GetEuros() {
			
			return euros;	
		}
		
		/*******************************************************************/
		// Método: GetCentimos()
		// Descripción: Devuelve los céntimos de una cantidad de dinero
		// Recibe: -
		// Devuelve: céntimos de una cantidad de dinero (centimos)
		/*******************************************************************/
		int GetCentimos() {
			
			return centimos;	
		}
		
		/*******************************************************************/
		// Método: CalcularTotalCentimos()
		// Descripción: Devuelve una cantidad de dinero en céntimos
		// Recibe: -
		// Devuelve: Cantidad de dinero en céntimos (total_centimos)
		/*******************************************************************/
		int CalcularTotalCentimos() {
			
			const int CENTIMOS_EN_EURO = 100;
			
			int total_centimos = (euros * CENTIMOS_EN_EURO) + centimos;	
			
			return total_centimos;
		}
		
		/*******************************************************************/
		// Método: CalcularCantidadDeDinero()
		// Descripción: Establece una cantidad de dinero en euros y céntimos
		//              a partir de una cantidad de dinero en céntimos
		// Recibe: Cantidad de dinero en céntimos (total_centimos)
		// Devuelve: -
		/*******************************************************************/
		void CalcularCantidadDeDinero(int total_centimos) {
			
			const int CENTIMOS_EN_EURO = 100;
			
			euros = total_centimos / CENTIMOS_EN_EURO;
			centimos = total_centimos % CENTIMOS_EN_EURO;
		}
		
		/*******************************************************************/
		// Método: ToString()
		// Descripción: Devuelve un string con una cantidad de dinero
		// Recibe: -
		// Devuelve: String con una cantidad de dinero (cad)
		/*******************************************************************/
		string ToString() {
			
			string cad;
			
			cad = to_string(euros) + " euros y " + to_string(centimos)
			      + " centimos";
				  
			return cad;	
		}
};

/***************************************************************************/
// Función: EliminaPrimerosSeparadores()
// Descripción: Devuelve una nueva cadena, resultante de eliminar los 
//              primeros caracteres separadores de "cadena"
// Recibe: String sobre la que se va a trabajar (cadena)
// Devuelve: String resultante de eliminar los primeros separadores de 
//           "cadena" (local)
/***************************************************************************/
string EliminaPrimerosSeparadores(string cadena) {	

	int pos = 0;
	
	int longitud_cadena = cadena.length();
	
	while( ( pos < longitud_cadena ) && ( isspace(cadena.at(pos)) ) ) 
		pos++;
	
	string cadena_resultante; 
	
	while(pos < longitud_cadena) {
		cadena_resultante.push_back(cadena.at(pos));
		pos++;
	}
		
	return cadena_resultante;
}

/***************************************************************************/
// Función: EliminaUltimosSeparadores()
// Descripción: Devuelve una nueva cadena, resultante de eliminar los 
//              últimos caracteres separadores de "cadena"
// Recibe: String sobre la que se va a trabajar (cadena)
// Devuelve: String resultante de eliminar los últimos separadores de 
//           "cadena" (cadena)
/***************************************************************************/
string EliminaUltimosSeparadores(string cadena) {

   	while( ( cadena.length() > 0 ) && ( isspace(cadena.back()) ) )
		cadena.pop_back();
        
	return cadena;
}

/***************************************************************************/
// Función: EliminaSeparadoresInicialesyFinales()
// Descripción: Devuelve una nueva cadena, resultante de eliminar los 
//              caracteres separadores iniciales y finales de "cadena"
// Recibe: String sobre la que se va a trabajar (cadena)
// Devuelve: String resultante de eliminar los separadores iniciales y finales
//			 de "cadena" (cadena)
/***************************************************************************/
string EliminaSeparadoresInicialesyFinales(string cadena) {	

	string cadena_resultante = EliminaUltimosSeparadores(
	                        		EliminaPrimerosSeparadores(cadena));
	                        		
	return cadena_resultante; 
}

/***************************************************************************/
// Función: LeeEntero()
// Descripción: Lee un número entero
// Recibe: Texto que etiqueta la lectura (titulo).
// Devuelve: Número entero (numero).
/***************************************************************************/
int LeeEntero(string titulo) {
	
	string numero;
	bool es_entero = true;
	
	do {
		
		es_entero = true;
		cout << titulo;	

		getline (cin, numero);
		
		int longitud_numero_con_separadores = numero.length();
		
		if(longitud_numero_con_separadores > 0) {
			
			numero = EliminaSeparadoresInicialesyFinales(numero);

			int longitud_numero_sin_separadores = numero.length();
			
			int i = 0;
			
			if( (numero[0] == '-') || (numero[0] == '+') )
				i = 1;
	
			while( (i <longitud_numero_sin_separadores) && es_entero) {
				
				if( (numero[i] < '0') || (numero[i] > '9') )
					es_entero = false;
					
				i++;
			}
		}
		else
			es_entero = false;		

	}while(!es_entero);

	return stoi(numero); 
}

/***************************************************************************/
// Función: LeeEnteroEnRango()
// Descripción: Lee un número entero dentro del rango ["menor" , "mayor"]
// Recibe: Texto que etiqueta la lectura (titulo),
//		   Valor mínimo del rango (menor),
//		   Valor máximo del rango (mayor)
// Devuelve: Número entero dentro del rango (numero)
/***************************************************************************/
int LeeEnteroEnRango(string titulo, int menor, int mayor) {
	
	int numero; 
	
	do {
		numero = LeeEntero(titulo);		
	}while( (numero < menor) || (numero > mayor) );
	
	return numero;	
}

/***************************************************************************/
// Función: LeeEnteroMayorOIgual()
// Descripción: Lee un número entero mayor o igual que "referencia"
// Recibe: Texto que etiqueta la lectura (titulo),
//		   Número entero de referencia (referencia)
// Devuelve: Número entero mayor o igual que "referencia" (numero)
/***************************************************************************/
int LeeEnteroMayorOIgual(string titulo, int referencia) {
	
	int numero; 
	
	do {
		numero = LeeEntero(titulo);		
	}while(numero < referencia);
	
	return numero;	
}


/***************************************************************************/
// Función: LeeDouble()
// Descripción: Lee un número real
// Recibe: Texto que etiqueta la lectura (titulo).
// Devuelve: Número real (numero).
/***************************************************************************/
double LeeDouble(string titulo) {
	
	string numero;
	bool hay_punto = false;
	bool es_double = true;
	
	do {
		
		es_double = true;
		cout << titulo;	
	
		getline (cin, numero);
		
		int longitud_numero_con_separadores = numero.length();
		
		if(longitud_numero_con_separadores > 0) {
			
			numero = EliminaSeparadoresInicialesyFinales(numero);

			int longitud_numero_sin_separadores = numero.length();
			
			int i = 0;
			
			if( (numero[0] == '-') || (numero[0] == '+') )
				i = 1;
				
			while( (i <longitud_numero_sin_separadores) && es_double ) {
				
				if( (numero[i] < '0') || (numero[i] > '9') ) {
					if(numero[i] == '.') {
						if (!hay_punto)
							hay_punto = true;	
						else
							es_double = false;
					}
					else
						es_double = false;
				}
				
				i++;
			}	
		}
		else
			es_double = false;		

	}while(!es_double);

	return stod(numero); 
}

/***************************************************************************/
// Función: LeeDoubleMayorOIgual()
// Descripción: Lee un número real mayor o igual que "referencia"
// Recibe: Texto que etiqueta la lectura (titulo),
//		   Número real de referencia (referencia)
// Devuelve: Número real mayor o igual que "referencia" (numero)
/***************************************************************************/
double LeeDoubleMayorOIgual(string titulo, double referencia) {
	
	double numero; 
	
	do {
		numero = LeeDouble(titulo);		
	}while(numero < referencia);
	
	return numero;	
}


/***************************************************************************/
// Función principal
/***************************************************************************/
int main() {
	
	// Declaración de constantes
	
	const int CENTIMOS_EN_EURO = 100;
	
	// Declaración de variables
	
	int euros_producto_inicial, centimos_producto_inicial;
	double incremento_mensual;
	int meses;
	
	// Entradas de datos
	
	cout << " Precio inicial del articulo: " << endl;

	euros_producto_inicial = LeeEnteroMayorOIgual("\t Euros: ", 0);
	centimos_producto_inicial = LeeEnteroMayorOIgual("\t Centimos: ", 0);
	
	incremento_mensual = LeeDoubleMayorOIgual(
	                               " Incremento fijo mensual (en euros): ", 0);
	                                    
	meses = LeeEnteroMayorOIgual(" Numero de meses: ", 1);
	
	// Declaración e inicialización (CONSTRUCTOR) del objeto "precio_inicial"
	// Hemos asegurado el cumplimiento de las precondiciones
	
	Dinero precio_inicial(euros_producto_inicial, centimos_producto_inicial);
	
	cout << endl;
	cout << " Precio inicial del articulo: " << precio_inicial.ToString();
	cout << endl << endl;
	
	// Declaración del objeto "precio_inicial" y asignación de "precio_inicial"
	// a "precio_mensual"
	
	Dinero precio_mensual;
	
	precio_mensual = precio_inicial;
	
	// Cálculos y salidas de datos
	
	// Precio del artículo cada mes
	for(int i = 1; i <= meses; i++) {
		
		int total_centimos = precio_mensual.CalcularTotalCentimos();
		
		total_centimos += incremento_mensual * CENTIMOS_EN_EURO;
		
		precio_mensual.CalcularCantidadDeDinero(total_centimos);
		
		cout << " Precio del articulo (Tras el mes " << i << "): " 
		     << precio_mensual.ToString() << endl;
	}
	
	// Declaración del objeto "precio_final" y asignación de "precio_mensual"
	// a "precio_final"
	Dinero precio_final;
	
	precio_final = precio_mensual;
	
	cout << endl;
	cout << " Precio final del articulo: " << precio_final.ToString();
	cout << endl << endl;
		
	return 0;	
}
