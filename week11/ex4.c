#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>


int main(){

    struct stat filestat;
    stat("./ex1.txt", &filestat);
    int fd_source = open("./ex1.txt", O_RDWR);
    int fd_dest = open("./ex1.memcpy.txt", O_RDWR | O_CREAT);
    system("chmod 644 ex1.memcpy.txt");
    ftruncate(fd_dest, filestat.st_size);
    char* fp_source = mmap(NULL, filestat.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd_source, 0);
    char* fp_dest = mmap(NULL, filestat.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd_dest, 0);
    memcpy(fp_dest, fp_source, filestat.st_size);
    return 0;
}
