/*

 *
 *  Created on: 21/09/2020
 *      Author: Andrea Pineiro Cavazos
 *
 * Casos de prueba para la actividad integral 2
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Dlist.h"
#include "Data.h"

int main(){

	string ans = "";
	string prueba = "";

	// Declaramos variables
	DList<Data> dlist;
	int numInicial, numFinal;
	int posInicial, posFinal;
	
	// Leemos la informacion del archivo de texto dentro de la carpeta
	// con esto creamos un objeto y lo agregamos a la lista doble.
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

    // Usamos Insertion Sort para ordenar la informacion con respecto al numero de cuponeras
	dlist.ordenaSeleccion();

	cout << endl << "\t\tAndrea Pineiro Cavazos A01705681\t\t" << endl;
	cout << "\t\t\tCUPONERAS BLACK BULL\t\t\t" << endl << endl;


		// Se prueba la opción 1, para mostrar los datos ordenados por
	// fecha.
	cout << "PRUEBA 1: DATOS ORDENADOS EN EL TXT" << endl;
	
	stringstream aux1;
	stringstream aux2;

	// Leemos el archivo con la respuesta correcta y lo guardamos en 
	// una string.
	ifstream arch ("OrdenadoForTest.txt");
	if (arch.is_open()){
		 while (getline(arch, line)){
			if (line[0] != ','){
				aux1 << line << "\n";
				//ans.push_back(line);;
			}
		} 
		arch.close();
	}
	else {
		cout << "Unable to open file";
	}
	ans = aux1.str();

	
	for (int i = 0; i < dlist.size; i++){
		aux2 << (dlist.get_obj(i)).toString() << "\n";
	}	
	prueba = aux2.str();

    cout << "\t\t1 " << (!ans.compare(prueba) ? "success\n" : "fail\n") << "\t\t";


    stringstream aux;
    // Se prueba la opción 2 de Buscar por nombre de equipo
	aux.str("");
	cout << endl << "PRUEBA 2: BUSCAR POR RANGO";
	numInicial = -1;
	numFinal = 2;
	cout << endl;

	
	cout << "\tNumero Inicial = -1\t\t" << endl;
	cout << "\tNumero Final = 2\t\t" << endl;

	ans = "Crisalida Yohel Ramirez Rodriguez 1   Gabriela Barranco Mendoza 1   Gloria Griselda Pedrizuela Arenal 1   Jose Daniel Perez Nunez 1   Jesus Octavio Olivares Gonzalez 1   Jorge Alberto Gonzalez Melendez 1   Jorge Armando Paz Estrada 1   Marco Antonio Dominguez Lopez 1   Martha Guerrero Olvera 1   Mitzi Yael Porras Perez 1   Navil Marlen Acosta Olvera 1   Naydelin Ruiz Hernandez 1   Oscar Nashiel Gonzalez Lara 1   Regina Rojas Crespo 1   Suriel Martinez Serrano 1   Zaira Omana Sanchez 1   Magali Citlalli Reyes Garcia 2   Maria de los Angeles Villanueva Espinosa 2   ﻿Angel Zaid Cruz Olivarez 2   Naoli Alfaro Ponce 2   Danya Omana Sanchez 2   Angeles Zeydel Olivares Hidalgo 2   Juan Francisco Bello Jardines  2   Julio Cesar Hernandez Velasco 2   Rodrigo Osvaldo Cortes Montiel 2   Sergio Rogelio Perez Ramirez  2   Valerio Ivan Islas Charolet 2   ";

	// Obtenemos los indices de la posicion inicial y final
   	posInicial = dlist.findFirst(numInicial);
  	posFinal = dlist.findLast(numFinal);
  

 	// Si el valor inicial es mayor al ultimo valor se encuentra fuera del limite
    if (numInicial > (dlist.get_obj(dlist.size - 1)).get_cuponeras()){
    	cout << "Los numeros exceden el limite. \n" << endl;
    }
    		
    // Si el valor final es menor al primer valor se encuentra debajo del limite
    else if(numFinal < (dlist.get_obj(0)).get_cuponeras()){
       	cout << "Los numeros estan por debajo del limite. \n" << endl;
    }

    else {
    	// Si el primer numero no se encuentra, el primer indice sera 0
    	if (numInicial < (dlist.get_obj(0)).get_cuponeras()){
    		posInicial = 0;
    	}

    	// Si el segundo numero no se encuentra el ultimo indice sera el final.
    	if (numFinal > (dlist.get_obj(dlist.size - 1)).get_cuponeras()){
    		posFinal = dlist.size - 1;
    	}

    	
		for (int i = posInicial; i < posFinal; i++){
			aux << (dlist.get_obj(i)).toString() << "  ";
		}
	}
    prueba = aux.str();

	cout << "\t\t2 " << (!ans.compare(prueba) ? "success\n" : "fail\n") << "\t\t";

    // Se prueba la opción 2 de Buscar por nombre de equipo
	aux.str("");
	cout << endl << "PRUEBA 3: BUSCAR POR RANGO";
	numInicial = 2;
	numFinal = 2;
	cout << endl;

	
	cout << "\tNumero Inicial = 2\t\t" << endl;
	cout << "\tNumero Final = 2\t\t" << endl;

	ans = "Magali Citlalli Reyes Garcia 2   Maria de los Angeles Villanueva Espinosa 2   ﻿Angel Zaid Cruz Olivarez 2   Naoli Alfaro Ponce 2   Danya Omana Sanchez 2   Angeles Zeydel Olivares Hidalgo 2   Juan Francisco Bello Jardines  2   Julio Cesar Hernandez Velasco 2   Rodrigo Osvaldo Cortes Montiel 2   Sergio Rogelio Perez Ramirez  2   Valerio Ivan Islas Charolet 2   ";

	// Obtenemos los indices de la posicion inicial y final
   	posInicial = dlist.findFirst(numInicial);
  	posFinal = dlist.findLast(numFinal);
  

 	// Si el valor inicial es mayor al ultimo valor se encuentra fuera del limite
    if (numInicial > (dlist.get_obj(dlist.size - 1)).get_cuponeras()){
    	cout << "Los numeros exceden el limite. \n" << endl;
    }
    		
    // Si el valor final es menor al primer valor se encuentra debajo del limite
    else if(numFinal < (dlist.get_obj(0)).get_cuponeras()){
       	cout << "Los numeros estan por debajo del limite. \n" << endl;
    }

    else {
    	// Si el primer numero no se encuentra, el primer indice sera 0
    	if (numInicial < (dlist.get_obj(0)).get_cuponeras()){
    		posInicial = 0;
    	}

    	// Si el segundo numero no se encuentra el ultimo indice sera el final.
    	if (numFinal > (dlist.get_obj(dlist.size - 1)).get_cuponeras()){
    		posFinal = dlist.size - 1;
    	}

    	
		for (int i = posInicial; i < posFinal; i++){
			aux << (dlist.get_obj(i)).toString() << "  ";
		}
	}
    prueba = aux.str();

	cout << "\t\t3 " << (!ans.compare(prueba) ? "success\n" : "fail\n") << "\t\t";



    // Se prueba la opción 2 de Buscar por nombre de equipo
	aux.str("");
	cout << endl << "PRUEBA 4: BUSCAR POR RANGO";
	numInicial = -2;
	numFinal = -3;
	cout << endl;

	
	cout << "\tNumero Inicial = -2\t\t" << endl;
	cout << "\tNumero Final = -3\t\t" << endl;

	ans = "";

	// Obtenemos los indices de la posicion inicial y final
   	posInicial = dlist.findFirst(numInicial);
  	posFinal = dlist.findLast(numFinal);
  

 	// Si el valor inicial es mayor al ultimo valor se encuentra fuera del limite
    if (numInicial > (dlist.get_obj(dlist.size - 1)).get_cuponeras()){
    	cout << "Los numeros exceden el limite. \n";
    }
    		
    // Si el valor final es menor al primer valor se encuentra debajo del limite
    else if(numFinal < (dlist.get_obj(0)).get_cuponeras()){
       	cout << "Los numeros estan por debajo del limite. \n";
    }

    else {
    	// Si el primer numero no se encuentra, el primer indice sera 0
    	if (numInicial < (dlist.get_obj(0)).get_cuponeras()){
    		posInicial = 0;
    	}

    	// Si el segundo numero no se encuentra el ultimo indice sera el final.
    	if (numFinal > (dlist.get_obj(dlist.size - 1)).get_cuponeras()){
    		posFinal = dlist.size - 1;
    	}

    	
		for (int i = posInicial; i < posFinal; i++){
			aux << (dlist.get_obj(i)).toString() << "  ";
		}
	}
    prueba = aux.str();

	cout << "\t\t4 " << (!ans.compare(prueba) ? "success\n" : "fail\n") << "\t\t";


	// Se prueba la opción 2 de Buscar por nombre de equipo
	aux.str("");
	cout << endl << "PRUEBA 4: BUSCAR POR RANGO";
	numInicial = 6;
	numFinal = 7;
	cout << endl;

	
	cout << "\tNumero Inicial = 6\t\t" << endl;
	cout << "\tNumero Final = 7\t\t" << endl;

	ans = "";

	// Obtenemos los indices de la posicion inicial y final
   	posInicial = dlist.findFirst(numInicial);
  	posFinal = dlist.findLast(numFinal);
  

 	// Si el valor inicial es mayor al ultimo valor se encuentra fuera del limite
    if (numInicial > (dlist.get_obj(dlist.size - 1)).get_cuponeras()){
    	cout << "Los numeros exceden el limite. \n";
    }
    		
    // Si el valor final es menor al primer valor se encuentra debajo del limite
    else if(numFinal < (dlist.get_obj(0)).get_cuponeras()){
       	cout << "Los numeros estan por debajo del limite. \n";
    }

    else {
    	// Si el primer numero no se encuentra, el primer indice sera 0
    	if (numInicial < (dlist.get_obj(0)).get_cuponeras()){
    		posInicial = 0;
    	}

    	// Si el segundo numero no se encuentra el ultimo indice sera el final.
    	if (numFinal > (dlist.get_obj(dlist.size - 1)).get_cuponeras()){
    		posFinal = dlist.size - 1;
    	}

    	
		for (int i = posInicial; i < posFinal; i++){
			aux << (dlist.get_obj(i)).toString() << "  ";
		}
	}
    prueba = aux.str();

	cout << "\t\t5 " << (!ans.compare(prueba) ? "success\n" : "fail\n") << "\t\t";


}