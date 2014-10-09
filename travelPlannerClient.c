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
  puts("");
  puts("-------------------------------------------");
  puts("-------------- Reseplanerare --------------");
  puts("-------------------------------------------");
  puts("1. Skapa nytt bussnätverk");
  puts("2. Skapa ny busshållsplats");
  puts("3. Skapa ny avgång");
  puts("4. Visa tidtabell för en startstation");
  puts("5. Möjliga resavägar från X till Y");
  puts("8. Kör testFunction");
  puts("9. Avsluta");
  puts("-------------------------------------------");
  puts("Vad vill du göra?");
}

void printOutputText(){
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
    printOutputText();
    puts("Ännu inte implementerat");
    break;
  case 2:
    printOutputText();
    puts("Ännu inte implementerat");
    break;
  case 3:
    printOutputText();
    puts("Ännu inte implementerat");
    break;
  case 4:
    printDeparturesForStation();
    break;
  case 5:
    printPathXtoY();
    break;
  case 8:
    printOutputText();
    testFunction();
    break;
  case 9:
    break;
  default:
    printOutputText();
    puts("Menupunkten finns inte, prova igen");
  }
  puts("*******************************************");
  return choice;
}

void printDeparturesForStation(){
  char* station = malloc(64);
  puts("\nAnge en station att visa tidtabell för:");
  fflush(stdout);
  scanf("%s", station);
  printOutputText();
  printf("Linje\tTid\n");
  printDeparturesInClockFormat(getNodeByNameElseAddNode(uppsalaNetwork, station));
}

void printPathXtoY (){
  char* X = malloc(32);
  char* Y = malloc(32);
  puts("\nAnge önskad startstation:");
  fflush(stdout);
  scanf("%s", X);
  puts("\nAnge önskad slutstation:");
  fflush(stdout);
  scanf("%s", Y);
  printOutputText();
  printPossiblePaths(uppsalaNetwork, X, Y);
}
