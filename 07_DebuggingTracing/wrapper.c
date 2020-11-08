#define _GNU_SOURCE

#include <dlfcn.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

typedef int (*orig_unlinkat_f_type)(int, const char*, int);

int unlinkat(int fd, const char *pathname, int flag) {
    if (strstr(pathname, "FIX") != NULL) {
        return EPERM;
    }
    orig_unlinkat_f_type orig_unlink = (orig_unlinkat_f_type)dlsym(RTLD_NEXT, "unlinkat");
    return orig_unlink(fd, pathname, flag);
}
