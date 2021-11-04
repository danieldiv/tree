#include "tree.h"

Tree* createTree() {
	return NULL;
}

void insertItem(Tree **t, Record r) {
	if(*t == NULL) {
		*t = (Tree*)malloc(sizeof(Tree));
		(*t)->esq = NULL;
		(*t)->dir = NULL;
		(*t)->reg = r;
	} else {
		int ret = memcmp((*t)->reg.palavra, r.palavra, 20);

		if(ret > 0)
			insertItem(&(*t)->esq, r);

		else if(ret < 0)
			insertItem(&(*t)->dir, r);
	}

}

// PESQUISA NA ARVORE
void pesquisaPalavra(Tree **t, Tree **aux, Record r, int *quant) {
	if(*t == NULL) {
		printf("[ERRO]: Node %s not found!\n", r.palavra);
		return;
	}
	(*quant)++;

	int ret = memcmp((*t)->reg.palavra, r.palavra, 20);

	if(ret > 0) { pesquisaPalavra(&(*t)->esq, aux, r, quant); return; }
	else if(ret < 0) { pesquisaPalavra(&(*t)->dir, aux, r, quant); return; }

	*aux = *t;
}

void pesquisaKey(Tree **t, Tree **aux, Record r, int *quant) {
	if(*t == NULL) {
		printf("[ERRO]: Node %d not found!\n", r.key);
		return;
	}
	(*quant)++;

	if((*t)->reg.key > r.key) { pesquisaKey(&(*t)->esq, aux, r, quant); return; }
	if((*t)->reg.key < r.key) { pesquisaKey(&(*t)->dir, aux, r, quant); return; }

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

void removeItem(Tree **t, Record r) {
	Tree *aux;

	if(*t == NULL) {
		printf("[ERROR]: Record not fould!!!\n");
		return;
	}

	if((*t)->reg.key > r.key) { removeItem(&(*t)->esq, r); return; }
	if((*t)->reg.key < r.key) { removeItem(&(*t)->dir, r); return; }

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
		printf("%s ", t->reg.palavra);
		preordem(t->esq);
		preordem(t->dir);
	}
}

void central(Tree *t) {
	if(!(t == NULL)) {
		central(t->esq);
		printf("%s ", t->reg.palavra);
		central(t->dir);
	}
}

void posordem(Tree *t) {
	if(!(t == NULL)) {
		posordem(t->esq);
		posordem(t->dir);
		printf("%s ", t->reg.palavra);
	}
}