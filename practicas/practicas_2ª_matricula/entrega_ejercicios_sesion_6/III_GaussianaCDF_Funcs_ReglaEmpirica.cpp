/*
	Relaci�n de ejercicios 3

	Ejercicio 30: Programa que, dada la media, la desviaci�n t�pica muestra:
	              
	              a) El valor que toma la funci�n gaussiana g(x) en un 
	                 punto de abscisa x, donde:
	                 
	                 													     2
	                                                      1      x - Media  ^
	                 									{--- * (----------)}
	                 				1				 ^    2     Desviaci�n
				   g(x) = ------------------------- e 
					                     ---------
					       Desviaci�n * V  2 * PI
	                 
	              b) El valor que toma la distribuci�n acumulada CDF(x) en
	                 un punto de abscisa x, donde:
	                 		                 __
	                 		  			    /  \ x
	                 					   /
	                   		CDF(x) =      /         g(x) dx
	                        		     /
	                                  __/ - infinito
	                                  
	              c) El valor que toma la distribuci�n acumulada CDF(x) en
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
					 		      		 Desviaci�n
					 		                    
					 Y para hallar g(|x|) habr� que tener en cuenta que, al ser
					 x una variable estandarizada, la media es igual a 0 y 
					 la desviaci�n t�pico es igual a 1.
					 		      
					 Finalmente, si x >= 0, entonces CDF(x) = w. 
					 Si no, CDF(x) = 1 - w.
					 
				  El punto de abscisa 'x' se correspondr� a los valores
				  comprendidos en el intervalo 
				  [Media - 3 * Desviacion, Media + 3 * Desviacion] y
				  usaremos 0.25 como diferencia entre dos valores
				  consecutivos de x.
					 
	Entradas: Media (media),
	          Desviaci�n t�pica (desviacion)
	Salidas: Valor que toma la funci�n gaussiana en el punto de
	         abscisa x (gaussiana),
	         Distribuci�n acumulada en el punto de abscisa x seg�n la 
	         funci�n del apartado b) (cdf_1)
	         Distribuci�n acumulada en el punto de abscisa x seg�n la 
	         funci�n del apartado c) (cdf_2)
	         
	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusi�n de los recursos de E/S
#include <cmath>		    // Inclusi�n de los recursos matematicos

using namespace std;

// Declaraci�n de constantes globales

const double PI = asin(0.5) * 6;

/***************************************************************************/
// Funci�n: LeerMedia
// Recibe: Texto que etiqueta la lectura (msg).
// Devuelve: Media de una distribuci�n gaussiana.
/***************************************************************************/
double LeerMedia(string msg) {		
	
	double media;
	
	cout << msg;
	cin >> media;
	
	return media;
}

/***************************************************************************/
// Funci�n: LeerDesviacionTipica
// Recibe: Texto que etiqueta la lectura (msg).
// Devuelve: Desviaci�n t�pica de una distribuci�n gaussiana.
/***************************************************************************/
double LeerDesviacionTipica(string msg) {		
	
	double desviacion;
	
	do {
		cout << msg;	
		cin >> desviacion;
	}while(desviacion <= 0);
	
	return desviacion;
}

/***************************************************************************/
// Funci�n: CalcularGaussiana
// Recibe: Media de la distribuci�n gaussiana (media),
//         Desviaci�n t�pica de la distribuci�n gaussiana (desviacion),
//         Punto de abscisa 'x' (abscisa).
// Devuelve: Valor que toma la funci�n gaussiana en un punto de
//			 abscisa 'x' (gaussiana).
/***************************************************************************/
double CalcularGaussiana(double media, double desviacion, double abscisa) {
	
	double gaussiana;
	double fraccion, exponencial;
	
	fraccion = (1 / (desviacion * sqrt(2 * PI)));
	exponencial = exp(-0.5 * pow((abscisa - media) / desviacion, 2));
	gaussiana =  fraccion * exponencial;
	
	return gaussiana;
}

