#include <stdio.h>

int main() {
        int size = 0;
        printf("Bem-vindo ao gerador de tabuleiros de xadrez!\n");
        printf("Informe o tamanho do lado do tabuleiro\n");
	// Ler entrada do usuário como tamanho do tabuleiro
        scanf("%d", &size);
        // Retornar valor de erro se valor for muito alto ou muito baixo
        if (size < 1 || size > 512) {
                printf("Insira um valor válido!");
                return -1;
        }
	// Imprimir valores do tabuleiro
        for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                        printf("%d ", (j + i % 2) % 2);
                }
                printf("\n");
        }
        return 0;
}
