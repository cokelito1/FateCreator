#include <stdio.h>

struct DataSheet{
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

int main(){

  return 0;
}
