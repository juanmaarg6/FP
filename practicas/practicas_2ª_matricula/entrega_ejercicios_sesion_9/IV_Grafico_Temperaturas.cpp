/*
	Relaci�n de ejercicios 4

	Ejercicio 39: Programa que muestra dos gr�ficos que resumen las 
	              temperaturas registradas diariamente:

					1) Las medias semanales de las m�nimas.
					2) Las medias semanales de las m�ximas.
	              
	Entradas: Temperaturas m�nimas y m�ximas semanales (minimas[], maximas[]).
	Salidas: Gr�fico que muestra las medias semanales de las temperaturas
	         m�nimas (tablero[][]),
	         Gr�fico que muestra las medias semanales de las temperaturas
	         m�ximas (tablero[][]).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/***************************************************************************/
// Funci�n principal
/***************************************************************************/
int main() {
	
	cout.setf (ios::fixed);
	cout.setf (ios::showpoint);	
	
	// N�m. de casillas para guardar las temperaturas diarias
	const int MAX_DIAS = 700; 	
	
	double minimas[MAX_DIAS]; // Temperaturas m�nimas	
	double maximas[MAX_DIAS]; // Temperaturas m�ximas	

	// N�m. de casillas para guardar las temperaturas medias semanales
	const int MAX_SEMANAS = 100; 	
	
	double medias_minimas [MAX_SEMANAS]; // Medias de las m�nimas semanales 
	double medias_maximas [MAX_SEMANAS]; // Medias de las m�ximas semanales 

	const int DIAS_SEMANA = 7; 	

	// Datos para la lectura
		
	string str_cabecera;
	
	string str_dia;
	string str_fecha;
	string str_temp_minima;
	string str_temp_maxima;
	
	int dia; 
	double minima;
	double maxima;
	
	// Lectura de la cabecera (no se procesa)
	/* La lectura se realiza con getline() porque se leen l�neas completas */
	
	getline(cin, str_cabecera); // Estaci�n meteorol�gica.
	getline(cin, str_cabecera); // A�o.
	getline(cin, str_cabecera); // Encabezados de las cuatro columnas. 
	
	// Lectura de datos
	/* Los datos se leen con >> porque estamos interesados en las palabas 
	   que componen las l�neas m�s que en la l�nea completa. Si se leyera 
	   la l�nea completa, despu�s habr�a que "aislar" las cuatro palabras 
	   que la componen, lo que supone una dificultad -innecesaria- a�adida */
	
	int cont_dias = 0; 
		
	cin >> str_dia;

	while(str_dia != "FIN") {
		
		cin >> str_fecha;
		cin >> str_temp_maxima;
		cin >> str_temp_minima;
		
		dia = stoi(str_dia);
		minima = stod(str_temp_minima);		
		maxima = stod(str_temp_maxima);
		
		minimas [cont_dias] = minima;
	 	maximas [cont_dias] = maxima;
	
		cont_dias++;
		
		cin >> str_dia;
	}
	
	cout << endl; 
	cout << "Se ha leido un total de " << setw(4) << cont_dias 
	     << " lineas de datos." << endl; 	
	
	if(cont_dias % 7 != 0) {
		cout << "Error: Los datos no corresponden a semanas completas" << endl; 		     
		exit (1);
	}

	int num_semanas = cont_dias / DIAS_SEMANA;
	cout << "Los datos corresponden a " << num_semanas << " semanas." << endl; 		     
	cout << endl; 
	
	// C�lculos de la m�nima anual (de las m�nimas) y la m�xima anual 
	// (de las m�ximas) 
	
	double minima_de_minimas_anual = minimas[0]; 
	double maxima_de_maximas_anual = maximas[0];
	
	for (int d = 1; d < cont_dias; d++) {
	
		if (minimas[d] < minima_de_minimas_anual) 
			minima_de_minimas_anual = minimas[d];
		if (maximas[d] > maxima_de_maximas_anual) 
			maxima_de_maximas_anual = maximas[d];
	}

	cout << endl; 
	cout << "Minima anual de las minimas = " << setw(6) << setprecision(2) 
	     << minima_de_minimas_anual << endl;  
	cout << "Maxima anual de las maximas = " << setw(6) << setprecision(2) 
	     << maxima_de_maximas_anual << endl;  
	cout << endl; 
			
			
	// C�lculo de las medias semanales (de las m�nimas y de las m�ximas)
			
	for (int semana = 0; semana < num_semanas; semana++) {
	
		double suma_minimas = 0;
		double suma_maximas = 0;
		
		for (int dia = 0; dia < DIAS_SEMANA; dia++) {

			suma_minimas += minimas[semana*DIAS_SEMANA + dia]; 
			suma_maximas += maximas[semana*DIAS_SEMANA + dia]; 
		}
		
		medias_minimas[semana] = suma_minimas/DIAS_SEMANA;
		medias_maximas[semana] = suma_maximas/DIAS_SEMANA;
	}
	
	cout << endl; 
	cout << "Temperaturas medias semanales: " << endl; 	
	cout << endl; 

	for(int semana = 0; semana < num_semanas; semana++) {
		
		cout << "Semana " << setw(3) << semana+1 
		     << " Media de minimas = " <<setw(6)<< setprecision(2) 
			 << medias_minimas[semana] 		
		     << " Media de maximas = " <<setw(6)<< setprecision(2) 
			 << medias_maximas[semana] << endl; 
	}
			

	/**********************************************************************/
	//								GR�FICAS							  //
	/**********************************************************************/			
	
	// Declaracion de variables
	
	const int NUM_FILAS = 20; 		// N�mero de filas del tablero
	const int NUM_COLS  = 60; 		// N�mero de columnas del tablero
	
	char tablero[NUM_FILAS][NUM_COLS];
	
	const char TRAZO = '*'; 		// Caracter del "trazo" (dibujo)
	const char HUECO = '.'; 		// Caracter del "hueco" (no dibujo)
	
	const double MIN_TEMP = -10.0;
	const double MAX_TEMP = 50.0;	
	const double SALTO_TEMP = 3.0;
		
	// Rellenamos todo el tablero con el car�cter 'HUECO'
	for(int i = 0; i < NUM_FILAS; i++)
		for(int j = 0; j < NUM_COLS; j++)
			tablero[i][j] = HUECO;
	
	// Medias de las m�nimas
	 	
	double intervalo;
	
	// Asignamos cada media de las temperaturas m�nimas
	// en la fila que le corresponda
	for(int j = 0; j < num_semanas; j++){
	
		int i = 0;
		
		for(intervalo = ( MIN_TEMP + SALTO_TEMP); intervalo < MAX_TEMP; 
		    intervalo += SALTO_TEMP) {
		
			if( ( medias_minimas[j] >= (intervalo - SALTO_TEMP) ) && 
			    ( medias_minimas[j] < intervalo ) ) {
			    	
				tablero[i][j] = TRAZO;
			}
				
			i++;
		}	
	}
	
	// Salida del gr�fico de las medias de las m�nimas
	
	cout << endl;
	cout << endl; 
	cout << "Medias de las minimas semanales: ";	
	cout << endl << endl;
	
	intervalo = MAX_TEMP;
		
	for(int i = NUM_FILAS-1; i >= 0; i--){
		
		intervalo -= SALTO_TEMP;
		
		cout << "[" << setw(6) << intervalo << "," << setw(6) 
			 << intervalo + SALTO_TEMP << ") ";
		
		for(int j = 0; j < NUM_COLS; j++)
			cout << tablero[i][j];
		
		cout << endl;
	}
		
	// Volvemos a establecer todos los valores de 'tablero' al car�cter 'HUECO'
	for(int i = 0; i < NUM_FILAS; i++)
		for(int j = 0; j < NUM_COLS; j++)
			tablero[i][j] = HUECO;
	
	// Medias de las m�ximas
	
	// Asignamos cada media de las temperaturas m�ximas
	// en la fila que le corresponda
	for(int j = 0; j < num_semanas; j++){
	
		int i = 0;
		
		for(intervalo = (MIN_TEMP + SALTO_TEMP); intervalo < MAX_TEMP; 
			intervalo += SALTO_TEMP){
		
			if( ( medias_maximas[j] >= (intervalo - SALTO_TEMP) ) && 
			   	( medias_maximas[j] < intervalo) ) {
			   		
				tablero[i][j] = TRAZO;
			}
				
			i++;
		}	
	}
		
	// Salida del gr�fico de las medias de las m�ximas
	
	cout << endl << endl;
	cout << "Medias de las maximas semanales: ";
	cout << endl << endl;	
	
	intervalo = MAX_TEMP;
	
	for(int i = NUM_FILAS-1; i >= 0; i--){
		
		intervalo -= SALTO_TEMP;
		
		cout << "[" << setw(6) << intervalo << "," << setw(6) 
			 << intervalo + SALTO_TEMP << ") ";
		
		for(int j = 0; j < NUM_COLS; j++)
			cout << tablero[i][j];
		
		cout << endl;
	}
	
	cout << endl << endl;
		
	return 0;	
}
