Andrea Piñeiro Cavazos A01705681

Este programa recibe datos del CSV "MetroRoma" en este se da la información de las conecciones de todas las estaciones del metro de Roma. Este programa te permite ver todas las conecciones de todos los nodos,o a las estaciones que puedes llegar desde una inicial. Así como darte información de por qué estaciones pasar para llegar de una a otra, y cuál es el camino más corto.

El programa muestra 5 opciones al usuario.

1.  Ver todas las conecciones de cada nodo en un archivo txt
2.  Obtener las conecciones desde una estación. Recibe el nombre de la estación y recibe sus nodos adyacentes.
3.  Obtener camino de un punto a otro. Esta función implementa DFS
4.  Obtener el camino más corto de un punto a otro. Se implementa BFS.
5.  Salir


# Estructura Extra
El árbol Trie nos permite almacenar palabras; en este árbol cada nodo guarda un caracter; este caractar puede ser compartido por muchas palabras. Al recorrer un camino hacia las hojas del árbol se forma una palabra con los caracteres en cada nodo. Con este tipo de árbol las complejidades se pueden reducir mucho pues encuentra la palabra visitando cada caracter y el hijo correspondiente. Un árbol bien balanceado puede llegar a tener un tiempo proporcional de M * logN.
Cada nodo del Trie tiene varias ramas, en estas ramas se representa un posible caracter, y las conecciones forman palabras. Al final de cada palabra debemos marcar el nodo final como el EndofWord, pues es donde acaba la palabra, esto permite al algoritmo de búsqueda saber cuano ha llegado al final de una palabra.

Este tipo de árboles pueden ser usados para diferentes problemas relacionados con strings. Un ejemplo es como cuando tenemos listas grandes de nombres de cosas (ej. un inventario), y queremos un método rápido y eficiente que nos diga si la palabra se encuentra dentro de nuestra lista. Con esta estructura podemos acortar el tiempo de búsqueda. También son usados estos árboles cuando queremos encontrar palabras que empiecen con cierto prefijo (ej. "co"). Con esta estructura reducimos la complejidad temporal pues no tenemos que buscar en todas las palabras, solo imprimimos las que tengan como nodos iniciales c -> o

En mi proyecto se usa el trie para verificar si la estacion que escribe el usuario como input sea una estación válida. Al inicio del programa se crea el trie y se agregan todas las estaciones; para poder hacer las 
búsquedas cuando el usuario quiera saber el camino entre estaciones.

# Casos de prueba
Se encuentran algunos al final del README y del main como comentarios, sin embargo en mainTests.cpp se pueden correr 4 
casos de prueba. 


# Complejidad

## INSERT (Trie)
	** Análisis de complejidad temporal **
	Recibe una string la cual va a añadir al árbol Trie, como mencioné anteriormente cada caracter 
	de la string va a estar en su respectivo nodo. La raíz del árbol tiene conexiones a 26 nodos 
	(tamaño del alfabeto) para que en este se guarde un caracter. Al insertar va al nodo con el 
	primer carácter, si no existe crea un nuevo nodo; y luego se mueve a la ramificación de este 
	carácter siguiendo el camino de nodos con el respectivo caracter o creando nuevos si es necesario. 
	Para insertar va a depender de la longitud de la string que queramos agregra, debido a que tiene 
	que recorrer o crear un nodo por cada caracter de la palabra. S recorrer cada caracter de la 
	palabra y en cada iteración guarda el caracter en el nodo y luego pasa al siguiente caracter. 
	Después de agregar todos los caracteres, marcamos el nodo final como EndOfWord para saber que ahí
	acaba la palabra.
	Complejidad: O(n)

## SEARCH (TRIE)
	** Análisis de complejidad temporal **
	Esta función también recibe como parámetro una string con la palabra que quiere buscar dentro 
	del Trie para saber si existe o no. La función regresa un valor boleano dependiendo si la palabra 
	se encuentra en el árbol o no. Igual que la función anterior, la función tendrá que recorrer toda 
	la string, para moverse de caracter en caracter. Primero se mueve al nodo con el primer caracter, 
	pasa al segundo y va avanzando de nodos dependiendo del caracter de la string.
	La función no pasa por todas las palabras, por lo que no se recorren todos los nodos. Si llegamos 
	a un punto en el que el siguiente caracter de la string no se encuentre dentro del árbol significa 
	que no esta la palabra. En cambio, si terminamos de recorrer todos los carácteres y llegamos a un 
	nodo marcado como EndOFWord, significa que si esta dentro del árbol.
	Este algoritmo sigue la misma lógica que el anterior.
	Complejidad: O(n) 


