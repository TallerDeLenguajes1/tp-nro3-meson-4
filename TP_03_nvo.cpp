//bibliotecas


# include  <stdio.h>
# include  <stdlib.h>
#include<time.h>
#include <string.h>

enum TRaza{Orco=1, Humano=2, Mago=3, Enano=4, Elfo=5};
char Nombres[6][10]={"Rocket","Gato","Chubaca","Pikachu","Perro","Capitan"};
char Apellidos[6][10]={"Cansado","Pro","Loco","Malo","Traumado","Bueno"};

struct TCaracteristicas{
int velocidad;// 1 a 10
int destreza; //1 a 5
int fuerza;//1 a 10
int nivel; //1 a 10
int armadura; //1 a 10
};

struct TDatos {
enum TRaza Raza; //nota 1
char *ApellidoNombre; //nota 2
int edad; //entre 0 a 300
double Salud;//100
};

struct TPersonaje {
struct TDatos * DatosPersonales;
struct TCaracteristicas *Caracteristicas;
};


void cargarcaract( struct TCaracteristicas *cargar);
void mostrarcaract(struct TCaracteristicas *mostrar);
void cargardatos(struct TDatos *cargard );
void mostrardatos(struct TDatos *mostrard);
void pelea();
int  main (void) {
	setvbuf(stdout,NULL,_IONBF,0);
	srand(time(NULL));
	//struct TCaracteristicas carc,*car;
	//struct TCaracteristicas *car;
	//struct TDatos *datos ;
	int n,i,j;
	printf("\nIngrese la cantidad de personajes");
	scanf("%d",&n);
	struct TPersonaje *personajes;
	personajes=(struct TPersonaje*)malloc(sizeof(struct TPersonaje)*n);
//car=&carc;
//int aleatorio=0+rand()%5-0;
//aleatorio=personajes.Caracteristicas;
//car=(struct TCaracteristicas*)malloc(sizeof(struct TCaracteristicas));
for(i=0;i<n;i++){
	fflush(stdin);
	personajes[i].DatosPersonales=(struct TDatos *)malloc(sizeof(struct TDatos ));
	personajes[i].Caracteristicas=(struct TCaracteristicas *)malloc(sizeof(struct TCaracteristicas));
	cargardatos(personajes[i].DatosPersonales);
	cargarcaract(personajes[i].Caracteristicas);

}

//datos=(struct TDatos*)malloc(sizeof(struct TDatos));
for(j=0;j<n;j++){

	mostrardatos(personajes[j].DatosPersonales);
	 mostrarcaract(personajes[j].Caracteristicas);

}
return 0;
}

void cargarcaract(struct TCaracteristicas *cargar){
srand(time(NULL));
printf("\nIngrese las Caracteristicas de un personaje");
cargar->velocidad=1+rand()%11-1;
cargar->destreza=1+rand()%6-1;
cargar->fuerza=1+rand()%11-1;
cargar->nivel=1+rand()%11-1;
cargar->armadura=1+rand()%11-1;
}

void mostrarcaract(struct TCaracteristicas *mostrar){
printf("\nla velocidad es%d",mostrar->velocidad);
printf("\n la destreza es%d",mostrar->destreza);
printf("\n su fuerza es%d",mostrar->nivel);
printf("\n su nivel es%d",mostrar->armadura);

}
void cargardatos(struct TDatos *cargard ){
	srand(time(NULL));
	int aleatorio;
	aleatorio=1+rand()%5-1;
	cargard->Raza=aleatorio;
	aleatorio=0+rand()%5-0;
	strcpy(cargard->ApellidoNombre,Nombres[aleatorio]);//copia la cadena de nombres aletoriamente
	aleatorio=0+rand()%5-0;
	strcat(cargard->ApellidoNombre,Apellidos[aleatorio]);//junta la cadena anterior con un apellido
	cargard->edad=rand()%301;
	cargard->Salud=100;
}
void mostrardatos(struct TDatos *mostrard){
	switch(mostrard->Raza){
	case 1:printf("\nOrco");
	break;
	case 2:printf("\nHumano");
	break;
	case 3:printf("\nMago");
	break;
	case 4:printf("\nEnano");
	break;
	case 5:printf("\nElfo");
	break;
	default:printf("\n error");
	}
	printf("\nel NombyApellido%s",mostrard->ApellidoNombre);
	printf("\nLa edad del personaje es %d",mostrard->edad);
	printf("\nLa salud del personaje es%lf",mostrard->Salud);
}
void pelea(struct TPersonaje *pelear ,int p1,int p2){
int pd,ed,va,pdef,mdp,dp,k;
srand(time(NULL));
k=0;
while(k<3){
	//printf("\nEl primer personaje pelea");

	pd=((pelear[p1].Caracteristicas->destreza)*(pelear[p1].Caracteristicas->fuerza)*(pelear[p1].Caracteristicas->nivel));

	ed=1+rand()%101-1;
	va=pd*ed;
	pdef=(pelear[p1].Caracteristicas->armadura)*(pelear[p1].Caracteristicas->velocidad);
	mdp=50000;
	dp=(((va*ed)-pdef)/mdp)*100;
	pelear[p1].DatosPersonales->Salud=(pelear[p1].DatosPersonales->Salud)-dp;
	printf("\nEl primer personaje pelea");
	printf("\nEl daño provocado por el segundo personaje es%d",dp);
	pd=(pelear[p2].Caracteristicas->destreza)*(pelear[p2].Caracteristicas->fuerza)*(pelear[p2].Caracteristicas->nivel);
		ed=1+rand()%101-1;
		va=pd*ed;
		pdef=(pelear[p2].Caracteristicas->armadura)*(pelear[p2].Caracteristicas->velocidad);
		mdp=50000;
		dp=(((va*ed)-pdef)/mdp)*100;
		pelear[p1].DatosPersonales->Salud=(pelear[p2].DatosPersonales->Salud)-dp;
		printf("\nEl segundo personaje pelea");
		printf("\nEl daño provocado por el primer personaje es%d",dp);

	k++;
}
printf("\nla salud del primer personaje es%lf",pelear->DatosPersonales->Salud);
printf("\nla salud del segundo personaje es%lf",pelear->DatosPersonales->Salud);
if((pelear[p1].DatosPersonales->Salud)>(pelear[p2].DatosPersonales->Salud)){
	printf("\nEl primer personaje gana");
}else if((pelear[p1].DatosPersonales->Salud)<(pelear[p2].DatosPersonales->Salud)){
	printf("\nEl segundo personaje gana");
}else if(pelear[p1].DatosPersonales->Salud==pelear[p2].DatosPersonales->Salud){
	printf("\nEmpate");

}

}
