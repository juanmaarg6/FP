/*
	Relación de ejercicios 4

	Ejercicio 12: Programa que, dado el número total de escaños a distribuir, 
				  el número de partidos que han participado en las elecciones 
				  y los votos obtenidos por cada uno de ellos, el programa
				  mostrará cuántos escaños obtuvo cada partido usando el
				  sistema (o ley) D'Hont.
				  
	              
	Entradas: Número de escaños a repartir (num_escagnos),
	          Número de partidos que han participado en las elecciones
	          (num_partidos),
	          Número de votos obtenidos por cada partido (partidos[].votos).
	Salidas: Distribución de los escaños según la el sistema o ley
	         D'Hont (partidos[].escagnos).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <iomanip>

using namespace std;

/****************************************************************************/
// Registro utilizado para representar los votos y los escaños de un
// partido político
/****************************************************************************/
struct Partido {
	char sigla;		// "Nombre" del partido
	long votos;		// Votos recibidos
	int escagnos;	// Escaños conseguidos		
};

/****************************************************************************/
// Función principal
/****************************************************************************/
int main () {	
		
	// Vector de datos
	const int MAX_PARTIDOS = 50;
	Partido partidos[MAX_PARTIDOS];
	
	int num_escagnos;
	int num_partidos;
	
	// Entradas de datos 
	
	do {
		cout << " Numero de escagnos = ";
		cin >> num_escagnos;
	}while(num_escagnos < 0);
	
	do {
		cout << " Numero de partidos = ";
		cin >> num_partidos;
	}while(num_partidos <= 0);
	
	// Inicializamos el vector 'partidos', de forma que la letra que
	// representa a un partido de cada posición del vector sea 'A', 'B', 'C', 
	//... , respectivamente, y cada partido tenga un número de escaños
	// asignados igual a 0
	char letra = 'A';
	for(int i = 0; i < num_partidos; i++)
		partidos[i].sigla = letra + i;
	
	for(int i = 0; i < num_partidos; i++)
		partidos[i].escagnos = 0;
	
	cout << endl;
	cout << " Introduzca el numero de votos de cada partido: ";
	cout << endl << endl;
	for(int i = 0; i < num_partidos; i++) {
		
		cout << "\t Partido " << partidos[i].sigla << ": ";
		cin >> partidos[i].votos;
	}

	// Cálculos
	
	double cociente = 0.0;
	double cociente_maximo = cociente;
	int partido_ganador_escagno;
	
	
	for(int i = 0; i < num_escagnos; i++) {
		
		int j = 0;
		
		while(j < num_partidos) {
			
			// Calculamos el máximo cociente = V_i / (S_i + 1), siendo V_i el 
			// número de votos que ha recibido el partido correspondiente
			// y S_i el número de escaños que lleva obtenidos hasta el
			// momento el partido correspondiente. 
			cociente = partidos[j].votos / (partidos[j].escagnos + 1);
			
			if(cociente_maximo <= cociente) {
				cociente_maximo = cociente;
				partido_ganador_escagno = j;
			}
			
			j++;
		}
		
		// El escaño es asignado al partido cuyo 'cociente' sea mayor
		// en comparación a los cocientes de los otros partidos
		partidos[partido_ganador_escagno].escagnos++;
		cociente_maximo = 0.0;
	}
	
	// Salidas
	
	cout << endl;
	cout << " Distribucion de escagnos: ";
	cout << endl;
	for(int i = 0; i < num_partidos; i++) {
		
		cout << endl;
		cout << "\t Partido " << partidos[i].sigla << " (" << setw(10) 
		     << partidos[i].votos << " votos) --> " << partidos[i].escagnos
		     << " Escagnos";
		     
	}

	cout << endl << endl;
	
	return 0;
}