## LOAD GRAPH LIST
	** Análisis de complejidad temporal **
	La función lee los datos de un archivo, y con cada línea crea un edge, para guardar la relación 
	entre ambos nodos. Va avanzando 
	en el archivo hasta leer la última línea. Agrega estas conexiones en el vector de listas. 
	Debe recorrer todas las líneas para crear todos los edges. Y manda a llamar la función auxiliar 
	addEdgeAdjList, con una 
	complejidad lineal. 
	Complejidad: O(n)


## PRINT ADJ LIST
	** Análisis de complejidad temporal **
	La función imprime la lista de adjacencia; imprime cada una de las listas dentro del vector. Esto 
	para mostrar el vértice, y 
	todos los nodos a los que se puede llegar con éste. 
	Se usan dos ciclos for para imprimir todas las listas; la primera va avanzando entre cada una de 
	las listas del vector, que son 
	el número de nodos. 
	Y el segundo ciclo avanza por cada uno de los elementos de la lista dentro de esa posición del 
	vector. En el peor de los casos, 
	cada nodo tendrá conexión con todos los demas.
	Complejidad: O(n^2).   


## DFS HELPER
	** Análisis de complejidad temporal **
	La función realiza la búsqueda DFS (Depth First Search); que sigue la lógica de avanzar hasta llegar
	al final del grafo por 
	alguna de sus ramas, y volver a hacer lo mismo hasta llegar a la meta. 
	Este algoritmo puede tener dos diferentes complejidades dependiendo de si se usa la lista de 
	adyacencia o si se usa la matriz 
	de adyacenia.
	Si se usa la matriz, tendrá una complejidad de O(V^2), donde V es el número de vértices del grafo. 
	En cambio si se usa la lista 
	de adyacencia, la complejidad es de O(V+E).
	Usa un stack para almacenar los elementos y poder sacar al siguiente, que sería el último agregado. 
	Primero se agrega un elemento,
	se saca, y se mete al stack los hijos de este; y se vuelve a hacer lo mismo con el que esta hasta 
	arriba hasta llegar a la meta o 
	recorrer todos los elementos. 
	En este caso usé la lista de adyacencia, en el peor de los casos recorrerá todos los caminos; y 
	llegará en la meta en el último o 
	no lo encontratá en el grafo. Por lo que tendrá que pasar una vez por todos los vértices y todos 
	los arcos. 
	Sin embargo, debido a la forma en la que lo implemente, tiene que recorrer el arreglo 2 veces, de 
	manera anidada para verificar si 
	el elemento ya fue visitado en el vector. Es por esto que en esta implementación la complejidad es 
	cuadrática
	Complejidad: O(n^2)


## DFS
	Esta es la función que se manda llamar, en esta se inicializan todas las estructuras que se van a 
	usar para la búsqueda. En esta 
	se manda llamar la función DFShelper, que es la que tiene la complejidad de la búsqueda DFS. Al 
	final también se manda a llamar las 
	funciones que imprimen el vector de nodos visitados y el camino para llegar del inicio a la meta.
	Complejidad: O(1) Debido a que solo llama otras funciones


## BFS HELPER
	La función realiza la búsqueda BFS (Breadth First Search); que sigue la lógica de revisar todos 
	los hijos de un nodo para encontrar
	el camino más corto de llegar a una meta. 
	Este algoritmo puede tener dos diferentes complejidades dependiendo de si se usa la lista de 
	adyacencia o si se usa la matriz de
	adyacenia.
	Si se usa la matriz, tendrá una complejidad de O(V^2), donde V es el número de vértices del grafo. 
	En cambio si se usa la lista de
	adyacencia, la complejidad es de O(V+E).
	Usa un queue para almacenar los elementos y poder sacar al siguiente, que sería el primero agregado. 
	Esta es su única diferencia con 
	el anterior Primero se agrega un elemento, se saca, y se mete al stack los hijos de este; y se 
	vuelve a hacer lo mismo con el que esta 
	hasta arriba hasta llegar a la meta o recorrer todos los elementos. 
	En este caso usé la lista de adyacencia, en el peor de los casos el elemento se encontratá en el 
	último nivel, o no estará dentro del 
	grafo. Por lo que tendrá que pasar una vez por todos los vértices y todos los arcos. 
	Igual que con DFS, debido a la forma en la que lo implemente, tiene que recorrer el arreglo 2 veces, 
	de manera anidada para verificar 
	si el elemento ya fue visitado en el vector. Es por esto que en esta implementación la complejidad 
	es cuadrática
	Complejidad: O(n^2)

