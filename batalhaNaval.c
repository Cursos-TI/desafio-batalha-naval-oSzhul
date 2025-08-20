#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato
    int tabuleiro[5][5] = {0};

    //Define o posicionamento do navio na horizontal
    int linha_h = 1; //Linha horizontal do navio posicionado
    int col_inicio_h = 0;
    int tamanho_h = 3;

    for (int i = 0; i < tamanho_h; i++) {
        tabuleiro[linha_h][col_inicio_h + i] = 1;
    }

    // Posição do navio na vertical
    int coluna_v = 3; // Linha vertical do navio posicionado
    int linha_inicio_v = 2;
    int tamanho_v = 2;

    for (int i = 0; i < tamanho_v; i++) {
        tabuleiro[linha_inicio_v + i][coluna_v] = 2;
    }

    // Coordenada do navio em horizontal
    printf("Coordenadas do navio na horizontal:\n");
    for (int i = 0; i < tamanho_h; i++) {
        printf("(%d, %d)\n", linha_h, col_inicio_h + i);
    }

    // Coordenada do navio na vertical
    printf("\nCoordenadas do navio na vertical:\n");
    for (int i = 0; i < tamanho_v; i++) {
        printf("(%d, %d)\n", linha_inicio_v + i, coluna_v);
    }
   
    return 0;
}

// Nivel Aventureiro

// Matrix 10x10
void exibirMatriz(int matriz[10][10], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

//Tabuleiro dos navios
void gerarTabuleiroAventureiro(int tabuleiro[10][10]) {
    
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            tabuleiro[i][j] = 0;

    // Posição horizontal
    for (int j = 2; j < 6; j++)
        tabuleiro[0][j] = 3;

    // Posição vertical
    for (int i = 2; i < 6; i++)
        tabuleiro[i][0] = 3;

    // Posição Diagonal
    for (int i = 0; i < 4; i++)
        tabuleiro[i][i] = 3;

    //Segunda posição diagonal
    for (int i = 0; i < 4; i++)
        tabuleiro[i][9 - i] = 3;
}

int main() {
    int tabuleiro[10][10];
    gerarTabuleiroAventureiro(tabuleiro);
    printf("Tabuleiro - Nível Aventureiro:\n");
    exibirMatriz(tabuleiro, 10);
    return 0;
}

//Nivel Mestre

//Matriz 5x5
void exibirMatriz(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Habilidade do Cone
void habilidadeCone(int matriz[5][5]) {
    int cone[5][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matriz[i][j] = cone[i][j];
}

// Habilidade da Cruz
void habilidadeCruz(int matriz[5][5]) {
    int cruz[5][5] = {
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matriz[i][j] = cruz[i][j];
}

// Habilidade do Octaedro
void habilidadeOctaedro(int matriz[5][5]) {
    int octaedro[5][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matriz[i][j] = octaedro[i][j];
}

int main() {
    int habilidade[5][5];

    printf("Habilidade: Cone\n");
    habilidadeCone(habilidade);
    exibirMatriz(habilidade);

    printf("\nHabilidade: Cruz\n");
    habilidadeCruz(habilidade);
    exibirMatriz(habilidade);

    printf("\nHabilidade: Octaedro\n");
    habilidadeOctaedro(habilidade);
    exibirMatriz(habilidade);

    return 0;
}
