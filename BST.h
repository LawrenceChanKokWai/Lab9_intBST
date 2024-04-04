#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include<iostream>

struct Node
{
    int m_object;
    Node *m_left;
    Node *m_right;
};

class BST
{
public:
    BST();
    ~BST();

    BST( const BST &otherBST );
    BST &operator = ( const BST &otherBST );

    bool IsEmpty() const;
    int GetTreeHeight() const;
    int GetTreeNodes() const;
    int GetTreeLeaves() const;
    Node *GetRoot() const;

    bool InsertNode( const int &object );
    bool DeleteNode( const int &object );
    bool SearchNode( const int &object );
    void DestroyTree();

    void PreOrderTraversal() const;
    void InOrderTraversal() const;
    void PostOrderTraversal() const;

protected:
    Node *m_root;

private:
    void Destroy( Node *&ptr );

    int GetMax( int x, int y ) const;
    int GetHeight( Node *ptr ) const;
    int GetNodes( Node *ptr ) const;
    int GetLeaves( Node *ptr ) const;

    void CopyTree( Node *&copiedTreeRoot, Node *otherTreeRoot );

    bool Insert( Node *&current, const int &object );
    bool Delete( Node *&current, const int &object );
    bool Search( Node *&current, const int &object );

    void PreOrder( Node *ptr ) const;
    void InOrder( Node *ptr ) const;
    void PostOrder( Node *ptr ) const;

};

#endif // BST_H_INCLUDED
