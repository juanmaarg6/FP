/*
   Ejercicio 14: Programa que, dados un capital inicial y un inter�s, calcula
					  cu�ntos a�os han de pasar hasta llegar a doblar, como m�nimo, el capital inicial.
                    
   C�digo fuente escrito por Juan Manuel Rodr�guez G�mez
*/

#include <iostream>

using namespace std;

int main()
{
   double capital, interes, doble_capital;                                                    
   int anio = 0;
   
   /*
   	1) Introducir un capital inicial y un inter�s desde teclado y almacenarlos 
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
   
   cout << "\n Pasaran " << anio << " a�os hasta doblar el capital";
   cout << "\n\n";
   
   system("pause");
}
   
