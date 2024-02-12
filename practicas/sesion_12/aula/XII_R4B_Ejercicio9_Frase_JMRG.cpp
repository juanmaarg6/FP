/*
	Ejercicio 9: Programa que, dada una frase,
	             realiza una de las siguientes opciones:
	             
					 1) Localizar la k-esima palabra de la frase.
					 2) Borrar los blancos iniciales de la frase.
					 3) Borrar los blancos finales de la frase.
					 4) Mostrar el numero de palabras de la frase.
					 5) Borrar la k-esima palabra de la frase.
					 6) Desplazar la k-esima palabra al final de la frase.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>
#include <vector>

using namespace std;

/*
	Clase en la que cada objeto de ella representa una
	frase.
*/
class Frase{
	private:
		vector<char> cadena; // Cadena de caracteres que forma la frase
	public:
		/*
			Constructor por defecto.
			
			Parametros: -
			
			Devuelve: -
		*/	
		Frase(){
		}
		
		/*
			Constructor de la clase.
			
			Parametros: frase (vector<char>).
			
			Devuelve: -
		*/	
		Frase(vector<char> frase){
			cadena = frase;
		}	
			
		/*
			Funcion que lee la frase.
			
			Parametros: -
			
			Devuelve: -
		*/	
		void LeerFrase();
		
		/*
			Funcion que muestra la cadena de caracteres que forma la frase.
			
			Parametros: -
			
			Devuelve: -
		*/	
		void MostrarVector();
		
		/*
			Funcion que muestra la frase.
			
			Parametros: -
			
			Devuelve: -
		*/			
		void MostrarCadena();
		
		/*
			Funcion que localiza una palabra elegida de la frase.
			
			Parametros: numero_palabra (int).
			
			Devuelve: posicion (int).
		*/		
		int LocalizarPalabra(int numero_palabra);

		/*
			Funcion que elimina los espacios blancos iniciales de la frase.
			
			Parametros: -
			
			Devuelve: -
		*/		
		void EliminarBlancosIniciales();

		/*
			Funcion que elimina los espacios blancos finales de la frase.
			
			Parametros: -
			
			Devuelve: -
		*/			
		void EliminarBlancosFinales();

		/*
			Funcion que muestra el numero de palabras de la frase.
			
			Parametros: -
			
			Devuelve: -
		*/			
		int NumeroPalabras();

		/*
			Funcion que borra una palabra elegida de la frase.
			
			Parametros: numero_palabra (int).
			
			Devuelve: -
		*/				
		void BorrarPalabra(int numero_palabra);

		/*
			Funcion que mueve una palabra elegida de la frase al final de dicha frase.
			
			Parametros: numero_palabra (int).
			
			Devuelve: -
		*/			
		void MoverPalabraFinal(int numero_palabra);
};

/*
	Funcion que muestra un menu de opciones para
	que el usuario elija una de ellas.
	
	Parametros: -
	
	Devuelve: -
*/	
void MenuOpciones();

