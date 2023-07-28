Node* divide(Node* head)
{
  
    queue<Node*> qe, qo,q;
    Node* cur = head;
    while (cur) {
        if (cur->data % 2 == 0)
            qe.push(cur);
        else
            qo.push(cur);
        cur = cur->next;
    }
    Node* node = new Node(-100);
    Node* ans = node;
  
    while (!qe.empty()) {
        q.push(qe.front());
        qe.pop();
    }
  
    while (!qo.empty()) {
        q.push(qo.front());
        qo.pop();
    }
    while (!q.empty()) {
        node->next = q.front();
        node = q.front();
        q.pop();
    }
  
    node->next = NULL;
    return ans->next;
}