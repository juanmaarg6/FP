/*
	Ejercicio 6: Programa que dados dos vectores enteros, muestra 
					 las veces que el segundo aparece en el primero
					 y la posicion en la que empiezan las coincidencias.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

int main(){

	const int LONGITUD_MAXIMA = 1000;
   int vector1[LONGITUD_MAXIMA], vector2[LONGITUD_MAXIMA];
    
   int longitud1, longitud2;
   int repeticiones = 0;
   int comienzos[LONGITUD_MAXIMA];
	
	bool es_repeticion = false;
	
	/*
		Algoritmo:
		
		El usuario introduce las longitudes de los vectores y dichos vectores.
		
		Mientras "posicion" no sea mayor que la diferencia de longitudes de los vectores:
			Si el vector2 aparece en vector1 a partir de una componente determinada:
				Inserta "posicion" en el vector "comienzos".
				Aumenta repeticiones en 1.
				
		Si "repeticiones" es mayor que 0:
			Mostrar el numero de repeticiones que se dan y las posiciones.
		Si no:
			Mostrar que no hay repeticiones.			
	*/
	
	cout << " Introduzca la longitud primer vector: ";
	cin >> longitud1;
	
	cout << " Introduzca la longitud del segundo vector: ";
	cin >> longitud2;
	
	if(longitud1 > 1000 || longitud2 > 1000){
		cout << "\n Error. La maxima longitud permitida es 1000" << endl << endl;
		exit(-1);
	}
	
	
	cout << "\n Introduzca el primer vector: ";
	for (int i = 0 ; i < longitud1 ; i++)
		cin >> vector1[i];
	
   cout << " Introduzca el segundo vector: ";
   for (int i = 0 ; i < longitud2 ; i++)
		cin >> vector2[i];
    
   int final = longitud1 - longitud2;
    
   for (int posicion = 0; posicion < final; posicion++){
      es_repeticion = true;
            
      for (int j = 0; j < longitud2 && es_repeticion; j++)
         if ( vector1[posicion+j] != vector2[j] )
            es_repeticion = false;
            
      if (es_repeticion){
         comienzos[repeticiones] = posicion;
         repeticiones++;
      }
   }
        
   if (repeticiones > 0){
      cout << "\n Se dan " << repeticiones << " repeticiones en las posiciones";
      for (int i = 0; i < repeticiones; i++)
         cout << " " << comienzos[i] << ",";
         
      cout << endl << endl;
   }
   else
      cout << "\n No hay repeticiones" << endl << endl;
      
   system("pause");
}
