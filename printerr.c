#include "lib_funcs.h"

/*
 * printerr - print error
 */

void printerr(char *prgm, char *cmd_C, char *cmd, char *err, char *err1)
{
	write(STDERR_FILENO, prgm, _strlen(prgm));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd_C, _strlen(cmd_C));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, err ? err : "", err ? _strlen(err) : 0);
	write(STDERR_FILENO, err1 ? err1 : "", err1 ? _strlen(err1) : 0);
	write(STDERR_FILENO, "\n", 1);
}
