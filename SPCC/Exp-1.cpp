
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define deb() printf("h-");
char pre[2][10];
int prep=-1;
int arr[200];

char header[10][20];
int headp =-1;

char keyword[10][10]= { 
        "for", 
        "return", 
        "int", 
        "char", 
        "void", 
        "break",
        "if",
        "else",
        "while",
        "do"
    }; 
int repeat[10];

char identif[100][10];
int id=-1;

FILE *fptr; 

void preprocessor(char c){
    int i;
    char f;
    char buff[100];
    
    i=0;
    if(prep==-1){
        prep++;
        while(c!=' '&&c!='<'){
            if(i==1)
                f=c;
            pre[0][i++]=c;
            c=fgetc(fptr);
        }
        pre[0][i]='\0';
    }
    else{
        i=0;
        while(c!=' '&&c!='<'){
            if(i==1)
                f=c;
            buff[i++]=c;
            c=fgetc(fptr);
        }
        buff[i]='\0';
        for(i=0;i<2;++i){
            if(!strcmp(pre[i],buff)){
                //deb();
                break;
            }
        }
        if(i==2){
            prep++;
            strcpy(pre[prep],buff);
        }
    }
    
    if(f=='i'){
        headp++;
        while(c!='<'){
           c=fgetc(fptr);
        }
        c=fgetc(fptr);
        i=0;
        while(c!='>'){
            header[headp][i++]=c;
            c=fgetc(fptr);
        }
        header[headp][i]='\0';
    }
}

int main()
{
    int i,flag=0;
    char c,buff[100];
    int bp=0;
    fptr = fopen("abc.txt", "r"); 
    if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    }
    c = fgetc(fptr); 
    while (c != EOF) 
    { 
        if(c=='#'){
            preprocessor(c);
        }
        if(c=='\"'){
            c = fgetc(fptr); 
            while(c!='\"'){
                c = fgetc(fptr); 
            }
            c = fgetc(fptr); 
        }
        
        if(c=='{'||c=='@'||c=='#'||c=='}'||c==')'||c=='['||c==']'||c=='\\'||c=='('||c=='\''||
        c==';'||c=='/'||c=='_'){
            if(!arr[c])
                printf("\nSymbol Found: %c",c);
            arr[c]=1;
        }
        if(c=='!'||c=='%'||c=='^'||c=='&'||c=='*'||c=='+'||c=='-'||c=='='||c=='/'||c==':'||c=='<'||c=='>'||c==','){
            printf("\nOperator Found: %c\n",c);
        }
        if(c>=48&&c<=57){
            printf("\n\nConstant found: ");
            while(1){
                if(c<=47||c>=58){
                    break;
                }
                printf("%c",c);
                c=fgetc(fptr);
            }
        }
        if(c!=' '&&c!='\n'){
            buff[bp++]=c;
        }
        
        else if(c==' '||c=='\n'){
            buff[bp]='\0';
            for(i=0;i<10;++i){
                if(!strcmp(buff,keyword[i])&&!repeat[i]){
                    repeat[i]=1;
                    printf("\nKeyword %s found.",buff);
                    break;
                }
            }
            if(i!=10){
                if(id==-1){
                    id++;
                    strcpy(identif[0],buff);
                }
                else{
                    for(i=0;i<=id;++i){
                        if(!strcmp(identif[i],buff)){
                            break;
                        }
                    }
                    if(i==id+1){
                        id++;
                        strcpy(identif[0],buff);
                    }
                }
            }
            else{
                for(i=0;i<10;++i){
                    if(!strcmp(buff,keyword[i]))
                        break;
                }
                if(i==10&&((buff[0]>=65&&buff[0]<=90)||(buff[0]>=97&&buff[0]<=122))){
                    i=0;
                    printf("\nIdentifier Found: ");
                    while(i<bp&&((buff[i]>=65&&buff[i]<=90)||(buff[i]>=97&&buff[i]<=122)||(buff[i]>=48&&buff[i]<=57))){
                        printf("%c",buff[i]);
                        i++;
                    }
                }
            }
            bp=0;
        }
        
        
        
        c = fgetc(fptr);
    } 
    printf("\n");
    if(prep!=-1){
        printf("\nPreprocessor Directives are:\n");
        for(i=0;i<=prep;++i){
            printf("%d.] %s\n",i+1,pre[i]);
        }
    }
    if(headp!=-1){
        printf("\nHeader Files are:\n");
        for(i=0;i<=headp;++i){
            printf("%d.] %s\n",i+1,header[i]);
        }
    }
    fclose(fptr); 
    return 0; 
}





ABC.txt

#include <stdio.h>
#define b 100

int main(){
    int a;
    a=10;
    printf("Value of a is %d",a);
    getch();
    return 0;
}

/*OUTPUT

                                                                                                                                               
Symbol Found: #                                                                                                                                  
                                                                                                                                                 
Constant found: 100                                                                                                                              
Keyword int found.                                                                                                                               
Symbol Found: (                                                                                                                                  
Symbol Found: )                                                                                                                                  
Symbol Found: {                                                                                                                                  
Identifier Found: main                                                                                                                           
Symbol Found: ;                                                                                                                                  
Identifier Found: a                                                                                                                              
Operator Found: =                                                                                                                                
                                                                                                                                                 
                                                                                                                                                 
Constant found: 10                                                                                                                               
Identifier Found: a                                                                                                                              
Operator Found: ,                                                                                                                                
                                                                                                                                                 
Identifier Found: printf                                                                                                                         
Identifier Found: getch                                                                                                                          
Keyword return found.                                                                                                                            
                                                                                                                                                 
Constant found: 0                                                                                                                                
Symbol Found: }                                                                                                                                  
                                                                                                                                                 
Preprocessor Directives are:                                                                                                                     
1.] #include                                                                                                                                     
2.] #define                                                                                                                                      
                                                                                                                                                 
Header Files are:                                                                                                                                
1.] stdio.h   */
