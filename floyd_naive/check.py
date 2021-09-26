import numpy as np
N = 0



def create_data(): 
    fin = open("input.data", "r")
    data = fin.readline().split()
    graph_type = int(data[0])
    N = int(data[1])
    M = int(data[2])

    G = np.full((N, N), np.inf)

    step = 3
    new_data = [data[i:i+step] for i in range(3, len(data), step)]

    for i in new_data:
        G[int(i[0]) - 1][int(i[1]) - 1] = int(i[2])
        if(graph_type == 2):
            G[int(i[1]) - 1][int(i[0]) - 1] = int(i[2])

    for i in range(N):
        G[i][i] = 0

    print(G)
    return G, N, M

def mul(G1, G2, N):
    G_mul = np.full((N, N), np.inf)
    for i in range(N):
        for j in range(N):
            for k in range(N):
                G_mul[i][j] = min(G_mul[i][j], G1[i][k] + G2[k][j])
    return G_mul

def floyd(G, N, M):
    G_res = G
    G_base = G
    for i in range(0, N-1):
        G = mul(G, G_base, N)
        G_res = np.minimum(G_res, G)
    return G_res

G, N, M = create_data()

ans = floyd(G, N, M)
print(ans)  

fout = open("check.data", "w")

for i in range(N):
    for j in range(N):
        if ans[i][j] != np.inf:
            fout.write(str(int(ans[i][j])))
        else:
            fout.write("2147483647")
        fout.write("\t\t")
    fout.write("\n")


