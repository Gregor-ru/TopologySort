#include "topo_sort.h"

void dfs(Graph& g, int v, bool* visited, MyList& result) {
    visited[v] = true;

    MyList::Node* current = g.adjacency[v].begin();
    while (current != nullptr) {
        int i = stoi(current->data);
        if (!visited[i]) {
            dfs(g, i, visited, result);
        }
        current = current->next;
    }

    result.push_front(to_string(v));
}

MyList topology_sort(Graph& g) {
    bool* visited = new bool[g.vertices];
    for (int i = 0; i < g.vertices; i++) {
        visited[i] = false;
    }

    MyList result;
    for (int i = 0; i < g.vertices; i++) {
        if (!visited[i]) {
            dfs(g, i, visited, result);
        }
    }

    delete[] visited;
    return result;
}