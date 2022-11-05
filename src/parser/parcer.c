/*
 * logger.h
 *
 *  Created on: Nov 1, 2022
 *      Author: hayouniaymen
 */

#include <parser.h>

struct config_struct config;

int read_int_from_config_line(char* config_line) {
    char prm_name[MAX_CONFIG_VARIABLE_LEN];
    int val;
    sscanf(config_line, "%s %d\n", prm_name, &val);
    return val;
}
void read_double_from_config_line(char* config_line, double* val) {
    char prm_name[MAX_CONFIG_VARIABLE_LEN];
    sscanf(config_line, "%s %lf\n", prm_name, val);
}
void read_str_from_config_line(char* config_line, char* val) {
    char prm_name[MAX_CONFIG_VARIABLE_LEN];
    sscanf(config_line, "%s %s\n", prm_name, val);
}


void read_config_file(char* config_filename, struct config_struct config) {
    FILE *fp;
    char buf[CONFIG_LINE_BUFFER_SIZE];

    if ((fp=fopen(config_filename, "r")) == NULL) {
        fprintf(stderr, "Failed to open config file %s", config_filename);
        exit(EXIT_FAILURE);
    }
    while(! feof(fp)) {
        fgets(buf, CONFIG_LINE_BUFFER_SIZE, fp);
        if (buf[0] == '#' || strlen(buf) < 4) {
            continue;
        }
        if (strstr(buf, "TBPL ")) {
            config.bytes_per_line = read_int_from_config_line(buf);
        }
        if (strstr(buf, "NUMIN ")) {
            read_double_from_config_line(buf, &config.numin);
        }
        if (strstr(buf, "NUMAX ")) {
            read_double_from_config_line(buf, &config.numax);
        }
        if (strstr(buf, "LLIST_NAME ")) {
            read_str_from_config_line(buf, config.llist_name);
        }
    }
    printf("TBPL = %d\n", config.bytes_per_line);
    printf("NUMIN = %f\nNUMAX = %f\n", config.numin, config.numax);
    printf("LLIST_NAME = %s\n", config.llist_name);
}
