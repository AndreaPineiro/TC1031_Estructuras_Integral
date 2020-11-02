Este programa recibe datos del CSV "Préstamos" en este se da la información del material de entrenamiento que el gimnasio Black Bull fitness prestó a sus clientes donde la cuartentena. 
Tiene los datos del nombre de la persona, la fecha, la cantidad de piezas y el nombre del equipo de entrenamiento (ej. cuerda, barra).
Para esta entrega uso una Double Linked List para ordenar los datos con ordena selección. Y esta sirve para guardar los objetos prestamo y poder hacer las búsquedas por nombre de equipo.
El heap contiene otros objetos llamados equipo, hechos con los mismos datos pero este solo tiene el nombre del equipo de entrenamiento (ej. barra) y la cantidad de barras que se encuentran prestadas. 

El programa muestra 4 opciones al usuario.
1. Ver los datos ordenados
	Esta opción crea un ".txt" donde el usuario puede ver los datos ordenados 
2. Buscar por nombre de equipo
	Esta opción permite al usuario ingresar el nombre del equipo y muestra todos los usuarios que rentaron ese material.
3. Obtener equipo mas prestado
	Esta opción nos imprime en consola el nombre del equipo y el número de piezas que están prestadas.
4. Salir
	Saca al usuario del programa. 


# DLINK 

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

## DLINK UPDATE
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro de la lista anidada hasta llegar al índice del elemento que queremos cambiar. 
	En este algoritmo, si el índice se encuentra en la primer mitad de los elementos empezamos desde head; si se encuentra en la segunda mitad, empezamos desde el tail. 
	Para hacer esto se usa un while que recorre los elementos hasta llegar a la posición con un apuntador auxiliar 'p', y los compara con el índice que recibimos. Avanza de uno en uno por que se utilizan los apuntadores de cada objeto para llegar al siguiente, o al anterior en dado caso; pero al dividir la lista en 2 la complejidad es O(n/2) que se redondea.
	Complejidad: O(n)


## DLINK REMOVE
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro de la lista anidada hasta llegar al índice del elemento que queremos eliminar.
	Si el índice es el 0, solo cambiamos el apuntador de la cabeza hacia el siguiente elemento. Y el de previous lo apuntamos a 0.
	Si el índice es 1, el apuntador de la cola debe apuntar hacia el previous, y next hacia 0.
	Si se encuentra en algún otro, usa un ciclo for que va desde 1 hasta el índice que queremos encontrar. Recorre los elementos uno por uno con un apuntador auxiliar 'p', y los compara con el índice que recibimos. Cuando nos encontramos con el número anterior al índice, usamos otro apuntador 'q' que apunte al objeto en el índice que queremos eliminar. Cambiamos el apuntador del objeto en p para que vaya hacia el siguiente de q; y eliminamos el objeto al que apunta q.
	El algoritmo avanza de uno en uno por que se utilizan los apuntadores de cada objeto para llegar al siguiente. 
	Por lo que el algoritmo recorrerá todos los elementos en el peor de los casos. 
	Complejidad: O(n)


## DLINK CLEAR
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro de la lista anidada hasta el final.
	Avanza elemento por elemento usando los apuntadores de cada objeto.
	Esta función llega hasta el final de la lista con un ciclo while. 
	Complejidad: O(n)

## DLINK TOSTRING
	** Análisis de complejidad temporal **
	La función recorre cada uno de los elementos dentro de la lista anidada hasta el final. Avanza elemento por elemento usando los apuntadores de cada objeto para obtener el valor de cada uno y añadirlo a una string con todos los elementos de la lista
	Complejidad: O(n)


# ORDENA SELECCIÓN (Dentro de DLINK)
	** Análisis de complejidad temporal **
	El primer ciclo es el que determina cuántas veces vamos a tener que recorrer todo el vector; este va desde 0 hasta n, incrementando de 1 en 1. 
	El segundo ciclo va a recorrer cada elemento del vector que no este ya en su posición correcta. Buscará el más pequeño y lo colocará en la posición hasta la izquierda. Este comenzará desde el valor de i (determinado por el primer ciclo) hasta n. 
	Tenemos dos ciclos anidados; los cuáles dependen de n. El segundo ciclo cada vez irá recorriendo 1 menos por lo que la complejidad del algoritmo no es precisamente O(n^2). 
	Matemáticamente tiene una complejidad de ((n * (n + 1)) / 2). Sin embargo, como estamos hablando de Big O, tenemos que irnos al peor de los casos que sería O(n^2). 

