#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Task {
    int startTime, processTime;
    int index;
    Task(int start, int run, int idx) : startTime(start), processTime(run), index(idx) {}
};

class HeapComparision {
    public:
        bool operator() (Task &t1, Task &t2) {
            if(t1.processTime > t2.processTime) {
                return true;
            }
            else if(t1.processTime < t2.processTime)
                return false;

            else
                return t1.index > t2.index;
        }
};


vector<int> getOrder(vector<vector<int>>& tasks) {
        int idx = 0;
        long long t = 1e12;
        for(auto &task : tasks) {
            task.push_back(idx);
            idx++;

            t = min(t, (long long)task[0]);
        }

        sort(tasks.begin(), tasks.end());

        // wait queue
        priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>>> wq;
        vector <int> order;

        idx = 0;
        while(idx < tasks.size() || !wq.empty()) {

			// add pending tasks to wait queue
            while(idx < tasks.size() and tasks[idx][0] <= t) {
                wq.push({ tasks[idx][1], tasks[idx][2] });
                idx++;
            }

            if(!wq.empty()) {
                // pick the shortest processing time task to process next
                auto currP = wq.top();
                wq.pop();

                t += (long long)currP[0];
                order.push_back(currP[1]);
            }
            else {
			    // move onto the next task directly if nothing in queue
                t = tasks[idx][0];
            }
        }

        return order;
    }

int main() {
    vector<vector<int>> v = {
        {9, 1}, {9, 2}, {9, 3}, {14, 2}, {3, 29}
    };
    vector<int> answer = getOrder(v);
    for(auto x : answer) cout << x << " ";
    cout << "\n";
    return 0;
}
