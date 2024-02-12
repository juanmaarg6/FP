/*
	Ejercicio 7: Programa que, dados dos enteros (numero 1 y numero 2) representados
				    como una secuencia de numeros, realiza una de las siguientes opciones:
	             
						1) Determinar si numero 1 es menor que numero 2.
						2) Determinar si numero 1 es mayor que numero 2.
						3) Determinar si numero 1 es menor o igual que numero 2.
						4) Determinar si numero 1 es mayor o igual que numero 2.
						5) Determinar si numero 1 es igual que numero 2.
						6) Determinar si numero 1 es distinto de numero 2.
						7) Calcular la suma de numero 1 y numero 2.
						8) Calcular la resta de numero 1 y numero 2.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/
#include <iostream>

using namespace std;

const int LONGITUD_MAXIMA = 1000;

/*
	Clase en la que cada objeto de ella representa un
	entero largo dado por una secuencia de numeros.
*/
class EnteroLargo{
	private:
		int longitud; // Longitud de la secuencia
		int cifras[LONGITUD_MAXIMA]; // Numeros de la secuencia
	public:
		/*
			Constructor por defecto.
			
			Parametros: -
			
			Devuelve: -
		*/	
		EnteroLargo();
		
		/*
			Funcion que establece la longitud de la secuencia.
			
			Parametros: _longitud (int).
			
			Devuelve: -
		*/
		void EstablecerLongitud(int _longitud);
		
		/*
			Funcion que establece los numeros de la secuencia.
			
			Parametros: _cifras[] (int), _longitud (int).
			
			Devuelve: -
		*/	
		void EstablecerCifras(int _cifras[], int _longitud);

		/*
			Funcion que muestra el entero dado en la secuencia de numeros.
			
			Parametros: -
			
			Devuelve: -
		*/
		void MostrarNumero();

		/*
			Funcion que muestra si el primer numero es menor que el segundo o no.
			
			Parametros: numero2 (EnteroLargo).
			
			Devuelve: -
		*/
		void NumeroMenor(EnteroLargo &numero2);
		
		/*
			Funcion que muestra si el primer numero es mayor que el segundo o no.
			
			Parametros: numero2 (EnteroLargo).
			
			Devuelve: -
		*/			
		void NumeroMayor(EnteroLargo &numero2);
		
		/*
			Funcion que muestra si el primer numero es menoro igual que el segundo o no.
			
			Parametros: numero2 (EnteroLargo).
			
			Devuelve: -
		*/		
		void NumeroMenorIgual(EnteroLargo &numero2);

		/*
			Funcion que muestra si el primer numero es mayor o igual que el segundo o no.
			
			Parametros: numero2 (EnteroLargo).
			
			Devuelve: -
		*/
		void NumeroMayorIgual(EnteroLargo &numero2);
		
		/*
			Funcion que muestra si el primer numero es igual que el segundo o no.
			
			Parametros: numero2 (EnteroLargo).
			
			Devuelve: -
		*/
		void NumeroIgual(EnteroLargo &numero2);

		/*
			Funcion que muestra si el primer numero es distinto del segundo o no.
			
			Parametros: numero2 (EnteroLargo).
			
			Devuelve: -
		*/
		void NumeroDistinto(EnteroLargo &numero2);

		/*
			Funcion que realiza la suma de dos enteros dados por una secuencia de numeros.
						
			Parametros: numero2 (EnteroLargo).
			
			Devuelve: suma (EnteroLargo).
		*/				
		EnteroLargo Sumar(EnteroLargo &numero2);

		/*
			Funcion que realiza la resta de dos enteros dados por una secuencia de numeros.
						
			Parametros: numero2 (EnteroLargo).
			
			Devuelve: resta (EnteroLargo).
		*/		
		EnteroLargo Restar(EnteroLargo &numero2);
};

/*
	Funcion que lee un entero (es decir, su longitud y
	la secuencia de numeros que lo representan).
				
	Parametros: numero (EnteroLargo).
	
	Devuelve: -
*/		
void LeerNumero(EnteroLargo &numero);

/*
	Funcion que muestra un menu de opciones para
	que el usuario elija una de ellas.
	
	Parametros: -
	
	Devuelve: -
*/	
void MenuOpciones();

