#include <stdio.h>

#define TAMANHO 10 // Tamanho do tabuleiro
#define TAMANHO_NAVIO 3 // Tamanho fixo dos navios
#define TAMANHO_HABILIDADE 5 // Tamanho das matrizes de habilidade

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0; // Inicializa com água
        }
    }
}

void posicionarNavios(int tabuleiro[TAMANHO][TAMANHO]) {
    // Posiciona um navio horizontal
    int linhaHorizontal = 2, colunaHorizontal = 4;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
    }

    // Posiciona um navio vertical
    int linhaVertical = 6, colunaVertical = 7;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = 3;
    }
}

void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int origemLinha, int origemColuna) {
    int offset = TAMANHO_HABILIDADE / 2; // Calcula o deslocamento para centralizar a habilidade

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTabuleiro = origemLinha + i - offset;
            int colunaTabuleiro = origemColuna + j - offset;

            // Verifica se a posição está dentro dos limites do tabuleiro
            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO && colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO) {
                if (habilidade[i][j] == 1 && tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5; // Marca a área afetada pela habilidade
                }
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("   ");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i); // Exibe os números das colunas
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%c  ", 'A' + i); // Exibe as letras das linhas
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 "); // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("3 "); // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("5 "); // Área afetada pela habilidade
            }
        }
        printf("\n");
    }
}

void criarHabilidadeCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= TAMANHO_HABILIDADE / 2 - i && j <= TAMANHO_HABILIDADE / 2 + i) {
                habilidade[i][j] = 1; // Marca a área do cone
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

void criarHabilidadeCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2) {
                habilidade[i][j] = 1; // Marca a área da cruz
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

void criarHabilidadeOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if ((i - TAMANHO_HABILIDADE / 2) + (j - TAMANHO_HABILIDADE / 2) <= TAMANHO_HABILIDADE / 2) {
                habilidade[i][j] = 1; // Marca a área do octaedro
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    // Criar e aplicar habilidade em cone
    criarHabilidadeCone(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 4, 4);

    // Criar e aplicar habilidade em cruz
    criarHabilidadeCruz(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 6, 6);

    // Criar e aplicar habilidade em octaedro
    criarHabilidadeOctaedro(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 8, 2);

    // Exibir o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
