Andrea Piñeiro Cavazos

Este programa recibe datos del txt "Cuponeras" en este se da la información del número de cuponeras que ha adquirido cada atleta del gimnasio Black Bull Fitness. Estas cuponeras incluyen 4 clases para que el atleta tome. En este registro se guarda la información de cada atleta y el número de cuponeras. Para esta entrega uso una Double Linked List para ordenar los datos con ordena selección. Y esta sirve para guardar los objetos Data y poder hacer las búsquedas por número de cuponeras. 

El programa muestra 3 opciones al usuario.

1. Ver los datos ordenados Esta opción crea un ".txt" donde el usuario puede ver los datos ordenados por número de cuponeras.
2. Buscar por número de cuponeras. Esta opción permite al usuario ingresar el número de cuponeras y muestra todos los usuarios que han adquirido ese número de cuponeras..
3. Salir Saca al usuario del programa.


# Casos de prueba
Se encuentran algunos al final del RADME y del main como comentarios, sin embargo en mainTests.cpp se pueden correr 5 
casos de prueba. 


## DLINK ADD
	** Análisis de complejidad temporal **
	Gracias a previous, la función ya no tiene que recorrer todos los elementos para llegar al final. 
	Este apuntador nos permite llegar directamente, y ligar el "next" del nuevo objeto a 0, y el 
	previous del objeto al "tail" anterior. 
	Para agregar el objeto no hacemos ningún recorrido, lo obtenemos directamente. 
	Complejidad: O(1)

## DLINK FIND(FIRST Y LAST)
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro de la lista anidada hasta llegar al final o 
	al inicio, o hasta encontrar el número dentro de la lista. 
	Para encontrar la primera ocurrencia, empieza desde la cabeza, y para el findLast empieza por la 
	tail.
	Para hacer esto se usa un while que recorre los elementos uno por uno, y los compara con el objeto
	que recibimos. 
	En el peor de los casos, el elemento se encontrará en la última posición de la lista, o no se 
	encontrará; por lo que el algoritmo recorrerá todos los elementos. 
	Complejidad: O(n)


## DLINK GET_OBJECT
	** Análisis de complejidad temporal **
	En este algoritmo, si el índice se encuentra en la primer mitad de los elementos empezamos desde 
	head; si se encuentra en la segunda mitad, empezamos desde el tail. 
	Para hacer esto se usa un while que recorre los elementos hasta llegar a la posición con un apuntador 
	auxiliar 'p', y los compara con el índice que recibimos. Avanza de uno en uno por que se utilizan 
	los apuntadores de cada objeto para llegar al siguiente, o al anterior en dado caso; pero al dividir 
	la lista en 2 la complejidad es O(n/2) que se redondea.
	Complejidad: O(n)

## UPDATE
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro de la lista anidada hasta llegar al índice del 
	elemento que queremos cambiar. 
	En este algoritmo, si el índice se encuentra en la primer mitad de los elementos empezamos desde 
	head; si se encuentra en la segunda mitad, empezamos desde el tail. 
	Para hacer esto se usa un while que recorre los elementos hasta llegar a la posición con un apuntador 
	auxiliar 'p', y los compara con el índice que recibimos. Avanza de uno en uno por que se utilizan 
	los apuntadores de cada objeto para llegar al siguiente, o al anterior en dado caso; pero al dividir 
	la lista en 2 la complejidad es O(n/2) que se redondea.
	Complejidad: O(n)


## REMOVE
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro de la lista anidada hasta llegar al índice del 
	elemento que queremos eliminar.
	Si el índice es el 0, solo cambiamos el apuntador de la cabeza hacia el siguiente elemento. Y el 
	de previous lo apuntamos a 0.
	Si el índice es 1, el apuntador de la cola debe apuntar hacia el previous, y next hacia 0.
	Si se encuentra en algún otro, usa un ciclo for que va desde 1 hasta el índice que queremos encontrar. 
	Recorre los elementos uno por uno con un apuntador auxiliar 'p', y los compara con el índice que 
	recibimos. Cuando nos encontramos con el número anterior al índice, usamos otro apuntador 'q' que 
	apunte al objeto en el índice que queremos eliminar. Cambiamos el apuntador del objeto en p para que 
	vaya hacia el siguiente de q; y eliminamos el objeto al que apunta q.
	El algoritmo avanza de uno en uno por que se utilizan los apuntadores de cada objeto para llegar al 
	siguiente.
	Por lo que el algoritmo recorrerá todos los elementos en el peor de los casos. 
	Complejidad: O(n)


## CLEAR
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro de la lista anidada hasta el final.
	Avanza elemento por elemento usando los apuntadores de cada objeto.
	Esta función llega hasta el final de la lista con un ciclo while. 
	Complejidad: O(n)

## TOSTRING
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro de la lista anidada hasta el final. Avanza 
	elemento por elemento usando los apuntadores de cada objeto para obtener el valor de cada uno y añadirlo 
	a una string con todos los elementos de la lista
	Complejidad: O(n)


