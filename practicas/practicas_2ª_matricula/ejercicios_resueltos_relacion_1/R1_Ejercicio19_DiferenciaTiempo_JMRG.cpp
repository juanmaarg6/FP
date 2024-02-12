/*
	Relaci�n de ejercicios 1

	Ejercicio 19: Programa que, dados dos instantes de tiempo de un mismo d�a,
	              calcula el n�mero de segundos que hay entre los dos 
				  instantes. 
	
	Entradas: Hora del instante inicial (h_inicial),
			  Minuto del instante inicial (min_inicial),
			  Segundo del instante inicial (seg_inicial),
			  Hora del instante final (h_final),
			  Minuto del instante final (min_final),
		      Segundo del instante final (seg_final).
	Salidas: N�mero de segundos entre los dos instantes (total_seg).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/


#include <iostream>			// Inclusi�n de librer�a de recursos de E/S

using namespace std;

// Programa principal

int main() {
	
	// Declaraci�n de variables
	
	int h_inicial = 0, min_inicial = 0, seg_inicial = 0;							
	int h_final = 0, min_final = 0, seg_final = 0;
	int seg_instante_ini = 0, seg_instante_fin = 0;							
	int total_seg = 0;	
							
	// Entradas de datos
	
	cout << " Instante inicial: " << endl << endl;
	cout << "\t Hora: ";									
	cin >> h_inicial;
	cout << endl << "\t Minuto: ";									
	cin >> min_inicial;
	cout << endl << "\t Segundo: ";									
	cin >> seg_inicial;
	
	cout << endl << endl << " Instante final: " << endl << endl;
	cout << "\t Hora: ";									
	cin >> h_final;
	cout << endl << "\t Minuto: ";									
	cin >> min_final;
	cout << endl << "\t Segundo: ";									
	cin >> seg_final;
	
	// C�lculos 
	
	seg_instante_ini = (h_inicial * 3600) + (min_inicial * 60) + seg_inicial;
	seg_instante_fin = (h_final * 3600) + (min_final * 60) + seg_final;

	total_seg = seg_instante_fin - seg_instante_ini;
			 
	// Salidas
	
	cout << endl << " Hay un total de " << total_seg 
	     << " entre los dos instantes dados" << endl << endl;	
		 
	system("pause");
	return 0;
}
