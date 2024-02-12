/*
	Ejercicio 8: Programa que elimina las mayusculas de un vector.
	
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
		
		Para "posicion_lectura" menor que "longitud":
			Si la componente del vector en "posicion_lectura" es minuscula:
				"posicion_escritura" almacena el valor de "posicion_lectura".
				Aumentar "posicion_escritura" en 1.
				
			Aumenta "posicion_lectura" en 1.
				
		La longitud del vector sera igual a "posicion_escritura"
				
		Mostrar en pantalla el vector sin mayusculas.
	*/
    
   cout << " Introduzca la longitud del vector: ";
   cin >> longitud;
   
   if(longitud > 1000){
		cout << "\n Error. La maxima longitud permitida es 1000" << endl << endl;
		exit(-1);
	}
    
   cout << "\n Introduzca el vector: ";
   for (int i = 0 ; i < longitud ; i++)
      cin >> vector[i];
	
   int posicion_escritura = 0;
    
   for (int posicion_lectura = 0; posicion_lectura < longitud; posicion_lectura++)
      if (vector[posicion_lectura] < 'A' || vector[posicion_lectura] > 'Z'){
         vector[posicion_escritura] = vector[posicion_lectura];
         posicion_escritura++;
      }
	
   longitud = posicion_escritura;
    
   cout << "\n El vector sin mayusculas queda: ";
   for (int i = 0; i < longitud; i++)
      cout << vector[i] << " ";
      
   cout << endl << endl;
   
   system("pause");
}
