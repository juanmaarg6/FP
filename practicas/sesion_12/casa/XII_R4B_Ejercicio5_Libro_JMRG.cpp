/*
	Ejercicio 5: Programa que asigna un libro, muestra sus
	             campos por pantalla (autor, titulo, editorial
					 y anio), devuelve cada campo y compara dos libros.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/*
	Clase en la que cada objeto de ella representa un
	libro.
*/
class Libro{
	private:
		string autor; // Autor del libro
		string titulo; // Titulo del libro
		string editorial; // Editorial del libro
		string anio; // Anio de publicacion del libro
	public:
		/*
			Constructor por defecto.
			
			Parametros: -
			
			Devuelve: -
		*/	
		Libro();

		/*
			Funcion que establece el autor del libro.
			
			Parametros: _autor (string).
			
			Devuelve: -
		*/	
		void EstablecerAutor(string _autor);

		/*
			Funcion que establece el titulo del libro.
			
			Parametros: _titulo (string).
			
			Devuelve: -
		*/	
		void EstablecerTitulo(string _titulo);

		/*
			Funcion que establece la editorial del libro.
			
			Parametros: _editorial (string).
			
			Devuelve: -
		*/	
		void EstablecerEditorial(string _editorial);
		
		/*
			Funcion que establece el anio de publicacion del libro.
			
			Parametros: _anio (string).
			
			Devuelve: -
		*/	
		void EstablecerAnio(string _anio);

		/*
			Funcion que muestra todos los campos que caracterizan al
			libro (autor, titulo, editorial y anio).
			
			Parametros: -
			
			Devuelve: -
		*/	
		void MostrarDatos();

		/*
			Funcion que muestra uno de los campos que caracterizan al
			libro (autor, titulo, editorial o anio).
			
			Parametros: -
			
			Devuelve: -
		*/	
		void MostrarCampo();
		
		/*
			Funcion que compara dos libros
			
			Parametros: libro2 (Libro).
			
			Devuelve: -
		*/	
		void CompararLibros(Libro libro2);
};

/*
	Funcion que lee los campos que caracterizan al libro
	(autor, titulo, editorial y anio).
	
	Parametros: libro (Libro).
	
	Devuelve: -
*/	
void LeerDatos(Libro &libro);

int main(){
	Libro libro1, libro2;
	
	/*
		Algoritmo:
		
		Se introducen los campos de libro1 (autor, titulo, editorial y anio)
		y se muestran.
		
		Se introducen los campos de libro2 (autor, titulo, editorial y anio)
		y se muestran.
		
		El usuario elige un campo a mostrar de libro1 (autor, titulo, editorial o anio)
		y se muestra.
		
		El usuario elige un campo a mostrar de libro2 (autor, titulo, editorial o anio)
		y se muestra.
		
		Se comparan libro1 y libro2.
	*/
	
	cout << " Libro 1";
	LeerDatos(libro1);
	libro1.MostrarDatos();

	cout << "\n\n Libro 2";
	LeerDatos(libro2);
	libro2.MostrarDatos();
	
	cout << "\n\n Mostrar campo de Libro 1";	
	libro1.MostrarCampo();

	cout << "\n\n Mostrar campo de Libro 2";	
	libro2.MostrarCampo();

	cout << "\n\n Comparar Libro 1 y Libro 2";	
	libro1.CompararLibros(libro2);
	
	cout << endl << endl;
	system("pause");
}

void LeerDatos(Libro &libro){
	string autor, titulo, editorial, anio;
	
	/*
		Algoritmo:
		
		El usuario introduce el nombre del autor del libro y
		este se establece en el objeto libro.
		
		El usuario introduce el titulo del libro y
		este se establece en el objeto libro.
		
		El usuario introduce la editorial del libro y
		este se establece en el objeto libro.
		
		El usuario introduce el anio de publicacion del libro y
		este se establece en el objeto libro.
	*/
	
	cout << "\n\t Introduzca el nombre del autor: ";
	getline(cin, autor);
	libro.EstablecerAutor(autor);
	
	cout << "\t Introduzca el titulo del libro: ";
	getline(cin, titulo);
	libro.EstablecerTitulo(titulo);
	
	cout << "\t Introduzca el nombre de la editorial: ";
	getline(cin, editorial);
	libro.EstablecerEditorial(editorial);
	
	cout << "\t Introduzca el anio de publicacion: ";
	getline(cin, anio);
	libro.EstablecerAnio(anio);
}

