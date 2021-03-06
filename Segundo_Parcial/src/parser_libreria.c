#include <stdio.h>
#include <stdlib.h>
#include "libros.h"
#include "LinkedList.h"

int parser_libraryFromText(FILE* pFile , LinkedList* pArrayListaLibros,eEditorial* editoriales,int tamEdit)
{
	int exito=0;
	char buffer[5][131];

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4));

	while(!feof(pFile))
	{
		eLibros* punteroLibro=NULL;

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4));

		punteroLibro=libro_newParametros(*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4),editoriales,tamEdit);
		if(punteroLibro!=NULL)
		{
			ll_add(pArrayListaLibros,(eLibros*)punteroLibro);
			exito=1;
		}
	}
    return exito;
}
