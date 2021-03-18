#include <stdio.h>
#include <string.h>

char backward[5][20];
char forward[5][20];
int topb = -1;
int topf = -1;

void pushf(char e[20])
{
    topf++;
    strcpy(forward[topf], e);
}
void pushb(char e[20])
{
    topb++;
    strcpy(backward[topb], e);
}

void popf()
{
    topf--;
}
void popb()
{
    topb--;
}
void pb()
{
    int i = 0;
    printf("\nBackward: ");
    if (topb >= 0)
    {

        for (i = topb; i > 0; i--)
            printf("%s->", backward[i]);
        printf("%s", backward[0]);
    }
}
void pf()
{
    int i = 0;
    printf("\nForward: ");
    if (topf >= 0)
    {

        for (i = topf; i > 0; i--)
            printf("%s->", forward[i]);
        printf("%s", forward[0]);
    }
}

int main()
{
    char choice = 'f';

    char cont = 'y';
    while (cont == 'y')
    {
        // printf("Enter choice: ");
        printf("(<--|-->)\n");
        scanf(" %c", &choice);
        if (choice == 'f')
        {
            if (topf < 0 && topb < 10)
            {
                printf("Nothing forward!\nEnter link: ");
                char l[20];
                scanf(" %s", &l);
                pushb(l);
                printf("\nGoing forward to...%s\n", l);
                printf("\ntopb=%d topf=%d\n", topb, topf);
                pb();
                pf();
            }
            else if (topf >= 0 && topb < 10)
            {
                printf("Going forward to...");
                printf("%s\n", forward[topf]);
                pushb(forward[topf]);
                popf();
                printf("from %s\n", backward[topb - 1]);
                pb();
                pf();
                printf("\n");
                printf("\ntopb=%d topf=%d", topb, topf);
            }
        }
        else if (choice == 'b')
        {
            if (topb < 0)
            {
                printf("Nothing backward!!\n");
            }
            else
            {
                printf("\nGoing back to...");
                printf("%s\n", backward[topb - 1]);
                pushf(backward[topb]);
                popb();
                printf("from %s\n", forward[topf]);
                pb();
                pf();
                printf("\n");
            }
        }
        printf("\nContinue? ");
        scanf(" %c", &cont);
    }

    pb();
    pf();
    return 0;
}
