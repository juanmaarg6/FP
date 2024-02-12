/*
	Ejercicio 17: Programa que lee un vector de numeros
	              enteros y devuelve dos nuevos vectores
	              que contienen, respectivamente, los
	              numeros pares e impares del vector inicial.
	              
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

const int LONGITUD_MAXIMA = 1000;

/*
	Funcion que divide un vector en otros dos: uno que contiene los numeros pares
	del vector original y otro que contiene los impares.
	
	Parametros: vector[] (int), longitud (int)
	
	Algoritmo:
		Se recorren todas las componentes del vector original.
		
		Si el numero es par, se almacena en el vector de numeros pares.
		Si no, se almacena en el vector de numeros impares.
		
		Se muestran en pantalla el vector de numeros pares y el de numeros impares.
				
	Devuelve: -
*/
void ParImpar(int vector[], int longitud);

int main(){
	int vector[LONGITUD_MAXIMA] = {0};
	int longitud = 0;
	
	/*
		Algoritmo:
			El usuario introduce la longitud del vector y dicho vector.
			
			Se calculan los vectores de numeros pares e impares y se
			muestran en pantalla.
	*/
	
	cout << " Introduzca la longitud del vector: ";
	cin >> longitud;
	
	if(longitud > LONGITUD_MAXIMA){
		cout << "\n Error. La maxima longitud permitida es " << LONGITUD_MAXIMA << endl << endl;
		exit(-1);	
	}
	
	cout << "\n Introduzca un vector: ";
	for(int i = 0; i < longitud; i++)
		cin >> vector[i];
	
	ParImpar(vector, longitud);
	
	cout << endl << endl;
	
	system("pause");
}

void ParImpar(int vector[], int longitud){
	int vector_par[LONGITUD_MAXIMA] = {0};
	int vector_impar[LONGITUD_MAXIMA] = {0};
	int longitud1 = 0, longitud2 = 0;
	
	for(int i = 0; i < longitud; i++){
		if(vector[i] % 2 == 0){
			vector_par[longitud1] = vector[i];
			longitud1++;
		}
		else{
			vector_impar[longitud2] = vector[i];
			longitud2++;
		}
	}
	
	cout << "\n Vector de numeros pares: ";
	for(int i = 0; i < longitud1; i++)
		cout << vector_par[i] << " ";
	
	cout << "\n Vector de numeros impares: ";
	for(int i = 0; i < longitud2; i++)
		cout << vector_impar[i] << " ";
}
