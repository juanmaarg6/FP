/*
	Ejercicio 7: Programa que elimina las mayusculas de un vector.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include<iostream>

using namespace std;

int main(){
    const int LONGITUD_MAXIMA = 1000;
    char vector[LONGITUD_MAXIMA];
	
	int longitud;
	
	/*
		Algoritmo:
		
		El usuario introduce la longitud del vector y dicho vector.
		
		Mientras "posicion" sea menor que "longitud":
			Si es una mayuscula:
				Desplaza todas las componentes del vector, a partir de "posicion",
				una posicion mas.
				Disminuye "longitud" en 1.
				
		Mostrar en pantalla el vector sin mayusculas.
	*/
	
	cout << " Introduzca la longitud del vector: ";
   cin >> longitud;
   
   if(longitud > 1000){
		cout << "\n Error. La maxima longitud permitida es 1000" << endl << endl;
		exit(-1);
	}
	
	cout << "\n Introduzca el vector: ";
	for (int i = 0; i < longitud; i++)
		cin >> vector[i];
	   
   int posicion = 0;
   while (posicion <= longitud){
      if (vector[posicion] >= 'A' && vector[posicion] <= 'Z'){
         for (int j = posicion; j < longitud; j++)
            vector[j] = vector[j + 1];
         longitud--;
      }
      else
         posicion++;
   }

   cout << "\n El vector sin mayusculas queda: ";
	for (int i = 0; i < longitud; i++)
		cout << vector[i] << " ";
		
	cout << endl << endl;
	
	system("pause");
}
