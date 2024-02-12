/*
   Ejercicio 14: Programa que, dados un capital inicial y un interés, calcula
					  cuántos años han de pasar hasta llegar a doblar, como mínimo, el capital inicial.
                    
   Código fuente escrito por Juan Manuel Rodríguez Gómez
*/

#include <iostream>

using namespace std;

int main()
{
   double capital, interes, doble_capital;                                                    
   int anio = 0;
   
   /*
   	1) Introducir un capital inicial y un interés desde teclado y almacenarlos 
		   en "capital" e "interes", respectivamente.
   	2) doble_capital = capital * 2.
   	3) Mientras que capital <= doble_capital:
   		3.1) capital = capital * (1 + (interes / 100)).
   		3.2) Aumentar "anio" (es un contador) en 1 .
   	4) Mostrar "anio".
   */
   
   cout << " Introduzca el capital inicial (en euros): ";                                                  
   cin >> capital;

   cout << " Introduzca el interes (en %): ";
   cin >> interes;
   
   doble_capital = capital * 2;
   
   while(capital <= doble_capital){
      capital = capital * (1 + (interes / 100));
      
      anio++;
   }
   
   cout << "\n Pasaran " << anio << " años hasta doblar el capital";
   cout << "\n\n";
   
   system("pause");
}
   
