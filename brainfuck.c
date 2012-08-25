#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "brainfuck.h"
#include "linkedlist.h"

#define APP_VERSION "0.1"

struct node_t* current;
struct settings_t pref;

int main(int argc, char** argv) {

	// get command line args
	char* app_name = *argv;
	pref.safe_mode = 0;
	pref.stats = 0;

	while (*++argv != NULL) {
		if (strcmp("--help",*argv) == 0 || strcmp("-h", *argv) == 0) {
			show_help(app_name);
			exit(1);

		} else if (strcmp("-f", *argv) == 0) {
			pref.filename = *++argv;
			
		} else if (strcmp("--safemode", *argv) == 0) {
			pref.safe_mode = 1;

		} else if (strcmp("--input", *argv) == 0 || strcmp("-i", *argv) == 0) {
			pref.input = *++argv;

		} else if (strcmp("--stats", *argv) == 0) {
			pref.stats = 1;

		} else {
			show_help(app_name);
			exit(1);
		}
	}
	
	FILE* file;
	
	if (pref.filename == NULL) {
		file = stdin;
		printf("Waiting code from stdin:\n");

	} else {
		file = fopen(pref.filename, "r");
		
		if (file == NULL) {
			perror("Incorrect filename");
			exit(1);
		}
	}
	
	char buffer[MAX_LINE_SIZE];
	int code_pointer = 0;
	char* code = (char*) malloc(sizeof(char) * MAX_LINE_SIZE);
	
	if (code == NULL) {
		printf("Error initializing code buffer\n");
		exit(1);
	}
	
	while (fgets(buffer, MAX_LINE_SIZE, file) != NULL) {
		memcpy(code + code_pointer, buffer, MAX_LINE_SIZE);
		code_pointer += strlen(buffer); 
		code = realloc(code, code_pointer + MAX_LINE_SIZE);
	}
	
	fclose(file);

	if (pref.safe_mode == 1 && safemode_check(code) != 1) {
		printf("The brackets are not balanced. Due safemode, the code will not be executed.\n");
		free(code);
		exit(1);
	}
		
	// interpret the code
	current = create_first_node();
	interpret(code);
	
	// cleanup all memory previously used
	destroy_all_nodes(current);
	free(code);
	
	return 0;
}

void interpret(char* code) {
	char c;
	while ((c = *code++) != '\0') {
	
		switch (c) {
			case '+':
				increment_value(current);
				break;
				
			case '-':
				decrement_value(current);
				break;
				
			case '>':
				move_right(&current);
				break;
				
			case '<':
				move_left(&current);
				break;
				
			case '.':
				printf("%c", get_value(current));
				break;
				
			case '[':
				// the [ symbol is already out of the code
				// so we can pass it safely
				code += start_loop_code(code);
				break;
				
			case ']':
				// beautiful case! does nothing
				break;
			
			case ',':
				change_value(current, get_input());
				break;
		}
	
	}
}


int start_loop_code(char* code) {
	int code_size = sizeof(char) * strlen(code);
	char* loop_code = (char*) malloc(code_size);
	int bracket_level = 1;
	int found = 0;
	int pos = 0;

	if (loop_code == NULL) {
		printf("start_loop_code: cannot initialize loop_code");
		exit(1);
	}

	bzero(loop_code, code_size);

	while (found == 0 && *code != '\0') {
		if (*code == '[') {
			bracket_level++;

		} else if (*code == ']') {
			bracket_level--;

			if (bracket_level == 0)
				found = 1;
		}

		*(loop_code + pos)  = *code++;
		pos++;
	}

	while (get_value(current) != 0) {
		interpret(loop_code);
	}

	free(loop_code);

	return pos;
}

int safemode_check(char* code) {
	int stack_size = 100;
	char* stack = (char*) malloc(sizeof(char) * stack_size);
	
	if (stack == NULL) {
		printf("safemode_check: stack not initialized!");
		exit(1);
	}
	
	int pos = 0;
	char c;
	while ((c = *code++) != '\0') {
	
		switch (c) {
		
			case '[':
				stack[pos++] = '[';
				break;
			
			case ']':
				if (pos == 0 || stack[pos - 1] != '[') {
					free(stack);
					return 0;
					
				} else {
					stack[--pos] = ' ';
					
				}
				break;
		}
		
		if ((pos - 1) >= stack_size) {
			stack_size = stack_size << 2;
			stack = realloc(stack, sizeof(char) * stack_size);
			
			if (stack == NULL) {
				printf("safemode_check: impossible to adjust stack size");
			}
		}
	}
	
	free(stack);

	return (pos == 0) ? 1 : 0;
}

char get_input() {
	if (pref.input == NULL || pref.input == '\0')
		return getchar();
	
	// print to screen the used character
	printf("%c", *pref.input);
	return *(pref.input++);
}

void show_help(char* app) {
	printf("%s version %s\n\n", app, APP_VERSION);
	printf("Usage:\n");
	printf("\t%s [-f file] [-i|--input ...] [--safemode]\n\n", app);
	printf("\t* If no file is specified, it reads from standard input\n");
	printf("\t* The -i flag allows you to pass arguments to the program\n");
	printf("\t* Safe mode checks if loop brackets are balanced (disabled by default)\n");
	printf("\n");
}