int main(){
	Frase frase;
	int k_esima_palabra;
	int opcion = 0;
	
	/*
		Algoritmo:
		
		El usuario introduce una frase.
		
		Se muestra la cadena de caracteres que forma la frase y dicha frase.
		
		Se muestra el menu de opciones.
			Si "opcion == 1", se localiza una palabra elegida de la frase.
			
			Si "opcion == 2", se eliminan los espacios blancos iniciales de la frase.

			Si "opcion == 3", se eliminan los espacios blancos finales de la frase.

			Si "opcion == 4", se muestra el numero de palabras de la frase.
			
			Si "opcion == 5", se borra una palabra elegida de la frase.

			Si "opcion == 6", se mueve una palabra elegida de la frase al final de dicha frase.
	*/
	
	frase.LeerFrase();
	
	cout << "\n Vector: ";
	frase.MostrarVector();
	
	cout << "\n Frase: (-)";
	frase.MostrarCadena();
	cout << "(-)";
	
	MenuOpciones();
	cin >> opcion;
	
	if(opcion == 1){
		cout << "\n\t Introduzca el numero de la palabra a localizar: ";
		cin >> k_esima_palabra;
		
		cout << "\n\t Posicion: " << frase.LocalizarPalabra(k_esima_palabra);

	}
	
	if(opcion == 2){
		frase.EliminarBlancosIniciales();
		
		cout << "\n\t Vector final: ";
		frase.MostrarVector();
		
		cout << "\n\t Frase final: (-)";
		frase.MostrarCadena();
		cout << "(-)";
	}
	
	if(opcion == 3){
	frase.EliminarBlancosFinales();
	
	cout << "\n\t Vector final: ";
	frase.MostrarVector();
		
	cout << "\n\t Frase final: (-)";
	frase.MostrarCadena();
	cout << "(-)";
	}
	
	if(opcion == 4)
		cout << "\n\t Numero Palabras: " << frase.NumeroPalabras();
		
	if(opcion == 5){
		cout << "\n\t Introduzca el numero de la palabra a borrar: ";
		cin >> k_esima_palabra;
		
		frase.BorrarPalabra(k_esima_palabra);
		
		cout << "\n\t Vector final: ";
		frase.MostrarVector();
		
		cout << "\n\t Frase final: ";
		frase.MostrarCadena();	
	}

	if(opcion == 6){
		cout << "\n\t Introduzca el numero de la palabra a desplazar: ";
		cin >> k_esima_palabra;
		
		frase.MoverPalabraFinal(k_esima_palabra);
		
		cout << "\n\t Vector final: ";
		frase.MostrarVector();
		
		cout << "\n\t Frase final: ";
		frase.MostrarCadena();	
	}
		
	cout << endl << endl;
	system("pause");
}

void MenuOpciones(){
	
	/*
		Algoritmo: 
		
		Se muestran las diferentes opciones que puede elegir el usuario.
	*/
	
	cout << "\n\n Menu de opciones: \n";
	cout << "\n\t 1) Localizar la k-esima palabra de la frase\n";
	cout << "\t 2) Borrar los blancos iniciales de la frase\n";
	cout << "\t 3) Borrar los blancos finales de la frase\n";
	cout << "\t 4) Mostrar el numero de palabras de la frase\n";
	cout << "\t 5) Borrar la k-esima palabra de la frase\n";
	cout << "\t 6) Desplazar la k-esima palabra al final de la frase\n";
	
	cout << "\n Introduzca una opcion: ";
}

void Frase::LeerFrase(){
	char respuesta;
	
	/*
		El usuario introduce una frase.
		
		Se almacena cada caracter de la frase introducida hasta
		encontrar el caracter '.'
	*/
	
	cout << " Introduzca una frase acabando con '.': ";
	cin.get(respuesta);
	
	while(respuesta != '.'){
		cadena.push_back(respuesta);
		cin.get(respuesta);
	}
}

void Frase::MostrarVector(){
	
	/*
		Algoritmo:
		
		Se muestran todos los caracteres que forman la frase.
	*/
	
	cout << "(";
	cout << cadena[0];
	
	for (int i = 1; i < cadena.size(); i++)
		cout << ", " << cadena[i];

	cout << ")";
}
		
void Frase::MostrarCadena(){
	
	/*
		Algoritmo:
		
		Se muestra la frase.
	*/
	
	for(int i = 0; i < cadena.size(); i++)
		cout << cadena[i];
}

