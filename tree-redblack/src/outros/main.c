#include<stdio.h>
#include<stdlib.h>

//0 is black
//1 is red

/* Rules of Red-Black Trees
    1. Root node is black
    2. The depth to every external node is the same (remember to count black nodes)
    3. Every red node's children are black
    4. every external node is black

    Inserting a Value
    1. Insert appropriately into the tree and assume red, unless 
        first node then color black
    2. 

    Rebalance
    
    Case 1 (d is black):
    c->  B            b->   B
        /  \               /  \ 
 b->   R d->B        a->  R c->R
     /   \       -->       \    \
a-> R     B                 B d-> B  

    case 2(d is red):

    c->  B            c->    R
        /  \               /   \ 
 b->   R d-> R        b-> B d-> B
     /          -->      /       \
a-> R                a->R   

*/

typedef struct Node{
   struct Node *left;
   struct Node *right;
   struct Node *parent;
   int val;
   int color;

} Node;

typedef struct Tree{
   Node *root;
} Tree;

int rebalance(Node*, Tree*);
int insert(Tree*, int);
int inorder(Node*);
int rotateRight(Node*, Tree*);
int rotateLeft(Node*, Tree*);
int pushColorDown(Node*);


int insert(Tree *t, int val){
    Node *current = t->root;
    Node *left = t->root->left;
    Node *right = t->root->right;
    while(1){
        //Case: Root not set
        if(left == NULL && right == NULL && current->val == -1){
            current->val = val;
            break;
        }
        //Case: value is less than current node value
        if(current->val > val){
            //SubCase: left node of current is set, iterate to next node
            if(left != NULL){
                current = left;
                right = current->right;
                left = current->left;
            }
            //SubCase: left node is not set, set to val
            else{
                left = (Node*)malloc(sizeof(Node));
                left->val = val;
                left->parent = current;
                left->color = 1;
                left->left = NULL;
                left->right = NULL;
                current->left = left;
                current = left;
                break;
            }
        }
        //Case: Val is greater than or equal to current val
        else{
            //subcase: 
            if(right != NULL){
                current = right;
                right = current->right;
                left = current->left;
            }
            else{
                right = (Node*)malloc(sizeof(Node));
                right->val = val;
                right->parent = current;
                right->color = 1;
                right->left = NULL;
                right->right = NULL;
                current->right = right;
                current = right;
                break;
            }
        }
    }
    rebalance(current, t);
    return 0;
    
}

//remember node here is actually parent of recently inserted node
int rotateRight(Node* node, Tree* t){
    Node* parent = node->parent;
    //check parent is not root
    if(parent->parent != NULL){
        Node* grandparent = parent->parent;
        //assign parent right to left of grandparent
        parent->left = node->right;
        if(node->right != NULL){
            node->right->parent = parent;
        }
        node->right = parent;
        node->parent = grandparent;
        parent->parent = node;
        // if(grandparent->left->val ==)
        if(grandparent->right != NULL && parent->val == grandparent->right->val){
            grandparent->right = node;
        }
        else{
            grandparent->left = node;
        }
        // pushColorDown(node);

    }
    else{
        //handle being root here

        //assign parent right to left of grandparent
        parent->left = node->right;
        if(node->right != NULL){
            node->right->parent = parent;
        }
        node->right = parent;
        node->parent = NULL;
        parent->parent = node;

        t->root = node;
        // pushColorDown(node);

    }
    
}

int rotateLeft(Node* node, Tree* t){
    Node* parent = node->parent;
    //check parent is not root
    if(parent->parent != NULL){
        Node* grandparent = parent->parent;
        //assign parent right to left of grandparent
        parent->right = node->left;
        if(node->left != NULL){
            node->left->parent = parent;
        }
        node->left = parent;
        node->parent = grandparent;
        parent->parent = node;
        //need to reassign grandparent to new node after rotation
        if(grandparent->right != NULL && parent->val == grandparent->right->val){
            grandparent->right = node;
        }
        else{
            grandparent->left = node;
        }
        
        // pushColorDown(node);

    }
    else{
        //handle being root here

        //assign parent right to left of grandparent
        parent->right = node->left;
        if(node->left != NULL){
            node->left->parent = parent;
        }
        node->left = parent;
        node->parent = NULL;
        parent->parent = node;

        t->root = node;
        // pushColorDown(node);

    }
}

int pushColorDown(Node* node){
        //node is root so must remain black
        if(node->parent == NULL){
            //need to check if left and right exists, one might be NULL
            if(node->left != NULL){
                node->left->color = node->color;
            }
            if(node->right != NULL){
                node->right->color = node->color;
            }
            node->color = 0;
        }
        else{
            //need to check if left and right exists, one might be NULL
            if(node->left != NULL){
                node->left->color = node->color;
            }
            if(node->right != NULL){
                node->right->color = node->color;
            }
            node->color = node->color ^ 1;
            
        }
        
        return 0;
}

