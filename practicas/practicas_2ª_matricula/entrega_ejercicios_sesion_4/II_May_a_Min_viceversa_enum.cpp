/*
	Relación de ejercicios 2

	Ejercicio 21: Programa que, dado un caracter:
				  
				  1) Si es una letra mayúscula, muestra su correspondiente
				     letra minúscula.
				  2) Si es una letra minúscula, muestra su correspondiente
				     letra mayúscula.
				  3) Si es un carácter no alfabético, muestra que el carácter
				     no es una letra.
				  
	
	Entradas: Letra original (letra_original).
	Salidas: Letra convertida (letra_convertida).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>		// Inclusión de los recursos de E/S

using namespace std;

// Programa principal

int main() {				

	// Declaración de constantes
	
	const char PRIMERA_MAYUSCULA = 'A';
	const char ULTIMA_MAYUSCULA = 'Z';
	const char PRIMERA_MINUSCULA = 'a';
	const char ULTIMA_MINUSCULA = 'z';
	const int DISTANCIA_MAYUSCULA_MINUSCULA = PRIMERA_MINUSCULA 
	                                          - PRIMERA_MAYUSCULA;
	const char PRIMER_DIGITO = '0';
	const char ULTIMO_DIGITO = '9';

	// Declaración de variables
	
	char letra_original, letra_convertida;
					
	// Entradas de datos
	
	cout << " Introduzca un caracter: ";
	cin >> letra_original;
		
	// Cálculos
	
	/*
		Algoritmo:
		
		Comprobar si el caracter introducido es una letra mayúscula, una
		letra minúscula, un dígito u otro carácter.
		
		Si el carácter introducido es una letra mayúscula:
			El carácter convertido va a ser la minúscula correspondiente.
		
		Si el carácter introducido es una letra minúscula:
			El carácter convertido va a ser la mayúscula correspondiente.
		
		Si el carácter introducido es un dígito:
			El carácter convertido va a ser el mismo dígito.
			
		Si el carácter introducido es otro carácter:
			El carácter convertido va a ser el mismo carácter.
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
