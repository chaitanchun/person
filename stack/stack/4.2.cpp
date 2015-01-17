#include "Graph.h"

bool checkPath(vector<Gnode>& graph, Gnode& end)
{

}

bool dfs(Gnode& node, Gnode& end)
{
    if (node.value == end.value)
        return true;

    for (size_t i = 0; i < node.adj.size(); i++)
    {
        if (!node.visited)
        {
            node.visited = true;
            if (dfs(node.adj[i]))
            {

            }

        }

    }

}
