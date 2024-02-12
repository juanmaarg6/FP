/*
	Ejercicio 19: Programa para jugar al "M" En Raya en un tablero
					  de dimension "n" x "n".
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

const int MAXIMA_DIMENSION = 100; // Constante que representa la dimension maxima del tablero del "M" En Raya
const string SEPARADOR = "\n\n **********************************************************************************\n\n"; // Constante que representa un separador

/*
	Clase en la que cada objeto de ella representa un
	juego de "M" En Raya.
*/
class M_En_Raya{
	private:
		int tablero[MAXIMA_DIMENSION][MAXIMA_DIMENSION]; // Tablero del "M" En Raya
		int dimension_tablero; // Dimension del tablero del "M" En Raya
		int fichas_en_raya_para_ganar; // Numero de fichas que hay que colocar en raya para ganar en el "M" En Raya
		
	public:
		/*
			Constructor por defecto.
			
			Parametros: -
			
			Devuelve: -
		*/	
		M_En_Raya();
		
		/*
			Funcion que establece la dimension del tablero del "M" En Raya.
			
			Parametros: _dimension_tablero (int).
			
			Devuelve: -
		*/	
		void SetDimensionTablero(int _dimension_tablero);
		
		/*
			Funcion que establece el tablero del "M" En Raya.
			
			Parametros: -
			
			Devuelve: -
		*/	
		void SetTablero();
		
		/*
			Funcion que establece el numero de fichas consecutivas para ganar en el "M" En Raya.
			
			Parametros: _fichas_en_raya_para_ganar (int).
			
			Devuelve: -
		*/	
		void SetFichasEnRayaParaGanar(int _fichas_en_raya_para_ganar);
		
		/*
			Funcion que muestra el tablero del "M" En Raya.
			
			Parametros: -
			
			Devuelve: -
		*/	
		void MostrarTablero();

		/*
			Funcion que muestra la posicion de cada casilla del tablero del "M" En Raya.
			
			Parametros: -
			
			Devuelve: -
		*/	
		void MostrarFilaColumnaCasilla();
		
		/*
			Funcion que calcula el numero de fichas que hay colocadas en el tablero del "M" En Raya.
			
			Parametros: -
			
			Devuelve: contador_fichas_en_tablero (int).
		*/	
		int ContarFichasEnTablero();
		
		/*
			Funcion que coloca una ficha (ya sea del jugador 1 o del jugador 2) en el tablero del "M" En Raya.
			
			Parametros: -
			
			Devuelve: -
		*/		
		void ColocarFichas();
		
		/*
			Funcion que comprueba si un jugador ha ganado en el "M" En Raya.
			
			Parametros: ficha_jugador (int).
			
			Devuelve: jugador_gana (bool).
		*/	
		bool JugadorGana(int ficha_jugador);
		
		/*
			Funcion que muestra quien ha ganado o si ha habido empate en el "M" En Raya.
			
			Parametros: -
			
			Devuelve: -
		*/		
		void VictoriaEmpate();
};

/*
	Funcion principal.
*/
int main(){
	M_En_Raya juego;
	int dimension_tablero = 0;
	int fichas_en_raya_para_ganar = 0;
	
	/*
		Algoritmo:
		
		El usuario introduce la dimension del tablero.
		
		Se muestra el tablero y las posiciones de cada casilla del tablero.
		
		El usuario introduce el numero de fichas que hay que colocar en raya para ganar.
		
		Los jugadores 1 y 2 comienzan a colocar fichas hasta que uno de los dos gane o haya empate.
		
		Se muestra quien ha ganado o si ha habido empate en el juego.
	*/
	
	do{
		cout << " Introduzca la dimension del tablero (3 <= dimension <= 100): ";
		cin >> dimension_tablero;
	}while(dimension_tablero < 3 || dimension_tablero > MAXIMA_DIMENSION);
	
	juego.SetDimensionTablero(dimension_tablero);
	
	juego.SetTablero();

	cout << endl;
	
	juego.MostrarTablero();
	juego. MostrarFilaColumnaCasilla();
	
	do{
		cout << "\n Introduzca el numero de fichas que hay que colocar en raya para ganar (3 <= numero <= dimension): ";
		cin >> fichas_en_raya_para_ganar;
	}while(fichas_en_raya_para_ganar < 3 || fichas_en_raya_para_ganar > dimension_tablero);
	
	juego.SetFichasEnRayaParaGanar(fichas_en_raya_para_ganar);
	
	cout << SEPARADOR;
	
	juego.ColocarFichas();
	
	cout << SEPARADOR;
	
	juego.VictoriaEmpate();
	
	cout << endl << endl;
	system("pause");
}

/*
	Constructores y funciones de la clase "M_En_Raya".
*/
M_En_Raya::M_En_Raya(){
	
	/*
		Algoritmo:
		
		Se establece un tablero 3x3, cuya dimension, por tanto, es 3.
		
		El numero de fichas que hay que colocar en raya para ganar se establece a 3.
	*/
	
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			tablero[i][j] = 0;
			
	dimension_tablero = 3;
	
	fichas_en_raya_para_ganar = 3;
}

