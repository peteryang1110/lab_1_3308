void helper(int &base, vector<int> &nums, vector<bool> &visited, int current, int start) {
    for (int i = start; i < nums.size(); i++) {
        int next = (current + nums[i]) % base;
        if (visited[next] == false) {
            visited[next] = true;
            helper(base, nums, visited, next, i);
        }
    }
}

vector<int> test(int &base, vector<int> &nums) {
    vector<bool> visited(base, false);
    for (int i = 0; i < nums.size(); i++) {
        visited[nums[i] % base] = true;
    }
    vector<int> newNums;
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == true) newNums.push_back(i);
    }
    for (int i = 0; i < newNums.size(); i++) {
        helper(base, newNums, visited, newNums[i], i);
    }
    vector<int> output;
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == true) {
            output.push_back(i);
        }
    }
    return output;
}
