#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void menu() {
    puts("Menu de Opções :\n");
    puts("1 - Ocupar armário.\n");
    puts("2 - Liberar armário.\n");
    puts("3 - Sair.\n");
}

int main() {
    srand(time(NULL));
    int opcao;
    int armarioAleatorio;
    unsigned char armarios = 0;

    while (1) {

        menu();
        printf("Escolha a opção : ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (armarios == 255) {
                    printf("Todos os armários estão ocupados.\n");
                } else {
                    do {
                        armarioAleatorio = rand() % 8;
                    } while (armarios & (1 << armarioAleatorio));
                    armarios |= (1 << armarioAleatorio);
                    printf("Armário %d foi ocupado.\n", armarioAleatorio + 1);
                }
                break;
            case 2:
                if (armarios == 0) {
                    printf("Todos os armários estão livres\n");
                } else {
                    printf("Digite o número do armário a ser liberado entre 1 e 8: ");
                    scanf("%d", &armarioAleatorio);
                    if (armarioAleatorio < 1 || armarioAleatorio > 8) {
                        printf("Número de armário inválido\n");
                    } else if (armarios & (1 << (armarioAleatorio - 1))) {
                        armarios &= ~(1 << (armarioAleatorio - 1));
                        printf("Armário %d foi liberado\n", armarioAleatorio);
                    } else {
                        printf("Armário %d já está livre\n", armarioAleatorio);
                    }
                }
                break;
            case 3:
                printf("Programa fechando\n");
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}