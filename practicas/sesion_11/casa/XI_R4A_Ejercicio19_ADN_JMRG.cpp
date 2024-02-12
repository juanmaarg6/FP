/*
	Ejercicio 19: Programa que, a partir de una base de datos
				     y una secuencia de ADN especifica, indica
					  si dicha secuencia esta registrada en la base
					  de datos y, en caso afirmativo, cual es el nombre
					  de la especie. 
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>
#include <string>

using namespace std;

const int LONGITUD_MAXIMA = 1000;

/*
	Estructura para definir a la especie de un animal.
*/
struct Especie{
		string nombre; // Nombre de la especie
		string adn;    // Secuencia de adn de la especie
};

/*
	Funcion que muestra las especies de la BBDD y, si el usuario quiere,
	añade mas especies.
	
	Parametros: base_de_datos[LONGITUD_MAXIMA] (Especie), longitud (int).
	
	Devuelve: -
*/
void EspeciesBBDD(Especie base_de_datos[LONGITUD_MAXIMA], int &longitud);

/*
	Funcion que comprueba si la secuencia de ADN introducida por el usuario
	esta registrada en la BBDD
	
	Parametros: adn (string), secuencia (string).
	
	Devuelve: respuesta (bool).
*/
bool CompararSecuenciaADN(string adn, string secuencia);

int main(){
	Especie mosca = {"Mosca del vinagre", "ATAATGGACAAT"};
	Especie lombriz = {"Lombriz de tierra", "GGATACT"};
	Especie ameba = {"Ameba verde", "AGAGAT"};
	
	Especie base_de_datos[LONGITUD_MAXIMA] = {mosca, lombriz, ameba};	
	int longitud = 3;	
	
	string secuencia;
	string especieEncontrada;
	
	bool encontrado = false;
	
	/*
		Algoritmo:
		
			Mostrar la BBDD.
			
			Introducir una secuencia de ADN a buscar en la BBDD.
			
			Si la secuencia de ADN se encuentra en la BBDD, entonces
			mostrar en pantalla que ha sido encontrada.
			Si no, mostrar en pantalla que no ha sido encontrada.			
	*/
	
	EspeciesBBDD(base_de_datos, longitud);
	
	cout << "\n Introduzca la secuencia de ADN que desea buscar: ";
	cin >> secuencia;
	
	for(int i = 0; i < longitud && encontrado == false; i++){
		encontrado = CompararSecuenciaADN(base_de_datos[i].adn, secuencia);
		if(encontrado)
			especieEncontrada = base_de_datos[i].nombre;
	}
	
	if(encontrado){
		cout << "\n La secuencia de ADN ha sido encontrada en la base de datos";
		cout << "\n Dicha secuencia corresponde a: " << especieEncontrada << endl << endl;
	}
	else
		cout << "\n La secuencia de ADN no ha sido encontrada en la base de datos" << endl << endl; 
		
	system("pause");
}

void EspeciesBBDD(Especie base_de_datos[LONGITUD_MAXIMA], int &longitud){
	
	char respuesta;
	
	/*
		Algoritmo:
		
			Mostrar las especies registradas en la BBDD.
			
			Preguntar al usuario si desea registrar otra especie.
				Si la respuesta es si, entonces el usuario introduce el nombre
				de la nueva especie y su secuencia de ADN. Ademas, se vuelve a
				preguntar al usuario si desea registrar otra especie mas.
				Si la respuesta es no, entonces la BBDD no se modifica.
				
			Mostrar el contenido final de la BBDD.
	*/
	
	cout << " Especies registradas en la base de datos actualmente: " << longitud << "\n\n";
	for(int i = 0; i < longitud; i++)
		cout << " " << i + 1 << ") " << base_de_datos[i].nombre << "\n";
	
	cout << "\n ¿Desea registrar otra especie? [Si (S) / No (N)]: ";
	cin >> respuesta;
		
	while(respuesta == 'S' || respuesta == 's'){
		longitud++;
		
		cout << "\n Introduzca el nombre de la nueva especie: ";
		cin.ignore();
		getline(cin, base_de_datos[longitud - 1].nombre);
		
		cout << " Introduzca la secuencia de ADN de la nueva especie: ";
		cin >> base_de_datos[longitud - 1].adn;
		
		cout << "\n ¿Desea registrar otra especie? [Si (S) / No (N)]: ";
		cin >> respuesta;
	}
	
	cout << "\n Especies registradas en la base de datos finalmente: " << longitud << "\n\n";
	for(int i = 0; i < longitud; i++)
		cout << " " << i + 1 << ") " << base_de_datos[i].nombre << "\n";
}

bool CompararSecuenciaADN(string adn, string secuencia){
	
	bool encontrada = false;
	int longitud_adn, longitud_secuencia;
	int contador_izquierda;
	string nueva_secuencia;
	
	/*
		Algoritmo:
		
			Calcular las longitudes de la secuencia de ADN introducida
			por el usuario y de la secuencia de ADN de la BBDD.
			
			Si ambas longitudes son iguales, entonces se reordena la
			secuencia de ADN introducida por el usuario, de forma que
			,aunque la secuencia inicial introducida por el usuario
			comience en un punto distinto respecto a la secuencia
			almacenada en la BBDD, ambas secuencias pertenecen a la
			misma especie. 
				Si la nueva secuencia corresponde con la secuencia de ADN
				de la BBDD, entonces "encontrada = true".
	*/
	
	longitud_adn = adn.length();
	longitud_secuencia = secuencia.length();
	
	if(longitud_adn == longitud_secuencia){
		
		for(int i = 0; i < longitud_adn && encontrada == false; i++){
			contador_izquierda = i;
			nueva_secuencia = "";
			
			for(int k = contador_izquierda; k < longitud_adn; k++)
				nueva_secuencia += secuencia[k];
			
			for(int j = 0; j < contador_izquierda; j++)
				nueva_secuencia += secuencia[j];
			
			if(nueva_secuencia == adn)
				encontrada = true;
		}
	}
	
	return encontrada;	
}
