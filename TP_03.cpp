//bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

enum TRaza{Orco = 1, Humano, Mago, Enano, Elfo};
char Nombres[6][30]={"Rocket", "Gato", "Chubaca", "Pikachu", "Perro", "Capitan"};
char Apellidos[6][30]={" Cansado", " Pro", " Loco", " Malo", " Traumado", " Bueno"};

struct TDatos {
	enum TRaza Raza; //nota 1
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

void Cargar_DatPj(struct TDatos *);
void Mostrar_DatPj(struct TDatos *);
void CargarCarac(TCaracteristicas *puntCarac);
void MostrarCarac(TCaracteristicas *puntCarac);

int main(void)
{	
	srand(time(NULL));
	struct TDatos Dat, *pDat;
	pDat = (TDatos *) malloc(sizeof(TDatos));
	pDat = &Dat;

	TCaracteristicas Carac, *puntCarac;

	puntCarac = (TCaracteristicas *)malloc(sizeof(TCaracteristicas));
	puntCarac = &Carac;

	Cargar_DatPj(pDat);
	Mostrar_DatPj(pDat);
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
//Funcion Cargar datos del personaje
void Cargar_DatPj(struct TDatos *DatosPj){
	int ale = 1 + rand() % (5-1);
	DatosPj->Raza = ale;
	ale = 0 + rand() % (5-0);
	strcpy(DatosPj->ApellidoNombre, Nombres[ale]); //Copio la cadena de nombres aleatoriamente
	ale = 0 + rand() % (5-0);
	strcat(DatosPj->ApellidoNombre, Apellidos[ale]);//Junto la cadena anterior con un apellido aleatorio
	ale = 0 + rand() % (300-0);
	DatosPj->edad = ale;
	DatosPj->Salud = 100;
}

//Funcion Mostrar datos del personaje
void Mostrar_DatPj(struct TDatos *DatosPj){
	printf("Datos del personaje:\n\nRaza: ");
	switch((*DatosPj).Raza){
		case 1: printf("Orco\n");
		break;
		case 2: printf("Humano\n");
		break;
		case 3: printf("Mago\n");
		break;
		case 4: printf("Enano\n");
		break;
		case 5: printf("Elfo\n");
		break;
		default: printf("Error\n");
	}
	printf("Nombre: %s\n", (*DatosPj).ApellidoNombre);
	printf("Edad: %d\n", (*DatosPj).edad);
	printf("Salud: %.3f\n\n", (*DatosPj).Salud);
}