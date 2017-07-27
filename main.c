#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char Names[50][50];
char Desc[50][50];

char aspectos[255][255];
char problemas[255][255];

FILE *fate_c;

typedef struct Datasheet DataSheet;

struct Datasheet{
  char name[50];
  char description[255];
  unsigned short f_points;
  unsigned short f_refresh;

  struct Aspects{
    char a_principal[255];
    char problem[255];
    char a_first[255];
    char a_second[255];
    char a_third[255];
  }aspects;

  struct Stryles{
    short e_sagaz;
    short e_cauto;
    short e_rapido;
    short e_furtivo;
    short e_energico;
    short e_llamativo;
  }styles;

  struct Hab{
    char h_1[255];
    char h_2[255];
    char h_3[255];
  }hab;

  struct Stress{
    short s_1;
    short s_2;
    short s_3;

    char con_2[255];
    char con_4[255];
    char con_6[255];
  }stress;
};




short fateDice(unsigned short quantity);
void printDS(DataSheet sheet);

DataSheet initData(DataSheet Data);

int main(int argc, char ** argv){

  srand(time(NULL));

  strcpy(Names[0], "Jorge");
  strcpy(Names[1], "Martin");
  strcpy(Names[2], "Pablo");
  strcpy(Names[3], "Vicente");
  strcpy(Names[4], "Joaquin");
  strcpy(Names[5], "Frodo");
  strcpy(Names[6], "Harry");
  strcpy(Names[7], "Renato");
  strcpy(Names[8], "PimPim");
  strcpy(Names[9], "Bruce");
  strcpy(Names[10], "Jay");
  strcpy(Names[11], "Barry");
  strcpy(Names[12], "Homero");
  strcpy(Names[13], "Bart");
  strcpy(Names[14], "Allan");
  strcpy(Names[15], "Brian");
  strcpy(Names[16], "Brayan");
  strcpy(Names[17], "Brayatan");
  strcpy(Names[18], "Stefano");
  strcpy(Names[19], "Sergio");
  strcpy(Names[20], "Diego");
  strcpy(Names[21], "Daniel");
  strcpy(Names[22], "Adrian");
  strcpy(Names[23], "Sergiu");
  strcpy(Names[24], "Piertov");
  strcpy(Names[25], "Gandalf");
  strcpy(Names[26], "Saruman");
  strcpy(Names[27], "Michel");
  strcpy(Names[28], "Bruno");
  strcpy(Names[29], "Gustavo");
  strcpy(Names[30], "Jose");
  strcpy(Names[31], "Miguel");
  strcpy(Names[32], "Jose Miguel");
  strcpy(Names[33], "Jamie");
  strcpy(Names[34], "Jaime");
  strcpy(Names[35], "Cristian");
  strcpy(Names[36], "Carlos");
  strcpy(Names[37], "Raimundo");
  strcpy(Names[38], "Zehv");
  strcpy(Names[39], "Khan");
  strcpy(Names[40], "Aragon");
  strcpy(Names[41], "Anathorn");
  strcpy(Names[42], "Walter");
  strcpy(Names[43], "Waldo");
  strcpy(Names[44], "Wally");
  strcpy(Names[45], "Nik");
  strcpy(Names[46], "Sushai");
  strcpy(Names[47], "Adolfo");
  strcpy(Names[48], "Arnoldo");
  strcpy(Names[49], "Timmy");

  strcpy(problemas[0], "Se vuelve loco por las mujeres");
  strcpy(problemas[1], "Cuando ve algo brillante va a por el");
  strcpy(problemas[2], "No se le dan las manualidades");
  strcpy(problemas[3], "Mal con las mujeres");
  strcpy(problemas[4], "Cualquier opurtunidad de sexo la aprovecha");
  strcpy(problemas[5], "Como se el tendra todo el dinero");
  strcpy(problemas[6], "Un maniaco por las armas");
  strcpy(problemas[7], "No puedo vivir sin oxigeno");
  strcpy(problemas[8], "Coagulacion lenta");
  strcpy(problemas[9], "Mala precizion");
  strcpy(problemas[10], "Voy a ser el mejor... Cueste lo que cueste");
  strcpy(problemas[11], "No puede irse de las tiendas sin comprar");
  strcpy(problemas[12], "Siempre dira la verdad");
  strcpy(problemas[13], "No conoce la verdad");
  strcpy(problemas[14], "Mujeres ahh, mejor hombres");
  strcpy(problemas[15], "Se siente cansado todo el tiempo");
  strcpy(problemas[16], "No puede vivir sin tener cerca alcohol");
  strcpy(problemas[17], "Fue adicto a la marihuana");
  strcpy(problemas[18], "Adicto a la cocaina");
  strcpy(problemas[19], "Adicto al crack");
  strcpy(problemas[20], "Obsesionado por las armas");
  strcpy(problemas[21], "Las mujeres en la cocina (Machista)");
  strcpy(problemas[22], "Poco atractivo");
  strcpy(problemas[23], "La suerte no esta cerca");
  strcpy(problemas[24], "Trauma con la muerte");

  strcpy(aspectos[0], "Se le dan bien las mujeres");
  strcpy(aspectos[1], "Buena punteria");
  strcpy(aspectos[2], "Buen cocinero");
  strcpy(aspectos[3], "Siempre lleva algo de dinero con el");
  strcpy(aspectos[4], "Nunca sale sin un arma");
  strcpy(aspectos[5], "Tiene todo lo que necesita para hackear");
  strcpy(aspectos[6], "Nunca esta solo");
  strcpy(aspectos[7], "Se le da bien trabajar en equipo");
  strcpy(aspectos[8], "Nunca sabes donde esta");
  strcpy(aspectos[9], "Esconderse es un juego");
  strcpy(aspectos[10], "La muerte eso es pan comido");
  strcpy(aspectos[11], "Nunca sabran que les pego");
  strcpy(aspectos[12], "Si algo no esta bien, yo podre repararlo");
  strcpy(aspectos[13], "Nadie me dice que no");
  strcpy(aspectos[14], "Soy el mejor en lo que hago");
  strcpy(aspectos[15], "Cuando algo sale mal... retrocedo el tiempo");
  strcpy(aspectos[16], "Muchos conocen la muerte gracias a mi");
  strcpy(aspectos[17], "Sera la primera y ultima vez que veas mi cara");
  strcpy(aspectos[18], "Muchos le temen a la muerte, es porque no saben quien soy");
  strcpy(aspectos[19], "Disparar pff juego de ninos");
  strcpy(aspectos[20], "Maestro de las artes marciales");
  strcpy(aspectos[21], "Experto dibujante");
  strcpy(aspectos[22], "Nada mejor que yo, en todo");
  strcpy(aspectos[23], "Experto en IT");
  strcpy(aspectos[24], "Recupero cosas de la basura");

  DataSheet d;
  d = initData(d);

  printDS(d);

  return 0;
}

