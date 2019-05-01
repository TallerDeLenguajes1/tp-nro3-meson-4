//bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX 3

typedef enum {Orco=1, Humano, Mago, Enano, Elfo}TRaza;
char Nombres[6][30]={"Rocket", "Gato", "Chubaca", "Pikachu", "Perro", "Capitan"};
char Apellidos[6][30]={" Cansado", " Pro", " Loco", " Malo", " Traumado", " Bueno"};

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

struct nodo{
	TPersonaje *DatosPersonaje;
	struct nodo *siguiente;
};
typedef struct nodo *Lista;

int Menu();
void Cargar_DatPj(struct TDatos *);
void Mostrar_DatPj(struct TDatos *);
void CargarCarac(TCaracteristicas *puntCarac);
void MostrarCarac(TCaracteristicas *puntCarac);
void Pelea(TPersonaje *arrePjs, int primerPJ, int segPJ);
Lista IniciarLista();
int esListaVacia(Lista start);
Lista CargarLista(Lista start,TPersonaje * persona);
Lista CargarFinal(Lista start,TPersonaje * Personaje);
void mostrar(Lista L);
Lista borrarLista(Lista start);
Lista borrarNodo(Lista start, int num);
void buscarElemento(Lista start,int num);


int main(void)
{	
	srand(time(NULL));
	TPersonaje * arrePjs;
	Lista L;
	int i=0, num, segPJ;

	
	L = IniciarLista();

	/*while(i<3){
		arrePjs =  (TPersonaje *) malloc(sizeof(TPersonaje));
		arrePjs -> DatosPersonales = (TDatos *) malloc(sizeof(TDatos));
	    arrePjs ->Caracteristicas = (TCaracteristicas *)malloc(sizeof(TCaracteristicas));
		Cargar_DatPj(arrePjs -> DatosPersonales);
		CargarCarac(arrePjs -> Caracteristicas);
		L = CargarLista(L, arrePjs);
		i++;
	}*/
	
	do{
		num = Menu();
		switch(num){
			case 1:
				arrePjs =  (TPersonaje *) malloc(sizeof(TPersonaje));
				arrePjs -> DatosPersonales = (TDatos *) malloc(sizeof(TDatos));
	   	 		arrePjs ->Caracteristicas = (TCaracteristicas *)malloc(sizeof(TCaracteristicas));
				Cargar_DatPj(arrePjs -> DatosPersonales);
				CargarCarac(arrePjs -> Caracteristicas);
				L = CargarLista(L, arrePjs);
				break;
			case 2:
				arrePjs =  (TPersonaje *) malloc(sizeof(TPersonaje));
				arrePjs -> DatosPersonales = (TDatos *) malloc(sizeof(TDatos));
	    		arrePjs ->Caracteristicas = (TCaracteristicas *)malloc(sizeof(TCaracteristicas));
				Cargar_DatPj(arrePjs -> DatosPersonales);
				CargarCarac(arrePjs -> Caracteristicas);
				L = CargarFinal(L, arrePjs);
				break;
			case 3:
				printf("Ingrese la posicion del personaje que desea ver: ");
				scanf("%d", &i);
				buscarElemento(L, i);
				break;
			case 4:
				L = borrarLista(L);
				break;
			case 5:
				printf("Ingrese la posicion del personaje que desea borrar: ");
				scanf("%d", &i);
				L = borrarNodo(L, i);
				break;
			case 6: mostrar(L);
				break;
			case 7:
				break;
		}
	}while(num!=9);

	return 0;
}

int Menu(){

	int num;

	printf("\n\n<<<<<< Menu >>>>>>\n\n");
	printf(" 1 - Insertar un nuevo Personaje al comienzo de la lista \n");
	printf(" 2 - Insertar un nuevo Personaje al final de la lista. \n");
	printf(" 3 - Buscar un Personaje en una posicion particular \n");
	printf(" 4 - Eliminar un Personaje de la lista \n");
	printf(" 5 - Eliminar un Personaje de la lista en una posicion particular. \n");
	printf(" 6 - Mostrar todos los personajes.\n");
	printf(" 7 - Comenzar pelea entre 2 personajes.\n");
	printf(" 9 - Salir.\n");
	printf("Por favor elija un numero del menu: ");
	scanf("%d", &num);

	return(num);
}

