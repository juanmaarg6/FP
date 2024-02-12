/*
	Ejercicio 1b): Programa que, dadas dos rectas,
						un valor de abscisa x y un valor 
						de ordenada y, muestra la pendiente 
						de ambas, el valor de ordenada y segun
						el valor de abscisa x introducido y el
						valor de abscisa x segun el valor de
						ordenada introducido.
	
	C�digo fuente realizado por Juan Manuel Rodr�guez G�mez.
*/

#include <iostream>

using namespace std;

/*
	Clase en la que cada objeto de ella representa una
	recta en el plano de la forma:
		
			       	 Ax + By + C = 0
*/
class Recta{
	public:
		double coeficiente_a; // Coeficiente A de la recta.
		double coeficiente_b; // Coeficiente B de la recta.
		double coeficiente_c; // Coeficiente C de la recta.
		
		/*
			Funcion que calcula la pendiente de una recta.
			
			Parametros: -
			
			Devuelve: pendiente (double).
		*/
		double PendienteRecta();
		
		/*
			Funcion que calcula el valor de abscisa (x) que toma
			una recta para un valor de ordenada (y) introducido.
			
			Parametros: ordenada (double).
			
			Devuelve: abscisa (double).
		*/
		double ValorAbscisaX(double ordenada);
		
		/*
			Funcion que calcula el valor de ordenada (y) que toma
			una recta para un valor de abscisa (x) introducido.
			
			Parametros: abscisa (double).
			
			Devuelve: ordenada (double).
		*/
		double ValorOrdenadaY(double abscisa);
};

int main(){
	Recta recta;
	double ordenada, abscisa;
	
	/*
		Algoritmo:
		
		El usuario introduce los tres coeficientes que definen a 
		la recta.
		
		Se muestra la recta.
		
		Se calcula la pendiente de la recta de la siguiente forma:
											
											coeficiente_a
						Pendiente = - ---------------
											coeficiente_b
											
		Se muestra la pendiente.
		
		El usuario introduce un valor de ordenada (y) y se
		muestra el valor de abscisa (x) que toma la recta para
		dicho valor de ordenada.
		
		El usuario introduce un valor de abscisa (x) y se
		muestra el valor de ordenada (y) que toma la recta para
		dicho valor de abscisa.
	*/
	
	cout << " Introduzca el coeficiente A de la recta: ";
	cin >> recta.coeficiente_a;
	cout << " Introduzca el coeficiente B de la recta: ";
	cin >> recta.coeficiente_b;
	
	if(recta.coeficiente_b == 0){
		cout << "\n\n Error. El coeficiente B no puede ser 0." << endl << endl;
		exit(-1);
	}
	
	cout << " Introduzca el coeficiente C de la recta: ";
	cin >> recta.coeficiente_c;
	
	cout << "\n Recta: " << recta.coeficiente_a << "x + " << recta.coeficiente_b << "y + " << recta.coeficiente_c << " = 0";
		
	cout << "\n\n Pendiente de la recta: " << recta.PendienteRecta();
	
	cout << "\n\n Introduzca un valor de ordenada (y): ";
	cin >> ordenada;	
	cout << " Para y = " << ordenada << " la recta tiene como abscisa x = " << recta.ValorAbscisaX(ordenada);
	
	cout << "\n\n Introduzca un valor de abscisa (x): ";
	cin >> abscisa;	
	cout << " Para x = " << abscisa << " la recta tiene como ordenada y = " << recta.ValorOrdenadaY(abscisa) << endl << endl;
	
	system("pause");
}

double Recta::PendienteRecta(){
	double pendiente;

	pendiente = (-1) * (coeficiente_a / coeficiente_b);

	return pendiente;
}

double Recta::ValorAbscisaX(double ordenada){
	double abscisa;
	
	abscisa = (- coeficiente_c - ordenada * coeficiente_b) / coeficiente_a;
	
	return abscisa;
}

double Recta::ValorOrdenadaY(double abscisa){
	double ordenada;
	
	ordenada = (- coeficiente_c - abscisa * coeficiente_a) / coeficiente_b;
	
	return ordenada;
}
