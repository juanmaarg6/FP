/*
	Relaci�n de ejercicios 1

	Ejercicio 31: Programa que, dados varios ejemplos, se indica si se produce
	              un problema de precisi�n o de desbordamiento y se muestra
	              el resultado final de las operaciones.
	
	Entradas: -
	Salidas: Resultado final de las operaciones de los ejemplos (resultado_a,
	         resultado_b, resultado_c, resultado_d, resultado_e, resultado_f).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>		// Inclusi�n de los recursos de E/S

using namespace std;

// Programa principal

int main() {	

	cout.precision(20);

	// Declaraci�n de constantes
	
	const string SEPARADOR = "\n\n-----------------------------";
	
	/**********************************************************************/
	
	// APARTADO A)
	
	// Declaraci�n de variables
	
	int chico1_a, chico2_a;
	int resultado_a;
	
	// C�lculos
	
	chico1_a = 123456789;
	chico2_a = 123456780;
	
	resultado_a =  chico1_a * chico2_a;
	
	// Salidas
	
	cout << "Apartado a)";
	cout << "\n\n\tchico1_a = " << chico1_a;
	cout << "\n\tchico2_a = " << chico2_a;
	cout << "\n\n\tresultado_a = chico1_a * chico2_a ";
	cout << "\n\n\tresultado_a = " << resultado_a;
	cout << SEPARADOR;
	
	/* 
		Se declaran dos variables enteras (chico1_a, chico2_a), y se asignan en
		ambas un n�mero de 9 cifras. Despu�s se multiplican y el resultado se 
		almacena en la variable entera "resultado_a". Al mostrarse en pantalla, 
		se observa un resultado que no se ajusta ni se aproxima al valor real 
		del resultado. 
		
		El programa muestra como resultado el valor 142596044. El verdadero 
		resultado deber�a ser del orden de 10e17. Esto se debe a que el rango 
		de una variable tipo "int" no alcanza el verdadero resultado.
	
		Se produce: DESBORDAMIENTO DE MEMORIA.
	*/
	
	/**********************************************************************/
	
	// APARTADO B)
	
	// Declaraci�n de variables	
	
	int chico1_b, chico2_b;
	long resultado_b;
	
	// C�lculos
	
	chico1_b = 123456789;
	chico2_b = 123456780;
	
	resultado_b =  chico1_b * chico2_b;
	
	// Salidas
	
	cout << "\n\nApartado b)";
	cout << "\n\n\tchico1_b = " << chico1_b;
	cout << "\n\tchico2_b = " << chico2_b;
	cout << "\n\n\tresultado_b = chico1_b * chico2_b ";
	cout << "\n\n\tresultado_b = " << resultado_b;
	cout << SEPARADOR;
	
	/* 		
		Se declaran dos variables enteras (chico1_b, chico2_b), y se asignan en 
		ambas un n�mero de 9 cifras. Despu�s se multiplican y el resultado se 
		almacena en la variable entera "resultado_b". Al mostrarse en pantalla, 
		se observa un resultado que no se ajusta ni se aproxima al valor real 
		del resultado. 
		
		El programa muestra como resultado el valor 142596044. El verdadero
		resultado deber�a ser del orden de 10e17. Esto se debe a que el rango 
		de una variable tipo "long" no alcanza el verdadero resultado.
	
		Se produce: DESBORDAMIENTO DE MEMORIA.
	*/
	
	/**********************************************************************/
	
	// APARTADO C)
	
	// Declaraci�n de variables	
	
	double real1_c, real2_c;
	double resultado_c;
	
	// C�lculos
	
	real1_c = 123.1;
	real2_c = 124.2;
	
	resultado_c =  real1_c * real2_c;
	
	// Salidas
	
	cout << "\n\nApartado c)";
	cout << "\n\n\treal1_c = " << real1_c;
	cout << "\n\treal2_c = " << real2_c;
	cout << "\n\n\tresultado_c = real1_c * real2_c ";
	cout << "\n\n\tresultado_c = " << resultado_c;
	cout << SEPARADOR;
	
	/* 
		Se declaran dos variables reales (real1_c, real2_c), y se asignan en 
		ambas un n�mero de 3 cifras enteras y 1 cifra real. Despu�s se 
		multiplican y el resultado se almacena en la variable real 
		"resultado_a". Al mostrarse en pantalla, se observa un resultado con 
		m�s cifras decimales de las que tendr�a que haber realmente. 	
		
		El programa muestra como resultado el valor 15289.020000000000437. El 
		verdadero resultado deber�a ser 15289.02. Esto se debe a que toda parte
		real se representa siempre de forma	aproximada.
	
		Se produce: ERROR DE PRECISI�N.
	*/	
	
	/**********************************************************************/
	
	// APARTADO D)
	
	// Declaraci�n de variables		
	
	double real1_d, real2_d;
	double resultado_d;
	
	// C�lculos
	
	real1_d = 123456789.1;
	real2_d = 123456789.2;
	
	resultado_d =  real1_d * real2_d;
	
	// Salidas
	
	cout << "\n\nApartado d)";
	cout << "\n\n\treal1_d = " << real1_d;
	cout << "\n\treal2_d = " << real2_d;
	cout << "\n\n\tresultado_d = real1_d * real2_d ";
	cout << "\n\n\tresultado_d = " << resultado_d;
	cout << SEPARADOR;
	
	/* 		
		Se declaran dos variables reales (real1_d, real2_d), y se asignan en 
		ambas un n�mero de 9 cifras enteras y 1 cifra real. Despu�s se 
		multiplican y el resultado se almacena en la variable real 
		"resultado_d". Al mostrarse en pantalla, se observa un resultado sin
	    parte decimal. 	
		
		El programa muestra como resultado el valor 15241578787227558. El 
		verdadero resultado deber�a ser 15241578787227558.72. Esto se debe a 
		que el resultado tiene m�s de 16 d�gitos, de forma que su 
		representaci�n no es exacta (se pierden d�gitos).
	
		Se produce: ERROR DE PRECISI�N.
	*/	
	
	/**********************************************************************/
	
	// APARTADO E)
	
	// Declaraci�n de variables	
	
	double real_e, otro_real_e;
	double resultado_e;
	
	// C�lculos
	
	real_e = 2e34;
	
	otro_real_e = real_e + 1;
	resultado_e = otro_real_e - real_e;
		
	// Salidas
	
	cout << "\n\nApartado e)";
	cout << "\n\n\treal_e = " << real_e;
	cout << "\n\n\totro_real_e = real_e + 1 ";
	cout << "\n\tresultado_e = otro_real_e - real_e ";
	cout << "\n\n\tresultado_e = " << resultado_e;
	cout << SEPARADOR;
	
	/* 
		Se declaran dos variables reales (real_e, otro_real_e), y se asigna un 
		valor de 2e34 a la variable "real_e". Despu�s se asigna a la variable 
		"otro_real_e" el valor "real_e + 1". Finalmente, se calcula la 
		diferencia de esos n�meros y se almacena en "resultado_e". Al mostrarse 
		en pantalla, se observa un resultado err�neo. 	
		
		El programa muestra como resultado el valor 0. El verdadero resultado 
		deber�a ser 1. Esto se debe a que el n�mero 2e34 + 1 tiene m�s de 16 
		d�gitos, de forma que su representaci�n no es exacta (se pierden 
		d�gitos). As� que el resultado de 2e34 + 1 es 2e34.
	
		Se produce: ERROR DE PRECISI�N.
	*/
	
	/**********************************************************************/
	
	// APARTADO F)
	
	// Declaraci�n de variables	
	
	double real_f, otro_real_f;
	double resultado_f;
	
	// C�lculos
	
	real_f = 1e+300;
	otro_real_f = 1e+200;

	resultado_f = real_f * otro_real_f;
		
	// Salidas
	
	cout << "\n\nApartado f)";
	cout << "\n\n\treal_f = " << real_f;
	cout << "\n\totro_real_f = " << otro_real_f;
	cout << "\n\n\tresultado_f = real_f * otro_real_f ";
	cout << "\n\n\tresultado_f = " << resultado_f;
	cout << SEPARADOR;
	
	/* 		
		Se declaran dos variables reales (real_f, otro_real_f), y se asigna un 
		valor de 1e+300 a la variable "real_f" y un valor de 1e+200 a la 
		variable "otro_real_f". Despu�s se multiplican y el resultado se 
		almacena en la variable real "resultado_f". Al mostrarse en pantalla, 
		se observa un resultado err�neo.
		
		El programa muestra como resultado "inf", es decir, infinito. El 
		verdadero resultado deber�a ser 1e+500. Esto se debe a que los reales
		no se desbordan de la misma forma que los enteros, mostrando de
		esta forma "inf" (infinito).
	
		Se produce: DESBORDAMIENTO DE MEMORIA.
	*/
	
	/**********************************************************************/
	
	// APARTADO G)
	
	// Declaraci�n de variables	
	
	double grande_g;
	float chico_g;
	
	// C�lculos
	
	grande_g = 2e+150;

	chico_g = grande_g;
			
	// Salidas
	
	cout << "\n\nApartado g)";
	cout << "\n\n\tgrande_g = " << grande_g;
	cout << "\n\n\tchico_g = grande_g ";
	cout << "\n\n\tchico_g = " << chico_g;
	cout << SEPARADOR << "\n\n";
	
	/*
		Se declaran dos variables: una real (grande_g), y otro real en coma 
		flotante (chico_g). Se asigna un valor de 2e+150 a la variable 
		"grande_g". Despu�s se asigna ese mismo valor a la variable "chico_g".
		Al mostrarse en pantalla, se observa un resultado err�neo.
		
		El programa muestra como resultado "inf", es decir, infinito. El 
		verdadero resultado deber�a ser 2e+150. Esto se debe a que los reales 
		en coma flotante no se desbordan de la misma forma que los enteros, 
		mostrando de esta forma "inf" (infinito).
	
		Se produce: DESBORDAMIENTO DE MEMORIA.
	*/
	
	/**********************************************************************/
	
	return 0;
}
