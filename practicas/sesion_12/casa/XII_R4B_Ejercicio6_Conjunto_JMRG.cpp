/*
	Ejercicio 6: Programa que, dados dos conjuntos (conjunto 1 y conjunto 2),
	             realiza una de las siguientes opciones:
	             
					 1) Determinar si un elemento esta dentro del conjunto 1.
					 2) Determinar si un elemento esta dentro del conjunto 2.
					 3) Incorporar un nuevo elemento al conjunto 1.
					 4) Incorporar un nuevo elemento al conjunto 2.
					 5) Eliminar un elemento del conjunto 1.
					 6) Eliminar un elemento del conjunto 2.
					 7) Calcular la union de conjunto 1 y conjunto 2.
					 8) Calcular la interseccion de conjunto 1 y conjunto 2.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/
#include <iostream>

using namespace std;

const int MAXIMOS_ELEMENTOS = 100;

/*
	Clase en la que cada objeto de ella representa un
	conjunto.
*/
class Conjunto{
	private:
		int numero_elementos; // Numero de elementos del conjunto
		int elementos[MAXIMOS_ELEMENTOS]; // Elementos del conjunto
		
		/*
			Funcion que ordena de menor a mayor los elementos del conjunto.
			
			Parametros: vector[] (int), longitud (int).
			
			Devuelve: -
		*/	
		void OrdenarConjunto(int vector[], int &longitud);
		
		/*
			Funcion que elimina los elementos repetidos del conjunto.
			
			Parametros: vector[] (int), longitud (int).
			
			Devuelve: -
		*/	
		void EliminarElementosRepetidos(int vector[], int &longitud);
		
	public:
		/*
			Constructor por defecto.
			
			Parametros: -
			
			Devuelve: -
		*/	
		Conjunto();

		/*
			Funcion que establece el numero de elementos del conjunto.
			
			Parametros: _numero_elementos (int).
			
			Devuelve: -
		*/
		void EstablecerNumeroElementos(int _numero_elementos);

		/*
			Funcion que establece los elementos del conjunto.
			
			Parametros: _elementos[] (int), _numero_elementos (int).
			
			Devuelve: -
		*/
		void EstablecerElementos(int _elementos[], int _numero_elementos);

		/*
			Funcion que muestra los elementos del conjunto.
			
			Parametros: -
			
			Devuelve: -
		*/
		void MostrarConjunto();

		/*
			Funcion que determina si un elemento esta o no en el conjunto.
			
			Parametros: -
			
			Devuelve: -
		*/
		void BuscarElemento();	

		/*
			Funcion que incorpora un nuevo elemento al conjunto.
			
			Parametros: -
			
			Devuelve: -
		*/
		void IncorporarNuevoElemento();

		/*
			Funcion que elimina un elemento del conjunto.
			
			Parametros: -
			
			Devuelve: -
		*/
		void EliminarElemento();

		/*
			Funcion que calcula la union de dos conjuntos.
			
			Parametros: conjunto2 (Conjunto).
			
			Devuelve: -
		*/	
		void ConjuntoUnion(Conjunto conjunto2);
		
		/*
			Funcion que calcula la interseccion de dos conjuntos.
			
			Parametros: conjunto2 (Conjunto).
			
			Devuelve: -
		*/		
		void ConjuntoInterseccion(Conjunto conjunto2);
};

/*
	Funcion que lee un conjunto (es decir, su numero de 
	elementos y los elementos que lo forman).
	
	Parametros: conjunto (Conjunto).
	
	Devuelve: -
*/	
void LeerConjunto(Conjunto &conjunto);

/*
	Funcion que muestra un menu de opciones para
	que el usuario elija una de ellas.
	
	Parametros: -
	
	Devuelve: -
*/	
void MenuOpciones();

int main(){
	Conjunto conjunto1, conjunto2;
	int opcion = 0;
	
	/*
		Algoritmo:
		
		El usuario introduce el conjunto1 y este se muestra.
		El usuario introduce el conjunto2 y este se muestra.
		
		Se muestra el menu de opciones.
			Si "opcion == 1", se determina si un elemento esta o no en el conjunto1.
			
			Si "opcion == 2", se determina si un elemento esta o no en el conjunto2.

			Si "opcion == 3", se incorpora un nuevo elemento al conjunto1.

			Si "opcion == 4", se incorpora un nuevo elemento al conjunto2.
			
			Si "opcion == 5", se elimina un elemento del conjunto1.

			Si "opcion == 6", se elimina un elemento del conjunto2.

			Si "opcion == 7", se calcula la union de conjunto1 y conjunto2.

			Si "opcion == 8", se calcula la interseccion de conjunto1 y conjunto2.
	*/

	cout << " Conjunto 1 \n";
	LeerConjunto(conjunto1);
	
	cout << "\n\t Conjunto 1: ";
	conjunto1.MostrarConjunto();
	
	cout << "\n\n Conjunto 2 \n";
	LeerConjunto(conjunto2);
	
	cout << "\n\t Conjunto 2: ";
	conjunto2.MostrarConjunto();

	MenuOpciones();
	cin >> opcion;
	
	if(opcion == 1)
		conjunto1.BuscarElemento();
	if(opcion == 2)
		conjunto2.BuscarElemento();
	if(opcion == 3)
		conjunto1.IncorporarNuevoElemento();
	if(opcion == 4)
		conjunto2.IncorporarNuevoElemento();
	if(opcion == 5)
		conjunto1.EliminarElemento();
	if(opcion == 6)
		conjunto2.EliminarElemento();
	if(opcion == 7)
		conjunto1.ConjuntoUnion(conjunto2);
	if(opcion == 8)
		conjunto1.ConjuntoInterseccion(conjunto2);
		
	cout << endl << endl;
	system("pause");
}

