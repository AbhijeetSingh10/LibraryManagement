#include<stdio.h>
#include<Stdlib.h>

typedef struct
{
    char username[15];
    char password[15];
} User;

typedef struct
{
    int id;
    char title[50];
    char author[50];
    char category[50];
    char publicaton[50];
    char description[500];
    int taken;

} Book;

int main()
{
    FILE *f;

    f = fopen("library.check","r");

    if(f == NULL){
        fclose(f);

        f = fopen("library.check","w");

        fputc(1,f);

        fclose(f);

    }
    else{
        fclose(f);
    }



}
