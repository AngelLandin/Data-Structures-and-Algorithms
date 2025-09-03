#include <iostream>
#include <vector>
#include <algorithm> // para sort
using namespace std;

vector<vector<int>> findPairs(vector<int>& nums, int start, int target) {
    vector<vector<int>> pairs;
    int left = start;
    int right = nums.size() - 1;

    while (left < right) {
        int op = nums.at(left) + nums.at(right);

        if (op == target) {
            pairs.push_back({nums.at(left), nums.at(right)});
            left++;
            while (left < right && nums.at(left) == nums.at(left - 1)) {
                left++;
            }
        } else if (op < target) {
            left++;
        } else {
            right--;
        }
    }
    return pairs;
}

vector<vector<int>> threeSums(vector<int> nums) {
    vector<vector<int>> triplets;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            return triplets; // ya no habrá más sumas = 0
        }

        if (i > 0 && nums.at(i) == nums.at(i - 1)) {
            continue; // evitar duplicados
        }

        vector<vector<int>> pairs = findPairs(nums, i + 1, -nums.at(i));

        for (int j = 0; j < pairs.size(); j++) {
            triplets.push_back({nums.at(i), pairs.at(j).at(0), pairs.at(j).at(1)});
        }
    }
    return triplets;
}

int main() {
    vector<int> nums = {0, -1, 2, -3, 1};

    vector<vector<int>> resultado = threeSums(nums);

    for (auto& trip : resultado) {
        for (auto& num : trip) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}
