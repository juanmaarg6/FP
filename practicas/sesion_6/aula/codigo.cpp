// Nombre: Juan Manuel Rodríguez Gómez
// Programa: Desencriptar un código de
//           identificación de una sucursal bancaria.

#include <iostream>

using namespace std;

int main(){
   
   char caracter;
   int digito1, digito2, digito3, digito4, digito5;
   int comienza_mensaje = 0;
   
   const char FIN_CODIGO = '@';
   const char INICIO_FIN_ID_CODIFICADO = '#';
   
   digito1 = digito2 = digito3 = digito4 = digito5 = 0;
   
   /*
      Algoritmo:
      
      Mientras no se introduzca '@':
      	
      	Comprobar si "caracter" es '#'. En ese caso, aumenta "comienzo_mensaje" en 1.
      	
      	Si "comienza_mensaje" es 1, se contabiliza el numero de veces que
      	aparece cada vocal entre el primer '#' y el segundo.
      	
      	Mostrar en pantalla el ID.
      
   */
   
   cout << " Introduzca la secuencia: ";
   cin >> caracter;
   
   while(caracter != FIN_CODIGO){
            
      if(caracter == INICIO_FIN_ID_CODIFICADO)
         comienza_mensaje++;
         
      if(comienza_mensaje == 1){
         switch(caracter){
            case 'a':
               digito1++; 
            break;
            
            case 'e': 
               digito2++;
            break; 
            
            case 'i': 
               digito3++;
            break; 
            
            case 'o': 
               digito4++;
            break; 
            
            case 'u': 
               digito5++;
            break; 
         }
      }
      
		cin >> caracter;
   }
   
   // Si solo se introduce un '#' o ninguno, se mostrara en pantalla "ID: 00000".
   if ( comienza_mensaje < 1 )
		digito1 = digito2 = digito3 = digito4 = digito5 = 0;
		   
   cout << "\n ID: " << digito1 << digito2 << digito3 << digito4 << digito5 << endl << endl;
   
   system("pause");  
}
