#include <stdio.h>

// Quantidade de passos que as peças vão andar
const int PASSOS_TORRE  = 5;
const int PASSOS_BISPO  = 5;
const int PASSOS_RAINHA = 8;

// Movimento do cavalo: 2 pra cima e 1 pra a direita
const int CAVALO_UP     = 2;
const int CAVALO_RIGHT  = 1;

// Torre recursiva: mostra "Direita" quantas vezes foi definido
int torre_direita(int passos) {
    if (passos <= 0) return 0;     // quando não houverem mais casas, para
    printf("Direita\n");
    return torre_direita(passos - 1); // chama de novo até acabar
}

// Bispo recursivo: anda em diagonal, ou seja, pra cima e para a direita
int bispo_cima_direita(int passos) {
    if (passos <= 0) return 0;
    printf("Cima\n");
    printf("Direita\n");
    return bispo_cima_direita(passos - 1);
}

// Rainha recursiva: anda para a esquerda
int rainha_esquerda(int passos) {
    if (passos <= 0) return 0;
    printf("Esquerda\n");
    return rainha_esquerda(passos - 1);
}

// Bispo com loops aninhados: mesma ideia, só que usando for
int bispo_loops(int passos) {
    for (int v = 0; v < passos; v++) {
        for (int up = 0; up < 1; up++) printf("Cima\n");
        for (int right = 0; right < 1; right++) printf("Direita\n");
    }
    return 0;
}

// Cavalo com loops: 2 casas para cima e 1 para a direita
int cavalo_complexo(int upTarget, int rightTarget) {
    for (int u = 0; u <= upTarget; u++) {
        for (int r = 0; r <= rightTarget; r++) {
            if (u == 0 && r == 0) continue;   // pula o estado inicial
            if (u > upTarget || r > rightTarget) break; // não deixa passar do limite

            // quando chega no L, imprime os passos
            if (u == upTarget && r == rightTarget) {
                for (int i = 0; i < upTarget; i++) printf("Cima\n");
                for (int j = 0; j < rightTarget; j++) printf("Direita\n");
                break;
            }
        }
        if (u == upTarget) break; // encerra o loop externo
    }
    return 0;
}

int main() {
    printf("Movimento da Torre:\n");
    torre_direita(PASSOS_TORRE);

    printf("\nMovimento do Bispo (recursivo):\n");
    bispo_cima_direita(PASSOS_BISPO);

    printf("\nMovimento do Bispo (loops):\n");
    bispo_loops(PASSOS_BISPO);

    printf("\nMovimento da Rainha:\n");
    rainha_esquerda(PASSOS_RAINHA);

    printf("\nMovimento do Cavalo:\n");
    cavalo_complexo(CAVALO_UP, CAVALO_RIGHT);

    return 0;
}