//Funcion cargar Caracteristicas
void CargarCarac(TCaracteristicas *puntCarac){

	int numAle;

	numAle = 1 + rand()% 10;
	(*puntCarac).velocidad= numAle;

	numAle = 1 + rand()% 5;
	(*puntCarac).destreza= numAle;

	numAle = 1+ rand()% 10;
	(*puntCarac).fuerza = numAle;

	numAle = 1 +rand()% 10;
	(*puntCarac).Nivel = numAle;

	numAle = 1 + rand()% 10;
	(*puntCarac).Armadura = numAle;

}
//Funcion mostrar Caracteristicas
void MostrarCarac(TCaracteristicas *puntCarac){
	printf("|=====Caracteristicas del poder de tu personaje=====|\n\n");
	printf("La velocidad del personaje es: %d.\n", (*puntCarac).velocidad);
	printf("Su puntaje de destreza es: %d.\n", (*puntCarac).destreza);
	printf("Tiene una fuerza de: %d de poder.\n", (*puntCarac).fuerza);
	printf("El nivel de batalla del personaje es: %d.\n", (*puntCarac).Nivel);
	printf("El poder de la armadura: %d.\n", (*puntCarac).Armadura);
}
//Funcion Cargar datos del personaje
void Cargar_DatPj(struct TDatos *DatosPj){
	int numAle = 1 + rand() % (5-1);
	
	switch(numAle){
		case 0:
		DatosPj->Raza = Orco;
		break;
		case 1:
		DatosPj->Raza = Humano;
		break;
		case 2:
		DatosPj->Raza = Mago;
		break;
		case 3:
		DatosPj->Raza = Enano;
		break;
		case 4:
		DatosPj->Raza = Elfo;
		break;
	}
	numAle = 0 + rand() % (5-0);
	//contamos la cantidad de letras necesarias para el nombre
	int cant =  strlen(Nombres[numAle]);
	cant +=  strlen(Apellidos[numAle]);
	
	//reservamos la cantidad de letras del nombre
	DatosPj->ApellidoNombre = (char * )malloc(sizeof(char) * cant + 1 );

	strcpy(DatosPj->ApellidoNombre, Nombres[numAle]); //Copio la cadena de nombres aleatoriamente
	numAle = 0 + rand() % (5-0);
	strcat(DatosPj->ApellidoNombre, Apellidos[numAle]);//Junto la cadena anterior con un apellido aleatorio


	numAle = 0 + rand() % (300-0);
	DatosPj->edad = numAle;
	DatosPj->Salud = 100;
}

