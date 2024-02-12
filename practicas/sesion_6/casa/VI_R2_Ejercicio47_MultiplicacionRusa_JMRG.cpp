/*
	Ejercicio 47: Programa que aplica el algoritmo de la
					  multiplicación rusa para calcular
					  la multiplicación de dos números enteros.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>														

using namespace std;

int main(){
	
	int multiplicando, auxiliar_multiplicando, multiplicador, auxiliar_multiplicador, resultado;
	bool multiplicando_impar;	
	
	/*
		Algoritmo:
		
		Introducir "multiplicando" y "multiplicador".
		
		Asignar los valores de "multiplicando" y "multiplicador" a sus
		respectivas variables auxiliares.
		
		Mientras "auxiliar_multiplicando" sea mayor o igual que 1:
		
			Comprobar si "auxiliar_multiplicando" es impar.
			
			Si "auxiliar_multiplicando" es impar, entonces sumar
			"auxiliar_multiplicador" a "resultado".
			
			Dividir "auxiliar_multiplicando" por 2.
			Multiplicar "auxiliar multiplicador" por 2.
			
		Mostrar en pantalla "multiplicando", "multiplicador" y "resultado".
	*/			
	
	cout << " Introduzca multiplicando: ";					
	cin >> multiplicando;
	
	cout << " Introduzca multiplicador: ";
	cin >> multiplicador;
	
	auxiliar_multiplicando = multiplicando;
	auxiliar_multiplicador = multiplicador;
	
	while(auxiliar_multiplicando >= 1){	
		
		multiplicando_impar = (auxiliar_multiplicando % 2) == 1;															
		
		if(multiplicando_impar)			
			resultado += auxiliar_multiplicador;
		
		auxiliar_multiplicando /= 2;
		auxiliar_multiplicador *= 2;
	}
	
	cout << "\n El resultado de multiplicar " << multiplicando << " por " << multiplicador << " es: " << resultado << endl << endl;
	
	system("pause");
}
