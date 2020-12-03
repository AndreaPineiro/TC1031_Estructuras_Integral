/*
 *  Created on: 22/11/2020
 *      Author: Andrea Pineiro Cavazos
 *
 *  Programa que contiene los casos de prueba para 
 *  las asistencias al programa de entrenamiento en linea BBFIT.
 *  
 *  Casos de prueba incluidos al final
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
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


string opcion2(Sorts<int> &sorts, vector<int> &fechas, vector<string> &info, string ini, string fin){
	stringstream aux;
	aux.str("");
	//string res = "";
	int fechaIni = dateToInt(ini);
	int fechaFin = dateToInt(fin);

	vector<string> range = sorts.busqueda(fechas, info, fechaIni, fechaFin);

	for (int i = 0; i < range.size(); i++){
		aux << range[i] << "\n";
	}
	//return res;
	return aux.str();

}

int main(){
	// Inicializamos todas las variables que vamos a usar
	string ans = "";
	string prueba = "";
	stringstream aux1;
	stringstream aux2;

	
	int anio, mes, dia, fechaIni, fechaFin;
	string fechaIniStr, fechaFinStr;
	vector<string> info;
	vector<int> fechas;

	// Leemos el archivo "csv" para obtener todos los datos de las asistencias
	string line;
    ifstream lee ("AsistenciasBBFIT.csv");

	if (lee.is_open()){
		 while (getline(lee, line)){
			if (line[0] != ','){
				info.push_back(line);
				fechas.push_back(dateToInt(line));
			}
		} 
		lee.close();
	}
	else {
		cout << "Unable to open file";
	}

	Sorts<int> sorts;
	// Se ordena el vector por fecha
	sorts.mergeSort(info, fechas);



	cout << endl << "\t\tAndrea Pineiro Cavazos A01705681\t\t" << endl;
	cout << "\t\t\tASISTENCIAS BBFIT HOME\t\t\t" << endl << endl;

	
	// Se prueba la opción 1, para mostrar los datos ordenados por
	// fecha.
	cout << "PRUEBA 1: DATOS ORDENADOS EN EL TXT" << endl;
	
	// Leemos el archivo con la respuesta correcta y lo guardamos en 
	// una string.
	ifstream arch ("OrdenadoForTest.txt");
	if (arch.is_open()){
		 while (getline(arch, line)){
			if (line[0] != ','){
				aux1 << line << ", ";
				//ans.push_back(line);;
			}
		} 
		arch.close();
	}
	else {
		cout << "Unable to open file";
	}
	ans = aux1.str();

	// Añadimos cada elemento del vector a la string que vamos a 
	// comparar con el resultado real. 
	for (int i = 0; i < info.size(); i++){
		aux2 << info[i] << ", ";
	}
	prueba = aux2.str();


    cout << "\t\t1 " << (!ans.compare(prueba) ? "success\n" : "fail\n") << "\t\t";


    // Se prueba la opción 2, para mostrar las asistencias en un rango
	// de fechas. En esta prueba las fechas estan debajo del límite.
	cout << endl << "PRUEBA 2: BUSCAR POR RANGO";
	fechaIniStr = "01/01/20";
	fechaFinStr = "05/01/20";
	cout << endl;
	cout << "\tFechaIni = 01/01/20\t\t" << endl;
	cout << "\tFechaFin = 05/01/20\t\t" << endl;


	ans = "";
	prueba = opcion2(sorts, fechas, info, fechaIniStr, fechaFinStr);

	cout << "\t\t2 " << (!ans.compare(prueba) ? "success\n" : "fail\n") << "\t\t";


	// Se prueba la opción 2, para mostrar las asistencias en un rango
	// de fechas. En esta prueba las fechas exceden el límite.
	cout << endl << "PRUEBA 3: BUSCAR POR RANGO";
	fechaIniStr = "12/12/21";
	fechaFinStr = "15/12/21";
	cout << endl;
	cout << "\tFechaIni = 12/12/21\t\t" << endl;
	cout << "\tFechaFin = 15/12/21\t\t" << endl;

	ans = "";
	prueba = opcion2(sorts, fechas, info, fechaIniStr, fechaFinStr);

	cout << "\t\t3 " << (!ans.compare(prueba) ? "success\n" : "fail\n") << "\t\t";


	// Se prueba la opción 2, para mostrar las asistencias en un rango
	// de fechas. 
	cout << endl << "PRUEBA 4: BUSCAR POR RANGO";
	fechaIniStr = "15/09/20";
	fechaFinStr = "28/09/20";
	cout << endl;
	cout << "\tFechaIni = 15/09/20\t\t" << endl;
	cout << "\tFechaFin = 28/09/20\t\t" << endl;
	ans = "15/09/20,Suriel Martinez Serrano,08:00\n15/09/20,Selma Janett Calleja Jaramillo,08:00\n15/09/20,Raciel Edmundo Escudero Diaz,06:00\n15/09/20,Paloma Ashly Covarrubias Hernandez,18:00\n15/09/20,Naydelin Ruiz Hernandez,18:00\n15/09/20,Mitzi Yael Porras Perez,08:00\n15/09/20,Maria Esther Hernandez Diaz,20:00\n15/09/20,Maria de los Angeles Villanueva Espinosa,08:00\n15/09/20,Marco Antonio Lozada Copca,06:00\n15/09/20,Luba Miriam Laski Covarrubias,18:00\n15/09/20,Julio Sanchez Ramirez,20:00\n15/09/20,Juan Antonio Zavala Manzanares,20:00\n15/09/20,Jose Antonio Alonso Cervantes,08:00\n15/09/20,Jorge Enrique Vargas Acosta,20:00\n15/09/20,Heberto Vizcaya Barrera,08:00\n15/09/20,Gaston Ceron Munoz,06:00\n15/09/20,Claudia Camacho Carreggio,06:00\n15/09/20,Carla Guzman Illescas,06:00\n15/09/20,Candy Nohemi Calderon Chavarria,06:00\n15/09/20,Axel Ishac Licona Calderon,18:00\n17/09/20,Vianney Alberto Melo Rios,08:00\n17/09/20,Selma Janett Calleja Jaramillo,08:00\n17/09/20,Raciel Edmundo Escudero Diaz,06:00\n17/09/20,Martha Guerrero Olvera,08:00\n17/09/20,Maria de los Angeles Villanueva Espinosa,08:00\n17/09/20,Jose Antonio Alonso Cervantes,08:00\n17/09/20,Heberto Vizcaya Barrera,08:00\n17/09/20,Gaston Ceron Munoz,06:00\n17/09/20,Gabriela Morales Mendez,08:00\n17/09/20,Gabriela Barranco Mendoza,08:00\n17/09/20,Claudia Camacho Carreggio,06:00\n17/09/20,Carla Guzman Illescas,06:00\n17/09/20,Candy Nohemi Calderon Chavarria,06:00\n";
	prueba = opcion2(sorts, fechas, info, fechaIniStr, fechaFinStr);
	cout << "\t\t4 " << (ans.compare(prueba) ? "success\n" : "fail\n") << "\t\t";


	// Se prueba la opción 2, para mostrar las asistencias en un rango
	// de fechas.
	cout << endl << "PRUEBA 4: BUSCAR POR RANGO";
	fechaIniStr = "10/07/20";
	fechaFinStr = "11/07/20";
	cout << endl;
	cout << "\tFechaIni = 10/07/20\t\t" << endl;
	cout << "\tFechaFin = 11/07/20\t\t" << endl;
	ans = "10/07/20,Zoe Bello Alfaro,19:30\n10/07/20,Ximena Shady Godinez Garrido,10:00\n10/07/20,Vianney Alberto Melo Rios,08:00\n10/07/20,Selma Janett Calleja Jaramillo,06:30\n10/07/20,Raciel Edmundo Escudero Diaz,06:30\n10/07/20,Maria Teresa de Jesus Barroeta Sanchez,19:30\n10/07/20,Magali Citlalli Reyes Garcia,19:30\n10/07/20,Luis Alejandro Cortes Rodriguez,19:30\n10/07/20,Luba Miriam Laski Covarrubias,19:30\n10/07/20,Julio Cesar Hernandez Velasco,08:00\n10/07/20,Juan Francisco Bello Jardines,19:30\n10/07/20,Ivan Oyervides Vega,08:00\n10/07/20,Gaston Ceron Munoz,06:30\n10/07/20,Gabriela Morales Mendez,08:00\n10/07/20,Diego Alberto Ramirez Ceron,19:30\n10/07/20,Claudia Camacho Carreggio,06:30\n10/07/20,Carla Guzman Illescas,06:30\n10/07/20,Berenice Alfaro Ponce,19:30\n10/07/20,Axel Ishac Licona Calderon,19:30\n10/07/20,Andrea Cortes Barroeta,19:30\n10/07/20,Alma Thais Godinez Garrido,10:00\n10/07/20,Adrian Cortes Barroeta,19:30\n10/07/20,Adolfo Miguel Pontigo Tovar,10:00\n11/07/20,Sandra Karina Tapia Navarrete,08:00\n11/07/20,Raciel Edmundo Escudero Diaz,08:00\n11/07/20,Maria Concepcion Avila Martinez,10:00\n11/07/20,Marco Antonio Banos Rubio,08:00\n11/07/20,Karen Danae Avila Martinez,10:00\n11/07/20,Claudia Camacho Carreggio,08:00\n11/07/20,Carla Guzman Illescas,08:00\n11/07/20,Adolfo Miguel Pontigo Tovar,10:00\n";
	prueba = opcion2(sorts, fechas, info, fechaIniStr, fechaFinStr);
	cout << "\t\t5 " << (ans.compare(prueba) ? "success\n" : "fail\n") << "\t\t";


}