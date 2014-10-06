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
    puts("Ännu inte implementerat");
    break;
  case 2:
    printOutPutText();
    puts("Ännu inte implementerat");
    break;
  case 3:
    printOutPutText();
    puts("Ännu inte implementerat");
    break;
  case 4:
    printOutPutText();
    puts("Ännu inte implementerat");
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

