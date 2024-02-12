/*
	Ejercicio 12: Programa que calcula el numero de
					  subsecuencias ascendentes de un
					  vector de enteros
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

int main(){

   const int LONGITUD_MAXIMA = 1000;
   int vector[LONGITUD_MAXIMA];
    
   int longitud;
   int numero_subsecuencias_ascendentes = 0;
   
   /*
   	Algoritmo:
   	
   	El usuario introduce la longitud del vector y dicho vector.
   	
   	Si "longitud" es mayor que 0:
   		Aumentar "numero_secuencias_ascendentes" en 1.
   		(Esto es para el caso de que "longitud" sea solo 1)
   		
   	Para "i" menor que "longitud":
   		Si la componente del vector es menor que la anterior:
   			Aumentar "numero_secuencias_ascendentes" en 1.
   			
   		Aumenta "i" en 1.
   
   	Mostrar en pantalla el numero de subsecuencias ascendentes.
   */
    
   cout << " Introduzca la longitud del vector: ";
   cin >> longitud;
   
   if(longitud > 1000){
		cout << "\n Error. La maxima longitud permitida es 1000" << endl << endl;
		exit(-1);
	}
	
	cout << "\n Introduzca el vector: ";
	for(int i = 0 ; i < longitud ; i++)
		cin >> vector[i];
	
   if(longitud > 0)
      numero_subsecuencias_ascendentes++;
    
   for(int i = 1; i < longitud; i++)
      if (vector[i] < vector[i-1])
         numero_subsecuencias_ascendentes++;
        
	cout << "\n Hay " << numero_subsecuencias_ascendentes << " subsecuencias ascendentes" << endl << endl;
	
	system("pause");
}
