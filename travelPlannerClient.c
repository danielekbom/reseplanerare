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
      puts("\nKlicka på retur för att komma till huvudmenyn");
    } else {
      puts("\nProgrammet avslutas, klicka på retur");
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
  puts("1. Skapa nytt bussnätverk");
  puts("2. Skapa ny busshållsplats");
  puts("3. Skapa ny avgång");
  puts("4. Visa tidtabell för en hållplats");
  puts("8. Kör testFunction");
  puts("9. Avsluta");
  puts("-------------------------------------------");
  puts("Vad vill du göra?");
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
    puts("Ännu inte implementerat");
    break;
  case 2:
    puts("Ännu inte implementerat");
    break;
  case 3:
    puts("Ännu inte implementerat");
    break;
  case 4:
    puts("Ännu inte implementerat");
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
