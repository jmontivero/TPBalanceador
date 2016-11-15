Trabajo Practico para Sintaxis y Semantica de los Lenguajes - UTN
Profesor: Sola, Jose María
Curso K2051
Grupo 2: Montivero, Javier - Martinez, Guido - Cabrera, Ivana - Merlis, Nicolas - Cabaleiro, Julian

-CONSIGNA-
Desarrollar un programa en lenguaje C que verifique errores simples en un programa C. Debe verificar
que parentesis, llaves y corchetes estén balanceados. Debe tratar correctamente las cadenas y los caracteres
literales, así como los comentarios. Implementarlo con una maquina de estados con goto y etiquetas.

Se presenta en main.c el programa probado y funcionando correctamente. En balanceador.gv se encuentra 
el codigo .dot para generar el grafo que representa la maquina de estados implementada, 
cuya salida se encuentra en balanceador.png. El archivo test.c es un programa en C que se puede 
usar para probar la entrega. Los archivos Stack.c y Stack.h son la implementacion y las cabeceras de la pila
usada para el automata de pila.

--ACLARACIONES--
En el grafo de la maquina de estados se usan las siguientes referencias, para reducir el numero de 
transiciones representadas:
	X: representa cualquier caracter que abre (parentesis '(', llave '{' o corchete '['),
	Y: representa cualquier caracter que cierra (parentesis ')', llave '}' o corchete ']'),
	Z: se usa luego de Y, para indicar cualquier caracter perteneciente a la pila (puede ser
		')', '}', ']' o '$'), salvo el indicado por Y,
	A: representa a alguno de los caracteres de la pila (puede ser ')', '}', ']' o '$'),
	C: representa todos los caracteres no contemplados en las demas transiciones 
		de cada estado.
Ademas, se utilizo una sola flecha reflexiva para representar todas las transiciones reflexivas en los
estados que tienen mas de una.