void M_En_Raya::SetDimensionTablero(int _dimension_tablero){
	dimension_tablero = _dimension_tablero;
}

void M_En_Raya::SetTablero(){
	for(int i = 0; i < dimension_tablero; i++)
		for(int j = 0; j < dimension_tablero; j++)
			tablero[i][j] = 0;
}

void M_En_Raya::SetFichasEnRayaParaGanar(int _fichas_en_raya_para_ganar){
	fichas_en_raya_para_ganar = _fichas_en_raya_para_ganar;
}

void  M_En_Raya::MostrarTablero(){		

	/*
		Algoritmo:
		
		Se muestra el valor cada casilla del tablero.
		
		Si la posicion de una casilla es multiplo de la dimension del tablero,
		entonces se hace un salto de linea.
	*/
	
	for(int i = 0; i < dimension_tablero; i++){
		for(int j = 0; j < dimension_tablero; j++){
			cout << "\t " << tablero[i][j];
			
			if((j + 1) % dimension_tablero == 0)
				cout << endl;
		}
	}	
}

void  M_En_Raya::MostrarFilaColumnaCasilla(){
	
	/*
		Algoritmo:
		
		Se muestra la posicion de cada casilla del tablero.
		
		Si la posicion de una casilla es multiplo de la dimension del tablero,
		entonces se hace un salto de linea.
	*/
	cout << "\n NOTA: A continuacion se muestran las posiciones de cada casilla del tablero \n\n";
	
	for(int i = 0; i < dimension_tablero; i++){
		for(int j = 0; j < dimension_tablero; j++){
			cout << "\t " << "[" << i << "]" << "[" << j << "]";
			
			if((j + 1) % dimension_tablero == 0)
				cout << endl;
		}
	}
}

int M_En_Raya::ContarFichasEnTablero(){
	int contador_fichas_en_tablero = 0;
	
	/*
		Algoritmo:
		
		Se recorre el tablero casilla a casilla.
			Si el valor de una casilla del tablero es 1 o 2,
			entonces "contador_fichas_en_tablero" aumenta en 1.
			
		Devuelve "contador_fichas_en_tablero".
	*/
	
	for(int i = 0; i < dimension_tablero; i++)	
		for(int j = 0; j < dimension_tablero; j++)	
			if(tablero[i][j] == 1 || tablero[i][j] == 2)
				contador_fichas_en_tablero++;
				
	return contador_fichas_en_tablero;
}

void M_En_Raya::ColocarFichas(){
	int fila, columna = 0;
	bool jugador1_gana, jugador2_gana, empate = false;
	
	do{
		if(ContarFichasEnTablero() == dimension_tablero * dimension_tablero)
			empate = true;
		
	/*
		Algoritmo:
		
		Mientras no gane ninguno de los dos jugadores o no haya empate:
		
			Si no ha ganado el jugador 2 o no ha habido empate:
				El jugador 1 coloca una ficha en la casilla que el elija.
				
				Dicha casilla toma el valor 1.
				
				Se muestra el tablero.
				
				Se comprueba si el jugador 1 ha ganado.
				
			Se comprueba si todas las casillas del tablero han sido rellenadas y, por tanto,
			hay empate.
	
			Si no ha ganado el jugador 1 o no ha habido empate:
				El jugador 2 coloca una ficha en la casilla que el elija.
				
				Dicha casilla toma el valor 2.
				
				Se muestra el tablero.
				
				Se comprueba si el jugador 2 ha ganado.
				
			Se comprueba si todas las casillas del tablero han sido rellenadas y, por tanto,
			hay empate.	
	*/
		
		if(!jugador2_gana && !empate){
			do{
				cout << "\n Jugador 1 (Introduzca 'fila (espacio) columna' para colocar ficha): ";
				cin >> fila >> columna;
			}while(fila < 0 || columna < 0 || fila >= dimension_tablero || columna >= dimension_tablero || tablero[fila][columna] == 1 || tablero[fila][columna] == 2);

			tablero[fila][columna] = 1;
			
			cout << endl;
			
			MostrarTablero();
			
			jugador1_gana = JugadorGana(1);
		}
		
		if(ContarFichasEnTablero() == dimension_tablero * dimension_tablero)
			empate = true;
			
		if(!jugador1_gana && !empate){
			do{
				cout << "\n Jugador 2 (Introduzca fila y columna para colocar ficha): ";
				cin >> fila >> columna;
			}while(fila < 0 || columna < 0 || fila >= dimension_tablero || columna >= dimension_tablero || tablero[fila][columna] == 1 || tablero[fila][columna] == 2);
		
			tablero[fila][columna] = 2;
			
			cout << endl;
			
			MostrarTablero();
			
			jugador2_gana = JugadorGana(2);
		}
			
		if(ContarFichasEnTablero() == dimension_tablero * dimension_tablero)
			empate = true;
			
	}while(!jugador1_gana && !jugador2_gana && !empate);
}
			
