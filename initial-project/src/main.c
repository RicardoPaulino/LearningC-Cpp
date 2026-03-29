
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int main()
{
    print_status("Iniciando motor do Browser...");

    char *network_buffer = malloc(1024);
    if (network_buffer == NULL)
    {
        print_status("Erro ao alocar memória para o buffer de rede!");
        return 1;
    }

    strcpy(network_buffer, "Dados recebidos da rede...");
    print_status(network_buffer);

    print_status("Finalizando o motor do Browser...");
    free(network_buffer);
    network_buffer = NULL;
    return 0;
}