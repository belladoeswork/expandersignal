#include "lumumbash.h"

int ft_safe_dup2(int oldfd, int newfd) {
    if (dup2(oldfd, newfd) == -1) {
        perror("dup2");
        exit(EXIT_FAILURE);
    }
    return newfd;
}

int ft_safe_close(int fd) {
    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
    return fd;
}

// int ft_safe_open(const char *pathname, int flags) {
//     int fd = open(pathname, flags);
//     if (fd == -1) {
//         perror("open");
//         exit(EXIT_FAILURE);
//     }
//     return fd;
// }
int ft_safe_open(const char *pathname, int flags, mode_t mode) {
    int fd = open(pathname, flags, mode);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    return fd;
}
