#include <stdio.h>
#include <fcntl.h>
#include <libgen.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>

#define RETURN_IF_ERROR(expr) \
    do { \
        int err = (expr); \
        if (err == -1) { \
            fprintf(stderr, "Error calling "  #expr " : %s\n", strerror(errno)); \
            return 1; \
        } \
    } while(0);

int main(int argc, char ** argv) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: %s FILEPATH\n", argv[0]);
        return 1;
    }

    char* filepath = argv[1];
    int fd = openat(AT_FDCWD, filepath, O_RDWR | O_CREAT | O_NOFOLLOW | O_CLOEXEC, 0644);

    struct flock flck = {
        .l_type = F_RDLCK,
        .l_whence = SEEK_SET,
        .l_start = 0,
        .l_len = 1,
    };
    RETURN_IF_ERROR(fcntl(fd, F_SETLK, &flck))
    printf("Success.\n");
    return 0;
}
