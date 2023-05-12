#pragma once

#define STATE_SIZE 3
#define CITY_SIZE 32
#define STREET_SIZE 128

typedef struct data_t {
    int cep;
    char state[STATE_SIZE];
    char city[CITY_SIZE];
    char street[STREET_SIZE];
} data_t;

typedef struct node_t {
    data_t *data;
    struct node_t *left;
    struct node_t *right;
    struct node_t *parent;
} node_t;

node_t *Node_new(int cep, char *state, char *city, char *street);
node_t *Node_search(node_t *current, int cep);
void Node_insert(node_t **current, node_t *to_insert);

void Node_central(node_t *current);
void Node_pre(node_t *current);
void Node_post(node_t *current);
