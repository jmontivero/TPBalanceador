#include<stdio.h>

void test(){
	int a = 2 / 4;
	char caracter = '}'; //Este literal caracter no desbalancea las llaves
	char string[] = "Este  literal cadena no desbalancea los corchetes\" ] " ;
	printf("Este es un programa de prueba para el parser.");//Este comentario no desbalancea los parentesis(
	/*Este 
	comentario tampoco(
	**/
	//Si se descomenta la linea siguiente, el programa falla
	//printf());
	
}
