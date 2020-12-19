#include <iostream>
using namespace std;

//=====================================================================
struct Node {
    int x;
    Node * left;
    Node * right;
};

//=====================================================================
class Tree 
{
    Node * root;
    public:
        Tree() 
        {
            root = NULL;
        }
        
    //-----------------------------------------------------------------
    void insert(int x) 
    {
        Node * ptr = new Node;

        ptr -> x = x;
        ptr -> left = NULL;
        ptr -> right = NULL;

        cout << "\n-------------------------------------" << endl;
        cout << "Node Address: " << ptr << endl;

        if (root == NULL)
            root = ptr;
        else 
        {
            Node * temp = root;

            while (true) 
            {
                if (temp -> x > x) 
                {
                    if (temp -> left == NULL) {
                        cout << "Node Parent Address: " << temp << endl;
                        cout << "Node Parent Value: " << temp -> x << endl;
                        temp -> left = ptr;
                        break;
                    } else
                        temp = temp -> left;
                } else 
                {
                    if (temp -> right == NULL) 
                    {
                        cout << "Node Parent Address: " << temp << endl;
                        cout << "Node Parent Value: " << temp -> x << endl;
                        temp -> right = ptr;
                        break;
                    } else
                        temp = temp -> right;
                }
            }
        }

        cout << "Root: " << root << endl;
        cout << "-------------------------------------" << endl;
    }
        
    //-----------------------------------------------------------------
    public: void inOrder(){ inOrder(root); }
    private: void inOrder(Node * temp) {
        if (temp != NULL) 
        {
            inOrder(temp -> left);
            cout << temp -> x << " ";
            inOrder(temp -> right);
        }
    }
        
    //-----------------------------------------------------------------
    public: void preOrder(){ inOrder(root); }
    private: void preOrder(Node * temp) 
    {
        if (temp != NULL) {
            cout << temp -> x << " ";
            preOrder(temp -> left);
            preOrder(temp -> right);
        }
    }
        
    //-----------------------------------------------------------------
    public: void postOrder(){ inOrder(root); }
    private: void postOrder(Node * temp) 
    {
        if (temp != NULL) {
            postOrder(temp -> left);
            postOrder(temp -> right);
            cout << temp -> x << " ";
        }
    }
        
    //-----------------------------------------------------------------
    public: Node * getRoot() {
        return root;
    }
        
    //-----------------------------------------------------------------
    public: void display(){ display(root); }
    private: void display(Node * temp) 
    {
        if (temp != NULL) {
            cout << endl;
            cout << "Parent: " << temp -> x << endl;
            cout << " Left Child of " << temp -> x << ": ";
            if (temp -> left == NULL)
                cout << "NULL" << endl;
            else
                cout << temp -> left -> x << endl;

            cout << " Right Child of " << temp -> x << ": ";
            if (temp -> right == NULL)
                cout << "NULL" << endl;
            else
                cout << temp -> right -> x << endl;
            display(temp -> left);
            display(temp -> right);
        }
    }
        
    //-----------------------------------------------------------------
    bool isEmpty() 
    {
        if (root == NULL)
            return true;

        return false;
    }
    
