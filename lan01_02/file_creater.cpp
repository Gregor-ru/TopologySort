#include "file_creater.h"

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

    fileStream << objectCount;
    fileStream << endl;

    for (int i = 0; i < objectCount; i++) {
        int precedes = gen() % objectCount;
        int follows = i;

        if (precedes == follows) {
            precedes = (precedes + 1) % objectCount;
        }

        fileStream << char('a' + precedes) << "<" << char('a' + follows);

        if (i < objectCount) {
            fileStream << endl;
        }
    }

    fileStream.close();

    cout << "Random file created: " << fileFullName << endl;
}