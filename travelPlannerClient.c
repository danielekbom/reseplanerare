#include "travelPlannerClient.h"

static Graph uppsalaNetwork;

void entryPoint(){
  uppsalaNetwork = importNetwork();

  mainMenu();
  //testFunction(uppsalaNetwork);
  destroyGraph(uppsalaNetwork);
}

void mainMenu(){
  int choice = 0;
  while(choice != 9){
    printMainMenu();
    choice = handleMainMenuInput();

    if(choice != 9){
      puts("\nKlicka pa retur for att komma till huvudmenyn");
    } else {
      puts("\nProgrammet avslutas, klicka pa retur");
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
  puts("1. Skapa nytt bussnatverk");
  puts("2. Skapa ny busshallsplats");
  puts("3. Skapa ny avgang");
  puts("4. Visa tidtabell for en startstation");
  puts("5. Mojliga resavagar fran X till Y");
  puts("8. Kor testFunction");
  puts("9. Avsluta");
  puts("-------------------------------------------");
  puts("Vad vill du gora?");
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
    puts("Annu inte implementerat");
    break;
  case 2:
    printOutputText();
    puts("Annu inte implementerat");
    break;
  case 3:
    printOutputText();
    puts("Annu inte implementerat");
    break;
  case 4:
    printDeparturesForStation();
    break;
  case 5:
    printPathXtoY();
    break;
  case 8:
    printOutputText();
    testFunction(uppsalaNetwork);
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
  puts("\nAnge en station att visa tidtabell for:");
  fflush(stdout);
  scanf("%s", station);
  printOutputText();
  printf("Linje\tTid\n");
  printDeparturesInClockFormat(getNodeByNameElseAddNode(uppsalaNetwork, station));
  free(station);
}

void printPathXtoY (){
  char* X = malloc(32);
  char* Y = malloc(32);
  puts("\nAnge onskad startstation:");
  fflush(stdout);
  scanf("%s", X);
  puts("\nAnge onskad slutstation:");
  fflush(stdout);
  scanf("%s", Y);
  printOutputText();
  printPossiblePaths(uppsalaNetwork, X, Y);
  free(X);
  free(Y);
}