/***************************************************************************/
// Funci�n: Forma1CalcularCDF
// Recibe: Media de la distribuci�n gaussiana (media),
//         Desviaci�n t�pica de la distribuci�n gaussiana (desviacion),
//         Punto de abscisa 'x' (abscisa).
// Devuelve: Distribuci�n acumulada en un punto de abscisa 'x' seg�n la 
//	         funci�n del apartado b).
/***************************************************************************/
double Forma1CalcularCDF(double media, double desviacion, double abscisa) {
	
	double cdf = 0.0;
	
	const double SALTO = 0.001;

	double gaussiana;
	double extremo_inferior_intervalo = media - (3 * desviacion);
	double incremento = extremo_inferior_intervalo;
	
	while(incremento < abscisa) {
			
		gaussiana = CalcularGaussiana(media, desviacion, incremento);
		
		cdf += gaussiana * SALTO;
		
		incremento += SALTO;
	}
	
	return cdf;
}

/***************************************************************************/
// Funci�n: Forma2CalcularCDF
// Recibe: Media de la distribuci�n gaussiana (media),
//         Desviaci�n t�pica de la distribuci�n gaussiana (desviacion),
//         Punto de abscisa 'x' (abscisa).
// Devuelve: Distribuci�n acumulada en un punto de abscisa 'x' seg�n la 
//	         funci�n del apartado c).
/***************************************************************************/
double Forma2CalcularCDF(double media, double desviacion, double abscisa) {
	
	double cdf;
	
	const double B_0 = 0.2316419;
	const double B_1 = 0.319381530;
	const double B_2 = -0.356563782;
	const double B_3 = 1.781477937;
	const double B_4 = -1.821255978;
	const double B_5 = 1.330274429;

	double MEDIA_ESTANDARIZADA = 0.0;
	double DESVIACION_ESTANDARIZADA = 1.0;
	
	double variable_estandarizada, valor_abs_variable_estandarizada;
	double gaussiana;
	double w, t;
	
	variable_estandarizada = (abscisa - media) / desviacion;
	valor_abs_variable_estandarizada = abs(variable_estandarizada);
	
	gaussiana = CalcularGaussiana(MEDIA_ESTANDARIZADA, 
	                              DESVIACION_ESTANDARIZADA, 
								  valor_abs_variable_estandarizada);
		
	t = 1.0 / ( 1 + (B_0 * valor_abs_variable_estandarizada) );
		
	w = 1 - (gaussiana * ( (B_1 * t) + (B_2 * t * t) + (B_3 * t * t * t) +
	                       (B_4 * t * t * t * t) + (B_5 * t * t * t * t * t) 
						 ) );
		
	if(variable_estandarizada >= 0)
		cdf = w;
	else
		cdf = 1 - w;
	
	return cdf;
}

/***************************************************************************/
// Funci�n principal
/***************************************************************************/
int main() {
	
	// Declaraci�n de constantes
	
	const double DIFERENCIA = 0.25;
		
	// Declaraci�n de variables
 		             
	double media, desviacion;	
	double gaussiana;			     
	double cdf_1;
	double cdf_2;

	// Entradas de datos
	
	media = LeerMedia(" Introduzca el valor de la media: ");				
	desviacion = LeerDesviacionTipica
	             (" Introduzca el valor de la desviacion tipica: ");
	
	// C�lculos
	
	double limite_inferior = media - (3 * desviacion);
	double limite_superior = media + (3 * desviacion);
	
	double i = limite_inferior;
	
	while(i <= limite_superior) {
		gaussiana = CalcularGaussiana(media, desviacion, i);
		cdf_1 = Forma1CalcularCDF(media, desviacion, i);
		cdf_2 = Forma2CalcularCDF(media, desviacion, i);
		
		// Salidas
		
		cout << endl;
		cout << " Para x = " << i << ": ";
		cout << endl << endl;
		cout << "\t g(" << i << ") = " << gaussiana;
		cout << endl;
		cout << "\t CDF_1(" << i << ") = " << cdf_1;
		cout << endl;
		cout << "\t CDF_2(" << i << ") = " << cdf_2;
		cout << endl;
		
		i+= DIFERENCIA;
	}
	
	return 0;
}
