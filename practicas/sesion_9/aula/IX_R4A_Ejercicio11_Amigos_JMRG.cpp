/*
	Ejercicio 11: Programa que, dados dos numeros naturales, 
					  muestra todas las parejas de numeros amigos
					  que existen en el intervalo formado por dichos
					  numeros naturales
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

bool Amigos(int entero1, int entero2){
   int suma1 = 0, suma2 = 0;
   int divisor_maximo1 = entero1 / 2;
   int divisor_maximo2 = entero2 / 2;
   bool amigos;
    
   /* 
		Algoritmo:
		
   	Se calcula la suma de los divisores del primer numero natural.

   	Se calcula la suma de los divisores del segundo numero natural.
   	
   	Si las suma de los divisores de uno coincide con el otro, y viceversa:
			Los dos numeros naturales son amigos, por lo que se devuelve "true".
   */
     
   for (int i = 1; i <= divisor_maximo1; i++)
		if (entero1 % i == 0)
         suma1 += i;
    
   for (int i = 1; i <= divisor_maximo2; i++)
      if (entero2 % i == 0)
         suma2 += i;
    
   amigos = (suma2 == entero1) && (suma1 == entero2);

   return amigos;
}

int main(){
	int entero1 = 0, entero2 = 0;
	
	/* 
		Algoritmo:
		
   	El usuario introduce dos numeros naturales, siendo el segundo
   	mayor que el primero.

   	Se comprueba (desde los dos numeros naturales introducidos) si
   	hay parejas de numeros amigos.
   		Si las hay, se muestran en pantalla.
   */
	
	do{
		cout << " Introduzca un numero natural 'a': ";
		cin >> entero1;
		
		cout << " Introduzca un numero natural 'b' (siendo b > a): ";
		cin >> entero2;
	}while((entero1 <= 0 || entero2 <= 0) || (entero1 > entero2));
	
	cout << "\n Las parejas de numeros amigos comprendidas entre " << entero1 << " y " << entero2 << " son: " << endl << endl;
	
	for (int candidato1 = entero1; candidato1 <= entero2; candidato1++)
  		for (int candidato2 = entero1; candidato2 <= entero2; candidato2++)
      	if (Amigos(candidato1,candidato2))
         	cout << " (" << candidato1 << ", " << candidato2 << ")" << " ";
         	
   cout << endl << endl;
   
   system("pause");
}
