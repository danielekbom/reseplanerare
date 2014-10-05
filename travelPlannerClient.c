#include "travelPlannerClient.h"

void entryPoint(){
  mainMenu();
}

void mainMenu(){
  int choice = 0;
  while(choice != 9){
    printMainMenu();
    choice = handleMainMenuInput();

    if(choice != 9){
      puts("\nKlicka p� retur f�r att komma till huvudmenyn");
    } else {
      puts("\nProgrammet avslutas, klicka p� retur");
    }

    fflush(stdout);
    fflush(stdin);
    getchar();
  }
}

void printMainMenu(){
  puts("\n\n");
  puts("-------------------------------------------");
  puts("-------------- Reseplanerare --------------");
  puts("-------------------------------------------");
  puts("1. Skapa nytt bussn�tverk");
  puts("2. Skapa ny bussh�llsplats");
  puts("3. Skapa ny avg�ng");
  puts("4. Visa tidtabell f�r en h�llplats");
  puts("8. K�r testFunction");
  puts("9. Avsluta");
  puts("-------------------------------------------");
  puts("Vad vill du g�ra?");
}

int handleMainMenuInput(){
  int choice = 0;
  fflush(stdout);
  scanf("%d", &choice);
  puts("\n*******************************************");
  puts("***************** Output ******************");
  puts("*******************************************");
  switch(choice){
  case 1:
    puts("�nnu inte implementerat");
    break;
  case 2:
    puts("�nnu inte implementerat");
    break;
  case 3:
    puts("�nnu inte implementerat");
    break;
  case 4:
    puts("�nnu inte implementerat");
    break;
  case 8:
    testFunction();
    break;
  case 9:
    break;
  default:
    puts("Menupunkten finns inte, prova igen");
  }
  puts("*******************************************");
  return choice;
}
