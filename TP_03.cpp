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
struct TCaracteristicas{
	int velocidad;// 1 a 10
	int destreza; //1 a 5
	int fuerza;//1 a 10
	int Nivel; //1 a 10
	int Armadura; //1 a 10
};
struct TPersonaje {
	TDatos * DatosPersonales;
	TCaracteristicas * Caracteristicas;
};

void Cargar_DatPj(struct TDatos *);
void Mostrar_DatPj(struct TDatos *);

int main()
{
	srand(time(NULL));
	struct TDatos Dat, *pDat;
	pDat = (TDatos *) malloc(sizeof(TDatos));
	pDat = &Dat;


	Cargar_DatPj(pDat);
	Mostrar_DatPj(pDat);
	
	return 0;
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
	printf("Datos del personaje:\nRaza: ");
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
	printf("Salud: %.3f\n", (*DatosPj).Salud);
}