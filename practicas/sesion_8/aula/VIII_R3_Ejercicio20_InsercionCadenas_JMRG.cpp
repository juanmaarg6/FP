/*
	Ejercicio 20: Programa que inserta una cadena de caracteres
					  dentro de otra cadena, en una determinada posicion.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

int main(){
	
	const int LONGITUD_MAXIMA = 1000;	
	int longitud1 = 0, longitud2 = 0;
	int posicion = 0;
	
	char cadena1[LONGITUD_MAXIMA] = {0};
	char cadena2[LONGITUD_MAXIMA] = {0};
	
	string insercion, parte2;
	
	/*
		Algoritmo:
		
		El usuario introduce las longitudes de las dos cadenas
		y dichas cadenas.
   	
   	El usuario introduce la posicion en la que quiere
   	insertar la cadena2 en la cadena1.
   	
		Segun la posicion introducida por el usuario, la cadena1
		se	rompe en dos partes (1ª parte = inicio --- posicion,
		2ª parte = posicion --- final). La primera parte se
		denomina "insercion".
		
		Añadir a "insercion" la cadena2.
		
		Añadir a "insercion" la segunda parte de la cadena1.
		
   	Mostrar en pantalla la insercion de la cadena2 en 
		la cadena1, en la posicion introducida por el usuario.
	*/	

	cout << " Introduzca la longitud de la primera cadena: ";
	cin >> longitud1;
	
   if(longitud1 > 1000){
		cout << "\n Error. La maxima longitud permitida es 1000" << endl << endl;
		exit(-1);
	}
	
	cout << " Introduzca la longitud de la segunda cadena: ";
	cin >> longitud2;
	
   if(longitud2 > 1000){
		cout << "\n Error. La maxima longitud permitida es 1000" << endl << endl;
		exit(-1);
	}
	
	cout << "\n Introduzca la primera cadena: ";
	for(int i = 0; i < longitud1; i++)
		cin >> cadena1[i];
		
	cout << " Introduzca la segunda cadena: ";
	for(int i = 0; i < longitud2; i++)
		cin >> cadena2[i];

	cout << "\n\n NOTA: La primera posicion de la cadena corresponde al numero 0";
	cout << "\n Introduzca la posicion donde quiere insertar la cadena2 en la cadena1: ";
	cin >> posicion;
	
	for(int x = 0; x < posicion; x++)
		insercion += cadena1[x];
	
	for(int j = posicion; j < longitud1; j++)
		parte2 += cadena1[j];
	
	for(int y = 0; y < longitud2; y++)
		insercion += cadena2[y];
	
	insercion += parte2;
	
	cout << "\n\n Resultado: " << insercion;
		
	cout << endl << endl;
	
	system("pause");
}
