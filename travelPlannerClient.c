#include "travelPlannerClient.h"

void entryPoint(){
  //mainMenu();
  testFunction();
  
  Graph uppsalaNetwork = importNetwork();
  printf("%u\n", getDepartureTime(uppsalaNetwork, 1, 2));
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
  puts("8. K�r testFunction");
  puts("9. Avsluta");
  puts("-------------------------------------------");
  puts("Vad vill du g�ra?");
}

void printOutPutText(){
  puts("\n*******************************************");
  puts("***************** Output ******************");
  puts("*******************************************");
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

