/*
	Relación de ejercicios 2

	Ejercicio 18: Programa que realiza la conversión entre dos unidades
	              de distancia.
	
	Entradas: Valor de la distancia inicial (valor),
	          Unidad de la distancia inicial (unidad_inicial),
	          Carácter 'a' (caracter_a),
	          Unidad de la distancia final (unidad_final).
	Salidas: Valor de la distancia final (conversion).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusión de los recursos de E/S
#include <iomanip>			// Inclusión de los recursos de modificación de E/S
#include <cmath>			// Inclusión de los recursos matemáticos

using namespace std;

// Programa principal

int main() {
	
	cout.setf (ios::fixed);
	cout.setf (ios::showpoint);
	
	// Declaración de constantes
	
	const int EXPONENTE_KM = 3;		// 1 km = 10^3 m
	const int EXPONENTE_M = 0;		// 1 m = 10^0 m
	const int EXPONENTE_CM = -2;	// 1 cm = 10^(-2) m
	const int EXPONENTE_MM = -3;	// 1 mm = 10^(-3) m

	// Declaración de variables
	
	double valor = 0.0;
	string unidad_inicial, unidad_final;
	char caracter_a;
	
	// Entradas de datos
	
	cout << " Introduzca una conversion entre dos unidades de distancia de"
	     << " la siguiente forma: " << endl << endl;
	cout << "\t 'valor' 'unidad_inicial' 'a' 'unidad_final'" << endl << endl;
	cout << " donde 'unidad_inicial' y 'unidad_final' solo pueden" 
	     << " ser iguales a: ";
	cout << endl << endl << "\t 1) 'mm' (milimetros)";
	cout << endl << "\t 2) 'cm' (centimetros)";
	cout << endl << "\t 3) 'm' (metros)";
	cout << endl << "\t 4) 'km' (kilometros)" << endl << endl;	
	
	cout << " > ";
	cin >> valor;
	cin >> unidad_inicial;
	cin >> caracter_a;
	cin >> unidad_final;
	
	// Cálculos
	
	/*
		Algoritmo:
		
		Comprobar si los datos introducidos son correctos.
		
		Si los datos son correctos:
		
			Calcular la conversión del valor dependiendo de la unidad inicial
			y final de distancia.
			
		Si no, mostrar mensaje de error.
	*/
	
	bool valor_correcto = (valor >= 0);
	bool unidad_inicial_correcta = ( (unidad_inicial == "mm") 
									 || (unidad_inicial == "cm") 
									 || (unidad_inicial == "m") 
									 || (unidad_inicial == "km") );
	bool caracter_a_correcto = (caracter_a == 'a');
	bool unidad_final_correcta = ( (unidad_final == "mm") 
									 || (unidad_final == "cm") 
									 || (unidad_final == "m") 
									 || (unidad_final == "km") );
									 
	bool datos_correctos = valor_correcto && unidad_inicial_correcta
	                       && caracter_a_correcto && unidad_final_correcta;
	
	if(datos_correctos) {
		
		double conversion = 0.0;
		int exp_unidad_inicial = 0, exp_unidad_final = 0;
		
		if(unidad_inicial == "km")
			exp_unidad_inicial = EXPONENTE_KM;
		
		if(unidad_inicial == "m")
			exp_unidad_inicial = EXPONENTE_M;
			
		if(unidad_inicial == "cm")
			exp_unidad_inicial = EXPONENTE_CM;			
			
		if(unidad_inicial == "mm")
			exp_unidad_inicial = EXPONENTE_MM;
			
		if(unidad_final == "km")
			exp_unidad_final = EXPONENTE_KM;
		
		if(unidad_final == "m")
			exp_unidad_final = EXPONENTE_M;
			
		if(unidad_final == "cm")
			exp_unidad_final = EXPONENTE_CM;			
			
		if(unidad_final == "mm")
			exp_unidad_final = EXPONENTE_MM;
			
		conversion = valor * pow(10, (exp_unidad_inicial - exp_unidad_final));
			
		// Salidas
		
		cout << endl << " " << setprecision(6) << valor << " "
		     << unidad_inicial << " = " << setprecision(6) << conversion 
			 << " " << unidad_final << endl << endl;
	}
	else {
		
		// Mensaje de error
		
		cout << endl << " Error: La entrada de datos es incorrecta.";
		cout << endl << "        Recuerde: 'valor' 'unidad_inicial' 'a'"
		     << " 'unidad_final'" << endl;
	    cout << "\tdonde 'unidad_inicial' y 'unidad_final' solo pueden" 
	         << " ser iguales a: ";
	    cout << endl << endl << "\t\t 1) 'mm' (milimetros)";
		cout << endl << "\t\t 2) 'cm' (centimetros)";
		cout << endl << "\t\t 3) 'm' (metros)";
		cout << endl << "\t\t 4) 'km' (kilometros)" << endl << endl;
	}
	
	return 0;	
}
