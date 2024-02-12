/*
	Ejercicio 15: Programa que lee una cadena, busca un
	              caracter en ella y devuelve si dicho
	              caracter se encuentra o no en la cadena.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

/*
	Funcion que busca un caracter en una cadena de caracteres
	
	Parametros: cadena[] (char), longitud (int), caracter (char)
	
	Algoritmo:
		Recorre, caracter a caracter, toda la cadena en busca del
		caracter deseado.
		
	Devuelve:
		"true" si se encuentra el caracter deseado en la cadena.
		"false" si no se encuentra el caracter deseado en la cadena.
*/
bool BuscarCaracter(char cadena[], int longitud, char caracter);

int main(){
	const int LONGITUD_MAXIMA = 1000;

	char cadena[LONGITUD_MAXIMA];
	char caracter;
	int longitud = 0, a = 0;
	
	/*
		Algoritmo:
			El usuario introduce una cadena de caracteres y
			el caracter que quiere buscar.
			
			Se calcula la longitud de la cadena.
			
			Si BuscarCaracter devuelve true, entonces mostrar
			que el caracter se encuentra en la cadena.
			Si no, mostrar que el caracter no se encuentra en la cadena.
	*/
	
	cout << " Introduzca una cadena de caracteres: ";
	cin.getline(cadena, LONGITUD_MAXIMA);
		
	while(cadena[a] != '\0'){
		longitud++;
		a++;
	}
	
	cout << "\n Introduzca el caracter que quiere buscar: ";
	cin >> caracter;
	
	if(BuscarCaracter(cadena, longitud, caracter))
		cout << "\n El caracter '" << caracter <<"' se encuentra en la cadena" << endl << endl;
	else
		cout << "\n El caracter '" << caracter <<"' no se encuentra en la cadena" << endl << endl;
		
	system("pause");
}

bool BuscarCaracter(char cadena[], int longitud, char caracter){
	bool respuesta = false;
	
	for(int i = 0; i <= longitud; i++){
		if(cadena[i] == caracter)
			respuesta = true;
	}
	
	return respuesta;
}
