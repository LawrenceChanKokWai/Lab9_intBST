#include<iostream>
#include<fstream>

#include "BST.h"

using namespace std;

int main()
{
    BST intBST;

    const string filename = "data.txt";
    ifstream inFile(filename);

    if (!inFile)
    {
        cerr << "Error opening file: " << filename << endl;
        return -1;
    }

    int number;
    while (inFile >> number)
    {
        intBST.InsertNode(number);

        // Consume the comma
        if (inFile.peek() == ',')
            inFile.ignore();
    }

    cout << endl;
    cout << "PreOrderTraversal: ";
    intBST.PreOrderTraversal();
    cout << endl;

    cout << "InOrderTraversal: ";
    intBST.InOrderTraversal();
    cout << endl;

    cout << "PostOrderTraversal: ";
    intBST.PostOrderTraversal();
    cout << endl;

    return 0;
}