## ORDENA SELECCIÓN
	** Análisis de complejidad temporal **
	El primer ciclo es el que determina cuántas veces vamos a tener que recorrer todo el vector; este va 
	desde 0 hasta n, incrementando de 1 en 1. 
	El segundo ciclo va a recorrer cada elemento del vector que no este ya en su posición correcta. Buscará 
	el más pequeño y lo colocará en la posición hasta la izquierda. Este comenzará desde el valor de i 
	(determinado por el primer ciclo) hasta n. 
	Tenemos dos ciclos anidados; los cuáles dependen de n. El segundo ciclo cada vez irá recorriendo 1 menos 
	por lo que la complejidad del algoritmo no es precisamente O(n^2). 
	Matemáticamente tiene una complejidad de ((n * (n + 1)) / 2). Sin embargo, como estamos hablando de Big O, 
	tenemos que irnos al peor de los casos que sería O(n^2). 

# Casos de Prueba

# Prueba 1 : Opcion 1. Ver datos ordenados
	Resultado en Datos.txt:
		Crisalida Yohel Ramirez Rodriguez 1 
		Gabriela Barranco Mendoza 1 
		Gloria Griselda Pedrizuela Arenal 1 
		Jose Daniel Perez Nunez 1 
		Jesus Octavio Olivares Gonzalez 1 
		Jorge Alberto Gonzalez Melendez 1 
		Jorge Armando Paz Estrada 1 
		Marco Antonio Dominguez Lopez 1 
		Martha Guerrero Olvera 1 
		Mitzi Yael Porras Perez 1 
		Navil Marlen Acosta Olvera 1 
		Naydelin Ruiz Hernandez 1 
		Oscar Nashiel Gonzalez Lara 1 
		Regina Rojas Crespo 1 
		Suriel Martinez Serrano 1 
		Zaira Omana Sanchez 1 
		Magali Citlalli Reyes Garcia 2 
		Maria de los Angeles Villanueva Espinosa 2 
		﻿Angel Zaid Cruz Olivarez 2 
		Naoli Alfaro Ponce 2 
		Danya Omana Sanchez 2 
		Angeles Zeydel Olivares Hidalgo 2 
		Juan Francisco Bello Jardines  2 
		Julio Cesar Hernandez Velasco 2 
		Rodrigo Osvaldo Cortes Montiel 2 
		Sergio Rogelio Perez Ramirez  2 
		Valerio Ivan Islas Charolet 2 
		Luis David Cruz Olivarez 2 
		Mario Villarreal Mares  3 
		Berenice Alfaro Ponce  3 
		Luba Miriam Laski Covarrubias 4 
		Axel Ishac Licona Calderon 4 
		Maria Esther Hernandez Diaz 4 


# Prueba 2 : Opcion 2. Buscar por rango
	Valor inicial: -1 // Out of range
	Valor final: 2

	Resultado en Datos.txt: 
		Crisalida Yohel Ramirez Rodriguez 1 
		Gabriela Barranco Mendoza 1 
		Gloria Griselda Pedrizuela Arenal 1 
		Jose Daniel Perez Nunez 1 
		Jesus Octavio Olivares Gonzalez 1 
		Jorge Alberto Gonzalez Melendez 1 
		Jorge Armando Paz Estrada 1 
		Marco Antonio Dominguez Lopez 1 
		Martha Guerrero Olvera 1 
		Mitzi Yael Porras Perez 1 
		Navil Marlen Acosta Olvera 1 
		Naydelin Ruiz Hernandez 1 
		Oscar Nashiel Gonzalez Lara 1 
		Regina Rojas Crespo 1 
		Suriel Martinez Serrano 1 
		Zaira Omana Sanchez 1 
		Magali Citlalli Reyes Garcia 2 
		Maria de los Angeles Villanueva Espinosa 2 
		﻿Angel Zaid Cruz Olivarez 2 
		Naoli Alfaro Ponce 2 
		Danya Omana Sanchez 2 
		Angeles Zeydel Olivares Hidalgo 2 
		Juan Francisco Bello Jardines  2 
		Julio Cesar Hernandez Velasco 2 
		Rodrigo Osvaldo Cortes Montiel 2 
		Sergio Rogelio Perez Ramirez  2 
		Valerio Ivan Islas Charolet 2 

# Prueba 3 : Opcion 2. Buscar por rango
	Valor inicial: 2 
	Valor final: 2

	Resultado en Datos.txt: 
		Magali Citlalli Reyes Garcia 2 
		Maria de los Angeles Villanueva Espinosa 2 
		﻿Angel Zaid Cruz Olivarez 2 
		Naoli Alfaro Ponce 2 
		Danya Omana Sanchez 2 
		Angeles Zeydel Olivares Hidalgo 2 
		Juan Francisco Bello Jardines  2 
		Julio Cesar Hernandez Velasco 2 
		Rodrigo Osvaldo Cortes Montiel 2 
		Sergio Rogelio Perez Ramirez  2 
		Valerio Ivan Islas Charolet 2 


# Prueba 4 : Opcion 2. Buscar por rango
	Valor inicial: -2 // Out of range
	Valor final: -3 // Out of range
	
	Resultado en consola:
		"Los numeros estan por debajo del limite"
