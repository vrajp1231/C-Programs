#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Edge;
//-------------------------------------------------------------
//
//
class Node
{
    public:
    Node(string iname)
    {
        name = iname;
    }
    string name;
    int in_count = 0;
    bool visited = false;
    
    vector<Edge *> out_edge_list;
};
//-------------------------------------------------------------
//
//
class Edge
{
    public:
    Edge(string iname, double iweight, Node *ifrom, Node *ito)
    {
        name = iname;
        weight = iweight;
        from = ifrom;
        to = ito;
    }

    string name;
    double weight;
    Node *from;
    Node *to;
    bool visited = false;
};

//-------------------------------------------------------------
//
//
class Graph
{
    public:
    vector<Node *> node_list;
    vector<Edge *> edge_list;
    
    //----------------------------------------------------------
    //
    Node* find_node(string name) 
    { 
        for(Node *n : node_list)
            if (n->name == name) return n;
        return 0;
    }
    //----------------------------------------------------------
    // Add a new edge ( and possibly new nodes) to the graph.
    //
    void add_edge(string name, double weight, string node_name_from, string node_name_to)
    {
        Node *node_from, *node_to;
        
        if (!(node_from = find_node(node_name_from))) 
            node_list.push_back(node_from = new Node(node_name_from));
            
        if (!(node_to = find_node(node_name_to))) 
            node_list.push_back(node_to = new Node(node_name_to));

        Edge *new_edge = new Edge(name, weight, node_from, node_to);
        edge_list.push_back(new_edge);
        node_from->out_edge_list.push_back(new_edge);
    }
    
    void print_nodes()
    {
        cout << "\nNodes\n=======================\n";
        for(Node *n : node_list)
        {
            for (Edge* e : edge_list)
            {
                if (n->name == e->to->name)
                    n->in_count = n->in_count + 1;
            }
            cout << n->name << ' ' << n->in_count << endl;
        }
    }
    
    void print_edges()
    {
        cout << "\nEdges\n=======================\n";
        for(Edge *e : edge_list)
            cout << e->name << ' ' << e->from->name << ' ' << e->to->name  << endl;
    }

    //----------------------------------------------------------
    // Initialize Node in counts.
    // NOTE: This method can be incorporated into the void print_nodes() method
    void init_in_counts()
    {
        cout << "\nNodes with In_Counts\n=======================\n";
        for (Node* n : node_list)
        {
            for (Edge* e : edge_list)
            {
                if (n->name == e->to->name)
                    n->in_count = n->in_count++;
            }
            cout << n->name << " " << n->in_count << endl;
        }
    }

    //=============================================================================
    // Pseudo-code for Depth First Traversal
    //
    void dfs(Node *n)
    {
        if (n->visited)
        {
            return;
        }
        cout << " Visiting " << n->name << endl;
        n->visited = true;

        for(Edge* e : n->out_edge_list)
        {
            dfs(e->to);
            n->visited = true;
        }
        cout << " Leaving " <<  n->name << endl;
    }

};

//-------------------------------------------------------------
//
//
int main()
{
    Graph g;
    g.add_edge("e1", 1.0, "1", "4");
    g.add_edge("e2", 2.0, "1", "5");
    g.add_edge("e3", 3.0, "2", "3");
    g.add_edge("e4", 4.0, "2", "4");
    g.add_edge("e5", 5.0, "3", "4");
    g.add_edge("e6", 6.0, "3", "6");
    g.add_edge("e7", 7.0, "3", "8");
    g.add_edge("e1", 8.0, "4", "5");
    g.add_edge("e3", 9.0, "5", "7");
    g.add_edge("e3", 10.0, "5", "9");
    g.add_edge("e3", 11.0, "6", "7");
    g.add_edge("e3", 12.0, "7", "9");
    g.add_edge("e3", 13.0, "8", "9");
    
    g.init_in_counts();
    g.print_nodes();
    g.print_edges();

    cout << "\nDepth First Transversal: Node 1\n";
    g.dfs(g.find_node("1"));
    for(Node *n : g.node_list)
    {
        n->visited = false;
    }

    cout << "\nDepth First Transversal: Node 2\n";
    g.dfs(g.find_node("2"));
    for(Node *n : g.node_list)
    {
        n->visited = false;
    }

    cout << "\nDepth First Transversal: Node 3\n";
    g.dfs(g.find_node("3"));
    for(Node *n : g.node_list)
    {
        n->visited = false;
    }
    
    return 0;
}