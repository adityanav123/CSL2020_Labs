#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int a) : val(a), next(nullptr) {}
};

Node* insert(int val, Node* root) {
    if(root == nullptr) return new Node(val);

    root->next = insert(val, root->next);
    
    return root;
} 

Node* _create_list(vector<int> v, Node* root) {
    for(auto x : v) {
        root = insert(x, root);
        //cout << "val: " << x << "\n";
    }
    return root;
}

void _print_list(Node* root) {
    if(root == nullptr) {
        cout << "list is empty!\n";
        return;
    }
    Node* tmp = root;
    while(tmp != nullptr) {
        cout << tmp->val << " "; 
        tmp = tmp->next;
    }cout << "\n";
}

Node* _middle_element(Node* head) {
    // finds the middle element.
    Node* slow = head, *fast = head;
    while(!fast->next && !fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    Node* middle = slow->next;
    slow->next = nullptr;
    return middle;
}

Node* merge(Node* left, Node* right) {
    Node* dummynode = new Node(INT_MAX);
    Node* traversal = dummynode;
    while(left != nullptr && right != nullptr) {
        if(left->val < right->val) {
            traversal->next = left;
            left = left->next;
        }
        else {
            traversal->next = right;
            right = right->next;
        }
        traversal = traversal->next;
    }
    // remaining elements.
    if(left != nullptr) traversal->next = left;
    if(right != nullptr) traversal->next = right;
    return dummynode->next;
}

Node* sortlist(Node* root) {
    // merge sort;
    if(root == nullptr || root->next == nullptr) return root;
    Node* mid = _middle_element(root);
    Node* left = sortlist(root);
    Node* right = sortlist(mid);
    return merge(left, right);

}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin); // input from file "inp.txt"
    #endif

    int n; // size.
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    Node* root = nullptr;
    root = _create_list(v, root);
    cout << "unsorted list = ";
    _print_list(root);
    cout << "sorted list = ";
    root = sortlist(root);
    _print_list(root);
    return 0;
}
