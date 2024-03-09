#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdalign.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>
#include <memory.h>
#include <assert.h>
#include <ctype.h>
#include <float.h>
#include <limits.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_SIZE 1024

typedef char* string;

void *NullError(void *x, const char *msg) {
    if (x == NULL)
    {
        perror(msg);
        exit(1);
    }
}
void *NotError(void *x, const char *msg) {
    if (!x) {
        perror(msg);
        exit(1);
    }
}