#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct node{
    int a = 12;
};

int main() {
    node* x = new node();
    delete x;
    printf("%d", x->a);
    return 0;
}