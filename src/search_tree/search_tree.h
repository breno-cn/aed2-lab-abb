#pragma once

#include "node.h"

typedef struct search_tree_t {
    node_t *start;
} search_tree_t;

search_tree_t *Tree_new();
void Tree_read_file(search_tree_t *tree, char *filepath);
node_t *Tree_search(search_tree_t *tree, int cep);
void Tree_insert(search_tree_t *tree, node_t *node);
