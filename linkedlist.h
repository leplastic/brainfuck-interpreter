#ifndef LINKEKLIST_H
#define LINKEKLIST_H

#define CELL_DEFAULT_VALUE 0

/**
 * Prototype for node_t structure
 */
struct node_t;

/**
 * Representation of individual memory cells
 */
struct node_t {
	struct node_t *next;
	struct node_t *prev;
	int value;
};

/**
 * Creates the first node
 * @return First node for use in set
 */
struct node_t* create_first_node();

/**
 * Creates a new node, given the left
 * and the right nodes (they can be NULL
 * if not avaliable) and the cell value
 */
struct node_t* create_new_node(struct node_t* left, struct node_t* right, int value);

/**
 * Change the current node to the left node
 * (it's created if it not exists)
 */
void move_left(struct node_t** cur);

/**
 * Change the current node to the right node
 * (it's created if it not exists)
 */
void move_right(struct node_t** cur);

/**
 * Subtract the value for a given cell by one
 */
void decrement_value(struct node_t* node);

/**
 * Add the value for a given cell by one
 */
void increment_value(struct node_t* node);

/**
 * Change a value for a given cell
 */
void change_value(struct node_t* node, int value);

/**
 * Gets the value for a given existing cell
 */
int get_value(struct node_t* cur);

/**
 * Return the value of the left cell without change the actual one
 * @return value to the left cell
 */
int peek_left_value(struct node_t* node);

/**
 * Return the value of the right cell without change the actual one
 * @return value to the right cell
 */
int peek_right_value(struct node_t* node);

/**
 * Destroy the node set by giving any node of it
 * The method follow the left and right nodes,
 * ensuring all set gets deleted
 */
int destroy_all_nodes(struct node_t* any_node);

#endif
