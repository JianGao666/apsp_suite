



## Apsp_suite



Apsp_suite is a HLS benchmark suite designed specifically for the All pair shortest path problem on the weighted directed or undirected graph. There are two versions of the all pair shortest path algorithm. The first one is called as Floyd_matrix which solve the apsp problem by computing the matrix closure of the weighted matrix defined over the tropical semiring [1]. The second one is called as Floyd_naive which is a basic floyd warshall algorithm [2] [3]. 

### Run

1 . open `input.data` and adjust values.

2 . run `python ./check.py` to generate `check.data`.

2 . type `make run` to run the code.

### HLS

1 . run `make hls`.

### Synthesize Verilog code

1 . run `make syn`.

### Floyd_matrix

1 .  Apsp may be understood algebraically as computing the matrix closure of the weight matrix defined over the tropical semiring [1]. In basic terms, let matrix D represent the distance matrix and its element D[1] [2] represent the distance from vertex 1 to vertex 2.  The matrix multiplication is the following form:

![Screenshot 2021-08-28 081041](https://user-images.githubusercontent.com/84207576/131219058-e126be19-5d2b-44fb-84a1-bede2597901e.png)

Now we redefine the matrix multiplication as min plus multiplication where sum becomes min and multiplication becomes sum.

![Screenshot 2021-08-28 081058](https://user-images.githubusercontent.com/84207576/131219078-a436d672-07bf-4067-a53c-cb8a1f749b59.png)

Now, we can say D^2 is the adjacency matrix which contains the shortest distance from each vertex to another vertex through 2 intermediate vertices. The answer for the apsp problem will be:

![Screenshot 2021-08-28 081109](https://user-images.githubusercontent.com/84207576/131219083-bb358474-8755-4c7f-a44f-495054efe706.png)

### Floyd_naive

1 . Floyd_naive is just the basic Floyd warshall algorithm [4]. 

![Screenshot 2021-08-26 113628](https://user-images.githubusercontent.com/84207576/131001602-dd25c5c4-692e-4e58-9429-35a4b297668f.png)

### Q&A

##### Input

1 . What is `input.data`?

`input.data` represents the graph type, number of vertex, number of edge, and the edge information.

2 . What does the data inside the `input.data` mean?

Here is a example of `input.data`:

`2 5 4 1 2 1 2 3 5 3 4 6 4 1 6` 

The first number is the graph type. 1 represents directed graph and 2 represents undirected graph. The second number represents the number of vertex. The third number represents the number of edge. The rest of number is the edge information. 1 2 1 represent an edge from vertex 1 to vertex 2 with weight 1 etc. 

3 . How to adjust the `input.data`?

Max vertex number is 100. Max edge number for directed graph <=  vex*(vex-1). Max edge number for undirected graph <= vex * (vex-1)/2.

4 . What will be the input based on the `input.data`?

An adjacency matrix. The element of the matrix will be 0 if the edge point to itself.  The element of the matrix will be infinity if there is no edge. The rest of element will be the weight based on the `input.data`.

##### Check

1 . What is `check.py`?

`check.py` use the similar method as the Floyd_matrix to generate the answer. `check.py`  take the same input as the Floyd_matrix and Floyd_naive which is `input.data`. The output of the `check.py` is the distance matrix which represent the total distance from each vertex to another vertex. Apsp_suite only print success! when each element of the output is the same as the `check.data`.

2 . What is `check.data`?

`check.data` represents the distance matrix which represent the total distance from each vertex to another vertex.

##### Output

1 . What is output?

Both Floyd_matrix and Floyd_naive print the output directly to the terminal, which is the distance matrix which represent the total distance from each vertex to another vertex.

### Reference

> [1] Jeremy T. Fineman and Eric Robinson. Fundamental graph algorithms. In Jeremy Kepner and John Gilbert, editors, *Graph Algorithms in the Language of Linear Algebra*, chapter 5, pages 45--58. Society of Industrial and Applied Mathematics, Philadelphia, PA, USA, 2011.
>
> [2] R. W. Floyd, “Algorithm 97: Shortest path,” *Communications of the ACM*, vol. 5, no. 6, p. 345, 1962. 
>
> [3] S. Warshall, “A theorem on boolean matrices,” *Journal of the ACM*, vol. 9, no. 1, pp. 11–12, 1962. 
>
> [4] https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm

