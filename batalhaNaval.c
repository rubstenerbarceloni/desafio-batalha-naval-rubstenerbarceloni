#include <stdio.h>
#include <stdlip.h>

#define TAMANHO_TABULEIRO  10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Declaração do tamanho tabuleiro (10x10)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa  as posições 
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas dos navios 
    int linhaHorizontal = 2; // linha para o navio horizontal
    int colunaHorizontal = 4; // coluna inicial
    int linhaVertical = 6; // linha inicial
    int colunaVertical = 7; // coluna para o navio vertical

    // Verificaçãodos limites do tabuleiro
    if (colunaHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        linhaVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        // Posiciona navio horizontal 
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = NAVIO;
        }

        // Posiciona navio vertical 
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaVertical + i][colunaVertical] = NAVIO;
            }
        } else {
            printf("Erro: Sobreposição de navios detectada!\n");
            return 1;
        }
    } else {
        printf("Erro: Coordenadas fora dos limites do tabuleiro.\n");
        return 1;
    }

    // exibição do tabuleiro
    printf("Tabuleiro Batalha Naval:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    system("pause")
    return 0;
}
