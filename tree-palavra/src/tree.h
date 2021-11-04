#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Record Record;
typedef struct Tree Tree;

struct Record {
	char *palavra;
	int key;
};

struct Tree {
	Record reg;
	Tree *esq, *dir;
};

Tree* createTree();
void insertItem(Tree **t, Record r);
void pesquisaPalavra(Tree **t, Tree **aux, Record r, int *quant);
void pesquisaKey(Tree **t, Tree **aux, Record r, int *quant);

void antecessor(Tree **t, Tree *aux);
void removeItem(Tree **t, Record r);

void preordem(Tree *t);
void central(Tree *t);
void posordem(Tree *t);
void palavras(Tree *t);

#endif