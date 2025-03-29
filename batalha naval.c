#include <stdio.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3

int main() {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[TAMANHO][TAMANHO];

        for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // vertical 1
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
    }

    // vertical 2 
    int linhaVertical = 6;
    int colunaVertical = 7;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = 3;
    }

    // Diagonal 1
    int linhaDiagonal1 = 0;
    int colunaDiagonal1 = 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] = 3;
    }

    // Diagonal 2
    int linhaDiagonal2 = 7;
    int colunaDiagonal2 = 9;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] = 3;
    }

    
    printf("   ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i); 
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%c  ", linha[i]); 
                for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 "); 
            } else if (tabuleiro[i][j] == 3) {
                printf("3 "); 
            }
        }
        printf("\n");
    }

}
