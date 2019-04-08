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
void Pelea(struct TPersonaje *, int, int);

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
	char temp[60];
	

	strcpy(temp, Nombres[ale]); //Copio la cadena de nombres aleatoriamente
	ale = 0 + rand() % (5-0);
	strcat(temp, Apellidos[ale]);//Junto la cadena anterior con un apellido aleatorio

	(*DatosPj).ApellidoNombre = (char *) malloc(sizeof(temp));
	strcpy((*DatosPj).ApellidoNombre, temp); //Copio la cadena de nombres aleatoriamente

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
	printf("Elija el numero del personaje que quiere seleccionar: \n");
	scanf("%d", &i);
	return(i);
}

void Pelea(struct TPersonaje *Personaje, int uno, int dos){
	printf("\n-----------La pelea entre los dos personajes comienza-----------\n");
	uno--; dos--;
	float Danio, MDP = 50000;
	int PD, PDEF, ED, VA, ale, j=0;
	for (int i = 0; i < 3; ++i)
	{
		printf("\n-----------RONDA %d-----------\n", ++j);
		//ATAQUE DEL PRIMER PERSONAJE
		PD = Personaje[uno].Caracteristicas->destreza * Personaje[uno].Caracteristicas->fuerza * Personaje[uno].Caracteristicas->Nivel;
		ale = 1 + rand() % 100;
		ED = ale;
		VA = PD * ED;
		PDEF = Personaje[dos].Caracteristicas->Armadura * Personaje[dos].Caracteristicas->velocidad;

		Danio = (float)((VA-PDEF)/MDP)*100;		
		Personaje[dos].DatosPersonales->Salud = Personaje[dos].DatosPersonales->Salud - Danio;
		printf("La cantidad de danio provocado por %s a %s fue de: %.3f\n",Personaje[uno].DatosPersonales->ApellidoNombre, Personaje[dos].DatosPersonales->ApellidoNombre, Danio);
		if (Personaje[dos].DatosPersonales->Salud < 0)
		{
			Personaje[dos].DatosPersonales->Salud = 0;
		}
		printf("%s quedo con %.3f de salud\n",Personaje[dos].DatosPersonales->ApellidoNombre, Personaje[dos].DatosPersonales->Salud);

		if (Personaje[dos].DatosPersonales->Salud <= 0)
		{
			i = 3;
		}else{
			//ATAQUE DEL SEGUNDO PERSONAJE
			PD = Personaje[dos].Caracteristicas->destreza * Personaje[dos].Caracteristicas->fuerza * Personaje[dos].Caracteristicas->Nivel;
			ale = 1 + rand() % 100;
			ED = ale;
			VA = PD * ED;
			PDEF = Personaje[uno].Caracteristicas->Armadura * Personaje[uno].Caracteristicas->velocidad;

			Danio = (float)((VA-PDEF)/MDP)*100;
			
			Personaje[uno].DatosPersonales->Salud = Personaje[uno].DatosPersonales->Salud - Danio;
			printf("La cantidad de danio provocado por %s a %s fue de: %.3f\n",Personaje[dos].DatosPersonales->ApellidoNombre, Personaje[uno].DatosPersonales->ApellidoNombre, Danio);
			if (Personaje[uno].DatosPersonales->Salud < 0)
			{
				Personaje[uno].DatosPersonales->Salud = 0;
			}
			printf("%s quedo con %.3f de salud\n",Personaje[uno].DatosPersonales->ApellidoNombre, Personaje[uno].DatosPersonales->Salud);
			if (Personaje[uno].DatosPersonales->Salud <= 0)
			{
				i = 3;
			}
		}
	}

	if (Personaje[uno].DatosPersonales->Salud == Personaje[dos].DatosPersonales->Salud)
	{
		printf("\n%s y %s han empatado\n", Personaje[uno].DatosPersonales->ApellidoNombre, Personaje[dos].DatosPersonales->ApellidoNombre);
	}

	if (Personaje[uno].DatosPersonales->Salud > Personaje[dos].DatosPersonales->Salud) 
	{
		printf("\nEl personaje: %s a ganado\n", Personaje[uno].DatosPersonales->ApellidoNombre);
	}
	if (Personaje[uno].DatosPersonales->Salud < Personaje[dos].DatosPersonales->Salud){
		printf("\nEl personaje: %s a ganado\n", Personaje[dos].DatosPersonales->ApellidoNombre);
	}

}