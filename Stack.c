
#define MAX 99999999
char stack[MAX];
int pointer = 0;

void push(char e){
	stack[pointer] = e;
	pointer++;
}

char pop(){
	pointer--;
	return stack[pointer];
}
