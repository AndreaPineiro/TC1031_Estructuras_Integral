Andrea Piñeiro Cavazos


## ORDENA MERGE 
	** Análisis de complejidad temporal **
	Este algoritmo tiene complejidad O(n * log(n)). 
	La función ordenaMerge, tiene complejidad O(1) porque solo manda a llamar la función mergeSplit, que es la que va a llevar a cabo las llamadas recursivas. 
	Para el split la función se va a mandar llamar n veces, pues se parte el vector hasta tener solo 1 elemento. Por lo que su complejidad es O(n).
	Para el merge, no se recorren todos los elementos en cada vuelta; primero se juntan los elementos solos (subconjunto de 1), y después se van juntando cada subconjunto, hasta tener ordenados todos los números. Como los subconjuntos ya están parcialmente ordenados, esta parte es mucho más eficiente; además que al recorreclo como si fuera un árbol, no se recorren todos los elementos. Por lo que el merge tiene complejidad O(log (n)).
	Total: O(n * log(n)).


## ORDENA SELECCIÓN
	** Análisis de complejidad temporal **
	El primer ciclo es el que determina cuántas veces vamos a tener que recorrer todo el vector; este va desde 0 hasta n, incrementando de 1 en 1. 
	El segundo ciclo va a recorrer cada elemento del vector que no este ya en su posición correcta. Buscará el más pequeño y lo colocará en la posición hasta la izquierda. Este comenzará desde el valor de i (determinado por el primer ciclo) hasta n. 
	Tenemos dos ciclos anidados; los cuáles dependen de n. El segundo ciclo cada vez irá recorriendo 1 menos por lo que la complejidad del algoritmo no es precisamente O(n^2). 
	Matemáticamente tiene una complejidad de ((n * (n + 1)) / 2). Sin embargo, como estamos hablando de Big O, tenemos que irnos al peor de los casos que sería O(n^2). 


## BUSQUEDA BINARIA 
	** Análisis de complejidad temporal **
	El algoritmo recorre log(n) pasos, ya que para encontrar el número en el vector no recorre todo el vector. 
	Obtiene el número de la mitad y lo compara con el número que buscamos, si son iguales, regresamos su índice, pues ya lo hemos encontrado. Si es menor llama la función de nuevo desde low hasta mid-1; si es mayor la llama desde mid+1 hasta high. 
	La función recursiva se detiene cuando se ha encontrado el número o siempre que low sea menor que high. 
	No recorremos todos los números, pues descartamos la mitad de ellos y luego la siguiente mitad...hasta que lo encontremos o lleguemos al caso base.
	Es por eso que la complejidad es O(log(n))
