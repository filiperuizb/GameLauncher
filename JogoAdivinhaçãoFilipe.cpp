#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define MAX 100

void removeCursor();
void gotoxy(int x, int y);
void setColor(int color);
void efeitoDigitacao(const char texto[100]);
void menu();
int getNumAlt(int min, int max);
void startGameADV();
void gameADV(int num);
void startGameForca();
int selecionarDificuldade();
void gameForca();

int teclaEnter = 13;
int setaBaixo = 80;
int setaCima = 72;
int setaEsquerda = 75;
int setaDireita = 77;


int main() {
  setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	removeCursor();
	menu();
  return 0;
}

void removeCursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo); 
    cursorInfo.bVisible = FALSE; 
    SetConsoleCursorInfo(hConsole, &cursorInfo); 
}


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

    /*
	CORES:
	0	Preto
	1	Azul
	2	Verde
	3	Azul claro
	4	Vermelho
	5	Roxo
	6	Amarelo
	7	Branco claro
	8	Cinza
	9	Azul claro
	10	Verde claro
	11	Azul piscina
	12	Vermelho claro
	13	Rosa
	14	Amarelo claro
	15	Branco
	*/
}
void efeitoDigitacao(const char texto[100]) {
    int i = 0;
    while (texto[i] != '\0') {
        
		printf("%c", texto[i]);
        Sleep(30); 
        i++;
        
        
    }
}

void menu() {
	char nomeUsuario[256];
  DWORD tamanho = sizeof(nomeUsuario);
	system("cls");
  setColor(6);
  if(GetUserName(nomeUsuario, &tamanho)) {
  	gotoxy(44,5);
  	printf("Seja BEM-VINDO, %s!", nomeUsuario);
	} else {
		gotoxy(44,5);
		printf("Seja BEM-VINDO!");
	}
	gotoxy(30, 7);
	setColor(15);
	printf("Este é o MENU PRINCIPAL, onde você vai poder escolher");
	gotoxy(38,8);
	printf("o jogo que deseja jogar! DIVIRTA-SE!");

	setColor(5);
	gotoxy(46,10);
	printf("-> MENU PRINCIPAL <-");
	gotoxy(44,11);
  efeitoDigitacao("________________________");
  
  int opcaoSelecionada = 0;  

    while (true) {
    	setColor(15);
      gotoxy(30,14);
      printf("%s Adivinhação", opcaoSelecionada == 0 ? ">" : " ");
      gotoxy(50,14);
      printf("%s Jogo da FORCA", opcaoSelecionada == 1 ? ">" : " ");
      gotoxy(70,14);
      setColor(4);
      printf("%s Em breve", opcaoSelecionada == 2 ? ">" : " ");
			  
      gotoxy(30,16);
      printf("%s Em breve", opcaoSelecionada == 3 ? ">" : " ");
      gotoxy(50,16);
      printf("%s Em breve", opcaoSelecionada == 4 ? ">" : " ");
      gotoxy(70,16);
    	printf("%s Em breve", opcaoSelecionada == 5 ? ">" : " ");

     
      int tecla = getch();

  
      if (tecla == setaCima) {
        if (opcaoSelecionada >= 3) {
        	opcaoSelecionada -= 3;
        }
      } else if (tecla == setaBaixo) {
      		if (opcaoSelecionada < 3) {
          	opcaoSelecionada += 3;
          }
      } else if (tecla == setaEsquerda) {
          if (opcaoSelecionada % 3 != 0) {
          	opcaoSelecionada -= 1;
          }
      } else if (tecla == setaDireita) {
        	if (opcaoSelecionada % 3 != 2) {
            opcaoSelecionada += 1;
          }
      } else if (tecla == teclaEnter) {
          system("cls");
          switch(opcaoSelecionada) {
          	case 0:
              startGameADV();
              break;
            case 1:
              startGameForca();
              break;
            case 2:
              
              break;
            case 3:
              
              break;
            case 4:
          
              break;
            case 5:
                    
                    break;
            }
            break;  
        }
    }
}

