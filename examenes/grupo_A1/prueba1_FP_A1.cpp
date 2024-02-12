#include <iostream>

using namespace std;

/***************************************************************************/
// Funci�n: LeerCaracter
// Recibe: -
// Devuelve: Car�cter le�do.
/***************************************************************************/
char LeerCaracter() {
	
	char caracter;
	
	cin >> caracter;
	
	return caracter;
}

/***************************************************************************/
// Funci�n: EsVocal
// Recibe: Car�cter (caracter).
// Devuelve: True (1) si el car�cter es una vocal y False (0) si no lo es.
/***************************************************************************/
bool EsVocal(char caracter) {

	const char MAYUSCULA_A = 'A';
	const char MAYUSCULA_E = 'E';
	const char MAYUSCULA_I = 'I';
	const char MAYUSCULA_O = 'O';
	const char MAYUSCULA_U = 'U';
	
	char caracter_mayuscula = toupper(caracter);

	bool es_vocal = ( (caracter_mayuscula == MAYUSCULA_A) || 
	                  (caracter_mayuscula == MAYUSCULA_E) || 
	                  (caracter_mayuscula == MAYUSCULA_I) || 
	                  (caracter_mayuscula == MAYUSCULA_O) || 
	                  (caracter_mayuscula == MAYUSCULA_U) );
	
	return es_vocal;	
}

/***************************************************************************/
// Funci�n: EsConsonante
// Recibe: Car�cter (caracter).
// Devuelve: True (1) si el car�cter es una consonante y False (0) si no lo es.
/***************************************************************************/
bool EsConsonante(char caracter) {

	const char MAYUSCULA_A = 'A';
	const char MAYUSCULA_Z = 'Z';
	
	bool es_consonante = false;
	
	char caracter_mayuscula = toupper(caracter);
	
	bool es_una_letra_mayuscula = ( (caracter_mayuscula >= MAYUSCULA_A) && 
	                                (caracter_mayuscula <= MAYUSCULA_Z) );
	bool no_es_vocal = !( EsVocal(caracter) );
	
	if(es_una_letra_mayuscula && no_es_vocal )
		es_consonante = true;
	
	return es_consonante;	
}

/***************************************************************************/
// Funci�n: EsDigito
// Recibe: Car�cter (caracter).
// Devuelve: True (1) si el car�cter es un d�gito y False (0) si no lo es.
/***************************************************************************/
bool EsDigito(char caracter) {

	const char DIGITO_0 = '0';
	const char DIGITO_9 = '9';
	
	bool es_digito = ( (caracter >= DIGITO_0) && (caracter <= DIGITO_9) );	
	
	return es_digito;	
}

/***************************************************************************/
// Funci�n: MostrarCategoriaGanadora
// Recibe: N�mero de vocales de la secuencia de caracteres (numero_de_vocales),
//         N�mero de consonantes de la secuencia de 
//         caracteres (numero_de_consonantes),
//         N�mero de digitos de la secuencia de caracteres (numero_de_digitos).
// Devuelve: -
/***************************************************************************/
void MostrarCategoriaGanadora(int numero_de_vocales, int numero_de_consonantes, 
                              int numero_de_digitos) {
	
	bool ganan_vocales = ( (numero_de_vocales > numero_de_consonantes) && 
	                       (numero_de_vocales > numero_de_digitos) );
	   
	bool ganan_consonantes = ( (numero_de_consonantes > numero_de_vocales) && 
	                           (numero_de_consonantes > numero_de_digitos) );

	bool ganan_digitos = ( (numero_de_digitos > numero_de_vocales) && 
	                       (numero_de_digitos > numero_de_consonantes) );
							   					                       
	if(ganan_vocales)
		cout << " La categoria ganadora es 'vocales' con un total de "
		     << numero_de_vocales << " valores leidos.";
	else if(ganan_consonantes)
		cout << " La categoria ganadora es 'consonantes' con un total de "
		     << numero_de_consonantes << " valores leidos.";
	else if(ganan_digitos)
		cout << " La categoria ganadora es 'digitos' con un total de "
		     << numero_de_digitos << " valores leidos.";
	else
		cout << " Hay un empate, luego, no ha ganado ninguna categoria.";
	}

/***************************************************************************/
// Funci�n principal
/***************************************************************************/
int main() {
	
	// Declaraci�n de constantes
	
	const char FIN = '#'; 		// Car�cter que finaliza la lectura de datos
	
	// Declaraci�n de variables
	
	char caracter;
	
	// Entrada inicial de datos
	caracter = LeerCaracter();
	
	// C�lculos
	
	/*
		Algoritmo:
		
		Mientras 'caracter' sea diferente de '#':
		
			Si 'caracter' es una vocal, entonces a 'numero_de_vocales' se
			le suma 1.
			
			Si 'caracter' es una consonante, entonces a 'numero_de_consonantes' 
			se le suma 1.
			
			Si 'caracter' es un d�gito, entonces a 'numero_de_digitos' se
			le suma 1.
			
			Se lee un nuevo 'caracter'.
			
		Se muestra al usuario el n�mero de vocales, consonantes y d�gitos que
		se han encontrado en la secuencia de caracteres que hab�a introducido
		y se muestra la categor�a ganadora (es decir, la que m�s apariciones
		ha tenido) junto a su n�mero de apariciones (dicha categor�a puede
		ser las vocales, las consonantes o los d�gitos).
	*/
	
	bool es_vocal = false, 
         es_consonante = false, 
	     es_digito = false;
		 
	int numero_de_vocales = 0, 
	    numero_de_consonantes = 0, 
		numero_de_digitos = 0;
		
	while(caracter != FIN) {
		
		es_vocal = EsVocal(caracter);
		es_consonante = EsConsonante(caracter);
		es_digito = EsDigito(caracter);
		
		if(es_vocal)
			numero_de_vocales++;
		if(es_consonante)
			numero_de_consonantes++;
		if(es_digito)
			numero_de_digitos++;
		
		// Entrada iterativa de datos (hasta que se lea el car�cter '#')
		
		caracter = LeerCaracter();	
	}
	
	// Salidas
	
	cout << endl;
	cout << " Hay " << numero_de_vocales << " vocales.";
	cout << endl;
	cout << " Hay " << numero_de_consonantes << " consonantes.";
	cout << endl;
	cout << " Hay " << numero_de_digitos << " digitos.";
	cout << endl << endl;
	
	MostrarCategoriaGanadora(numero_de_vocales, numero_de_consonantes, 
	                         numero_de_digitos); 
	                         
	cout << endl << endl;
	
	return 0;	
}
