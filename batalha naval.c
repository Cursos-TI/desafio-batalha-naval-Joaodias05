#include <stdio.h>

int main() {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10];

    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // navio horizontal
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
    }

    // navio vertical
    int linhaVertical = 6;
    int colunaVertical = 7;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = 3;
    }

    printf("   ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", i); 
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%c  ", linha[i]); 
        for (int j = 0; j < 10; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 ");
            } else if (tabuleiro[i][j] == 3) {
                printf("3 "); 
            }
        }
        printf("\n");
    }
}














 







