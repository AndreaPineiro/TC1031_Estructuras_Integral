// =================================================================
//
// File: main.cpp
// Author: Andrea Pineiro Cavazos
// Description: Este proyecto implementa grafos usando la información 
// sobre las estaciones del metro de Roma, Italia. Recibe en el documento
// "MetroRoma.txt" las conecciones entre todas las estaciones. 
//  Este programa te permite ver todas las conecciones de todos los nodos,
// o a las estaciones que puedes llegar desde una inicial.
// Así como darte información de por qué estaciones pasar para llegar de una
// a otra, y cuál es el camino más corto.
//
// =================================================================

#include <iostream>
#include <fstream>
#include "graph.h"

using namespace std;

int main(){
    Graph g;
    // We create the adjacency list with the information about the subway
    g.loadGraphList("MetroRoma.txt", 77, 77);
    
    cout << endl << "\t\tAndrea Piñeiro Cavazos A01705681\t\t" << endl;
    cout << "\t\t\tMETRO DE ROMA\t\t\t" << endl << endl;
    int opcion = 0;

    // We show 5 options for the user.
    while (opcion < 5 && opcion > -1){
		cout << "\t\t\tOpciones:\t\t\t" << endl;
		cout << "1. Ver todas las conecciones de cada nodo en un archivo txt" << endl;
		cout << "2. Obtener las conecciones desde una parada" << endl;
        cout << "3. Obtener camino de un punto a otro" << endl;
		cout << "4. Obtener el camino más corto de un punto a otro" << endl;
		cout << "5. Salir" << endl;
		cout << endl;
        cout << "Introduce tu opción: ";
        cin >> opcion;
		cout << endl;

		switch (opcion) {
			// The first option shows every vertex and it's conecctions. It prints it on a txt
            case 1:
                {
                    ofstream file("Conexiones.txt");
		            file << g.printAdjList() << endl;
	                file.close();
                    cout << "Se encuentran en Conexiones.txt" << endl << endl << endl;
                }
            break;

            case 2:
                {
                    // The second option allows you to introduce the name of an
                    // station, and get all the adjacent stations.
                    string ciudad;
                    cout << "Introduce el nombre de la estación: ";
                    cin.ignore();
                    getline(cin, ciudad);
                    cout << endl;
                    if (g.NodeInGraph(ciudad) == false){
                        cout << "\tLa estación no existe" << endl << endl << endl;
                    } else {
                        cout << g.connectionsFromOrigin(ciudad);
                        cout << endl << endl << endl;
                    }
                }
            break;

            case 3:
                {
                    // The third option gives you a path to get from an
                    // initial station to your destiny
                    string origen, destino;
                    cout << "Introduce el nombre de la estación inicial: ";
                    cin.ignore();
                    getline(cin, origen);
                    cout << "Introduce el nombre de la estación de destino: ";
                    getline(cin, destino);
                    cout << endl;
                    if (g.NodeInGraph(origen) == false){
                        cout << "\tLa estación de origen no existe." << endl << endl << endl;
                    } else if (g.NodeInGraph(destino) == false){
                        cout << "\tLa estación de destino no existe." << endl << endl << endl;
                    } else {
                        cout << "\t" << g.DFS(origen, destino) << "\t";
                        cout << endl << endl << endl;
                    }
                }
            break;

            case 4:
                {
                    // The fourth option gives you the shortest path to
                    // get to you destiny.
                    string origen, destino;
                    cout << "Introduce el nombre de la estación inicial: ";
                    cin.ignore();
                    getline(cin, origen);
                    cout << "Introduce el nombre de la estación de destino: ";
                    getline(cin, destino);
                    cout << endl;
                    if (g.NodeInGraph(origen) == false){
                        cout << "\tLa estación de origen no existe." << endl << endl << endl;
                    } else if (g.NodeInGraph(destino) == false){
                        cout << "\tLa estación de destino no existe." << endl << endl << endl;
                    } else {
                        cout << "\t" << g.BFS(origen, destino) << "\t";
                        cout << endl << endl << endl;
                    }
                }
            break;
        }
        if (opcion > 5 || opcion < -1){
			cout << "Opcion invalida" << endl;
		}
    }
    cout << "Gracias" << endl;
}

