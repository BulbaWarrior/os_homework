#include <stdio.h>
#include <dirent.h>

int in(int n, int* a){
    for(int i = 0; i < 256; i++){
        if(a[i] == n){
            return 1;
        }
    }
    return 0;
}

void add(int n, int* a){
    for(int i = 0; i < 256; i++){
        if(a[i] == -1){
            a[i] = n;
            return;
        }
    }
}

int main(int argc, char** argv){
    char path[256] = "~/OS/week10/tmp/";
    DIR* dirp = opendir(path);
    struct dirent* entry;
    int inodes[256];
    int count = 0;
    for(int i = 0; i < 256; i++){
        inodes[i] = -1;
    }
    while(entry = readdir(dirp) != NULL){
        int inode = entry->d_ino;
        if(entry->d_ino >= 2 && !in(entry->dino, inodes)){

        }
        strcpy(name, path);
        strcat(name, entry->d_name);
        struct stat* statbuf = malloc(sizeof(struct stat));
        stat(name, statbuf);
        if(!in(statbuf->st_ino, inodes) && statbuf->st_nlink >= 2){
            add(statbuf->st_ino, inodes);
            find_links(statbuf->st_ino);
        }
    }

    return 0;
}
