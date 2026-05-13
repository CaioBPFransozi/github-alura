#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline() {
	char *result = NULL;
	size_t size = 0;

	if (getline(&result, &size, stdin) == -1) {
		printf("Impossível ler string");
		exit(-4);
	};

	return result;
}

int main() {
        int size = 0;
        char *forma;

        printf("Gerador de formatos\n");
        printf("Informe o formato desejado\n");
        printf("Opções: tabuleiro ou diamante\n");

	forma = readline();
        // Padronizar string para letras minúsculas
        for (size_t i = 0; i < strlen(forma); i++) {
                forma[i] = tolower(forma[i]);
        }

        // Verificar se string corresponde a tabuleiro ou diamante
        int is_tabuleiro = strcmp(forma, "tabuleiro\n") == 0;
        int is_diamante = strcmp(forma, "diamante\n") == 0;

	// Retornar valor de erro caso não corresponda
        if (!is_tabuleiro && !is_diamante) {
                printf("Insira uma forma válida!");
                return -1;
        }

        // Ler entrada do usuário como tamanho do formato
        printf("Informe o tamanho do %s", forma);
        if (scanf("%d", &size) != 1) {
		printf("Impossível ler tamanho!");
		return -5;
	};
        // Retornar valor de erro se valor for muito alto ou muito baixo
        if (size < 1 || size > 512) {
                printf("Insira um valor válido!");
                return -2;
        }

        if (is_tabuleiro) {
                // Imprimir valores do tabuleiro
                for (int i = 0; i < size; i++) {
                        for (int j = 0; j < size; j++) {
                                printf("%d ", (j + i % 2) % 2);
                        }
                        printf("\n");
                }
        } else {
		if (size % 2 == 0) {
			printf("Tamanho deve ser ímpar para diamante!");
			return -3;
		}
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
	free(forma);

        return 0;
}
