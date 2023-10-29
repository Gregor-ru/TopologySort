#include "framework.h"

#include "file_creater.h"
#include "graph.h"
#include "topo_sort.h"

int main() {
    int objectCount = OBJECT_COUNT_DEFAULT;
    string directory = FILES_PATH_DEFAULT;
    string fileName = "random_relations.txt";

    random_txt_creator(objectCount, directory, fileName);

    ifstream inputFile(directory + fileName);

    if (!inputFile) {
        cerr << "File open error" << endl;
        return 1;
    }

    int numObjects;
    inputFile >> numObjects;

    Graph g(numObjects);
    int i = 0;
    while (inputFile) {
        string line;
        inputFile >> line;
        
        if (!line.empty()) {
            string a = line.substr(0, 1);
            string b = line.substr(2, 1);
            int u = a[0] - 'a';
            int v = b[0] - 'a';
            g.add_edge(u, v);
        }
    }

    inputFile.close();

    MyList result = topology_sort(g);

    cout << "Topology sort result: ";
    MyList::Node* current = result.begin();
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}