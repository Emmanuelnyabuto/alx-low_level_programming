#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int src_fd, dst_fd, read_size;
    char buffer[BUF_SIZE];

    if (argc != 3) {
        dprintf(2, "Usage: cp file_from file_to\n");
        exit(97);
    }

    src_fd = open(argv[1], O_RDONLY);
    if (src_fd < 0) {
        dprintf(2, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    dst_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (dst_fd < 0) {
        dprintf(2, "Error: Can't write to %s\n", argv[2]);
        close(src_fd);
        exit(99);
    }

    while ((read_size = read(src_fd, buffer, BUF_SIZE)) > 0) {
        if (write(dst_fd, buffer, read_size) != read_size) {
            dprintf(2, "Error: Can't write to %s\n", argv[2]);
            close(src_fd);
            close(dst_fd);
            exit(99);
        }
    }

    if (close(dst_fd) < 0) {
        dprintf(2, "Error: Can't close fd %d\n", dst_fd);
        exit(100);
    }

    if (close(src_fd) < 0) {
        dprintf(2, "Error: Can't close fd %d\n", src_fd);
        exit(100);
    }

    return 0;
}
