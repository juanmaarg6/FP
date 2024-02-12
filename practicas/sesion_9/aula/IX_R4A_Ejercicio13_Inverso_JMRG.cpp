/*
	Ejercicio 13: Programa que, dado un numero entero, 
					  muestra el entero pero con sus digitos
					  en orden inverso.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

void Inversor(int numero){
   int resultado = 0;
   int auxiliar = 0;
   
   /*
   	Algoritmo:
   	
   	Mientras el numero sea distinto de 0:
   	
   		Se divide el numero por 10 y se almacena el resto.
   		
   		Se muestra dicho resto.
   		
   		Se elimina el ultimo digito del numero.
   */
   
   auxiliar = numero;
   
   do{
      resultado = auxiliar % 10;
      cout << resultado;
      auxiliar /= 10;
   }while(auxiliar != 0);
}

int main(){
   int numero = 0;
   
      /*
   	Algoritmo:
   	
   	El usuario introduce un numero entero.
   	
   	Se muestra en pantalla el numero entero pero
   	con sus digitos en orden inverso.
   */
   
   cout << " Introduzca un numero entero: ";
   cin >> numero;
   
   cout << "\n Numero con sus digitos en orden inverso: ";
   Inversor(numero);
   
   cout << endl << endl;
   
   system("pause");
}