/*
	Prueba 1 : Opcion 1. Ver todas las conecciones de cada nodo en un archivo txt
		
	ESTO SE ENCUENTRA EN UN ARCHIVO, "CONEXIONES.TXT"

	Resultado:
		vertex Cornelia : Battisini, Baldo del Ubaldi
        vertex Battisini : Cornelia
        vertex Baldo del Ubaldi : Cornelia, Valle Aurelia
        vertex Valle Aurelia : Baldo del Ubaldi, Cipro
        vertex Cipro : Valle Aurelia, Ottaviano
        vertex Ottaviano : Cipro, Lepanto, Clodio Mazzini, Risorgimento
        vertex Lepanto : Ottaviano, Barberini Fontana di Trevi
        vertex Barberini Fontana di Trevi : Lepanto, Spagna
        vertex Spagna : Barberini Fontana di Trevi, Barberini
        vertex Barberini : Spagna, Repubblica
        vertex Repubblica : Barberini, Termini
        vertex Termini : Repubblica, Vittorio Emanuele, Castro Pretorio, Cavour
        vertex Vittorio Emanuele : Termini, Manzoni
        vertex Manzoni : Vittorio Emanuele, San Giovanni
        vertex San Giovanni : Manzoni, Re di Roma, Amba Aradam, Lodi
        vertex Re di Roma : San Giovanni, Ponte Lungo
        vertex Ponte Lungo : Re di Roma, Furio Camillo
        vertex Furio Camillo : Ponte Lungo, Colli Albani
        vertex Colli Albani : Furio Camillo, Arco di Travertino
        vertex Arco di Travertino : Colli Albani, Porta Furba
        vertex Porta Furba : Arco di Travertino, Numidio Quadrato
        vertex Numidio Quadrato : Porta Furba, Lucio Sestio
        vertex Lucio Sestio : Numidio Quadrato, Giulio Agricola
        vertex Giulio Agricola : Lucio Sestio, Subaugusta
        vertex Subaugusta : Giulio Agricola, Cinecittà
        vertex Cinecittà : Subaugusta, Anagnina
        vertex Anagnina : Cinecittà
        vertex Clodio Mazzini : Ottaviano
        vertex Risorgimento : Ottaviano, San Pietro
        vertex San Pietro : Risorgimento, Chiesa Nuova
        vertex Chiesa Nuova : San Pietro, Venezia
        vertex Venezia : Chiesa Nuova, Colosseo
        vertex Colosseo : Venezia, Amba Aradam, Cavour, Circo Massimo
        vertex Amba Aradam : Colosseo, San Giovanni
        vertex Lodi : San Giovanni, Pigneto
        vertex Pigneto : Lodi, Malatesta
        vertex Malatesta : Pigneto, Teano
        vertex Teano : Malatesta, Gardenie
        vertex Gardenie : Teano, Mirti
        vertex Mirti : Gardenie, Parco di Centocelle
        vertex Parco di Centocelle : Mirti, Torre Spaccata
        vertex Torre Spaccata : Parco di Centocelle, Giglioli
        vertex Giglioli : Torre Spaccata, Giardinetti
        vertex Giardinetti : Giglioli
        vertex Torre Angela : Gardinetti, Torre Gaia
        vertex Gardinetti : Torre Angela
        vertex Torre Gaia : Torre Angela, Grotte Celoni
        vertex Grotte Celoni : Torre Gaia, Fontana Candida
        vertex Fontana Candida : Grotte Celoni, Borghesiana
        vertex Borghesiana : Fontana Candida, Bolognetta
        vertex Bolognetta : Borghesiana, Finocchio
        vertex Finocchio : Bolognetta, Graniti
        vertex Graniti : Finocchio, Pantano
        vertex Pantano : Graniti
        vertex Ponte Mammolo : Rebibbia, Santa Maria del Soccorso
        vertex Rebibbia : Ponte Mammolo
        vertex Santa Maria del Soccorso : Ponte Mammolo, Pietralata
        vertex Pietralata : Santa Maria del Soccorso, Monti Tiburtini
        vertex Monti Tiburtini : Pietralata, Quintilliani
        vertex Quintilliani : Monti Tiburtini, Tiburtina
        vertex Tiburtina : Quintilliani, Policlinico
        vertex Policlinico : Tiburtina, Castro Pretorio
        vertex Castro Pretorio : Policlinico, Termini
        vertex Cavour : Termini, Colosseo
        vertex Circo Massimo : Colosseo, Piramide
        vertex Piramide : Circo Massimo, Garbatella
        vertex Garbatella : Piramide, San Paolo Basilica
        vertex San Paolo Basilica : Garbatella, Marconi
        vertex Marconi : San Paolo Basilica, EUR Magliana
        vertex EUR Magliana : Marconi, EUR Palasport
        vertex EUR Palasport : EUR Magliana, EUR Fermi
        vertex EUR Fermi : EUR Palasport, Laurentin
        vertex Laurentin : EUR Fermi



Prueba 2 : Opcion 2. Obtener las conecciones desde una parada
		
        Introduce el nombre de la estación: "Termini"

		CONSOLA RESULTADO:
        Vertex Termini : Repubblica, Vittorio Emanuele, Castro Pretorio, Cavour


Prueba 3 : Opcion 3.  Obtener camino de un punto a otro
	Introduce el nombre de la estación inicial: Ottaviano
    Introduce el nombre de la estación de destino: San Giovanni 

	CONSOLA RESULTADO: 
		Path: Ottaviano, Risorgimento, San Pietro, Chiesa Nuova, Venezia, Colosseo, Cavour, Termini, Vittorio Emanuele, Manzoni, San Giovanni.


Prueba 4 : Opción 4. Obtener el camino más corto de un punto a otro
    Introduce el nombre de la estación inicial: Ottaviano
    Introduce el nombre de la estación de destino: San Giovanni 

    CONSOLA RESULTADO:
        Path: Ottaviano, Risorgimento, San Pietro, Chiesa Nuova, Venezia, Colosseo, Amba Aradam, San Giovanni.

*/