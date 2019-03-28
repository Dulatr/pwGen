/*
=============Feature Test for Uniqueness=============

A means for determining whether a char[] contains any
repeats within the array.

INPUTS: Reads stdin for a char[].

OUTPUTS: -The string read from stdin.
         -characters that offend the uniqueness 
          criteria and their corresponding indexes 
          upon first occurance. 
         -Strength or entropy in bits for a string 
          provided. 

USE CASE: Typical use may be piping output from pwGen
          into unique() as in:
        
          ./pwGen <option> <integer value> | ./unique

=====================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define false 0
#define true 1
#define bool int

void main(){
    int length = 30;
    char temp[length];

    int result = scanf("%s",temp);
    if(result < 0){
        printf("Failed to read stdin, check formatting.\n");
        return;
    }

    printf("string read is: %s\n",temp);
    
    bool is_unique = true;

    int offense_counter = 0;
    
    //implementation
    int i = 0;
    int j = 0;

    for(i=0;i<length;i++){
        for(j=i+1;j<length;j++){
            if(temp[i]==temp[j]){
                is_unique = false;
                printf("offending characters: %c , %c\t found at positions: %d,%d\n",temp[i],temp[j],i,j);
                offense_counter++;
            }
        }
    }

    printf("is unique? %d\t offense counter: %d\n",is_unique,offense_counter);
    
    printf("strength of password? %f\n",log2(pow(85.,(double)length)));
}