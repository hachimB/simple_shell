#include "lib_funcs.h"

/*
 * printerr - print error 
 */

void printerr(char *prgm, char* cmd_C, char *cmd)
{
    write(STDERR_FILENO, prgm, _strlen(prgm));
    write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd_C, _strlen(cmd_C));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);
}