int main(){
	EnteroLargo numero1, numero2, suma, resta;
	int opcion = 0;
	
	/*
		Algoritmo:
		
		El usuario introduce el numero1 y este se muestra.
		El usuario introduce el numero2 y este se muestra.
		
		Se muestra el menu de opciones.
			Si "opcion == 1", se determina si numero 1 es menor que numero 2.
			Si "opcion == 2", se determina si numero 1 es mayor que numero 2.
			Si "opcion == 3", se determina si numero 1 es menor o igual que numero 2.
			Si "opcion == 4", se determina si numero 1 es mayor o igual que numero 2.
			Si "opcion == 5", se determina si numero 1 es igual que numero 2.
			Si "opcion == 6", se determina si numero 1 es distinto de numero 2.
			Si "opcion == 7", se calcula la suma de numero 1 y numero 2.
			Si "opcion == 8", se calcula la resta de numero 1 y numero 2.
	*/
	cout << " Numero 1\n\n";
	LeerNumero(numero1);
	cout << "\n\t Numero 1 = ";
	numero1.MostrarNumero();

	cout << "\n\n Numero 2\n\n";
	LeerNumero(numero2);
	cout << "\n\t Numero 2 = ";
	numero2.MostrarNumero();

	MenuOpciones();
	cin >> opcion;
	
	if(opcion == 1)
		numero1.NumeroMenor(numero2);
	if(opcion == 2)
		numero1.NumeroMayor(numero2);
	if(opcion == 3)
		numero1.NumeroMenorIgual(numero2);
	if(opcion == 4)
		numero1.NumeroMayorIgual(numero2);
	if(opcion == 5)
		numero1.NumeroIgual(numero2);
	if(opcion == 6)
		numero1.NumeroDistinto(numero2);	
	if(opcion == 7){
		suma = numero1.Sumar(numero2);
		suma.MostrarNumero();
	}
	if(opcion == 8){
		resta = numero1.Restar(numero2);
		resta.MostrarNumero();
	}
	
	cout << endl << endl;
	system("pause");
}

void LeerNumero(EnteroLargo &numero){
	int longitud;
	int cifras[LONGITUD_MAXIMA] = {0};
	
	/*
		Algoritmo:
		
		El usuario introduce el numero de cifras del numero y este
		se establece en el objeto numero.
		
		El usuario introduce la secuencia de numeros y
		este se establece en el objeto numero.
	*/
	
	do{
		cout << "\t Introduzca el numero de cifras del numero: ";
		cin >> longitud;
	}while(longitud < 0 || longitud > LONGITUD_MAXIMA);

	numero.EstablecerLongitud(longitud);

	cout << "\t Introduzca cifra a cifra el numero (separe las cifras con espacios): ";
	for(int i = 0; i < longitud; i++){
		cin >> cifras[i];
	}
	
	numero.EstablecerCifras(cifras, longitud);
}

void MenuOpciones(){
	
	/*
		Algoritmo: 
		
		Se muestran las diferentes opciones que puede elegir el usuario.
	*/
	
	cout << "\n\n Menu de opciones: \n";
	cout << "\n\t 1) Determinar si numero 1 es menor que numero 2\n";
	cout << "\t 2) Determinar si numero 1 es mayor que numero 2\n";
	cout << "\t 3) Determinar si numero 1 es menor o igual que numero 2\n";
	cout << "\t 4) Determinar si numero 1 es mayor o igual que numero 2\n";
	cout << "\t 5) Determinar si numero 1 es igual que numero 2\n";
	cout << "\t 6) Determinar si numero 1 es distinto de numero 2\n";
	cout << "\t 7) Calcular la suma de numero 1 y numero 2\n";
	cout << "\t 8) Calcular la resta de numero 1 y numero 2\n";
	
	cout << "\n Introduzca una opcion: ";
}

EnteroLargo::EnteroLargo(){
	longitud = 1;
	cifras[LONGITUD_MAXIMA] = 0;
}

void EnteroLargo::EstablecerLongitud(int _longitud){
	longitud = _longitud;
}
	
void EnteroLargo::EstablecerCifras(int _cifras[], int _longitud){
	
	/*
		Algoritmo:
		
		Se establece el primer numero de la secuencia (puede ser positivo o negativo).
		
		Se establecen el resto de numeros de la secuencia, que si son positivos se
		dejan igual y si son negativos se les cambia el signo y se dejan como positivos.
	*/
	cifras[0] = _cifras[0];
	for(int i = 1; i < _longitud; i++){
		if(_cifras[i] < 0)
			cifras[i] = - _cifras[i];
		else
			cifras[i] = _cifras[i];
	}
}

