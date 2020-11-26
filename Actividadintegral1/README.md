Andrea Piñeiro Cavazos

En este avance se obtienen los datos de un archivo .csv que contiene las asistencias de los atletlas del gimnasio 
"Black Bull Fitness". En este se encuentra la fecha, el nombre del atleta y la hora en la que asistió. 
En un vector se ordenan estos datos con Ordena Selección por fecha, y te permite ver la información ordenada y 
buscar en un rango de fechas.

# Casos de prueba
Se encuentran algunos al final del main como comentarios, sin embargo en mainTests.cpp se pueden correr 5 
casos de prueba. 

## ORDENA MERGE 
	** Análisis de complejidad temporal **
	Este algoritmo tiene complejidad O(n * log(n)). 
	La función ordenaMerge, tiene complejidad O(1) porque solo manda a llamar la función mergeSplit, que es la 
	que va a llevar a cabo las llamadas recursivas. 
	Para el split la función se va a mandar llamar n veces, pues se parte el vector hasta tener solo 1 elemento. 
	Por lo que su complejidad es O(n).
	Para el merge, no se recorren todos los elementos en cada vuelta; primero se juntan los elementos solos 
	(subconjunto de 1), y después se van juntando cada subconjunto, hasta tener ordenados todos los números. 
	Como los subconjuntos ya están parcialmente ordenados, esta parte es mucho más eficiente; además que al 
	recorreclo como si fuera un árbol, no se recorren todos los elementos. Por lo que el merge tiene 
	complejidad O(log (n)).
	Total: O(n * log(n)).
## ORDENA SELECCIÓN
	** Análisis de complejidad temporal **
	El primer ciclo es el que determina cuántas veces vamos a tener que recorrer todo el vector; este va desde 
	0 hasta n, incrementando de 1 en 1. 
	El segundo ciclo va a recorrer cada elemento del vector que no este ya en su posición correcta. Buscará el 
	más pequeño y lo colocará en la posición hasta la izquierda. Este comenzará desde el valor de i (determinado 
	por el primer ciclo) hasta n. 
