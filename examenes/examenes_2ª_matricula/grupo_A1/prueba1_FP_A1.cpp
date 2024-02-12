#include <iostream>

using namespace std;

/***************************************************************************/
// Función: LeerCaracter
// Recibe: -
// Devuelve: Carácter leído.
/***************************************************************************/
char LeerCaracter() {
	
	char caracter;
	
	cin >> caracter;
	
	return caracter;
}

/***************************************************************************/
// Función: EsVocal
// Recibe: Carácter (caracter).
// Devuelve: True (1) si el carácter es una vocal y False (0) si no lo es.
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
// Función: EsConsonante
// Recibe: Carácter (caracter).
// Devuelve: True (1) si el carácter es una consonante y False (0) si no lo es.
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
// Función: EsDigito
// Recibe: Carácter (caracter).
// Devuelve: True (1) si el carácter es un dígito y False (0) si no lo es.
/***************************************************************************/
bool EsDigito(char caracter) {

	const char DIGITO_0 = '0';
	const char DIGITO_9 = '9';
	
	bool es_digito = ( (caracter >= DIGITO_0) && (caracter <= DIGITO_9) );	
	
	return es_digito;	
}

/***************************************************************************/
// Función: MostrarCategoriaGanadora
// Recibe: Número de vocales de la secuencia de caracteres (numero_de_vocales),
//         Número de consonantes de la secuencia de 
//         caracteres (numero_de_consonantes),
//         Número de digitos de la secuencia de caracteres (numero_de_digitos).
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
// Función principal
/***************************************************************************/
int main() {
	
	// Declaración de constantes
	
	const char FIN = '#'; 		// Carácter que finaliza la lectura de datos
	
	// Declaración de variables
	
	char caracter;
	
	// Entrada inicial de datos
	caracter = LeerCaracter();
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Mientras 'caracter' sea diferente de '#':
		
			Si 'caracter' es una vocal, entonces a 'numero_de_vocales' se
			le suma 1.
			
			Si 'caracter' es una consonante, entonces a 'numero_de_consonantes' 
			se le suma 1.
			
			Si 'caracter' es un dígito, entonces a 'numero_de_digitos' se
			le suma 1.
			
			Se lee un nuevo 'caracter'.
			
		Se muestra al usuario el número de vocales, consonantes y dígitos que
		se han encontrado en la secuencia de caracteres que había introducido
		y se muestra la categoría ganadora (es decir, la que más apariciones
		ha tenido) junto a su número de apariciones (dicha categoría puede
		ser las vocales, las consonantes o los dígitos).
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
		
		// Entrada iterativa de datos (hasta que se lea el carácter '#')
		
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
