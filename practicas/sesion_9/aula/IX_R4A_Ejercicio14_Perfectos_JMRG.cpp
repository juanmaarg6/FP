/*
	Ejercicio 14: Programa que, dado un numero positivo, 
					  muestra todos los numeros perfectos
					  hasta el numero dado.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

int Perfecto(int tope){
	int contador;
	int total;
	
	cout << endl;
	
	/*
		Algoritmo:
		
		Desde el 2 hasta el numero "tope":
				
			Se calculan los divisores del numero
			correspondiente y se suman.
			
			Si la suma de los divisores es igual
			al numero correspondiente, entonces
			es numero perfecto, por lo que se muestra
			en pantalla.
	*/
	
	for(int i = 2; i <= tope; i++){
		total = 0;
		contador = 1;
		
		do{
			if(i % contador == 0)
				total += contador;
				
			contador++;
		}while(contador < i);
		
		if(total == i)
			cout << " " << i;
	}
}

int main(){
	int tope = 0;
	
		/*
		Algoritmo:
		
		El usuario introduce un numero positivo.
		
		Se muestran los numeros perfectos que hay
		el numero introducido. 
	*/
	
	do{
		cout << " Introduzca un numero positivo: ";
		cin >> tope;
	}while(tope <= 0);
	
	cout << "\n Numeros perfectos hasta " << tope << ": \n";
	Perfecto(tope);
	
	cout << endl << endl;
	
	system("pause");
}
