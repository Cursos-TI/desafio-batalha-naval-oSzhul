#include <stdio.h>
#include <string.h>


// Função genérica para exibir uma matriz de qualquer tamanho
void exibirMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// --- Funções do Nível Aventureiro ---

// Prepara o tabuleiro para o Nível Aventureiro
void gerarTabuleiroAventureiro(int tabuleiro[10][10]) {
    // Inicializa todo o tabuleiro com 0
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posição horizontal (navio de tamanho 4, representado por '3')
    for (int j = 2; j < 6; j++) {
        tabuleiro[0][j] = 3;
    }

    // Posição vertical (navio de tamanho 4, representado por '3')
    for (int i = 2; i < 6; i++) {
        tabuleiro[i][0] = 3;
    }

    // Posição Diagonal principal (navio de tamanho 4, representado por '3')
    for (int i = 0; i < 4; i++) {
        tabuleiro[i][i] = 3;
    }

    // Segunda posição diagonal (navio de tamanho 4, representado por '3')
    for (int i = 0; i < 4; i++) {
        tabuleiro[i][9 - i] = 3;
    }
}


// --- Funções do Nível Mestre ---

// Habilidade do Cone
void habilidadeCone(int matriz[5][5]) {
    int cone[5][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = cone[i][j];
        }
    }
}

// Habilidade da Cruz
void habilidadeCruz(int matriz[5][5]) {
    int cruz[5][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,1,1,1,0},
        {0,0,1,0,0}
    };
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = cruz[i][j];
        }
    }
}

// Habilidade do Octaedro (Losango)
void habilidadeOctaedro(int matriz[5][5]) {
    int octaedro[5][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,1,1,1,0},
        {0,0,1,0,0}
    };
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = octaedro[i][j];
        }
    }
}


// --- Função Principal ---

int main() {
    // --- Nível Novato ---
    printf("--- Nível Novato ---\n");
    int tabuleiro_novato[5][5] = {0};

    // Define o posicionamento do navio na horizontal (representado por '1')
    int linha_h = 1;
    int col_inicio_h = 0;
    int tamanho_h = 3;
    for (int i = 0; i < tamanho_h; i++) {
        tabuleiro_novato[linha_h][col_inicio_h + i] = 1;
    }

    // Posição do navio na vertical (representado por '2')
    int coluna_v = 3;
    int linha_inicio_v = 2;
    int tamanho_v = 2;
    for (int i = 0; i < tamanho_v; i++) {
        tabuleiro_novato[linha_inicio_v + i][coluna_v] = 2;
    }

    printf("Tabuleiro - Nível Novato:\n");
    exibirMatriz(5, 5, tabuleiro_novato);
    printf("\n");

    // --- Nivel Aventureiro ---
    printf("--- Nível Aventureiro ---\n");
    int tabuleiro_aventureiro[10][10];
    gerarTabuleiroAventureiro(tabuleiro_aventureiro);
    printf("Tabuleiro - Nível Aventureiro:\n");
    exibirMatriz(10, 10, tabuleiro_aventureiro);
    printf("\n");

    // --- Nivel Mestre ---
    printf("--- Nível Mestre ---\n");
    int habilidade[5][5];

    printf("Habilidade: Cone\n");
    habilidadeCone(habilidade);
    exibirMatriz(5, 5, habilidade);

    printf("\nHabilidade: Cruz\n");
    habilidadeCruz(habilidade);
    exibirMatriz(5, 5, habilidade);

    printf("\nHabilidade: Octaedro\n");
    habilidadeOctaedro(habilidade);
    exibirMatriz(5, 5, habilidade);
    printf("\n");

    //Nivel Desafio
    printf("--- Nível Desafio ---\n");
    int tabuleiro_desafio[10][10];

    // 1. Começa com o tabuleiro do nível Aventureiro
    gerarTabuleiroAventureiro(tabuleiro_desafio);

    // 2. Adiciona os navios do nível Novato
    // Navio horizontal (valor '1')
    for (int i = 0; i < tamanho_h; i++) {
        tabuleiro_desafio[linha_h][col_inicio_h + i] = 1;
    }
    // Navio vertical (valor '2')
    for (int i = 0; i < tamanho_v; i++) {
        tabuleiro_desafio[linha_inicio_v + i][coluna_v] = 2;
    }

    printf("Tabuleiro base do Desafio (Juntando nivel novato com Aventureiro):\n");
    exibirMatriz(10, 10, tabuleiro_desafio);

    // 3. Aplica as 3 habilidades do nível Mestre
    int origem_hab_linha = 3;
    int origem_hab_coluna = 3;

    // Habilidade Cone
    printf("\nAplicando Habilidade: Cone (Representado com '6')\n");
    int tab_desafio_cone[10][10];
    memcpy(tab_desafio_cone, tabuleiro_desafio, sizeof(tabuleiro_desafio));
    int hab_cone[5][5];
    habilidadeCone(hab_cone);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (hab_cone[i][j] == 1) {
                tab_desafio_cone[origem_hab_linha + i][origem_hab_coluna + j] = 6;
            }
        }
    }
    exibirMatriz(10, 10, tab_desafio_cone);

    // Habilidade Cruz
    printf("\nAplicando Habilidade: Cruz (Representado com '7')\n");
    int tab_desafio_cruz[10][10];
    memcpy(tab_desafio_cruz, tabuleiro_desafio, sizeof(tabuleiro_desafio));
    int hab_cruz[5][5];
    habilidadeCruz(hab_cruz);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (hab_cruz[i][j] == 1) {
                tab_desafio_cruz[origem_hab_linha + i][origem_hab_coluna + j] = 7;
            }
        }
    }
    exibirMatriz(10, 10, tab_desafio_cruz);

    // Habilidade Octaedro
    printf("\nAplicando Habilidade: Octaedro (Representado com '8')\n");
    int tab_desafio_octaedro[10][10];
    memcpy(tab_desafio_octaedro, tabuleiro_desafio, sizeof(tabuleiro_desafio));
    int hab_octaedro[5][5];
    habilidadeOctaedro(hab_octaedro);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (hab_octaedro[i][j] == 1) {
                tab_desafio_octaedro[origem_hab_linha + i][origem_hab_coluna + j] = 8;
            }
        }
    }
    exibirMatriz(10, 10, tab_desafio_octaedro);

    return 0;
}