int Frase::LocalizarPalabra(int numero_palabra){
	int contador = 0;
	int posicion;
	bool buscando = true;
	bool acabar = false;
	
	/*
		Algoritmo:
		
		Si el numero de la palabra elegida a localizar es menor que el 
		numero de palabras:
			Desdede "i = 0" hasta el final de la cadena de caracteres
			y "acabar == false":
		
			Si "buscando":
				Si el caracter de la cadena es un espacio en blanco:
					Se aumenta "contador" en 1.
					
					Si "contador == numero_palabra":
						"acabar = true" y "posicion = i".
						
					"buscando = false".
			Si no:
				Si el caracter de la cadena es un espacio en blanco, 
				"buscando = true".
				
		Si no, se muestra que el numero de la palabra elegida a 
		localizar no es valido y se detiene el programa.
		
		Se devuelve "posicion".
	*/
	
	if(numero_palabra <= NumeroPalabras()){			
		for(int i = 0; i < cadena.size() && acabar == false; i++){
			if(buscando){
				if(cadena[i] != ' '){
					contador++;
					if(contador == numero_palabra){
						acabar = true;
						posicion = i;
					}
					buscando = false;
				}
			}
			else{
				if(cadena[i] == ' '){
					buscando = true;
				}
			}
		}
	}
	else{
		cout << "\n\t El numero de la palabra a localizar no es valido." << endl << endl;
		exit(-1);
	}
	
	return posicion;
}
	
void Frase::EliminarBlancosIniciales(){
	
	/*
		Algoritmo:
		
		Mientras el primer elemento de la cadena de caracteres sea
		un espacio en blanco:
			
			Cada elemento toma el valor del elemento siguiente de la
			cadena de caracteres.
			
			Se elimina el ultimo elemento del vector.
	*/
	while(cadena.front() == ' '){
		for (int i = 0; i < cadena.size(); i++)
			cadena[i] = cadena[i + 1];					

		cadena.pop_back();
	}
}

void Frase::EliminarBlancosFinales(){
		
	/*
		Algoritmo:
		
		Mientras el ultimo elemento de la cadena de caracteres sea
		un espacio en blanco:
			
			Se elimina el ultimo elemento del vector.
	*/
	
	while(cadena.back() == ' '){
		cadena.pop_back();
	}
}

int Frase::NumeroPalabras(){
	int contador_palabras = 0;
	bool buscando = true;
	
	/*
		Algoritmo:
		
		Desde "i = 0" hasta el final de la cadena de caracteres:
		
			Si "buscando":
				Si el caracter de la cadena es una letra (minuscula o
				mayuscula), aumenta en 1 el contador de palabras y 
				"buscando = false".
			Si no:
				Si el caracter de la cadena es un espacio en blanco, 
				"buscando = true".
	*/
	
	for (int i = 0; i < cadena.size(); i++){
		if(buscando){
			if(cadena[i] >= 'A' && cadena[i] <= 'z'){
				contador_palabras++;
				buscando = false;
			}
		}
		else{
			if(cadena[i] == ' ')
				buscando = true;
		}
	}
	
	return contador_palabras;
}

void Frase::BorrarPalabra(int numero_palabra){
	int posicion = LocalizarPalabra(numero_palabra);
	
	/*
		Algoritmo:
		
		Se localiza la posicion de la palabra a borrar.
		
		Mientras que el elemento que se encuentra en "posicion"
		no sea un espacio en blanco:
			Desde "i = posicion" hasta el final de la cadena de caracteres:
				Cada elemento toma el valor del elemento siguiente de la
				cadena de caracteres.
				
			Se elimina el ultimo elemento del vector.
	*/
	
	while(cadena[posicion] != ' '){
		for(int i = posicion; i < cadena.size(); i++)
			cadena[i] = cadena[i + 1];
							
		cadena.pop_back();
	}
}

void Frase::MoverPalabraFinal(int numero_palabra){
	int posicion = LocalizarPalabra(numero_palabra);
	int contador = posicion;
	
	/*
		Algoritmo:
		
		Se localiza la posicion de la palabra a borrar.
		
		Mientras que el elemento que se encuentra en "contador"
		no sea un espacio en blanco:
			Se aniade el elemento de la posicion "contador" al final
			de la cadena de caracteres.
			
			Se aumenta "contador" en 1.
				
		Se borra la palabra elegida en la frase inicial.
	*/
	
	while(cadena[contador] != ' '){				
		cadena.push_back(cadena[contador]);
		contador++;
	}
	
	BorrarPalabra(numero_palabra);
}
