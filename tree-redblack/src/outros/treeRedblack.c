// #include "treeRedblack.h"

// Tree* createTree() {
// 	return NULL;
// }

// void rotacaoSimplesDireita(Tree **raiz, Tree **x) {
// 	printf("rotacao D 1: %d\n", (*x)->dir->reg.key);
 
// 	Tree *y;

// 	y = (*x)->esq;
// 	(*x)->esq = y->dir;
// 	y->dir->pai = (*x);
// 	y->pai = (*x)->pai;

// 	if((*x)->pai == NULL)
// 		(*raiz) = y;
// 	else if((*x) == (*x)->pai->dir)
// 		(*x)->pai->dir = y;
// 	else
// 		(*x)->pai->esq = y;
// 	y->dir = (*x);
// 	(*x)->pai = y;
// }

// void rotacaoSimplesEsquerda(Tree **raiz, Tree **x) {
// 	printf("rotacao E 1\n");

// 	Tree *y;

// 	y = (*x)->dir;
// 	(*x)->dir = y->esq;
// 	y->esq->pai = (*x);
// 	y->pai = (*x)->pai;

// 	if((*x)->pai == NULL)
// 		(*raiz) = y;
// 	else if((*x) == (*x)->pai->esq)
// 		(*x)->pai->esq = y;
// 	else
// 		(*x)->pai->dir = y;
// 	y->esq = (*x);
// 	(*x)->pai = y;
// }

// void corrigeInsersao(Tree **raiz, Tree **item) {
// 	Tree *tio = createTree();

// 	printf("entrou na correcao\n");
// 	while((*item) != (*raiz) && (*item)->pai->cor) {
// 		printf("loop\n");

// 		if((*item)->pai == NULL) {
// 			printf("pai null\n");
// 			return;
// 		} else {
// 			printf("pai normal\n");
// 		}

// 		if((*item)->pai->pai == NULL) {
// 			printf("avo null\n");
// 			return;
// 		} else {
// 			printf("avo normal\n");
// 		}
			

// 		if((*item)->pai == (*item)->pai->pai->esq) {
// 			printf("primeiro if\n");
// 			tio = (*item)->pai->pai->dir;

// 			printf("antes do if\n");
// 			if(tio->cor) {
// 				printf("dentro do if\n");
// 				(*item)->pai->cor = false;
// 				tio->cor = false;
// 				(*item)->pai->pai->cor = true;
// 				(*item) = (*item)->pai->pai;
// 				printf("finalizou itens do if\n");
// 			}
// 			else if((*item) == (*item)->pai->dir) {
// 				printf("else if\n");
// 				(*item) = (*item)->pai;

// 				if((*item)->dir != NULL && (*raiz)->pai == NULL)
// 					rotacaoSimplesEsquerda(raiz, item);
// 				else
// 					return;
// 			}
// 			printf("depois do else if: %d\n", (*item)->reg.key);

// 			// if((*item)->pai == NULL) {
// 			// 	printf("depois do else if pai: null\n");
// 			// } else {
// 			// 	printf("depois do else if pai: %d\n", (*item)->pai->reg.key);
// 			// }
			
// 			if((*item)->pai != NULL) {
// 				(*item)->pai->cor = false;
// 				printf("depois do else if pai: %d\n", (*item)->pai->reg.key);
				
// 				if((*item)->pai->pai != NULL) {
// 					(*item)->pai->pai->cor = true;
// 					printf("depois do else if pai: %d\n", (*item)->pai->pai->reg.key);
// 				} else {
// 					printf("avo null\n");
// 				}
// 			} else {
// 				printf("pai null\n");
// 			}

// 			printf("finalizou itens depois do if\n");

// 			// if((*item)->pai->pai == NULL) {
// 			// 	printf("pai do pai null\n");
// 			// } else {
// 			// 	printf("pai do pai normal: %d\n", (*item)->pai->pai->reg.key);
// 			// }

// 			if((*item)->pai != NULL) {
// 				if((*item)->pai->pai->esq != NULL && (*raiz)->pai == NULL) {
// 					printf("fazendo rotacao fora direita\n");
// 					rotacaoSimplesDireita(raiz, &(*item)->pai->pai);
// 				}
// 				else {
// 					printf("retornando\n");
// 					return;
// 				}
// 			} else {
// 				return;
// 			}
// 			printf("passou a rotacao 1\n");
// 		} else {
// 			printf("entrou no else 2\n");
// 			tio = (*item)->pai->pai->esq;

// 			if(tio->cor) {
// 				(*item)->pai->cor = false;
// 				tio->cor = false;
// 				(*item)->pai->pai->cor = true;
// 				(*item) = (*item)->pai->pai;
// 			}
// 			else if((*item) == (*item)->pai->esq) {
// 				(*item) = (*item)->pai;

