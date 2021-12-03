// #include "ArvoreLLRB.h"

// ArvoreLLRB *raiz;

// int cor(struct NO* H) {
//     if(H == NULL)
//         return BLACK;
//     else
//         return H->cor;
// }

// void trocaCor(struct NO* H) {
//     H->cor = !H->cor;
//     if(H->esq != NULL)
//         H->esq->cor = !H->esq->cor;
//     if(H->dir != NULL)
//         H->dir->cor = !H->dir->cor;
// }

// struct NO* rotacionaEsquerda(struct NO* A) {
//     struct NO* B = A->dir;
//     A->dir = B->esq;
//     B->esq = A;
//     B->cor = A->cor;
//     A->cor = RED;
//     return B;
// }

// struct NO* rotacionaDireita(struct NO* A) {
//     struct NO* B = A->esq;
//     A->esq = B->dir;
//     B->dir = A;
//     B->cor = A->cor;
//     A->cor = RED;
//     return B;
// }

// struct NO* move2EsqRed(struct NO* H) {
//     trocaCor(H);

//     if(cor(H->dir->esq) == RED) {
//         H->dir = rotacionaDireita(H->dir);
//         H = rotacionaEsquerda(H);
//         trocaCor(H);
//     }
//     return H;
// }

// struct NO* move2DirRed(struct NO* H) {
//     trocaCor(H);

//     if(cor(H->esq->esq) == RED) {
//         H = rotacionaDireita(H);
//         trocaCor(H);
//     }
//     return H;
// }

// struct NO* balancear(struct NO* H) {
//     if(cor(H->dir) == RED)
//         H = rotacionaEsquerda(H);
//     if(H->esq != NULL && cor(H->esq) == RED && cor(H->esq->esq) == RED)
//         H = rotacionaDireita(H);
//     if(cor(H->esq) == RED && cor(H->dir) == RED)    
//         trocaCor(H);
    
//     return H;
// }

// int insere_ArvLLRB(ArvoreLLRB *raiz, int valor) {
//     int resp = 0;

//     *raiz = insereNO(*raiz, valor, &resp);
//     if((*raiz) != NULL)
//         (*raiz)->cor = BLACK;
    
//     return resp;
// }

// struct NO* insereNO(struct NO* H, int valor, int *resp) {
//     if(H == NULL) {
//         struct NO *novo;
//         novo = (struct NO*)malloc(sizeof(struct NO));

//         if(novo == NULL) {
//             *resp = 0;
//             return NULL;
//         }
//         novo->info = valor;
//         novo->cor = RED;
//         novo->dir = NULL;
//         novo->esq = NULL;
//         *resp = 1;

//         return novo;
//     }

//     if(valor == H->info)
//         *resp = 0;
//     else {
//         if(valor < H->info)
//             H->esq = insereNO(H->esq, valor, resp);
//         else
//             H->dir = insereNO(H->dir, valor, resp);
//     }

//     if(cor(H->dir) == RED && cor(H->esq) == BLACK)
//         H = rotacionaEsquerda(H);

//     if(cor(H->esq) == RED && cor(H->esq->esq) == RED)
//         H = rotacionaDireita(H);

//     if(cor(H->esq) == RED && cor(H->dir) == RED)
//         trocaCor(H);

//     return H;
// }

// void preordem(struct NO *t) {
// 	if(!(t == NULL)) {
// 		printf("%d ", t->info);
// 		preordem(t->esq);
// 		preordem(t->dir);
// 	}
// }

// void central(struct NO *t) {
// 	if(!(t == NULL)) {
// 		central(t->esq);
// 		printf("%d:%d ", t->info, t->cor);
// 		central(t->dir);
// 	}
// }

// void posordem(struct NO *t) {
// 	if(!(t == NULL)) {
// 		posordem(t->esq);
// 		posordem(t->dir);
// 		printf("%d ", t->info);
// 	}
// }
