/*
 * timer.c
 *
 *  Created on: Nov 5, 2022
 *      Author: hayouniaymen
 */

#include <timer.h>

char	*logger_get_time(void){
	time_t		tm;
	char		*buf;
	struct tm	*tm_info;

	if (!(buf = (char *)malloc(sizeof(char) * 9)))
		return (NULL);
	tm = time(NULL);
	tm_info = localtime(&tm);
	strftime(buf, 9, "%H:%M:%S", tm_info);
	return (buf);
}

int	logger_init_open_file(char *log_file){
	if (log_file == NULL)
		g_log_fd = -1;
	g_log_fd = open(log_file, O_WRONLY | O_APPEND | O_CREAT, 0755);
	return (g_log_fd);
}
