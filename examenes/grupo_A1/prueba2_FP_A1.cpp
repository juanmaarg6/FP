/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// (C) FRANCISCO JOS� CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


/***************************************************************************/
// Tipo enumerado para procesar un car�cter le�do
/***************************************************************************/

enum class Tipo {Vocal, Consonante, Digito, Otro};

/***************************************************************************/
// Dato struct para agrupar los contadores de las categor�as del tipo 
// enumerado Tipo
/***************************************************************************/

struct Contador {
	int vocales;		// Contador del n�mero de vocales
	int consonantes;	// Contador del n�mero de consonantes
	int digitos;		// Contador del n�mero de d�gitos
	int otros;			// Contador del n�mero de otros
};
/***************************************************************************/
// Funci�n: EsLetra
// Descripci�n: Comprueba si un car�cter es una letra.
// Recibe: Car�cter (c).
// Devuelve: True (1) si el car�cter es una letra y False (0) si no lo es.
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
// Funci�n: EsVocal
// Descripci�n: Comprueba si un car�cter es una vocal.
// Recibe: Car�cter (c).
// Devuelve: True (1) si el car�cter es una vocal y False (0) si no lo es.
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
// Funci�n: EsConsonante
// Descripci�n: Comprueba si un car�cter es una consonante.
// Recibe: Car�cter (c).
// Devuelve: True (1) si el car�cter es una consonante y False (0) si no lo es.
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
// Funci�n: EsDigito
// Descripci�n: Comprueba si un car�cter es un d�gito.
// Recibe: Car�cter (c).
// Devuelve: True (1) si el car�cter es un d�gito y False (0) si no lo es.
/***************************************************************************/

bool EsDigito (char c) 
{
	bool es_digito = ( (c >= '0') && (c <= '9') );	
	
	return (es_digito);	
}

/***************************************************************************/
// Funci�n: EsOtro
// Descripci�n: Comprueba si un car�cter no es ni una vocal, ni una
//			    consonante y tampoco un d�gito.
// Recibe: Car�cter (c).
// Devuelve: True (1) si el car�cter es otro (es decir, si no es ni una vocal,
//           ni una consonante y tampoco un d�gito) y False (0) si no lo es.
/***************************************************************************/

bool EsOtro (char c) 
{
	bool es_otro = !( EsVocal(c) ) && !( EsConsonante(c) ) && !( EsDigito(c) );
	
	return (es_otro);
}

/***************************************************************************/
// Funci�n: Clasifica
// Descripci�n: Comprueba a qu� categor�a del tipo enumerado Tipo
//			    pertenece una letra 
// Recibe: Letra (letra).
// Devuelve: Categor�a del tipo enumerado Tipo a la que pertenece 'letra'
//           (puede ser una vocal, una consonante, un d�gito u otro).
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
// Funci�n principal
/***************************************************************************/

int main()
{
	// Declaraci�n de constantes
	
	const char FIN = '#';			// Car�cter que pone fin a la lectura
									// de car�cteres
	
	// Declaraci�n de variables
	
	char caracter;
	Tipo tipo_caracter;
	Contador contador = {0, 0, 0, 0}; // Inicializamos todos los contadores a 0
	int num_total_caracteres = 0;
	
	// Entrada de datos
	
	cin >> caracter;
	
	// C�lculos
	
	// Mientras el usuario no introduzca el car�cter '#'
	while(caracter != FIN) {
		
		// Vemos a qu� categor�a del tipo enumerado Tipo pertenece 'caracter'
		tipo_caracter = Clasifica(caracter);
		
		// En funci�n de la categor�a a la que pertenezca 'caracter',
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
		
		// Volvemos a leer un car�cter
		cin >> caracter;
	}
	
	// Sumamos los contadores de las diferentes categor�as para calcular
	// el n�mero total de car�cteres introducidos por el usuario
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
