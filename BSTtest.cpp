
#include<iostream>

#include "BST.h"

using namespace std;

void Assert_Equals( bool condition, const string &message );
void TestInitialization( BST &intBST );
void TestInsertionAndSearchOperation( BST &intBST );
void TestTraversalOrders( BST &intBST );
void TestDeepCopyingOperations();
void TestDestroyTree();
void TestDeleteOperation();

int main()
{

    BST myBST;

    TestInitialization( myBST );
    TestInsertionAndSearchOperation( myBST );
    TestTraversalOrders( myBST );
    TestDeepCopyingOperations();
    TestDestroyTree();
    TestDeleteOperation();


    return 0;
}

void Assert_Equals( bool condition, const string &message )
{
    cout << (condition ? "\t-->[ PASS ] " : "\t-->[ FAIL ] ") << message << endl;
}

//++++ Test on initialization of intBST +++
void TestInitialization( BST &intBST )
{
    cout << "Test on initialization of intBst" << endl;
    Assert_Equals( intBST.GetTreeHeight() == 0, "Constructed initial tree height is zero" );
    Assert_Equals( intBST.GetTreeNodes() == 0, "Constructed initial tree node is zero" );
    Assert_Equals( intBST.GetTreeLeaves() == 0, "Constructed initial tree leaves is zero" );
    Assert_Equals( intBST.GetRoot() == nullptr, "Constructed initial root pointing at nullptr" );
    cout << endl;
}

//++++ Test node insertion +++
void TestInsertionAndSearchOperation( BST &intBST )
{
    cout << "Test on node insertion to BinarySearchTree" << endl;
    Assert_Equals( intBST.InsertNode(5), "Insertion of object 5");
    Assert_Equals( intBST.GetTreeHeight() == 1, "Tree height after inserting a node" );
    Assert_Equals( intBST.GetTreeNodes() == 1, "Tree node after inserting a node" );
    Assert_Equals( intBST.GetTreeLeaves() == 1, "Tree leaves after inserting a node" );
    Assert_Equals( intBST.InsertNode(2), "Insertion of object 2");
    Assert_Equals( intBST.InsertNode(10), "Insertion of object 10");
    Assert_Equals( intBST.InsertNode(10) == false, "Unable to perform insertion of duplicate object 10");
    Assert_Equals( intBST.GetTreeHeight() == 2, "Tree height after inserting two more nodes" );
    Assert_Equals( intBST.GetTreeNodes() == 3, "Tree node after inserting two more nodes" );
    Assert_Equals( intBST.GetTreeLeaves() == 2, "Tree leaves after inserting two more nodes" );
    Assert_Equals( intBST.SearchNode(2), "Search for a node that exist in the BinarySearchTree");
    Assert_Equals( intBST.SearchNode(12) == false, "Search for a node that does not exist in the BinarySearchTree");
    cout << endl;
}

//++++ Test traversal orders +++
void TestTraversalOrders( BST &intBST )
{
    cout << "Test on Traversal Orders" << endl;
    cout << "\tActual Pre-Order Traversal: ";
    intBST.PreOrderTraversal();
    cout << " | Expected Pre-Order Traversal: 5 2 10" << endl;
    cout << "\tActual In-Order Traversal: ";
    intBST.InOrderTraversal();
    cout << " | Expected In-Order Traversal: 2 5 10" << endl;
    cout << "\tActual Post-Order Traversal: ";
    intBST.PostOrderTraversal();
    cout << " |Expected Post-Order Traversal: 2 10 5" << '\n' << endl;
}

//++++ Test Copy Constructor & Equals Assignment Operators +++
void TestDeepCopyingOperations()
{
    BST bst;
    bst.InsertNode(5);
    bst.InsertNode(3);
    bst.InsertNode(10);

    BST copiedBST( bst );
    cout << "Test on copy constructor" << endl;
    Assert_Equals( copiedBST.GetTreeHeight() == 2, "Height of copied BST using copy constructor" );
    Assert_Equals( copiedBST.GetTreeNodes() == 3, "Number of nodes from copiedBST using copy constructor" );
    Assert_Equals( copiedBST.GetTreeLeaves() == 2, "Number of leaves from copiedBST using copy constructor" );
    Assert_Equals( &copiedBST != &bst, "Both Addresses from copiedBST and otherBST differences using copy constructor");
    cout << endl;

    cout << "Test on equal assignment operator" << endl;
    BST equalAssignmentBST( bst );
    Assert_Equals( equalAssignmentBST.GetTreeHeight() == 2, "Height of copied BST using copy constructor" );
    Assert_Equals( equalAssignmentBST.GetTreeNodes() == 3, "Number of nodes from copiedBST using copy constructor" );
    Assert_Equals( equalAssignmentBST.GetTreeLeaves() == 2, "Number of leaves from copiedBST using copy constructor" );
    Assert_Equals( &equalAssignmentBST != &bst, "Both Addresses from equalAssignmentBST and otherBST differences using copy constructor");
    cout << endl;
}

//++++ Test Destroy Tree +++
void TestDestroyTree()
{
    BST bst;
    bst.InsertNode(5);
    bst.InsertNode(3);
    bst.InsertNode(10);

    bst.DestroyTree();

    cout << "Test on destroying tree operator" << endl;
    Assert_Equals( bst.GetTreeHeight() == 0, "Tree height is zero after DestroyTree" );
    Assert_Equals( bst.GetTreeNodes() == 0, "Tree has zero nodes after DestroyTree" );
    Assert_Equals( bst.GetTreeLeaves() == 0, "Tree has zero leaves after DestroyTree" );
    Assert_Equals( bst.GetRoot() == nullptr, "Tree pointer is pointing nullptr" );
    cout << endl;
}

//++++ Test Deleting a node +++
void TestDeleteOperation()
{
    BST bst;
    bst.InsertNode(5);
    cout << "Test on deleting object operation" << endl;
    Assert_Equals( bst.DeleteNode(5), "Deletion of node object 5 (1 node)" );
    bst.InsertNode(5);
    bst.InsertNode(3);
    cout << "\nScenario deleting left child node \n";
    cout << "\t   In-Order before left child node: [ "; bst.InOrderTraversal(); cout << " ]" << endl;
    Assert_Equals( bst.DeleteNode(3), "Deletion of node with only a left leaf (2 node)" );
    cout << "\t   In-Order after deleting left child node: [ "; bst.InOrderTraversal(); cout << " ]" << endl;

    bst.InsertNode(3);
    cout << "\nScenario deleting root node \n";
    cout << "\t   In-Order before root node: [ "; bst.InOrderTraversal(); cout << " ]" << endl;
    Assert_Equals( bst.DeleteNode(5), "Deletion of root node (2 node)" );
    cout << "\t   In-Order after deleting root node: [ "; bst.InOrderTraversal(); cout << " ]" << endl;

    bst.InsertNode(8);
    bst.InsertNode(3);
    bst.InsertNode(10);
    bst.InsertNode(1);
    bst.InsertNode(6); //<-- delete this
    bst.InsertNode(4);
    bst.InsertNode(7);

    cout << "\nScenario deleting node with left and right child \n";
    cout << "\t   In-Order before node deletion: [ "; bst.InOrderTraversal(); cout << " ]" << endl;
    Assert_Equals( bst.DeleteNode(6), "Deletion of root node (2 node)" );
    cout << "\t   In-Order after deleting root node: [ "; bst.InOrderTraversal(); cout << " ]" << endl;

    cout << endl;
}
