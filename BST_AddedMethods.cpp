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
    void insert(int z) // int z passed in from main()
    {
        Node * ptr = new Node;

        ptr -> x = z;
        ptr -> left = NULL;
        ptr -> right = NULL;

        cout << "\n-------------------------------------" << endl;
        cout << "Node Address: " << ptr << endl;

        if (root == NULL)
            root = ptr;
        else 
        {
            Node * temp = root; // creats a temp node to help traverse BST

            while (true) 
            {
                if (temp -> x > z) 
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
        
    // In Order Traversal
    public: void inOrder()
    { 
        inOrder(root);
    }
    private: void inOrder(Node * temp) {
        if (temp != NULL) 
        {
            inOrder(temp -> left);
            cout << temp -> x << " ";
            inOrder(temp -> right);
        }
    }
        
    // Pre Order Traversal
    public: void preOrder()
    {
        inOrder(root);
    }
    private: void preOrder(Node * temp) 
    {
        if (temp != NULL) {
            cout << temp -> x << " ";
            preOrder(temp -> left);
            preOrder(temp -> right);
        }
    }
        
    // Post Order Traversal
    public: void postOrder()
    {
        inOrder(root);
    }
    private: void postOrder(Node * temp) 
    {
        if (temp != NULL) {
            postOrder(temp -> left);
            postOrder(temp -> right);
            cout << temp -> x << " ";
        }
    }
        
    // Get Root
    public: Node * getRoot() {
        return root;
    }
        
    // Display Parent and Children
    public: void display()
    {
        display(root);
    }
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

    // Find1 Method (Non Recursive)
    public:
        Node * find1(int q)
        {
            Node * finder1 = root;
            while(finder1 != NULL)
            {
                if(finder1 -> x == q)
                    break;
                else if(finder1 -> x > q)
                    finder1 = finder1 -> left;
                else if(finder1 -> x < q)
                     finder1 = finder1 -> right;
            }
            return finder1;
        }

    // Find2 Method (Recursive)
    public:
        Node * find2(int q)
        {
            return find2(q, root);
        }
    private:
        Node * find2(int q, Node * finder1)
        {
            if(finder1 == NULL || finder1 -> x == q)
                return finder1;
            
            if(finder1 -> x > 1)
            {
                return find2(q, finder1 -> left);
            }
            else {
                return find2(q, finder1 -> right);
            }
        }
    
    // Counts number of nodes
    public:
        int node_count()
        {
            return node_count(root);
        }
    private:
        int node_count(Node * counting)
        {
            if(counting == NULL)
            {
                return 0;
            }
            else
            {
                int total_count = 1 + node_count(counting -> left) + node_count(counting -> right);
                return total_count;
            }
            
        }

    // Counts sum of all nodes
    public:
        int node_sum()
        {
            return node_sum(root);
        }
    private:
        int node_sum(Node * sum)
        {
            if(sum == NULL)
            {
                return 0;
            }
            else
            {
                int total_sum = sum -> x + node_sum(sum -> left) + node_sum(sum -> right);
                return total_sum;
            }
        }
        
    // Checks if node is empty
    bool isEmpty() 
    {
        if (root == NULL)
            return true;

        return false;
    }
    
    public:     
    // Removes all nodes with int value
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
        
    // Removes a node
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
        
    // Deletes all Nodes
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

};

//=====================================================================
int main(){
    Tree T;
    T.insert(50);
    T.insert(20);
    T.insert(80);
    T.insert(60);
    T.insert(90);
    T.display();

    int find1_value = 0;
    cout << "Enter the value you want to find using find1 method" << endl;
    cin >> find1_value;

    int find2_value = 0;
    cout << "Enter the value you want to find using find2 method" << endl;
    cin >> find2_value;

    if(T.find1(find1_value) != NULL)
    {
        cout << "This value is found in the BST" << endl;
    }
    else if (T.find1(find1_value) == NULL)
    {
        cout << "This value cannot be found in the BST" << endl;
    }

    if(T.find2(find2_value) != NULL)
    {
        cout << "This value is found in the BST" << endl;
    }
    else if (T.find2(find2_value) == NULL)
    {
        cout << "This value cannot be found in the BST" << endl;
    }
    
    cout << "The number of nodes in this BST is: " << T.node_count() << endl;
    cout << "The sum of the nodes in this BST is: " << T.node_sum() << endl;

    system("pause");
	return 0;
}