void EnteroLargo::MostrarNumero(){
	for(int i = 0; i < longitud; i++)
		cout << cifras[i];
}

void EnteroLargo::NumeroMenor(EnteroLargo &numero2){
	bool numero1_es_menor = false;
	
	/*
		Algoritmo:
		
		Si el numero de cifras de numero1 es menor que el de numero2,
		entonces numero1 es menor que numero2.
		
		Si el numero de cifras de numero1 es mayor que el de numero2,
		entonces numero1 no es menor que numero2.
		
		Si el numero de cifras de numero1 es igual que el de numero2,
		entonces se comparan ambas secuencias de numeros cifra a cifra
		de izquierda a derecha.
			Si una cifra de numero1 es menor que su correspondiente en numero2, 
			entonces	numero1 es menor que numero2.
			Si no, entonces numero1 no es menor que numero2.
	*/
	
	if(longitud < numero2.longitud)
		numero1_es_menor = true;
	
	if(longitud > numero2.longitud)
		numero1_es_menor = false;
		
	if(longitud == numero2.longitud){
		for(int i = 0; i < longitud; i++)
			for(int j = 0; j < numero2.longitud; j++)
				if(cifras[i] < numero2.cifras[j])
					numero1_es_menor = true;	
				else
					numero1_es_menor = false;	
	}	
	
	if(numero1_es_menor)
		cout << "\n\t Numero 1 es menor que Numero 2";
	else
		cout << "\n\t Numero 1 no es menor que Numero 2";
}
	
void EnteroLargo::NumeroMayor(EnteroLargo &numero2){
	bool numero1_es_mayor = false;
	
	/*
		Algoritmo:
		
		Si el numero de cifras de numero1 es mayor que el de numero2,
		entonces numero1 es mayor que numero2.
		
		Si el numero de cifras de numero1 es menor que el de numero2,
		entonces numero1 no es mayor que numero2.
		
		Si el numero de cifras de numero1 es igual que el de numero2,
		entonces se comparan ambas secuencias de numeros cifra a cifra
		de izquierda a derecha.
			Si una cifra de numero1 es mayor que su correspondiente en numero2, 
			entonces numero1 es mayor que numero2.
			Si no, entonces numero1 no es mayor que numero2.
	*/
	
	if(longitud > numero2.longitud)
		numero1_es_mayor = true;
	
	if(longitud < numero2.longitud)
		numero1_es_mayor = false;
		
	if(longitud == numero2.longitud){
		for(int i = 0; i < longitud; i++)
			for(int j = 0; j < numero2.longitud; j++)
				if(cifras[i] > numero2.cifras[j])
					numero1_es_mayor = true;	
				else		
					numero1_es_mayor = false;	
	}	
	
	if(numero1_es_mayor)
		cout << "\n\t Numero 1 es mayor que Numero 2";
	else
		cout << "\n\t Numero 1 no es mayor que Numero 2";
}


void EnteroLargo::NumeroMenorIgual(EnteroLargo &numero2){
	bool numero1_es_menor_igual = false;
	
	/*
		Algoritmo:
		
		Si el numero de cifras de numero1 es menor que el de numero2,
		entonces numero1 es menor o igual que numero2.
		
		Si el numero de cifras de numero1 es mayor que el de numero2,
		entonces numero1 no es menor o igual que numero2.
		
		Si el numero de cifras de numero1 es igual que el de numero2,
		entonces se comparan ambas secuencias de numeros cifra a cifra
		de izquierda a derecha.
			Si una cifra de numero1 es menor o igual que su correspondiente en numero2, 
			entonces numero1 es menor o igual que numero2.
			Si no, entonces numero1 no es menor o igual que numero2.
	*/
	
	if(longitud < numero2.longitud)
		numero1_es_menor_igual = true;
	
	if(longitud > numero2.longitud)
		numero1_es_menor_igual = false;
		
	if(longitud == numero2.longitud){
		for(int i = 0; i < longitud; i++)
			for(int j = 0; j < numero2.longitud; j++)
				if(cifras[i] <= numero2.cifras[j])
					numero1_es_menor_igual = true;	
				else		
					numero1_es_menor_igual = false;	
	}	
	
	if(numero1_es_menor_igual)
		cout << "\n\t Numero 1 es menor o igual que Numero 2";
	else
		cout << "\n\t Numero 1 no es menor o igual que Numero 2";
}

