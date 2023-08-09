class Solution {
private:
    // Helper function to convert the binary tree to a doubly linked list.
    // Returns the head of the doubly linked list.
    Node* convertToDLLHelper(Node* root) {
        
        if (root == NULL) return NULL;
        
        // Recursively convert the left subtree to a DLL and get the left DLL's tail node.
        if (root->left) {
            Node* leftSubTreeTail = convertToDLLHelper(root->left);
            
            // Find the tail node of the left DLL and connect it with the current node.
            while (leftSubTreeTail->right) leftSubTreeTail = leftSubTreeTail->right;
            
            leftSubTreeTail->right = root;
            root->left = leftSubTreeTail;
        }
        
        // Recursively convert the right subtree to a DLL and get the right DLL's head node.
        if (root->right) {
            Node* rightSubTreeHead = convertToDLLHelper(root->right);
            
            // Find the head node of the right DLL and connect it with the current node.
            while (rightSubTreeHead->left) rightSubTreeHead = rightSubTreeHead->left;
            
            rightSubTreeHead->left = root;
            root->right = rightSubTreeHead;
        }
        
        return root;
    }
    
public:
    // Function to convert binary tree to a doubly linked list and return its head.
    Node* bToDLL(Node* root) {
        // If the root is NULL, there is no binary tree to convert.
        if (root == NULL) return NULL;
        
        // Convert the binary tree to a DLL and get the head of the DLL.
        root = convertToDLLHelper(root);
        
        // Find the head of the DLL by traversing to the leftmost node.
        while (root->left) root = root->left;
        
        return root;
    }
};