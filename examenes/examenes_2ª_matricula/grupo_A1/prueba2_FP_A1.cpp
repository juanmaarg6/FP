/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


/***************************************************************************/
// Tipo enumerado para procesar un carácter leído
/***************************************************************************/

enum class Tipo {Vocal, Consonante, Digito, Otro};

/***************************************************************************/
// Dato struct para agrupar los contadores de las categorías del tipo 
// enumerado Tipo
/***************************************************************************/

struct Contador {
	int vocales;		// Contador del número de vocales
	int consonantes;	// Contador del número de consonantes
	int digitos;		// Contador del número de dígitos
	int otros;			// Contador del número de otros
};
/***************************************************************************/
// Función: EsLetra
// Descripción: Comprueba si un carácter es una letra.
// Recibe: Carácter (c).
// Devuelve: True (1) si el carácter es una letra y False (0) si no lo es.
/***************************************************************************/

bool EsLetra (char c) 
{
	bool es_letra = false; 
	char c_may = toupper(c);
	
	if (c_may >= 'A' && c_may <= 'Z')
		es_letra = true;
		
	return (es_letra);	
}

/***************************************************************************/
// Función: EsVocal
// Descripción: Comprueba si un carácter es una vocal.
// Recibe: Carácter (c).
// Devuelve: True (1) si el carácter es una vocal y False (0) si no lo es.
/***************************************************************************/

bool EsVocal (char c) 
{
	bool es_vocal = false;
	char c_may = toupper(c);

	if(c_may == 'A' || c_may == 'E' || c_may == 'I' || c_may == 'O' || 
	   c_may == 'U') {
	
		es_vocal = true;
	}
	
	return (es_vocal);	
}

/***************************************************************************/
// Función: EsConsonante
// Descripción: Comprueba si un carácter es una consonante.
// Recibe: Carácter (c).
// Devuelve: True (1) si el carácter es una consonante y False (0) si no lo es.
/***************************************************************************/

bool EsConsonante (char c) 
{
	bool es_consonante = false;
	char c_may = toupper(c);
	
	bool es_letra_mayuscula = ( (c_may >= 'A') && (c_may <= 'Z') );
	bool no_es_vocal = !( EsVocal(c) );
	
	if(es_letra_mayuscula && no_es_vocal)
		es_consonante = true;
	
	return (es_consonante);	
}

/***************************************************************************/
// Función: EsDigito
// Descripción: Comprueba si un carácter es un dígito.
// Recibe: Carácter (c).
// Devuelve: True (1) si el carácter es un dígito y False (0) si no lo es.
/***************************************************************************/

bool EsDigito (char c) 
{
	bool es_digito = ( (c >= '0') && (c <= '9') );	
	
	return (es_digito);	
}

/***************************************************************************/
// Función: EsOtro
// Descripción: Comprueba si un carácter no es ni una vocal, ni una
//			    consonante y tampoco un dígito.
// Recibe: Carácter (c).
// Devuelve: True (1) si el carácter es otro (es decir, si no es ni una vocal,
//           ni una consonante y tampoco un dígito) y False (0) si no lo es.
/***************************************************************************/

bool EsOtro (char c) 
{
	bool es_otro = !( EsVocal(c) ) && !( EsConsonante(c) ) && !( EsDigito(c) );
	
	return (es_otro);
}

/***************************************************************************/
// Función: Clasifica
// Descripción: Comprueba a qué categoría del tipo enumerado Tipo
//			    pertenece una letra 
// Recibe: Letra (letra).
// Devuelve: Categoría del tipo enumerado Tipo a la que pertenece 'letra'
//           (puede ser una vocal, una consonante, un dígito u otro).
/***************************************************************************/

Tipo Clasifica (char letra)
{
	Tipo tipo_letra;
	
	if( EsVocal(letra) )
		tipo_letra = Tipo::Vocal;
	
	if( EsConsonante(letra) )
		tipo_letra = Tipo::Consonante;
		
	if( EsDigito(letra) )
		tipo_letra = Tipo::Digito;
		
	if( EsOtro(letra) )
		tipo_letra = Tipo::Otro;
	
	return (tipo_letra);
}

/***************************************************************************/
// Función principal
/***************************************************************************/

int main()
{
	// Declaración de constantes
	
	const char FIN = '#';			// Carácter que pone fin a la lectura
									// de carácteres
	
	// Declaración de variables
	
	char caracter;
	Tipo tipo_caracter;
	Contador contador = {0, 0, 0, 0}; // Inicializamos todos los contadores a 0
	int num_total_caracteres = 0;
	
	// Entrada de datos
	
	cin >> caracter;
	
	// Cálculos
	
	// Mientras el usuario no introduzca el carácter '#'
	while(caracter != FIN) {
		
		// Vemos a qué categoría del tipo enumerado Tipo pertenece 'caracter'
		tipo_caracter = Clasifica(caracter);
		
		// En función de la categoría a la que pertenezca 'caracter',
		// incrementamos en 1 el contador correspondiente
		switch(tipo_caracter) {
			case(Tipo::Vocal) :
				contador.vocales++;
				break;
			case(Tipo::Consonante) :
				contador.consonantes++;
				break;
			case(Tipo::Digito) :
				contador.digitos++;
				break;
			case(Tipo::Otro) :
				contador.otros++;
				break;
		}
		
		// Volvemos a leer un carácter
		cin >> caracter;
	}
	
	// Sumamos los contadores de las diferentes categorías para calcular
	// el número total de carácteres introducidos por el usuario
	num_total_caracteres = contador.vocales + contador.consonantes +
	                           contador.digitos + contador.otros;
	
	// Salida
	 
	cout << endl;
	cout << "Hay un total de " << num_total_caracteres << " caracteres." 
	     << endl;	
	cout << endl;
	cout << "Hay " <<setw(2) << contador.vocales << " vocales." << endl;	
	cout << "Hay " <<setw(2) << contador.consonantes << " consonantes." 
	     << endl;
	cout << "Hay " <<setw(2) << contador.digitos << " digitos." << endl;
	cout << "Hay " <<setw(2) << contador.otros << " otros." << endl;	
	cout << endl;

	return 0;	
}

/***************************************************************************/
/***************************************************************************/
