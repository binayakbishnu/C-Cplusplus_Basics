#include <stdio.h>

struct state
{
    char name[20];
    int engg, med, man, univ;
};

int main()
{
    int n = 0;
    scanf(" %d", &n);
    struct state list[n];
    int singletotal[n];
    int i = 0;
    int max = 0, x = 0;
    for (i = 0; i < n; i++)
    {
        singletotal[i] = 0;
        scanf(" %s", &list[i].name);

        scanf(" %d", &list[i].engg);
        singletotal[i] += list[i].engg;

        scanf(" %d", &list[i].med);
        singletotal[i] += list[i].med;

        scanf(" %d", &list[i].man);
        singletotal[i] += list[i].man;

        scanf(" %d", &list[i].univ);
        singletotal[i] += list[i].univ;

        if (max < singletotal[i])
        {
            max = singletotal[i];
            x = i;
        }
    }
    printf("%s", list[x].name);

    return 0;
}