/*
 * sorts.h

 *
 *  Created on: 21/09/2020
 *      Author: Andrea Piñeiro Cavazos
 *
 */


#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <list>
using namespace std;


template <class T>
class Sorts {
	public:
		void ordenaSeleccion(vector<T> &original, vector<string> &v2);
		vector<string> busqueda(vector<int>, vector<string>, int , int);
		void mergeSort(vector<string> &, vector<T> &);

	// Funciones privadas, que serán usadas como auxiliares
	private:
		void swap(vector<T>&, int, int);
		void swapString(vector<string>&, int, int);
		int busqBinaria(vector<int>, int, bool);
		void copyArray(vector<string> &, vector<T> &,vector<string> &, vector<T> &, int, int);
		void mergeArray(vector<string> &, vector<T> &,vector<string> &, vector<T> &, int, int, int);
		void mergeSplit(vector<string> &, vector<T> &,vector<string> &, vector<T> &, int, int); 

		
};

// Esta función auxiliar realiza un cambio entre 2 índices del vector;
// el dato del primero pasa al segundo y viceversa. 

// Complejidad: O(1) CONSTANTE
template <class T>
void Sorts<T>::swap(vector<T> &original, int x, int y){
	int temp = original[x];
	original[x] = original[y];
	original[y] = temp;
}

// Esta función hace lo mismo pero con un vector de strings
template <class T>
void Sorts<T>::swapString(vector<string> &original, int x, int y){
	string temp = original[x];
	original[x] = original[y];
	original[y] = temp;
}


// Está función implementa el algoritmo SelectionSort, en el cual
// se recorre el arreglo, se busca el elemento más pequeño de todo arreglo
// y después se le coloca en la primera posición.
// Recibe el vector y lo devuelve ordenado

// Complejidad: O(n^2) CUADRÁTICA
template <class T>
void Sorts<T>::ordenaSeleccion(vector<T> &original, vector<string> &v2){
	int pos;
	for (int i = 0; i < original.size(); i++){
		pos = i;
		for (int j = i; j < original.size(); j++){
			if (original[j] < original[pos]){
				pos = j;
			}
		}
		if (pos != i){
			swap(original, pos, i);
			swapString(v2, pos, i);
		}
	}
}




// Esta función lo que hace es dividir el vector por la mitad, si el número
// en la mitad es igual al número que buscamos, regresamos su índice, pues ya lo
// hemos encontrado. Si es menor llama la función de nuevo desde low hasta mid-1; si es mayor
// la llama desde mid+1 hasta high. 

//Complejidad: O(log (n)) LOGARÍTMICA
template <class T>
int Sorts<T>::busqBinaria(vector<int> original, int x, bool inicial){
	int mid;
	int low = 0;
	int high = original.size() - 1;

	while (low < high){
		mid = (low + high) / 2;
		if(x == original[mid]){
			if (inicial == true){
				if (mid == 0 || original[mid - 1] != x){
					return mid;
				} else {
					high = mid - 1; 
				}
			} else {
				if ((mid == original.size() - 1) || original[mid + 1] != x){
					return mid;
				} else {
					low = mid + 1;
				}
			}
		} else if (x < original[mid]){
			high = mid - 1;
		} else if (x > original[mid]){
			low = mid + 1;
		} 
	}
	return low;
}

// Esta función manda llamar 2 veces la busqueda binaria, para encontrar la posicioón de la
// fecha inicial, y la de la fecha final. Si se encuentran por debajo o exceden el línite muestra
// un mensaje. Si esta dentro del rango, escribe la información en un vector.

// Complejidad: O(n) Debido a que el vector depende del rango n de datos dentro de las fechas que 
// hayamos declarado.
template <class T>
vector<string> Sorts<T>::busqueda(vector<int> fecha, vector<string> inf, int fechaInicial, int fechaFinal){
    vector<string> range;
    int posInicial, posFinal;
    posInicial = busqBinaria(fecha, fechaInicial, true);
    posFinal = busqBinaria(fecha, fechaFinal, false);
    cout << endl;

    if (fechaInicial > fecha[fecha.size() - 1]){
        cout << "Las fechas exceden el límite. \n" << endl;
    }
    else if(fechaFinal < fecha[0]){
        cout << "Las fechas están por debajo del límite. \n" << endl;
    }
    else {
    	for (int i = posInicial; i <= posFinal; i++){
    		range.push_back(inf[i]);
    	}
	}

    return range;
}


// Esta función auxiliar recibe dos vectores y dos números, los datos
// entre ambos índices se copian del primero al segundo.

// Complejidad: O(n) LINEAL
template <class T>
void Sorts<T>::copyArray(vector<string> &A, vector<T> &A2,vector<string> &B, vector<T> &B2, int low, int high) {
    for (int i = low ; i <= high ; i++) {
        A2[i] = B2[i];
        A[i] = B[i];
    }
}


// Esta función auxiliar para MergeSort lo que hace es recibir 2 vectores y 3 números; los
// números están divididos entre los datos desde low a mid, y desde mid+1 a high.
// Lo que hace la función es ordenar los datos entre ambos segmentos en el vector B,

// Complejidad: O(log (n) LOGARÍTMICA
template <class T>
void Sorts<T>::mergeArray(vector<string> &A, vector<T> &A2,vector<string> &B, vector<T> &B2, int low, int mid, int high) {
    int i, j, k;
    
    i = low;
    j = mid + 1;
    k = low;

    while(i <= mid && j <= high){
        if(A2[i] < A2[j]){
            B2[k] = A2[i];
            B[k] = A[i];
            i++;
        }else{
            B2[k] = A2[j];
            B[k] = A[j];
            j++;
        }
        k++;
    }
    if (i > mid){
		for(; j <= high; j++){
        	B2[k] = A2[j];
        	B[k] = A[j];
        	k++;
    	}
	} else {
		for(; i <= mid; i++){
        	B2[k] = A2[i];
        	B[k] = A[i];
        	k++;
    	}
	}
}

// Esta función auxiliar para mergeSort, recibe 2 vectores y 2 números; lo que hace es
// dividir en 2 segmentos esa parte del arreglo de forma recursiva, hasta que tengamos 
// 1 solo elemento. Cuando se ha llegado al caso base, se manda llamar a MergeArray para
// ordenar los números y a copyArray para copiarlo en el vector original. 
// La complejidad del split es de O(n), y la de mergeArray que se manda a llamar O(log(n))

// Complejidad del split: O(n) LINEAL
template <class T>
void Sorts<T>::mergeSplit(vector<string> &A, vector<T> &A2,vector<string> &B, vector<T> &B2, int low, int high) {
    int  mid, size, i, j;

	if ((high - low) < 1){
		return;
	} else {
    	mid = low + ((high - low) / 2);
    	mergeSplit(A,A2,B,B2, low, mid);
    	mergeSplit(A,A2,B,B2, mid + 1, high);
    	mergeArray(A,A2,B,B2,low, mid, high);
    	copyArray(A,A2,B,B2, low, high);
	}
}

// Función que realiza el algoritmo de sort, haciendo 2 copias del vector
template <class T>
void Sorts<T>::mergeSort(vector<string> &A, vector<T> &A2) {
	vector<string> B(A.size());
	vector<T> B2(A2.size());
	mergeSplit(A,A2, B,B2 ,0, A2.size() - 1);
}

#endif