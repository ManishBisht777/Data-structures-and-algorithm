# include <iostream>
# include <vector>
# include <queue>
# include <stack>
using namespace std;


//maintiain min left horizontal dist ans max right horizontal dist and compare form curr horixontals
//check again
vector<int> topview(Node* root)
{
    vector<int> ans;
    queue<pair<Node*, int>> q;
    stack<int> left;
    vector<int> right;
    int hd=0,l=0,r=0;
    q.push(make_pair(root,0));

    Node* n;
    while(q.size())
    {
        n=q.front().first;
        hd=q.front().second;

        if(hd<l)
        {
            left.push(n->data);
            l=hd;
        }
        else if(hd>r)
        {
            right.push_back(n->data);
            r=hd;
        }

        if(n->left)
        {
            q.push(make_pair(n->left,hd-1));
        }
        if(n->right)
        {
            q.push(make_pair(n->right,hd+1));
        }
        q.pop();
    }

    while(left.size())
    {
        ans.push_back(left.top());
        left.pop();
    }

    ans.push_back(root->data);

    for(auto i : right)
    {
        ans.push_back(i);
    }

    return ans;

} 