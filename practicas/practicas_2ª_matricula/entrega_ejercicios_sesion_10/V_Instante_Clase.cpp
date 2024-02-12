/*
	Relaci�n de ejercicios 5

	Ejercicio 10: Programa que, dado un n�mero de horas, minutos y segundos 
	              iniciales/finales, calcula el n�mero de segundos que hay de 
				  diferencia entre ambos instantes.
				 
				 Para ello se hace uso de la clase Instante.
	              
	Entradas: Instante inicial (hora_inicial, minuto_inicial, segundo_inicial),
	          Instante final (hora_final, minuto_final, segundo_final).
	Salidas: Diferencia entre el instante inicial y el instante final 
	         (instante_diferencia).

	Codigo fuente escrito por Juan Manuel Rodriguez Gomez.
*/

#include <iostream>
#include <string>

using namespace std;

/***************************************************************************/
// Clase Instante: representa un instante de tiempo dentro de un d�a.
/***************************************************************************/
class Instante {
	
	private:
	
		// PRE: 0 <= hora <= 23, 0 <= minuto <= 59, 0 <= segundo <= 59
		int hora;			// Hora del instante
		int minuto;			// Minuto del instante
		int segundo;		// Segundo del instante
		
	public:
	
		/*******************************************************************/
		// Constructor sin par�metros
		/*******************************************************************/
		Instante() {
		
			hora = 0;
			minuto = 0;
			segundo = 0;
		}
		
		/*******************************************************************/
		// Constructor con par�metros
		// PRE: 0 <= valor_hora <= 23, 0 <= valor_minuto <= 59, 
		//      0 <= valor_segundo <= 59
		/*******************************************************************/
		Instante(int valor_hora, int valor_minuto, int valor_segundo)
		        : hora(valor_hora), minuto(valor_minuto), 
				  segundo(valor_segundo) {
			
		}
		
		/*******************************************************************/
		// M�todo: SetHora()
		// Descripci�n: Establece la hora de un instante de tiempo
		// Recibe: Hora de un instante de tiempo (valor_hora)
		// Devuelve: -
		// PRE: 0 <= valor_hora <= 23
		/*******************************************************************/
		void SetHora(int valor_hora) {
			
			hora = valor_hora;
		}
		
		/*******************************************************************/
		// M�todo: SetMinuto()
		// Descripci�n: Establece el minuto de un instante de tiempo
		// Recibe: Minuto de un instante de tiempo (valor_minuto)
		// Devuelve: -
		// PRE: 0 <= valor_minuto <= 59
		/*******************************************************************/
		void SetMinuto(int valor_minuto) {
			
			minuto = valor_minuto;
		}
		
		/*******************************************************************/
		// M�todo: SetSegundo()
		// Descripci�n: Establece el segundo de un instante de tiempo
		// Recibe: Segundo de un instante de tiempo (valor_segundo)
		// Devuelve: -
		// PRE: 0 <= valor_segundo <= 59
		/*******************************************************************/
		void SetSegundo(int valor_segundo) {
			
			segundo = valor_segundo;	
		}
		
		/*******************************************************************/
		// M�todo: GetHora()
		// Descripci�n: Devuelve la hora de un instante de tiempo
		// Recibe: -
		// Devuelve: Hora de un instante de tiempo (hora)
		/*******************************************************************/
		int GetHora() {
			
			return hora;	
		}
		
		/*******************************************************************/
		// M�todo: GetMinuto()
		// Descripci�n: Devuelve el minuto de un instante de tiempo
		// Recibe: -
		// Devuelve: Minuto de un instante de tiempo (minuto)
		/*******************************************************************/
		int GetMinuto() {
			
			return minuto;	
		}
		
		/*******************************************************************/
		// M�todo: GetSegundo()
		// Descripci�n: Devuelve el segundo de un instante de tiempo
		// Recibe: -
		// Devuelve: Segundo de un instante de tiempo (minuto)
		/*******************************************************************/
		int GetSegundo() {
			
			return segundo;	
		}
		
		/*******************************************************************/
		// M�todo: CalcularSegundosDesdeInicio()
		// Descripci�n: Devuelve el n�mero de segundos transcurridos entre un
		//              instante y el instante 0h 0min 0seg
		// Recibe: -
		// Devuelve: Total de segundos entre un instante y el instante
		//           0h 0min 0seg (total_segundos)
		/*******************************************************************/
		int CalcularSegundosDesdeInicio() {
			
			const int MINUTOS_EN_HORA = 60;
			const int SEGUNDOS_EN_MINUTO = 60;
			const int SEGUNDOS_EN_HORA = MINUTOS_EN_HORA * 
			                             SEGUNDOS_EN_MINUTO;
			                              
			int total_segundos = hora * SEGUNDOS_EN_HORA + 
			                     minuto * SEGUNDOS_EN_MINUTO +
			                     segundo;
			                     
			return total_segundos;
		}
		
