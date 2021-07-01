#include "libros.h"
#ifndef CONTROLADOR_LIBRERIA_H_
#define CONTROLADOR_LIBRERIA_H_

int controller_loadFromText(char* path , LinkedList* pArrayListaLibros,eEditorial* editoriales,int tamEdit);
int controller_saveAsText(char* path , LinkedList* pArrayListaLibros,eEditorial* editoriales,int tamEdit);
int controller_ListLibrary(LinkedList* pArrayListaLibros,eEditorial* editoriales,int tamEdit);
int controller_sortLibrary(LinkedList* pArrayListaLibros);
int controller_aplicarDescuentos(LinkedList* pArrayListaLibros,eEditorial* editoriales,int tamEdit);

#endif /* CONTROLADOR_LIBRERIA_H_ */
