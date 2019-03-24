#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

//common text
#define usage "\n\tUSAGE: pwGen -l <integer length>\n"
#define error1 "Too many arguements provided. Exiting...\n"
#define MAX 40

//character list
const char list[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v',
                        'w','x','y','z','@','!','#','$','%','&','*','(',')','-','_','=','+','[',']','{','}','<','>','?',
                        '|','~','`'};

void main(int argc, char *argv[]){

    int i;
    int length,midpoint,rval,options;
    int l_flag = 0, unrecognized=0;

    if(argc > 3){
        printf(error1);
        return;
    }
    else{   
        //taken by example by Brian Kernighan from C programming second edition
        //use argc to determine argument processed, increment through each argument in argv[]
        while(--argc > 0 && (*++argv)[0] == '-'){
            while(options = *++argv[0]){
                switch (options)
                {
                    //room here for more flag options in the future
                    case 'l':
                        l_flag = 1;
                        length = atoi(argv[1]);
                        if(length > MAX){
                            printf("Defaulting to %d for length. you tried: %d\n",MAX,length);
                            length = MAX;
                        }
                        else if(length == 0){
                            printf("Invalid length entry, defaulting to length 12\n");
                            length = 12;
                        }
                        break;  
                    default:
                        printf("unrecognized option:> %c\n",options);
                        printf(usage);
                        unrecognized=1;
                        break;
                }
            };
        }
    }   
    if(unrecognized == 1){
        return;
    }
    else if(l_flag == 0){        
        length = 12;
    }

    //password generation
    char password[length];
    srand(time(NULL));

    if(length % 2 != 0){
        midpoint = length/2 + 1;
    }
    else
    {
        midpoint = length/2;
    }   

    for(i=0;i<midpoint;i++){

        password[i] = list[rand() % 48];
        password[length-i-1] = list[rand() % 48];

        if(isalpha(password[i]) || isalpha(password[length - i -1])){
            //whether alphabetical characters should be capitalized            
            rval = rand() % 10;
            if(rval>5){
                password[i] = toupper(password[i]);
            }
            rval = rand() % 10;
            if(rval > 5){
                password[length - i - 1] = toupper(password[length - i - 1]);
            }
        }
    }

    for(i=0;i<length;i++){
        printf("%c",password[i]);
    }
    printf("\n");
    return;
}