/*
 * sorts.h

 *
 *  Created on: 21/09/2020
 *      Author: Andrea Piñeiro Cavazos
 *
 *  Programa que ordena y permite buscar en un rango de fechas, 
 *  las asistencias al programa de entrenamiento en línea BBFIT.
 *
 *  Casos de prueba incluidos al final
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "sorts.h"

using namespace std;

// Esta función convierte una string a entero
int stringToInt(string i){
	int x;
	x = stoi(i);
	return x;
}

// De las líneas que lee separa "02/06/20" en día, mes y año; como valor a ordenar
// multiplica el año por 10000 mas el mes por 100, de esta manera tenemos 2 dígitos para 
// sumar el día
int dateToInt(string line){
	string dia, mes, año;
	dia = line.substr(0,2);
	mes = line.substr(3,2);
	año = line.substr(6,2);
	int val = stringToInt(año) * 10000 + stringToInt(mes) * 100 + stringToInt(dia);
	return val;
}

// Llena 2 vectores, uno con toda la información, otra con las fechas
// convertidas a número de cada fila
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

// Esta función escribe los resultados en un nuevo archivo .txt
void newTxt(vector<string> v){
	ofstream file("Datos.txt");
	for (int i = 0; i < v.size(); i++){
		file << v[i] << endl;
	}
	file.close();
}


int main(){
	int año, mes, dia, fechaIni, fechaFin;
	string fechaIniStr, fechaFinStr; 
	vector<string> info;
	vector<int> fechas;
	fill(info, fechas);
	Sorts<int> sorts;
	// En este caso use merge sort, sin embargo también se podría hacer con insertion sort.
	sorts.mergeSort(info, fechas);

	cout << endl << "Andrea Piñeiro Cavazos A01705681" << endl;
	int opcion = 0;
	// Se presentan 3 opciones al usuario
	while (opcion != 3){
		cout << "\t\t\tOpciones:\t\t\t" << endl;
		cout << "1. Ver los datos ordenados" << endl;
		cout << "2. Buscar por rango" << endl;
		cout << "3. Salir" << endl;
		cin >> opcion;
		cout << endl;

		// En la opción 1 en el .txt se despliega toda la información ordenada por fecha
		if (opcion == 1){
			newTxt(info);
			cout << "Los datos se encuentran en Datos.txt\n\n";

		// En la opción dos permite al usuario ingresar una fecha de inicio y fecha 
		// final, y escribe en el .txt todos los datos dentro de ese rango.
		} else if (opcion == 2){
			cout << "Introduce las fechas con formato:" << endl;
			cout << "\t\tdia/mes/año (Ejemplo 21/07/20)\t\t" << endl;
			cout << "Introduce fecha inicial: ";
			cin >> fechaIniStr;
			fechaIni = dateToInt(fechaIniStr);

			cout << "Introduce fecha final: ";
			cin >> fechaFinStr;
			fechaFin = dateToInt(fechaFinStr);
			vector<string> range = sorts.busqueda(fechas, info, fechaIni, fechaFin);
			newTxt(range);
			cout << "Los datos se encuentran en Datos.txt\n";

		// La opción 3 saca al usuario
		} else if (opcion == 3){
			cout << "Gracias" << endl;
			break;

		// Si el usuario ingresa otro número el sistema muestra error
		} else {
			cout << "Opción inválida" << endl;
		}
	}

}

/* Casos de prueba

Prueba 1 : Opción 2. Buscar por rango
	Fecha inicial: 01/01/20
	Fecha final: 05/01/20

	Resultado: "Las fechas están por debajo del límite."


Prueba 2 : Opción 2. Buscar por rango
	Fecha inicial: 12/12/21
	Fecha final: 15/12/21

	Resultado: "Las fechas exceden el límite."


Prueba 3 : Opción 2. Buscar por rango  (Excede el valor final)
	Fecha inicial: 15/09/20
	Fecha final: 28/09/20

	Resultado: 
	15/09/20,Suriel Martínez Serrano,08:00
	15/09/20,Selma Janett Calleja Jaramillo,08:00
	15/09/20,Raciel Edmundo Escudero Díaz,06:00
	15/09/20,Paloma Ashly Covarrubias Hernández,18:00
	15/09/20,Naydelin Ruíz Hernández,18:00
	15/09/20,Mitzi Yael Porras Pérez,08:00
	15/09/20,Maria Esther Hernandez Diaz,20:00
	15/09/20,María de los Angeles Villanueva Espinosa,08:00
	15/09/20,Marco Antonio Lozada Copca,06:00
	15/09/20,Luba Miriam Laski Covarrubias,18:00
	15/09/20,Julio Sánchez Rámirez,20:00
	15/09/20,Juan Antonio Zavala Manzanares,20:00
	15/09/20,José Antonio Alonso Cervantes,08:00
	15/09/20,Jorge Enrique Vargas Acosta,20:00
	15/09/20,Heberto Vizcaya Barrera,08:00
	15/09/20,Gaston Ceron Munoz,06:00
	15/09/20,Claudia Camacho Carreggio,06:00
	15/09/20,Carla Guzman Illescas,06:00
	15/09/20,Candy Nohemi Calderón Chavarria,06:00
	15/09/20,Axel Ishac Licona Calderón,18:00
	17/09/20,Vianney Alberto Melo Rios,08:00
	17/09/20,Selma Janett Calleja Jaramillo,08:00
	17/09/20,Raciel Edmundo Escudero Díaz,06:00
	17/09/20,Martha Guerrero Olvera,08:00
	17/09/20,María de los Angeles Villanueva Espinosa,08:00
	17/09/20,José Antonio Alonso Cervantes,08:00
	17/09/20,Heberto Vizcaya Barrera,08:00
	17/09/20,Gaston Ceron Munoz,06:00
	17/09/20,Gabriela Morales Mendez,08:00
	17/09/20,Gabriela Barranco Mendoza,08:00
	17/09/20,Claudia Camacho Carreggio,06:00
	17/09/20,Carla Guzman Illescas,06:00
	17/09/20,Candy Nohemi Calderón Chavarria,06:00


Prueba 4 : Opción 2. Buscar por rango  (Excede el valor inicial)
	Fecha inicial: 01/02/20
	Fecha final: 04/03/20

	Resultado:
	02/03/20,María Fernanda Camacho Tovar
	02/03/20,Mayra Alejandra Tovar Gonzalez
	02/03/20,Octavio Montaño Mendoza
	02/03/20,Mario Villarreal Mares
	02/03/20,Maria Teresa de Jesús Barroeta Sanchez
	02/03/20,Luis Alejandro Cortes Rodriguez
	02/03/20,Felipe Ochoa Velasco
	02/03/20,Mario Villarreal Mares
	02/03/20,Elvia Cortazar Martinez
	02/03/20,Gibran Aparicio Cortazar
	02/03/20,Gustavo Aparicio Cortazar
	02/03/20,Zoé Bello Alfaro
	02/03/20,Berenice Alfaro Ponce
	02/03/20,Juan Francisco Bello Jardines
	02/03/20,Angel Zaid Cruz Olivarez
	02/03/20,Angeles Zeydel Olivares
	02/03/20,Luis David Cruz Olivares
	02/03/20,Zoé Bello Alfaro
	02/03/20,Berenice Alfaro Ponce
	02/03/20,Juan Francisco Bello Jardines
	02/03/20,Heidy Ceron Islas
	02/03/20,Diana Jimena Ramirez Ceron
	02/03/20,Sergio Rogelio Pérez Ramírez
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
	02/03/20,Maria Evodia Rios Castañeda
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
	02/03/20,Leonardo Restrepo Muñoz
	02/03/20,Victor Manuel Lopez Medina
	02/03/20,Julio Cesar Hernandez Velasco
	02/03/20,Gaston Ceron Munoz
	02/03/20,Marco Antonio Lozada Copca
	02/03/20,Valerio Ivan Islas Charolet
	02/03/20,Fabiola Hernandez Escudero
	02/03/20,Marco Antonio Baños Rubio
	02/03/20,Carla Guzman Illescas
	02/03/20,Luis Antonio Roldan Bautista
	02/03/20,Jose Luis Marin Gonzalez
	02/03/20,Claudia Camacho Carreggio
	02/03/20,Raciel Edmundo Escudero Díaz
	03/03/20,Julio Alfredo Cornejo Grimaldo
	03/03/20,Manuel
	03/03/20,Jose Daniel Perez Nunez
	03/03/20,Gabriela Morales Mendez
	03/03/20,Alicia Chavarria Lopez
	03/03/20,Leonardo Restrepo Muñoz
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
	03/03/20,Octavio Montaño Mendoza
	03/03/20,María Fernanda Camacho Tovar
	03/03/20,Maria Evodia Rios Castañeda
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
	03/03/20,Maria Teresa de Jesús Barroeta Sanchez
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
	03/03/20,Raciel Edmundo Escudero Díaz
	03/03/20,Aida Hernandez Ramirez
	03/03/20,Melissa Azpeitia Hernandez
	03/03/20,Cesar Israel Acosta Arias
	03/03/20,Valerio Ivan Islas Charolet
	03/03/20,Israel Ulises Hernandez Martinez
	03/03/20,Fabiola Hernandez Escudero
	03/03/20,Marco Antonio Baños Rubio
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
	04/03/20,María Fernanda Camacho Tovar
	04/03/20,Octavio Montaño Mendoza
	04/03/20,Berenice Alfaro Ponce
	04/03/20,Juan Francisco Bello Jardines
	04/03/20,Naoli Alfaro Ponce
	04/03/20,Zoé Bello Alfaro
	04/03/20,Regina Rojas Crespo
	04/03/20,Elvia Cortazar Martinez
	04/03/20,Gustavo Aparicio Cortazar
	04/03/20,Gibran Aparicio Cortazar
	04/03/20,Jose Manuel Gachuz Moreno
	04/03/20,Magali Citlalli Reyes Garcia
	04/03/20,Celinn Mirell Gutierrez Rodriguez
	04/03/20,Andrea Cortes Barroeta
	04/03/20,Maria Teresa de Jesús Barroeta Sanchez
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
	04/03/20,Raciel Edmundo Escudero Díaz
	04/03/20,Claudia Camacho Carreggio
	04/03/20,Fabiola Hernandez Escudero
	04/03/20,Aida Hernandez Ramirez
	04/03/20,Julio Alfredo Cornejo Grimaldo
	04/03/20,Marco Antonio Baños Rubio
	04/03/20,Julio Cesar Hernandez Velasco
	04/03/20,Jorge Eduardo Vargas Cortes
	04/03/20,Victor Manuel Lopez Medina
	04/03/20,Alicia Chavarria Lopez
	04/03/20,Pablo Manuel Gayosso Chavez
	04/03/20,Vianney Alberto Melo Rios
	04/03/20,Gabriela Morales Mendez
	04/03/20,Leonardo Restrepo Muñoz
	04/03/20,Eduardo Gonzalez Suarez
	04/03/20,Guadalupe Myriam Romero Gomez
	04/03/20,Maria Concepcion Avila Martinez
	04/03/20,Eduardo Gonzalez Suarez


Prueba 5: Opción 2. Buscar por rango
	Fecha inicial: 10/07/20
	Fecha final: 11/07/20

	Resultado:
	10/07/20,Claudia Camacho Carreggio
	10/07/20,Raciel Edmundo Escudero Díaz
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
	10/07/20,Zoé Bello Alfaro
	10/07/20,Berenice Alfaro Ponce
	10/07/20,Juan Francisco Bello Jardines
	10/07/20,Axel Ishac Licona Calderón
	10/07/20,Luba Miriam Laski Covarrubias
	10/07/20,Maria Teresa de Jesús Barroeta Sanchez
	10/07/20,Luis Alejandro Cortes Rodriguez
	10/07/20,Magali Citlalli Reyes Garcia
	10/07/20,Adrian Cortés Barroeta
	10/07/20,Andrea Cortes Barroeta
	10/07/20,Diego Alberto Ramirez Ceron
	11/07/20,Raciel Edmundo Escudero Díaz
	11/07/20,Claudia Camacho Carreggio
	11/07/20,Carla Guzman Illescas
	11/07/20,Sandra Karina Tapia Navarrete
	11/07/20,Marco Antonio Baños Rubio
	11/07/20,Adolfo Miguel Pontigo Tovar
	11/07/20,Maria Concepcion Avila Martinez
	11/07/20,Karen Danae Ávila Mártínez
*/