## BFS
	Esta es la función que se manda llamar, en esta se inicializan todas las estructuras que se van a 
	usar para la búsqueda. En esta se 
	manda llamar la función BFShelper, que es la que tiene la complejidad de la búsqueda BFS. Al final 
	también se manda a llamar las funciones 
	que imprimen el vector de nodos visitados y el camino para llegar del inicio a la meta.
	Complejidad: O(1) Debido a que solo llama otras funciones


# FUNCIONES AUXILIARES

## ADD EDGE ADJ LIST
	En esta función, se agrega una relación al vector de listas. Recibe 2 string y con esta obtiene 
	2 datos para agregar el primero a la 
	lista del segundo y viceversa. 
	Para esto se usa un ciclo para obtener el primer valor de las listas para saber cual es el nodo
	Complejidad: O(n) 


## PRINT VISITED
	En esta función se imprimen todos los elementos que fueron visitados, en el orden en el que se 
	les visitó. Para esto se usa un ciclo for, 
	que va desde 0 hasta el tamaño del vector de visitados; y se imprime en orden cada uno de los 
	valores. 
	En el peor de los casos se deben imprimir todos los nodos, pues todos fueron visitados. 
	Complejidad: O(n) n -> número de nodos

## PRINT PATH
	En esta función se imprime el camino desde el nodo inicial hasta la meta. Va recorriendo de atrás
	para adelante y mete cada uno de los 
	nodos dentro de un stack; después pasa al padre de este nodo y lo mete en el stack, hasta llegar
	al inicio.
	Debido a que estan ordenados por string, es necesario recorrer toda la lista para saber la posición 
	en la que se encuentra.
	Después de que todos esten en el stack, comienza a sacarlos y a imprimir su valor, para imprimirlo 
	en el orden correct. 
	Debido a que se deben meter y sacar todos los elementos del camino; en el peor de los casos el 
	camino esta formado por todos los nodos. 
	Por lo que se deben recorrer todos los nodos y se usan 2 ciclos.
	Complejidad: O(n^2). n -> número de nodos

# Casos de Prueba

##Prueba 1 : Opcion 1. Ver todas las conecciones de cada nodo en un archivo txt
		
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


## Prueba 2 : Opcion 2. Obtener las conecciones desde una parada
		
        Introduce el nombre de la estación: "Termini"

	CONSOLA RESULTADO:
        	Vertex Termini : Repubblica, Vittorio Emanuele, Castro Pretorio, Cavour


## Prueba 3 : Opcion 3.  Obtener camino de un punto a otro
	
	Introduce el nombre de la estación inicial: Ottaviano
    	Introduce el nombre de la estación de destino: San Giovanni 

	CONSOLA RESULTADO: 
		Path: Ottaviano, Risorgimento, San Pietro, Chiesa Nuova, Venezia, Colosseo, Cavour, Termini, Vittorio Emanuele, 		Manzoni, San Giovanni.


## Prueba 4 : Opción 4. Obtener el camino más corto de un punto a otro
    
    	Introduce el nombre de la estación inicial: Ottaviano
    	Introduce el nombre de la estación de destino: San Giovanni 

    	CONSOLA RESULTADO:
        	Path: Ottaviano, Risorgimento, San Pietro, Chiesa Nuova, Venezia, Colosseo, Amba Aradam, San Giovanni.


## Prueba 5: Opción 3. Obtener el camino de un punto a otro
	
	Introduce el nombre de la estación inicial: Otta
    	Introduce el nombre de la estación de destino: Termi

    	CONSOLA RESULTADO:
    		Las estaciones no existen.


## Prueba 6: Opción 4: Obtener el camino más corto de un punto a otro
	Introduce el nombre de la estación inicial: Lod
    Introduce el nombre de la estación de destino: Ottaviano

    CONSOLA RESULTADO:
    		La estación de origen no existe


## Prueba 7: Opción 2: Obtener las conexiones de una parada
	Introduce el nombre de la estación: Af

	CONSOLA RESULTADO:
		La estación no existe.
