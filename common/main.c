#include <stdio.h>
#include <stdlib.h>
#include "floyd.h"

int* input_data;
graph_t graph;

// check if the number of edges and vertex is valid
// directed graph Vex*(Vex - 1) >= edge
// undirected graph vex*(vex - 1)/2 >= edge
int check(int Vex, int edge, int kind) {
    if (Vex > 100 || Vex < 0) {
        return 0;
    }
    if (kind == 1){
        if (Vex <= 0 || edge <= 0 || Vex*(Vex - 1) < edge){
            return 0;
        }
    }
    if(kind == 2){
        if (Vex <= 0 || edge <= 0 || ((Vex*(Vex - 1)) / 2) < edge){
            return 0;
        }
    }
    return 1;
}

int main() {
    int data_cnt = 0, fscanf_res;
    int vex; int edge;
    int kind;
    FILE* fp_input = fopen("input.data", "r");

    if (fp_input  == NULL)
    {
        printf("illegal input data\n");
        return 1;
    }

    fscanf_res = fscanf(fp_input, "%d %d %d", &kind, &vex, &edge);
    data_cnt = edge * 3;
    input_data = malloc(sizeof(int) * data_cnt);
    for (int i = 0; i < data_cnt; i++)
    {
        fscanf_res = fscanf(fp_input, "%d ", input_data + i);
    }
    printf("\n");

    if (kind != 1 && kind != 2) {
        printf("illegal graph type\n");
        return 1;
    }
    if (!check(vex, edge, kind)) {
        printf("illegal, input again\n");
        return 1;
    }
    graph_t graph;
    Graph(vex, edge, &graph);
    if(createGraph(kind, &graph) != 0)
        return 1;
    print(&graph);
    Floyd(graph.arc, vex);
    print_arc(&graph);
    output_check(&graph);
    return 0;
}