		/*******************************************************************/
		// M�todo: CalcularMinutosDesdeInicio()
		// Descripci�n: Devuelve el n�mero de minutos transcurridos entre un
		//              instante y el instante 0h 0min 0seg
		// Recibe: -
		// Devuelve: Total de minutos entre un instante y el instante
		//           0h 0min 0seg (total_minutos)
		/*******************************************************************/
		int CalcularMinutosDesdeInicio() {
			
			const int MINUTOS_EN_HORA = 60;
			const int SEGUNDOS_EN_MINUTO = 60;
			const int MINUTOS_EN_SEGUNDO = 1 / SEGUNDOS_EN_MINUTO;
			
			int total_minutos = hora * MINUTOS_EN_HORA +
			                    minuto +
			                    segundo * MINUTOS_EN_SEGUNDO;
			                    
			return total_minutos;
		}
		
		/*******************************************************************/
		// M�todo: CalcularSegundosEntreInstantes()
		// Descripci�n: Devuelve el n�mero de segundos transcurridos entre
		//              dos instantes
		// Recibe: Instante de tiempo (instante)
		// Devuelve: Total de segundos transcurridos entre dos instantes
		//           (total_segundos)
		/*******************************************************************/
		int CalcularSegundosEntreInstantes(Instante instante) {
			
			int segs_entre_inicio_e_instante1 = CalcularSegundosDesdeInicio();
			int segs_entre_inicio_e_instante2 = 
			                            instante.CalcularSegundosDesdeInicio();
			
			int total_segundos = segs_entre_inicio_e_instante2 - 
			                     segs_entre_inicio_e_instante1;
								 			
			return total_segundos;
		}
		
		/*******************************************************************/
		// M�todo: CalcularInstante()
		// Descripci�n: Establece un instante de tiempo a partir del 
		//              n�mero de segundos transcurridos desde el
		//              instante 0h 0min 0seg
		// Recibe: Total de segundos transcurridos  desde el
		//         instante 0h 0min 0seg (total_segundos)
		// Devuelve: -
		/*******************************************************************/
		void CalcularInstante(int total_segundos) {
			
			const int MINUTOS_EN_HORA = 60;
			const int SEGUNDOS_EN_MINUTO = 60;
			const int SEGUNDOS_EN_HORA = MINUTOS_EN_HORA * 
			                             SEGUNDOS_EN_MINUTO;			
										 
			hora = total_segundos / SEGUNDOS_EN_HORA;
			total_segundos %= SEGUNDOS_EN_HORA;
			
			minuto = total_segundos / SEGUNDOS_EN_MINUTO;
			total_segundos %= SEGUNDOS_EN_MINUTO;
			
			segundo = total_segundos;
		}
		
		/*******************************************************************/
		// M�todo: ToString()
		// Descripci�n: Devuelve un string con un instante de tiempo
		//              representado de la forma (hora h : minuto m : segundo s)
		// Recibe: -
		// Devuelve: String con con un instante de tiempo (cad)
		/*******************************************************************/
		string ToString() {
			
			string cad;
			
			cad = "(" + to_string(hora) + " h : " + 
			      to_string(minuto) + " m : " +
			      to_string(segundo) + " s)";
			
			return cad;	
		}
};

/***************************************************************************/
// Funci�n: EliminaPrimerosSeparadores()
// Descripci�n: Devuelve una nueva cadena, resultante de eliminar los 
//              primeros caracteres separadores de "cadena"
// Recibe: String sobre la que se va a trabajar (cadena)
// Devuelve: String resultante de eliminar los primeros separadores de 
//           "cadena" (local)
/***************************************************************************/
string EliminaPrimerosSeparadores(string cadena) {	

	int pos = 0;
	
	int longitud_cadena = cadena.length();
	
	while( ( pos < longitud_cadena ) && ( isspace(cadena.at(pos)) ) ) 
		pos++;
	
	string cadena_resultante; 
	
	while(pos < longitud_cadena) {
		cadena_resultante.push_back(cadena.at(pos));
		pos++;
	}
		
	return cadena_resultante;
}


/***************************************************************************/
// Funci�n: EliminaUltimosSeparadores()
// Descripci�n: Devuelve una nueva cadena, resultante de eliminar los 
//              �ltimos caracteres separadores de "cadena"
// Recibe: String sobre la que se va a trabajar (cadena)
// Devuelve: String resultante de eliminar los �ltimos separadores de 
//           "cadena" (cadena)
/***************************************************************************/
string EliminaUltimosSeparadores(string cadena) {

   	while( ( cadena.length() > 0 ) && ( isspace(cadena.back()) ) )
		cadena.pop_back();
        
	return cadena;
}

