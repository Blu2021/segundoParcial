#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libros.h"

eLibros* libro_newParametros(char* idStr,char* title,char* author,char* price,char* editorial,
							eEditorial* editoriales,int tamEdit)
{
	eLibros* punteroLibro;
	int auxIdEditorial;

	punteroLibro=((eLibros*)malloc(sizeof(eLibros)));

	if(punteroLibro!=NULL)
	{
		libro_setId(punteroLibro,atoi(idStr));
		libro_setPrecio(punteroLibro,atof(price));
		libro_setTitulo(punteroLibro,title);
		libro_setAutor(punteroLibro,author);
		consigue_IdEditorial(editorial,&auxIdEditorial,editoriales,tamEdit);
		libro_setIdEditorial(punteroLibro,auxIdEditorial);
	}

	return punteroLibro;
}

int libro_setId(eLibros* this,int id)
{
	int exito=0;

	if(this!=NULL)
	{
		exito=1;
		(*this).idLibro=id;
	}
	return exito;
}

int libro_setPrecio(eLibros* this,float price)
{
	int exito=0;

	if(this!=NULL)
	{
		exito=1;
		(*this).precio=price;
	}
	return exito;
}

int libro_setTitulo(eLibros* this,char* nombre)
{
	int exito=0;

	if(this!=NULL)
	{
		exito=1;
		strcpy((*this).titulo,nombre);
	}

	return exito;
}

int libro_setAutor(eLibros* this,char* nombre)
{
	int exito=0;

	if(this!=NULL)
	{
		exito=1;
		strcpy((*this).autor,nombre);
	}

	return exito;
}

int libro_setIdEditorial(eLibros* this,int idEditorial)
{
	int exito=0;

	if(this!=NULL)
	{
		exito=1;
		(*this).idEditorial=idEditorial;
	}

	return exito;
}

int libro_getId(eLibros* this,int* id)
{
	int exito=0;

	if(this!=NULL&&id!=NULL)
	{
		exito=1;
		*id=(*this).idLibro;
	}

	return exito;
}

int libro_getTitulo(eLibros* this,char* titulo)
{
	int exito=0;

	if(this!=NULL&&titulo!=NULL)
	{
		exito=1;
		strcpy(titulo,(*this).titulo);
	}

	return exito;
}

int libro_getAutor(eLibros* this,char* autor)
{
	int exito=0;

	if(this!=NULL&&autor!=NULL)
	{
		exito=1;
		strcpy(autor,(*this).autor);
	}

	return exito;
}

int libro_getPrecio(eLibros* this,float* precio)
{
	int exito=0;

	if(this!=NULL&&precio!=NULL)
	{
		exito=1;
		*precio=(*this).precio;
	}

	return exito;
}

int libro_getIdEditorial(eLibros* this,int* id)
{
	int exito=0;

	if(this!=NULL&&id!=NULL)
	{
		exito=1;
		*id=(*this).idEditorial;
	}

	return exito;
}

int consigue_IdEditorial(char* descripcion,int* id,eEditorial* editorial,int tamEdit)
{
	int exito=0;
	int i;
	int auxId=*id;

	if(descripcion!=NULL)
	{
		for(i=0;i<tamEdit;i++)
		{
			strupr(descripcion);
			if(strcmp((*(editorial+i)).nombreEditorial,descripcion)==0)
			{
				auxId=(*(editorial+i)).idEditorial;
				*id=auxId;
				exito=1;
				break;
			}
		}
	}

	return exito;
}

int consigue_DescEditorial(int id,char* descripcion,eEditorial* editorial,int tamEdit)
{
	int exito=0;
	int i;

	for(i=0;i<tamEdit;i++)
	{
		if((*(editorial+i)).idEditorial==id)
		{
			strcpy(descripcion,(*(editorial+i)).nombreEditorial);
			exito=1;
			break;
		}
	}

	return exito;
}

int aplicarDescuentos(void *libroRecibido)
{
	 int exito=0;
	 int auxEditorial;
	 float auxPrecio;

	 if(libroRecibido!=NULL)
	 {
		auxEditorial=(*(eLibros*)(libroRecibido)).idEditorial;

		switch(auxEditorial)
		{
			case 1:
				auxPrecio=(*(eLibros*)(libroRecibido)).precio;
				if(auxPrecio>299)
				{
					auxPrecio=auxPrecio-(auxPrecio*20)/100;
					(*(eLibros*)(libroRecibido)).precio=auxPrecio;
				}
			break;
			case 2:
				auxPrecio=(*(eLibros*)(libroRecibido)).precio;
				if(auxPrecio<201)
				{
					auxPrecio=auxPrecio-(auxPrecio*10)/100;
					(*(eLibros*)(libroRecibido)).precio=auxPrecio;
				}
			break;
		}
		 exito=1;
	 }

	 return exito;
}

int ordenarPorAutor(void* libroUno,void* libroDos)
{
	int orden=0;
	eLibros* libroU=libroUno;
	eLibros* libroD=libroDos;

	if(strcmp((*libroU).autor,(*libroD).autor)>0)
	{
		orden=1;
	}

	return orden;
}
