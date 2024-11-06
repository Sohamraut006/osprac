/Client/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXSIZE 27

// Error handling function
void die(char *s) {
    perror(s);
    exit(1);
}

int main() {
    int shmid;
    key_t key;
    char *shm, *s;

    // Assign a key for shared memory
    key = 5678;

    // Locate the shared memory segment created by the server
    if ((shmid = shmget(key, MAXSIZE, 0666)) < 0) {
        die("shmget");
    }

    // Attach the shared memory segment to the process's address space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        die("shmat");
    }

    // Now read what the server put in the memory
    for (s = shm; *s != '\0'; s++) {
        putchar(*s);
    }
    putchar('\n');

    // Mark the first character of the shared memory segment with '*'
    *shm = '*';

    exit(0);
}




