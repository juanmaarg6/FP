/*
	Ejercicio 10: Programa que. dada una permutacion,
	              comprueba si dicha permutacion es 
	              correcta, calcula el cuadrado de 
	              la permutacion y calcula la potencia
	              k-esima de la permutacion.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include<iostream>

using namespace std;

const int LONGITUD_MAXIMA = 1000;

struct Permutacion{
	int imagen[LONGITUD_MAXIMA];
	int longitud;
};

int main(){
	Permutacion permutacion;
   Permutacion cuadrado;
   Permutacion k_esima;
      
   bool repetidos = false;
   int potencia_k_esima;
   
   /*
   	Algoritmo:
   	
   	El usuario introduce la longitud de la permutacion
   	y dicha permutacion.
   	
   	Se comprueba si es una permutacion y se muestra 
   	en pantalla si lo es o no (en caso de tener un
		elemento repetido, no lo es).
		
		Se calcula el cuadrado de la permutacion (la composicion)
		y se muestra en pantalla.
		
		El usuario introduce una potencia. Se calcula dicha 
		potencia de la permutacion y se muestra en pantalla
   */
	
	cout << " Introduzca la longitud de la permutacion: ";
	cin >> permutacion.longitud;
	
	if(permutacion.longitud > LONGITUD_MAXIMA){
		cout << "\n Error. La maxima longitud permitida es " << LONGITUD_MAXIMA << endl << endl;
		exit(-1);	
	}
	
	cout << "\n Introduzca la permutacion: ";
	for(int i = 0; i < permutacion.longitud; i++)
		cin >> permutacion.imagen[i];
	
	for(int i = 0; i < permutacion.longitud && !repetidos; i++)
		for(int j =i + 1; j < permutacion.longitud && !repetidos; j++)
			if (permutacion.imagen[i] == permutacion.imagen[j])
				repetidos = true;
	
   if(repetidos){
      cout << "\n No es una permutacion\n";
      exit(-1);
   }
   else
      cout << "\n Si es una permutacion\n"; 
	
   cuadrado = permutacion;
    
   for(int i = 0; i < cuadrado.longitud; i++)
      cuadrado.imagen[i] = permutacion.imagen[permutacion.imagen[i]];
      
   cout << "\n Cuadrado de la permutacion: ";
   for(int i = 0; i < cuadrado.longitud; i++)
   	cout << cuadrado.imagen[i] << " ";
        
   k_esima = permutacion;
    
   cout << "\n\n Introduzca una potencia: ";
   cin >> potencia_k_esima;
       
   for(int i = 0; i < k_esima.longitud; i++)
      for (int j = 0; j < potencia_k_esima; j++)
      	k_esima.imagen[i] = permutacion.imagen[permutacion.imagen[j]];
         
   cout << "\n Potencia " << potencia_k_esima << " de la permutacion: ";
   for(int i = 0; i < k_esima.longitud; i++)
      cout << k_esima.imagen[i] << " ";
      
   cout << endl << endl;
   
   system("pause");
}
