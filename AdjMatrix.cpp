#include <iostream>
#include <vector>

struct Graph {
	int V;
	int E;
	std::vector<int, int> adjM;
};

class graphOperations {
public:

	struct Graph* adjMatrixofUndirectedGraph();
};

struct Graph* graphOperations::adjMatrixofUndirectedGraph()
{
	int  i = 0, u = 0, v = 0;

	struct Graph* G = new Graph;
	if (nullptr == G)
	{
		std::cout << "Memory Error" << "\n";
		return;
	}
	std::cin >> G->V >> G->E;

	for (;u < G->V; u++)
	{
		for (; v < G->V; v++)
		{
			G->adjM[u][v] = 0;
		}
	}

	for (; i < G->E; i++)
	{
		std::cin >> u >> v;
		G->adjM[u][v] = 1;
		G->adjM[v][u] = 1;
	}

	return G;
}

int main()
{
	graphOperations gOper;
	struct Graph* G = gOper.adjMatrixofUndirectedGraph();
	std::cout << G->E << G->V << std::endl;
}