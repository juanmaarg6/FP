/*
	Ejercicio 14: Programa que automatiza la realizacion
	              y correccion de un examen tipo test de una
	              asignatura.
	
	Código fuente realizado por Juan Manuel Rodríguez Gómez.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
	Clase en la que cada objeto de ella representa un
	examen.
*/
class Examen{
	private:
		string asignatura; // Nombre de la asignatura
		vector<string> preguntas; // Preguntas del examen
		vector<char> soluciones; // Soluciones del examen
				
	public:
		/*
			Constructor por defecto.
			
			Parametros: -
			
			Devuelve: -
		*/	
		Examen();

		/*
			Constructor de la clase.
			
			Parametros: asignar_valor (string).
			
			Devuelve: -
		*/			
		Examen(string asignar_valor);
		
		/*
			Funcion que establece una pregunta.
			
			Parametros: -
			
			Devuelve: -
		*/	
		void SetPregunta();
		
		/*
			Funcion que, segun la decision del usuario, establece o no 
			una nueva pregunta.
			
			Parametros: -
			
			Devuelve: -
		*/			
		void NuevaPregunta();

		/*
			Funcion que devuelve el numero total de preguntas del examen.
			
			Parametros: -
			
			Devuelve: -
		*/	
		int NumeroPreguntas();

		/*
			Funcion que devuelve el enunciado de la pregunta.
			
			Parametros: -
			
			Devuelve: -
		*/		
		void GetEnunciado();

		/*
			Funcion que devuelve la respuesta de la pregunta.
			
			Parametros: -
			
			Devuelve: -
		*/				
		void GetRespuesta();

		/*
			Funcion que lee las respuestas de los alumnos en el examen.
			
			Parametros: -
			
			Devuelve: -
		*/	
		vector<char> LeerRespuestas();
		
		/*
			Funcion que devuelve la calificacion del alumno en el examen.
			
			Parametros: -
			
			Devuelve: -
		*/		
		int ObtencionResultados();
};

int main(){
	Examen examen;
	string asignatura;
	
	cout << " Introduzca el nombre de la asignatura: ";
	cin >> asignatura;
	
	examen.SetPregunta();
	
	examen.NuevaPregunta();
	
	cout << "\n Numero total de preguntas: " << examen.NumeroPreguntas();
	
	examen.GetEnunciado();
	
	examen.GetRespuesta();
	
	cout << "\n\n\t Calificacion del alumno: " << examen.ObtencionResultados();
	
	cout << endl << endl;
	system("pause");
}

Examen::Examen(){
}

Examen::Examen(string asignar_valor){
	asignatura = asignar_valor;
}

void Examen::SetPregunta(){
	string pregunta;
	char respuesta = 'a';
	
	cout << "\n Introduzca una pregunta: ";
	cin.ignore();
	getline(cin, pregunta);

	cout << " Introduzca la respuesta asociada a la pregunta: ";
	cin >> respuesta;

	preguntas.push_back(pregunta);
	soluciones.push_back(respuesta);
}

void Examen::NuevaPregunta(){
	string nueva_pregunta;
	char nueva_solucion, continuar;
	
	do{
		do{
			cout << "\n\t ¿Desea introducir otra pregunta? ['S' (Si) // 'N' (No)]: ";
			cin >> continuar;
		}while(continuar != 'S' && continuar != 's' && continuar != 'N' && continuar != 'n');
		
		if(continuar == 'S' || continuar == 's'){
			cout << "\n Introduzca una nueva pregunta: ";
			cin.ignore();
			getline(cin, nueva_pregunta);
			
			cout << " Introduzca la respuesta asociada a la nueva pregunta: ";
			cin >> nueva_solucion;
			
			preguntas.push_back(nueva_pregunta);
			soluciones.push_back(nueva_solucion);
		}
	}while(continuar == 'S' || continuar == 's');
}

int Examen::NumeroPreguntas(){
	return preguntas.size();
}

void Examen::GetEnunciado(){
	int busqueda_pregunta;
	
	do{
		cout << "\n\n Introduzca el numero de la pregunta cuyo enunciado desea mostrar: ";
		cin >> busqueda_pregunta;
	}while(busqueda_pregunta < 0 || busqueda_pregunta > preguntas.size());
	
	cout << "\n\t Enunciado de la pregunta " << busqueda_pregunta << " : " << preguntas[busqueda_pregunta];
}

void Examen::GetRespuesta(){
	int busqueda_respuesta;
	
	do{
		cout << "\n\n Introduzca el numero de la pregunta cuya respuesta desea mostrar: ";
		cin >> busqueda_respuesta;
	}while(busqueda_respuesta < 0 || busqueda_respuesta > soluciones.size());
	
	cout << "\n\t Respuesta de la pregunta " << busqueda_respuesta << ": " << soluciones[busqueda_respuesta];
}

vector<char> Examen::LeerRespuestas(){
	vector<char> soluciones_alumno;
	char respuesta;
	
	cout << "\n\n Introduzca las respuestas de los alumnos a las preguntas proporcionadas anteriormente (X significa no responder)\n";
	
	for(int i = 0; i < NumeroPreguntas(); i++){
		cout << "\n\t Pregunta " << i << ": ";
		cin >> respuesta;
		soluciones_alumno.push_back(respuesta);
	}

	return soluciones_alumno;
}

int Examen::ObtencionResultados(){
	int calificacion = 0;
	vector<char> resultados = LeerRespuestas();
	
	for(int i=0; i<NumeroPreguntas();i++){
		if(soluciones[i] == resultados[i])
			calificacion++;
			
		if(soluciones[i] != resultados[i] && resultados[i] != 'X')
			calificacion--;
	}
	
	if(calificacion < 0)
		calificacion = 0;
		
	return calificacion;
}
