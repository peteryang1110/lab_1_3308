void helper(int &base, vector<int> &nums, vector<bool> &visited, int current, int start) {
    for (int i = start; i < nums.size(); i++) {
        if (visited[(current + nums[i]) % base] == false) {
            visited[(current + nums[i]) % base] = true;
            helper(base, nums, visited, (current + nums[i]) % base, i);
        }
    }
}

vector<int> test(int &base, vector<int> &nums) {
    vector<bool> visited(base, false);
    for (int i = 0; i < nums.size(); i++) {
        nums[i] %= base;
    }
    helper(base, nums, visited, 0, 0);
    vector<int> output;
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == true) {
            output.push_back(i);
        }
    }
    return output;
}
