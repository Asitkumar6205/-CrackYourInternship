int morrisTraversal(Node* root) {
    int cnt = 0;
    Node* curr = root;
    
    while(curr != NULL) {
        if(curr->left == NULL) {
            ++cnt;
            curr = curr->right;
        }
        else {
            Node* prev = curr->left;
            while(prev->right && prev->right != curr) prev = prev->right;
            
            if(prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            }
            else {
                ++cnt;
                prev->right = NULL;
                curr = curr->right;
            }
        }
    } 
    
    return cnt;
}

float getMedian(int total, Node* prev, Node* curr) {
    float ans = 0;
    if(total%2 == 0) ans = (prev->data + curr->data)/2.0;
    else ans = curr->data;
    
    return ans;
}

float findMedian(struct Node *root) {
      int total = morrisTraversal(root);
      int cnt = 0;
      
      Node* curr = root, *prev = curr;
      
      while(curr != NULL) {
        if(curr->left == NULL) {
            ++cnt;
            if(total%2 == 0 && cnt == (total/2) + 1) return getMedian(total, prev, curr);
            else if(total%2 != 0 && cnt == (total+1)/2) return getMedian(total, prev, curr);
            prev = curr;
            curr = curr->right;
        }
        else {
            Node* prev2 = curr->left;
            while(prev2->right && prev2->right != curr) prev2 = prev2->right;
            
            if(prev2->right == NULL) {
                prev2->right = curr;
                curr = curr->left;
            }
            else {
                ++cnt;
                prev2->right = NULL;
                prev = prev2;
                if(total%2 == 0 && cnt == (total/2) + 1) return getMedian(total, prev, curr);
                else if(total%2 != 0 && cnt == (total+1)/2) return getMedian(total, prev, curr);
                prev = curr;
                curr = curr->right;
            }
        }
    }
    
    return 0;
}