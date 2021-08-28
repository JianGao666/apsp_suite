#include "../common/floyd.h"

//Calculate the apsp
void Floyd(int arc[MAX_VEX][MAX_VEX], int vex)
{
    int row = 0;
    int col = 0;
    //Floyd warshall algorithm
    int temp = 0;
    int select = 0;
    for (temp = 0; temp < vex; temp++) {
        for (row = 0; row < vex; row++) {
            for (col = 0; col < vex; col++) {
                // we need select to avoid overflow
                select = (arc[row][temp] == MAX || arc[temp][col] == MAX) ?
                    MAX : (arc[row][temp] + arc[temp][col]);
                if (arc[row][col] > select) {
                    //update dis matrix
                    arc[row][col] = select;
                }
            }
        }
    }
}