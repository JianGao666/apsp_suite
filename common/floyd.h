#ifndef _FLOYF_H_
#define _FLOYF_H_
#include <stdio.h>
#include <stdlib.h>
#define MAX_VEX 100
#define MAX 0x7fffffff
#define MIN(A, B) (A < B ? A : B)

extern int* input_data;

typedef struct graph_t_struct
{
    int vex;     //vertex number 
    int edge;       //edge number 
    int arc[MAX_VEX][MAX_VEX];      //adjacency matrix value
} graph_t;


//constuctor
void Graph(int vex, int edge, graph_t* graph);
// Determine if our input.data edge value is valid.
//vertex index starts from 1
int check_edge_value(int start, int end, int weight, graph_t* graph);
// create graph
int createGraph(int kind, graph_t* graph);
// print adjacency matrix
void print(graph_t* graph);
// calculate apsp
void Floyd(int arc[MAX_VEX][MAX_VEX], int vex);
// print adjacency matrix after floyd
void print_arc(graph_t* graph);
// check output
void output_check(graph_t* graph);
#endif
