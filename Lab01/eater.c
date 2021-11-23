#include <stdio.h>

int main()
{
    int plate, x=3, y=3, z=2;
    char status1='y', status2='y';
    scanf("%d%d%d", &x, &y, &z);
    scanf(" %c %c", &status1, &status2);
    plate = x;
    if (status1 == 'Y' || status1 == 'y')
        plate += y;
    if (status2 == 'Y' || status2 == 'y')
        if (plate % z == 0)
            plate = plate / z;
        else
            plate = plate / z + 1;
    printf("%d", plate);
}