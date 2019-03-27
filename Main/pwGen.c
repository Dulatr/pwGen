#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

//common text
#define usage "\n\tUSAGE: pwGen -l <integer length>\n\t       pwGen -s -l <integer length>\n\t       pwGen -ls/sl <integer length>\n"
#define error1 "Too many arguements provided. Exiting...\n"
#define MAX 40

//character list
const char list[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v',
                        'w','x','y','z','@','!','#','$','%','&','*','(',')','-','_','=','+','[',']','{','}','<','>','?',
                        '|','~','`','0','1','2','3','4','5','6','7','8','9'};

int * is_sequential(char str[],int str_length);

void main(int argc, char *argv[]){

    int i;
    int length,midpoint,rval,options;
    int l_flag = 0,s_flag = 0, unrecognized=0;
    int * sequence;

    if(argc > 4){
        printf(error1);
        return;
    }
    else{   
        //taken by example by Brian Kernighan from C programming second edition
        //increment through each argument in argv[]
        while(--argc>0 && (*++argv)[0] == '-'){
            
            while(options = *++argv[0]){
                switch (options)
                {
                    //room here for more flag options in the future
                    case 'l':
                        l_flag = 1;
                        if(argc > 1){
                            length = atoi(argv[1]);
                        }
                        if(length > MAX){
                            printf("Defaulting to %d for length. you tried: %d\n",MAX,length);
                            length = MAX;
                        }
                        else if(length == 0){
                            printf("Invalid length entry, defaulting to length 12\n");
                            length = 12;
                        }
                        break;  
                    case 's':
                        s_flag = 1;
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

        password[i] = list[rand() % ((int)sizeof(list)/sizeof(list[0]))];
        password[length-i-1] = list[rand() % ((int)sizeof(list)/sizeof(list[0]))];

        //whether alphabetical characters should be capitalized
        if(isalpha(password[i]) || isalpha(password[length - i -1])){      
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
    //sequential flag    
    if(s_flag){
        while(s_flag){
            int fin_ctr = 0;   

            sequence = is_sequential(password,length); 

            for(int j =0;j<length;j++){
                if(sequence[j] == 1){
                    password[j] = list[rand() % ((int)sizeof(list)/sizeof(list[0]))];
                    fin_ctr++;        
                }
            }
            if(fin_ctr == 0){
                s_flag = 0;
            }          
        }
        free(sequence);         
    }
    //display password
    for(i=0;i<length;i++){
        printf("%c",password[i]);
    }    
    printf("\n");
    return;
}

/*  scans a character string of known length,
    returns the indices of the repeated sequential characters
    maximum indices length is if every character in password is the same.
    
    If a character that follows immediately after previous adjacent character repeats,
    this function will return a 1 at that index.*/
int * is_sequential(char str[],int str_length){
    int i,j=0;
    int * indices = malloc(sizeof(int) * str_length);

    for(i=0;i<str_length;i++){
        if(str[i] == str[i+1]){
            indices[i]=1;
            j++;
        }
        else
        {
            indices[i] = 0;
        }       
    }
    
    return indices;
}