void EnteroLargo::NumeroMayorIgual(EnteroLargo &numero2){
	bool numero1_es_mayor_igual = false;

	/*
		Algoritmo:
		
		Si el numero de cifras de numero1 es mayor que el de numero2,
		entonces numero1 es mayor o igual que numero2.
		
		Si el numero de cifras de numero1 es menor que el de numero2,
		entonces numero1 no es mayor o igual que numero2.
		
		Si el numero de cifras de numero1 es igual que el de numero2,
		entonces se comparan ambas secuencias de numeros cifra a cifra
		de izquierda a derecha.
			Si una cifra de numero1 es mayor o igual que su correspondiente en numero2, 
			entonces numero1 es mayor o igual que numero2.
			Si no, entonces numero1 no es mayor o igual que numero2.
	*/
	
	if(longitud > numero2.longitud)
		numero1_es_mayor_igual = true;

	if(longitud < numero2.longitud)
		numero1_es_mayor_igual = false;
				
	if(longitud == numero2.longitud){
		for(int i = 0; i < longitud; i++)
			for(int j = 0; j < numero2.longitud; j++)
				if(cifras[i] >= numero2.cifras[j])
					numero1_es_mayor_igual = true;	
				else		
					numero1_es_mayor_igual = false;	
	}	
	
	if(numero1_es_mayor_igual)
		cout << "\n\t Numero 1 es mayor o igual que Numero 2";
	else
		cout << "\n\t Numero 1 no es mayor o igual que Numero 2";
}

void EnteroLargo::NumeroIgual(EnteroLargo &numero2){
	bool numero1_igual_numero2 = false;

	/*
		Algoritmo:
		
		Si el numero de cifras de numero1 es igual que el de numero2,
		entonces se comparan ambas secuencias de numeros cifra a cifra
		de izquierda a derecha.
			Si una cifra de numero1 es igual que su correspondiente en numero2, 
			entonces numero1 es igual que numero2.
			Si no, entonces numero1 no es igual que numero2.			
	*/
	
	if(longitud == numero2.longitud)
		for(int i = 0; i < longitud; i++)
			for(int j = 0; j < numero2.longitud; j++)
				if(cifras[i] == numero2.cifras[j])
					numero1_igual_numero2 = true;	
				else		
					numero1_igual_numero2 = false;		
	
	if(numero1_igual_numero2)
		cout << "\n\t Numero 1 es igual que Numero 2";
	else
		cout << "\n\t Numero 1 no es igual que Numero 2";
}

void EnteroLargo::NumeroDistinto(EnteroLargo &numero2){
	bool numero1_distinto_numero2 = false;

	/*
		Algoritmo:
		
		Si el numero de cifras de numero1 es distinto que el de numero2,
		entonces numero1 es distinto de numero2.
		
		Si el numero de cifras de numero1 es igual que el de numero2,
		entonces se comparan ambas secuencias de numeros cifra a cifra
		de izquierda a derecha.
			Si una cifra de numero1 es distinta de su correspondiente en numero2, 
			entonces numero1 es distinto que numero2.
			Si no, entonces numero1 no es distinto que numero2.			
	*/
		
	if(longitud != numero2.longitud)
		numero1_distinto_numero2 = true;			
	else{
		for(int i = 0; i < longitud; i++)
			for(int j = 0; j < numero2.longitud; j++)
				if(cifras[i] != numero2.cifras[j])
					numero1_distinto_numero2 = true;	
				else		
					numero1_distinto_numero2 = false;	
	}	
	
	if(numero1_distinto_numero2)
		cout << "\n\t Numero 1 es distinto de Numero 2";
	else
		cout << "\n\t Numero 1 no es distinto de Numero 2";
}

