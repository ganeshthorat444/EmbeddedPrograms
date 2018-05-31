#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x1234

typedef struct shm
{
	int Count;
}shm_t;


int main()
{
        int i, ret, shmid;
        shm_t *ptr;
        // shm created by process A; so do not create again.
        shmid = shmget(SHM_KEY, sizeof(shm_t), 0);
        if(shmid < 0)
        {
                perror("shmget() failed");
                _exit(1);
        }

        // get pointer to the shm rgn
        ptr = (shm_t*) shmat(shmid, NULL, 0);
        if(ptr == (void*)-1)
        {
                perror("shmat() failed");
                _exit(2);
        }

        for(i=0; i<100; i++)
        {
                printf("process B : %d\n", --ptr->Count);
                sleep(1);
        }

        shmdt(ptr);

        return 0;
}

