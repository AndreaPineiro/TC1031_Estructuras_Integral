Andrea Piñeiro Cavazos

En este avance se obtienen los datos de un archivo .csv que contiene las asistencias de los atletlas del gimnasio 
"Black Bull Fitness". En este se encuentra la fecha, el nombre del atleta y la hora en la que asistió. 
En un vector se ordenan estos datos con Ordena Selección por fecha, y te permite ver la información ordenada y 
buscar en un rango de fechas.

# Casos de prueba
Se encuentran algunos al final del README, sin embargo en mainTests.cpp se pueden correr 5 
casos de prueba. 

# Complejidad

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
	Tenemos dos ciclos anidados; los cuáles dependen de n. El segundo ciclo cada vez irá recorriendo 1 menos por 
	lo que la complejidad del algoritmo no es precisamente O(n^2). 
	Matemáticamente tiene una complejidad de ((n * (n + 1)) / 2). Sin embargo, como estamos hablando de Big O, tenemos que 		irnos al peor de los casos que sería O(n^2). 


## BUSQUEDA BINARIA 
	** Análisis de complejidad temporal **
	El algoritmo recorre log(n) pasos, ya que para encontrar el número en el vector no recorre todo el vector. 
	Obtiene el número de la mitad y lo compara con el número que buscamos, si son iguales, regresamos su índice, 
	pues ya lo hemos encontrado. Si es menor llama la función de nuevo desde low hasta mid-1; si es mayor la 
	llama desde mid+1 hasta high. 
	La función recursiva se detiene cuando se ha encontrado el número o siempre que low sea menor que high. 
	No recorremos todos los números, pues descartamos la mitad de ellos y luego la siguiente mitad...hasta que 
	lo encontremos o lleguemos al caso base.
	Es por eso que la complejidad es O(log(n))
	
# Casos de prueba

## Prueba 1 : Opcion 2. Buscar por rango
	Fecha inicial: 01/01/20
	Fecha final: 05/01/20

	Resultado: "Las fechas estan por debajo del limite."


## Prueba 2 : Opcion 2. Buscar por rango
	Fecha inicial: 12/12/21
	Fecha final: 15/12/21

	Resultado: "Las fechas exceden el limite."


## Prueba 3 : Opcion 2. Buscar por rango  (Excede el valor final)
	Fecha inicial: 15/09/20
	Fecha final: 28/09/20

	Resultado: 
	15/09/20,Suriel Martinez Serrano,08:00
	15/09/20,Selma Janett Calleja Jaramillo,08:00
	15/09/20,Raciel Edmundo Escudero Diaz,06:00
	15/09/20,Paloma Ashly Covarrubias Hernandez,18:00
	15/09/20,Naydelin Ruiz Hernandez,18:00
	15/09/20,Mitzi Yael Porras Perez,08:00
	15/09/20,Maria Esther Hernandez Diaz,20:00
	15/09/20,Maria de los Angeles Villanueva Espinosa,08:00
	15/09/20,Marco Antonio Lozada Copca,06:00
	15/09/20,Luba Miriam Laski Covarrubias,18:00
	15/09/20,Julio Sanchez Ramirez,20:00
	15/09/20,Juan Antonio Zavala Manzanares,20:00
	15/09/20,Jose Antonio Alonso Cervantes,08:00
	15/09/20,Jorge Enrique Vargas Acosta,20:00
	15/09/20,Heberto Vizcaya Barrera,08:00
	15/09/20,Gaston Ceron Munoz,06:00
	15/09/20,Claudia Camacho Carreggio,06:00
	15/09/20,Carla Guzman Illescas,06:00
	15/09/20,Candy Nohemi Calderon Chavarria,06:00
	15/09/20,Axel Ishac Licona Calderon,18:00
	17/09/20,Vianney Alberto Melo Rios,08:00
	17/09/20,Selma Janett Calleja Jaramillo,08:00
	17/09/20,Raciel Edmundo Escudero Diaz,06:00
	17/09/20,Martha Guerrero Olvera,08:00
	17/09/20,Maria de los Angeles Villanueva Espinosa,08:00
	17/09/20,Jose Antonio Alonso Cervantes,08:00
	17/09/20,Heberto Vizcaya Barrera,08:00
	17/09/20,Gaston Ceron Munoz,06:00
	17/09/20,Gabriela Morales Mendez,08:00
	17/09/20,Gabriela Barranco Mendoza,08:00
	17/09/20,Claudia Camacho Carreggio,06:00
	17/09/20,Carla Guzman Illescas,06:00
	17/09/20,Candy Nohemi Calderon Chavarria,06:00