EnteroLargo EnteroLargo::Sumar(EnteroLargo &numero2){
	EnteroLargo suma;
	int longitud_total;
	int a = longitud, b = numero2.longitud, i;
	
	/*
		Algoritmo:
		
		Si el numero de cifras de numero1 es mayor o igual que el de numero2,
		entonces el numero de cifras de la suma de ambos numeros sera
		igual al numero de cifras de numero1.
		Si no, el numero de cifras de la suma de ambos numeros sera
		igual al numero de cifras de numero2.		
			
		Mientras el numero de cifras de la suma sea distinto de -1:
		
			Si el numero de cifras de numero1 es -1, entonces la cifra
			correspondiente de suma sera igual a la correspondiente cifra de numero2.
			Si no, entonces:
			
				Si el numero de cifras de numero2 es -1, entonces la cifra
				correspondiente de suma sera igual a la correspondiente cifra de numero1.
				Si no, entonces la cifra correspondiente de suma sera igual a la 
				suma de las correspondientes cifras de numero1 y numero2.
				
			Si al dividir una cifra de la suma por 10 el resultado es mayor que 0,
			entonces a la cifra anterior de la suma se le suma el resultado de dicha
			division y la cifra pasa a tomar el valor del resto de dividir ella misma
			por 10. 
				
			Se reducen el numero de cifras de la suma, el numero de cifras de numero1
			y el numero de cifras de numero2 en 1.
			
		Se establecen la longitud y la secuencia de cifras en el objeto suma.
		
		Se devuelve el objeto suma.	
	*/
	
	if(longitud >= numero2.longitud)
		longitud_total = longitud;
	else
		longitud_total = numero2.longitud;
		
	i = longitud_total;

	while(i != -1){
		if(a == -1)
			suma.cifras[i] += numero2.cifras[b];
		else
			if(b == -1)
				suma.cifras[i] += cifras[a];
			else
				suma.cifras[i] += cifras[a] + numero2.cifras[b];
						
		if(((suma.cifras[i] / 10) > 0) && i > 0){
				suma.cifras[i - 1] += suma.cifras[i] / 10;
				suma.cifras[i] = suma.cifras[i] % 10;
		}
			
			i--;
			a--;
			b--;	
	}

	suma.EstablecerLongitud(longitud_total);
	suma.EstablecerCifras(suma.cifras, longitud_total);
	
	cout << "\n\t Suma = ";
	
	return suma;
}

EnteroLargo EnteroLargo::Restar(EnteroLargo &numero2){
	EnteroLargo resta;
	int longitud_total;
	int a = longitud, b = numero2.longitud, i;
	
	/*
		Algoritmo:
		
		Si el numero de cifras de numero1 es mayor o igual que el de numero2,
		entonces el numero de cifras de la resta de ambos numeros sera
		igual al numero de cifras de numero1.
		Si no, el numero de cifras de la resta de ambos numeros sera
		igual al numero de cifras de numero2.
			
		Mientras el numero de cifras de la resta sea distinto de -1:
		
			Si el numero de cifras de numero1 es -1, entonces la cifra
			correspondiente de resta sera igual a la correspondiente cifra de numero2.
			Si no, entonces:
			
				Si el numero de cifras de numero2 es -1, entonces la cifra
				correspondiente de resta sera igual a la correspondiente cifra de numero1.
				Si no, entonces la cifra correspondiente de resta sera igual a la 
				resta de las correspondientes cifras de numero1 y numero2.
				
			Si al dividir una cifra de la resta por 10 el resultado es mayor que 0,
			entonces a la cifra anterior de la resta se le suma el resultado de dicha
			division y la cifra pasa a tomar el valor del resto de dividir ella misma
			por 10. 
				
			Se reducen el numero de cifras de la resta, el numero de cifras de numero1
			y el numero de cifras de numero2 en 1.
			
		Se establecen la longitud y la secuencia de cifras en el objeto resta.
		
		Se devuelve el objeto resta.	
	*/
	
	if(longitud >= numero2.longitud)
		longitud_total = longitud;
	else
		longitud_total = numero2.longitud;
		
	i = longitud_total;
	
	while(i != -1){
		if(a == -1)
			resta.cifras[i] += numero2.cifras[b];
		else
			if(b == -1)
				resta.cifras[i] += cifras[a];
			else
				resta.cifras[i] += cifras[a] - numero2.cifras[b];
						
		if(((resta.cifras[i] / 10) > 0) && i > 0){
				resta.cifras[i - 1] += resta.cifras[i] / 10;
				resta.cifras[i] = resta.cifras[i] % 10;
		}
			
			i--;
			a--;
			b--;	
	}

	resta.EstablecerLongitud(longitud_total);
	resta.EstablecerCifras(resta.cifras, longitud_total);
	
	cout << "\n\t Resta = ";
	
	return resta;
}
