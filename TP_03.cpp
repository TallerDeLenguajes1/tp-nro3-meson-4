//bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define M 5

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
int Eleccion();
void Pelea(TPersonaje *, int, int);

int main(void)
{	
	srand(time(NULL));
	int n, ppj, spj;
	//struct TDatos Dat, *pDat;
	struct TPersonaje *PJ;

	/*pDat = (TDatos *) malloc(sizeof(TDatos));
	pDat = &Dat;
	TCaracteristicas Carac, *puntCarac;
	puntCarac = (TCaracteristicas *)malloc(sizeof(TCaracteristicas));
	puntCarac = &Carac;

	Cargar_DatPj(pDat);
	Mostrar_DatPj(pDat);
	CargarCarac(puntCarac);
	MostrarCarac(puntCarac);
	printf("--------------------\n");*/

	printf("Ingrese cuantos personajes desea cargar: ");
	scanf("%d", &n);
	PJ = (TPersonaje *) malloc(n * sizeof(TPersonaje)); //asigno el tamaño al arreglo de estructura

	for (int i = 0; i < n; i++)//Cargo y muestro los personajes con sus datos y caracteristicas
	{
		int j = i;
		j++;
		printf("\nPERSONAJE %d:\n", j);
		PJ[i].DatosPersonales = (TDatos *) malloc(sizeof(TDatos));
		PJ[i].Caracteristicas = (TCaracteristicas *)malloc(sizeof(TCaracteristicas));
		Cargar_DatPj((PJ + i)->DatosPersonales);
		CargarCarac((PJ + i)->Caracteristicas);
		Mostrar_DatPj(PJ[i].DatosPersonales);
		MostrarCarac(PJ[i].Caracteristicas);
	}

	//Eleccion de personajes
	printf("\n-------------------------------\n");
	ppj = Eleccion();
	spj = Eleccion();
	Pelea(PJ, ppj, spj);


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
	DatosPj->Raza = (TRaza)ale;
	ale = 0 + rand() % (5-0);

	(*DatosPj).ApellidoNombre = (char *) malloc(sizeof(char));

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

int Eleccion(){
	int i;
	printf("Elija personaje: \n");
	scanf("%d", &i);
	return(i);
}

void Pelea(TPersonaje *Personaje, int uno, int dos){
	printf("La pelea entre los dos personajes comienza\n");
	uno--; dos--;
	int PD, ED, VA, PDEF, MDP = 50000, ale = 1 + rand() % 100, Danio;
	for (int i = 0; i < 3; ++i)
	{
		//ATAQUE DEL PRIMER PERSONAJE
		PD = Personaje[uno].Caracteristicas.destreza * Personaje[uno].Caracteristicas.fuerza * Personaje[uno].Caracteristicas.Nivel;
		ED = ale/100;
		VA = PD * ED;
		PDEF = Personaje[dos].Caracteristicas.armadura * Personaje[dos].Caracteristicas.velocidad;

		if (PDEF > VA)
		{
			Danio = 0;
		}else {
			Danio = VA - PDEF;
		}

		if (Danio > MDP)
		{
			Danio = MDP;
		}
		
		Personaje[dos].DatosPersonales.Salud = Personaje[dos].DatosPersonales.Salud - Danio;
		printf("La cantidad de danio provocado del primer personaje al segundo fue de: %d\n", Danio);
		printf("El segundo personaje quedo con %.2f de salud\n", Personaje[dos].DatosPersonales.Salud);
	}

}