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
#include "graph.h"

using namespace std;

int main(){
    string g_ans;
    Graph g;
    g.loadGraphList("MetroRoma.txt", 73, 73);
    cout << endl << "\t\tAndrea Piñeiro Cavazos A01705681\t\t" << endl;
    cout << "\t\t\tMETRO DE ROMA\t\t\t" << endl << endl;


    cout << "PRUEBA 1: OPCIÓN 2 CONECCIONES DESDE UNA PARADA" << endl;
    cout << "\tEstación: Asf  (No existe)\t\t" << endl;
    g_ans = "\tLa estación no existe";
    cout << " 1 " << (!g_ans.compare(g.connectionsFromOrigin("Asf")) ? "success\n" : "fail\n") << endl << endl;

    cout << "PRUEBA 2: OPCIÓN 3 OBTENER CAMINO DE UN PUNTO A OTRO" << endl;
    cout << "\tOrigen: Ottava (No existe)\t\t" << endl;
    cout << "\tDestino: Termi (No existe)\t\t" << endl;
    g_ans = "\tLas estaciones no existen.";
    cout << " 2 " << (!g_ans.compare(g.DFS("Ottava", "Termi")) ? "success\n" : "fail\n") << endl << endl;

    cout << "PRUEBA 3: OPCIÓN 2 CONECCIONES DESDE UNA PARADA" << endl;
    cout << "\tEstación: Colosseo\t\t" << endl;
    g_ans = "Vertex Colosseo : Venezia, Amba Aradam, Cavour, Circo Massimo\n";
    cout << " 3 " << (g_ans.compare(g.connectionsFromOrigin("Colosseo")) ? "success\n" : "fail\n") << endl << endl;

    cout << "PRUEBA 4: OPCIÓN 3 OBTENER CAMINO DE UN PUNTO A OTRO" << endl;
    cout << "\tOrigen: Ottaviano\t\t" << endl;
    cout << "\tDestino: San Giovanni\t\t" << endl;
    g_ans = " Path: Ottaviano, Risorgimento, San Pietro, Chiesa Nuova, Venezia, Colosseo, Cavour, Termini, Vittorio Emanuele, Manzoni, San Giovanni.";
    cout << " 4 " << (g_ans.compare(g.DFS("Ottaviano", "San Giovanni")) ? "success\n" : "fail\n") << endl << endl;

    cout << "PRUEBA 5: OPCIÓN 4 OBTENER CAMINO MÁS CORTO DE UN PUNTO A OTRO" << endl;
    cout << "\tOrigen: Ottaviano\t\t" << endl;
    cout << "\tDestino: San Giovanni\t\t" << endl;
    g_ans = " Path: Ottaviano, Risorgimento, San Pietro, Chiesa Nuova, Venezia, Colosseo, Amba Aradam, San Giovanni.";
    cout << " 5 " << (g_ans.compare(g.BFS("Ottaviano", "San Giovanni")) ? "success\n" : "fail\n") << endl << endl;

    cout << "PRUEBA 6: OPCIÓN 4 OBTENER CAMINO MÁS CORTO DE UN PUNTO A OTRO" << endl;
    cout << "\tOrigen: Cipro\t\t" << endl;
    cout << "\tDestino: Tiburtina\t\t" << endl;
    g_ans = " Path: Cipro, Ottaviano, Lepanto, Barberini Fontana di Trevi, Spagna, Barberini, Repubblica, Termini, Castro Pretorio, Policlinico, Tiburtina.";
    cout << " 6 " << (g_ans.compare(g.BFS("Cipro", "Tiburtina")) ? "success\n" : "fail\n") << endl << endl;

    cout << "PRUEBA 7: OPCIÓN 3 OBTENER CAMINO DE UN PUNTO A OTRO" << endl;
    cout << "\tOrigen: Risorgimento\t\t" << endl;
    cout << "\tDestino: Spagna\t\t" << endl;
    g_ans = " Path: Risorgimento, San Pietro, Chiesa Nuova, Venezia, Colosseo, Cavour, Termini, Repubblica, Barberini, Spagna.";
    cout << " 7 " << (g_ans.compare(g.DFS("Risorgimento", "Spagna")) ? "success\n" : "fail\n") << endl << endl;

    cout << "PRUEBA 8: OPCIÓN 4 OBTENER CAMINO MÁS CORTO DE UN PUNTO A OTRO" << endl;
    cout << "\tOrigen: Risorgimento\t\t" << endl;
    cout << "\tDestino: Spagna\t\t" << endl;
    g_ans = " Path: Risorgimento, Ottaviano, Lepanto, Barberini Fontana di Trevi, Spagna.";
    cout << " 8 " << (g_ans.compare(g.BFS("Risorgimento", "Spagna")) ? "success\n" : "fail\n") << endl << endl;
}