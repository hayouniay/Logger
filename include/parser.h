/*
 * parser.h
 *
 *  Created on: Nov 5, 2022
 *      Author: hayouniaymen
 */

#ifndef INCLUDE_PARSER_H_
#define INCLUDE_PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_CONFIG_VARIABLE_LEN 20
#define CONFIG_LINE_BUFFER_SIZE 100
#define MAX_LLIST_NAME_LEN 256
#define MAX_OUT_NAME_LEN 256

struct config_struct {
    int bytes_per_line;
    char llist_name[MAX_LLIST_NAME_LEN];
    double numin, numax;
};

int read_int_from_config_line(char* config_line);
void read_double_from_config_line(char* config_line, double* val);
void read_str_from_config_line(char* config_line, char* val);
void read_config_file(char* config_filename, struct config_struct config);




#endif /* INCLUDE_PARSER_H_ */
