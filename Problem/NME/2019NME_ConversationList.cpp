#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int d, Node *left, Node *right) : data(d), left(left), right(right) {}
};

class LRU {
public:
    Node *head, *tail;
    unordered_map<int, Node *> map;

    LRU() {
        head = new Node(0, nullptr, nullptr);
        tail = new Node(0, nullptr, nullptr);
        head->right = tail;
        tail->left = head;
    }

    Node *find(int id) {
        auto iter = map.find(id);
        Node *newNode;
        if (iter == map.end()) {
            newNode = new Node(id, head, head->right);
            map.emplace(id, newNode);
        } else {
            newNode = iter->second;
            newNode->left->right = newNode->right;
            newNode->right->left=newNode->left;
            newNode->left = head;
            newNode->right = head->right;
        }
        head->right->left = newNode;
        head->right = newNode;
        return newNode;
    }
};

int main() {
    int n, m;
    cin >> n;
    while(n--){
        cin >> m;
        LRU lru;
        int id;
        while(m--){
            cin >> id;
            lru.find(id);
        }
        Node* node = lru.head;
        while((node = node->right) != lru.tail) cout << node->data << " ";
        cout << endl;
    }
    return 0;
}