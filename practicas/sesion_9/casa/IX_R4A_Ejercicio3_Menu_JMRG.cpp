/*
	Ejercicio 3: Programa que muestra si se ha aceptado
	             o cancelado un mensaje de confirmacion,
	             segun el caracter introducido por el usuario
	             ('S' para aceptar, 'N' para cancelar).
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

// Funcion que calcula si se acepta o se cancela el mensaje de confirmacion

bool Confirmar(char caracter){	
	bool respuesta;
	
	if(caracter == 'S')
		respuesta = true;
	else if(caracter == 'N')
		respuesta = false;
	
	return respuesta;
}

int main(){
	char caracter = 'a';
	bool respuesta_valida = false;
	
	/*
		Algoritmo:
		
		El usuario introduce 'S' o 'N'.
		
		Si introduce 'S', entonces mostrar en pantalla que
		acepta el mensaje de confirmacion.
		
		Si introduce 'N', entonces mostrar en pantalla que
		acepta el mensaje de confirmacion.
	*/
	
	do{
		cout << " ¿Confirmar (S/N)?: ";
		cin >> caracter;
		
		respuesta_valida = (caracter == 'S' || caracter == 'N');
	}while(!respuesta_valida);
	
	if(Confirmar(caracter))
		cout << "\n Mensaje de confirmacion aceptado" << endl << endl;
	else
		cout << "\n Mensaje de confirmacion cancelado" << endl << endl;
		
	system("pause");
}