int getNumAlt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void startGameADV() {
    int num = getNumAlt(1, 500);
    gotoxy(46,5);
    setColor(5);
    efeitoDigitacao("-> JOGO DA ADIVINHAÇÃO <-");
    gotoxy(45,6);
    efeitoDigitacao("___________________________");

    gotoxy(33,8);
    setColor(15);
    efeitoDigitacao("Olá! Sou o Oráculo e vou te guiar neste jogo incrível!");
    gotoxy(35,9);
    efeitoDigitacao("Irei gerar um número de 1 a 500 para você adivinhar.");
    gotoxy(50,11);
    setColor(6);
    efeitoDigitacao("Está preparado(a)?");

    int opcaoSelecionada = 0;  
    int tecla;
    
    while (true) {
        gotoxy(48,13);
        setColor(6);
				printf("%s Começar o Jogo!", opcaoSelecionada == 0 ? ">" : " ");
        gotoxy(48,14);
        printf("%s Voltar para o MENU", opcaoSelecionada == 1 ? ">" : " ");

   
        tecla = getch();
        
        
        if (tecla == 224) {  
            tecla = getch();  
            if (tecla == setaCima) {  
                opcaoSelecionada = (opcaoSelecionada == 0) ? 1 : 0;  
            } else if (tecla == setaBaixo) {  
                opcaoSelecionada = (opcaoSelecionada == 0) ? 1 : 0;  
            }
        } else if (tecla == teclaEnter) {  
            if (opcaoSelecionada == 0) {
                system("cls");
                gameADV(num); 
                break;
            } else if (opcaoSelecionada == 1) {
                system("cls");
                menu();  
                break;
            }
        }
    }
}

void gameADV(int num) {
    gotoxy(46,5);
    setColor(5);
    printf("-> JOGO DA ADIVINHAÇÃO <-");
    gotoxy(46,6);
    printf("__________________________");

    setColor(2);
    gotoxy(52,8);
    efeitoDigitacao("PROCESSANDO...");
    Sleep(1000);
    gotoxy(52,9);
    setColor(5);
    printf("NÚMERO GERADO!!!");
    setColor(15);
    
    int tentativas = 0;
    int numDigitado;

    while (true) {
        gotoxy(42,11);
        printf("%d° tentativa: ", tentativas + 1);
        gotoxy(42,12);
        printf("Fale um número entre 1 a 500: ");
        
        gotoxy(72,12);
        printf("     "); 
        gotoxy(72,12);

        int result = scanf("%d", &numDigitado);
        
        if (result != 1) {
            while (getchar() != '\n'); 
            gotoxy(42, 13);
            setColor(4);
            printf("Entrada inválida! Tente novamente.");
            continue;
        }

        if (numDigitado < 1 || numDigitado > 500) {
            gotoxy(42, 13);
            setColor(4);
            printf("Número inválido! Digite um valor entre 1 e 500.");
            setColor(15);
            continue;
        }

        tentativas++; 

        gotoxy(42, 13);
        printf("                                                         ");
				gotoxy(42,13);
				printf("                                                         ");
				gotoxy(42,13);
				printf("PROCESSANDO...");
				gotoxy(42,13);
				printf("                                                         ");
        if(numDigitado > num) {
            gotoxy(42,13);
            setColor(4);
            Sleep(1000);
            printf("ERROU! O número gerado é menor que %d", numDigitado);
            setColor(15); 
        } else if(numDigitado < num) {
            gotoxy(42,13);
            setColor(4);
            Sleep(1000);
            printf("ERROU! O número gerado é maior que %d", numDigitado);
            setColor(15); 
        } else {
            gotoxy(42, 14);
            setColor(2);
            Sleep(1000);
            printf("PARABÉNS! Você ACERTOU! Precisou de: %d tentativas.", tentativas);
            gotoxy(42, 15);
            setColor(15);
            printf("Aperte ENTER para voltar ao menu inicial! ");
            int tecla = getch();
            if(tecla == 13) {
                system("cls");
                startGameADV();
            }
            break;
        }

        if(tentativas >= 15) {
            gotoxy(42,14);
            setColor(4);
            printf("VOCÊ PERDEU!");
            gotoxy(42,15);
            printf("O limite máximo de tentativas é 15. Tente novamente!");
            Sleep(2000);
            system("cls");
            startGameADV();
            break;
        }
    }
}

void startGameForca() {
	gotoxy(52,5);
    setColor(5);
    efeitoDigitacao("-> JOGO DA FORCA <-");
    gotoxy(47,6);
    efeitoDigitacao("___________________________");

    gotoxy(33,8);
    setColor(15);
    efeitoDigitacao("Olá! Sou o Oráculo e vou te guiar neste jogo incrível!");
    gotoxy(35,9);
    efeitoDigitacao("Irei gerar uma palavra para você adivinhar por letra!");
    gotoxy(50,11);
    setColor(6);
    efeitoDigitacao("Está preparado(a)?");

    int opcaoSelecionada = 0;  
    int tecla;
    
    while (true) {
        gotoxy(48,13);
        setColor(6);
				printf("%s Começar o Jogo!", opcaoSelecionada == 0 ? ">" : " ");
        gotoxy(48,14);
        printf("%s Voltar para o MENU", opcaoSelecionada == 1 ? ">" : " ");

   
        tecla = getch();
        
        
        if (tecla == 224) {  
            tecla = getch();  
            if (tecla == setaCima) {  
                opcaoSelecionada = (opcaoSelecionada == 0) ? 1 : 0;  
            } else if (tecla == setaBaixo) {  
                opcaoSelecionada = (opcaoSelecionada == 0) ? 1 : 0;  
            }
        } else if (tecla == teclaEnter) {  
            if (opcaoSelecionada == 0) {
                system("cls");
                gameForca();
                break;
            } else if (opcaoSelecionada == 1) {
                system("cls");
                menu();  
                break;
            }
        }
    }

}

