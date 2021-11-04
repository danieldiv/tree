#include "tree.h"

int main() {

	system("clear");

	Tree *raiz;
	Record r;

	raiz = createTree();

	int vetor[] = {12, 7, 13, 23, 11, 3, 4, 8, 10, 99, 1, 17, 9};
	int tam = sizeof(vetor)/sizeof(vetor[0]);

	Tree *aux;

	printf("ELEMENTOS ARVORE: { ");
	for(int i=0; i < tam; i++) {
		r.key = vetor[i];
		printf("%d ", r.key);
		insertItem(&raiz, r);
	}
	printf("}\n\n");
	
	printf("PRE ORDEN: { ");
	preordem(raiz);
	
	printf("}\n\nCENTRAL: { ");
	central(raiz);
	
	printf("}\n\nPOS ORDEN: { ");
	posordem(raiz);
	printf("}\n");

	r.key = 23;
	removeItem(&raiz, r);
	r.key = 11;
	removeItem(&raiz, r);
	r.key = 12;
	removeItem(&raiz, r);
	r.key = 8;
	removeItem(&raiz, r);

	printf("\n==========================");

	printf("\n\nREMOVE (23, 11, 12, 8) E IMPRIME ARVORE: { ");
	central(raiz);

	printf("}\n\nPRE ORDEN: { ");
	preordem(raiz);
	
	printf("}\n\nPOS ORDEN: { ");
	posordem(raiz);
	printf("}\n\n");

	return EXIT_SUCCESS;
}