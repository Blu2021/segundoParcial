#ifndef LIBROS_H_
#define LIBROS_H_

typedef struct
{
	int idLibro;
	char titulo[131];
	char autor[31];
	float precio;
	int idEditorial;
}eLibros;

typedef struct
{
	int idEditorial;
	char nombreEditorial[31];
}eEditorial;

eLibros* libro_newParametros(char* idStr,char* title,char* author,char* price,char* editorial,
							eEditorial* editoriales,int tamEdit);
int libro_setId(eLibros* this,int id);
int libro_setPrecio(eLibros* this,float price);
int libro_setTitulo(eLibros* this,char* nombre);
int libro_setAutor(eLibros* this,char* nombre);
int libro_setIdEditorial(eLibros* this,int idEditorial);
int libro_getId(eLibros* this,int* id);
int libro_getTitulo(eLibros* this,char* titulo);
int libro_getAutor(eLibros* this,char* autor);
int libro_getPrecio(eLibros* this,float* precio);
int libro_getIdEditorial(eLibros* this,int* id);
int consigue_IdEditorial(char* descripcion,int* id,eEditorial* editorial,int tamEdit);
int consigue_DescEditorial(int id,char* descripcion,eEditorial* editorial,int tamEdit);
int aplicarDescuentos(void *libroRecibido);
int ordenarPorAutor(void* libroUno,void* libroDos);

#endif /* LIBROS_H_ */
