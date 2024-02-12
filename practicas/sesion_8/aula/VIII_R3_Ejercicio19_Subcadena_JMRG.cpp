/*
	Ejercicio 19: Programa que, dada una cadena de caracteres 
					  y dos posiciones dentro de la cadena, x e y, 
					  devuelve otra cadena con los caracteres comprendidos 
					  entre las posiciones x e y (inclusive).
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

int main(){
	
	const int LONGITUD_MAXIMA = 1000;
	char vector[LONGITUD_MAXIMA] = {0};
	
	int longitud = 0;
	int posicion1 = 0, posicion2 = 0;
	
	/*
		Algoritmo:
		   	
		El usuario introduce la longitud del vector y dicho vector.
   	
   	El usuario introduce dos posiciones del vector.
   		
   	Mostrar en pantalla los caracteres comprendidos entre las
   	dos posiciones introducidas por el usuario.	
	*/

	cout << " Introduzca la longitud del vector: ";
	cin >> longitud;
	
   if(longitud > 1000){
		cout << "\n Error. La maxima longitud permitida es 1000" << endl << endl;
		exit(-1);
	}
	
	cout << "\n Introduzca el vector: ";
	
	for(int i = 0; i < longitud; i++)
		cin >> vector[i];

	cout << "\n\n NOTA: La primera posicion corresponde al numero 0";
	cout << "\n Introduzca dos posiciones (separadas por espacios): ";
	cin >> posicion1 >> posicion2;
	
	cout << "\n\n Los caracteres comprendidos entre la posicion " << posicion1 << " y la posicion " << posicion2 << " son:";
	
	for(int i = posicion1; i <= posicion2; i++)
		cout << " " << vector[i];
		
	cout << endl << endl;
	
	system("pause");
}
