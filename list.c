#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50

char listaDeCompras[MAX_ITEMS][MAX_NAME_LEN];
int contadorDeItens = 0;

void adcItem()
{
    if (contadorDeItens < MAX_ITEMS)
    {
        printf("Nome do item: ");
        getchar();
        fgets(listaDeCompras[contadorDeItens], MAX_NAME_LEN, stdin);
        listaDeCompras[contadorDeItens][strcspn(listaDeCompras[contadorDeItens], "\n")] = 0;
        contadorDeItens++;
    }
    else
    {
        printf("Lista cheia!\n");
    }
}

void removeItem()
{
    printf("Item para remover: ");
    char item[MAX_NAME_LEN];
    getchar();
    fgets(item, MAX_NAME_LEN, stdin);
    item[strcspn(item, "\n")] = 0;

    for (int i = 0; i < contadorDeItens; i++)
    {
        if (strcmp(listaDeCompras[i], item) == 0)
        {
            for (int j = i; j < contadorDeItens - 1; j++)
            {
                strcpy(listaDeCompras[j], listaDeCompras[j + 1]);
            }
            contadorDeItens--;
            return;
        }
    }
    printf("Item não encontrado.\n");
}

void exibirItens()
{
    if (contadorDeItens == 0)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        for (int i = 0; i < contadorDeItens; i++)
        {
            printf("%d. %s\n", i + 1, listaDeCompras[i]);
        }
    }
}

void ordenarItens()
{
    for (int i = 0; i < contadorDeItens - 1; i++)
    {
        for (int j = i + 1; j < contadorDeItens; j++)
        {
            if (strcmp(listaDeCompras[i], listaDeCompras[j]) > 0)
            {
                char temp[MAX_NAME_LEN];
                strcpy(temp, listaDeCompras[i]);
                strcpy(listaDeCompras[i], listaDeCompras[j]);
                strcpy(listaDeCompras[j], temp);
            }
        }
    }
    printf("Lista ordenada!\n");
}

void contarItens()
{
    printf("Total de itens: %d\n", contadorDeItens);
}

int main()
{
    int opcao;

    do
    {
        printf("\n1. Adicionar\n2. Remover\n3. Exibir\n4. Ordenar\n5. Contar\n0. Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adcItem();
            break;
        case 2:
            removeItem();
            break;
        case 3:
            exibirItens();
            break;
        case 4:
            ordenarItens();
            break;
        case 5:
            contarItens();
            break;
        }
    } while (opcao != 0);

    return 0;
}
