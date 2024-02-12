/*
   Ejercicio 18: Programa que calcula la funci�n potencia x^n y la funci�n factorial n!,
                 siendo n un n�mero entero y x un n�mero real.
                    
   C�digo fuente escrito por Juan Manuel Rodr�guez G�mez
*/

#include <iostream>

using namespace std;

int main(){	
	
	double x = 0, potencia = 1, contador_potencia = 0;
	int n = 0, factorial = 1, contador_factorial = 0;
	
	/*
   	1) Introducir un n�mero real y un n�mero entero y almacenarlos
   	   en "x" y "n", respectivamente.
   	2) Calcular la funci�n potencia x^n ("potencia").
   	3) Calcular la funci�n factorial n! ("factorial").
   		3.1) Se valora el caso de que 0! = 1 (esto es as� por convenio).
   	4) Mostrar "potencia" y "factorial".
   */							
	
	cout << " Introduzca un numero real (x): ";
	cin >> x;
	
	cout << " Introduzca un numero natural (n): ";				
	cin >> n;
	


	while(contador_potencia != n){
		contador_potencia++;
		potencia *= x;	
	}
	
	if(n == 0){
		factorial = 1;
	}
	
	else{
		
		while(contador_factorial != n){
			contador_factorial++;
			factorial *= contador_factorial;	
		}
	}
	
	cout << "\n Funcion potencia (x^n) = " << x << "^" << n << " = " << potencia;
	cout << "\n Funcion factorial (n!) = " << n << "!" << " = " << factorial << endl;
	cout << "\n\n";
	
	system("pause");
}
