#include "../common/floyd.h"

//constructor 
void Graph(int vex, int edge, graph_t* graph)
{
	graph->vex = vex;
	graph->edge = edge;
    for (int i = 0; i < vex; i++) {
        for (int k = 0; k < vex; k++) {
            //initiate all value in adjacency matrx infinite
            graph->arc[i][k] = MAX;
        }
    }
}
// Determine if our input.data edge value is valid.
// vertex index starts from 1
int check_edge_value(int start, int end, int weight, graph_t* graph)
{
    if (start<1 || end<1 || start>graph->vex || end>graph->vex || weight < 0) {
        return 0;
    }
    return 1;
}
// create graph
int createGraph(int kind, graph_t* graph)
{
    int start = 0;
    int end = 0;
    int weight = 0;
    int count = 0;
    // all the edge point to vertex itself is equal to 0
    for (int v = 0; v < graph->vex; v++){
        graph->arc[v][v] = 0;
    }
    while (count != graph->edge) {
        //check if the edge value is valid 
        start  = *(input_data + count * 3 + 0);
        end    = *(input_data + count * 3 + 1);
        weight = *(input_data + count * 3 + 2);

        if (!check_edge_value(start, end, weight, graph)) {
            printf("illegal, input again\n");
            return 1;
        }
        //assign value to the adjacency matrix 
        graph->arc[start - 1][end - 1] = weight;
        //if the graph is undirected 
        if (kind == 2)
            graph->arc[end - 1][start - 1] = weight;
        ++count;
    }
    return 0;
}
//print the adjacency matrix
void print(graph_t* graph)
{
    printf("adjacency matrix is :\n");
    int count_row = 0; //the index for the row 
    int count_col = 0; //the index for the column 
    while (count_row != graph->vex) {
        count_col = 0;
        while (count_col != graph->vex) {
            if (graph->arc[count_row][count_col] == MAX)
                printf("NaN\t");
            else
                printf("%d\t", graph->arc[count_row][count_col]);
            ++count_col;
        }
        printf("\n");
        ++count_row;
    }
}
//print the adjacency matrix after FW
void print_arc(graph_t* graph)
{
    printf("adjacency matrix after FW is :\n");
    int count_row = 0; //the index for the row 
    int count_col = 0; //the index for the column 
    while (count_row != graph->vex) {
        count_col = 0;
        while (count_col != graph->vex) {
            if (graph->arc[count_row][count_col] == MAX)
                printf("NaN\t");
            else
                printf("%d\t", graph->arc[count_row][count_col]);
            ++count_col;
        }
        printf("\n");
        ++count_row;
    }
}

void output_check(graph_t* graph)
{
    freopen("check.data", "r", stdin);
    int _n = graph->vex;
    int flag = 1;
    for(int i = 0; i < _n; i++)
        for(int j = 0; j < _n; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            if(tmp != graph->arc[i][j])
                flag = 0;
        }
    if(flag)
        printf("Success!");
    else
        printf("Not correct");
}
