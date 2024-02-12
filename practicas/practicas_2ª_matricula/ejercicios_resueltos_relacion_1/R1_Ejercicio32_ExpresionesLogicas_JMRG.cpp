/*
	Relaci�n de ejercicios 1

	Ejercicio 32: Programa que:
	
				  1) Dada una expresi�n l�gica, esta es verdadera si una 
				     variable de tipo car�cter llamada letra es una letra 
					 may�scula y es falsa en otro caso.
					 
				  2) Dada una expresi�n l�gica, esta es verdadera si una 
				     variable de tipo entero llamada edad es mayor o igual que 
					 18 y menor que 67.
					 
				  3) Dada una expresi�n l�gica, nos informe cuando un a�o es 
				     bisiesto (los a�os bisiestos son aquellos que o bien son 
					 divisibles por 4 pero no por 100, o bien son divisibles 
					 por 400).
					 
				  4) Dada una expresi�n l�gica, nos informe si el valor de una 
				     variable double llamada distancia es menor que la 
					 constante LIMITE.
					 
				  5) Dadas tres variables l�gicas, una registra si el valor 
				     de una variable int es menor que otra, otra informa si son 
					 iguales y otra informa si es mayor.
	              
	Entradas: 1) Letra (letra).
	          2) Edad en a�os (edad).
	          3) A�o (anio).
	          4) Distancia en metros (distancia).
	          5) Dos n�meros enteros (numero1, numero2).
	Salidas: 1) '1' si la letra es may�scula o '0' si no lo es (es_mayuscula).
	         2) '1' si la edad es mayor o igual que 18 y menor que 67 
	            o '0' si no lo es (edad_correcta).
	         3) '1' si el a�o es bisiesto o '0' si no lo es (es_bisiesto).
	         4) '1' si la distancia es menor que un l�mite dado o 
	            '0' si no lo es (dist_menor_limite).
	         5) Comparaci�n entre los dos n�meros (numero1_menor_numero2, 
			    numero1_igual_numero2, numero1_mayor_numero2).
	            
	         

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusi�n de los recursos de E/S

using namespace std;

// Programa principal

int main() {				
			
    /**********************************************************************/
    
	// Declaraci�n de variables
	
	char letra = 'a';
	bool es_mayuscula = false;
								
	// Entradas de datos
	
	cout << " 1) Introduzca una letra: ";
	cin >> letra;
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Comprobar si la letra introducida est� comprendida entre la 'A' y la
		'Z' en el c�digo ASCII, es decir, si es may�scula.
	*/
	
	es_mayuscula = letra >= 'A' && letra <= 'Z';
	
	// Salidas
	
	cout << endl << "\t Letra mayuscula: " << es_mayuscula << endl << endl; 
	
    /**********************************************************************/
    
    // Declaraci�n de variables
	
	int edad = 0;
	bool edad_correcta = false;
								
	// Entradas de datos
	
	cout << " 2) Introduzca una edad: ";
	cin >> edad;
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Comprobar si la edad introducida es mayor o igual que 18 y menor que
		67.
	*/
	
	edad_correcta = edad >= 18 && edad < 67;
	
	// Salidas
	
	cout << endl << "\t Edad mayor o igual que 18 y menor que 67: " 
	     << edad_correcta << endl << endl; 
	
    /**********************************************************************/
    
    // Declaraci�n de variables
	
	int anio = 0;
	bool es_bisiesto = false;
								
	// Entradas de datos
	
	cout << " 3) Introduzca un anio: ";
	cin >> anio;
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Comprobar si el a�o introducido es bisiesto. Lo ser� si es divisible
		por 4 pero no por 100 o si es divisible por 400.
	*/
	
	es_bisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
	
	// Salidas
	
	cout << endl << "\t Anio bisiesto: " << es_bisiesto << endl << endl; 
	
    /**********************************************************************/
     
    // Declaraci�n de constantes
    
    const double LIMITE = 10.0;
    
    // Declaraci�n de variables
	
	double distancia = 0.0;
	bool dist_menor_limite = false;
								
	// Entradas de datos
	
	cout << " 4) Introduzca una distancia en metros: ";
	cin >> distancia;
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Comprobar si la distancia introducida es menor que la constante 
		LIMITE.
	*/
	
	dist_menor_limite = distancia < LIMITE;
	
	// Salidas
	
	cout << endl << "\t Distancia menor que LIMITE: " << dist_menor_limite 
	     << endl << endl; 
	
    /**********************************************************************/
    
    // Declaraci�n de variables
	
	int numero1 = 0, numero2 = 0;
	bool numero1_menor_numero2 = false;
	bool numero1_igual_numero2 = false;
	bool numero1_mayor_numero2 = false;
								
	// Entradas de datos
	
	cout << " 5) Introduzca el primer numero entero: ";
	cin >> numero1;
	cout << "    Introduzca el segundo numero entero: ";
	cin >> numero2;
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Comparar los dos n�meros introducidos (ver si el primer n�mero 
		introducido es menor, mayor o igual que el segundo n�mero introducido).
	*/
	
	numero1_menor_numero2 = numero1 < numero2;
	numero1_igual_numero2 = numero1 == numero2;
	numero1_mayor_numero2 = numero1 > numero2;

	// Salidas
	
	cout << endl << "\t Numero 1 menor que numero 2: " << numero1_menor_numero2 
	     << endl; 
	cout << endl << "\t Numero 1 igual que numero 2: " << numero1_igual_numero2 
	     << endl; 
	cout << endl << "\t Numero 1 mayor que numero 2: " << numero1_mayor_numero2 
	     << endl << endl; 
	
    /**********************************************************************/
    
	return 0;
}
