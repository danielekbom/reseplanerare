#include "travelPlannerClient.h"

static Graph uppsalaNetwork;

void entryPoint(){
  uppsalaNetwork = importNetwork();

  mainMenu();
  testFunction();

  destroyGraph(uppsalaNetwork);
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
  puts("5. M�jliga resav�gar fr�n X till Y");
  puts("8. K�r testFunction");
  puts("9. Avsluta");
  puts("-------------------------------------------");
  puts("Vad vill du g�ra?");
}

void printOutPutText(){
  puts("\n*******************************************");
  puts("***************** Output ******************");
  puts("*******************************************");
  fflush(stdout);
}

int handleMainMenuInput(){
  int choice = 0;
  fflush(stdout);
  scanf("%d", &choice);
  switch(choice){
  case 1:
    printOutPutText();
    puts("�nnu inte implementerat");
    break;
  case 2:
    printOutPutText();
    puts("�nnu inte implementerat");
    break;
  case 3:
    printOutPutText();
    puts("�nnu inte implementerat");
    break;
  case 4:
    printOutPutText();
    puts("�nnu inte implementerat");
    break;
  case 5:
    printOutPutText();
    printPathXtoY();
  case 8:
    printOutPutText();
    testFunction();
    break;
  case 9:
    break;
  default:
    printOutPutText();
    puts("Menupunkten finns inte, prova igen");
  }
  puts("*******************************************");
  return choice;
}

void printPathXtoY (){
  char* X = malloc(32);
  char* Y = malloc(32);
  puts("\nSkriv �nskad startstation:");
  fflush(stdout);
  scanf("%s", X);
  puts("\nSkriv �nskad destination:");
  fflush(stdout);
  scanf("%s", Y);
  printPossiblePaths(uppsalaNetwork, X, Y);
}
