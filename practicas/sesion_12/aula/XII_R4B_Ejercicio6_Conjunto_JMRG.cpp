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
#include <vector>

using namespace std;

/*
	Clase en la que cada objeto de ella representa un
	conjunto.
*/
class Conjunto{
	private:
		vector<int> elementos; // Elementos del conjunto
	
		/*
			Funcion que ordena de menor a mayor los elementos del conjunto.
			
			Parametros: vector[] (int), longitud (int).
			
			Devuelve: -
		*/	
		void OrdenarConjunto();
		
		/*
			Funcion que elimina los elementos repetidos del conjunto.
			
			Parametros: vector[] (int), longitud (int).
			
			Devuelve: -
		*/	
		void EliminarElementosRepetidos();
		
	public:
		/*
			Constructor por defecto.
			
			Parametros: -
			
			Devuelve: -
		*/	
		Conjunto();

		/*
			Constructor de la clase.
			
			Parametros: _elementos(vector<int>).
			
			Devuelve: -
		*/
		Conjunto(vector<int> _elementos);

		/*
			Funcion que lee un conjunto.
			
			Parametros: -
			
			Devuelve: -
		*/	
		void LeerConjunto();
		
		/*
			Funcion que obtiene el vector del objeto "elementos".
			
			Parametros: -
			
			Devuelve: elementos (vector<int>).
		*/	
		vector<int> ObtenerVector();

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
			
			Parametros: _conjunto2 (Conjunto).
			
			Devuelve: conjunto_union (vector<int>)
		*/	
		vector<int> ConjuntoUnion(Conjunto _conjunto2);
		
		/*
			Funcion que calcula la interseccion de dos conjuntos.
			
			Parametros: _conjunto2 (Conjunto).
			
			Devuelve: -
		*/		
		void ConjuntoInterseccion(Conjunto _conjunto2);
};

/*
	Funcion que muestra un menu de opciones para
	que el usuario elija una de ellas.
	
	Parametros: -
	
	Devuelve: -
*/	
void MenuOpciones();

