#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;

    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;

    while (n--) {
        int x;
        cin >> x;

        if (l.empty() || r.empty()) {
            l.push(x);
        } else {
            if (x <= l.top()) {
                l.push(x);
            } else if (x >= r.top()) {
                r.push(x);
            } else {
                l.push(x);
            }
        }
        while (!(l.size() == r.size() || l.size() == r.size() + 1)) {
            if (l.size() > r.size()) {
                r.push(l.top());
                l.pop();
            } else {
                l.push(r.top());
                r.pop();
            }
        }

        cout << l.top() << '\n';
    }

    return 0;
}
