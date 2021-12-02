#include "treeRedblack.h"

Tree* createTree() {
	return NULL;
}

void rotacaoSimplesDireita(Tree **raiz, Tree **x) {
	Tree *y;

	y = (*x)->esq;
	(*x)->esq = y->dir;
	y->dir->pai = (*x);
	y->pai = (*x)->pai;

	if((*x)->pai == NULL)
		(*raiz) = y;
	else if((*x) == (*x)->pai->dir)
		(*x)->pai->dir = y;
	else
		(*x)->pai->esq = y;
	y->dir = (*x);
	(*x)->pai = y;
}

void rotacaoSimplesEsquerda(Tree **raiz, Tree **x) {
	Tree *y;

	y = (*x)->dir;
	(*x)->dir = y->esq;
	y->esq->pai = (*x);
	y->pai = (*x)->pai;

	if((*x)->pai == NULL)
		(*raiz) = y;
	else if((*x) == (*x)->pai->esq)
		(*x)->pai->esq = y;
	else
		(*x)->pai->dir = y;
	y->esq = (*x);
	(*x)->pai = y;
}

void insertItem(Tree **raiz, Tree **item, Record r) {
	if(*raiz == NULL) {
		*raiz = (Tree*)malloc(sizeof(Tree));
		(*raiz)->esq = NULL;
		(*raiz)->dir = NULL;
		(*raiz)->reg = r;
		
		(*raiz)->pai = (*item);
		(*item)->cor = true;
	} else {
		Tree *tio = createTree();

		if(r.key < (*raiz)->reg.key)
			insertItem(&(*raiz)->esq, raiz, r);

		if(r.key > (*raiz)->reg.key) 
			insertItem(&(*raiz)->dir, raiz, r);

		while(item != raiz && (*item)->pai->cor) {
			printf("loop\n");
			if((*item)->pai == (*item)->pai->pai->esq) {
				tio = (*item)->pai->pai->dir;

				if(tio->cor) {
					(*item)->pai->cor = false;
					tio->cor = false;
					(*item)->pai->pai->cor = true;
					(*item) = (*item)->pai->pai;
				}
				else if((*item) == (*item)->pai->dir) {
					(*item) = (*item)->pai;
					rotacaoSimplesEsquerda(raiz, item);
				}
				(*item)->pai->cor = false;
				(*item)->pai->pai->cor = true;
				rotacaoSimplesDireita(raiz, &(*item)->pai->pai);
			} else {
				if((*item)->pai == (*item)->pai->pai->dir) {
					tio = (*item)->pai->pai->esq;

					if(tio->cor) {
						(*item)->pai->cor = false;
						tio->cor = false;
						(*item)->pai->pai->cor = true;
						(*item) = (*item)->pai->pai;
					}
					else if((*item) == (*item)->pai->esq) {
						(*item) = (*item)->pai;
						rotacaoSimplesDireita(raiz, item);
					}
					(*item)->pai->cor = false;
					(*item)->pai->pai->cor = true;
					rotacaoSimplesEsquerda(raiz, &(*item)->pai->pai);
				}
			}
		}
		(*raiz)->cor = false;
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