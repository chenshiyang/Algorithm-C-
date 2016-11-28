#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> imap;
    vector<int> result;
    for(int i = 0; i != nums.size(); ++ i) {
        auto res = imap.find(target - nums[i]);
        if(res == imap.end()) {
            imap[nums[i]] = i;
        } else {
            result.push_back(res->second);
            result.push_back(i);
            return result;
        }
    }
    return result;
}

int main() {
    cout << "hello" << endl;
    vector<int> ivec = {2, 7, 11, 15};
    auto res = twoSum(ivec, 17);
    for(auto i : res) {
        cout << i << ends;
    }
}
