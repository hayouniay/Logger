#ifndef LOGGER_H_
#define LOGGER_H_

#include <timer.h>


# define D_OFF			0
# define D_FATAL		1
# define D_ERROR		2
# define D_WARN			3
# define D_INFO			4
# define D_DEBUG		5
# define D_TRACE		6

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
