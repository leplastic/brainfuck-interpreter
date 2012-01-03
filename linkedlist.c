#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

struct node_t* create_first_node() {
	return create_new_node(NULL, NULL, CELL_DEFAULT_VALUE);
}

struct node_t* create_new_node(struct node_t* left, struct node_t* right, int value) {
	struct node_t* node = 
		(struct node_t*) malloc(sizeof(struct node_t));
		
	if (node == NULL) {
		perror("create_new_node: node not initialized");
		exit(1);
	}
	
	node->next = right;
	node->prev = left;
	node->value = value;
	
	return node;
}

void move_left(struct node_t** cur) {
	if (*cur == NULL) {
		perror("move_left: current node is NULL");
		exit(1);
	}
	
	if ((*cur)->prev == NULL)
		(*cur)->prev = create_new_node(NULL, *cur, CELL_DEFAULT_VALUE);
	
	*cur = (*cur)->prev;
}

void move_right(struct node_t** cur) {
	if (*cur == NULL) {
		perror("move_right: current node is NULL");
		exit(1);
	}
	
	if ((*cur)->next == NULL)
		(*cur)->next = create_new_node(*cur, NULL, CELL_DEFAULT_VALUE);
	
	*cur = (*cur)->next;
}

void decrement_value(struct node_t* node) {
	change_value(node, get_value(node) - 1);
}

void increment_value(struct node_t* node) {
	change_value(node, get_value(node) + 1);
}

void change_value(struct node_t* node, int value) {
	if (node == NULL) {
		perror("change_value: current node is NULL");
		exit(1);
	}
	
	node->value = value;
}

int get_value(struct node_t* cur) {
	if (cur == NULL) {
		perror("get_value: current node is NULL");
		exit(1);
	}
	
	return cur->value;
}

int destroy_all_nodes(struct node_t* any_node) {
	if (any_node == NULL)
		return 0;
		
	struct node_t* cur = any_node->prev;
	struct node_t* other = NULL;
	
	// destroy the left part
	while (cur != NULL) {
		other = cur->prev;
		free(cur);
		cur = other;
	}

	// destroy the current node and the right part
	cur = any_node;
	
	while (cur != NULL) {
		other = cur->next;
		free(cur);
		cur = other;
	}
	
	return 0;
}

int peek_left_value(struct node_t* node) {
	if (node == NULL || node->prev == NULL)
		return CELL_DEFAULT_VALUE;
	
	else
		return node->prev->value;
}

int peek_right_value(struct node_t* node) {
	if (node == NULL || node->next == NULL)
		return CELL_DEFAULT_VALUE;
	
	else
		return node->next->value;
}
