/*
	Ejercicio 18: Programa que, dado un numero racional representado
	              como una fraccion:
	              
	              - Muestra la fraccion irreducible de dicha fraccion.
	              - Compara si dicho racional es menor que otro.
	              - Muestra el numero racional hasta un cierto numero de decimales dado.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>
#include <vector>

using namespace std;

/*
	Clase en la que cada objeto de ella representa un
	numero racional, r, mediante dos numeros enteros,
	a y b, los cuales representan el numerador y el denominador
	de la fraccion r = a/b, respectivamente.
*/
class Racional{
	private:
		int numerador; // Numerador de la fraccion
		int denominador; // Denominador de la fraccion
	public:
		/*
			Constructor por defecto.
			
			Parametros: -
			
			Devuelve: -
		*/	
		Racional();
		
		/*
			Constructor de la clase.
			
			Parametros: _numerador (int), _denominador (int).
			
			Devuelve: -
		*/	
		Racional(int _numerador, int _denominador);
		
		/*
			Funcion que muestra la fraccion irreducible de una fraccion dada.
			
			Parametros: -
			
			Devuelve: -
		*/	
		void FraccionIrreducible();
		
		/*
			Funcion que determina si un racional es menor que otro.
			
			Parametros: racional2 (Racional).
			
			Devuelve: -
		*/	
		bool Menor(Racional racional2);
		
		/*
			Funcion que muestra el numero racional hasta un cierto numero de decimales dado.
			
			Parametros: precision (int).
			
			Devuelve: -
		*/	
		void MostrarRacional(int precision);
};

int main(){
   Racional racional1(7,2);
   Racional racional2(-2,10);
   Racional racional3(1,3);
      
   cout << " Fraccion irreducible de 7/2: ";
   racional1.FraccionIrreducible();
   
   cout << "\n Fraccion irreducible de -2/10: ";
   racional2.FraccionIrreducible();
   
   cout << "\n\n ¿7/2 es menor que -2/10?: ";
   if(racional1.Menor(racional2))
   	cout << "Sí";
   else
   	cout << "No";
   
	cout << "\n ¿-2/10 es menor que 7/2?: ";
   if(racional2.Menor(racional1))
   	cout << "Sí";
   else
   	cout << "No";	
   
   cout << "\n\n 7/2 = ";
   racional1.MostrarRacional(5);
   cout << "\n -2/10 = ";
   racional2.MostrarRacional(2);
   cout << "\n 1/3 = ";
   racional3.MostrarRacional(10);	
   
   cout << endl << endl;
   system("pause");
}

Racional::Racional(){
	numerador = 1;
	denominador = 2;
}

Racional::Racional(int _numerador, int _denominador){
	// Solo vamos a permitir denominadores positivos
   if(_denominador != 0){
      if(_denominador < 0){
         numerador = - _numerador;
         denominador = - _denominador;
      }
		else{
         numerador = _numerador;
         denominador = _denominador;
      }
   }
   // No se permiten denominadores nulos
   else{
      numerador = 1;
      denominador = 2;
   }
}

void Racional::FraccionIrreducible(){
	int _numerador = numerador;
	int _denominador = denominador;
	int resto;
	
   if(numerador < 0)
      _numerador = - numerador;
   
   /*
   	Algoritmo:
   	
   	Se calcula el Maximo Comun Divisor del numerador y el denominador.
   	
   	Se divide tanto numerador como denominador por el Maximo Comun Divisor.
   */
   resto = _numerador % _denominador;
    
   while(resto != 0){
      _numerador = _denominador;
      _denominador = resto;
      resto = _numerador % _denominador;
   }
    
   numerador = numerador / _denominador;
   denominador = denominador / _denominador;	
   
   cout << numerador << "/" << denominador;
}

bool Racional::Menor(Racional racional2){
	bool es_menor;
	
	es_menor = (numerador * racional2.denominador) < (racional2.numerador * denominador);
	
	return es_menor;
}

void Racional::MostrarRacional(int precision){
	int _numerador, _denominador, parte_entera, digito_parte_decimal;

	if(precision <= 0)
  		precision = 1;

	if(numerador < 0){
  		cout << "-";
  		_numerador = - numerador;
	}
	else{
  		cout << "+";
  		_numerador = numerador;
	}
	
	_denominador = denominador;


	parte_entera = _numerador / _denominador;
	cout << parte_entera << ".";
	_numerador = (_numerador - _denominador * parte_entera) * 10;

	/*
		Algoritmo:
		
		Para cada digito de la parte decimal hasta "precision":
			Se divide numerador y denominador y se muestra la parte entera.
			El resultado de la division se resta a la fraccion y luego se multiplica todo por 10.
	*/
	
	for(int i = 0; i < precision; i++){
  		digito_parte_decimal = _numerador / _denominador;
  		cout << digito_parte_decimal;
  		_numerador = (_numerador - _denominador * digito_parte_decimal) * 10;
	}
}

