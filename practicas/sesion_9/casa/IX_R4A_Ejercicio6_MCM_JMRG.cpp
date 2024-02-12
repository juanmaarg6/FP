/*
	Ejercicio 6: Programa que muestra el Minimo Comun Multiplo
				    de dos numeros enteros.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

// Funcion que calcula y devuelve el mcm de dos numeros

int MCM(int num1, int num2){
	int contador = 2, respuesta = 0;
	bool mcm = false;
	
	while(!mcm){
		mcm = ((contador % num1 == 0) && (contador % num2 == 0));
		
		if(mcm)
			respuesta = contador;
		else
			contador++;
	}
	
	return respuesta;
}

int main(){
	int num1 = 0, num2 = 0;
	int mcm = 0;
	
	/*
		Algoritmo:
		
		El usuario introduce dos numeros positivos.
		
		Calcular el Minimo Comun Multiplo.
		
		Mostrar en pantalla el Minimo Comun Multiplo
		de los dos numeros positivos.
	*/
	
	do{
		cout << " Inserte un numero positivo 'a': ";
		cin >> num1;
		
		cout << " Inserte un numero positivo 'b': ";
		cin >> num2;
	}while(num1 <= 0 || num2 <= 0);
	
	mcm = MCM(num1, num2);
	
	cout << "\n El Minimo Comun Multiplo de " << num1 << " y " << num2 << " es: " << mcm << endl << endl;
	
	system("pause");
}
