#include "treeRedblack.h"

Tree* createTree() {
	return NULL;
}

void rotacaoSimplesDireita(Tree **t) {
	Tree *aux;

	aux = (*t)->esq;
	(*t)->esq = aux->dir;
	aux->dir = (*t);
	// (*t)->peso = getMaxPeso( getPeso( &(*t)->esq ), getPeso( &(*t)->dir ) ) + 1;
	// aux->peso = getMaxPeso( getPeso( &(*t)->esq ), (*t)->peso ) + 1;
	(*t) = aux;
}

void rotacaoSimplesEsquerda(Tree **t) {
	Tree *aux;

	aux = (*t)->dir;
	(*t)->dir = aux->esq;
	aux->esq = (*t);
	// (*t)->peso = getMaxPeso( getPeso( &(*t)->esq ), getPeso( &(*t)->dir ) ) + 1;
	// aux->peso = getMaxPeso( getPeso( &(*t)->esq ), (*t)->peso ) + 1;
	(*t) = aux;
}

// void rotacaoDuplaDireita(Tree **t) {
// 	rotacaoSimplesEsquerda(&(*t)->esq);
// 	rotacaoSimplesDireita(t);
// }

// void rotacaoDuplaEsquerda(Tree **t) {
// 	rotacaoSimplesDireita(&(*t)->dir);
// 	rotacaoSimplesEsquerda(t);
// }

void insertItem(Tree **t, Tree **p, Record r) {
	if(*t == NULL) {
		*t = (Tree*)malloc(sizeof(Tree));
		(*t)->esq = NULL;
		(*t)->dir = NULL;
		(*t)->reg = r;

		if((*p)->reg.key == r.key) {
			(*t)->pai = createTree();
			(*t)->cor = false;
		} else {
			(*t)->pai = *p;
			(*t)->cor = true;
		}
			
		// }
		// (*t)->peso = 0;
	} else {
		Tree *pai = createTree();
		Tree *avo = createTree();
		Tree *tio = createTree();

		// if(t->pai != NULL) {
		// 	printf(" - (pai: %d) ", t->pai->reg.key);

		// 	if(t->pai->pai != NULL) {
		// 		printf(" - (pai-pai: %d)", t->pai->pai->reg.key);

		// 		if(t->pai->pai->dir != NULL && t->pai->pai->dir->reg.key != t->pai->reg.key)
		// 			printf(" - (tio: %d)", t->pai->pai->dir->reg.key);
		// 		else if(t->pai->pai->esq != NULL && t->pai->pai->esq->reg.key != t->pai->reg.key)
		// 			printf(" - (tio: %d)", t->pai->pai->esq->reg.key);
		// 	}
		// }

		if(r.key < (*t)->reg.key) {
			pai = (*t);

			insertItem(&(*t)->esq, t, r);

			// if(pai->pai != NULL) {
			// 	avo = pai->pai;

			// 	if(avo->dir != NULL && avo->dir->reg.key != pai->reg.key)
			// 		tio = avo->dir;
			// 	else if(avo->esq != NULL && avo->esq->reg.key != pai->reg.key)
			// 		tio = avo->esq;
					
			// }

			printf("E: (%d)-(%d)", (*t)->esq->reg.key, pai->reg.key);

			
			
			// if(tio != NULL)
			// 	printf("-(%d)", tio->reg.key);
			// printf("\n");
			
			// printf("E: (%d)-(%d)\n", (*t)->esq->reg.key, (*t)->reg.key);

			// if(getPeso( &(*t)->esq) - getPeso(&(*t)->dir) == 2) {
			// 	if(r.key < (*t)->esq->reg.key)
			// 		rotacaoSimplesDireita(t);
				// else 
				// 	rotacaoDuplaDireita(t);
			// }
		}

		if(r.key > (*t)->reg.key) {
			pai = (*t);

			// if(pai->dir != NULL)
			// 	tio = pai->dir;
			// else if(pai->esq != NULL)
			// 	tio = pai->esq;
			// else
			// 	tio = NULL;

			// if(pai->pai != NULL) {
			// 	avo = pai->pai;

			// 	if(avo->dir != NULL && avo->dir->reg.key != pai->reg.key)
			// 		tio = avo->dir;
			// 	else if(avo->esq != NULL && avo->esq->reg.key != pai->reg.key)
			// 		tio = avo->esq;
					
			// }

			insertItem(&(*t)->dir, t, r);
			printf("D: (%d)-(%d)", (*t)->dir->reg.key, pai->reg.key);

			// if(tio != NULL)
			// 	printf("-(%d)", tio->reg.key);
			// printf("\n");

			// if(getPeso( &(*t)->dir) - getPeso(&(*t)->esq) == 2) {
			// 	if(r.key > (*t)->dir->reg.key)
			// 		rotacaoSimplesEsquerda(t);
				// else
				// 	rotacaoDuplaEsquerda(t);
			// }
		}

		if(pai->pai != NULL) {
				avo = pai->pai;

				if(avo->dir != NULL && avo->dir->reg.key != pai->reg.key)
					tio = avo->dir;
				else if(avo->esq != NULL && avo->esq->reg.key != pai->reg.key)
					tio = avo->esq;
					
			}

		if(avo != NULL) {
			if(tio != NULL) {
				printf("-(*%d*)-(%d)", avo->reg.key, tio->reg.key);
			}
		}
		printf("\n");
		
		// printf("tio: %d\n", (*p)->reg.key);
			


	}
	// (*t)->peso = getMaxPeso( getPeso( &(*t)->esq ), getPeso( &(*t)->dir ) ) + 1;

}