DataSheet initData(DataSheet Data){
  //Name
  strcpy(Data.name, Names[rand() % 50]);

  //Aspectos init
  strcpy(Data.aspects.a_principal, aspectos[rand() % 25]);
  strcpy(Data.aspects.problem, problemas[rand() % 25]);
  strcpy(Data.aspects.a_first, aspectos[rand() % 25]);
  strcpy(Data.aspects.a_second, aspectos[rand() % 25]);
  strcpy(Data.aspects.a_third, aspectos[rand() % 25]);

  //Styles init
  Data.styles.e_sagaz = fateDice(4);
  Data.styles.e_cauto = fateDice(4);
  Data.styles.e_rapido = fateDice(4);
  Data.styles.e_furtivo = fateDice(4);
  Data.styles.e_energico = fateDice(4);
  Data.styles.e_llamativo = fateDice(4);

  //Fate Points
  Data.f_points = 3;
  Data.f_refresh = 3;

  return Data;
}

short fateDice(unsigned short quantity){
  short ret = 0;

  for(int i = 0; i < quantity; i++){
    short tmp = rand() % 3;

    if(tmp == 0){
      ret = ret - 1;
    } else if(tmp == 1){
      ret = ret;
    } else if(tmp == 2){
      ret = ret + 1;
    }
  }

  return ret;
}

void printDS(DataSheet sheet){
  printf("Nombre:    %s \n", sheet.name);

  printf("\n");

  printf("Principal: %s \n", sheet.aspects.a_principal);
  printf("Problema:  %s \n", sheet.aspects.problem);
  printf("Primero:   %s \n", sheet.aspects.a_first);
  printf("Segundo:   %s \n", sheet.aspects.a_second);
  printf("Tercero:   %s \n", sheet.aspects.a_third);

  printf("\n");

  printf("Sagaz:     %d \n", sheet.styles.e_sagaz);
  printf("Cauto:     %d \n", sheet.styles.e_cauto);
  printf("Rapido:    %d \n", sheet.styles.e_rapido);
  printf("Furtivo:   %d \n", sheet.styles.e_furtivo);
  printf("Energico:  %d \n", sheet.styles.e_energico);
  printf("Llamativo: %d \n", sheet.styles.e_llamativo);

  printf("\n");

  printf("Fate:      %d \n", sheet.f_points);
  printf("Refresh:   %d \n", sheet.f_refresh);
  printf("\n");

  fate_c = fopen("character.fte", "w");

  fprintf(fate_c ,"Nombre:    %s \n", sheet.name);

  fprintf(fate_c ,"\n");

  fprintf(fate_c ,"Principal: %s \n", sheet.aspects.a_principal);
  fprintf(fate_c ,"Problema:  %s \n", sheet.aspects.problem);
  fprintf(fate_c ,"Primero:   %s \n", sheet.aspects.a_first);
  fprintf(fate_c ,"Segundo:   %s \n", sheet.aspects.a_second);
  fprintf(fate_c ,"Tercero:   %s \n", sheet.aspects.a_third);

  fprintf(fate_c ,"\n");

  fprintf(fate_c ,"Sagaz:     %d \n", sheet.styles.e_sagaz);
  fprintf(fate_c ,"Cauto:     %d \n", sheet.styles.e_cauto);
  fprintf(fate_c ,"Rapido:    %d \n", sheet.styles.e_rapido);
  fprintf(fate_c ,"Furtivo:   %d \n", sheet.styles.e_furtivo);
  fprintf(fate_c ,"Energico:  %d \n", sheet.styles.e_energico);
  fprintf(fate_c ,"Llamativo: %d \n", sheet.styles.e_llamativo);

  fprintf(fate_c ,"\n");

  fprintf(fate_c ,"Fate:      %d \n", sheet.f_points);
  fprintf(fate_c ,"Refresh:   %d \n", sheet.f_refresh);
  fprintf(fate_c ,"\n");

  fclose(fate_c);
}
