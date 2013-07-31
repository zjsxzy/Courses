'''
Programming assignment 3:

implement the Karger's
randomized algorithm
for finding the minimum cut
in the given graph.

@author: Mikhail Dubov
'''

import math
import random

class UndirectedGraph:
    
    def __init__(self, vertices):
        self.adj_vertices = []
        while vertices > 0:
            self.adj_vertices.append([])
            vertices -= 1
        
        
    def copy(self):
        res = UndirectedGraph(0)
        for l in self.adj_vertices:
            res.adj_vertices.append(l[:])
        return res
        
        
    def add_edge(self, i, j):
        # Assuming there will be a
        # call of self.add_edge(j, i)
        self.adj_vertices[i].append(j)
    
    def n(self):
        return len(self.adj_vertices)
    
    
    def merge_karger(self, i, j):
        
        i_adj = self.adj_vertices[i]
        k = 0
        while k < len(i_adj):
            if i_adj[k] == j:
                i_adj.pop(k)
                k -= 1
            k += 1
        
        for v in self.adj_vertices[j]:
            if (v != i):
                self.add_edge(i, v)
                v_adj = self.adj_vertices[v]
                # Assuming undirected graph
                k = 0
                l = len(v_adj)
                while k < l:
                    if(v_adj[k] == j):
                        v_adj[k] = i
                        break
                    k += 1
                
        # Optimization: instead of computing a new graph
        # just swap j-th and (n-1)-th lines 'in-place'
        self.adj_vertices[j] = self.adj_vertices[self.n()-1]
        for v in self.adj_vertices[j]:
            v_adj = self.adj_vertices[v]
            # Assuming undirected graph
            k = 0
            l = len(v_adj)
            while k < l:
                if(v_adj[k] == (self.n()-1)):
                    v_adj[k] = j
                    break
                k += 1
        self.adj_vertices.pop()

    

def _kargerMinCut(graph, seed):
    
    # Each time - new seed
    random.seed(seed)
        
    while graph.n() > 2:
        # Picking random edge
        i = random.randint(0, graph.n()-1)
        adj = graph.adj_vertices[i]
        j = random.choice(adj)
        
        graph.merge_karger(i, j)

    # Two vertices remain
    return len(graph.adj_vertices[0])
    

def kargerMinCut(graph, N):
    '''
    Computes the minimum cut of the graph.
    
    Running time lower bound is Omega(N * m), where
    N - number of iterations,
    m - number of graph edges.
    
    For high success probability (1/n failure chance),
    use N = n^2 * log(n).
    '''
    
    i = 0
    
    # (!) Working with the copy of the graph,
    # not destroying the original one
    min_res = _kargerMinCut(graph.copy(), i)
    while i < N:
        t = _kargerMinCut(graph.copy(), i)
        print(str(i)+': '+str(t))
        if t < min_res: min_res = t
        i += 1
        
    return min_res


def main():
    
    f = open('kargerMinCut.txt')
    # (!) Even better approach to reading line than in PA2
    lines = f.read().splitlines()
    f.close()
    
    graph = UndirectedGraph(200)

    for line in lines:
        lst = line.split('\t')
        t = int(lst[0])-1
        for i in lst[1:-1]:
            v = int(i)-1
            graph.add_edge(t, v)
            
    # To get (1/n) failure probability,
    # repeat the basic procedure n^2 * log(n) times
    
    N = math.log(graph.n()) #graph.n()**2 * math.log(graph.n())
    print(kargerMinCut(graph, N))


if __name__ == '__main__':
    main()