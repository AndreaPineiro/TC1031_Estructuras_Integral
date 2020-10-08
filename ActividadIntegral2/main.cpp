// =================================================================
//
// File: main.cpp
// Author: Andrea Piñeiro Cavazos
// Description: Este proyecto añade a una lista ligada los datos
// acerca de los atletas inscritos en el gimnasio Black Bull Fitness
// y el número de cumponeras que han comprado
//
// =================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Dlist.h"
#include "Data.h"

using namespace std;


// Esta función escribe los resultados en un nuevo archivo .txt,
// recibe la lista y dos índices, el inicial y final.
void TxtDatos(DList<Data> d, int ini, int fin){
	ofstream file("Datos.txt");
	for (int i = ini; i < fin; i++){
		file << (d.get_obj(i)).toString() << endl;
	}
	file.close();
}

int main(){
	// Declaramos variables
	DList<Data> dlist;
	int numInicial, numFinal;
	int posInicial, posFinal;
	
	// Leemos la información del archivo de texto dentro de la carpeta
	// con esto creamos un objeto y lo añadimos a la lista doble.
	string line;
    ifstream lee;
    lee.open("Cuponeras.csv");
    
    while(lee.good()){
    	string nombre;
    	string cuponera;

    	getline(lee, nombre, ',');
    	getline(lee, cuponera, '\n');

    	Data dat(nombre, cuponera);
    	dlist.add(dat);
    }

    // Usamos Insertion Sort para ordenar la información con respecto al número de cuponeras
	dlist.ordenaSeleccion();

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

		// En la opción 1 en el .txt se despliega toda la información ordenada por número de cuponeras
		if (opcion == 1){
			TxtDatos(dlist, 0, dlist.size);
			cout << "Los datos se encuentran en Datos.txt\n\n";

		// En la opción dos permite al usuario ingresar un valor de inicio y un valor de fin , 
		// y escribe en el .txt todos los datos dentro de ese rango.
		} else if (opcion == 2){


			cout << "Introduce el valor inicial: ";
			cin >> numInicial;

			cout << "Introduce el valor final: ";
			cin >> numFinal;
			
			// Obtenemos los índices de la posición inicial y final
    		posInicial = dlist.findFirst(numInicial);
    		posFinal = dlist.findLast(numFinal);
    		cout << endl;

    		// Si el valor inicial es mayor al último valor se encuentra fuera del límite
    		if (numInicial > (dlist.get_obj(dlist.size - 1)).get_cuponeras()){
        		cout << "Las fechas exceden el límite. \n" << endl;
    		}
    		
    		// Si el valor final es menor al primer valor se encuentra debajo del límite
    		else if(numFinal < (dlist.get_obj(0)).get_cuponeras()){
        		cout << "Las fechas están por debajo del límite. \n" << endl;
    		}

    		else {
    			// Si el primer número no se encuentra, el primer índice será 0
    			if (numInicial < (dlist.get_obj(0)).get_cuponeras()){
    				posInicial = 0;
    			}

    			// Si el segundo número no se encuentra el último índice será el final.
    			if (numFinal > (dlist.get_obj(dlist.size - 1)).get_cuponeras()){
    				posFinal = dlist.size - 1;
    			}

    			TxtDatos(dlist, posInicial, posFinal);
    			cout << "Los datos se encuentran en Datos.txt\n\n";
    		}
    		

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

/*
	Prueba 1 : Opción 1. Ver datos ordenados
	Resultado:
		Crisalida Yohel Ramirez Rodriguez 1 
		Gabriela Barranco Mendoza 1 
		Gloria Griselda Pedrizuela Arenal 1 
		José Daniel Pérez Núñez 1 
		Jesús Octavio Olivares González 1 
		Jorge Alberto Gonzalez Melendez 1 
		Jorge Armando Paz Estrada 1 
		Marco Antonio Dominguez López 1 
		Martha Guerrero Olvera 1 
		Mitzi Yael Porras Pérez 1 
		Navil Marlén Acosta Olvera 1 
		Naydelin Ruíz Hernández 1 
		Oscar Nashiel Gonzalez Lara 1 
		Regina Rojas Crespo 1 
		Suriel Martínez Serrano 1 
		Zaira Omaña Sánchez 1 
		Magali Citlalli Reyes Garcia 2 
		Maria de los Angeles Villanueva Espinosa 2 
		﻿Angel Zaid Cruz Olivarez 2 
		Naoli Alfaro Ponce 2 
		Danya Omaña Sánchez 2 
		Angeles Zeydel Olivares Hidalgo 2 
		Juan Francisco Bello Jardines  2 
		Julio César Hernández Velasco 2 
		Rodrigo Osvaldo Cortes Montiel 2 
		Sergio Rogelio Pérez Ramírez  2 
		Valerio Iván Islas Charolet 2 
		Luis David Cruz Olivarez 2 
		Mario Villarreal Mares  3 
		Berenice Alfaro Ponce  3 
		Luba Miriam Laski Covarrubias 4 
		Axel Ishac Licona Calderón 4 
		Maria Esther Hernandez Diaz 4 


Prueba 2 : Opción 2. Buscar por rango
	Valor inicial: -1 // Out of range
	Valor final: 2

	Resultado: 
		Crisalida Yohel Ramirez Rodriguez 1 
		Gabriela Barranco Mendoza 1 
		Gloria Griselda Pedrizuela Arenal 1 
		José Daniel Pérez Núñez 1 
		Jesús Octavio Olivares González 1 
		Jorge Alberto Gonzalez Melendez 1 
		Jorge Armando Paz Estrada 1 
		Marco Antonio Dominguez López 1 
		Martha Guerrero Olvera 1 
		Mitzi Yael Porras Pérez 1 
		Navil Marlén Acosta Olvera 1 
		Naydelin Ruíz Hernández 1 
		Oscar Nashiel Gonzalez Lara 1 
		Regina Rojas Crespo 1 
		Suriel Martínez Serrano 1 
		Zaira Omaña Sánchez 1 
		Magali Citlalli Reyes Garcia 2 
		Maria de los Angeles Villanueva Espinosa 2 
		﻿Angel Zaid Cruz Olivarez 2 
		Naoli Alfaro Ponce 2 
		Danya Omaña Sánchez 2 
		Angeles Zeydel Olivares Hidalgo 2 
		Juan Francisco Bello Jardines  2 
		Julio César Hernández Velasco 2 
		Rodrigo Osvaldo Cortes Montiel 2 
		Sergio Rogelio Pérez Ramírez  2 
		Valerio Iván Islas Charolet 2 

Prueba 3 : Opción 2. Buscar por rango
	Valor inicial: 2 // Out of range
	Valor final: 2 // Out of range

	Resultado: 
		Magali Citlalli Reyes Garcia 2 
		Maria de los Angeles Villanueva Espinosa 2 
		﻿Angel Zaid Cruz Olivarez 2 
		Naoli Alfaro Ponce 2 
		Danya Omaña Sánchez 2 
		Angeles Zeydel Olivares Hidalgo 2 
		Juan Francisco Bello Jardines  2 
		Julio César Hernández Velasco 2 
		Rodrigo Osvaldo Cortes Montiel 2 
		Sergio Rogelio Pérez Ramírez  2 
		Valerio Iván Islas Charolet 2 

*/
