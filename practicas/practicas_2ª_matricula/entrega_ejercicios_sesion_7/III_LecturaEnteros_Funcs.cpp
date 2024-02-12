/*
	Relaci�n de ejercicios 3

	Ejercicio 18: Programa que lee:
	
	              	a) Un n�mero entero.
	              	b) Un n�mero entero en un rango dado.
	              	c) Un n�mero entero mayor que otro dado.
	
	Entradas: N�meros enteros (entero, entero_en_rango, entero_mayor_o_igual).
	Salidas: N�meros enteros le�dos (entero, entero_en_rango, 
	                                 entero_mayor_o_igual).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>		// Inclusi�n de los recursos de E/S

using namespace std;

/***************************************************************************/
// Funci�n: LeeEntero
// Recibe: Texto que etiqueta la lectura (titulo).
// Devuelve: N�mero entero.
/***************************************************************************/
int LeeEntero(string titulo) {
	
	int entero;
	string cadena_entrada;
	bool numero_negativo,
	     es_entero;
	
	do {
		
		es_entero = true;
		
		cout << titulo;
		cin >> cadena_entrada;
		
		numero_negativo = (cadena_entrada.at(0) == '-');
		
		// Si 'cadena_entrada' es un n�mero negativo (tiene el signo "-" 
		// en la primera posici�n), eliminamos el signo y solo nos quedamos
		// con el n�mero
		if(numero_negativo)
			cadena_entrada = cadena_entrada.substr(1, cadena_entrada.length());
			
		int longitud_cadena_entrada = cadena_entrada.length();
		
		// Comprobamos si cada car�cter de 'cadena_entrada' es un d�gito
		for(int i = 0; ( i < longitud_cadena_entrada ) && es_entero; i++)
			if( !( isdigit( cadena_entrada.at(i) ) ) )
				es_entero = false;
	}while( !(es_entero) );
	
	// Si 'cadena_entrada' era un n�mero negativo (ten�a el signo "-" 
	// en la primera posici�n), le a�adimos el signo "-" que le eliminamos
	// anteriormente
	if(numero_negativo)
		cadena_entrada = "-" + cadena_entrada;
	
	entero = stoi(cadena_entrada);
	
	return entero;
}

/***************************************************************************/
// Funci�n: LeeEnteroEnRango
// Recibe: Texto que etiqueta la lectura (titulo),
//		   Valor m�nimo del rango (menor),
//		   Valor m�ximo del rango (mayor).
// Devuelve: N�mero entero dentro del rango.
/***************************************************************************/
int LeeEnteroEnRango(string titulo, int menor, int mayor) {
	
	int entero_en_rango;
	
	do {
		entero_en_rango = LeeEntero(titulo);
	}while( (entero_en_rango < menor) || (entero_en_rango > mayor) );
	
	return entero_en_rango;
}

/***************************************************************************/
// Funci�n: LeeEnteroMayorOIgual
// Recibe: Texto que etiqueta la lectura (titulo),
//		   N�mero entero de referencia (referencia).
// Devuelve: N�mero entero mayor o igual que 'referencia'.
/***************************************************************************/
int LeeEnteroMayorOIgual(string titulo, int referencia) {
	
	int entero_mayor_o_igual;
	
	do {
		entero_mayor_o_igual = LeeEntero(titulo);
	}while(entero_mayor_o_igual < referencia);
		
	return entero_mayor_o_igual;	
}

/***************************************************************************/
// Funci�n principal
/***************************************************************************/
int main() {
	
	// Declaraci�n de variables
	
	int entero, 
	    entero_en_rango, 
		entero_mayor_o_igual;
	
	// Entradas de datos
	
	entero = LeeEntero(" Introduzca un numero entero: ");
	entero_en_rango = LeeEnteroEnRango
	                  (" Introduzca un numero entero del rango [0,100] ", 
					   0, 100);
	entero_mayor_o_igual = LeeEnteroMayorOIgual
	                       (" Introduzca un numero entero mayor o igual a 10: ",
						    10);
	
	// Salidas de datos
	
	cout << endl;
	cout << " Numero entero introducido: " << entero;
	cout << endl;
	cout << " Numero entero del rango [0,100] introducido: " 
	     << entero_en_rango;
	cout << endl;
	cout << " Numero entero mayor o igual a 10 introducido: " 
	     << entero_mayor_o_igual;
	cout << endl << endl;

	return 0;
}
