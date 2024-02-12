/*
	Ejercicio 21: Programa que determina si dos palabras son iguales
				     segun el siguiente criterio: la primera y la ultima
				     letra de ambas es la misma y el resto de letras son las
				     mismas pero no necesariamente en las mismas posiciones.
				     
	Codigo fuente realizado por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <string>

using namespace std;

/*
	Funcion que ordena alfabeticamente una palabra desde su segunda letra hasta
	su penultima.
	
	Parametros: palabra.
	
	Devuelve: palabra.
*/
string Ordenar(string palabra);

/*
	Funcion que determina si dos palabras son iguales segun el criterio dado.
	
	Parametros: palabra1, palabra2
	
	Devuelve: "true" si son iguales y "false" si no lo son.
*/
bool PalabrasIguales(string palabra1, string palabra2);


int main(){
   string palabra1;
   string palabra2;
   
   bool palabras_iguales;
   
   /*
   	Algoritmo:
   	
   	El usuario introduce dos palabras.
   	
   	Se comprueba si son iguales.
   	
   	Si lo son, mostrar que son iguales.
   	Si no, mostrar que no son iguales.
   */
    
   cout << " Introduzca la primera palabra: ";
   cin >> palabra1;
   
   cout << "\n Introduzca la segunda palabra: ";
   cin >> palabra2;
	    
   palabras_iguales = PalabrasIguales(palabra1, palabra2);
    
   if(palabras_iguales)
      cout << "\n\n Las palabras son iguales" << endl << endl;
   else
      cout << "\n\n Las palabras no son iguales" << endl << endl;
      
   system("pause");
}

string Ordenar(string palabra){
	
	int primera_letra = 1;
	int penultima_letra = palabra.length() - 1;
   int valor_minimo, posicion_valor_minimo;
   char intercambio;
    
   /*  
		Algoritmo: 
		
		Ordenar alfabeticamente los caracteres comprendidos
		entre el segundo caracter y el penultimo caracter de la palabra
		(ambos incluidos).
   */
    
	for(int limite_partes = primera_letra; limite_partes < penultima_letra; limite_partes++){
		valor_minimo = palabra[limite_partes];
		posicion_valor_minimo = limite_partes;
		
		for(int i = limite_partes; i < penultima_letra; i++){
			if(palabra[i] < valor_minimo){
				valor_minimo = palabra[i];
				posicion_valor_minimo = i;
			}
		}
		
		intercambio = palabra[limite_partes];
		palabra[limite_partes] = valor_minimo;
		palabra[posicion_valor_minimo] = intercambio;	
	}
           
   return palabra;
}

bool PalabrasIguales(string palabra1, string palabra2){

   bool longitudes_iguales;
   bool palabras_iguales;
    
   /* 
		Algoritmo:
		
		Comprobar si las longitudes de las dos palabras son iguales.
		
		Si lo son:
			Ordenar ambas palabras desde la segunda hasta la penultima letra.
			Comprobar si son iguales.
     */
   
   longitudes_iguales = palabra1.length() == palabra2.length();
    
   if(longitudes_iguales)
        palabras_iguales = Ordenar(palabra1) == Ordenar(palabra2);

   return palabras_iguales;
}
