#include "file_creater.h"
#include "graph.h"

void random_txt_creator(int objectCount, const string& directory, const string& fileName) {
    if (objectCount < 1) {
        cout << "Invalid object count." << endl;
        return;
    }

    string fileFullName = directory + fileName;

    ofstream fileStream(fileFullName);

    if (!fileStream.is_open()) {
        cout << "Error: File not created" << endl;
        return;
    }

    random_device rd;
    mt19937 gen(rd());

    MyList orderList;
    for (int i = 0; i < objectCount; i++) {
        orderList.push_back(to_string(i));
    }

    fileStream << objectCount;
    fileStream << endl;

    MyList::Node* followsNode = orderList.begin();

    for (int i = 0; i < objectCount; i++) {
        MyList::Node* precedesNode = orderList.begin();

        while (precedesNode != followsNode) {
            fileStream << char('a' + stoi(precedesNode->data)) << "<" << char('a' + stoi(followsNode->data));
            fileStream << endl;

            precedesNode = precedesNode->next;
        }

        followsNode = followsNode->next;
    }

    fileStream.close();

    cout << "Random file created: " << fileFullName << endl;
}

