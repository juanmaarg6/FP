// Nombre: Juan Manuel Rodríguez Gómez
// Programa: Devuelve el número de apariciones
//           de una cifra "k" en los enteros contenidos
//           en un intervalo cerrado de numeros enteros
//           [a,b], siendo a < b.

#include <iostream>

using namespace std;

int main(){
   
   int entero_a, entero_b, cifra_k, numero, contador_k = 0;
   bool numero_contiene_k;
   
   /*
      Algoritmo:
      
         Introducir "entero_a", "entero_b" y "cifra_k", siendo
         entero_b > entero_a y 0 <= cifra_k <= 9.
         
         Si un dígito de uno de los números comprendidos en el 
         intervalo cerrado ["entero_a","entero_b"] es igual a "cifra_k":
         
            Aumentar "contador_k" en 1.
         
         Mostrar en pantalla el número de veces que aparece "cifra_k" en
         en el intervalo cerrado ["entero_a","entero_b"], es decir, 
         mostrar "contador_k".
   */
   
   cout << " Introduzca un numero entero 'a': ";
   cin >> entero_a;
   
   do{
      cout << " Introduzca un numero entero 'b' (siendo b > a): ";
      cin >> entero_b;
   }while(entero_b < entero_a);
   
   do{
      cout << "\n Introduzca una cifra 'k' (siendo 0 <= k <= 9): ";
      cin >> cifra_k;
   }while((cifra_k < 0) || (cifra_k > 9));
      
   for( int i = entero_a; i <= entero_b; i++){
      
      if(entero_a > 0)
         numero = i;
         
      else
         numero = -i;
      
      while(numero != 0){
         
         numero_contiene_k = (numero % 10) == cifra_k;
         
         if(numero_contiene_k)
            contador_k++;
         
         numero /= 10;
      }
   }
   
   cout << "\n La cifra " << cifra_k << " aparece " << contador_k << " veces en el intervalo [" << entero_a << "," << entero_b << "]" << endl << endl;
 
   system("pause");  
}
