/*
	Ejercicio 4: Programa que, dada una fecha,
	             muestra si la fecha es valida,
	             ademas de la fecha del dia siguiente
	             y del dia anterior.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

/*
	Clase en la que cada objeto de ella representa una
	fecha valida de la forma dia/mes/año, donde estos tres
	valores son numeros enteros.
*/
class Fecha{
	private:
		int dia; // Dia del mes
		int mes; // Mes del año
		int anio; // Año
	public:
		/*
			Constructor de la clase.
			
			Parametros: d (dia), m (mes), a (año)
		*/
		Fecha(int d, int m, int a);
		
		/*
			Funcion que establece una fecha.
			
			Parametros: d (dia), m (mes), a (año).
			
			Devuelve: -
		*/
		void EstablecerFecha(int d, int m, int a);
		
		/*
			Funcion que comprueba si el año introducido es bisiesto.
			
			Parametros: anio
			
			Devuelve: "true" si el año es bisiesto y "false" si no lo es.
		*/
		bool Bisiesto(int anio);
		
		/*
			Funcion que comprueba si el mes introducido es valido.
			
			Parametros: mes
			
			Devuelve: "true" si el mes es valido y "false" si no lo es.
		*/
		bool MesValido(int mes);

		/*
			Funcion que comprueba si el dia introducido es valido.
			
			Parametros: dia
			
			Devuelve: "true" si el mes es valido y "false" si no lo es.
		*/
		bool DiaValido(int dia, int mes, int anio);
		
		/*
			Funcion que comprueba si la fecha introducida es valida.
			
			Parametros: dia, mes, anio.
			
			Devuelve: "true" si el mes es valido y "false" si no lo es.
		*/
		bool FechaValida(int dia, int mes, int anio);
		
		/*
			Funcion que calcula la fecha del dia anterior.
			
			Parametros: _dia, _mes, _anio.
			
			Devuelve: -
		*/
		void FechaDiaAnterior(int _dia,int _mes, int _anio);
		
		/*
			Funcion que calcula la fecha del dia siguiente.
			
			Parametros: _dia, _mes, _anio.
			
			Devuelve: -
		*/
		void FechaDiaSiguiente(int _dia, int _mes, int _anio);
};

int main(){
	int dia;
	int mes;
	int anio;
	Fecha hoy(0,0,0);
	Fecha ayer(0,0,0);
	Fecha maniana(0,0,0);
	
	/*
		Algoritmo:
		
			El usuario introduce una fecha y esta se almacena.
			
			Se comprueba si la fecha introducida es valida y se
			muestra el resultado en pantalla.
			
			Se muestra en pantalla la fecha del dia anterior y la
			fecha del dia siguiente.
	*/
	
	cout << " Introduzca una fecha: ";
	cout << "\n\n\t Dia: ";
	cin >> dia; 
	cout << "\n\t Mes: ";
	cin >> mes; 
	cout << "\n\t Año: ";
	cin >> anio; 
	
	hoy.EstablecerFecha(dia, mes, anio);
	ayer.EstablecerFecha(dia, mes, anio);
	maniana.EstablecerFecha(dia, mes, anio);
	
	if(hoy.FechaValida(dia, mes, anio) == false){
		cout << "\n La fecha introducida no es valida" << endl << endl;
		exit(-1);
	}
	else
		cout << "\n La fecha introducida es valida.";
	
	ayer.FechaDiaAnterior(dia, mes, anio);
	maniana.FechaDiaSiguiente(dia, mes, anio);
	
	system("pause");
}

Fecha::Fecha(int d, int m, int y){
	dia = d;
	mes = m;
	anio = y;
}

void Fecha::EstablecerFecha(int d, int m, int y){
	dia = d;
	mes = m;
	anio = y;
}

bool Fecha::Bisiesto(int anio){
	bool bisiesto;
	bool salida = false;
	
	/*
		Algoritmo:
		
		Si el año es multiplo de 4 y no es multiplo de 100, o si el año
		es multiplo de 400, entonces dicho año es bisiesto.
		
		Si es bisiesto, devuelve "true". 
		Si no lo es, devuelve "false".
	*/
	
	bisiesto = ((anio % 4 == 0) && (anio % 100 != 0)) || (anio % 400 == 0);
	
	if(bisiesto)
		salida = true;
	else
		salida = false;
				
	return salida;
}