bool M_En_Raya::JugadorGana(int ficha_jugador){
	bool jugador_gana = false;
	int contador_fichas_consecutivas = 0;

	/*
		Algoritmo:
		
		Si "jugador_gana == false":
			Se comprueba, para cada fila del tablero, si el jugador tiene el numero de fichas que hay 
			que colocar en raya para ganar.
			
			Si las tiene, entonces "jugador_gana == true".

		Si "jugador_gana == false":
			Se comprueba, para cada columna del tablero, si el jugador tiene el numero de fichas que hay 
			que colocar en raya para ganar.
			
			Si las tiene, entonces "jugador_gana == true".
			
		Si "jugador_gana == false":
			Se comprueba, para cada diagonal hacia la derecha del tablero, si el jugador tiene el numero de fichas que hay 
			que colocar en raya para ganar.
			
			Si las tiene, entonces "jugador_gana == true".
			
		Si "jugador_gana == false":
			Se comprueba, para cada diagonal hacia la izquierda del tablero, si el jugador tiene el numero de fichas que hay 
			que colocar en raya para ganar.
			
			Si las tiene, entonces "jugador_gana == true".
			
		Devuelve jugador_gana".
	*/
	
	if(!jugador_gana)
      for(int i = 0; i < dimension_tablero && !jugador_gana; i++){
      	contador_fichas_consecutivas = 1;
      	
         for(int j = 0; j < dimension_tablero && !jugador_gana; j++)
				if(tablero[i][j] == ficha_jugador && tablero[i][j] == tablero[i][j + 1])
					contador_fichas_consecutivas++;	     
					
			if(contador_fichas_consecutivas == fichas_en_raya_para_ganar)
				jugador_gana = true;
      }
      
	if(!jugador_gana)
   	for(int j = 0; j < dimension_tablero && !jugador_gana; j++){
      	contador_fichas_consecutivas = 1;
      	
         for(int i = 0; i < dimension_tablero && !jugador_gana; i++)
				if(tablero[i][j] == ficha_jugador && tablero[i][j] == tablero[i + 1][j])
					contador_fichas_consecutivas++;	     
					
			if(contador_fichas_consecutivas == fichas_en_raya_para_ganar)
				jugador_gana = true;
      }

	if(!jugador_gana){
		for(int i = 0; i <= dimension_tablero && !jugador_gana; i++){
			contador_fichas_consecutivas = 0;
			
			for(int k = i, j = 0; k < dimension_tablero && !jugador_gana; k++, j++)
		   	if(tablero[k][j] == ficha_jugador)
					contador_fichas_consecutivas++;
														
			if(contador_fichas_consecutivas == fichas_en_raya_para_ganar)
				jugador_gana = true;
		}
		
		for(int j = 0; j <= dimension_tablero && !jugador_gana; j++){
			contador_fichas_consecutivas = 0;
			
			for(int k = j, i = 0; k < dimension_tablero && !jugador_gana; k++, i++)
		   	if(tablero[i][k] == ficha_jugador)
					contador_fichas_consecutivas++;
														
			if(contador_fichas_consecutivas == fichas_en_raya_para_ganar)
				jugador_gana = true;
		}
	}
	
	if(!jugador_gana){
		for(int i = 0; i <= dimension_tablero && !jugador_gana; i++){
			contador_fichas_consecutivas = 0;
			
			for(int k = i, j = 0; j < dimension_tablero && !jugador_gana; k--, j++)
		   	if(tablero[k][j] == ficha_jugador)
					contador_fichas_consecutivas++;
														
			if(contador_fichas_consecutivas == fichas_en_raya_para_ganar)
				jugador_gana = true;
		}
		
		for(int j = 0; j <= dimension_tablero && !jugador_gana; j++){
			contador_fichas_consecutivas = 0;
			
			for(int k = j, i = dimension_tablero - 1; k < dimension_tablero && !jugador_gana; k++, i--)
		   	if(tablero[i][k] == ficha_jugador)
					contador_fichas_consecutivas++;
														
			if(contador_fichas_consecutivas == fichas_en_raya_para_ganar)
				jugador_gana = true;
		}
	}
					
	return jugador_gana;
}	 

void M_En_Raya::VictoriaEmpate(){
	
	/*
		Algoritmo:
		
		Se comprueba si ha ganado el jugador 1 y, en ese caso, se muestra en pantalla que ha ganado.
		
		Si no, se comprueba si ha ganado el jugador 2 y, en ese caso, se muestra en pantalla que ha ganado.

		Si no, se muestra en pantalla que ha habido empate.
	*/
	
	if(JugadorGana(1))
		cout << "\n GANADOR: Jugador 1";
	else if(JugadorGana(2))
		cout << "\n GANADOR: Jugador 2";
	else
		cout << "\n EMPATE";
}
