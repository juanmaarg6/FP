/*
	Ejercicio 3: Programa que es capaz de asignar un valor a un
	             numero complejo, obtener su parte real y su parte
					 imaginaria y sumar, restar o multiplicar dos
					 numeros complejos.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/
#include <iostream>

using namespace std;

const char COMPLEJO = 'i';

/*
	Clase en la que cada objeto de ella representa un
	numero complejo de la forma "a + bi".
*/
class Complejos{
	private:
		double coeficiente_a; // Coeficiente a del numero complejo
		double coeficiente_b; // Coeficiente b del numero complejo
	public:
		/*
			Constructor por defecto.
			
			Parametros: -
			
			Devuelve: -
		*/		
		Complejos();
		
		/*
			Constructor de la clase.
			
			Parametros: parte_real (double), parte_imaginaria (double).
			
			Devuelve: -
		*/	
		Complejos(double parte_real, double parte_imaginaria);
		
		/*
			Funcion que establece la parte real del numero complejo.
			
			Parametros: parte_real (double).
			
			Devuelve: -
		*/	
		void EstablecerParteReal(double parte_real);
		
		/*
			Funcion que establece la parte imaginaria del numero complejo.
			
			Parametros: parte_imaginaria (double).
			
			Devuelve: -
		*/	
		void EstablecerParteImaginaria(double parte_imaginaria);
		
		/*
			Funcion que muestra el numero complejo.
			
			Parametros: -
			
			Devuelve: -
		*/	
		void MostrarComplejo();
		
		/*
			Funcion que obtiene la parte real del numero complejo.
			
			Parametros: -
			
			Devuelve: -
		*/	
		void ObtenerParteReal();
		
		/*
			Funcion que obtiene la parte imaginaria del numero complejo.
			
			Parametros: -
			
			Devuelve: -
		*/	
		void ObtenerParteImaginaria();
		
		/*
			Funcion que suma dos numeros complejos.
			
			Parametros: complejo2 (Complejo).
			
			Devuelve: complejo_suma (Complejo).
		*/	
   	Complejos Sumar(Complejos &complejo2);
		
		/*
			Funcion que resta dos numeros complejos.
			
			Parametros: complejo2 (Complejo).
			
			Devuelve: complejo_resta (Complejo).
		*/			
		Complejos Restar(Complejos &complejo2);
		
		/*
			Funcion que multiplica dos numeros complejos.
			
			Parametros: complejo2 (Complejo).
			
			Devuelve: complejo_multiplicacion (Complejo).
		*/			
		Complejos Multiplicar(Complejos &complejo2);
};

		
/*
	Funcion que lee los coeficientes de un numero complejo.
	
	Parametros: -
	
	Devuelve: -
*/	
void LeerComplejo(Complejos &complejo){
	double parte_real, parte_imaginaria;
	
	cout << "\n\n\t Introduzca la parte real del numero complejo: ";
	cin >> parte_real;
	complejo.EstablecerParteReal(parte_real);
	
	cout << "\t Introduzca la parte imaginaria del numero complejo (sin la 'i'): ";
	cin >> parte_imaginaria;
	complejo.EstablecerParteImaginaria(parte_imaginaria);
}

int main(){
	Complejos complejo1, complejo2;
	Complejos complejo_suma, complejo_resta, complejo_multiplicacion;
	
	/*
		Algoritmo:
		
		Se lee complejo1 y se muestra.
		Se muestra la parte real e imaginaria de complejo1.
		
		Se lee complejo2 y se muestra.
		Se muestra la parte real e imaginaria de complejo2.
		
		Se suman complejo1 y complejo2 y se muestra el resultado.
		Se restan complejo1 y complejo2 y se muestra el resultado.
		Se multiplican complejo1 y complejo2 y se muestra el resultado.
	*/
	cout << " Complejo 1";
	LeerComplejo(complejo1);
	
	complejo1.MostrarComplejo();

	complejo1.ObtenerParteReal();

	complejo1.ObtenerParteImaginaria();

	
	cout << "\n\n Complejo 2";
	LeerComplejo(complejo2);
	
	complejo2.MostrarComplejo();
	
	complejo2.ObtenerParteReal();

	complejo2.ObtenerParteImaginaria();
	
	cout << "\n\n Suma Complejo 1 y Complejo 2 \n";
	complejo_suma = complejo1.Sumar(complejo2);
	complejo_suma.MostrarComplejo();
	
	cout << "\n Resta Complejo 1 y Complejo 2 \n";
	complejo_resta = complejo1.Restar(complejo2);
	complejo_resta.MostrarComplejo();
	
	cout << "\n Multiplicacion Complejo 1 y Complejo 2 \n";
	complejo_multiplicacion = complejo1.Multiplicar(complejo2);
	complejo_multiplicacion.MostrarComplejo();
	
	cout << endl << endl;
	system("pause");
}

Complejos::Complejos(){
	coeficiente_a = 0;
	coeficiente_b = 1;
}

Complejos::Complejos(double parte_real, double parte_imaginaria){
	coeficiente_a = parte_real;
	coeficiente_b = parte_imaginaria;
}

void Complejos::EstablecerParteReal(double parte_real){
	coeficiente_a = parte_real;
}

void Complejos::EstablecerParteImaginaria(double parte_imaginaria){
	coeficiente_b = parte_imaginaria;
}

void Complejos::MostrarComplejo(){
	if(coeficiente_b < 0)
		cout << "\n\t " << coeficiente_a << " " << coeficiente_b << COMPLEJO << "\n";
	else
		cout << "\n\t " << coeficiente_a << " + " << coeficiente_b << COMPLEJO << "\n";
}

void Complejos::ObtenerParteReal(){
	cout << "\n\t Parte Real: " << coeficiente_a;
}


void Complejos::ObtenerParteImaginaria(){
	cout << "\n\t Parte Imaginaria: " << coeficiente_b << COMPLEJO;
}

Complejos Complejos::Sumar(Complejos &complejo2){
	Complejos complejo_suma;
  
	complejo_suma.coeficiente_a = coeficiente_a + complejo2.coeficiente_a;
	complejo_suma.coeficiente_b = coeficiente_b + complejo2.coeficiente_b;
  
	return complejo_suma;
}

Complejos Complejos::Restar(Complejos &complejo2){
	Complejos complejo_resta;
  
	complejo_resta.coeficiente_a = coeficiente_a - complejo2.coeficiente_a;
	complejo_resta.coeficiente_b = coeficiente_b - complejo2.coeficiente_b;
  
	return complejo_resta;
}

Complejos Complejos::Multiplicar(Complejos &complejo2){
	Complejos complejo_multiplicacion;
  
	complejo_multiplicacion.coeficiente_a = (coeficiente_a * complejo2.coeficiente_a) - (coeficiente_b * complejo2.coeficiente_b);
	complejo_multiplicacion.coeficiente_b = (coeficiente_a * complejo2.coeficiente_b) + (coeficiente_b * complejo2.coeficiente_a);
  
	return complejo_multiplicacion;
}
