#include "travelPlannerClient.h"

void entryPoint(){
  mainMenu();
}

void mainMenu(){
  int choice = 0;
  while(choice != 9){
    printMainMenu();
    choice = handleMainMenuInput();
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
  puts("\n");
}

int handleMainMenuInput(){
  int choice = 0;
  scanf("%d", &choice);
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
    puts("Programmet avslutas");
    break;
  default:
    puts("Menupunkten finns inte, prova igen");
  }
  return choice;
}