Libro::Libro(){
	autor = "-";
	titulo = "-";
	editorial = "-";
	anio = "-";
}

void Libro::EstablecerAutor(string _autor){
	autor = _autor;
}

void Libro::EstablecerTitulo(string _titulo){
	titulo = _titulo;
}

void Libro::EstablecerEditorial(string _editorial){
	editorial = _editorial;
}

void Libro::EstablecerAnio(string _anio){
	anio = _anio;
}

void Libro::MostrarDatos(){
	
	/*
		Algoritmo:
		
		Se muestran todos los campos que caracterizan al objeto libro.
	*/
	
	cout << "\n\t Autor: " << autor;
	cout << "\n\t Titulo: " << titulo;
	cout << "\n\t Editorial: " << editorial;
	cout << "\n\t Anio: " << anio;
}

void Libro::MostrarCampo(){
	char opcion;
	
	/*
		Algoritmo:
		
		Se muestran los diferentes campos para que el usuario 
		elija uno y este se muestre.
		
		El usuario elige una opcion y esta se muestra.
	*/
	
	cout << "\n\n\t Campos a mostrar: ";
	cout << "\n\t\t A. Autor";
	cout << "\n\t\t B. Titulo";
	cout << "\n\t\t C. Editorial";
	cout << "\n\t\t D. Anio";
	
	cout << "\n\n\t Introduzca un campo a mostrar ('A'/'B'/'C'/'D'): ";
	cin >> opcion;
	
	opcion = toupper(opcion);
	
	if(opcion == 'A')
		cout << "\t\t Autor: " << autor;
	if(opcion == 'B')
		cout << "\t\t Titulo: " << titulo;
	if(opcion == 'C')
		cout << "\t\t Editorial: " << editorial;
	if(opcion == 'D')
		cout << "\t\t Anio: " << anio;
	if(opcion != 'A' && opcion != 'B' && opcion != 'C' && opcion != 'D')
		cout << "\t\t Campo no encontrado";
}
		
void Libro::CompararLibros(Libro libro2){
	bool mismo_autor, mismo_titulo, misma_editorial, mismo_anio;
	bool libros_iguales, libros_relacionados;
	
	/*
		Algoritmo:
		
		Los libros seran iguales si tienen el mismo autor, el mismo titulo,
		la misma editorial y el mismo anio de publicacion.
		
		Los libros estaran relacionados si tienen al menos uno de los cuatro campos
		(autor, titulo, editorial o anio) en comun.
		
		Se muestra si los libros son iguales, si estan relacionados o si no son iguales
		y tampoco tienen nada en comun.
	*/

	mismo_autor = autor == libro2.autor;
	mismo_titulo = titulo == libro2.titulo;
	misma_editorial = editorial == libro2.editorial;
	mismo_anio = anio == libro2.anio;
	
	libros_iguales = mismo_autor && mismo_titulo && misma_editorial && mismo_anio;
	libros_relacionados = (mismo_autor && !mismo_titulo && !misma_editorial && !mismo_anio)
								 || (!mismo_autor && mismo_titulo && !misma_editorial && !mismo_anio)
								 || (!mismo_autor && !mismo_titulo && misma_editorial && !mismo_anio)
								 || (!mismo_autor && !mismo_titulo && !misma_editorial && mismo_anio);
	
	if(libros_iguales)
		cout << "\n\n\t Los libros son iguales";
	else if(libros_relacionados)
		cout << "\n\n\t Los libros tienen algun/os campo/s en comun"; 
	else
		cout << "\n\n\t Los libros ni son iguales ni tienen nada en comun";
}
