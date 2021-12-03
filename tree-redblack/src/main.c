#include "redblack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    TNoRB *arvore = NULL;
    int vetor[] = {11,2,14,1,7,15,5,8,4};
	int tam = sizeof(vetor)/sizeof(vetor[0]);

	for(int i=0; i < tam; i++) {
        insereNo(&arvore, NULL, &arvore, vetor[i]);
	}
    printf("pre ordem: { ");
    preOrder(arvore);
    printf("}\ncentral: { ");
    inOrder(arvore);
    printf("}");

    return 0;
}