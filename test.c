#include "philosophers.h"

void *funct(void *t)
{
    int i = 1;
    while(i < 12)
    {
        printf("thread 1 : %d\n",i);
        i++; 
    }
    sleep(1);
}
int main(int ac, char **av)
{
    pthread_t p1;
    int i = 1;
    while(i < 7)
    {
        printf("thread 2 : %d\n",i);
        i++; 
    }
    sleep(2);
    pthread_create(&p1,NULL,funct,NULL);
}