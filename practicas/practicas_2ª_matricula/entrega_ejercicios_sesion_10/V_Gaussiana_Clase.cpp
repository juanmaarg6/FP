/*
	Relación de ejercicios 5

	Ejercicio 7: Programa que, dada la media, la desviación típica muestra:
	              
	              a) El valor que toma la función gaussiana g(x) en un 
	                 punto de abscisa x, donde:
	                 
	                 													     2
	                                                      1      x - Media  ^
	                 									{--- * (----------)}
	                 				1				 ^    2     Desviación
				   g(x) = ------------------------- e 
					                     ---------
					       Desviación * V  2 * PI
	                 
	              b) El valor que toma la distribución acumulada CDF(x) en
	                 un punto de abscisa x, donde:
	                 		                 __
	                 		  			    /  \ x
	                 					   /
	                   		CDF(x) =      /         g(x) dx
	                        		     /
	                                  __/ - infinito
	                                  
	              c) El valor que toma la distribución acumulada CDF(x) en
	                 un punto de abscisa x, donde:
	                 
	                 CDF(x) ~ w = 1 - g(|x|)(b_1 * t + b_2 * t^2 + b_3 * t^3 + 
					                         b_4 * t^4 + b_5 * t^5) 
	                 
	                 
				                            1
				                 t = ---------------
				                     1 + (b_0 * |x|)
				                     
				     b_0 = 0,2316419 ; b_1 = 0,319381530 ; b_2 = -0,356563782 ;
					 b_3 = 1,781477937 ; b_4 = -1,821255978 ; b_5 = 1,330274429
					 
					 Tener en cuenta que 'x' es una variable estandarizada, 
					 luego:
					 
					               		  x - Media
					 		 		x = -------------
					 		      		 Desviación
					 		                    
					 Y para hallar g(|x|) habrá que tener en cuenta que, al ser
					 x una variable estandarizada, la media es igual a 0 y 
					 la desviación típico es igual a 1.
					 		      
					 Finalmente, si x >= 0, entonces CDF(x) = w. 
					 Si no, CDF(x) = 1 - w.
					 
				  El punto de abscisa 'x' se correspondrá a los valores
				  comprendidos en el intervalo 
				  [Media - 3 * Desviacion, Media + 3 * Desviacion] y
				  usaremos 0.25 como diferencia entre dos valores
				  consecutivos de x.
				  
				 Para ello se hace uso de la clase Gaussiana.
					 
	Entradas: Media (media),
	          Desviación típica (desviacion).
	Salidas: Valor que toma la función gaussiana en el punto de
	         abscisa x (gaussiana),
	         Distribución acumulada en el punto de abscisa x según la 
	         función del apartado b) (cdf_1),
	         Distribución acumulada en el punto de abscisa x según la 
	         función del apartado c) (cdf_2).
	         
	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/***************************************************************************/
// Clase Gaussiana: representa una función gaussiana.
/***************************************************************************/
class Gaussiana {
	
	private:
		
		// PRE: desviacion > 0
		double media;			// Media de la función gaussiana
		double desviacion;		// Desviación típica de la función gaussiana
		
	public:
		
		/*******************************************************************/
		// Constructor sin parámetros
		/*******************************************************************/
		Gaussiana() {
			
			media = 0.0;
			desviacion = 1.0;
		}
		
		/*******************************************************************/
		// Constructor con parámetros
		// PRE: valor_desviacion > 0
		/*******************************************************************/
		Gaussiana(double valor_media, double valor_desviacion)
		         : media(valor_media), desviacion(valor_desviacion) {
		         	
		}
		
		/*******************************************************************/
		// Método: SetMedia()
		// Descripción: Establece la media de una función gaussiana
		// Recibe: Media de una función gaussiana (valor_media)
		// Devuelve: -
		/*******************************************************************/
		void SetMedia(double valor_media) {
			
			media = valor_media;
		}
		
		/*******************************************************************/
		// Método: SetDesviacion()
		// Descripción: Establece la desviación de una función gaussiana
		// Recibe: Desviación de una función gaussiana (valor_desviacion)
		// Devuelve: -
		// PRE: valor_desviacion > 0
		/*******************************************************************/
		void SetDesviacion(double valor_desviacion) {
		
			desviacion = valor_desviacion;	
		}
		
		/*******************************************************************/
		// Método: GetMedia()
		// Descripción: Devuelve la media de una función gaussiana
		// Recibe: -
		// Devuelve: Media de una función gaussiana (media)
		/*******************************************************************/
		double GetMedia() {
			
			return media;	
		}
		
		/*******************************************************************/
		// Método: GetDesviacion()
		// Descripción: Devuelve la desviación de una función gaussiana
		// Recibe: -
		// Devuelve: Desviación de una función gaussiana (desviacion)
		/*******************************************************************/
		double GetDesviacion() {
			
			return desviacion;	
		}

		/*******************************************************************/
		// Método: CalcularValorGaussiana()
		// Recibe: Punto de abscisa 'x' (abscisa).
		// Devuelve: Valor que toma la función gaussiana en un punto de
		//			 abscisa 'x' (valor_gaussiana).
		/*******************************************************************/
		double CalcularValorGaussiana(double abscisa) {
	
			const double PI = asin(0.5) * 6;

			double valor_gaussiana;
			double fraccion, exponencial;
				
			fraccion = (1 / (desviacion * sqrt(2 * PI)));
			exponencial = exp(-0.5 * pow((abscisa - media) / desviacion, 2));
			valor_gaussiana =  fraccion * exponencial;
	
			return valor_gaussiana;
		}
		
