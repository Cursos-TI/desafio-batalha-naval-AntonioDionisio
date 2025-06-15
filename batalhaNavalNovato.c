#include <stdio.h>

// Tamanho do tabuleiro
#define TAMANHO 10
// Tamanho dos navios
#define TAMANHO_NAVIO 3
// Valor para representar água
#define AGUA 0
// Valor para representar um navio
#define NAVIO 3

int main() {
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO][TAMANHO] = {0};
    
    // Coordenadas iniciais dos navios
    // Navio horizontal: linha 2, coluna 3
    int linha_horizontal = 2;
    int coluna_horizontal = 3;
    
    // Navio vertical: linha 5, coluna 7
    int linha_vertical = 5;
    int coluna_vertical = 7;
    
    // Validação das posições dos navios
    // Verifica se o navio horizontal cabe no tabuleiro
    if (coluna_horizontal + TAMANHO_NAVIO > TAMANHO) {
        printf("Erro: Navio horizontal não cabe no tabuleiro a partir da coluna %d\n", coluna_horizontal);
        return 1;
    }
    
    // Verifica se o navio vertical cabe no tabuleiro
    if (linha_vertical + TAMANHO_NAVIO > TAMANHO) {
        printf("Erro: Navio vertical não cabe no tabuleiro a partir da linha %d\n", linha_vertical);
        return 1;
    }
    
    // Verifica sobreposição
    // Para navios de tamanho 3 nas posições definidas, não há sobreposição
    
    // Posiciona o navio horizontal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = NAVIO;
    }
    
    // Posiciona o navio vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = NAVIO;
    }
    
    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    printf("0 = água, 3 = navio\n\n");
    
    // Imprime números das colunas
    printf("   ");
    for (int col = 0; col < TAMANHO; col++) {
        printf("%d ", col);
    }
    printf("\n");
    
    // Imprime linhas do tabuleiro
    for (int linha = 0; linha < TAMANHO; linha++) {
        // Número da linha
        printf("%d  ", linha);
        
        // Conteúdo da linha
        for (int col = 0; col < TAMANHO; col++) {
            printf("%d ", tabuleiro[linha][col]);
        }
        printf("\n");
    }
    
    return 0;
}