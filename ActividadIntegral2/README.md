### AVANCE 2
	En este avance implemente una double linked list, para mostrar los datos de los clientes de Black Bull Pachuca, que tiene
	un registro de los nombres y de la cantidad de cuponeras que han adquirido.

## DLINK ADD
	** Análisis de complejidad temporal **
	Gracias a previous, la función ya no tiene que recorrer todos los elementos para llegar al final. Este apuntador nos permite llegar directamente, y ligar el "next" del nuevo objeto a 0, y el previous del objeto al "tail" anterior. 
	Para agregar el objeto no hacemos ningún recorrido, lo obtenemos directamente. 
	Complejidad: O(1)

## DLINK FIND(FIRST Y LAST)
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro de la lista anidada hasta llegar al final o al inicio, o hasta encontrar el número dentro de la lista. 
	Para encontrar la primera ocurrencia, empieza desde la cabeza, y para el findLast empieza por la tail.
	Para hacer esto se usa un while que recorre los elementos uno por uno, y los compara con el objeto que recibimos. 
	En el peor de los casos, el elemento se encontrará en la última posición de la lista, o no se encontrará; por lo que el algoritmo recorrerá todos los elementos. 
	Complejidad: O(n)


## DLINK GET_OBJECT
	** Análisis de complejidad temporal **
	Va recorriendo todos los elementos hasta llegar al índice que estamos buscando. 
	En este algoritmo, si el índice se encuentra en la primer mitad de los elementos empezamos desde head; si se encuentra en la segunda mitad, empezamos desde el tail. 
	Para hacer esto se usa un while que recorre los elementos hasta llegar a la posición con un apuntador auxiliar 'p', y los compara con el índice que recibimos. Avanza de uno en uno por que se utilizan los apuntadores de cada objeto para llegar al siguiente, o al anterior en dado caso; pero al dividir la lista en 2 la complejidad es O(n/2) que se redondea.
	Complejidad: O(n)

## UPDATE
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro de la lista anidada hasta llegar al índice del elemento que queremos cambiar. 
	En este algoritmo, si el índice se encuentra en la primer mitad de los elementos empezamos desde head; si se encuentra en la segunda mitad, empezamos desde el tail. 
	Para hacer esto se usa un while que recorre los elementos hasta llegar a la posición con un apuntador auxiliar 'p', y los compara con el índice que recibimos. Avanza de uno en uno por que se utilizan los apuntadores de cada objeto para llegar al siguiente, o al anterior en dado caso; pero al dividir la lista en 2 la complejidad es O(n/2) que se redondea.
	Complejidad: O(n)


## REMOVE
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro de la lista anidada hasta llegar al índice del elemento que queremos eliminar.
	Si el índice es el 0, solo cambiamos el apuntador de la cabeza hacia el siguiente elemento. Y el de previous lo apuntamos a 0.
	Si el índice es 1, el apuntador de la cola debe apuntar hacia el previous, y next hacia 0.
	Si se encuentra en algún otro, usa un ciclo for que va desde 1 hasta el índice que queremos encontrar. Recorre los elementos uno por uno con un apuntador auxiliar 'p', y los compara con el índice que recibimos. Cuando nos encontramos con el número anterior al índice, usamos otro apuntador 'q' que apunte al objeto en el índice que queremos eliminar. Cambiamos el apuntador del objeto en p para que vaya hacia el siguiente de q; y eliminamos el objeto al que apunta q.
	El algoritmo avanza de uno en uno por que se utilizan los apuntadores de cada objeto para llegar al siguiente. 
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
	La función recorre cada uno de los elementos dentro de la lista anidada hasta el final. Avanza elemento por elemento usando los apuntadores de cada objeto para obtener el valor de cada uno y añadirlo a una string con todos los elementos de la lista
	Complejidad: O(n)


## ORDENA SELECCIÓN
	** Análisis de complejidad temporal **
	El primer ciclo es el que determina cuántas veces vamos a tener que recorrer todo el vector; este va desde 0 hasta n, incrementando de 1 en 1. 
	El segundo ciclo va a recorrer cada elemento del vector que no este ya en su posición correcta. Buscará el más pequeño y lo colocará en la posición hasta la izquierda. Este comenzará desde el valor de i (determinado por el primer ciclo) hasta n. 
	Tenemos dos ciclos anidados; los cuáles dependen de n. El segundo ciclo cada vez irá recorriendo 1 menos por lo que la complejidad del algoritmo no es precisamente O(n^2). 
	Matemáticamente tiene una complejidad de ((n * (n + 1)) / 2). Sin embargo, como estamos hablando de Big O, tenemos que irnos al peor de los casos que sería O(n^2). 

