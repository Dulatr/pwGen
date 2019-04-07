#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/random.h>


uint16_t Twist(uint16_t seed);
uint16_t * Seed_list(uint16_t constant);

void main(){
    uint16_t * seed_list;
    seed_list = Seed_list(32768u);
    for(int i = 0;i<256;i++){
        printf("%9.0d, %9.0d\n",seed_list[i],Twist(seed_list[i]));
    }
}

uint16_t Twist(uint16_t seed){
    uint16_t z,x,y;
    
    y=seed^(x>>11);
    y=y^((y<<3)& 0x5680);
    y=y^((y<<7)&0xEFC6);
    z=y^(y>>9);
}

uint16_t * Seed_list(uint16_t constant){
    uint16_t ran_values[256];
    uint16_t * returns = malloc(4 * 256);
    uint16_t temp;

    int result = getrandom(ran_values,256,GRND_NONBLOCK);
    
    for(int i = 255;i>=0;i--){
        temp = ran_values[i-1];
        returns[i]=16*(temp^(temp >> (16-2)))+i;
    }

    return returns;
}   