#include "tree.h"
#include "time.h"

int main() {

	system("clear");

	Tree *raiz;
	Tree *aux;
	Record r;

	char t = 's';

	printf("%d", (int)t);

	int tamNome, tamBusca, quantArvore, quantVetor;
	int controle;

	char nome [30][20] = {"livro", "calculadora", "tijolo", "pimenta", "banana", "abacate", "abacaxi", "leite", "manteiga", "cenoura", "macarrao", "arroz", "feijao", "limao", "televisao", "computador", "manga", "celular", "relogio", "carregador", "regua", "bolo", "janela", "caneta", "lapiz", "borracha", "armazenamento", "memoria", "perna", "ombro"};
	char busca [10][20] = {"calculadora", "banana", "casa", "manteiga", "cenoura", "televisao", "cobertor", "manga", "caneta", "ombro"};

	raiz = createTree();

	tamNome = sizeof(nome)/sizeof(nome[0]);
	tamBusca = sizeof(busca)/sizeof(busca[0]);

	printf("ELEMENTOS ARVORE: {\n");
	for(int i=0; i < tamNome; i++) {
		r.key = i;
		r.palavra = nome[i];

		printf("%d ", r.key);
		printf("%s\n", r.palavra);

		insertItem(&raiz, r);
	}
	printf("}\n\n");
	
	printf("PRE ORDEN: { ");
	preordem(raiz);
	
	printf("}\n\nCENTRAL: { ");
	central(raiz);
	
	printf("}\n\nPOS ORDEN: { ");
	posordem(raiz);

	quantArvore = 0;
	quantVetor = 0;
	controle = 1;

	printf("\n\n===============================\n");

	printf("\nPESQUISANDO PELA PALAVRA: { ");
	for(int i=0; i < tamBusca; i++) {
		printf("%s ", busca[i]);
	}
	printf("}\n\n");

	for(int i=0; i < tamBusca; i++) {
		r.palavra = busca[i];
		pesquisaPalavra(&raiz, &aux, r, &quantArvore);
	}

	// PESQUISA NO VETOR NORMAL
	for(int i=0; i < tamBusca; i++) {
		for(int j=0; j < tamNome; j++) {
			quantVetor++;
			controle = strcmp(busca[i], nome[j]);

			if(controle == 0) {
				controle = 1;
				break;
			}
		}
	}

	printf("\nQuantidade de acessos na arvore: %d\n", quantArvore);
	printf("Quantidade de acessos medio na arvore: %d\n", (quantArvore / tamBusca));
	printf("\nQuantidade de acessos no vetor: %d\n", quantVetor);
	printf("Quantidade de acessos medio no vetor: %d\n", (quantVetor / tamBusca));

	// int buscaKey [10] = {1, 4, 31, 8, 9, 14, 6, 16, 23, 10};

	// printf("\n===============================\n");
	// printf("\nPESQUISANDO PELA KEY: { ");


	// quantArvore = 0;
	// quantVetor = 0;

	// for(int i=0; i < 10; i++) {
	// 	printf("%d ", buscaKey[i]);
	// }
	// printf("}\n\n");

	// for(int i=0; i < 10; i++) {
	// 	r.key = buscaKey[i];
	// 	pesquisaKey(&raiz, &aux, r, &quantArvore);
	// }

	// for(int i=0; i < 10; i++) {
	// 	for(int j=0; j < tamNome; j++) {
	// 		quantVetor++;

	// 		if(buscaKey[j] == i)
	// 			break;
	// 	}
	// }

	// printf("\nQuantidade de acessos na arvore: %d\n", quantArvore);
	// printf("Quantidade de acessos medio na arvore: %d\n", (quantArvore / tamBusca));
	// printf("\nQuantidade de acessos no vetor: %d\n", quantVetor);
	// printf("Quantidade de acessos medio no vetor: %d\n", (quantVetor / tamBusca));

	return EXIT_SUCCESS;
}