# HEAP

## HEAP EMPTY
	** Análisis de complejidad temporal **
	La función revisa si el heap está vacío, es decir, si no contiene ningún elemento. Para esto, revisa el atributo count, que indica cuántos elementos hay. Si count es igual a 0, significa que no hay ningún elemento en el heap. 
	La función no realiza ningún ciclo, solo obtiene el valor del atributo count, por lo que la complejidad es constante.
	Complejidad: O(1)

## HEAP SIZE
	** Análisis de complejidad temporal **
	La función obtiene el número de elementos que hay en el heap. Para esto, revisa el atributo count, que indica cuántos elementos hay. 
	La función no realiza ningún ciclo, solo obtiene el valor del atributo count, por lo que la complejidad es constante.
	Complejidad: O(1)

## HEAP PUSH
	** Análisis de complejidad temporal **
	Esta función agrega a la fila priorizada un elemento; cuando lo recibe lo coloca hasta el final de la lista, pero con un while lo acomoda en el lugar correcto, para que no sea mayor que su padre.
	Gracias a que los elementos están ordenados equitativamente en cada rama, no hay necesidad de recorrer todos los objetos. En el peor de los casos tendría que mover el elemento hasta la primer posición, pero solo pasaría por una rama, por lo que la complejidad es logarítmica.
	Complejidad: O(log(n))


## HEAP POP
	** Análisis de complejidad temporal **
	Esta función saca de la fila priorizada el objeto con mayor prioridad, es decir el objeto que se encuentra al inicio del arreglo; esto debido a que como es un heap ordenado, el primer elemento es el de mayor prioridad.
	La función sobreescribe el primer elemento del heap con el último que añadimos. Y manda a llamar la función Heapify.
	Como solo estamos mandando llamar la función, tiene una complejidad constante. O(1).

	Sin embargo, debido al algoritmo de Heapify la complejidad total al eliminar un elemento es
	Complejidad: O(log(n))
	En el apartado de Heapify se explica el análisis temporal


## HEAP HEAPIFY
	** Análisis de complejidad temporal **
	Esta función revisa que el heap este ordenado correctamente, es decir que el elemento que se encuentre al inicio sea el de mayor prioridad. Esto lo hace comparando el valor de el elemento con sus vecinos en la derecha o en la izquierda; si alguno de ellos es de mayor prioridad hace un swap por con el menor. 
	Esta función se llama recursivamente después que el primer elemento ya se ordeno; lo que hace es volverla a llamar pero ahora con min. 
	Sin embargo, debido al acomodo de los elementos; es como se fuera un árbol balanceado; por lo que no tendrá que llamar la función n veces. 
	En el peor de los casos se tendría que llegar hasta el final de una de las ramas, y como los elementos están ordenados equitativamente en cada rama, no hay necesidad de recorrer todos los objetos; por lo que es logarítmica.
	Complejidad de O(log(n)


## HEAP TOP
	** Análisis de complejidad temporal **
	La función obtiene el objeto que se encuentra en el primer lugar del heap, es decir, el elemento con mayor prioridad. 
	La función no realiza ningún ciclo, solo obtiene el valor que se encuentra en la posición 0 del arreglo, por lo que la complejidad es constante.
	Complejidad: O(1)

## HEAP SWAP
	** Análisis de complejidad temporal **
	La función recibe dos posiciones, e intercambia los objetos que se encuentran en ambas; el primer objeto lo pasa a la segunda posición y viceversa. Para hacerlo guarda uno de los valores en una variable auxiliar. 
	La función no realiza ningún ciclo, solo obtiene el valor del las posiciones y los cambia.
	Complejidad de O(1)


## HEAP FULL
	** Análisis de complejidad temporal **
	La función obtiene el número de elementos que hay en el heap y lo compara con el tamaño de elementos máximo que acepta el heap. Para esto, revisa el atributo count, que indica cuántos elementos hay y el de size (tamaño del arreglo); si son iguales significa que el arreglo está lleno.
	La función no realiza ningún ciclo, solo obtiene el valor de los atributo, por lo que la complejidad es constante.
	Complejidad de O(1)


## HEAP PARENT, LEFT, RIGHT
	** Análisis de complejidad temporal **
	Estas funciones regresan la posición en la que se encuentra el padre, el objeto de la izquierda y el de la derecha respectivamente. 
	La función no realiza ningún ciclo, solo realizan un cálculo para encontrar estas posiciones.
	Complejidad de O(1)
