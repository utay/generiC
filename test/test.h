#ifndef TEST_H_
#define TEST_H_

#define PASS 0
#define SKIP 77
#define ERROR 99
#define FAIL 1

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void gc_assert(bool expression, char* buff);
char *gc_msg(char *format, ...);
void gc_set_status(int s);
void gc_set_exit_on_failure(bool exit);
int gc_get_status();

#endif /* TEST_H_ */
