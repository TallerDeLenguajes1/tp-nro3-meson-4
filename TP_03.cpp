//bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//prototipos
enum TRaza{Orco, Humano, Mago, Enano, Elfo};
char Nombres[6][10]={"ale", "b", "c", "d", "e"};
char Apellidos[6][10]={"f", "g", "hormiga", "i", "j"};
//estructuras
struct TDatos {
	TRaza Raza; //nota 1
	char *ApellidoNombre; //nota 2
	int edad; //entre 0 a 300
	double Salud;//100
};
typedef struct TDatos TDatos;

struct TCaracteristicas{
	int velocidad;// 1 a 10
	int destreza; //1 a 5
	int fuerza;//1 a 10
	int Nivel; //1 a 10
	int Armadura; //1 a 10
};
typedef struct TCaracteristicas TCaracteristicas;

struct TPersonaje {
	TDatos * DatosPersonales;
	TCaracteristicas * Caracteristicas;
};
typedef struct TPersonaje TPersonaje;

void CargarCarac(TCaracteristicas *puntCarac);
void MostrarCarac(TCaracteristicas *puntCarac);

int main(void)
{	
	srand(time(NULL));
	TCaracteristicas Carac, *puntCarac;

	puntCarac = (TCaracteristicas *)malloc(sizeof(TCaracteristicas));
	puntCarac = &Carac;

	CargarCarac(puntCarac);
	MostrarCarac(puntCarac);




	return 0;
}

void CargarCarac(TCaracteristicas *puntCarac){

	int numAle;

	numAle = rand()% 10;
	(*puntCarac).velocidad= numAle;

	numAle = rand()% 5;
	(*puntCarac).destreza= numAle;

	numAle = rand()% 10;
	(*puntCarac).fuerza = numAle;

	numAle = rand()% 10;
	(*puntCarac).Nivel = numAle;

	numAle = rand()% 10;
	(*puntCarac).Armadura = numAle;

}

void MostrarCarac(TCaracteristicas *puntCarac){
	printf("Caracteristicas del poder de tu personaje: \n\n");
	printf("La velocidad del personaje es: %d.\n", (*puntCarac).velocidad);
	printf("Su puntaje de destreza es: %d.\n", (*puntCarac).destreza);
	printf("Tiene una fuerza de: %d de poder.\n", (*puntCarac).fuerza);
	printf("El nivel de batalla del personaje es: %d.\n", (*puntCarac).Nivel);
	printf("El poder de la armadura: %d.\n", (*puntCarac).Armadura);
}