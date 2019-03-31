/*
=============Testing the generation of 'PsuedoWords'=============

A test means of producing semi pronouncable words.

generates a consonant/vowel/consonant/vowel/..etc character array
which doesn't always work. first test.

INPUTS: None
OUTPUTS: Randomly generated psuedo-word of length 4-7

=================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#include <sys/random.h>
#include <sys/errno.h>

#define true 1
#define false 0
#define bool int

const char consonants[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v',
                        'w','x','y','z'};
const char vowels[] = {'a','e','i','o','u'};

int get_seed(int size);

void main(){

    srand(get_seed(256));
    int length = rand() % 3 + 4;

    int val = length;
    char word[length];
    char new_word[length];
    int i = 0;

    while(((length--)) > 0 && i < val){
        srand(get_seed(256));    
        if(length % 2 != 0){
            word[i++] = consonants[(rand() % 21)];
            srand(get_seed(256));
            if(((double)rand()/RAND_MAX) > 0.5){
                srand(get_seed(256));
                word[i++] = consonants[rand()%21];
            }            
        }
        else{
            word[i++] = vowels[(rand() % 5)];               
        }
    }
    for(i=0;i<val;i++){
        printf("%c",word[i]);
    }
    printf("\n");
}

int get_seed(int size){
    int buf[256];
    int temp = getrandom(buf,256,GRND_NONBLOCK);    
    return buf[0];
}