bool Fecha::MesValido(int mes){
	bool salida;
	
	/*
		Algoritmo:
		
		Si el mes es menor o igual a 0, o mayor que 12, entonces no es
		valido, por lo que se devuelve "false".
		Si no, devuelve "true".
	*/
	
	if(mes <= 0 || mes > 12)
		salida = false;
	else
		salida = true;
		
	return salida;
}

bool Fecha::DiaValido(int dia, int mes, int anio){
	bool salida = true;
	
	/*
		Algoritmo:
		
		Si el dia es menor o igual que 0, o mayor que 31, se devuelve
		"false".
		Si no, dependiendo del mes introducido y de si el año es bisiesto,
		se devolvera "true" o "false.
	*/
	
	if(dia <= 0 || dia > 31)
		salida = false;
	else{
		if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
			if(dia == 31)
				salida = false;
		}
		if(mes == 2){
			if(Bisiesto(anio) == false){
				if(dia > 28)
					salida = false;
			}
			else{
				if(dia > 29)
					salida = false;
			}	
		}
	}

	return salida;
}

bool Fecha::FechaValida(int dia, int mes, int anio){
	
	/*
		Algoritmo:
		
		La fecha sera valida si el mes es valido y el dia tambien es valido.
		En ese caso, devuelve "true".
		Si no, devuelve "false".
	*/
	
	if(MesValido(mes) == true && DiaValido(dia, mes, anio) == true)
		return true;
	else
		return false;
}

void Fecha::FechaDiaAnterior(int _dia, int _mes, int _anio){
	
	/*
		Algoritmo:
		
		Si el dia es mayor que 1, entonces la fecha anterior consiste en
		restar 1 a dicho dia.
		Si dia es igual a 1, se calcula la fecha anterior en funcion de
		cual sea el mes y de si el año es bisiesto.
		
		Se muestra la fecha del dia anterior.
	*/
	
	if(_dia > 1)
		dia = _dia - 1;
	if(_dia == 1){
		if(_mes == 2 || _mes == 4 || _mes == 6 || _mes == 8 || _mes == 9 || _mes == 11){
			dia = 31;
			mes = _mes - 1;
		}
		if(_mes == 5 || _mes == 7 || _mes == 10 || _mes == 12){
			dia = 30;
			mes = _mes - 1;
		}
		if(_mes == 1){
			dia = 31;
			mes = 12;
			anio = _anio - 1;
		}
		if(_mes == 3){
			if(Bisiesto(_anio) == true){
				dia = 29;
				mes = _mes - 1;
			}
			else{
				dia = 28;
				mes = _mes - 1;
			}
		}
	}
	
	cout << "\n Fecha del dia anterior: " << dia << "/" << mes << "/" << anio;
}

void Fecha::FechaDiaSiguiente(int _dia, int _mes, int _anio){
	
	/*
		Algoritmo:
		
		En funcion del dia, del mes y de si el año es bisiesto, se calcula la fecha siguiente
		siguiente segun una fecha dada
		
		Se muestra la fecha del dia siguiente.
	*/
	
	if(_mes == 1 || _mes == 3 || _mes == 5 || _mes == 7 || _mes == 8 || _mes == 10 || _mes == 12){
		if (_dia < 31)
			dia = _dia + 1;
		else{
			dia = 1;
			if(_mes != 12)
				mes = _mes + 1;
			else{
				mes = 1;
				anio = _anio + 1;
			}
		}
	}
	else{
		if(_dia < 28)
			dia = _dia + 1;
		else{
			if(_mes != 2){
				if(_dia < 30)
					dia = _dia + 1;
				else{
					dia = 1;
					mes = _mes + 1;
				}
			}
			else{
				if(Bisiesto(_anio) == true)
					dia = _dia + 1;
				else{
					dia = 1;
					mes = _mes + 1;
				}
			}
		}
	}
	
	cout << "\n Fecha del dia siguiente: " << dia << "/" << mes << "/" << anio << endl << endl;
}