// 				if((*item)->esq != NULL && (*raiz)->pai == NULL)
// 					rotacaoSimplesDireita(raiz, item);
// 				else
// 					return;
// 			}
// 			(*item)->pai->cor = false;
// 			(*item)->pai->pai->cor = true;

// 			if((*item)->pai->pai->dir != NULL && (*raiz)->pai == NULL)
// 				rotacaoSimplesEsquerda(raiz, &(*item)->pai->pai);
// 			else
// 				return;
// 			printf("passou a rotacao 2\n");
// 		} 
// 		printf("passou do if e else\n");
// 	}
// 	printf("finalizou a correcao\n");
// 	(*raiz)->cor = false;
// 	printf("mudou a cor\n");
// }

// void insertItem(Tree **item, Tree **raiz, Record r) {
// 	printf("\ninicio insercao (r): %d\n", r.key);
// 	if(*item == NULL)
// 		printf("item nulo\n");
// 	else {
// 		printf("item existente: %d\n", (*item)->reg.key);
		
// 		if((*item)->esq != NULL)
// 			printf("item esq: %d\n", (*item)->esq->reg.key);
// 		if((*item)->dir != NULL)
// 			printf("item dir: %d\n", (*item)->dir->reg.key);
// 	}
		
// 	system("read -p\"\nparada\" continue");
// 	if(*item == NULL) {
// 		printf("inserindo %d\n", r.key);

// 		if(*raiz == NULL) {
// 			printf("\nraiz eh nula\n\n");
// 			*item = (Tree*)malloc(sizeof(Tree));
// 			(*item)->pai = NULL;
			
// 		} else {
// 			*item = (Tree*)malloc(sizeof(Tree));
// 			(*item)->pai = (*raiz);
// 		}
// 		(*item)->esq = NULL;
// 		(*item)->dir = NULL;
// 		(*item)->reg = r;
// 		(*item)->cor = true;
			

		
// 	} else {
// 		if(r.key < (*item)->reg.key) {
// 			printf("%d < %d\n", r.key, (*item)->reg.key);
// 			insertItem(&(*item)->esq, item, r);
// 		}

// 		if(r.key > (*item)->reg.key) {
// 			printf("%d > %d\n", r.key, (*item)->reg.key);
// 			insertItem(&(*item)->dir, item, r);
// 		}
			
// 	}
// 		printf("correcaoItem: %d-%d\n", (*item)->reg.key, (*item)->cor);
// 		printf("correcaoRaiz: %d-%d\n", (*raiz)->reg.key, (*raiz)->cor);
// 		corrigeInsersao(raiz, item);
// }

// void pesquisa(Tree **t, Tree **aux, Record r) {
// 	if(*t == NULL) {
// 		printf("[ERRO]: Node (%d) not found!\n", r.key);
// 		return;
// 	}

// 	if((*t)->reg.key > r.key) { pesquisa(&(*t)->esq, aux, r); return; }
// 	if((*t)->reg.key < r.key) { pesquisa(&(*t)->dir, aux, r); return; }

// 	*aux = *t;
// }

// void antecessor(Tree **t, Tree *aux) {
// 	if((*t)->dir != NULL) {
// 		antecessor(&(*t)->dir, aux);
// 		return;
// 	}

// 	aux->reg = (*t)->reg;
// 	aux = *t;
// 	*t = (*t)->esq;
// 	free(aux);
// }

// void removeItem(Tree **t, Tree **f, Record r) {
// 	Tree *aux;

// 	if(*t == NULL) {
// 		printf("[ERROR]: Record (%d) not found!!!\n", r.key);
// 		return;
// 	}

// 	if(r.key < (*t)->reg.key) { removeItem(&(*t)->esq, t, r); return; }
// 	if(r.key > (*t)->reg.key) { removeItem(&(*t)->dir, t, r); return; }

// 	if((*t)->dir == NULL) {
// 		aux = *t;
// 		*t = (*t)->esq;
// 		free(aux);

// 		return;
// 	}

// 	if((*t)->esq != NULL) {
// 		antecessor(&(*t)->esq, *t);
		
// 		return;
// 	}

// 	aux = *t;
// 	*t = (*t)->dir;
// 	free(aux);
	
// }

// void preordem(Tree *t) {
// 	if(!(t == NULL)) {
// 		printf("%d ", t->reg.key);
// 		preordem(t->esq);
// 		preordem(t->dir);
// 	}
// }

// void central(Tree *t) {
// 	if(!(t == NULL)) {
// 		central(t->esq);
// 		printf("(%d:%d)", t->reg.key, t->cor);