int selecionarDificuldade() {
    int opcaoSelecionada = 0;
    char *dificuldades[] = {"Facil", "Medio", "Dificil"};
    int totalDificuldades = 3;

    while (1) {
        system("cls");
        gotoxy(45, 5);
        setColor(5);
        printf("-> SELECIONE A DIFICULDADE <-");

        for (int i = 0; i < totalDificuldades; i++) {
            gotoxy(40 + i * 15, 8);
            setColor(opcaoSelecionada == i ? 6 : 7);  
            printf("%s", dificuldades[i]);
        }

        int tecla = getch();
        if (tecla == setaEsquerda) {
            opcaoSelecionada = (opcaoSelecionada - 1 + totalDificuldades) % totalDificuldades;
        } else if (tecla == setaDireita) {
            opcaoSelecionada = (opcaoSelecionada + 1) % totalDificuldades;
        } else if (tecla == teclaEnter) {
            return opcaoSelecionada;
        }
    }
}

void gameForca() {
    char palavrasFacil[10][50] = {
        "casa", "sol", "flor", "rio", "fogo", "lua", "paz", "amor", "copo", "gato"
    };

    char palavrasMedio[10][50] = {
        "programacao", "computador", "tecnologia", "sistema", "internet",
        "aplicativo", "plataforma", "processador", "engenheiro", "software"
    };

    char palavrasDificil[10][50] = {
        "criptografia", "infraestrutura", "microssegundos", "desenvolvimento",
        "inteligencia", "funcionalidade", "interface", "processamento",
        "computacional", "multithreading"
    };

    system("cls");
    gotoxy(30, 8);
    setColor(7);
    printf("Escolha a dificuldade:");
    printf("\n 0 - Fácil\n 1 - Médio\n 2 - Difícil\n");
    int dificuldade = selecionarDificuldade();

    char (*palavras)[50];
    int tentativas;
    char *dificuldades[] = {"Facil", "Medio", "Dificil"};

    switch (dificuldade) {
        case 0:
            palavras = palavrasFacil;
            tentativas = 7;
            break;
        case 1:
            palavras = palavrasMedio;
            tentativas = 5;
            break;
        case 2:
            palavras = palavrasDificil;
            tentativas = 3;
            break;
    }

    srand(time(NULL));
    int indice = rand() % 10;
    char *palavraSorteada = palavras[indice];

    int tamanhoPalavra = strlen(palavraSorteada);
    char palavraDisplay[50];
    int acertos = 0;
    int erros = 0;

    for (int i = 0; i < tamanhoPalavra; i++) {
        palavraDisplay[i] = '_';
    }
    palavraDisplay[tamanhoPalavra] = '\0';

    while (erros < tentativas && acertos < tamanhoPalavra) {
        system("cls");
        setColor(5);
        gotoxy(45, 5);
        printf("-> JOGO DA FORCA <-");

        gotoxy(40, 6);
        printf("___________________________");

        gotoxy(40, 8);
        setColor(7);
        printf("Dificuldade: %s", dificuldades[dificuldade]);

        gotoxy(40, 9);
        printf("Palavra: %s", palavraDisplay);
        gotoxy(40, 11);
        printf("Tentativas restantes: %d", tentativas - erros);

        gotoxy(40, 13);
        printf("Digite uma letra: ");
        char letra = getch();
        int acertouLetra = 0;

        for (int i = 0; i < tamanhoPalavra; i++) {
            if (palavraSorteada[i] == letra && palavraDisplay[i] == '_') {
                palavraDisplay[i] = letra;
                acertos++;
                acertouLetra = 1;
            }
        }

        if (!acertouLetra) {
            erros++;
        }
    }

    system("cls");
    gotoxy(45, 5);
    if (acertos == tamanhoPalavra) {
        setColor(2);  
        printf("Parabéns! Você venceu!");
    } else {
        setColor(4);  
        printf("Você perdeu! A palavra era: %s", palavraSorteada);
    }

    gotoxy(40, 8);
    setColor(7);
    printf("Aperte ENTER para voltar ao menu...");
    while (getch() != teclaEnter);
    menu();
}

