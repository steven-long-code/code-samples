#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

int main()
{
    char message[]="This is a test\n";

    write(1, message, strlen(message));
    write(2, message, strlen(message));
    //read(0, message, 10);
    write(1, message, strlen(message));

    int fd;
    fd = open("test.txt", O_RDONLY);
    read(fd, message, 5);
    write(1, message, strlen(message));
    read(fd, message, 5);
    write(1, message, strlen(message));

    lseek(fd, 0, SEEK_SET);
    read(fd, message, 5);
    write(1, message, strlen(message));
    lseek(fd, 0, SEEK_SET);
    read(fd, message, 5);
    write(1, message, strlen(message));

    int fd2;
    lseek(fd, 0, SEEK_SET);
    fd2 = dup(fd);
    read(fd, message, 5);
    write(1, message, strlen(message));
    read(fd2, message, 5);
    write(1, message, strlen(message));


    fd = open("test_w.txt", O_WRONLY | O_CREAT );
    write(fd, message, strlen(message));

    // dup can be used to implement redirection
    // close 0 or 1, and dup the file, since newly created file descriptor is always the lowest available one.
}