// int getPeso(Tree **t) {
// 	if(*t == NULL)
// 		return -1;
// 	return (*t)->peso;
// }

// int getMaxPeso(int left, int right) {
// 	if(left > right)
// 		return left;
// 	return right;
// }

void pesquisa(Tree **t, Tree **aux, Record r) {
	if(*t == NULL) {
		printf("[ERRO]: Node (%d) not found!\n", r.key);
		return;
	}

	if((*t)->reg.key > r.key) { pesquisa(&(*t)->esq, aux, r); return; }
	if((*t)->reg.key < r.key) { pesquisa(&(*t)->dir, aux, r); return; }

	*aux = *t;
}

// void rebalanceTree(Tree **t) {

// 	int balance;
// 	int left = 0;
// 	int right = 0;

	// balance = getPeso(&(*t)->esq) - getPeso(&(*t)->dir);
	
	// if((*t)->esq)
	// 	left = getPeso(&(*t)->esq->esq) - getPeso(&(*t)->esq->dir);
	// if((*t)->dir)
	// 	right = getPeso(&(*t)->dir->esq) - getPeso(&(*t)->dir->dir);

	// printf("\n============Valores balanceamento=========\n");
	// printf("Raiz: %d, Filho esq: %d, Filho dir: %d\n", balance, left, right);
	// printf("==========================================");

	// if(balance == 2 && left >= 0)
	// 	rotacaoSimplesDireita(t);
		
	// if(balance == 2 && left < 0)
	// 	rotacaoDuplaDireita(t);

	// if(balance == -2 && right <= 0)
	// 	rotacaoDuplaEsquerda(t);
	// if(balance == -2 && right > 0)
	// 	rotacaoSimplesEsquerda(t);
// }

void antecessor(Tree **t, Tree *aux) {
	if((*t)->dir != NULL) {
		antecessor(&(*t)->dir, aux);
		return;
	}

	aux->reg = (*t)->reg;
	aux = *t;
	*t = (*t)->esq;
	free(aux);
}

void removeItem(Tree **t, Tree **f, Record r) {
	Tree *aux;

	if(*t == NULL) {
		printf("[ERROR]: Record (%d) not found!!!\n", r.key);
		return;
	}

	if(r.key < (*t)->reg.key) { removeItem(&(*t)->esq, t, r); return; }
	if(r.key > (*t)->reg.key) { removeItem(&(*t)->dir, t, r); return; }

	if((*t)->dir == NULL) {
		aux = *t;
		*t = (*t)->esq;
		free(aux);

		// rebalanceTree(f);
		return;
	}

	if((*t)->esq != NULL) {
		antecessor(&(*t)->esq, *t);
		
		// rebalanceTree(f);
		// rebalanceTree(t);
		return;
	}

	aux = *t;
	*t = (*t)->dir;
	free(aux);
	
	// rebalanceTree(f);
	// rebalanceTree(t);
}

void preordem(Tree *t) {
	if(!(t == NULL)) {
		printf("%d ", t->reg.key);
		preordem(t->esq);
		preordem(t->dir);
	}
}

void central(Tree *t) {
	if(!(t == NULL)) {
		central(t->esq);
		printf("(%d:%d)", t->reg.key, t->cor);

		if(t->pai != NULL) {
			printf(" - (pai: %d) ", t->pai->reg.key);

			if(t->pai->pai != NULL) {
				printf(" - (pai-pai: %d)", t->pai->pai->reg.key);

				if(t->pai->pai->dir != NULL && t->pai->pai->dir->reg.key != t->pai->reg.key)
					printf(" - (tio: %d)", t->pai->pai->dir->reg.key);
				else if(t->pai->pai->esq != NULL && t->pai->pai->esq->reg.key != t->pai->reg.key)
					printf(" - (tio: %d)", t->pai->pai->esq->reg.key);
			}
		}
		printf("\n");

		central(t->dir);
	}
}

void posordem(Tree *t) {
	if(!(t == NULL)) {
		posordem(t->esq);
		posordem(t->dir);
		printf("%d ", t->reg.key);
	}
}