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
	TPersonaje * siguiente;
};
typedef struct TPersonaje TPersonaje;


void Cargar_DatPj(struct TDatos *);
void Mostrar_DatPj(struct TDatos *);
void CargarCarac(TCaracteristicas *puntCarac);
void MostrarCarac(TCaracteristicas *puntCarac);
int Eleccion();
void Pelea(struct TPersonaje *);
void AgregarPersonaje(TPersonaje **, int);
void MostrarPersonajes(TPersonaje *);
void Eleccion_Lista(TPersonaje *, TPersonaje **, int);
int SeleccionMenu();
void Menu(struct TPersonaje *);
void EliminarPersonaje(TPersonaje **);
void MostrarUnPersonaje(TPersonaje *);
void EliminacionPorPelea(TPersonaje **, int);

int main(void)
{	
	srand(time(NULL));
	TPersonaje *PJ = NULL;

	//MENU CON TODAS LAS OPERACIONES DE LISTA
	Menu(PJ);	

	return 0;
}

void CargarCarac(TCaracteristicas *puntCarac){

	int numAle;

	numAle = 1 + rand()% 10;
	(*puntCarac).velocidad= numAle;

	numAle = 1 + rand()% 5;
	(*puntCarac).destreza= numAle;

	numAle = 1 + rand()% 10;
	(*puntCarac).fuerza = numAle;

	numAle = 1 + rand()% 10;
	(*puntCarac).Nivel = numAle;

	numAle = 1 + rand()% 10;
	(*puntCarac).Armadura = numAle;

}

void MostrarCarac(TCaracteristicas *puntCarac){
	printf("((((((((Caracteristicas del poder de tu personaje: ))))))))\n\n");
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
	ale = 0 + rand() % (6);
	char temp[60];
	

	strcpy(temp, Nombres[ale]); //Copio la cadena de nombres aleatoriamente
	ale = 0 + rand() % (6);
	strcat(temp, Apellidos[ale]);//Junto la cadena anterior con un apellido aleatorio

	(*DatosPj).ApellidoNombre = (char *) malloc(sizeof(temp));
	strcpy((*DatosPj).ApellidoNombre, temp); //Copio la cadena de nombres aleatoriamente

	ale = 0 + rand() % (300-0);
	DatosPj->edad = ale;
	DatosPj->Salud = 100;
}

//Funcion Mostrar datos del personaje
void Mostrar_DatPj(struct TDatos *DatosPj){
	printf("((((((((Datos del personaje:))))))))\n\nRaza: ");
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
	printf("[[[[Elija el numero del personaje que quiere seleccionar:]]]] \n");
	scanf("%d", &i);
	return(i);
}

