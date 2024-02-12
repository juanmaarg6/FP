/*
	Ejercicio 1a): Programa que, dadas dos rectas,
						muestra la pendiente de ambas.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
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
};

int main(){
	Recta recta1, recta2;
	double pendiente1, pendiente2;
	
	/*
		Algoritmo:
		
		El usuario introduce los tres coeficientes que definen a 
		la recta 1 y los tres coeficientes que definen a la recta 2.
		
		Se muestran ambas rectas.
		
		Se calcula la pendiente de cada recta de la siguiente forma:
											
											coeficiente_a
						Pendiente = - ---------------
											coeficiente_b
											
		Se muestran ambas pendientes.
	*/
	
	cout << " Introduzca el coeficiente A de la recta 1: ";
	cin >> recta1.coeficiente_a;
	cout << " Introduzca el coeficiente B de la recta 1: ";
	cin >> recta1.coeficiente_b;
	
	if(recta1.coeficiente_b == 0){
		cout << "\n\n Error. El coeficiente B no puede ser 0." << endl << endl;
		exit(-1);
	}
	
	cout << " Introduzca el coeficiente C de la recta 1: ";
	cin >> recta1.coeficiente_c;
	
	cout << "\n Introduzca el coeficiente A de la recta 2: ";
	cin >> recta2.coeficiente_a;
	cout << " Introduzca el coeficiente B de la recta 2: ";
	cin >> recta2.coeficiente_b;
	
	if(recta2.coeficiente_b == 0){
		cout << "\n\n Error. El coeficiente B no puede ser 0." << endl << endl;
		exit(-1);
	}
	
	cout << " Introduzca el coeficiente C de la recta 2: ";
	cin >> recta2.coeficiente_c;
	
	cout << "\n Recta 1: " << recta1.coeficiente_a << "x + " << recta1.coeficiente_b << "y + " << recta1.coeficiente_c << " = 0";
	cout << "\n Recta 2: " << recta2.coeficiente_a << "x + " << recta2.coeficiente_b << "y + " << recta2.coeficiente_c << " = 0";
	
	pendiente1 = (-1) * (recta1.coeficiente_a / recta1.coeficiente_b); 
	pendiente2 = (-1) * (recta2.coeficiente_a / recta2.coeficiente_b); 
	
	cout << "\n\n Pendiente de la recta 1: " << pendiente1;
	cout << "\n Pendiente de la recta 2: " << pendiente2 << endl << endl;
	
	system("pause");
}
