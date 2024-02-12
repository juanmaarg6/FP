/*
	Ejercicio 17: Programa que dado el nombre y los apellidos
		           de una persona y un numero entero 'N', muestra
		           una sugerencia de nombre de usuario para
		           registrarse en una pagina web. 
					  
					  Dicho nombre de usuario estara formado por 
					  los N primeros caracteres de cada nombre y apellido.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main(){
	int N = 0, caracter = 0, siguiente_caracter = 0;
	int k = 0;
	bool espacio = false;
	string cadena, nombre_usuario;
	
	/*
		Algoritmo:
		
		El usuario introduce su nombre y apellidos, ademas
		de un numero.
		
		Calcular la longitud de la cadena.
		
		Mientras no acabe la cadena de caracteres introducida
		por el usuario:
		
			Si el caracter correspondiente no es un espacio:
				Se almacena en la cadena "nombre_usuario",
				los N primeros caracteres de la palabra
				correspondiente de la cadena.
				
			Si el caracter correspondiente es un espacio:
				Se pasa al siguiente caracter y se almacena
				en la cadena "nombre_usuario", los N primeros 
				caracteres de la palabra correspondiente de la cadena.
		
		Mostrar en pantalla el nombre de usuario sugerido
		para el sistema web.
		
	*/
	
	cout << " Introduzca su nombre y apellidos: ";
	getline(cin, cadena);

	cout << " Introduzca un numero: ";
	cin >> N;
	
	while(cadena[caracter] != '\0'){
		if(!espacio){
			while(k < N){
				nombre_usuario += tolower(cadena[k]);
				k++;
			}
		}
		
		if(cadena[caracter] == ' '){
			espacio = true;
			siguiente_caracter = caracter + 1;
			k = 0;
			do{	
				nombre_usuario += tolower(cadena[siguiente_caracter]);
				k++;
				siguiente_caracter++;
			}while(k < N);
		}
		caracter++;
	}

	cout << "\n\n Nombre de usuario sugerido: " << nombre_usuario << endl << endl;
	
	system("pause");		
}
