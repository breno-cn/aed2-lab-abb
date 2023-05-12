#include <stdio.h>

#include "search_tree/search_tree.h"

int main() {
    search_tree_t *tree = Tree_new();
    char *filepath = "arq.txt";
    Tree_read_file(tree, filepath);

    printf("-------------------------------------------------\n");
    Tree_central(tree);

    return 0;
}
