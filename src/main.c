#include <stdio.h>

int main() {
	int size = 0;
	printf("Bem-vindo ao gerador de tabuleiros de xadrez!\n");
	printf("Informe o tamanho do lado do tabuleiro\n");
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d ", (j + i % 2) % 2);
		}
		printf("\n");
	}
        return 0;
}
