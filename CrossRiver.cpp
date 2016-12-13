#include<iostream>
#include<vector>
#include<unordered_set>
#include<cmath>

using namespace std;

void narrate(const vector<vector<int>> &procedures) {
    vector<string> items = {"farmer", "wolf", "sheep", "cabbage"};

    for(auto arr : procedures) {
        cout << "south:" << ends;
        for(size_t i = 0; i != arr.size(); ++ i) {
            if(arr[i] == 0) {
                cout << items[i] << ends;
            }
        }
        cout << endl;
        cout << "north:" << ends;
        for(size_t i = 0; i != arr.size(); ++ i) {
            if(arr[i] != 0) {
                cout << items[i] << ends;
            }
        }
        cout << endl << endl;
    }
}

bool is_dangerous(const vector<int> &arr) {
    return ((arr[1] == arr[2] && arr[0] != arr[1]) || (arr[2] == arr[3] && arr[0] != arr[2]));
}

int caculate_status(const vector<int> &arr) {
    int res = 0;
    for(size_t i = 0; i != arr.size(); ++ i ) {
        if(arr[i] == 0)
            res += pow(2, i);
    }
    return res;
}

void backtrack(vector<int> &arr, unordered_set<int> status, bool &done, vector<vector<int>> &procedures) {
    if(done) {
        return;
    }

    int current_status = caculate_status(arr);
    if(status.find(current_status) != status.end()) {
        return;
    } else {
        status.insert(current_status);
    }


    if(arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3] && arr[3] == 1) {
        narrate(procedures);
        cout << "done." << endl;
        done = true;
        return;
    }

    for(size_t i = 1; i != arr.size(); ++ i) {
        if(arr[i] == arr[0]) {
            arr[0] = 1 - arr[0];
            arr[i] = 1 - arr[i];
            if(!is_dangerous(arr)) {
                procedures.push_back(arr);
                backtrack(arr, status, done, procedures);
                procedures.pop_back();
            }
            //recover
            arr[0] = 1 - arr[0];
            arr[i] = 1 - arr[i];
        }
    }
    //do not carry anything
    arr[0] = 1 - arr[0];
    if(!is_dangerous(arr)) {
        procedures.push_back(arr);
        backtrack(arr, status, done, procedures);
        procedures.pop_back();
    }
    arr[0] = 1 - arr[0];

    status.erase(current_status);
}

void solve() {
    vector<int> arr(4, 0);

    bool done = false;
    unordered_set<int> status;
    vector<vector<int>> procedures;
    procedures.push_back(arr);
    backtrack(arr, status, done, procedures);
}



int main() {
    solve();
}
