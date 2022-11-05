/*
 ============================================================================
 Name        : Logger.c
 Author      : hayouni aymen
 Version     :
 Copyright   : C@pyright reserved Aymen Hayouni
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <logger.h>
#include <parser.h>

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	// Initialize the logger (level and output file).

	if (logger_init(D_TRACE, LOG_FILE_PATH) != 0)
		printf("failed to open the logger\n");

	// Display log messages.

	for(int i=0;i<10;i++)
		log("%s", "debug message");

	// Close the logger.

	logger_close();
	return EXIT_SUCCESS;
}
