/*
	Ejercicio 11: Programa que, dados los movimientos realizados
					  sobre la traccion de una bicicleta (es decir, el
					  conjunto de estrella [engranaje trasero], cadena y 
					  pinion [engranaje delantero]), muestra la posicion final 
					  de la estrella y el pinion.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>
#include <vector>

using namespace std;

const int LONGITUD_PINION = 7;
const int LONGITUD_ESTRELLA = 3;

/*
	Clase en la que cada objeto de ella representa la
	traccion de una bicicleta.
*/
class Bicicleta{
	private:
		const int pinion[LONGITUD_PINION] = {1,2,3,4,5,6,7}; // Posiciones del pinion
		const int estrella[LONGITUD_ESTRELLA] = {1,2,3}; // Posiciones de la estrella
		int posicion_pinion; // Posicion del pinion
		int posicion_estrella; // Posicion de la estrella
		vector<char> movimientos; // Movimientos realizados sobre la traccion de la bicicleta
		
		/*
			Funcion que comprueba si la posicion de los engranajes (estrella y pinion) es correcta.
			
			Parametros: componente (char).
			
			Devuelve: -
		*/	
		bool SeguridadMecanismo(char componente);

		/*
			Funcion que comprueba si hay riesgo de que se rompa la cadena.
			
			Parametros: -
			
			Devuelve: -
		*/	
		bool SeguridadCadena();
		
	public:
		/*
			Constructor por defecto.
			
			Parametros: -
			
			Devuelve: -
		*/	
		Bicicleta();
		
		/*
			Funcion que lee la secuencia de movimientos de la traccion de la bicicleta.
			
			Parametros: -
			
			Devuelve: -
		*/	
		void LeerSecuencia();

		/*
			Funcion que establece las posiciones del pinion y la estrella.
			
			Parametros: -
			
			Devuelve: -
		*/	
		void SetPosiciones();

		/*
			Funcion que devuelve la posicion de la estrella.
			
			Parametros: -
			
			Devuelve: -
		*/			
		int GetPosicionEstrella();
		
		/*
			Funcion que devuelve la posicion del pinion.
			
			Parametros: -
			
			Devuelve: -
		*/				
		int GetPosicionPinion();
		
		/*
			Funcion que muestra las posiciones del pinion y la estrella.
			
			Parametros: -
			
			Devuelve: -
		*/				
		void GetPosiciones();
};

int main(){
	Bicicleta bicicleta;
	
	bicicleta.LeerSecuencia();
	bicicleta.SetPosiciones();
	bicicleta.GetPosiciones();
	
	cout << endl << endl;
	system("pause");
}

bool Bicicleta::SeguridadMecanismo(char componente){
	bool respuesta;
	
	if(componente == 'p'){
		if(-1 < posicion_pinion && posicion_pinion < 7)
			respuesta = true;
		else
			respuesta = false;
	}
	if(componente == 'e'){
		if(-1 < posicion_estrella && posicion_estrella < 3)
			respuesta = true;
		else
			respuesta = false;
	}
	
	return respuesta;
}

bool Bicicleta::SeguridadCadena(){
	bool respuesta = true;
	
	if(GetPosicionEstrella() == 1 && GetPosicionPinion() >= 5)
		respuesta = false;
	if(GetPosicionEstrella() == 2 && GetPosicionPinion() == 1 || GetPosicionEstrella() == 2 && GetPosicionPinion() == 7)
		respuesta = false;
	if(GetPosicionEstrella() == 3 && GetPosicionPinion() <= 3)
		respuesta = false;

	return respuesta;
}

Bicicleta::Bicicleta(){
	posicion_pinion = 0;
	posicion_estrella = 0;
}

void Bicicleta::LeerSecuencia(){
	char caracter;
	vector<char> vector_parametro;

	do{
 	   cin >> caracter;
	   if(caracter != '#')
	   	vector_parametro.push_back(caracter);
	}while(caracter != '#');
	
	movimientos = vector_parametro;
}

void Bicicleta::SetPosiciones(){
	for(int i = 0; i < movimientos.size(); i++){
		if(movimientos[i] == 'E'){
			if(movimientos[i + 1] == 'S'){
				posicion_estrella++;
				
				if(!SeguridadMecanismo('e'))
					posicion_estrella--;
			}
			
			if(movimientos[i + 1] == 'B'){
				posicion_estrella--;
				
				if(!SeguridadMecanismo('e'))
					posicion_estrella++;
			}
		}
		
		if(movimientos[i] == 'P'){
			if(movimientos[i + 1] == 'S'){
				posicion_pinion++;
				
				if(!SeguridadMecanismo('p'))
					posicion_estrella--;
			}
			
			if(movimientos[i + 1] == 'B'){
				posicion_pinion--;
				
				if(!SeguridadMecanismo('p'))
					posicion_estrella++;
			}
			
			if(movimientos[i + 1] == 'T'){
				posicion_pinion += 2;
				
				if(!SeguridadMecanismo('p'))
					posicion_estrella -= 2;
			}
			
			if(movimientos[i + 1] == 'C'){
				posicion_pinion -= 2;
				
				if(!SeguridadMecanismo('e'))
					posicion_estrella += 2;
			}
		}
	}
	
	if(!SeguridadCadena())
		posicion_estrella = posicion_pinion = 0;
}

int Bicicleta::GetPosicionEstrella(){
	return estrella[posicion_estrella];
}

int Bicicleta::GetPosicionPinion(){
	return pinion[posicion_pinion];
}

void Bicicleta::GetPosiciones(){
	if(posicion_estrella == 0 && posicion_pinion == 0 && movimientos.size() != 0)
		cout << "\n\n Se reseteara la estrella y el pinion por temas de proteccion de cadena\n";

	cout << "\n\t Posicion Estrella: " << estrella[posicion_estrella];
	cout << "\n\t Posicion Pinion: " << pinion[posicion_pinion];
}
