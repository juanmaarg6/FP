/*
	Ejercicio 16: Programa que, dados los identificadores y las fechas de
	              un conjunto de libros, muestra dichos identificadores con sus
					  respectivas fechas en orden de mayor a menor fecha (a igualdad de fechas
					  se ordenan de menor a mayor identificador).
					   	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

/*
	Clase en la que cada objeto de ella representa el identificador de un libro.
*/
class Identificador{
	private:
		string cadena;
		
	public:
		void SetIdentificador(string nueva_cadena);

		string GetIdentificador();
				
		bool EsIgual_a(Identificador cadena2);
		
		bool EsMenor_que(Identificador cadena2);
};

/*
	Clase en la que cada objeto de ella representa la fecha de un libro.
*/
class Fecha{
	private:
		int dia;
		int mes;
		int anio;
		
	public:
		void SetDiaMesAnio(int _dia, int _mes, int _anio);
		
		int GetDia();
		
		int GetMes();
		
		int GetAnio();
		
		void MostrarFecha();
		
		bool EsIgual_a(Fecha fecha2);
		
		bool EsMenor_que(Fecha fecha2);
};

/*
	Clase en la que cada objeto de ella representa un libro.
*/
class Libro{
	private:
		Identificador identificador;
		Fecha fecha;
	public:
		void SetLibro(Identificador _identificador, Fecha _fecha);

		void MostrarIdentificador();
		
		void MostrarFecha();
		
		bool EsIgual_a(Libro libro2);
		
		bool EsMenor_que(Libro libro2);

};

/*
	Clase en la que cada objeto de ella representa una biblioteca.
*/
class Biblioteca{
	private:
		Libro libros[100];
		int elementos;
	public:
		Biblioteca();
		
		int GetNumeroElementos();
		
		void AniadirLibro(Libro nuevo_libro, int posicion);
		
		void MostrarLibro(int posicion);
		
		void Ordenar();
};

/*
	Clase que lee los libros de la biblioteca
*/
class LectorBiblioteca{
	public: 
		Biblioteca biblioteca;
	public:
		void LeerDatos();
};

/*
	Clase que muestra los libros de la biblioteca
*/
class ImpresorBiblioteca{
	public: 
		Biblioteca biblioteca;
	public:
		void ImprimirDatos();
};		

/*
	Funcion principal
*/
int main(){
	LectorBiblioteca biblioteca1;
	ImpresorBiblioteca biblioteca2;

	biblioteca1.LeerDatos();
	
	biblioteca2.biblioteca = biblioteca1.biblioteca;
	
	cout << endl << endl << " Libros ordenados por fecha de mayor a menor:";
	biblioteca2.ImprimirDatos();
	
	cout << endl << endl;
	system("pause");
}

// *******************************************************************************************

void Identificador::SetIdentificador(string cadena_nueva){
	cadena = cadena_nueva;
}

string Identificador::GetIdentificador(){
	return cadena;
}
		
bool Identificador::EsIgual_a(Identificador cadena2){
	return (cadena.compare(cadena2.cadena) == 0);
}

bool Identificador::EsMenor_que(Identificador cadena2){
	return (cadena.compare(cadena2.cadena) < 0);
}

// *******************************************************************************************

void Fecha::SetDiaMesAnio(int _dia, int _mes, int _anio){
	dia = _dia;
	mes = _mes;
	anio = _anio;
}

int Fecha::GetDia(){
	return dia;
}

int Fecha::GetMes(){
	return mes;
}

int Fecha::GetAnio(){
	return anio;
}

void Fecha::MostrarFecha(){
	cout<< GetDia() << "/" << GetMes() << "/" << GetAnio();
}
		
bool Fecha::EsIgual_a(Fecha fecha2){
	if((dia == fecha2.dia) && (mes == fecha2.mes) && (anio == fecha2.anio)) 
		return true;
	else 
		return false;
}

bool Fecha::EsMenor_que(Fecha fecha2){
	if(anio < fecha2.anio) 
		return true;
	else if((anio = fecha2.anio) && (mes < fecha2.mes)) 
		return true;
	else if((anio = fecha2.anio) && (mes = fecha2.mes) && (dia < fecha2.dia)) 
		return true;
	else 
		return false;
}

// *******************************************************************************************

void Libro::SetLibro(Identificador _identificador, Fecha _fecha){
	identificador = _identificador;
	fecha = _fecha;
}

void Libro::MostrarIdentificador(){
	cout << identificador.GetIdentificador();
}

void Libro::MostrarFecha(){
	fecha.MostrarFecha();
}

bool Libro::EsIgual_a(Libro libro2){
	if((identificador.EsIgual_a(libro2.identificador) == true) && (fecha.EsIgual_a(libro2.fecha) == true)) 
		return true;
	else 
		return false;
}

bool Libro::EsMenor_que(Libro libro2){
	if(fecha.EsMenor_que(libro2.fecha) == true) 
		return true;
	else if((fecha.EsIgual_a(libro2.fecha) == true) && (identificador.EsMenor_que(libro2.identificador) == true)) 
		return true;
	else 
		return false;
}

// *******************************************************************************************

Biblioteca::Biblioteca(){
	elementos = 0;
}

int Biblioteca::GetNumeroElementos(){
	return elementos;
}
		
void Biblioteca::AniadirLibro(Libro nuevo_libro, int posicion){
	libros[posicion]= nuevo_libro;
	
	elementos++;
}

void Biblioteca::MostrarLibro(int posicion){
	libros[posicion].MostrarIdentificador();
	
	cout << ", ";
	
	libros[posicion].MostrarFecha();
	
	cout << endl;
}

void Biblioteca::Ordenar(){
	int i, izquierda;
	Libro auxiliar;
	
	for (izquierda = 0; izquierda < elementos; izquierda++)
		for(i = elementos - 1; i > izquierda; i--)
			if(libros[i].EsMenor_que(libros[i - 1]) == false){
				cout << i;
				auxiliar = libros[i];
				libros[i] = libros[i - 1];
				libros[i - 1]= auxiliar;
			}
}

// *******************************************************************************************

void LectorBiblioteca::LeerDatos(){
	string cadena;
	Identificador identificador;
	Fecha fecha;
	int dia, mes, anio;
	int i = 0;
	Libro nuevo_libro;

	cout << " Introduzca el identificador del libro ('FFFF' para terminar): ";
	cin >> cadena;
	identificador.SetIdentificador(cadena);
	
	do{
		cout << " Introduzca la fecha del libro (dia (espacio) mes (espacio) anio): ";
		cin >> dia >> mes >> anio;
		fecha.SetDiaMesAnio(dia, mes, anio);
			
		nuevo_libro.SetLibro(identificador, fecha);
		biblioteca.AniadirLibro(nuevo_libro, i);
		i++;
		
		cout << "\n Introduzca el identificador del libro ('FFFF' para terminar): ";
		cin >> cadena;
		identificador.SetIdentificador(cadena);		
	}while(identificador.GetIdentificador() != "FFFF");
	
	biblioteca.Ordenar();
}

// *******************************************************************************************

void ImpresorBiblioteca::ImprimirDatos(){	
	for(int i = 0; i < biblioteca.GetNumeroElementos(); i++){
		cout << endl << "\n Libro " << i << ":";
		biblioteca.MostrarLibro(i);
	}
}
