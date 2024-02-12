/*
	Ejercicio 7: Programa que, dado un año, un mes y un dia
				    de entrada, muestra en pantalla si la fecha
				    indicada es valida o no.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>

using namespace std;

// Funcion que comprueba si la fecha es valida o no.

bool FechaValida (int anio, int mes, int dia){
   bool mes_valido = mes >= 1 && mes <= 12;
   bool dia_valido_normal = dia >= 1 && dia <= 28;
   bool valido_normal = mes_valido && dia_valido_normal;
    
   bool anio_bisiesto = (anio % 4 == 0) || ((anio % 100 != 0) && (anio % 400 == 0));
   bool mes_tiene_dia_31 = (dia == 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12 );
   bool mes_tiene_dia_30 = (dia == 30) && (mes != 2) && mes_valido;
   bool mes_tiene_dia_29 = (dia == 29) && (mes != 2) && mes_valido;
   bool mes_2_tiene_dia_29_anio_bisiesto = (dia == 29) && (mes == 2) && anio_bisiesto;
    
   bool fecha_valida = valido_normal || mes_tiene_dia_31 || mes_tiene_dia_30 || mes_tiene_dia_29 || mes_2_tiene_dia_29_anio_bisiesto;
    
   return fecha_valida;
}

int main(){
   int anio, mes, dia;
    
   cout << " Introduzca una fecha:";
    
   cout << "\n\n\t Dia: ";
   cin >> dia;

   cout << "\t Mes: ";
   cin >> mes;

   cout << "\t Año: ";
   cin >> anio;   
    
   if(FechaValida(anio,mes,dia))
   	cout << "\n La fecha introducida es valida" << endl << endl;
   else
   	cout << "\n La fecha introducida no es valida" << endl << endl;
   	
	system("pause");
}
