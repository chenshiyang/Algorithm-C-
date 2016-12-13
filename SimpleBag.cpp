#include<iostream>
#include<vector>

using namespace std;

void backtrack(const vector<int> &array, vector<int> &stack, int target, int current_sum, size_t index, vector<vector<int>> &result) {
    //get a solution
    if(target == current_sum) {
        result.push_back(stack);
        return;
    }

    //no item left
    if(index == array.size()) {
        return;
    }

    //don't use array[index]
    backtrack(array, stack, target, current_sum, index + 1, result);

    //use array[index] if possible
    if(current_sum + array[index] <= target) {//if still have enough space
        current_sum += array[index];
        stack.push_back(array[index]);
        backtrack(array, stack, target, current_sum, index + 1, result);
        stack.pop_back();
    }
}

void solve(const vector<int> &array, int target) {
    if(target <= 0) {
        return;
    }

    vector<int> stack;
    int current_sum = 0;
    vector<vector<int>> result;
    backtrack(array, stack, target, current_sum, 0, result);
    for(auto v : result) {
        for(auto i : v) {
            cout << i << ends;
        }
        cout << endl;
    }
}

int main() {
    int target = 10;
    vector<int> array = {1, 8, 4, 3, 5, 2};
    solve(array, target);
}