/***************************************************************************/
// Funci�n: EliminaSeparadoresInicialesyFinales()
// Descripci�n: Devuelve una nueva cadena, resultante de eliminar los 
//              caracteres separadores iniciales y finales de "cadena"
// Recibe: String sobre la que se va a trabajar (cadena)
// Devuelve: String resultante de eliminar los separadores iniciales y finales
//			 de "cadena" (cadena)
/***************************************************************************/
string EliminaSeparadoresInicialesyFinales(string cadena) {	

	string cadena_resultante = EliminaUltimosSeparadores(
	                        		EliminaPrimerosSeparadores(cadena));
	                        		
	return cadena_resultante; 
}

/***************************************************************************/
// Funci�n: LeeEntero()
// Descripci�n: Lee un n�mero entero
// Recibe: Texto que etiqueta la lectura (titulo).
// Devuelve: N�mero entero (numero).
/***************************************************************************/
int LeeEntero(string titulo) {
	
	string numero;
	bool es_entero = true;
	
	do {
		
		es_entero = true;
		cout << titulo;	

		getline (cin, numero);
		
		int longitud_numero_con_separadores = numero.length();
		
		if(longitud_numero_con_separadores > 0) {
			
			numero = EliminaSeparadoresInicialesyFinales(numero);

			int longitud_numero_sin_separadores = numero.length();
			
			int i = 0;
			
			if( (numero[0] == '-') || (numero[0] == '+') )
				i = 1;
	
			while( (i <longitud_numero_sin_separadores) && es_entero) {
				
				if( (numero[i] < '0') || (numero[i] > '9') )
					es_entero = false;
					
				i++;
			}
		}
		else
			es_entero = false;		

	}while(!es_entero);

	return stoi(numero); 
}

/***************************************************************************/
// Funci�n: LeeEnteroEnRango()
// Descripci�n: Lee un n�mero entero dentro del rango ["menor" , "mayor"]
// Recibe: Texto que etiqueta la lectura (titulo),
//		   Valor m�nimo del rango (menor),
//		   Valor m�ximo del rango (mayor)
// Devuelve: N�mero entero dentro del rango (numero)
/***************************************************************************/
int LeeEnteroEnRango(string titulo, int menor, int mayor) {
	
	int numero; 
	
	do {
		numero = LeeEntero(titulo);		
	}while( (numero < menor) || (numero > mayor) );
	
	return numero;	
}

/***************************************************************************/
// Funci�n: LeeEnteroMayorOIgual()
// Descripci�n: Lee un n�mero entero mayor o igual que "referencia"
// Recibe: Texto que etiqueta la lectura (titulo),
//		   N�mero entero de referencia (referencia)
// Devuelve: N�mero entero mayor o igual que "referencia" (numero)
/***************************************************************************/
int LeeEnteroMayorOIgual(string titulo, int referencia) {
	
	int numero; 
	
	do {
		numero = LeeEntero(titulo);		
	}while(numero < referencia);
	
	return numero;	
}

/***************************************************************************/
// Funci�n principal
/***************************************************************************/
int main() {
	
	// Declaraci�n de variables
	
	int hora_inicial, minuto_inicial, segundo_inicial;
	int hora_final, minuto_final, segundo_final;
	
	// Entradas de datos
	
	// Instante inicial
	
	cout << " Instante inicial: ";
	cout << endl;
	
	hora_inicial = LeeEnteroEnRango("\t Hora: ", 0, 23);
	minuto_inicial = LeeEnteroEnRango("\t Minuto: ", 0, 59);
	segundo_inicial = LeeEnteroEnRango("\t Segundo: ", 0, 59);
	
	// Instante final

	cout << endl;
	cout << " Instante final: ";
	cout << endl;
	
	do {
		hora_final = LeeEnteroEnRango("\t Hora: ", 0, 23);	
	}while(hora_final < hora_inicial);
	
	minuto_final = LeeEnteroEnRango("\t Minuto: ", 0, 59);
	segundo_final = LeeEnteroEnRango("\t Segundo: ", 0, 59);
	
	// C�lculos
	
	// Declaraci�n e inicializaci�n (CONSTRUCTOR) de los objetos 
	// "instante_inicial" e "instante_final"
	// Hemos asegurado el cumplimiento de las precondiciones
	Instante instante_inicial(hora_inicial, minuto_inicial, segundo_inicial);
	Instante instante_final(hora_final, minuto_final, segundo_final);
	
	int segundos_entre_instantes = 
	           instante_inicial.CalcularSegundosEntreInstantes(instante_final);
	
	// Declaraci�n del objeto "instante_diferencia"
	Instante instante_diferencia;
	
	instante_diferencia.CalcularInstante(segundos_entre_instantes);
	
	// Salidas
	
	cout << endl;
	cout << " Instante diferencia: " << instante_diferencia.ToString();
	cout << endl << endl;
	cout << " Hora del instante diferencia: " 
	     << instante_diferencia.GetHora();
	cout << endl;
	cout << " Minuto del instante diferencia: " 
	     << instante_diferencia.GetMinuto();
	cout << endl;
	cout << " Segundo del instante diferencia: " 
	     << instante_diferencia.GetSegundo();
			
	return 0;	
}