## Prueba 4 : Opcion 2. Buscar por rango  (Excede el valor inicial)
	Fecha inicial: 01/02/20
	Fecha final: 04/03/20

	Resultado:
	02/03/20,Maria Fernanda Camacho Tovar
	02/03/20,Mayra Alejandra Tovar Gonzalez
	02/03/20,Octavio Montano Mendoza
	02/03/20,Mario Villarreal Mares
	02/03/20,Maria Teresa de Jesus Barroeta Sanchez
	02/03/20,Luis Alejandro Cortes Rodriguez
	02/03/20,Felipe Ochoa Velasco
	02/03/20,Mario Villarreal Mares
	02/03/20,Elvia Cortazar Martinez
	02/03/20,Gibran Aparicio Cortazar
	02/03/20,Gustavo Aparicio Cortazar
	02/03/20,Zoe Bello Alfaro
	02/03/20,Berenice Alfaro Ponce
	02/03/20,Juan Francisco Bello Jardines
	02/03/20,Angel Zaid Cruz Olivarez
	02/03/20,Angeles Zeydel Olivares
	02/03/20,Luis David Cruz Olivares
	02/03/20,Zoe Bello Alfaro
	02/03/20,Berenice Alfaro Ponce
	02/03/20,Juan Francisco Bello Jardines
	02/03/20,Heidy Ceron Islas
	02/03/20,Diana Jimena Ramirez Ceron
	02/03/20,Sergio Rogelio Perez Ramirez
	02/03/20,Maria Concepcion Avila Martinez
	02/03/20,Jose Daniel Perez Nunez
	02/03/20,Jose Daniel Garcia Rios
	02/03/20,Jorge Enrique Vargas Acosta
	02/03/20,Oscar Nashiel Gonzalez Lara
	02/03/20,Elba Zuzely Vizcaya Barrera
	02/03/20,Maria Fernanda Alfaro Gonzalez
	02/03/20,Ximena Shady Godinez Garrido
	02/03/20,Alma Thais Godinez Garrido
	02/03/20,Joel Ramirez Ortega
	02/03/20,Jalil Aparicio Cortazar
	02/03/20,Maria Evodia Rios Castaneda
	02/03/20,Norma Aida Pineiro Acosta
	02/03/20,Mario Alberto Mendoza Pineiro
	02/03/20,Ariadna Pineiro Acosta
	02/03/20,Felipe Ochoa Velasco
	02/03/20,Hector Adrian Hernandez Segura
	02/03/20,Deyanira Perez Hernandez
	02/03/20,Oscar Duran Soto
	02/03/20,Julio Alfredo Cornejo Grimaldo
	02/03/20,Carlos Angel Rodriguez Lopez
	02/03/20,Pablo Manuel Gayosso Chavez
	02/03/20,Gabriela Morales Mendez
	02/03/20,Alicia Chavarria Lopez
	02/03/20,Vianney Alberto Melo Rios
	02/03/20,Leonardo Restrepo Munoz
	02/03/20,Victor Manuel Lopez Medina
	02/03/20,Julio Cesar Hernandez Velasco
	02/03/20,Gaston Ceron Munoz
	02/03/20,Marco Antonio Lozada Copca
	02/03/20,Valerio Ivan Islas Charolet
	02/03/20,Fabiola Hernandez Escudero
	02/03/20,Marco Antonio Banos Rubio
	02/03/20,Carla Guzman Illescas
	02/03/20,Luis Antonio Roldan Bautista
	02/03/20,Jose Luis Marin Gonzalez
	02/03/20,Claudia Camacho Carreggio
	02/03/20,Raciel Edmundo Escudero Diaz
	03/03/20,Julio Alfredo Cornejo Grimaldo
	03/03/20,Manuel
	03/03/20,Jose Daniel Perez Nunez
	03/03/20,Gabriela Morales Mendez
	03/03/20,Alicia Chavarria Lopez
	03/03/20,Leonardo Restrepo Munoz
	03/03/20,Jose Juan Aviles Abrego
	03/03/20,Guadalupe Myriam Romero Gomez
	03/03/20,Eduardo Gonzalez Suarez
	03/03/20,Dulce Alheli Torres Rodriguez
	03/03/20,Nathan Mauricio Flores Ponce
	03/03/20,Pablo Manuel Gayosso Chavez
	03/03/20,Alma Thais Godinez Garrido
	03/03/20,Maria Fernanda Alfaro Gonzalez
	03/03/20,Elba Zuzely Vizcaya Barrera
	03/03/20,Jose Daniel Garcia Rios
	03/03/20,Alejandro Martinez Rodriguez
	03/03/20,Alba Leticia Badillo Ramirez
	03/03/20,Jalil Aparicio Cortazar
	03/03/20,Hector Adrian Hernandez Segura
	03/03/20,Felipe Ochoa Velasco
	03/03/20,Danya Sanchez Omana
	03/03/20,Mayra Alejandra Tovar Gonzalez
	03/03/20,Octavio Montano Mendoza
	03/03/20,Maria Fernanda Camacho Tovar
	03/03/20,Maria Evodia Rios Castaneda
	03/03/20,Mario Alberto Mendoza Pineiro
	03/03/20,Cristal Torres Torres
	03/03/20,Ariadna Pineiro Acosta
	03/03/20,Oscar Nashiel Gonzalez Lara
	03/03/20,Zaira Sanchez Omana
	03/03/20,Oscar Duran Soto
	03/03/20,Danya Sanchez Omana
	03/03/20,Magali Citlalli Reyes Garcia
	03/03/20,Luis Alejandro Cortes Rodriguez
	03/03/20,Elvia Cortazar Martinez
	03/03/20,Gustavo Aparicio Cortazar
	03/03/20,Gibran Aparicio Cortazar
	03/03/20,Maria Teresa de Jesus Barroeta Sanchez
	03/03/20,Jorge Enrique Vargas Acosta
	03/03/20,Jose Daniel Perez Nunez
	03/03/20,Regina Rojas Crespo
	03/03/20,Berenice Alfaro Ponce
	03/03/20,Juan Francisco Bello Jardines
	03/03/20,Diana Jimena Ramirez Ceron
	03/03/20,Heidy Ceron Islas
	03/03/20,Angeles Zeydel Olivares
	03/03/20,Angel Zaid Cruz Olivarez
	03/03/20,Luis David Cruz Olivares
	03/03/20,Gaston Ceron Munoz
	03/03/20,Marco Antonio Lozada Copca
	03/03/20,Luis Antonio Roldan Bautista
	03/03/20,Claudia Camacho Carreggio
	03/03/20,Carla Guzman Illescas
	03/03/20,Jose Luis Marin Gonzalez
	03/03/20,Raciel Edmundo Escudero Diaz
	03/03/20,Aida Hernandez Ramirez
	03/03/20,Melissa Azpeitia Hernandez
	03/03/20,Cesar Israel Acosta Arias
	03/03/20,Valerio Ivan Islas Charolet
	03/03/20,Israel Ulises Hernandez Martinez
	03/03/20,Fabiola Hernandez Escudero
	03/03/20,Marco Antonio Banos Rubio
	04/03/20,Guadalupe Myriam Romero Gomez
	04/03/20,Dulce Alheli Torres Rodriguez
	04/03/20,Jose Daniel Garcia Rios
	04/03/20,Oscar Nashiel Gonzalez Lara
	04/03/20,Mariana Camacho Ortega
	04/03/20,Efrain Sanchez Becerril
	04/03/20,Maria Fernanda Alfaro Gonzalez
	04/03/20,Elba Zuzely Vizcaya Barrera
	04/03/20,Jalil Aparicio Cortazar
	04/03/20,Alejandro Martinez Rodriguez
	04/03/20,Jorge Enrique Vargas Acosta
	04/03/20,Orlando Jair Lopez Santiago
	04/03/20,Adolfo Miguel Pontigo Tovar
	04/03/20,Oscar Duran Soto
	04/03/20,Danya Sanchez Omana
	04/03/20,Zaira Sanchez Omana
	04/03/20,Mario Villarreal Mares
	04/03/20,Felipe Ochoa Velasco
	04/03/20,Norma Aida Pineiro Acosta
	04/03/20,Ariadna Pineiro Acosta
	04/03/20,Deyanira Perez Hernandez
	04/03/20,Maria Fernanda Camacho Tovar
	04/03/20,Octavio Montano Mendoza
	04/03/20,Berenice Alfaro Ponce
	04/03/20,Juan Francisco Bello Jardines
	04/03/20,Naoli Alfaro Ponce
	04/03/20,Zoe Bello Alfaro
	04/03/20,Regina Rojas Crespo
	04/03/20,Elvia Cortazar Martinez
	04/03/20,Gustavo Aparicio Cortazar
	04/03/20,Gibran Aparicio Cortazar
	04/03/20,Jose Manuel Gachuz Moreno
	04/03/20,Magali Citlalli Reyes Garcia
	04/03/20,Celinn Mirell Gutierrez Rodriguez
	04/03/20,Andrea Cortes Barroeta
	04/03/20,Maria Teresa de Jesus Barroeta Sanchez
	04/03/20,Angeles Zeydel Olivares
	04/03/20,Angel Zaid Cruz Olivarez
	04/03/20,Luis David Cruz Olivares
	04/03/20,Maria Esther Hernandez Diaz
	04/03/20,Diana Jimena Ramirez Ceron
	04/03/20,Valerio Ivan Islas Charolet
	04/03/20,Ulises Alan Carrenno Mejia
	04/03/20,Jose Luis Marin Gonzalez
	04/03/20,Gaston Ceron Munoz
	04/03/20,Israel Ulises Hernandez Martinez
	04/03/20,Carla Guzman Illescas
	04/03/20,Luis Antonio Roldan Bautista
	04/03/20,Marco Antonio Lozada Copca
	04/03/20,Raciel Edmundo Escudero Diaz
	04/03/20,Claudia Camacho Carreggio
	04/03/20,Fabiola Hernandez Escudero
	04/03/20,Aida Hernandez Ramirez
	04/03/20,Julio Alfredo Cornejo Grimaldo
	04/03/20,Marco Antonio Banos Rubio
	04/03/20,Julio Cesar Hernandez Velasco
	04/03/20,Jorge Eduardo Vargas Cortes
	04/03/20,Victor Manuel Lopez Medina
	04/03/20,Alicia Chavarria Lopez
	04/03/20,Pablo Manuel Gayosso Chavez
	04/03/20,Vianney Alberto Melo Rios
	04/03/20,Gabriela Morales Mendez
	04/03/20,Leonardo Restrepo Munoz
	04/03/20,Eduardo Gonzalez Suarez
	04/03/20,Guadalupe Myriam Romero Gomez
	04/03/20,Maria Concepcion Avila Martinez
	04/03/20,Eduardo Gonzalez Suarez