		/*******************************************************************/
		// Método: Forma1CalcularCDF()
		// Recibe: Punto de abscisa 'x' (abscisa).
		// Devuelve: Distribución acumulada en un punto de abscisa 'x'.
		/*******************************************************************/
		double Forma1CalcularCDF(double abscisa) {
			
			double cdf = 0.0;
			
			const double SALTO = 0.001;
		
			double valor_gaussiana;
			double extremo_inferior_intervalo = media - (3 * desviacion);
			double incremento = extremo_inferior_intervalo;
			
			while(incremento < abscisa) {
					
				valor_gaussiana = CalcularValorGaussiana(incremento);
				
				cdf += valor_gaussiana;
				
				incremento += SALTO;
			}
			
			cdf *= SALTO;
			
			return cdf;
		}

		/*******************************************************************/
		// Función: Forma2CalcularCDF
		// Recibe: Punto de abscisa 'x' (abscisa).
		// Devuelve: Distribución acumulada en un punto de abscisa 'x'.
		/*******************************************************************/
		double Forma2CalcularCDF(double abscisa) {

			double cdf;
			
			const double B_0 = 0.2316419;
			const double B_1 = 0.319381530;
			const double B_2 = -0.356563782;
			const double B_3 = 1.781477937;
			const double B_4 = -1.821255978;
			const double B_5 = 1.330274429;
		
			const double MEDIA_ESTANDARIZADA = 0.0;
			const double DESVIACION_ESTANDARIZADA = 1.0;
			
			double variable_estandarizada, valor_abs_variable_estandarizada;
			double valor_gaussiana;
			double w, t;
			
			variable_estandarizada = (abscisa - media) / desviacion;
			
			media = MEDIA_ESTANDARIZADA;
			desviacion = DESVIACION_ESTANDARIZADA;
			
			valor_abs_variable_estandarizada = abs(variable_estandarizada);
			
			valor_gaussiana = CalcularValorGaussiana(
			                                valor_abs_variable_estandarizada);
				
			t = 1.0 / ( 1 + (B_0 * valor_abs_variable_estandarizada) );
			
			double t_1 = t;
			double t_2 = t_1 * t;
			double t_3 = t_2 * t;
			double t_4 = t_3 * t;
			double t_5 = t_4 * t;
			
			w = 1 - (valor_gaussiana * ( (B_1 * t_1) + (B_2 * t_2) + 
			                             (B_3 * t_3) + (B_4 * t_4) + 
										 (B_5 * t_5) 
								       ) );
				
			if(variable_estandarizada >= 0)
				cdf = w;
			else
				cdf = 1 - w;
			
			return cdf;
		}

		/*******************************************************************/
		// Método: ToString()
		// Descripción: Devuelve un string con una función gaussiana 
		//              representada de la forma N(media, desviacion)
		// Recibe: -
		// Devuelve: String con una función gaussiana (cad)
		/*******************************************************************/
		string ToString() {
			
			string cad;
			
			cad = "N ( " + to_string(media) + ", " + to_string(desviacion)
			      + ")";
				  
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
// Función: LeeDoubleEnRango()
// Descripción: Lee un número real dentro del rango ["menor" , "mayor"]
// Recibe: Texto que etiqueta la lectura (titulo),
//		   Valor mínimo del rango (menor),
//		   Valor máximo del rango (mayor)
// Devuelve: Número real dentro del rango (numero)
/***************************************************************************/
double LeeDoubleEnRango(string titulo, double menor, double mayor) {
	
	double numero; 
	
	do {
		numero = LeeDouble(titulo);		
	}while( (numero < menor) || (numero > mayor) );
	
	return numero;	
}

/***************************************************************************/
// Función: LeeDoubleMayor()
// Descripción: Lee un número real mayor que "referencia"
// Recibe: Texto que etiqueta la lectura (titulo),
//		   Número real de referencia (referencia)
// Devuelve: Número real mayor que "referencia" (numero)
/***************************************************************************/
double LeeDoubleMayor(string titulo, double referencia) {
	
	double numero; 
	
	do {
		numero = LeeDouble(titulo);		
	}while(numero <= referencia);
	
	return numero;	
}

/***************************************************************************/
// Función principal
/***************************************************************************/
int main() {
	
	// Declaración de constantes
	
	const double DIFERENCIA = 0.25;
		
	// Declaración de variables
 		             
	double media, desviacion;	
	double valor_gaussiana, cdf_1, cdf_2;			     
	
	// Entradas de datos
	
	media = LeeDouble(" Introduzca el valor de la media: ")	;			
	desviacion = LeeDoubleMayor(
	                 " Introduzca el valor de la desviacion tipica: ", 0);
	
	// Cálculos
	
	// Declaración e inicialización (CONSTRUCTOR) del objeto "gaussiana"
	// Hemos asegurado el cumplimiento de las precondiciones
	Gaussiana gaussiana(media, desviacion);
	
	cout << endl;
	cout << " Gaussiana: " << gaussiana.ToString();
	cout << endl;
	
	double limite_inferior = media - (3 * desviacion);
	double limite_superior = media + (3 * desviacion);
	
	for(double i = limite_inferior; i <= limite_superior; i+=DIFERENCIA) {

		valor_gaussiana = gaussiana.CalcularValorGaussiana(i);
		cdf_1 = gaussiana.Forma1CalcularCDF(i);
		cdf_2 = gaussiana.Forma2CalcularCDF(i);
		
		// Salidas
		
		cout << endl;
		cout << " Para x = " << i << ": ";
		cout << endl << endl;
		cout << "\t g(" << i << ") = " << valor_gaussiana;
		cout << endl;
		cout << "\t CDF_1(" << i << ") = " << cdf_1;
		cout << endl;
		cout << "\t CDF_2(" << i << ") = " << cdf_2;
		cout << endl;
				
		gaussiana.SetMedia(media);
		gaussiana.SetDesviacion(desviacion);
	}
	
	return 0;	
}
