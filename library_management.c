#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

typedef struct
{
    char username[15];
    char password[15];
} User;

typedef struct
{
    int id;
    int taken;
    char title[50];
    char author[50];
    char category[50];
    char publicaton[50];
    char description[500];

} Book;

int main()
{
    char username[15], password[15];
    User user;
    Book book;
    int choice, option, firstTime, id;
    FILE *f;

    f = fopen("librarian.check", "r");

    if (f == NULL)
    {
        fclose(f);

        f = fopen("librarian.check", "w");

        fputc(1, f);

        fclose(f);
    }
    else
    {
        fclose(f);
    }

    f = fopen("id.check", "r");

    if (f == NULL)
    {
        fclose(f);

        f = fopen("id.check", "w");
        fputc(0, f);
        fclose(f);
    }
    else
    {
        fclose(f);
    }

    printf("Login as : \n");
    printf("1. Librarian\n");
    printf("2. Student\n");
    printf("3. exit\n");

    printf("Enter the number: \n");
    scanf("%d", &choice);

    printf("You Chose: %d \n", choice);

    switch (choice)
    {
    case 1:
        f = fopen("librarian.check", "r");

        if (f == NULL)
        {
            printf("Something went wrong\n");
            exit(0);
        }
        else
        {
            firstTime = fgetc(f);
            fclose(f);

            if (firstTime == 1)
            {
                printf("\nRegister your Username and Password\n");
                printf("Enter your Username (14 character)\n");
                scanf("%s", &user.username);
                printf("Entered value is %s\n", &user.username);
                printf("Enter your Password(14 character)\n");
                scanf("%s", &user.password);
                printf("Entered value is %s\n", &user.password);

                f = fopen("credential.bin", "wb");
                if (f == NULL)
                {
                    printf("Something went wrong\n");
                    exit(0);
                }
                fwrite(&user, sizeof(User), 1, f);
                fclose(f);

                f = fopen("librarian.check", "w");
                fputc(0, f);
                fclose(f);
            }
            else
            {
                printf("Enter your Credentials to login...\n");
                printf("Enter your Username: \n");
                scanf("%s", &username);

                printf("Enter your Password: \n");
                scanf("%s", &password);

                f = fopen("credential.bin", "rb");

                if (f == NULL)
                {
                    printf("Something went wrong!");
                    exit(0);
                }
                else
                {
                    fread(&user, sizeof(User), 1, f);

                    if (strcmp(username, user.username) != 0 || strcmp(password, user.password) != 0)
                    {
                        printf("Invalid username or password!\n");
                        exit(0);
                    }
                    fclose(f);

                    printf("Logged in Successfully.\n");

                    printf("1. Add Book\n");
                    printf("2. Search Book\n");
                    printf("3. Update Book\n");
                    printf("4. Delete Book\n");
                    printf("4. Monitor Student request\n");
                    printf("Choose option Option\n");
                    scanf("%d", &option);
                    printf("You chose : %d\n");

                    switch (option)
                    {
                    case 1:
                        flush();
                        printf("Provide book info\n");
                        printf("Author: \n");
                        fgets(book.author, 50, stdin);
                        printf("Title: \n");
                        fgets(book.title, 50, stdin);
                        printf("Category: \n");
                        fgets(book.category, 50, stdin);
                        printf("Publicaion: \n");
                        fgets(book.publicaton, 50, stdin);
                        printf("Description: \n");
                        fgets(book.description, 500, stdin);
                        book.taken = 0;

                        f = fopen("id.check", "r");

                        if (f == NULL)
                        {
                            printf("Something went wrong!!!");
                            exit(0);
                        }
                        id = fgetc(f);
                        book.id = id;
                        id++;
                        fclose(f);

                        f = fopen("id.check", "w");
                        fputc(id, f);
                        fclose(f);

                        break;

                    default:
                        break;
                    }
                }
            }
        }

        break;

    case 2:

        break;

    case 3:
        exit(0);
        break;

    default:
        printf("Invalid Number\n");
        break;
    }

    int clrscr();

    printf("Success!!!!");
    printf("check");
}