    public:     
    //-----------------------------------------------------------------
    void removeAll(int value) 
    {
        while (true) 
        {
            Node * temp = root, * ptemp = root;

            while (temp != NULL && temp -> x != value) 
            {
                ptemp = temp;
                if (temp -> x < value)
                    temp = temp -> right;
                else if (temp -> x > value)
                    temp = temp -> left;
            }

            if (temp == NULL) 
            {
                cout << "All nodes cotaining " << value << " are deleted" << endl;
                break;
            } else 
            {
                if (temp -> left == NULL && temp -> right == NULL) 
                {
                    if (temp == root)
                        root = NULL;
                    else if (ptemp -> left == temp)
                        ptemp -> left = NULL;
                    else if (ptemp -> right == temp)
                        ptemp -> right = NULL;
                } else if (temp -> left == NULL && temp -> right != NULL) 
                {
                    if (temp == root)
                        root = temp -> right;
                    else if (ptemp -> left == temp)
                        ptemp -> left = temp -> right;
                    else if (ptemp -> right == temp)
                        ptemp -> right = temp -> left;
                } else if (temp -> right == NULL && temp -> left != NULL) 
                {
                    if (temp == root)
                        root = temp -> left;
                    else if (ptemp -> left == temp)
                        ptemp -> left = temp -> left;
                    else if (ptemp -> right == temp)
                        ptemp -> right = temp -> right;
                } else if (temp -> left != NULL && temp -> right != NULL) 
                {
                    Node * tempHolder = temp, * ptempHolder = temp;

                    while (tempHolder -> left != NULL) 
                    {
                        ptempHolder = tempHolder;
                        tempHolder = tempHolder -> left;
                    }

                    temp -> x = tempHolder -> x;
                    ptempHolder -> left = tempHolder -> right;

                    temp = tempHolder;
                }

                delete temp;
                cout << "Node Removed Successfully." << endl;
            }
        }
    }
        
    //-----------------------------------------------------------------
    void remove(int value) 
    {
        Node * temp = root, * ptemp = root;

        while (temp != NULL && temp -> x != value) 
        {
            ptemp = temp;
            if (temp -> x < value)
                temp = temp -> right;
            else if (temp -> x > value)
                temp = temp -> left;
        }

        if (temp == NULL) {
            cout << "Value Not Found...." << endl;
        } else 
        {
            if (temp -> left == NULL && temp -> right == NULL) 
            {
                if (temp == root)
                    root = NULL;
                else if (ptemp -> left == temp)
                    ptemp -> left = NULL;
                else if (ptemp -> right == temp)
                    ptemp -> right = NULL;
            } else if (temp -> left == NULL && temp -> right != NULL) 
            {
                if (temp == root)
                    root = temp -> right;
                else if (ptemp -> left == temp)
                    ptemp -> left = temp -> right;
                else if (ptemp -> right == temp)
                    ptemp -> right = temp -> left;
            } else if (temp -> right == NULL && temp -> left != NULL) 
            {
                if (temp == root)
                    root = temp -> left;
                else if (ptemp -> left == temp)
                    ptemp -> left = temp -> left;
                else if (ptemp -> right == temp)
                    ptemp -> right = temp -> right;
            } else if (temp -> left != NULL && temp -> right != NULL) 
            {
                Node * tempHolder = temp, * ptempHolder = temp;

                while (tempHolder -> left != NULL) 
                {
                    ptempHolder = tempHolder;
                    tempHolder = tempHolder -> left;
                }

                temp -> x = tempHolder -> x;
                ptempHolder -> left = tempHolder -> right;

                temp = tempHolder;
            }

            delete temp;
            cout << "Node Removed Successfully." << endl;
        }
    }
        
    //-----------------------------------------------------------------
    void deleteAllNodes(Node * temp) {
        if (temp != NULL) {
            deleteAllNodes(temp -> left);
            deleteAllNodes(temp -> right);
            cout << "Address: " << temp << endl;
            cout << "Value: " << temp -> x << endl << endl;
            delete temp;
        }
    }
        
    //-----------------------------------------------------------------
    ~Tree() {
        cout << "Below Nodes Deleted Successfully:" << endl;
        deleteAllNodes(root);
    }

    // Depth - Determines how deep the BST is
    public:
        int depth()
        {
            return depth(root);
        }
    private:
        int depth(Node *sum)
        {
            if(sum == NULL)
            {
                return 0;
            }
            else
            {
                int left = depth(sum->left);
                int right = depth(sum->right);

                if (left > right)
                {
                    return left + 1;
                }
                else
                {
                    return right + 1;
                }
            }
        }
};

//=====================================================================
int main(){
    Tree T;
    Tree No_Depth;

    T.insert(50);
    T.insert(20);
    T.insert(80);
    T.insert(60);
    T.insert(90);
    T.display();
    cout << "The number of the nodes in this BST is: " << T.depth() << endl;

    No_Depth.display();
    cout << "The number of the nodes in this BST is: " << No_Depth.depth() << endl;

    system("pause");
	return 0;
}