void Pelea(struct TPersonaje *Personaje){
	float Danio, MDP = 50000;
	int PD, PDEF, ED, VA, ale, j = 0, uno, dos;
	TPersonaje *PJ1, *PJ2;

	
	uno = Eleccion();//ELECCION DEL PRIMER PERSONAJE
	dos = Eleccion();//ELECCION DEL SEGUNDO PERSONAJE
	Eleccion_Lista(Personaje, &PJ1, uno);//SELECCIONA EL PRIMER PERSONAJE DESDE LA LISTA
	Eleccion_Lista(Personaje, &PJ2, dos);//SELECCIONA EL SEGUNDO PERSONAJE DESDE LA LISTA

	printf("\n-----------La pelea entre %s y %s comienza-----------\n", PJ1->DatosPersonales->ApellidoNombre, PJ2->DatosPersonales->ApellidoNombre);
	for (int i = 0; i < 3; ++i)
	{
		printf("\n-----------RONDA %d-----------\n", ++j);
		//ATAQUE DEL PRIMER PERSONAJE
		PD = PJ1->Caracteristicas->destreza * PJ1->Caracteristicas->fuerza * PJ1->Caracteristicas->Nivel;
		ale = 1 + rand() % 100;
		ED = ale;
		VA = PD * ED;
		PDEF = PJ2->Caracteristicas->Armadura * PJ2->Caracteristicas->velocidad;

		Danio = (float)((VA-PDEF)/MDP)*100;		
		PJ2->DatosPersonales->Salud = PJ2->DatosPersonales->Salud - Danio;
		printf("La cantidad de danio provocado por %s a %s fue de: %.3f\n",PJ1->DatosPersonales->ApellidoNombre, PJ2->DatosPersonales->ApellidoNombre, Danio);
		if (PJ2->DatosPersonales->Salud < 0)
		{
			PJ2->DatosPersonales->Salud = 0;
		}
		printf("%s quedo con %.3f de salud\n",PJ2->DatosPersonales->ApellidoNombre, PJ2->DatosPersonales->Salud);

		if (PJ2->DatosPersonales->Salud <= 0)
		{
			i = 3;
		}else{
			//ATAQUE DEL SEGUNDO PERSONAJE
			PD = PJ2->Caracteristicas->destreza * PJ2->Caracteristicas->fuerza * PJ2->Caracteristicas->Nivel;
			ale = 1 + rand() % 100;
			ED = ale;
			VA = PD * ED;
			PDEF = PJ1->Caracteristicas->Armadura * PJ1->Caracteristicas->velocidad;

			Danio = (float)((VA-PDEF)/MDP)*100;
			
			PJ1->DatosPersonales->Salud = PJ1->DatosPersonales->Salud - Danio;
			printf("La cantidad de danio provocado por %s a %s fue de: %.3f\n",PJ2->DatosPersonales->ApellidoNombre, PJ1->DatosPersonales->ApellidoNombre, Danio);
			if (PJ1->DatosPersonales->Salud < 0)
			{
				PJ1->DatosPersonales->Salud = 0;
			}
			printf("%s quedo con %.3f de salud\n",PJ1->DatosPersonales->ApellidoNombre, PJ1->DatosPersonales->Salud);
			if (PJ1->DatosPersonales->Salud <= 0)
			{
				i = 3;
			}
		}
	}

	if (PJ1->DatosPersonales->Salud == PJ2->DatosPersonales->Salud)
	{
		printf("\n%s y %s han empatado\n", PJ1->DatosPersonales->ApellidoNombre, PJ2->DatosPersonales->ApellidoNombre);
	}

	if (PJ1->DatosPersonales->Salud > PJ2->DatosPersonales->Salud) 
	{
		printf("\n!!!!!!!!El personaje: %s a ganado!!!!!!!!\n", PJ1->DatosPersonales->ApellidoNombre);
		printf("\nEl personaje: %s ha sido eliminado del juego :(!!!\n", PJ2->DatosPersonales->ApellidoNombre);
		EliminacionPorPelea(&Personaje, dos);
	}
	if (PJ1->DatosPersonales->Salud < PJ2->DatosPersonales->Salud){
		printf("\n!!!!!!!!El personaje: %s a ganado!!!!!!!!\n", PJ2->DatosPersonales->ApellidoNombre);
		printf("\nEl personaje: %s ha sido eliminado del juego :(!!!\n", PJ1->DatosPersonales->ApellidoNombre);
		EliminacionPorPelea(&Personaje, uno);
	}

}

void Eleccion_Lista(TPersonaje *Inicio, TPersonaje **Personaje, int num)
{

	TPersonaje *temp = Inicio;//SE IGUALA AL INICIO DE LA LISTA
	int cont = 1; //CONTADOR HASTA QUE SE IGUALE AL NUMERO DEL PERSONAJE QUE SE SELECCIONO

	while (temp != NULL)
	{
		if (cont == num)
		{
			(*Personaje) = temp;
			temp = NULL;
		}else
		{
			cont++;
			temp = temp->siguiente;
		}
	}

}

void AgregarPersonaje(TPersonaje ** lista, int cant)
{
	TPersonaje *aux;
	TPersonaje *nuevo_pj;


	for (int i = 0; i < cant; ++i)
	{
		nuevo_pj = (TPersonaje *) malloc(sizeof(TPersonaje)); //RESERVO LA MEMORIA
		nuevo_pj->DatosPersonales = (TDatos *) malloc(sizeof(TDatos));
		nuevo_pj->Caracteristicas = (TCaracteristicas *)malloc(sizeof(TCaracteristicas));
		Cargar_DatPj(nuevo_pj->DatosPersonales);//ASIGNO LOS DATOS AL NUEVO PERSONAJE
		CargarCarac(nuevo_pj->Caracteristicas);//ASIGNO LAS CARACTERISTICAS AL NUEVO PERSONAJE
		nuevo_pj->siguiente =  NULL;


		if ((*lista) == NULL)
		{
			(*lista) = nuevo_pj;
		}else{
			aux = (*lista);
			while (aux->siguiente != NULL)
			{
				aux = aux->siguiente;
			}
			aux->siguiente = nuevo_pj;
		}
	}
	
}

