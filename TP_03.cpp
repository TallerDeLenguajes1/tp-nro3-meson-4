#include <stdlib.h>
#include <stdio.h>

enum TRaza{Orco = 1, Humano, Mago, Enano, Elfo};
char Nombres[10][10]={'Rock', 'G', 'C', 'D', 'P'};
char Apellidos[10][10]={'Azul', 'V', 'S', 'D', 'B'};

struct TDatos {
	TRaza Raza; //nota 1
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

void Cargar_DatPj(struct TDatos);
void Mostrar_DatPj(struct TDatos);

int main()
{
	struct TDatos pj1;
	Cargar_DatPj(pj1);
	Mostrar_DatPj(pj1);
	
	return 0;
}

void Cargar_DatPj(struct TDatos Personaje){
	srand(time(NULL));
	Personaje.Raza = 1 + rand() % 5;
	Personaje.ApellidoNombre

}

void Mostrar_DatPj(struct TDatos Personaje){
	printf("Raza: ");
	switch(Personaje.Raza){
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
	}
}