## Prueba 5: Opcion 2. Buscar por rango
	Fecha inicial: 10/07/20
	Fecha final: 11/07/20

	Resultado:
	10/07/20,Zoe Bello Alfaro,19:30
	10/07/20,Ximena Shady Godinez Garrido,10:00
	10/07/20,Vianney Alberto Melo Rios,08:00
	10/07/20,Selma Janett Calleja Jaramillo,06:30
	10/07/20,Raciel Edmundo Escudero Diaz,06:30
	10/07/20,Maria Teresa de Jesus Barroeta Sanchez,19:30
	10/07/20,Magali Citlalli Reyes Garcia,19:30
	10/07/20,Luis Alejandro Cortes Rodriguez,19:30
	10/07/20,Luba Miriam Laski Covarrubias,19:30
	10/07/20,Julio Cesar Hernandez Velasco,08:00
	10/07/20,Juan Francisco Bello Jardines,19:30
	10/07/20,Ivan Oyervides Vega,08:00
	10/07/20,Gaston Ceron Munoz,06:30
	10/07/20,Gabriela Morales Mendez,08:00
	10/07/20,Diego Alberto Ramirez Ceron,19:30
	10/07/20,Claudia Camacho Carreggio,06:30
	10/07/20,Carla Guzman Illescas,06:30
	10/07/20,Berenice Alfaro Ponce,19:30
	10/07/20,Axel Ishac Licona Calderon,19:30
	10/07/20,Andrea Cortes Barroeta,19:30
	10/07/20,Alma Thais Godinez Garrido,10:00
	10/07/20,Adrian Cortes Barroeta,19:30
	10/07/20,Adolfo Miguel Pontigo Tovar,10:00
	11/07/20,Sandra Karina Tapia Navarrete,08:00
	11/07/20,Raciel Edmundo Escudero Diaz,08:00
	11/07/20,Maria Concepcion Avila Martinez,10:00
	11/07/20,Marco Antonio Banos Rubio,08:00
	11/07/20,Karen Danae Avila Martinez,10:00
	11/07/20,Claudia Camacho Carreggio,08:00
	11/07/20,Carla Guzman Illescas,08:00
	11/07/20,Adolfo Miguel Pontigo Tovar,10:00
