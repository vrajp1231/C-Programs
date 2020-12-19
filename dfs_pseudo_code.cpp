    //=============================================================================
    // Pseudo-code for Depth First Traversal
    //
    void dfs(Node *n)
    {
        if n is visited return  // return immediately on a visited node
        print visiting n
        mark n as visited
        for each outgoing edge
            call dfs(node edge goes to)
        print leaving n
    }
    
    void dfs(Node *n)
    {
        print visiting n
        mark n as visited
        for each outgoing edge
            if node edge goes to is not visited // avoid calling dfs on a visited node
                call dfs(node edge goes to)
        print leaving n
    }