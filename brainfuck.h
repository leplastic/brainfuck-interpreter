#ifndef BRAINFUCK_H
#define BRAINFUCK_H

#define MAX_LINE_SIZE 1024

/**
 * Options to brainfuck application
 */
struct settings_t {
	int safe_mode;
	char* filename;
	char* input;
	int stats;
};

/**
 * Shows the command line parameters accepted by 
 * the program and the current version
 */
void show_help();

/**
 * Interprets the code
 * @param[code] brainfuck code to be interpreted
 */
void interpret(char* code);

/**
 * Run a debugging session on the current code
 * It's intented to be interactive
 */
void run_debugger();

/**
 * Runs the code inside a loop
 * @param[code] the code following the '[' character
 * @returns relative position where the loop ends
 * @remarks Uses dynamic memory that must be freed later
 */
int start_loop_code(char* code);

/**
 * Checks if the loop brackets are balanced
 * @param[code] the code to be checked
 * @returns false(0) if there's something wrong, 1 otherwise.
 */
int safemode_check(char* code);

/**
 * Gets the input from the command line arguments or standard input
 * @returns read char (from input flag or stdin)
 */
char get_input();

#endif
