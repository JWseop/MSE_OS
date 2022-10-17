#ifndef __FUNC_H
#define __FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

int child_process(int x, int y, int interval);
void parent_process(int child_process_result);

int Input_Error_identifier(int argc, char* argv[]);
int Input_Error_identifier2(int value[]);
int pid_process(int pid, int value[]);

#endif /* __FUNC_H */
