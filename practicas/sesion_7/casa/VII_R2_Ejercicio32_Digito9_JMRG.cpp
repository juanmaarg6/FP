/*
	Ejercicio 32: Programa que muestra el numero de apariciones
	              de una cifra en los numeros contenidos en un
	              intervalo cerrado.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

int main(){
	
	int minimo, maximo, cifra, numero, contador_cifra = 0;
   bool numero_contiene_cifra;
   
   /*
      Algoritmo:
      
         Introducir dos numeros enteros (el segundo menor que el primero)
         y una cifra (entre 1 y 9).
         
         Ver cuantas veces aparece la cifra introducida en el intervalo
         formado por los dos numeros enteros introducidos.
         
         Mostrar en pantalla el número de veces que aparece dicha cifra
         en dicho intervalo.
   */

   cout << " Introduzca un numero entero 'a': ";
   cin >> minimo;
   
   do{
      cout << " Introduzca un numero entero 'b' (siendo b > a): ";
      cin >> maximo;
   }while(maximo < minimo);
   
   do{
      cout << "\n Introduzca una cifra (entre 1 y 9): ";
      cin >> cifra;
   }while((cifra < 1) || (cifra > 9));
      
   for( int i = minimo; i <= maximo; i++){
      
      if(minimo > 0)
         numero = i;
         
      else
         numero = -i;
      
      while(numero != 0){
         
         numero_contiene_cifra = (numero % 10) == cifra;
         
         if(numero_contiene_cifra)
            contador_cifra++;
         
         numero /= 10;
      }
   }
   
   cout << "\n La cifra " << cifra << " aparece " << contador_cifra << " veces en el intervalo [" << minimo << "," << maximo << "]" << endl << endl;
 
   system("pause");
}
