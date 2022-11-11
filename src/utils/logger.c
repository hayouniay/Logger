/*
 * logger.c
 *
 *  Created on: Nov 5, 2022
 *      Author: hayouniaymen
 */


#include <logger.h>

int g_log_lvl = 0;
int g_log_fd = 0;

int	logger_init(int level, char *log_file){
	int	ret;

	if ((ret = logger_init_open_file(log_file)) < 0)
		return (ret);
	g_log_lvl = LOG_OFF;
	if (level >= LOG_FATAL && level <= LOG_TRACE)
	{
		g_log_lvl = level;
		dprintf(g_log_fd, "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> NEW INSTANCE OF THE APPLICATION\n");
	}
	return (0);
}

int	logger_close(void){
	dprintf(g_log_fd, "END OF THE APPLICATION INSTANCE\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	return (close(g_log_fd));
}

void	logger_msg(int fd, char *file, int line, const char *fmt, ...){
	va_list	lst;
	char	*time;
	char	*out_info;
	char	*out_mesg;
	char 	*f = NULL;
	char 	*log_level = NULL;

	if (g_log_lvl < LOG_DEBUG)
		return ;

	switch (g_log_lvl) {
		case LOG_FATAL:
			log_level="FATAL";
			break;
		case LOG_ERROR:
			log_level="ERROR";
			break;
		case LOG_WARN:
			log_level="WARNING";
			break;
		case LOG_INFO:
			log_level="INFO";
			break;
		case LOG_DEBUG:
			log_level="DEBUG";
			break;
		case LOG_TRACE:
			log_level="TRACE";
			break;
		default:
			log_level="OFF";
			break;
	}

	if (strlen(file) >= 20)
	{
		f = strdup(file + (strlen(file) - 20));
		f[0] = '+';

	}
	else
		f = strdup(file);

	time = logger_get_time();
	asprintf(&out_info, "[%s] [%s] [%s: %3d]- ", \
			time, log_level, f, line);
	free(f);

	va_start(lst, fmt);
	vasprintf(&out_mesg, fmt, lst);
	va_end(lst);

	dprintf(fd, "%s%s\n", out_info, out_mesg);

	free(out_info);
	free(out_mesg);
	free(time);
}
