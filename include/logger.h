#ifndef LOGGER_H_
#define LOGGER_H_

#include <timer.h>


# define LOG_OFF			0
# define LOG_FATAL		1
# define LOG_ERROR		2
# define LOG_WARN			3
# define LOG_INFO			4
# define LOG_DEBUG		5
# define LOG_TRACE		6

#define LOG_FILE_PATH "logs/output_logs.log"
/*
** Functions to use for display log messages.
*/

#define log(...)		\
	logger_msg(g_log_fd, __FILENAME__, __LINE__, __VA_ARGS__)


void	logger_msg(int fd, char *file, int line, const char *fmt, ...);
int	logger_init(int level, char *log_file);
int	logger_close(void);

#endif /* LOGGER_H_ */