int main(){
	Conjunto conjunto1, conjunto2, conjunto_union, conjunto_interseccion;
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
	conjunto1.LeerConjunto();
	
	cout << "\n\t Conjunto 1: ";
	conjunto1.MostrarConjunto();
	
	cout << "\n\n Conjunto 2 \n";
	conjunto2.LeerConjunto();
	
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
	if(opcion == 7){
		conjunto_union = conjunto1.ConjuntoUnion(conjunto2);
		conjunto_union.MostrarConjunto();
	}
	if(opcion == 8)
		conjunto1.ConjuntoInterseccion(conjunto2);
		
	cout << endl << endl;
	system("pause");
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

void Conjunto::OrdenarConjunto(){
	int valor_minimo = 0, posicion_valor_minimo = 0, intercambio;
	
	/*
		Algoritmo:
		
		Se recorren todos los elementos de vector[limite_partes] de vector.
			Se halla la posicion (posicion_valor_minimo) del menor elemento
			del subvector delimitado por las componentes [limite_partes, longitud - 1],
			ambos inclusive.
			
			Se intercambian vector[limite_partes] con vector[posicion_valor_minimo].
	*/
	
	for(int limite_partes = 0; limite_partes < elementos.size(); limite_partes++){
		valor_minimo = elementos[limite_partes];
		posicion_valor_minimo = limite_partes;
		
		for(int i = limite_partes; i < elementos.size(); i++){
			if(elementos[i] < valor_minimo){
				valor_minimo = elementos[i];
				posicion_valor_minimo = i;
			}
		}
		
		intercambio = elementos[limite_partes];
		elementos[limite_partes] = valor_minimo;
		elementos[posicion_valor_minimo] = intercambio;	
	}
}

void Conjunto::EliminarElementosRepetidos(){
   vector<int> elementos_unicos;
	bool encontrado_anteriormente = false;    
	int i = 0;
	
	/*
		Algoritmo:
		
		Mientras "i" sea menor que la longitud del vector "elementos":
			Se recorren todos los elementos del vector "elementos".
				Si se encuentra un elemento que se ha repetido anteriormente,
				entonces "encontrado_anteriormente = true",
				
			Si "encontrado_anteriormente", se elimina dicho elemento del vector "elementos".
			Si no, dicho elemento pasa a formar parte del vector "elementos_unicos".
	*/
	
	while (i < elementos.size()){
		encontrado_anteriormente = false;
		for(int j = 0; j < elementos_unicos.size() && !encontrado_anteriormente; j++)
		   if (elementos[i] == elementos_unicos[j])
		      encontrado_anteriormente = true;
		        
		if(encontrado_anteriormente)
		   elementos.erase(elementos.begin() + i);
		else{
		   elementos_unicos.push_back(elementos[i]);
		   i++;
		}
	}
}

Conjunto::Conjunto(){
	elementos = vector<int>(1,1);
}

Conjunto::Conjunto(vector<int> _elementos){     	
  	elementos = _elementos;
}


void Conjunto::LeerConjunto(){
	int numero_elementos;
	
	/*
		Algoritmo:
		
		El usuario introduce el numero de elementos del conjunto y este
		se establece en el objeto conjunto.
		
		El usuario introduce los elementos del conjunto y este
		se establece en el objeto conjunto.
	*/

	do{
	   cout << "\n Introduzca el numero de elementos del conjunto: ";
	   cin >> numero_elementos;
	}while(numero_elementos < 0 || numero_elementos > 100);

   vector<int> vector(numero_elementos);
    
   cout << "\n Introduzca los elementos del conjunto: ";
   for (int i = 0; i < numero_elementos; i++)
      cin >> vector[i];
    
   elementos = vector;	
}

vector<int> Conjunto::ObtenerVector(){
  	return elementos;
}
		
void Conjunto::MostrarConjunto(){
	
	/*
		Algoritmo:
		
		Se ordena el conjunto.
		
		Se eliminan los elementos repetidos del conjunto.
		
		Se muestran todos los elementos del conjunto.
	*/
	
	OrdenarConjunto();
  	
   EliminarElementosRepetidos();
   
	for(int i = 0; i < elementos.size(); i++)
		cout << elementos[i] << " ";
}

void Conjunto::BuscarElemento(){
	bool encontrado = false;
	int elemento;
	int i = 0;
	
	/*
		Algoritmo:
		
		El usuario introduce un elemento a buscar en el conjunto.
		
		Miestras que dicho elemento no sea encontrado, se compara,
		elemento a elemento, todos los elementos del conjunto.
		
		Si el elemento a buscar esta en el conjunto, se muestra que dicho
		elemento se encuentra en el conjunto.
		Si no, se muestra que dicho elemento no se encuentra en el conjunto.
	*/
	
	cout << "\n Introduzca el elemento a buscar en el conjunto: ";
	cin >> elemento;
	
	while(i != elementos.size() && !encontrado){
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
	
	elementos.resize(elementos.size() + 1);
	elementos[elementos.size() - 1] = nuevo_elemento;
				
	OrdenarConjunto();
	EliminarElementosRepetidos();
	
	cout << "\n\t Conjunto resultante:";
	for(int i = 0; i < elementos.size(); i++)
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
		
		Se muestra el conjunto resultante.
	*/
				
	cout << "\n NOTA: La posicion del primer elemento corresponde al 0";
	
	cout << "\n Introduzca la posicion del elemento a eliminar del conjunto: ";
	cin >> posicion;
	
	if(posicion >= 0 && posicion < elementos.size()){		
		for(int i = posicion; i < elementos.size() - 1; i++)
			elementos[i] = elementos[i + 1];
			
		elementos.resize(elementos.size() - 1);
		
		cout << "\n\t Conjunto resultante:";
		for(int i = 0; i < elementos.size(); i++)
		cout << " " << elementos[i];
	}
	else
		cout << "\n\t La posicion introducida no se ha encontrado en dicho conjunto";
}

vector<int> Conjunto::ConjuntoUnion(Conjunto _conjunto2){
	vector<int> conjunto2 = _conjunto2.ObtenerVector();
	vector<int> conjunto_union;
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
	
	conjunto_union.resize(elementos.size() + conjunto2.size());
	
	while(a < elementos.size()){
		conjunto_union[a] = elementos[a];
		a++;
	}
	
	for(int c = a; c < conjunto_union.size(); c++){
		conjunto_union[c] = conjunto2[b];	
		b++;
	}
	
	cout << "\n\t Conjunto union: ";
	
	return conjunto_union;	
}

void Conjunto::ConjuntoInterseccion(Conjunto _conjunto2){
	vector<int> conjunto2 = _conjunto2.ObtenerVector();
	
	/*
		Algoritmo:
			
		Se recorren ambos conjuntos y si hay un elemento que este
		simultaneamente en ambos conjuntos, entonces dicho elemento
		forma parte del conjunto interseccion.
		
		Se muestra el conjunto interseccion.
	*/
   
	cout << "\n\t Conjunto interseccion:";
	for(int a = 0; a < elementos.size(); a++)
		for(int b = 0; b < conjunto2.size(); b++)
			if(elementos[a] == conjunto2[b])
				cout << " " << elementos[a];
}
