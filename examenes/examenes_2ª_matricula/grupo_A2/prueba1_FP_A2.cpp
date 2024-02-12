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
/***************************************************************************/

enum class Tipo {MuyCorta, Corta, Otra};

/***************************************************************************/
/***************************************************************************/

struct Contador {
	int muycortas;
	int cortas;	
	int otras;
};

/***************************************************************************/
/***************************************************************************/

bool EsMuyCorta (string palabra) 
{
	bool es_muy_corta = false;

	if(palabra.length() == 1 || palabra.length() == 2)
		es_muy_corta = true;
	
	return (es_muy_corta);	
}

/***************************************************************************/
/***************************************************************************/

bool EsCorta (string palabra) 
{
	bool es_corta = false;

	if(palabra.length() == 3 || palabra.length() == 4)
		es_corta = true;
	
	return (es_corta);	
}

/***************************************************************************/
/***************************************************************************/

bool EsOtra (string palabra) 
{
	bool es_otra = false;

	if(palabra.length() >= 5)
		es_otra = true;
	
	return (es_otra);	
}

string ConvertirPalabraAMayuscula (string palabra) 
{
	string palabra_may;
	
	for(int i = 0; i < palabra.length(); i++)
		palabra_may += toupper(palabra[i]);
	
	return (palabra_may);
}

/***************************************************************************/
/***************************************************************************/

Tipo Clasifica (string palabra)
{
	Tipo tipo_palabra;
	
	if( EsMuyCorta(palabra) )
		tipo_palabra = Tipo::MuyCorta;
	
	if( EsCorta(palabra) )
		tipo_palabra = Tipo::Corta;
		
	if( EsOtra(palabra) )
		tipo_palabra = Tipo::Otra;
	
	return (tipo_palabra);
}

/***************************************************************************/
/***************************************************************************/

int main()
{
	// Declaración de constantes
	
	const string FINALIZAR = "FIN";
	
	// Declaración de variables
	
	string cad_final;
	string palabra;
	Tipo tipo_palabra;
	Contador contador = {0, 0, 0};
	int num_total_palabras = 0;
	
	// Entrada de datos
	
	cin >> palabra;

	// Cálculos
	
	while(palabra != FINALIZAR) {
		
		// Vemos a qué categoría del tipo enumerado Tipo pertenece 'palabra'
		tipo_palabra = Clasifica(palabra);
		
		// En función de la categoría a la que pertenezca 'palabra',
		// incrementamos en 1 el contador correspondiente
		switch(tipo_palabra) {
			case(Tipo::MuyCorta) :
				contador.muycortas++;
				break;
			case(Tipo::Corta) :
				contador.cortas++;
				break;
			case(Tipo::Otra) :
				contador.otras++;
				break;
		}
		
		// Si 'palabra' pertenece a la categoría 'Otra' del tipo enumerado
		// 'Tipo', entonces 'palabra' se convierte a mayúsculas y la
		// añadimos a 'cad_final' 
		if(tipo_palabra == Tipo::Otra) {
			string palabra_may = ConvertirPalabraAMayuscula(palabra);
			cad_final += palabra_may + " ";
		}
		// Si no, añadimos 'palabra' correspondiente a 'cad_final', sin ninguna
		// conversión 
		else
			cad_final += palabra + " ";
		
		// Volvemos a leer una palabra
		cin >> palabra;
	}
	
	num_total_palabras = contador.muycortas + contador.cortas + 
	                     contador.otras;

	// Salida
	
	cout << endl;	
	cout << cad_final << endl; 
	cout << endl;
	 
	cout << endl;
	cout << "Hay un total de " << num_total_palabras << " palabras." << endl;	
	cout << endl;
	cout << "Hay " << setw(2) << contador.muycortas << " muy cortas." << endl;	
	cout << "Hay " << setw(2) << contador.cortas << " cortas." << endl;
	cout << "Hay " << setw(2) << contador.otras << " otras." << endl;
	cout << endl;

	return 0;	
}

/***************************************************************************/
/***************************************************************************/
