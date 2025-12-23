#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> heap;

// Percolate down
// Heapify is only possible when both the left and right sub-tree are
// perfectly maintaining the "heap property"
void heapify(int i, int n) {
    while(true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < n && heap[left] > heap[largest]) {
            largest = left;
        }
        if(right < n && heap[right] > heap[largest]) {
            largest = right;
        }
        if(largest != i) {
            swap(heap[i], heap[largest]);
            i = largest;
        }
        else break;
    }

}

void insert(int val) {
    heap.push_back(val);
    int i = heap.size() - 1;
    while(i > 0) {
        int par = (i - 1) / 2;
        if(heap[par] < heap[i]) {
            swap(heap[par], heap[i]);
            i = par;
        }
        else break;
    }
}

void delete_root() {
    int n = heap.size();
    heap[0] = heap[n - 1];
    heap.pop_back();
    n--;
    heapify(0, n);

}

void print_heap() {
    for(int i = 0; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << '\n';
}

int main() {
    insert(100);
    insert(50);
    insert(20);
    insert(200);
    print_heap();
    delete_root();
    print_heap();
   
    return 0;
}
