
#include "BST.h"

BST::BST()
{
    m_root = nullptr;
}

BST::~BST()
{
    Destroy( m_root );
}

bool BST::IsEmpty() const
{
    return ( m_root == nullptr );
}

int BST::GetTreeHeight() const
{
    return GetHeight( m_root );
}

int BST::GetTreeNodes() const
{
    return GetNodes( m_root );
}

int BST::GetTreeLeaves() const
{
    return GetLeaves( m_root );
}

Node *BST::GetRoot() const
{
    return m_root;
}

BST::BST( const BST &otherTree )
{
    if( otherTree.m_root == nullptr )
    {
        m_root = nullptr;
    }
    CopyTree( m_root, otherTree.m_root );
}

BST &BST::operator = ( const BST &otherTree )
{
    if( this != &otherTree )
    {
        if( m_root != nullptr )
        {
            Destroy( m_root );
        }
        if( otherTree.m_root == nullptr )
        {
            m_root = nullptr;
        }
        CopyTree( m_root, otherTree.m_root );
    }
    return *this;
}

bool BST::InsertNode( const int &object )
{
    return Insert( m_root, object );
}

bool BST::DeleteNode( const int &object )
{
    return Delete( m_root, object );
}

bool BST::SearchNode( const int &object )
{
    return Search( m_root, object );
}

void BST::PreOrderTraversal() const
{
    PreOrder( m_root );
}

void BST::InOrderTraversal() const
{
    InOrder( m_root );
}

void BST::PostOrderTraversal() const
{
    PostOrder( m_root );
}

void BST::DestroyTree()
{
    Destroy( m_root );
}

// ************** PRIVATE **************************
//*************************************************
void BST::Destroy( Node *&ptr )
{
    if( ptr != nullptr )
    {
        Destroy( ptr->m_left );
        Destroy( ptr->m_right );
        delete ptr;
        ptr = nullptr;
    }
}

int BST::GetMax( int x, int y ) const
{
    if( x >= y )
    {
        return x;
    }
    else
    {
        return y;
    }
}

int BST::GetHeight( Node *ptr ) const
{
    if( ptr == nullptr )
    {
        return 0;
    }
    else
    {
        return ( 1 + GetMax(GetHeight(ptr->m_left), GetHeight(ptr->m_right)) );
    }
}

int BST::GetNodes( Node *ptr ) const
{
    if( ptr == nullptr )
    {
        return 0;
    }
    else
    {
        return ( 1 + GetNodes(ptr->m_left) + GetNodes(ptr->m_right) );
    }
}

int BST::GetLeaves( Node *ptr ) const
{
    if( ptr == nullptr )
    {
        return 0;
    }
    else if( ptr->m_left == nullptr && ptr->m_right == nullptr )
    {
        return 1;
    }
    else
    {
        return ( GetLeaves(ptr->m_left) + GetLeaves(ptr->m_right) );
    }
}

void BST::CopyTree( Node *&copiedTreeRoot, Node *otherTreeRoot )
{
    if( otherTreeRoot == nullptr )
    {
        copiedTreeRoot = nullptr;
    }
    else
    {
        copiedTreeRoot = new Node;
        copiedTreeRoot->m_object = otherTreeRoot->m_object;
        CopyTree( copiedTreeRoot->m_left, otherTreeRoot->m_left );
        CopyTree( copiedTreeRoot->m_right, otherTreeRoot->m_right );
    }
}

bool BST::Insert( Node *&current, const int &object )
{
    if( current == nullptr )
    {
        current = new Node;
        current->m_object = object;
        current->m_left = nullptr;
        current->m_right = nullptr;
        return true;
    }
    else if( object < current->m_object )
    {
        return Insert( current->m_left, object );
    }
    else if( object > current->m_object )
    {
        return Insert( current->m_right, object );
    }
    else
    {
        return false;
    }
}

bool BST::Delete( Node *&current, const int &object )
{
    if( current == nullptr )
    {
        return false;
    }
    else if( object < current->m_object )
    {
        return Delete( current->m_left, object );
    }
    else if( object > current->m_object )
    {
        return Delete( current->m_right, object );
    }
    else
    {
        if( current->m_left == nullptr )
        {
            Node *temp = current->m_right;
            delete current;
            current = temp;
        }
        else if( current->m_right == nullptr )
        {
            Node *temp = current->m_left;
            delete current;
            current = temp;
        }
        else
        {
            if( GetHeight(current->m_left) >= GetHeight(current->m_right) )
            {
                Node *temp = current->m_left;
                while( current->m_right != nullptr )
                {
                    temp = current->m_right;
                }
                current->m_object = temp->m_object;
                return Delete( current->m_left, temp->m_object );
            }
            else
            {
                Node *temp = current->m_right;
                while( current->m_left != nullptr )
                {
                    temp = current->m_left;
                }
                current->m_object = temp->m_object;
                return Delete( current->m_right, temp->m_object );
            }
        }
        return true;
    }
}

bool BST::Search( Node *&current, const int &object )
{
    if( current == nullptr )
    {
        return false;
    }
    if( object == current->m_object )
    {
        return true;
    }
    else if( object < current->m_object )
    {
        return Search( current->m_left, object );
    }
    else
    {
        return Search( current->m_right, object );
    }
}

void BST::PreOrder( Node *ptr ) const
{
    if( ptr != nullptr )
    {
        std::cout << ptr->m_object << " ";
        PreOrder( ptr->m_left );
        PreOrder( ptr->m_right );
    }
}

void BST::InOrder( Node *ptr ) const
{
    if( ptr != nullptr )
    {
        InOrder( ptr->m_left );
        std::cout << ptr->m_object << " ";
        InOrder( ptr->m_right );
    }
}

void BST::PostOrder( Node *ptr ) const
{
    if( ptr != nullptr )
    {
        PostOrder( ptr->m_left );
        PostOrder( ptr->m_right );
        std::cout << ptr->m_object << " ";
    }
}

