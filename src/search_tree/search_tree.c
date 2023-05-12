#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "search_tree.h"

#define BUFFER_SIZE 512

search_tree_t *Tree_new() {
    search_tree_t *tree = malloc(sizeof(search_tree_t));
    if (!tree)
        return NULL;

    tree->start = NULL;
    return tree;
}

void Tree_read_file(search_tree_t *tree, char *filepath) {
    FILE *file = fopen(filepath, "r");

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        int cep = atoi(strtok(buffer, " "));
        char *state = strtok(NULL, " ");
        char *city = strtok(NULL, " ");
        char *street = strtok(NULL, "\n");

        printf("%d %s %s %s\n", cep, state, city, street);

        if (Tree_search(tree, cep)) {
            printf("ja existe\n");
            continue;
        }

        node_t *node = Node_new(cep, state, city, street);
        Tree_insert(tree, node);
    }

    fclose(file);
}

node_t *Tree_search(search_tree_t *tree, int cep) {
    return Node_search(tree->start, cep);
}

void Tree_insert(search_tree_t *tree, node_t *node) {
    Node_insert(&(tree->start), node);
}

void Tree_central(search_tree_t *tree) {
    Node_central(tree->start);
}

void Tree_pre(search_tree_t *tree) {
    Node_pre(tree->start);
}

void Tree_post(search_tree_t *tree) {
    Node_post(tree->start);
}