// 		if(t->pai != NULL) {
// 			printf(" - (pai: %d) ", t->pai->reg.key);

// 			if(t->pai->pai != NULL) {
// 				printf(" - (pai-pai: %d)", t->pai->pai->reg.key);

// 				if(t->pai->pai->dir != NULL && t->pai->pai->dir->reg.key != t->pai->reg.key)
// 					printf(" - (tio: %d)", t->pai->pai->dir->reg.key);
// 				else if(t->pai->pai->esq != NULL && t->pai->pai->esq->reg.key != t->pai->reg.key)
// 					printf(" - (tio: %d)", t->pai->pai->esq->reg.key);
// 			}
// 		}
// 		printf("\n");

// 		central(t->dir);
// 	}
// }

// void posordem(Tree *t) {
// 	if(!(t == NULL)) {
// 		posordem(t->esq);
// 		posordem(t->dir);
// 		printf("%d ", t->reg.key);
// 	}
// }

// //item = novo
// // void insertItem(Tree **raiz, Tree **item, Record r) {
// // 	// Tree *novaRaiz = (*raiz);
// // 	// Tree *pai = NULL;
// // 	// Tree *atual = (*raiz);

// // 	// while(atual != NULL) {
// // 	// 	pai = atual;
// // 	// 	atual = ((*item)->reg.key < atual->reg.key) ? atual->esq : atual->dir;
// // 	// }

// // 	// (*item)->pai = atual;

// // 	// if(pai == NULL)
// // 	// 	novaRaiz = (*item);
// // 	// else if((*item)->reg.key < pai->reg.key)
// // 	// 	pai->esq = (*item);
// // 	// else {
// // 	// 	pai->dir = (*item);
// // 	// 	(*item)->esq = NULL;
// // 	// 	(*item)->dir = NULL;
// // 	// 	(*item)->cor = true;

// // 	// 	corrigeInsersao(&novaRaiz, item);
// // 	// }

// // 	if(*item == NULL) {
// // 		// system("read -p\"\nraiz == null\" continue");
// // 		printf("r: %d\n", r.key);
// // 		*item = (Tree*)malloc(sizeof(Tree));
// // 		(*item)->esq = NULL;
// // 		(*item)->dir = NULL;
// // 		(*item)->reg = r;
		
// // 		(*item)->pai = (*raiz);
// // 		(*item)->cor = true;
// // 	} 
// // 	else {
// // 		// system("read -p\"\ninsert else\" continue");
// // 		Tree *tio = createTree();

// // 		if(r.key < (*raiz)->reg.key)
// // 			insertItem(raiz, &(*raiz)->esq, r);

// // 		if(r.key > (*raiz)->reg.key) 
// // 			insertItem(raiz, &(*raiz)->dir, r);

// 	// 	while((*item) != (*raiz) && (*item)->pai->cor) {
// 	// 		printf("loop\n");
// 	// 		if((*item)->pai == (*item)->pai->pai->esq) {
// 	// 			tio = (*item)->pai->pai->dir;

// 	// 			if(tio->cor) {
// 	// 				(*item)->pai->cor = false;
// 	// 				tio->cor = false;
// 	// 				(*item)->pai->pai->cor = true;
// 	// 				(*item) = (*item)->pai->pai;
// 	// 			}
// 	// 			else if((*item) == (*item)->pai->dir) {
// 	// 				(*item) = (*item)->pai;
// 	// 				rotacaoSimplesEsquerda(raiz, item);
// 	// 			}
// 	// 			(*item)->pai->cor = false;
// 	// 			(*item)->pai->pai->cor = true;
// 	// 			rotacaoSimplesDireita(raiz, &(*item)->pai->pai);
// 	// 		} else {
// 	// 			if((*item)->pai == (*item)->pai->pai->dir) {
// 	// 				tio = (*item)->pai->pai->esq;

// 	// 				if(tio->cor) {
// 	// 					(*item)->pai->cor = false;
// 	// 					tio->cor = false;
// 	// 					(*item)->pai->pai->cor = true;
// 	// 					(*item) = (*item)->pai->pai;
// 	// 				}
// 	// 				else if((*item) == (*item)->pai->esq) {
// 	// 					(*item) = (*item)->pai;
// 	// 					rotacaoSimplesDireita(raiz, item);
// 	// 				}
// 	// 				(*item)->pai->cor = false;
// 	// 				(*item)->pai->pai->cor = true;
// 	// 				rotacaoSimplesEsquerda(raiz, &(*item)->pai->pai);
// 	// 			}
// 	// 		}
// 	// 	}
// 	// }
// 		// (*raiz)->cor = false;
// // }