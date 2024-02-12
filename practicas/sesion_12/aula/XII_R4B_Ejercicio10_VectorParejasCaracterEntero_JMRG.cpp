/*
	Ejercicio 10: Programa que, dada una cadena de caracteres
					  y una pareja caracter-entero, borra de la cadena de caracteres
					  cada caracter que aparece en la pareja caracter-entero,
					  tantas veces como indique el numero entero correspondiente
					  de dicha pareja.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>
#include <vector>

using namespace std;

/*
	Estructura que representa una pareja caracter-entero.
*/
struct ParejaCaracterEntero{
	char caracter;
	int numero;
};

/*
	Clase en la que cada objeto de ella representa un
	vector pareja caracter-entero.
*/
class VectorParejasCaracterEntero{
	private:
		vector<ParejaCaracterEntero> elementos; // Vector pareja caracter-entero
	public:
		/*
			Constructor por defecto.
			
			Parametros: -
			
			Devuelve: -
		*/	
		VectorParejasCaracterEntero();
		
		/*
			Constructor de la clase.
			
			Parametros: frase (vector<char>).
			
			Devuelve: -
		*/	
		VectorParejasCaracterEntero(vector<ParejaCaracterEntero> parejas);
		
		/*
			Funcion que obtiene la longitud de la cadena de caracteres.
			
			Parametros: -
			
			Devuelve: longitud (int).
		*/	
		int ObtenerLongitud();
		
		/*
			Funcion que obtiene el caracter de la pareja caracter-entero.
			
			Parametros: posicion (int).
			
			Devuelve: caracter (char).
		*/	
		char ObtenerCaracter(int posicion);
		
		/*
			Funcion que obtiene el numero entero de la pareja caracter-entero.
			
			Parametros: posicion (int).
			
			Devuelve: veces (int).
		*/			
		int ObtenerVeces(int posicion);
		
		/*
			Funcion que lee la pareja caracter-entero.
			
			Parametros: -
			
			Devuelve: -
		*/		
		void IntroducirPareja();
		
		/*
			Funcion que muestra la pareja caracter-entero.
			
			Parametros: -
			
			Devuelve: -
		*/				
		void MostrarPareja();
};

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
		Frase();
		/*
			Constructor de la clase.
			
			Parametros: frase (vector<char>)
			
			Devuelve: -
		*/			
		Frase(vector<char> frase);
		
		/*
			Funcion que lee la frase.
			
			Parametros: -
			
			Devuelve: -
		*/	
		void LeerFrase();
		
		/*
			Funcion que muestra la frase.
			
			Parametros: -
			
			Devuelve: -
		*/	
		void MostrarFrase();
		
		/*
			Funcion que elimina una letra frase.
			
			Parametros: posicion (int).
			
			Devuelve: -
		*/	
		void EliminarLetra(int posicion);

		/*
			Funcion que borra una letra de la frase tantas veces
			como indique el numero entero de la pareja caracter-entero.
			
			Parametros: parejas (VectorParejasCaracterEntero).
			
			Devuelve: -
		*/		
		void Borrar(VectorParejasCaracterEntero parejas);
		
};

int main(){
	Frase frase;
	VectorParejasCaracterEntero parejas;
	
	/*
		Algoritmo:
		
		El usuario introduce una frase y esta se muestra.
		
		El usuario introduce las parejas caracter-entero.
		
		Se borran los caracteres de la frase en funcion de
		las parejas caracter-entero.
		
		Se muestra la frase final.				
	*/
	
	frase.LeerFrase();
	frase.MostrarFrase();
	
	cout << "\n\n\t NOTA: Se diferencia minusculas de mayusculas";
	parejas.IntroducirPareja();
	parejas.MostrarPareja();
	
	frase.Borrar(parejas);
	
	frase.MostrarFrase();
	
	cout << endl << endl;
	system("pause");
}

VectorParejasCaracterEntero::VectorParejasCaracterEntero(){
}

VectorParejasCaracterEntero::VectorParejasCaracterEntero(vector<ParejaCaracterEntero> parejas){
	elementos = parejas;
}

int VectorParejasCaracterEntero::ObtenerLongitud(){
	int longitud = elementos.size();		
	return longitud;
}

char VectorParejasCaracterEntero::ObtenerCaracter(int posicion){
	char caracter = elementos[posicion].caracter;			
	return caracter;
}

int VectorParejasCaracterEntero::ObtenerVeces(int posicion){
	int veces = elementos[posicion].numero;
	return veces;
}

void VectorParejasCaracterEntero::IntroducirPareja(){
	char respuesta, continuar;
	int veces;
	ParejaCaracterEntero pareja;
	
	/*
		Algoritmo:
		
		Mientras el usuario decida introducir una pareja caracter-entero:
		
			El usuario introduce una pareja caracter-entero.
			
			Esta pareja se aniade al final del vector "elementos".
			
			Se le pregunta al usuario si desea introducir otra pareja caracter-entero:
				Si introduce 'S' o 's', la respuesta es si, por lo que vuelve a introducir 
				otra pareja caracter-entero.
				Si introduce cualquier otro caracter, la respuesta es no.
	*/
	
	do{
		
		cout << "\n\n\t Introduzca el caracter que desea eliminar: ";
		cin >> respuesta;
		cout << "\t Introduzca el numero de veces que desea eliminarlo: ";
		cin >> veces;
		
		pareja.caracter = respuesta;
		pareja.numero = veces;
		
		elementos.push_back(pareja);
		
		cout << "\n\t ¿Desea introducir otra pareja (Si = 'S'//'s' | No = Cualquier otro caracter): ";
		cin >> continuar;			
	}while(continuar == 'S' || continuar == 's');
}

void VectorParejasCaracterEntero::MostrarPareja(){
	
	cout << "\n\n\n Parejas: [";
	cout << "(" << elementos[0].caracter << "," << elementos[0].numero << ")";
	
	for(int i = 1; i < elementos.size() - 1; i++)
		cout << ",(" << elementos[i].caracter << "," << elementos[i].numero << ")";
	
	if(elementos.size() > 1)
		cout << ",(" << elementos[elementos.size() - 1].caracter << "," << elementos[elementos.size() - 1].numero << ")";
	cout << "]";
}

Frase::Frase(){
}

Frase::Frase(vector<char> frase){
	cadena = frase;
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

void Frase::MostrarFrase(){
	
	/*
		Algoritmo:
		
		Se muestra la frase.
	*/
	
	cout << "\n\n Frase final: ";
	for(int i = 0; i < cadena.size(); i++)
		cout << cadena[i];
}

void Frase::EliminarLetra(int posicion){
	for(int i = posicion; i < cadena.size(); i++)
		cadena[i] = cadena[i + 1];				
		
	cadena.pop_back();
}

void Frase::Borrar(VectorParejasCaracterEntero parejas){
	int contador = 0;
	
	for(int i = 0; i < parejas.ObtenerLongitud(); i++){
		for (int j = 0; j < cadena.size() && contador < parejas.ObtenerVeces(i); j++)
			if(cadena[j] == parejas.ObtenerCaracter(i)){
				EliminarLetra(j);
				contador++;
			}
		contador = 0;
	}
}
