#include <stdio.h>
#include <stdlib.h>

// Estructura que representa un nodo del árbol
struct node {
  int data;
  struct node* left;
  struct node* right;
};

// Función que crea un nuevo nodo del árbol
struct node* createNode(int data) {
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}
// Función que inserta un nuevo nodo en el árbol
void insertNode(struct node** root, int data) {
  // Si el árbol está vacío, crea un nuevo nodo y lo asigna como raíz
  if (*root == NULL) {
    *root = createNode(data);
    return;
  }
  // Si el valor del nuevo nodo es menor que el de la raíz, lo inserta en el subárbol izquierdo
  if (data < (*root)->data) {
    insertNode(&(*root)->left, data);
  }
  // Si el valor del nuevo nodo es mayor o igual que el de la raíz, lo inserta en el subárbol derecho
  else {
    insertNode(&(*root)->right, data);
  }
}

// Recorrido en inorden
void inorder(struct node* root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

// Recorrido en preorden
void preorder(struct node* root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

// Recorrido en posorden
void postorder(struct node* root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

int main() {
 // Crea la raíz del árbol
  struct node* root = NULL;

  // Inserta algunos nodos en el árbol
  insertNode(&root, -1);
  insertNode(&root, 3);
  insertNode(&root, 12);
  insertNode(&root, -4);
  insertNode(&root, 7);
  insertNode(&root, 6);
  insertNode(&root, 8);

  printf("Recorrido en inorden: ");
  inorder(root);
  printf("\nRecorrido en preorden: ");
  preorder(root);
  printf("\nRecorrido en posorden: ");
  postorder(root);
  printf("\n");

  return 0;
}