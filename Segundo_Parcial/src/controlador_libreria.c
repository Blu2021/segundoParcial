#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "libros.h"
#include "parser_libreria.h"
#include "blu2021.h"
#include "controlador_libreria.h"

int controller_loadFromText(char* path , LinkedList* pArrayListaLibros,eEditorial* editoriales,int tamEdit)
{
	int exito=0;
	FILE* punteroArchivo;

	punteroArchivo=fopen(path,"r");

	//ll_clear(pArrayListaLibros);

	if(punteroArchivo!=NULL)
	{
		if(parser_libraryFromText(punteroArchivo,pArrayListaLibros,editoriales,tamEdit))
		{
			exito=1;
			printf("Datos cargados desde texto con exito\n");
		}
		else
		{
			system("pause");
		}
	}
	fclose(punteroArchivo);

    return exito;
}

int controller_sortLibrary(LinkedList* pArrayListaLibros)
{
	int exito=0;
	int opcionOrdenar;
	int dimensionLinkedList;

	dimensionLinkedList=ll_len(pArrayListaLibros);

	if(dimensionLinkedList>1&&pArrayListaLibros!=NULL)
	{
		utn_levantaEnteros(&opcionOrdenar,"Ingrese opcion de ordenamiento\n"
										  "ordenar por Autores: 1","ERROR",1,1);
		switch(opcionOrdenar)
		{
			case 1:
				if(!ll_sort(pArrayListaLibros,ordenarPorAutor,1))
				{
					exito=1;
					printf("Libros ordenados por autor de 'a' hasta 'z'\n");
				}
			break;
		}
	}
	else
	{
		 exito=0;
	}

    return exito;
}

int controller_ListLibrary(LinkedList* pArrayListaLibros,eEditorial* editoriales,int tamEdit)
{
	int exito=0;
	int i;
	int dimensionLinkedList;
	eLibros* auxDirMemLibros;
	char auxDescripcion[31];

	dimensionLinkedList=ll_len(pArrayListaLibros);

	if(pArrayListaLibros!=NULL&&dimensionLinkedList>0)
	{
		exito=1;

		for(i=0;i<dimensionLinkedList;i++)
		{
			auxDirMemLibros=ll_get(pArrayListaLibros,i);
			if(i==0)
			{
				printf("------------------------------------**********LIBROS***********---------------------------------------\n");
				printf("IdLibro    Titulo                                             Autor                Precio    Editorial\n");
			}
			consigue_DescEditorial((*auxDirMemLibros).idEditorial,auxDescripcion,editoriales,tamEdit);
			printf("%-11d%-51s%-21s%-10.2f%s\n",(*auxDirMemLibros).idLibro,(*auxDirMemLibros).titulo,(*auxDirMemLibros).autor,(*auxDirMemLibros).precio,auxDescripcion);
		}
	}
    return exito;
}

int controller_aplicarDescuentos(LinkedList* pArrayListaLibros,eEditorial* editoriales,int tamEdit)
{
	int exito=0;
	//LinkedList* descuentosAplicados=NULL;

	if(pArrayListaLibros!=NULL&&ll_isEmpty(pArrayListaLibros)==0)
	{
		//descuentosAplicados=
		ll_map(pArrayListaLibros,aplicarDescuentos);
		printf("Descuentos aplicados,gracias por elegirnos\n");
		exito=1;
	}

	//controller_saveAsText("mapeadoPRUEBA.csv",pArrayListaLibros,editoriales,tamEdit);
	//ll_deleteLinkedList(descuentosAplicados);

	return exito;
}

int controller_saveAsText(char* path , LinkedList* pArrayListaLibros,eEditorial* editoriales,int tamEdit)
{
	int exito=0;
	FILE* punteroArchivo;
	int dimensionLinkedList;
	int i;
	eLibros* auxDirMemLibro;
	int auxId;
	char auxTitulo[131];
	char auxAutor[31];
	float auxPrecio;
	int auxIdEditorial;
	char auxDescripcion[31];

	punteroArchivo=fopen(path,"w");
	dimensionLinkedList=ll_len(pArrayListaLibros);

	if(path!=NULL&&pArrayListaLibros!=NULL&&punteroArchivo!=NULL&&dimensionLinkedList>0)
	{
		exito=1;
		fprintf(punteroArchivo,"id,titulo,autor,precio,editorialId\n");
		for(i=0;i<dimensionLinkedList;i++)
		{
			auxDirMemLibro=ll_get(pArrayListaLibros,i);
			libro_getId(auxDirMemLibro,&auxId);
			libro_getTitulo(auxDirMemLibro,auxTitulo);
			libro_getAutor(auxDirMemLibro,auxAutor);
			libro_getPrecio(auxDirMemLibro,&auxPrecio);
			libro_getIdEditorial(auxDirMemLibro,&auxIdEditorial);
			consigue_DescEditorial(auxIdEditorial,auxDescripcion,editoriales,tamEdit);
			fprintf(punteroArchivo,"%d,%s,%s,%.2f,%s\n",auxId,auxTitulo,auxAutor,auxPrecio,auxDescripcion);
		}
		fclose(punteroArchivo);
		printf("Datos guardados con exito(modo texto)\n");
	}
	return exito;
}
