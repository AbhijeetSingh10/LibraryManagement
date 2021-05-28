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
    User user;
    int choice, firstTime;
    FILE *f;

    f = fopen("librarian.check","r");

    if(f == NULL){
        fclose(f);

        f = fopen("librarian.check","w");

        fputc(1,f);

        fclose(f);

    }
    else{
        fclose(f);
    }

    f = fopen("id.check","r");
 
    if(f == NULL){
        fclose(f);

        f= fopen("id.check","w");
        fputc(0,f);
        fclose(f);

    }
    else{
        fclose(f);
    }

    printf("Login as a : \n");
    printf("1. Librarian\n");
    printf("2. Student\n");
    printf("3. exit\n");

    printf("Enter the number\n");

    scanf("%d",&choice);
    printf("You Chose: %d", choice);

    switch(choice){
        case 1 : 
            f = fopen("librarian.check","r");

            if(f == NULL)
            {
                printf("Something went wrong\n");
                exit(0);
            }
            else{
                firstTime = fgetc(f);
                fclose(f);

                if(firstTime == 1){
                    printf("\nRegister your Username and Password\n");
                    printf("Enter your Username (14 character)");
                    fgets(user.username,14, stdin);
                    printf("Enter your Password(14 character)");
                    fgets(user.password,14,stdin);

                    f = fopen("credential.bin","wb");
                    if (f == NULL)
                    {
                        printf("Something went wrong\n");
                        exit(0);
                    }
                    fwrite(&user, sizeof(User),1,f);
                    fclose(f);

                    f = fopen("librarian.check","w");
                    fputc(0,f);
                    fclose(f);
                    

                }
            }

            
                
        break;

        case 2:

        break;

        case 3: exit(0);  
        break;

    }

    printf("Success!!!!");
    printf("check");
}
