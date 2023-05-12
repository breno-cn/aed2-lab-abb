#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"

node_t *Node_new(int cep, char *state, char *city, char *street) {
    node_t *node = malloc(sizeof(node));
    if (!node)
        return NULL;

    node->data = malloc(sizeof(data_t));
    if (!node->data)
        return NULL;

    node->data->cep = cep;
    strcpy(node->data->state, state);
    strcpy(node->data->city, city);
    strcpy(node->data->street, street);

    return node;
}

node_t *Node_search(node_t *current, int cep) {
    // é um nó folha, encerrar
    if (current == NULL)
        return NULL;

    // encontrou o cep
    if (current->data->cep == cep)
        return current;

    if (cep < current->data->cep)
        return Node_search(current->left, cep);

    return Node_search(current->right, cep);
}

void Node_insert(node_t **current, node_t *to_insert) {
    // primeiro nó a ser inserido
    if (current == NULL) {
        printf("primeiro no\n");
        *current = to_insert;
        return;
    }

    // nó sem filhos, inserir
    if (to_insert->data->cep < (*current)->data->cep) {
        printf("na esquerda\n");
        // inserir na esquerda
        if ((*current)->left == NULL) {
            (*current)->left = to_insert;
            return;
        }
        Node_insert(&(*current)->left, to_insert);
    } else {
        printf("na direita\n");
        // inserir na direita
        if ((*current)->right == NULL) {
            (*current)->right = to_insert;
            return;
        }
        Node_insert(&(*current)->right, to_insert);
    }
}

void Node_central(node_t *current) {
    if (!current)
        return;

    Node_central(current->left);
    printf("%d\n", current->data->cep);
    Node_central(current->right);
}

void Node_pre(node_t *current) {
    if (!current)
        return;

    printf("%d\n", current->data->cep);
    Node_pre(current->left);
    Node_pre(current->right);
}

void Node_post(node_t *current) {
    if (!current)
        return;

    Node_post(current->left);
    Node_post(current->right);
    printf("%d\n", current->data->cep);
}
