/*

 *
 *  Created on: 21/09/2020
 *      Author: Andrea Pineiro Cavazos
 *
 *  Programa que ordena y permite buscar en un rango de fechas, 
 *  las asistencias al programa de entrenamiento en linea BBFIT.
 *
 *  Casos de prueba incluidos al final
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "sorts.h"

using namespace std;

// Esta funcion convierte una string a entero
int stringToInt(string i){
	int x;
	x = stoi(i);
	return x;
}

// De las lineas que lee separa "02/06/20" en dia, mes y ano; como valor a ordenar
// multiplica el ano por 10000 mas el mes por 100, de esta manera tenemos 2 digitos para 
// sumar el dia
int dateToInt(string line){
	string dia, mes, anio;
	dia = line.substr(0,2);
	mes = line.substr(3,2);
	anio = line.substr(6,2);
	int val = stringToInt(anio) * 10000 + stringToInt(mes) * 100 + stringToInt(dia);
	return val;
}

// Llena 2 vectores, uno con toda la informacion, otra con las fechas
// convertidas a numero de cada fila
void fill(vector<string> &a, vector<int> &b){
    string line;
    ifstream lee ("AsistenciasBBFIT.csv");

	if (lee.is_open()){
		 while (getline(lee, line)){
			if (line[0] != ','){
				a.push_back(line);
				b.push_back(dateToInt(line));
			}
		} 
		lee.close();
	}
	else {
		cout << "Unable to open file";
	}
}

// Esta funcion escribe los resultados en un nuevo archivo .txt
void newTxt(vector<string> v){
	ofstream file("Datos.txt");
	for (int i = 0; i < v.size(); i++){
		file << v[i] << endl;
	}
	file.close();
}


int main(){
	int anio, mes, dia, fechaIni, fechaFin;
	string fechaIniStr, fechaFinStr; 
	vector<string> info;
	vector<int> fechas;
	fill(info, fechas);
	Sorts<int> sorts;
	// En este caso use merge sort, sin embargo tambien se podria hacer con insertion sort.
	sorts.mergeSort(info, fechas);

	cout << endl << "\t\tAndrea Pineiro Cavazos A01705681\t\t" << endl;
	int opcion = 0;
	// Se presentan 3 opciones al usuario
	while (opcion != 3){
		cout << endl << "\t\t\tOpciones:\t\t\t" << endl;
		cout << "1. Ver los datos ordenados" << endl;
		cout << "2. Buscar por rango" << endl;
		cout << "3. Salir" << endl;
		cout << endl;
        cout << "Introduce tu opción: ";
        cin >> opcion;
		cout << endl;

		// En la opcion 1 en el .txt se despliega toda la informacion ordenada por fecha
		if (opcion == 1){
			newTxt(info);
			cout << "Los datos se encuentran en Datos.txt\n\n";

		// En la opcion dos permite al usuario ingresar una fecha de inicio y fecha 
		// final, y escribe en el .txt todos los datos dentro de ese rango.
		} else if (opcion == 2){
			cout << "Introduce las fechas con formato:" << endl;
			cout << "\t\tdia/mes/anio (Ejemplo 21/07/20)\t\t" << endl;
			cout << "Introduce fecha inicial: ";
			cin >> fechaIniStr;
			fechaIni = dateToInt(fechaIniStr);

			cout << "Introduce fecha final: ";
			cin >> fechaFinStr;
			fechaFin = dateToInt(fechaFinStr);
			vector<string> range = sorts.busqueda(fechas, info, fechaIni, fechaFin);
			newTxt(range);
			cout << "Los datos se encuentran en Datos.txt\n\n";

		// La opcion 3 saca al usuario
		} else if (opcion == 3){
			cout << "Gracias" << endl;
			break;

		// Si el usuario ingresa otro numero el sistema muestra error
		} else {
			cout << "Opcion invalida" << endl;
		}
	}

}

/* Casos de prueba

Prueba 1 : Opcion 2. Buscar por rango
	Fecha inicial: 01/01/20
	Fecha final: 05/01/20

	Resultado: "Las fechas estan por debajo del limite."


Prueba 2 : Opcion 2. Buscar por rango
	Fecha inicial: 12/12/21
	Fecha final: 15/12/21

	Resultado: "Las fechas exceden el limite."


Prueba 3 : Opcion 2. Buscar por rango  (Excede el valor final)
	Fecha inicial: 15/09/20
	Fecha final: 28/09/20

	Resultado: 
	15/09/20,Suriel Martinez Serrano,08:00
	15/09/20,Selma Janett Calleja Jaramillo,08:00
	15/09/20,Raciel Edmundo Escudero Diaz,06:00
	15/09/20,Paloma Ashly Covarrubias Hernandez,18:00
	15/09/20,Naydelin Ruiz Hernandez,18:00
	15/09/20,Mitzi Yael Porras Perez,08:00
	15/09/20,Maria Esther Hernandez Diaz,20:00
	15/09/20,Maria de los Angeles Villanueva Espinosa,08:00
	15/09/20,Marco Antonio Lozada Copca,06:00
	15/09/20,Luba Miriam Laski Covarrubias,18:00
	15/09/20,Julio Sanchez Ramirez,20:00
	15/09/20,Juan Antonio Zavala Manzanares,20:00
	15/09/20,Jose Antonio Alonso Cervantes,08:00
	15/09/20,Jorge Enrique Vargas Acosta,20:00
	15/09/20,Heberto Vizcaya Barrera,08:00
	15/09/20,Gaston Ceron Munoz,06:00
	15/09/20,Claudia Camacho Carreggio,06:00
	15/09/20,Carla Guzman Illescas,06:00
	15/09/20,Candy Nohemi Calderon Chavarria,06:00
	15/09/20,Axel Ishac Licona Calderon,18:00
	17/09/20,Vianney Alberto Melo Rios,08:00
	17/09/20,Selma Janett Calleja Jaramillo,08:00
	17/09/20,Raciel Edmundo Escudero Diaz,06:00
	17/09/20,Martha Guerrero Olvera,08:00
	17/09/20,Maria de los Angeles Villanueva Espinosa,08:00
	17/09/20,Jose Antonio Alonso Cervantes,08:00
	17/09/20,Heberto Vizcaya Barrera,08:00
	17/09/20,Gaston Ceron Munoz,06:00
	17/09/20,Gabriela Morales Mendez,08:00
	17/09/20,Gabriela Barranco Mendoza,08:00
	17/09/20,Claudia Camacho Carreggio,06:00
	17/09/20,Carla Guzman Illescas,06:00
	17/09/20,Candy Nohemi Calderon Chavarria,06:00


Prueba 4 : Opcion 2. Buscar por rango  (Excede el valor inicial)
	Fecha inicial: 01/02/20
	Fecha final: 04/03/20

	Resultado:
	02/03/20,Maria Fernanda Camacho Tovar
	02/03/20,Mayra Alejandra Tovar Gonzalez
	02/03/20,Octavio Montano Mendoza
	02/03/20,Mario Villarreal Mares
	02/03/20,Maria Teresa de Jesus Barroeta Sanchez
	02/03/20,Luis Alejandro Cortes Rodriguez
	02/03/20,Felipe Ochoa Velasco
	02/03/20,Mario Villarreal Mares
	02/03/20,Elvia Cortazar Martinez
	02/03/20,Gibran Aparicio Cortazar
	02/03/20,Gustavo Aparicio Cortazar
	02/03/20,Zoe Bello Alfaro
	02/03/20,Berenice Alfaro Ponce
	02/03/20,Juan Francisco Bello Jardines
	02/03/20,Angel Zaid Cruz Olivarez
	02/03/20,Angeles Zeydel Olivares
	02/03/20,Luis David Cruz Olivares
	02/03/20,Zoe Bello Alfaro
	02/03/20,Berenice Alfaro Ponce
	02/03/20,Juan Francisco Bello Jardines
	02/03/20,Heidy Ceron Islas
	02/03/20,Diana Jimena Ramirez Ceron
	02/03/20,Sergio Rogelio Perez Ramirez
	02/03/20,Maria Concepcion Avila Martinez
	02/03/20,Jose Daniel Perez Nunez
	02/03/20,Jose Daniel Garcia Rios
	02/03/20,Jorge Enrique Vargas Acosta
	02/03/20,Oscar Nashiel Gonzalez Lara
	02/03/20,Elba Zuzely Vizcaya Barrera
	02/03/20,Maria Fernanda Alfaro Gonzalez
	02/03/20,Ximena Shady Godinez Garrido
	02/03/20,Alma Thais Godinez Garrido
	02/03/20,Joel Ramirez Ortega
	02/03/20,Jalil Aparicio Cortazar
	02/03/20,Maria Evodia Rios Castaneda
	02/03/20,Norma Aida Pineiro Acosta
	02/03/20,Mario Alberto Mendoza Pineiro
	02/03/20,Ariadna Pineiro Acosta
	02/03/20,Felipe Ochoa Velasco
	02/03/20,Hector Adrian Hernandez Segura
	02/03/20,Deyanira Perez Hernandez
	02/03/20,Oscar Duran Soto
	02/03/20,Julio Alfredo Cornejo Grimaldo
	02/03/20,Carlos Angel Rodriguez Lopez
	02/03/20,Pablo Manuel Gayosso Chavez
	02/03/20,Gabriela Morales Mendez
	02/03/20,Alicia Chavarria Lopez
	02/03/20,Vianney Alberto Melo Rios
	02/03/20,Leonardo Restrepo Munoz
	02/03/20,Victor Manuel Lopez Medina
	02/03/20,Julio Cesar Hernandez Velasco
	02/03/20,Gaston Ceron Munoz
	02/03/20,Marco Antonio Lozada Copca
	02/03/20,Valerio Ivan Islas Charolet
	02/03/20,Fabiola Hernandez Escudero
	02/03/20,Marco Antonio Banos Rubio
	02/03/20,Carla Guzman Illescas
	02/03/20,Luis Antonio Roldan Bautista
	02/03/20,Jose Luis Marin Gonzalez
	02/03/20,Claudia Camacho Carreggio
	02/03/20,Raciel Edmundo Escudero Diaz
	03/03/20,Julio Alfredo Cornejo Grimaldo
	03/03/20,Manuel
	03/03/20,Jose Daniel Perez Nunez
	03/03/20,Gabriela Morales Mendez
	03/03/20,Alicia Chavarria Lopez
	03/03/20,Leonardo Restrepo Munoz
	03/03/20,Jose Juan Aviles Abrego
	03/03/20,Guadalupe Myriam Romero Gomez
	03/03/20,Eduardo Gonzalez Suarez
	03/03/20,Dulce Alheli Torres Rodriguez
	03/03/20,Nathan Mauricio Flores Ponce
	03/03/20,Pablo Manuel Gayosso Chavez
	03/03/20,Alma Thais Godinez Garrido
	03/03/20,Maria Fernanda Alfaro Gonzalez
	03/03/20,Elba Zuzely Vizcaya Barrera
	03/03/20,Jose Daniel Garcia Rios
	03/03/20,Alejandro Martinez Rodriguez
	03/03/20,Alba Leticia Badillo Ramirez
	03/03/20,Jalil Aparicio Cortazar
	03/03/20,Hector Adrian Hernandez Segura
	03/03/20,Felipe Ochoa Velasco
	03/03/20,Danya Sanchez Omana
	03/03/20,Mayra Alejandra Tovar Gonzalez
	03/03/20,Octavio Montano Mendoza
	03/03/20,Maria Fernanda Camacho Tovar
	03/03/20,Maria Evodia Rios Castaneda
	03/03/20,Mario Alberto Mendoza Pineiro
	03/03/20,Cristal Torres Torres
	03/03/20,Ariadna Pineiro Acosta
	03/03/20,Oscar Nashiel Gonzalez Lara
	03/03/20,Zaira Sanchez Omana
	03/03/20,Oscar Duran Soto
	03/03/20,Danya Sanchez Omana
	03/03/20,Magali Citlalli Reyes Garcia
	03/03/20,Luis Alejandro Cortes Rodriguez
	03/03/20,Elvia Cortazar Martinez
	03/03/20,Gustavo Aparicio Cortazar
	03/03/20,Gibran Aparicio Cortazar
	03/03/20,Maria Teresa de Jesus Barroeta Sanchez
	03/03/20,Jorge Enrique Vargas Acosta
	03/03/20,Jose Daniel Perez Nunez
	03/03/20,Regina Rojas Crespo
	03/03/20,Berenice Alfaro Ponce
	03/03/20,Juan Francisco Bello Jardines
	03/03/20,Diana Jimena Ramirez Ceron
	03/03/20,Heidy Ceron Islas
	03/03/20,Angeles Zeydel Olivares
	03/03/20,Angel Zaid Cruz Olivarez
	03/03/20,Luis David Cruz Olivares
	03/03/20,Gaston Ceron Munoz
	03/03/20,Marco Antonio Lozada Copca
	03/03/20,Luis Antonio Roldan Bautista
	03/03/20,Claudia Camacho Carreggio
	03/03/20,Carla Guzman Illescas
	03/03/20,Jose Luis Marin Gonzalez
	03/03/20,Raciel Edmundo Escudero Diaz
	03/03/20,Aida Hernandez Ramirez
	03/03/20,Melissa Azpeitia Hernandez
	03/03/20,Cesar Israel Acosta Arias
	03/03/20,Valerio Ivan Islas Charolet
	03/03/20,Israel Ulises Hernandez Martinez
	03/03/20,Fabiola Hernandez Escudero
	03/03/20,Marco Antonio Banos Rubio
	04/03/20,Guadalupe Myriam Romero Gomez
	04/03/20,Dulce Alheli Torres Rodriguez
	04/03/20,Jose Daniel Garcia Rios
	04/03/20,Oscar Nashiel Gonzalez Lara
	04/03/20,Mariana Camacho Ortega
	04/03/20,Efrain Sanchez Becerril
	04/03/20,Maria Fernanda Alfaro Gonzalez
	04/03/20,Elba Zuzely Vizcaya Barrera
	04/03/20,Jalil Aparicio Cortazar
	04/03/20,Alejandro Martinez Rodriguez
	04/03/20,Jorge Enrique Vargas Acosta
	04/03/20,Orlando Jair Lopez Santiago
	04/03/20,Adolfo Miguel Pontigo Tovar
	04/03/20,Oscar Duran Soto
	04/03/20,Danya Sanchez Omana
	04/03/20,Zaira Sanchez Omana
	04/03/20,Mario Villarreal Mares
	04/03/20,Felipe Ochoa Velasco
	04/03/20,Norma Aida Pineiro Acosta
	04/03/20,Ariadna Pineiro Acosta
	04/03/20,Deyanira Perez Hernandez
	04/03/20,Maria Fernanda Camacho Tovar
	04/03/20,Octavio Montano Mendoza
	04/03/20,Berenice Alfaro Ponce
	04/03/20,Juan Francisco Bello Jardines
	04/03/20,Naoli Alfaro Ponce
	04/03/20,Zoe Bello Alfaro
	04/03/20,Regina Rojas Crespo
	04/03/20,Elvia Cortazar Martinez
	04/03/20,Gustavo Aparicio Cortazar
	04/03/20,Gibran Aparicio Cortazar
	04/03/20,Jose Manuel Gachuz Moreno
	04/03/20,Magali Citlalli Reyes Garcia
	04/03/20,Celinn Mirell Gutierrez Rodriguez
	04/03/20,Andrea Cortes Barroeta
	04/03/20,Maria Teresa de Jesus Barroeta Sanchez
	04/03/20,Angeles Zeydel Olivares
	04/03/20,Angel Zaid Cruz Olivarez
	04/03/20,Luis David Cruz Olivares
	04/03/20,Maria Esther Hernandez Diaz
	04/03/20,Diana Jimena Ramirez Ceron
	04/03/20,Valerio Ivan Islas Charolet
	04/03/20,Ulises Alan Carrenno Mejia
	04/03/20,Jose Luis Marin Gonzalez
	04/03/20,Gaston Ceron Munoz
	04/03/20,Israel Ulises Hernandez Martinez
	04/03/20,Carla Guzman Illescas
	04/03/20,Luis Antonio Roldan Bautista
	04/03/20,Marco Antonio Lozada Copca
	04/03/20,Raciel Edmundo Escudero Diaz
	04/03/20,Claudia Camacho Carreggio
	04/03/20,Fabiola Hernandez Escudero
	04/03/20,Aida Hernandez Ramirez
	04/03/20,Julio Alfredo Cornejo Grimaldo
	04/03/20,Marco Antonio Banos Rubio
	04/03/20,Julio Cesar Hernandez Velasco
	04/03/20,Jorge Eduardo Vargas Cortes
	04/03/20,Victor Manuel Lopez Medina
	04/03/20,Alicia Chavarria Lopez
	04/03/20,Pablo Manuel Gayosso Chavez
	04/03/20,Vianney Alberto Melo Rios
	04/03/20,Gabriela Morales Mendez
	04/03/20,Leonardo Restrepo Munoz
	04/03/20,Eduardo Gonzalez Suarez
	04/03/20,Guadalupe Myriam Romero Gomez
	04/03/20,Maria Concepcion Avila Martinez
	04/03/20,Eduardo Gonzalez Suarez


Prueba 5: Opcion 2. Buscar por rango
	Fecha inicial: 10/07/20
	Fecha final: 11/07/20

	Resultado:
	10/07/20,Claudia Camacho Carreggio
	10/07/20,Raciel Edmundo Escudero Diaz
	10/07/20,Carla Guzman Illescas
	10/07/20,Selma Janett Calleja Jaramillo
	10/07/20,Gaston Ceron Munoz
	10/07/20,Ivan Oyervides Vega
	10/07/20,Julio Cesar Hernandez Velasco
	10/07/20,Gabriela Morales Mendez
	10/07/20,Vianney Alberto Melo Rios
	10/07/20,Adolfo Miguel Pontigo Tovar
	10/07/20,Alma Thais Godinez Garrido
	10/07/20,Ximena Shady Godinez Garrido
	10/07/20,Zoe Bello Alfaro
	10/07/20,Berenice Alfaro Ponce
	10/07/20,Juan Francisco Bello Jardines
	10/07/20,Axel Ishac Licona Calderon
	10/07/20,Luba Miriam Laski Covarrubias
	10/07/20,Maria Teresa de Jesus Barroeta Sanchez
	10/07/20,Luis Alejandro Cortes Rodriguez
	10/07/20,Magali Citlalli Reyes Garcia
	10/07/20,Adrian Cortes Barroeta
	10/07/20,Andrea Cortes Barroeta
	10/07/20,Diego Alberto Ramirez Ceron
	11/07/20,Raciel Edmundo Escudero Diaz
	11/07/20,Claudia Camacho Carreggio
	11/07/20,Carla Guzman Illescas
	11/07/20,Sandra Karina Tapia Navarrete
	11/07/20,Marco Antonio Banos Rubio
	11/07/20,Adolfo Miguel Pontigo Tovar
	11/07/20,Maria Concepcion Avila Martinez
	11/07/20,Karen Danae Avila Martinez
*/
