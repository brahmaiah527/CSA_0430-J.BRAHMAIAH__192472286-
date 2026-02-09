#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int src, dest;
    char buf[50];
    int n;

    // Create source file and write data into it
    src = open("source.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(src, "Hello OS Lab!\nFile Copy using system calls.", 43);
    close(src);

    // Open source file for reading and destination for writing
    src = open("source.txt", O_RDONLY);
    dest = open("dest.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    // Copy data
    while ((n = read(src, buf, sizeof(buf))) > 0)
        write(dest, buf, n);

    close(src);
    close(dest);
    return 0;
}

