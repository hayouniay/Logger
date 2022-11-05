/*
 * timer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: hayouniaymen
 */

#ifndef INCLUDE_TIMER_H_
#define INCLUDE_TIMER_H_


# include <stdarg.h>
# define _GNU_SOURCE
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*
** Macro to get the basename of the __FILE__ macro.
*/

# define __FILENAME__	\
	(strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

/*
** Global variables, the file descriptor to write on, and the log level.
*/

extern int g_log_lvl, g_log_fd;

char	*logger_get_time(void);
int		logger_init_open_file(char *log_file);


#endif /* INCLUDE_TIMER_H_ */
