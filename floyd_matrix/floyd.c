#include "../common/floyd.h"

//Calculate the matrix multiplication, sum is min and multiplication is sum.
void mul(int arc1[MAX_VEX][MAX_VEX], int arc2[MAX_VEX][MAX_VEX], int vex)
{
    int tmp[MAX_VEX][MAX_VEX];
    int i, j, k;
    for (i = 0; i < vex; i++)
    {
        for (j = 0; j < vex; j++)
        {
            tmp[i][j] = arc1[i][j];
        }
    }
    for (i = 0; i < vex; i++)
    {
        for (j = 0; j < vex; j++)
        {
            for (k = 0; k < vex; k++)
            {
                if(tmp[i][k] != MAX && arc2[k][j] != MAX)
                    arc1[i][j] = MIN(arc1[i][j], tmp[i][k] + arc2[k][j]);
            }
        }
    }
    return ;
}
//Calculate the apsp
void Floyd(int arc[MAX_VEX][MAX_VEX], int vex)
{   
    int i, j, k;
    int G_base[MAX_VEX][MAX_VEX];
    for (i = 0; i < vex; i++)
    {
        for (j = 0; j < vex; j++)
        {
            G_base[i][j] = arc[i][j];
        }
    }
    for (k = 0; k < vex-1; k++)
        mul(arc, G_base, vex);
}