int rebalance(Node* node, Tree* t){
    while(node->parent != NULL && node->color != 0 && node->parent->color == 1){
    //Check if parent and current node are both red
    Node *parent = node->parent;
    if(node->color == 1 && parent->color == 1){
        //check if check if child is left or right node of parent
        if(parent->left != NULL && parent->left->val == node->val){
            //check if parent is also left or right of grandparent
            if(parent->parent->left != NULL && parent->parent->left->val == parent->val){
                //check for uncle is red
                if(parent->parent->right != NULL && parent->parent->right->color == 1){
                    pushColorDown(parent->parent);
                }
                //perform rotation right
                else{
                    rotateRight(parent, t);
                    pushColorDown(parent);
                    node = parent;
                }
                
            }
            //parent is right child of it's parent
            else{
                //check for uncle is red
                if(parent->parent->left != NULL && parent->parent->left->color == 1){
                    pushColorDown(parent->parent);
                }
                //perform rotation right
                else{
                    rotateRight(node, t);
                    node = parent;
                }

                
            }
        }
        //child is right of parent
        else{
              //check if parent is also left or right of grandparent
            if(parent->parent->left != NULL && parent->parent->left->val == parent->val){
                if(parent->parent->right != NULL && parent->parent->right->color == 1){
                    pushColorDown(parent->parent);
                }
                else{
                    rotateLeft(node, t);
                    node = parent;
                }
            }
            //parent is right child of it's parent
            else{
                //check for uncle is red
                if(parent->parent->left != NULL && parent->parent->left->color == 1){
                    pushColorDown(parent->parent);
                }
                //perform rotation right
                else{
                    rotateLeft(parent, t);
                    pushColorDown(parent);
                    node = parent;
                }

                
            }
            
        }

    }
    }
    
}

/*

int rebalance(Node *node, Tree *t){
    if(node->parent == NULL){
        node->color = 0;
    }
    else{
        node->color = 1;
        Node *parent = node->parent;
        Node *grandparent = node->parent->parent;
        Node *greatgrandparent = NULL;
        if(parent->color == 1){
            Node *sibling = NULL;
            int siblingcreate = 0;
            int left = 0;
            //Made a critical assumption that sibling would exist, but it may not
            if(grandparent->left == NULL){

                sibling = (Node*) malloc(sizeof(Node));
                sibling->color = 0;
                
                siblingcreate = 1;
            }
            else if(grandparent->right == NULL){
                sibling = (Node*) malloc(sizeof(Node));
                sibling->color = 0;
                left = 1;
                siblingcreate = 1;
            }
            else if(grandparent->left->val == parent->val){
                sibling = grandparent->right;
                left = 1;
            }
            else{
                sibling = grandparent->left;
            }
            if(sibling->color == 0){
                //grandparent becomes child of parent
                if(left == 0){
                    grandparent->right = NULL;//Not sure I can just erase right
                    grandparent->color = 1;
                    parent->left = grandparent;
                    parent->color = 0;
                    if(grandparent->parent != NULL){
                        greatgrandparent = grandparent->parent;
                    }
                    grandparent->parent = parent;
                    
                }
                else{
                    grandparent->left = NULL;//Not sure I can just erase left
                    grandparent->color = 1;
                    parent->right = grandparent;
                    parent->color = 0;
                    if(grandparent->parent != NULL){
                        greatgrandparent = grandparent->parent;
                    }
                    grandparent->parent = parent;
                }
                if(greatgrandparent != NULL){
                        
                        //need to determine which child the grandparent 
                       // belongs to so we can properly assign the parent of inserted node
                        if(greatgrandparent->left->val < grandparent->val){
                            greatgrandparent->right = parent;
                            parent->parent = greatgrandparent;
                            //greatgrandparent = parent;
                        }
                        else{
                            greatgrandparent->left = parent;
                            parent->parent = greatgrandparent;
                            //greatgrandparent = parent;
                        }
                }
                else{
                    parent->parent = NULL;
                    grandparent->parent = parent;
                    t->root = parent;
                }
            }
            else{
                parent->color = 0;
                sibling->color = 0;
                grandparent->color = 1;
                rebalance(grandparent, t);
            }
            if(siblingcreate == 1){
                free(sibling);
            }
        }
    }

    return 0;

}
*/



int inorder(Node *node){
    printf("%d \n", node->val);
    if(node->left != NULL){
        inorder(node->left);
    }
    if(node->right != NULL){
        inorder(node->right);
    }
    
        return 0;
}

int main(int argc, char *argv[]){
    printf("Hello world!");
    int vals[9] = {5, 22, 23, 4, 2, 3, 1, 30, 29};
    Tree t;
    t.root = NULL;
    if(t.root == NULL){
        t.root = (Tree*)malloc(sizeof(Tree));
		// 			*item = (Tree*)malloc(sizeof(Tree));
    }
    t.root->left = NULL;
    t.root->right = NULL;
    t.root->parent = NULL;
    t.root->val = -1;
    t.root->color = 0;
    printf("Hello world!");
    for(int i =0; i < 9; i++){
        insert(&t, vals[i]);
        // printf("-----------------");
        // inorder(t.root);
    }

    inorder(t.root);
    return 0;
}

