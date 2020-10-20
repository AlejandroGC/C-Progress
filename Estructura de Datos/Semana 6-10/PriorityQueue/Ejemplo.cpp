#include <bits/stdc++.h>
#include <stack>
#include <queue>

using namespace std;

int main(){
    int n, dato;
    queue<int> q;
    stack<int> s;
    priority_queue<int> pqMay;
    priority_queue<int, vector<int>, greater<int>> pqMen;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> dato;
        q.push(dato);
        s.push(dato);
        pqMay.push(dato);
        pqMen.push(dato);
    }
    cout << "Queue: ";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
    cout << "Stack: ";
    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    cout << "Priority Queue: ";
    while(!pqMay.empty()){
        cout << pqMay.top() << " ";
        pqMay.pop();
    }
    cout << endl;

    cout << "Priority Queue Menor: ";
    while(!pqMen.empty()){
        cout << pqMen.top() << " ";
        pqMen.pop();
    }
    cout << endl;


    return 0;
}