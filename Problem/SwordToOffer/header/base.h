
#ifndef CPP_BASE_H
#define CPP_BASE_H
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

template <class T>
void printVector(vector<T> vec){
    for(T t : vec) cout << t << " ";
    cout << endl;
}

#endif //CPP_BASE_H