void LeerConjunto(Conjunto &conjunto){
	int numero_elementos;
	int elementos[MAXIMOS_ELEMENTOS];
	
	/*
		Algoritmo:
		
		El usuario introduce el numero de elementos del conjunto y este
		se establece en el objeto conjunto.
		
		El usuario introduce los elementos del conjunto y este
		se establece en el objeto conjunto.
	*/
	
	do{
		cout << "\n\t Introduzca el numero de elementos del conjunto: ";
		cin >> numero_elementos;
	}while(numero_elementos < 0 || numero_elementos > MAXIMOS_ELEMENTOS);
	
	conjunto.EstablecerNumeroElementos(numero_elementos);
	
	cout << "\t Introduzca los elementos del conjunto: ";
	for(int i = 0; i < numero_elementos; i++)
		cin >> elementos[i];
		
	conjunto.EstablecerElementos(elementos, numero_elementos);
}

void MenuOpciones(){
	
	/*
		Algoritmo: 
		
		Se muestran las diferentes opciones que puede elegir el usuario.
	*/
	
	cout << "\n\n Menu de opciones: \n";
	cout << "\n\t 1) Determinar si un elemento esta dentro del conjunto 1\n";
	cout << "\t 2) Determinar si un elemento esta dentro del conjunto 2\n";
	cout << "\t 3) Incorporar un nuevo elemento al conjunto 1\n";
	cout << "\t 4) Incorporar un nuevo elemento al conjunto 2\n";
	cout << "\t 5) Eliminar un elemento del conjunto 1\n";
	cout << "\t 6) Eliminar un elemento del conjunto 2\n";
	cout << "\t 7) Calcular la union de conjunto 1 y conjunto 2\n";
	cout << "\t 8) Calcular la interseccion de conjunto 1 y conjunto 2\n";
	
	cout << "\n Introduzca una opcion: ";
}

void Conjunto::OrdenarConjunto(int vector[], int &longitud){
	int valor_minimo = 0, posicion_valor_minimo = 0, intercambio;
	
	/*
		Algoritmo:
		
		Se recorren todos los elementos de vector[limite_partes] de vector.
			Se halla la posicion (posicion_valor_minimo) del menor elemento
			del subvector delimitado por las componentes [limite_partes, longitud - 1],
			ambos inclusive.
			
			Se intercambian vector[limite_partes] con vector[posicion_valor_minimo].
	*/
	
	for(int limite_partes = 0; limite_partes < longitud; limite_partes++){
		valor_minimo = vector[limite_partes];
		posicion_valor_minimo = limite_partes;
		
		for(int i = limite_partes; i < longitud; i++){
			if(vector[i] < valor_minimo){
				valor_minimo = vector[i];
				posicion_valor_minimo = i;
			}
		}
		
		intercambio = vector[limite_partes];
		vector[limite_partes] = valor_minimo;
	vector[posicion_valor_minimo] = intercambio;	
	}
}

void Conjunto::EliminarElementosRepetidos(int vector[], int &longitud){
	int k = 0;
	
	/*
		Algoritmo:
		
		Se recorre elemento a elemento el vector. 
		
			Si un elemento coincide con el siguiente, entonces
			cada elemento a partir de dicho elemento siguiente
			se iguala a su elemento siguiente.
			
			La longitud del vector se reduce en 1.
	*/
	
	for(int i = 0; i < longitud; i++){
		for(int j = i + 1; j < longitud; j++){
			if(vector[i] == vector[j]){
				k = j;
				
				while(k < longitud){
					vector[k] = vector[k + 1];
					k++;
				}
				
				longitud--;
				j--;
			}
		}
	}
}

Conjunto::Conjunto(){
	numero_elementos = 0;
	elementos[MAXIMOS_ELEMENTOS] = 0;
}

void Conjunto::EstablecerNumeroElementos(int _numero_elementos){
	numero_elementos = _numero_elementos;
}

void Conjunto::EstablecerElementos(int _elementos[], int _numero_elementos){
	
	/*
		Algoritmo:
		
		Se establecen los elementos del objeto conjunto.
		
		Se ordenan dichos elementos y se eliminan los repetidos.
	*/
	
	for(int i = 0; i < _numero_elementos; i++)
		elementos[i] = _elementos[i];

	OrdenarConjunto(elementos, numero_elementos);
	EliminarElementosRepetidos(elementos, numero_elementos);
}

