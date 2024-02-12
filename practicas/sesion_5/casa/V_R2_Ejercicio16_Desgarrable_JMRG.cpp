/*
   Ejercicio 16: Programa que lee un número entero y muestra en
                 pantalla si es o no es desgarrable.
                 
                 Un número entero n se dice que es desgarrable
                 si al dividirlo en dos partes (izquierda y derecha),
                 el cuadrado de la suma de ambas partes es igual a n.
                    
   Código fuente escrito por Juan Manuel Rodríguez Gómez
*/

#include <iostream>

using namespace std;

int main()
{
   int entero, parte_izquierda = 1, parte_derecha = 0;										
   int divisor = 10;
   
   bool es_desgarrable = 0;
   
   /*
   	1) Introducir un número entero desde teclado y almacenarlo en "entero".
   	2) Mientras que "entero" no cumpla que es desgarrable y la parte izquierda
   	   sea distinta que 0:
   	   2.1) Calcular "parte_izquierda" de "entero".
   	   2.2) Calcular "parte_derecha" de "entero".
   	   2.3) Comprobar si el número es desgarrable.
   	   2.4) Multiplicar "divisor" por 10 para calcular las diferentes "parte_izquierda"
   	        y "parte_derecha" en las que se puede dividir "entero".
   	3) Si "entero" es desgarrable, mostrar que sí lo es. En caso contrario, mostrar
   	   que no lo es.
   */
   
   cout << "Introduzca un numero entero: ";															
   cin >> entero;
   
   while((es_desgarrable == 0) && (parte_izquierda != 0)){																										
   	parte_izquierda = entero / divisor;
   	parte_derecha = entero % divisor;
   	
   	es_desgarrable = ((parte_izquierda + parte_derecha) * (parte_izquierda + parte_derecha)) == entero;
   	divisor *= 10;
   }
   
   if(es_desgarrable){
   	cout << "\n El numero " << entero << " es desgarrable";
   }
   
   else{
   	cout << "\n El numero " << entero << " no es desgarrable";
   }
   
	cout << "\n\n";
	
	system("pause");
}
