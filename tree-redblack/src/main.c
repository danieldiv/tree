#include "tree.h"

int main() {

	system("clear");

	Tree *raiz;
	Record r;

	raiz = createTree();

	int vetor[] = {8,4,15,2,6,5,12,13};
	// int vetor[] = {10,2,7,5,3,9,16,4,11,1,6,23,14};
	// int vetor[] = {78,44,67,92,22,110,16,54,23,32,37};
	int tam = sizeof(vetor)/sizeof(vetor[0]);

	Tree *aux;

	for(int i=0; i < tam; i++) {
		r.key = vetor[i];
		insertItem(&raiz, r);
	}
	
	printf("PRE ORDEN: { ");
	preordem(raiz);
	
	printf("}\nCENTRAL: { ");
	central(raiz);
	
	printf("}\nPOS ORDEN: { ");
	posordem(raiz);
	printf("}\n");

	return EXIT_SUCCESS;
}