#include "treeRedblack.h"

Tree* createTree() {
	return NULL;
}

void rotacaoSimplesDireita(Tree **t) {
	Tree *aux;

	aux = (*t)->esq;
	(*t)->esq = aux->dir;
	aux->dir = (*t);
	(*t) = aux;
}

void rotacaoSimplesEsquerda(Tree **t) {
	Tree *aux;

	aux = (*t)->dir;
	(*t)->dir = aux->esq;
	aux->esq = (*t);
	(*t) = aux;
}

void insertItem(Tree **t, Tree **p, Record r) {
	if(*t == NULL) {
		*t = (Tree*)malloc(sizeof(Tree));
		(*t)->esq = NULL;
		(*t)->dir = NULL;
		(*t)->reg = r;

		if((*p)->reg.key == r.key) {
			(*t)->pai = createTree();
			(*t)->cor = false;
			(*t)->isRaiz = true;
		} else {
			(*t)->pai = *p;
			(*t)->cor = true;
			(*t)->isRaiz = false;
		}
	} else {
		Tree *pai = (*t);
		Tree *avo = createTree();
		Tree *tio = createTree();
		Tree *item = createTree();

		if(r.key < (*t)->reg.key) {
			insertItem(&(*t)->esq, t, r);
			item = pai->esq;
		}

		if(r.key > (*t)->reg.key) {
			insertItem(&(*t)->dir, t, r);
			item = pai->dir;
		}

		while(item != pai && pai->cor && !pai->isRaiz) {
			if(pai->pai != NULL)
				avo = pai->pai;

			if(avo != NULL)
				printf("avo: %d\n", avo->reg.key);
			if(pai != NULL)
				printf("pai: %d\n", pai->reg.key);
			printf("item: %d\n\n", item->reg.key);

			if(pai != NULL) {
				// system("read -p \"\npai nao eh nulo\" continue");
				if(avo != NULL) {
					// system("read -p \"\navo nao eh nulo\" continue");
					if(pai->reg.key < avo->reg.key) {
						tio = avo->dir;
						// system("read -p \"\npai eh menor do que avo\" continue");
						printf("tio: %d\n", tio->reg.key);

						if(tio) {
							if(tio->cor) {
								// system("read -p \"\nEntrou no tio\" continue");
								pai->cor = false;
								tio->cor = false;
								avo->cor = true;
								item = avo;
							} else if(item->reg.key > pai->reg.key) {
								item = pai;
								system("read -p \"\nRotacao simples esquerda dentro\" continue");
								rotacaoSimplesEsquerda(t);
							}
							pai->cor = false;
							avo->cor = true;

							system("read -p \"\nRotacao simples direita fora\" continue");
							// rotacaoSimplesDireita(t);
						}
					} else {
						// system("read -p \"\npai eh maior do que avo\" continue");
						tio = avo->esq;
						if(tio) {
							if(tio->cor) {
								// system("read -p \"\nEntrou no tio\" continue");
								pai->cor = false;
								tio->cor = false;
								avo->cor = true;
								item = avo;
							} else if(item->reg.key > pai->reg.key) {
								item = pai;
								system("read -p \"\nRotacao simples direita dentro\" continue");
								rotacaoSimplesDireita(t);
							}
							pai->cor = false;
							avo->cor = true;

							system("read -p \"\nRotacao simples esquerda fora\" continue");
							// rotacaoSimplesEsquerda(t);
						}	
					}
				}
			}
		}
	}
}

void pesquisa(Tree **t, Tree **aux, Record r) {
	if(*t == NULL) {
		printf("[ERRO]: Node (%d) not found!\n", r.key);
		return;
	}

	if((*t)->reg.key > r.key) { pesquisa(&(*t)->esq, aux, r); return; }
	if((*t)->reg.key < r.key) { pesquisa(&(*t)->dir, aux, r); return; }

	*aux = *t;
}

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

		return;
	}

	if((*t)->esq != NULL) {
		antecessor(&(*t)->esq, *t);
		
		return;
	}

	aux = *t;
	*t = (*t)->dir;
	free(aux);
	
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