void MostrarPersonajes(TPersonaje * lista)
{
	TPersonaje *temp = lista;
	int cont = 0;

	while (temp != NULL)
	{
		printf("\n<<<<<<PERSONAJE: %d>>>>>>\n", ++cont);
		Mostrar_DatPj(temp->DatosPersonales);//MUESTRO LOS DATOS
		MostrarCarac(temp->Caracteristicas);//MUESTRO LAS CARACTERISTICAS
		printf("\n==============================================\==============================================\n");
		temp = temp->siguiente;
	}
}

int SeleccionMenu()
{
	int num;
	printf("\n.::MENU::.\nSeleccione un numero del menu:\n\n================================================\n\n");
	printf("1: Mostrar todos los personajes\n2: Eliminar un personaje\n3: Buscar un personaje\n4: Jugar en Arena\n5: Agregar personajes\n6: Salir\n");
	scanf("%d", &num);
	return (num);
}

void Menu(struct TPersonaje *Personaje)
{
	int salir = 0, cant;
	do
	{
		int num = SeleccionMenu();
		switch(num)
		{
			case 1: MostrarPersonajes(Personaje);
			break;
			case 2: EliminarPersonaje(&Personaje);
			break;
			case 3: MostrarUnPersonaje(Personaje);
			break;
			case 4: Pelea(Personaje);
			break;
			case 5:
			printf("\nIngrese cuantos personajes quiere agregar: ");
			scanf("%d", &cant);
			AgregarPersonaje(&Personaje, cant);
			break;
			case 6: salir = 1;
			break;
			default: printf("\nPorfavor ingrese un numero valido :(!!!\n");
			break;
		}
	}while(salir != 1);
}

void EliminarPersonaje(TPersonaje **Personajes)
{
	TPersonaje *aux = &Personajes;
	TPersonaje *anterior;
	int num, cont = 1;
	printf("\nIngrese el numero del personaje que desea eliminar: ");
	scanf("%d", &num);

	if (num == 1)
	{
		(*Personajes) = (*Personajes)->siguiente;
		free(aux);
	}else
	{
		while (cont < num && aux)
		{	
			cont++;
			anterior = aux;
			aux = aux->siguiente;

		}

		if (aux != NULL)
		{
			anterior->siguiente = aux->siguiente;
			free(aux);
		}else
		{
			printf("\nNo existe el personaje\n");
		}
	}
}

void MostrarUnPersonaje(TPersonaje *Personajes)
{
	TPersonaje *aux = Personajes;
	int num, cont = 1;
	printf("\nIngrese el numero del personaje que desea ver: ");
	scanf("%d", &num);

	while (cont < num && aux)
	{
		cont++;
		aux = aux->siguiente;
	}

	if (aux != NULL)
	{
		printf("\n<<<<<<PERSONAJE: %d>>>>>>\n", cont);
		Mostrar_DatPj(aux->DatosPersonales);//MUESTRO LOS DATOS
		MostrarCarac(aux->Caracteristicas);//MUESTRO LAS CARACTERISTICAS
		printf("\n==============================================\==============================================\n");
	}else
	{
		printf("\nNo existe el personaje\n");
	}
}

void EliminacionPorPelea(TPersonaje **Inicio, int num)
{
	TPersonaje *aux = (*Inicio);
	TPersonaje *anterior;
	int cont = 1;

	if (num == 1)
	{
		(*Inicio) = (*Inicio)->siguiente;
		free(aux);
	}
	else
	{

		while (cont < num && aux)
		{	
			cont++;
			anterior = aux;
			aux = aux->siguiente;

		}

		if (aux != NULL)
		{
			anterior->siguiente = aux->siguiente;
			free(aux);
		}else
		{
			printf("\nha ocurrido un error!!!\n");
		}
	}
}