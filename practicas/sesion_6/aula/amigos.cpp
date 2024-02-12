// Nombre: Juan Manuel Rodríguez Gómez
// Programa: Muestra si dos números enteros son "amigos",
//           es decir, si la suma de los divisores propios 
//           de uno es igual al otro, y viceversa.

#include <iostream>

using namespace std;

int main(){
   
   int entero1, entero2, suma_divisores1 = 0, suma_divisores2 = 0;
   bool numeros_amigos;
   
   /*
      Algoritmo:
      
      Introducir "entero1" y "entero2".
      
      Calcular los divisores de "entero1" y
      sumar todos ellos ("suma_divisores1").
      
      Calcular los divisores de "entero2" y
      sumar todos ellos ("suma_divisores2").
      
      Si "suma_divisores2" es igual a "entero1"
      y "suma_divisores1" es igual a "entero2":
      
         Mostrar que "entero1" y "entero2" son números amigos.
         
      Si no:
      
         Mostrar que "entero1" y "entero2" no son números amigos.
   */
   
   cout << " Introduzca el primer numero entero: ";
   cin >> entero1;
   
   cout << " Introduzca el segundo numero entero: ";
   cin >> entero2;
   
   for(int divisor1 = 1; divisor1 < entero1; divisor1++){
      
      if( entero1 % divisor1 == 0 )
         suma_divisores1 += divisor1;
   }
         
   for(int divisor2 = 1; divisor2 < entero2; divisor2++){
      
      if( entero2 % divisor2 == 0 )
         suma_divisores2 += divisor2;   
   }
   
   numeros_amigos = (suma_divisores2 == entero1) && (suma_divisores1 == entero2); 
   
   if(numeros_amigos)
      cout << "\n Los numeros " << entero1 << " y " << entero2 << " son numeros amigos" << endl << endl; 
   else
      cout << "\n Los numeros " << entero1 << " y " << entero2 << " no son numeros amigos" << endl << endl;  
 
   system("pause");  
}
