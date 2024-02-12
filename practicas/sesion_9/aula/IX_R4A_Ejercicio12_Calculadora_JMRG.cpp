/*
	Ejercicio 12: Programa que, dados dos numeros naturales
					  y una operacion, muestra el resultado
					  de la operacion aplicada a los dos numeros
					  naturales ya introducidos.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

void MenuOpciones(){
   cout << " Opciones de la calculadora: \n";
   cout << "\t 1. Suma (+)\n";
   cout << "\t 2. Resta (-)\n";
   cout << "\t 3. Multiplicacion (*)\n";
   cout << "\t 4. Division (/)\n";
   cout << "\t 5. MCM (m)\n";
   cout << "\t 6. MCD (d)\n";
}

int Calcular(int num1, char caracter, int num2){
   int resultado = 0;
   
   /*
   	Algoritmo:
   	
   	En funcion del caracter introducido, se realiza
   	una operacion u otra, y almacena el resultado.
   	
   	Devuelve el resultado.
   */
   
   if(caracter == '+')
      resultado = num1 + num2;
   else if(caracter == '-')
      resultado = num1 - num2;
   else if(caracter == '*')
      resultado = num1 * num2;
   else{
      if(num2 == 0){
         cout << "\n Error. No se puede dividir por 0" << endl << endl;
         exit(-1);
      }
      else
         resultado = num1 / num2;
   }
	
   return resultado;
}

int MCM(int num1, int num2){
	int contador = 2, respuesta = 0;
	bool mcm = false;
	
	/*
		Algoritmo:
		
		Mientras no se halle el mcm:
			Se comprueba numero a numero (desde el 2) si
			es divisible por "num1" y "num2".
			
			Si lo es, se ha encontrado el mcm.
			Si no lo es, se pasa al siguiente numero.
			
		Devuelve el mcm.
	*/
	
	while(!mcm){
		mcm = ((contador % num1 == 0) && (contador % num2 == 0));
		
		if(mcm)
			respuesta = contador;
		else
			contador++;
	}
	
	return respuesta;
}

int MCD(int num1, int num2){
   int mcm = 0;
   int mcd = 0;
   
   /*
		Algoritmo:
		
		Se calcula el MCD a partir del mcm. Para ello se usa
		la siguiente propiedad:
			MCM(num1,num2) * MCD(num1,num2) = num1 * num2
			
		Devuelve el MCD
	*/
   
   mcm = MCM(num1, num2);
   
   mcd = (num1 * num2) / mcm;
   
   return mcd;
}

int main(){
   int numero1 = 0, numero2 = 0;
   char operador = 'a';
   bool operador_valido = true;
   
   /*
		Algoritmo:
		
		Se muestran las diferentes operaciones que puede
		realizar la calculadora.
		
		El usuario introduce dos numeros enteros y la
		operacion que desea realizar.
		
		Se realiza la operacion elegida y se muestra
		el resultado en pantalla.
	*/
   
   MenuOpciones();
   
   cout << "\n Introduzca el primer numero entero: ";
   cin >> numero1;
   
   cout << " Introduzca el segundo numero entero: ";
   cin >> numero2;
   
   cout << "\n ¿Que operacion desea realizar? (+, -, *, /, m, d): ";
   cin >> operador;
   
   operador_valido = operador == '+' || operador == '-' || operador == '*' || operador == '/' ||
   operador == 'm' || operador == 'd';
   
   if(!operador_valido){
      cout << "\n Error. No se puede realizar esa operacion en la calculadora" << endl << endl;
      exit(-1);
   }

   if(operador == 'm')
      cout << "\n MCM(" << numero1 << "," << numero2 << ") = " << MCM(numero1, numero2);
   else{
      if(operador == 'd')
      	cout << "\n MCD(" << numero1 << "," << numero2 << ") = " << MCD(numero1, numero2);
      else
         cout << "\n " << numero1 << " " << operador << " " << numero2 << " = " << Calcular(numero1, operador, numero2);
   }
      
   cout << endl << endl;
	
	system("pause");  
}
