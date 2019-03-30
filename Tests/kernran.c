/*
=============Generating random numbers from kernel==============
Using the sys/random library to generate a more secure random 
generated integer.

getrandom() uses /dev/urandom in linux to read bytes into a 
buffer. the buffer can then be used as a seed for srand().
optimally you would generate a new seed for each call of random.

this is significantly better for any security need than using 
time.h as outputs are much less likely to repeat.

call this function multiple times to see the effects on seed and
rand() output. it seems that with lower buffer sizes read,
the byte range is significantly smaller. 
================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/random.h>
#include <sys/errno.h>

void main(){
    int buf[256];
    int result = getrandom(buf,256,GRND_NONBLOCK);
    if(result<0){
        printf("failed.\n");
        printf("Error thrown: %d\n",errno);
    }
    else
    {
        printf("number of bytes read: %d\n",result);
    }   
    //sum the buffer, does this compromise the randomness? or does it help prevent predictability?
    result = 0;
    for(int i =0;i<256;i++){
        result += buf[i];
    }

    srand(result);
    printf("%d %d\n",result,rand()%59);
}