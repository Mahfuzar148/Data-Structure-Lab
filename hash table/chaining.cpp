
#include <bits/stdc++.h>
using namespace std;
#define MX 17
vector<int> table[MX];

void chaining(int data) {
    int index = (data % MX);
    table[index].push_back(data);
}

void search_chaining(int data) {
    int index = (data % MX);
    for (int i = 0; i < table[index].size(); i++) {
        if (table[index][i] == data) {
            cout << data << " found at index " << index << "->" << i << endl;
            return; // Once found, no need to continue searching
        }
    }
    cout << data << " not found" << endl;
}

int main() {
    cout << "Enter data otherwise type -1:" << endl;
    int data;

    while (1) {
            cin>>data;
          if(data == -1) break;

           chaining(data);
    }

    cout << "Enter data for searching otherwise type -1:" << endl;
    int data1;
    while (cin >> data1 && data1 != -1) {
        search_chaining(data1);
    }

    return 0;
}
