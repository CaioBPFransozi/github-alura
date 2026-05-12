#include <stdio.h>
#include <stdlib.h>

int main() {
        int size = 0;
        int forma = 0;
        printf("Bem-vindo ao gerador de formatos!\n");
        printf("Informe a forma desejada\n");
        printf("1 - Tabuleiro\n2 - Diamante\n");
        scanf("%d", &forma);
        if (forma < 1 || forma > 2) {
                printf("Insira uma forma válida!");
                return -1;
        }
        // Ler entrada do usuário como tamanho do tabuleiro
        printf("Informe o tamanho do %s\n",
               forma == 1 ? "tabuleiro" : "diamante");
        scanf("%d", &size);
        if (size < 1 || size > 512) {
                printf("Insira um valor válido!");
                return -2;
        }
        // Retornar valor de erro se valor for muito alto ou muito baixo
        if (forma == 1) {
                // Imprimir valores do tabuleiro
                for (int i = 0; i < size; i++) {
                        for (int j = 0; j < size; j++) {
                                printf("%d ", (j + i % 2) % 2);
                        }
                        printf("\n");
                }
        } else {
		// Imprimir valores do diamante
                for (int i = 0; i < size; i++) {
                        int absolute = abs(size / 2 - i);
                        for (int j = 0; j < size; j++) {
                                printf("%d ",
                                       j >= absolute && j < size - absolute);
                        }
                        printf("\n");
                }
        }
        return 0;
}
