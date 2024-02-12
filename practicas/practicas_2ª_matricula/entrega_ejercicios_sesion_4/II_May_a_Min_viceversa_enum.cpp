/*
	Relaci�n de ejercicios 2

	Ejercicio 21: Programa que, dado un caracter:
				  
				  1) Si es una letra may�scula, muestra su correspondiente
				     letra min�scula.
				  2) Si es una letra min�scula, muestra su correspondiente
				     letra may�scula.
				  3) Si es un car�cter no alfab�tico, muestra que el car�cter
				     no es una letra.
				  
	
	Entradas: Letra original (letra_original).
	Salidas: Letra convertida (letra_convertida).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusi�n de los recursos de E/S

using namespace std;

// Programa principal

int main() {				

	// Declaraci�n de constantes
	
	const char PRIMERA_MAYUSCULA = 'A';
	const char ULTIMA_MAYUSCULA = 'Z';
	const char PRIMERA_MINUSCULA = 'a';
	const char ULTIMA_MINUSCULA = 'z';
	const int DISTANCIA_MAYUSCULA_MINUSCULA = PRIMERA_MINUSCULA 
	                                          - PRIMERA_MAYUSCULA;
	const char PRIMER_DIGITO = '0';
	const char ULTIMO_DIGITO = '9';

	// Declaraci�n de variables
	
	char letra_original, letra_convertida;
					
	// Entradas de datos
	
	cout << " Introduzca un caracter: ";
	cin >> letra_original;
		
	// C�lculos
	
	/*
		Algoritmo:
		
		Comprobar si el caracter introducido es una letra may�scula, una
		letra min�scula, un d�gito u otro car�cter.
		
		Si el car�cter introducido es una letra may�scula:
			El car�cter convertido va a ser la min�scula correspondiente.
		
		Si el car�cter introducido es una letra min�scula:
			El car�cter convertido va a ser la may�scula correspondiente.
		
		Si el car�cter introducido es un d�gito:
			El car�cter convertido va a ser el mismo d�gito.
			
		Si el car�cter introducido es otro car�cter:
			El car�cter convertido va a ser el mismo car�cter.
	*/
		
	enum class TipoCaracter {LetraMayuscula, LetraMinuscula, 
	                         Digito, OtroCaracter};
	
	TipoCaracter caracter;
	
	bool es_letra_mayuscula = ( (letra_original >= PRIMERA_MAYUSCULA) 
	                            && (letra_original <= ULTIMA_MAYUSCULA) );
	bool es_letra_minuscula = ( (letra_original >= PRIMERA_MINUSCULA) 
	                            && (letra_original <= ULTIMA_MINUSCULA) );
	bool es_digito = ( (letra_original >= PRIMER_DIGITO) 
	                    && (letra_original <= ULTIMO_DIGITO) );
	bool es_otro_caracter = ( !(es_letra_mayuscula) && !(es_letra_minuscula) 
	                          && !(es_digito));
				
	if(es_letra_mayuscula) {
		
		caracter = TipoCaracter::LetraMayuscula;
		letra_convertida = letra_original + DISTANCIA_MAYUSCULA_MINUSCULA;
	}
	
	if(es_letra_minuscula) {
		
		caracter = TipoCaracter::LetraMinuscula;
		letra_convertida = letra_original - DISTANCIA_MAYUSCULA_MINUSCULA;
	}
	
	if(es_digito) {
		
		caracter = TipoCaracter::Digito;
		letra_convertida = letra_original;
	}
			
	if(es_otro_caracter) {
			
		caracter = TipoCaracter::OtroCaracter;
		letra_convertida = letra_original;
	}
	
	// Salidas
	
	cout << endl;
	
	switch(caracter) {
		
		case(TipoCaracter::LetraMayuscula) :
			cout << " La letra era una mayuscula. Una vez convertida es '"
			     << letra_convertida << "'";
			break;

		case(TipoCaracter::LetraMinuscula) :
			cout << " La letra era una minuscula. Una vez convertida es '"
			     << letra_convertida << "'";
			break;
		
		case(TipoCaracter::Digito) :
			cout << " El caracter no era una letra, sino un digito";
			break;
			
		case(TipoCaracter::OtroCaracter) :
			cout << " El caracter no era ni una letra ni un digito";		
			break;
	}
	
	cout << endl << endl;				

	return 0;
}