void Conjunto::MostrarConjunto(){
	for(int i = 0; i < numero_elementos; i++)
		cout << elementos[i] << " ";
}

void Conjunto::BuscarElemento(){
	bool encontrado = false;
	int elemento;
	int i = 0;
	
	/*
		Algoritmo:
		
		El usuario introduce un elemento a buscar en el conjunto.
		
		Miestras que dicho elemento no sea encontrado, se compara
		,elemento a elemento, todos los elementos del conjunto.
		
		Si el elemento a buscar esta en el conjunto, se muestra que dicho
		elemento se encuentra en el conjunto.
		Si no, se muestra que dicho elemento no se encuentra en el conjunto.
	*/
	
	cout << "\n Introduzca el elemento a buscar en el conjunto: ";
	cin >> elemento;
	
	while(i != numero_elementos && !encontrado){
		encontrado = elemento == elementos[i];
		i++;
	}
	
	if(encontrado)
		cout << "\n\t El elemento " << elemento << " se encuentra en dicho conjunto";
	else
		cout << "\n\t El elemento " << elemento << " no se encuentra en dicho conjunto";
}		

void Conjunto::IncorporarNuevoElemento(){
	int nuevo_elemento = 0;
	
	/*
		Algoritmo:
		
		El usuario introduce un elemento a incorporar al conjunto.
		
		Se amplia la longitud del conjunto en 1 y se incorpora
		dicho elemento al conjunto.
		
		Se ordenan los elementos del conjunto y se eliminan los repetidos.
		
		Se muestra el conjunto resultante.
	*/
	
	cout << "\n Introduzca el elemento a incorporar al conjunto: ";
	cin >> nuevo_elemento;
	
	numero_elementos += 1;
	elementos[numero_elementos - 1] = nuevo_elemento;
				
	OrdenarConjunto(elementos, numero_elementos);
	EliminarElementosRepetidos(elementos, numero_elementos);
	
	cout << "\n\t Conjunto resultante:";
	for(int i = 0; i < numero_elementos; i++)
		cout << " " << elementos[i];
}

void Conjunto::EliminarElemento(){
	int posicion = 0;
	
	/*
		Algoritmo:
		
		El usuario introduce la posicion del elemento a eliminar del conjunto.
		
		Se recorren todas las componentes desde la posicion del elemento a eliminar
		hasta el final.
		
			Cada elemento pasa a tomar el valor del elemento siguiente.
			
		El numero de elementos del conjunto se reduce en 1.
	*/
				
	cout << "\n NOTA: La posicion del primer elemento corresponde al 0";
	
	cout << "\n Introduzca la posicion del elemento a eliminar del conjunto: ";
	cin >> posicion;
	
	if(posicion >= 0 && posicion < numero_elementos){		
		for(int i = posicion; i < numero_elementos - 1; i++)
			elementos[i] = elementos[i+1];
			
		numero_elementos--;
		
		cout << "\n\t Conjunto resultante:";
		for(int i = 0; i < numero_elementos; i++)
		cout << " " << elementos[i];
	}
	else
		cout << "\n\t La posicion introducida no se ha encontrado en dicho conjunto";
}

void Conjunto::ConjuntoUnion(Conjunto conjunto2){
	Conjunto conjunto_union;
	int a = 0, b = 0;
	
	/*
		Algoritmo:
		
		El numero de elementos del conjunto union se calcula como la suma
		del numero de elementos de los dos conjuntos.
		
		El conjunto union sera igual a juntar el primer conjunto con el 
		segundo conjunto.
		
		Se ordenan los elementos del conjunto union y se eliminan los repetidos.
		
		Se muestra el conjunto union.
	*/
	
	conjunto_union.numero_elementos = numero_elementos + conjunto2.numero_elementos;
	
	while(a < numero_elementos){
		conjunto_union.elementos[a] = elementos[a];
		a++;
	}
	
	for(int c = a; c < conjunto_union.numero_elementos; c++){
		conjunto_union.elementos[c] = conjunto2.elementos[b];	
		b++;
	}
	
	OrdenarConjunto(conjunto_union.elementos, conjunto_union.numero_elementos);
	EliminarElementosRepetidos(conjunto_union.elementos, conjunto_union.numero_elementos);
	
	cout << "\n\t Conjunto union:";
		for(int i = 0; i < conjunto_union.numero_elementos; i++)
			cout << " " << conjunto_union.elementos[i];		
}

void Conjunto::ConjuntoInterseccion(Conjunto conjunto2){
	
	/*
		Algoritmo:
			
		Se recorren ambos conjuntos y si hay un elemento que este
		simultaneamente en ambos conjuntos, entonces dicho elemento
		forma parte del conjunto interseccion.
		
		Se muestra el conjunto interseccion.
	*/
	cout << "\n\t Conjunto interseccion:";
	for(int a = 0; a < numero_elementos; a++)
		for(int b = 0; b < conjunto2.numero_elementos; b++)
			if(elementos[a] == conjunto2.elementos[b])
				cout << " " << elementos[a];
}
