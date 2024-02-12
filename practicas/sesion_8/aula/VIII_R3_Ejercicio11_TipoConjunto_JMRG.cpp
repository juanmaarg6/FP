/*
	Ejercicio 11: Programa que, dado un conjunto ordenado
	              de forma ascendente introducido por el usuario:
	
					  1) Determina si un elemento se encuentra en
					  	  dicho conjunto.
					  	  
					  2) Incorpora un nuevo elemento al conjunto,
					     manteniendo el orden ascendente.
					     
					  3) Calcula la union de dicho conjunto con otro
					     introducido por el usuario.
				
					  4) Calcula la interseccion de dicho conjunto con otro
					     introducido por el usuario.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

struct TipoConjunto{
	int num_elem;
	int elementos[1000];
};

void menu_opciones(){
	
	cout << "\n Menu de opciones: \n";
	cout << "\n\t 1) Determinar si un elemento esta dentro del conjunto\n";
	cout << "\t 2) Incorporar un nuevo elemento al conjunto\n";
	cout << "\t 3) Calcular la union de 2 conjuntos\n";
	cout << "\t 4) Calcular la interseccion de 2 conjuntos\n";
	
	cout << "\n Introduzca una opcion: ";
}
	
int main(){
	
	TipoConjunto conjunto1, conjunto2, conjunto_union;
	int opcion = 0, elemento = 0;
	int posicion_nuevo_elemento = 0;
	
	// Contador
	int i = 0, a = 0, b = 0, k = 0;
	
	// Variable para la opcion 1
	bool elemento_conjunto = false;
	
	// Variables para la opcion 2
	bool elemento_entre_componentes = false;
	bool elemento_menor_todos = false;
	
	// Variables enteras para la opcion 3
	int valor_minimo = 0, posicion_valor_minimo = 0, intercambio;
	
	/*
		Algoritmo:
		
		El usuario introduce el cardinal del conjunto y dicho conjunto.
   	
   	Opcion 1:
   	
   		El usuario introduce el elemento a buscar.
   		
   		Se recorre todo el conjunto para ver si el elemento
   		introducido esta dentro del conjunto.
   		
   		Si esta:
   			Mostrar en pantalla que "elemento" esta en el conjunto.
   			
   		Si no esta:
   			Mostrar en pantalla que "elemento" no esta en el conjunto.
   	
   		
		Opcion 2:
		
			El usuario introduce el elemento a incorporar.
			
			1º caso) el elemento a incoporar esta entre otros del conjunto 
			o es mayor que todos ellos;
			
				Se comprueba si el elemento a introducir esta entre otros
				del conjunto y en ese caso se le asigna al elemento una
				posicion en el conjunto para mantener el orden ascendente.
				
				Si el elemento esta entre otros del conjunto:
					Mostrar en pantalla el nuevo conjunto con el elemento
					introducido en su posicion correspondiente, de forma 
					que se mantiene el orden ascendente.
					
				Si no (significa que el elemento a introducir es mayor que
				todos los del conjunto):
					Mostrar en pantalla el nuevo conjunto con el elemento
					introducido al final.
					
		Opcion 3:
		
			El usuario introduce el cardinal de un segundo conjunto y 
			dicho conjunto.
			
			Juntamos el primer conjunto con el segundo, formando asi
			el conjunto union.
			
			Ordenar los elementos del conjunto union.
			
			Eliminar los elementos repetidos del conjunto union.
			
			Mostrar en pantalla el conjunto union.
			
		Opcion 4:
		
			El usuario introduce el cardinal de un segundo conjunto y 
			dicho conjunto.
			
			Se recorren ambos conjuntos y si hay un elemento que este
			simultaneamente en ambos conjuntos, entonces dicho elemento
			forma parte del conjunto interseccion.
			
			Mostrar en pantalla el conjunto interseccion.				
	*/
		
	cout << " Introduzca el cardinal del conjunto: ";
	cin >> conjunto1.num_elem;
	
	if(conjunto1.num_elem > 1000){
		cout << "\n Error. La maxima longitud permitida es 1000" << endl << endl;
		exit(-1);
	}
	
	cout << "\n Introduzca los elementos del conjunto: ";
	for(int i = 0; i < conjunto1.num_elem; i++)
		cin >> conjunto1.elementos[i];
	
	menu_opciones();
	cin >> opcion;
	
	// Opcion 1: Determinar si un elemento esta dentro del conjunto

	if(opcion == 1){
		cout << "\n\n Introduzca el elemento a buscar: ";
		cin >> elemento;
		
		while(!elemento_conjunto && i < conjunto1.num_elem){
			elemento_conjunto = elemento == conjunto1.elementos[i];
			
			i++;
		}
		
		if(elemento_conjunto)
			cout << "\n El elemento " << elemento << " esta en el conjunto" << endl << endl;
		
		else
			cout << "\n El elemento " << elemento << " no esta en el conjunto" << endl << endl;
	}
	
	// Opcion 2: Incorporar un nuevo elemento al conjunto
	
	if(opcion == 2){
		cout << "\n Introduzca el elemento a incorporar: ";
		cin >> elemento;
		
		// Caso en el que el elemento a incoporar esta entre otros del conjunto o es mayor que todos ellos
		
		while(i < conjunto1.num_elem){
			elemento_entre_componentes = (elemento >= conjunto1.elementos[i]) && (elemento <= conjunto1.elementos[i+1]);
			
			if(elemento_entre_componentes){
				posicion_nuevo_elemento = i;
				i = conjunto1.num_elem;
			}

			i++;
		}
		
		if(elemento_entre_componentes){
			cout << "\n Resultado:";

			for(int c = 0; c < conjunto1.num_elem; c++){
				cout << " " << conjunto1.elementos[c];
				if(c == posicion_nuevo_elemento)
					cout << " " << elemento;
			}
			
			cout << endl << endl;
		}
			
		else{
			cout << "\n Resultado: ";
			
			for(int b = 0; b < conjunto1.num_elem; b++)
				cout << conjunto1.elementos[b] << " ";
				
			cout << elemento << endl << endl;
		}
		
		// Caso en el que el elemento a incoporar es menor que todos los del conjunto
		
		if(elemento < conjunto1.elementos[0])
			elemento_menor_todos = true;
		
		if(elemento_menor_todos){
			cout << "\n Resultado: " << elemento;
			
			for(int b = 0; b < conjunto1.num_elem; b++)
				cout << " " << conjunto1.elementos[b];
			
			cout << endl << endl;
		}
	}
	
	// Opcion 3: Calcular la union de 2 conjuntos
	
	if(opcion == 3){
		cout << "\n Introduzca el cardinal del conjunto 2: ";
		cin >> conjunto2.num_elem;
	
		if(conjunto2.num_elem > 1000){
			cout << "\n Error. La maxima longitud permitida es 1000" << endl << endl;
			exit(-1);
		}
	
		cout << "\n Introduzca los elementos del conjunto 2: ";
		for(int i = 0; i < conjunto2.num_elem; i++)
			cin >> conjunto2.elementos[i];
					
		conjunto_union.num_elem = conjunto1.num_elem + conjunto2.num_elem;
		
		// Juntar el primer y el segundo conjunto en el conjunto union	
		
		while(a < conjunto1.num_elem){
			conjunto_union.elementos[a] = conjunto1.elementos[a];
			a++;
		}
		
		for(int c = a; c < conjunto_union.num_elem; c++){
			conjunto_union.elementos[c] = conjunto2.elementos[b];	
			b++;
		}
		
		// Ordenar los elementos del conjunto union
						
		for(int limite_partes = 0; limite_partes < conjunto_union.num_elem; limite_partes++){
			valor_minimo = conjunto_union.elementos[limite_partes];
			posicion_valor_minimo = limite_partes;
			
			for(int i = limite_partes; i < conjunto_union.num_elem; i++){
				if(conjunto_union.elementos[i] < valor_minimo){
					valor_minimo = conjunto_union.elementos[i];
					posicion_valor_minimo = i;
				}
			}
			
			intercambio = conjunto_union.elementos[limite_partes];
			conjunto_union.elementos[limite_partes] = valor_minimo;
			conjunto_union.elementos[posicion_valor_minimo] = intercambio;
			
		}
				
		// Eliminar los elementos repetidos del conjunto union
			
		for(int i = 0; i < conjunto_union.num_elem; i++){
			for(int j = i + 1; j < conjunto_union.num_elem; j++){
				if(conjunto_union.elementos[i] == conjunto_union.elementos[j]){
					k = j;
					
					while(k < conjunto_union.num_elem){
						conjunto_union.elementos[k] = conjunto_union.elementos[k+1];
						k++;
					}
					conjunto_union.num_elem--;
				}
			}
		}
				
		cout << "\n Conjunto union: ";
		for(int i = 0; i < conjunto_union.num_elem; i++)
			cout << conjunto_union.elementos[i] << " ";				
			
		cout << endl << endl;
	}
	
	// Opcion 4: Calcular la interseccion de 2 conjuntos
	
	if(opcion == 4){
		
		cout << "\n Introduzca el cardinal del conjunto 2: ";
		cin >> conjunto2.num_elem;
	
		if(conjunto2.num_elem > 1000){
			cout << "\n Error. La maxima longitud permitida es 1000" << endl << endl;
			exit(-1);
		}
	
		cout << "\n Introduzca los elementos del conjunto 2: ";
		for(int i = 0; i < conjunto2.num_elem; i++)
			cin >> conjunto2.elementos[i];
		
		cout << "\n Conjunto interseccion:";
		for(int a = 0; a < conjunto1.num_elem; a++){
			for(int b = 0; b < conjunto2.num_elem; b++){
				if(conjunto1.elementos[a] == conjunto2.elementos[b])
					cout << " " << conjunto1.elementos[a];
			}
		}
		
		cout << endl << endl;
	}
		
	system("pause");
}
