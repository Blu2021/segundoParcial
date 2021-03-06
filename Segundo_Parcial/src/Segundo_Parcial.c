//DAUD MANZO JUAN PABLO
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "blu2021.h"
#include "libros.h"
#include "controlador_libreria.h"

#define EDITORIALES 6

int main(void)
{
	setbuf(stdout,NULL);

	int opcionMenu;
	int entroAlUno=0;
	int entroAlCuatro=0;
	char nombreArchivo[31];
	LinkedList* listaLibros=ll_newLinkedList();
	eEditorial editoriales[EDITORIALES]={{1,"PLANETA"},{2,"SIGLO XXI EDITORES"},{3,"PEARSON"},
					                     {4,"MINOTAURO"},{5,"SALAMANDRA"},{6,"PENGUIN BOOKS"}};

	if(listaLibros!=NULL)
	{
		do
		{
			printf("Bienvenido al Menu de la Libreria\n"
				   "1. Cargar los datos de los libros desde el archivo datos.csv\n"
				   "2. Ordenar libros por autor de manera ascendente - a +\n"
				   "3. Imprimir listado de libros\n"
				   "4. Aplicar descuento a libros que entran en la promo\n"
				   "5. Guardar listado con descuentos en mapeado.csv\n"
				   "6. Salir\n");
			utn_levantaEnteros(&opcionMenu,"Ingrese opcion de menu","ERROR,opcion invalida",1,6);

			switch(opcionMenu)
			{
				case 1:
					utn_levantaCadenaCaracteres(nombreArchivo,"Ingrese nombre archivo","ERROR",31);
					if(controller_loadFromText(nombreArchivo,listaLibros,editoriales,EDITORIALES))
					{
						entroAlUno=1;
					}
					else
					{
						printf("No se encuentra el archivo ingresado,verifique por favor\n");
					}
					system("pause");
				break;
				case 2:
					if(!controller_sortLibrary(listaLibros))
					{
						printf("No hay Libros cargados cuales ordenar o solamente hay un Libro cargado\n");
					}
					system("pause");
				break;
				case 3:
					if(!controller_ListLibrary(listaLibros,editoriales,EDITORIALES))
					{
						printf("No hay libros cargados cuales listar\n");
					}
					system("pause");
				break;
				case 4:
					if(entroAlUno&&entroAlCuatro==0)
					{
						if(!controller_aplicarDescuentos(listaLibros,editoriales,EDITORIALES))
						{
							printf("No ha cargado ninguna libreria a la cual aplicar descuentos\n");
						}
						else
						{
							entroAlCuatro=1;
						}
					}
					else
					{
						printf("Ud no cargo el archivo ? ya utilizo sus descuentos\n");
					}
					system("pause");
				break;
				case 5:
					controller_saveAsText("mapeado.csv",listaLibros,editoriales,EDITORIALES);
					system("pause");
				break;
				case 6:
					printf("Saliendo de libreria... gracias por su visita\n");
				break;
			}
		}while(opcionMenu!=6);
	}

	return 0;
}
