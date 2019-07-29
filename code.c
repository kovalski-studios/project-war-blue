#include <stdio.h>
#include <stdlib.h>

#define MAX_LEVELS  10
#define MAX_ENEMIES 5
#define MIN_ENEMIES 10
#define MAX_BLOWS   3
#define MAX_NUMBER_RANDOM 3

int main(int argc, char *argv[]) {
    srand(time(NULL));
    char Name[50];
    int Levels = 1;
    int NumberEnemies;
    int Blows = 0;
    int Life = 2;
    int Points = 50;

    int reiniciar;

    //printf("Entre com o seu nome caro jogador:");
    //scanf("%s", &Name);
    //printf("Caro Sr. %s, você está prestes a entrar em um mundo cheio de guerra e sangue. Você está preparado para batalha?\n\n");
    //printf("Siga em frente e entre na guerra.\n\n");
    do {

        for(; Levels < MAX_LEVELS + 1;){

            NumberEnemies = 0;
            printf("Level: %d\n", Levels);

            NumberEnemies = (rand() % MAX_ENEMIES) + 1;
            printf("Existem %d inimigo(s) no level %d\n", NumberEnemies, Levels);

            while (NumberEnemies != 0 && Life != 0 && Points != 0) {
                int RandonBlow = (rand() % MAX_NUMBER_RANDOM);
                int Blow;
                int Chance = MAX_BLOWS;

                printf("Inimigo %d\n", NumberEnemies);

                while (Chance != 0 ) {
                    printf("====> %d\n\n", RandonBlow);
                    printf("Voce possui %d vidas!\n", Life);
                    printf("Sua pontuacao no momento esta em %d pontos.\n", Points);
                    printf("Dê um golpe em seu inimigo. Escolhe entre 0 e 2:");
                    scanf("%d", &Blow);
                    if (Blow != RandonBlow) {
                        Chance--;
                        if (Chance == 0) {
                            Life--;
                            Points-=20;
                            printf("E voce tem agora %d vidas!!\n", Life);
                            printf("E voce tem agora %d pontos!!\n", Points);
                        }
                        Points-=10;
                        printf("Você não conseguiu derrotar o inimigo!\n");
                        printf("Restam %d inimigo(s) neste level %d e você ainda tem %d chances de acerta-lo!\n\n", NumberEnemies, Levels, Chance);
                        printf("E voce tem agora %d pontos!!\n", Points);
                        system("PAUSE");system("cls");
                    } else {
                        NumberEnemies--;
                        printf("Você derrotou seu inimigo!\n");
                        printf("Restam %d inimigo(s) neste level %d\n\n", NumberEnemies, Levels);
                        Chance = 0;
                        Life++;
                        Points+=15;
                        system("PAUSE");system("cls");
                    }
                }
            }

            if (NumberEnemies != 0 || Points <= 0) {
                printf("GAME OVER! Sua pontuacao final %d.\n\n", Points);
                system("PAUSE");system("cls");

                do {
                    printf("Digite 1 - (recomecar) ou 0 - (sair):");
                    scanf("%d",&reiniciar);

                    if (reiniciar < 0 || reiniciar > 1) {
                        printf("Opcao invalida!!");
                        reiniciar = 3;
                    }

                    if (reiniciar == 1) {
                        Life = 3;
                        Blows = 0;
                        Levels = 1;
                        Points = 50;
                    }
                } while(reiniciar == 3);
            } else {
                Levels+=1;
                if (Levels < MAX_LEVELS + 1) {
                    Points*=Levels;
                    printf("Parabéns! Você acaba de passar para o level %d.\n", Levels);
                    printf("Você possui %d pontos.\n\n", Points);
                    system("PAUSE");system("cls");
                } else {
                    Points*=10;
                }
            }
        }

        if (Levels > MAX_LEVELS && NumberEnemies == 0) {
            printf("Parabens!!! Voce venceu o warblue!!!\n\n");
            printf("Sua pontucao final: %d pontos.\n\n", Points);
            system("PAUSE");system("cls");
        }
    } while(reiniciar == 1);
    return 0;
}
