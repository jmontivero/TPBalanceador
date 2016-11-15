#include <stdio.h>
#include "Stack.h"
//Verifica balanceos de parentesis, llaves y corchetes en un programa en C.
//Ignora los desbalanceos dentro de literales cadena, caracter y en comentarios de una o multiples lineas.
//Contempla las secuencias de escape dentro de los literales cadena y caracter.
//Autores: Cabaleiro, Julian - Cabrera, Ivana - Martinez, Guido - 
// - Merlis, Nicolas - Montivero, Javier 
//30/10/2016

int main() {
	push('$'); // $ se usa como caracter de fondo de pila
	
    mid:
		switch(getchar()){
			case '(': //Abre parentesis
				switch(pop()){
					case '$':
						push('$');
						push(')');
						goto mid;
					case '}':
						push('}');
						push(')');
						goto mid;
					case ']':
						push(']');
						push(')');
						goto mid;
					case ')':
						push(')');
						push(')');
						goto mid;
				}
			case '{': //Abre llaves
				switch(pop()){
					case '$':
						push('$');
						push('}');
						goto mid;
					case ')':
						push(')');
						push('}');
						goto mid;
					case ']':
						push(']');
						push('}');
						goto mid;
					case '}':
						push('}');
						push('}');
						goto mid;
				}
			case '[': //Abre corchetes
				switch(pop()){
					case '$':
						push('$');
						push(']');
						goto mid;
					case ')':
						push(')');
						push(']');
						goto mid;
					case '}':
						push('}');
						push(']');
						goto mid;
					case ']':
						push(']');
						push(']');
						goto mid;
				}
			case ')': //Cierra parentesis
				if(pop() == ')')
					goto mid;
				goto error;
			case '}': //Cierra llaves
				if(pop() == '}')
					goto mid;
				goto error;
			case ']': //Cierra corchetes
				if(pop() == ']')
					goto mid;
				goto error;
			case EOF: //Fin del archivo
				if(pop() == '$')
					goto end;
				goto error;
			case '\'': //Literal caracter
				goto literalCaracter;
			case '\"': //Literal cadena
				goto literalCadena;
			case '/': //Comentarios
			    goto posibleComment;
			default:
				goto mid;
		}

    literalCaracter: 
		switch(getchar()){
			case '\'': //Al leer ' finaliza el literal caracter
				goto mid;
			case '\\': //Secuencia de escape, se ignora el siguiente caracter
                getchar();
                goto literalCaracter;                 
			default:
				goto literalCaracter;
		}
	
	literalCadena:
		switch(getchar()){
			case '\"': //Finaliza el literal con "
				goto mid;
			case '\\': //Secuencia de escape, se ignora el siguiente caracter
                getchar();
                goto literalCadena;
			default:
				goto literalCadena;
		}
	    
	posibleComment: //Si se recibe un / se entra en estado posible comentario
        switch(getchar()){
            case '/': //Al recibir otro / -> Comentario de una linea
                 goto singleLineComment;
            case '*': //Al recibir un * -> Comentario de multiples lineas
                 goto multiLineComment;
            default: //Si se recibe algo distinto, no se trataba de un comentario
                 goto mid;
        }
    
    singleLineComment: //Se ignoran los caracteres hasta el cambio de linea
         switch(getchar()){
             case '\n':
                  goto mid;
             default:
                  goto singleLineComment;                       
         }   
                          
	multiLineComment: //Se ignoran los caracteres hasta leer un asterisco
        switch(getchar()){
            case '*': //Al leer un asterisco, es posible que se tenga que salir del estado comentario.
                 goto pOutMLComment;
            default:
                 goto multiLineComment;
        }
    
    pOutMLComment: //Estado de posible salida de comentario
        switch(getchar()){
            case '/': //Fin comentario
                goto mid;
            case '*': //Caso especial "/***/"
                 goto pOutMLComment;
            default:
                goto multiLineComment;
        }
    
	end://Estado de fin satisfactorio
		printf("\nLos parentesis), llaves y corchetes estan balanceados.");
		return 0;
		
	error://Estado de fin erroneo
		printf("\nLos parentesis, llaves y corchetes no estan balanceados.");
        return 0;
}

