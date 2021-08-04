#include <bits/stdc++.h>
using namespace std;
//O(n) -- TC
//O(w) -- AS
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

int maxWidth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<Node *> q;
    q.push(root);
    int width = INT_MIN;
    while (!q.empty())
    {
        int count = q.size();
        width = max(count, width);
        for (int i = 0; i < count; i++)
        {

            Node *curr = q.front();
            q.pop();

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
    return width;
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    cout << maxWidth(root);
}
