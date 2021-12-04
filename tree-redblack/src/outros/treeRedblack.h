/**
    def_header.c
	Using windows.h for coloring the nodes in console.
	
    @author George Papageorgakis
    @version 1.0 01/2012
*/
#ifndef DEF_HEADER_H
#define	DEF_HEADER_H
#include <stdio.h>
#include <stdlib.h>
// #include <windows.h>   // WinApi header

void Left_Rotate(struct node *x);
void Right_Rotate(struct node *y);
void fix_insert(struct node *aux);
void rb_insert(struct node *x,struct node *y,struct node *temp);
void RB_transplant(struct node *aux,struct node *auxchild);

struct node *tree_successor(struct node *aux_succ);

void RB_delete_fix(struct node *x,struct node *w);
void RB_delete(struct node* z,struct node* y,struct node *x);
void search_delete(struct node *aux,int z);

void io_print(struct node *aux,struct node *auxnill);
void tree_print(struct node *aux,struct node *nill);

void preordem(struct node *aux);
void central(struct node *aux);
int check(struct node *aux,int z,int chk);

enum type {black, red};

struct node {
	enum type color;
	int key;
	struct node *LC, *RC, *P;
};

#endif	/* DEF_HEADER_H */
// #ifndef TREE_H
// #define TREE_H

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// typedef struct Record Record;
// typedef struct Tree Tree;

// struct Record {
// 	int value;
// 	int key;
// };

// struct Tree {
// 	Record reg;
// 	Tree *esq, *dir;
// 	Tree *pai;
// 	bool cor; // 1 - vermelho | 0 - preto
// };

// Tree* createTree();
// void insertItem(Tree **item, Tree **raiz, Record r);
// void corrigeInsersao(Tree **raiz, Tree **item);
// void pesquisa(Tree **t, Tree **aux, Record r);

// void antecessor(Tree **t, Tree *aux);
// void removeItem(Tree **t, Tree **f, Record r);

// void preordem(Tree *t);
// void central(Tree *t);
// void posordem(Tree *t);

// void rotacaoSimplesDireita(Tree **raiz, Tree **x);
// void rotacaoSimplesEsquerda(Tree **raiz, Tree **x);

// #endif