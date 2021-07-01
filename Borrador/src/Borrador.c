#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i;
	//EJEMPLO UNO
	char *caracteres[5]={"uno","dos","tres","cuatro","cinco"};
	//EJEMPLO DOS
	char cadenaCaracteres[5][7];
	//EJEMPLO UNO
	for(i=0;i<5;i++)
	{
		printf("Soy un array de caracteres %s\n",*(caracteres+i));
	}
	//EJEMPLO DOS
	for(i=0;i<5;i++)
	{
		strcpy((*(cadenaCaracteres+i)),"String");
		printf("Soy un array de caracteres %s\n",*(cadenaCaracteres+i));
	}

	return 0;
}