//Funcion Mostrar datos del personaje
void Mostrar_DatPj(struct TDatos *DatosPj){
	printf("|=====Datos del personaje=====|\n\nRaza: ");
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

void Pelea(TPersonaje *arrePjs, int primerPJ, int segPJ){

	int i=0;
	int PD, ED, VA, PDEF, MDP=50000, danioProv;

	printf("Bienvenidos a la zona de Pelea.\n");
	while(i<3){
		printf("|-------- Ronda %d -------|\n", i);
		//Efectividad de ataque Personaje 1
		PD = ((arrePjs[primerPJ-1].Caracteristicas->destreza)*(arrePjs[primerPJ-1].Caracteristicas->fuerza)*(arrePjs[primerPJ-1].Caracteristicas->Nivel));
		ED = 1 + rand()% 100;
		VA = PD * ED;
		PDEF = ((arrePjs[primerPJ-1].Caracteristicas->Armadura)*(arrePjs[primerPJ-1].Caracteristicas->velocidad));
		danioProv = (((VA*ED)-PDEF)/MDP)*100;
		arrePjs[primerPJ-1].DatosPersonales->Salud = (arrePjs[primerPJ-1].DatosPersonales->Salud) - danioProv;
		printf("El danio provocado al segundo personaje fue de: %d\n\n", danioProv);
		//---------------------------------
		//Efectividad de ataque Personaje 2
		PD = ((arrePjs[segPJ-1].Caracteristicas->destreza)*(arrePjs[segPJ-1].Caracteristicas->fuerza)*(arrePjs[segPJ-1].Caracteristicas->Nivel));
		ED = 1 + rand()% 100;
		VA = PD * ED;
		PDEF = ((arrePjs[segPJ-1].Caracteristicas->Armadura)*(arrePjs[segPJ-1].Caracteristicas->velocidad));
		danioProv = (((VA*ED)-PDEF)/MDP)*100;
		arrePjs[segPJ-1].DatosPersonales->Salud = (arrePjs[segPJ-1].DatosPersonales->Salud) - danioProv;
		printf("El danio provocado al primer personaje fue de: %d\n\n", danioProv);
		//---------------------------------
		i++;
	}
				
	printf("La salud del primer personaje es de: %.3f\n", arrePjs[primerPJ-1].DatosPersonales->Salud);
	printf("La salud del segundo personaje es de: %.3f\n", arrePjs[segPJ-1].DatosPersonales->Salud);
	if((arrePjs[primerPJ-1].DatosPersonales->Salud)>(arrePjs[segPJ-1].DatosPersonales->Salud)){
		printf("Primer personaje gana.\n");
	}else if((arrePjs[primerPJ-1].DatosPersonales->Salud)<(arrePjs[segPJ-1].DatosPersonales->Salud)){
		printf("Segundo personaje gana.\n");
	}else if((arrePjs[primerPJ-1].DatosPersonales->Salud)==(arrePjs[segPJ-1].DatosPersonales->Salud)){
		printf("Empate entre ambos.\n");
	}
}

Lista IniciarLista(){
	Lista A = NULL;
	return A;
}

int esListaVacia(Lista start){
	if(start==NULL){
		return 1;
	}else{
		return 0;
	}
}

Lista CargarLista(Lista start,TPersonaje * Personaje){
	Lista nuevo;
	nuevo = (Lista )malloc(sizeof(Lista));

	nuevo->DatosPersonaje = Personaje;
	nuevo->siguiente = start;
	start = nuevo;

	return start;
}

Lista CargarFinal(Lista start,TPersonaje * Personaje){
	Lista nuevo = (Lista )malloc(sizeof(Lista));
	
	if(!esListaVacia(start))
	{
		Lista aux = start;
		while(aux->siguiente!=NULL)
		{
			aux = aux->siguiente;
		}

		nuevo->DatosPersonaje = Personaje;
		nuevo->siguiente = NULL;
		aux->siguiente = nuevo;	
	}
	else
	{
		start = CargarLista(start, Personaje);
	}
	return start;
}

void mostrar(Lista L){
	struct nodo *varAux; //Lista varAux;
	varAux = L;
	while(varAux!=NULL){
		Mostrar_DatPj(varAux->DatosPersonaje->DatosPersonales);
		MostrarCarac(varAux->DatosPersonaje->Caracteristicas);
		varAux = varAux->siguiente;
	}
}

Lista borrarLista(Lista start){
	Lista aux=start;
	if(esListaVacia(start)){
		return start;
	}else{
   	   start=start->siguiente;
       free(aux);
       return start ;
	}
}

Lista borrarNodo(Lista start, int num){
	Lista aux = start;
	Lista anterior;
	int i=1;

	if(num==1){
		if(esListaVacia(start)){
			return start;
		}else{
   	   		start=start->siguiente;
       		free(aux);
       		return start;
		}
	}else{
		while(i<num && aux!=NULL){
			anterior = aux;
			aux = aux->siguiente;
			i++;
		}
		if(aux!=NULL){
			anterior->siguiente = aux->siguiente;
			free(aux);
		}
		return start;
	}
}
void buscarElemento(Lista start,int num){
	Lista aux=start;
	int valor=0, i=1;
	while(aux!=NULL && valor!=1){
	  if(i==num){//Si el elemento está en el nodo entonces igualo a 1
		printf("Entra en el primer if\n");
		valor=1;
      }else{
      	aux=aux->siguiente;
      }
      i++;
	}
	if(esListaVacia(aux)){
		printf("La lista esta vacia o no contiene ningun personaje en esta posicion.");
	}else{
		Mostrar_DatPj(aux->DatosPersonaje->DatosPersonales);
		MostrarCarac(aux->DatosPersonaje->Caracteristicas);
	}
}
