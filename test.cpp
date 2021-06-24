vector<int> test(int base, vector<int> nums) {
    vector<bool> visited(base, false);
    queue<int> q;

    for (int i = 0; i < nums.size(); i++) {
        nums[i] = nums[i] % base;
        q.push(nums[i]);
        visited[nums[i]] = true;
    }
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int i = 0; i < nums.size(); i++) {
            if (visited[(current + nums[i]) % base] == false) {
                visited[(current + nums[i]) % base] = true;
                q.push((current + nums[i]) % base);
            }
        }

    }

    vector<int> output;
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == true) output.push_back(i);
    }

    return output;
}



void test(vector<char> &s, vector<char> &t) {
        unordered_map<int, vector<int>> map;
        vector<vector<vector<int>>> substrInfo(t.size() + 1, vector<vector<int>>());
        // substrInfo = (s start index, s end index, t start index, t end index)
        // indices will all + 1
        vector<vector<int>> output;
        vector<bool> visited(t.size(), false);
        bool successful;
        
        // insert map, O(n)
        for (int i = 0; i < s.size(); i++) {
            if (map.count(s[i]) == 0) {
                map[s[i]] = vector<int>();
            }
            map[s[i]].push_back(i);
        }
        
        // find substrings, worst case O(m * n) 
        for (int i = 0; i < t.size(); i++) {
            if (map.count(t[i]) > 0) {
                // for all same characters
                for (int sPtr : map[t[i]]) {
                    // left
                    int currentS = sPtr;
                    int currentT = i;
                    while (currentS >= 0 && currentT < t.size() && s[currentS] == t[currentT]) {
                        currentS--;
                        currentT++;
                    }
                    vector<int> info;
                    info.push_back(sPtr + 1);
                    info.push_back(currentS + 2);
                    info.push_back(i);
                    info.push_back(currentT - 1);
                    substrInfo[abs(currentS - sPtr)].push_back(info);
                    
                    // right
                    currentS = sPtr;
                    currentT = i;
                    while (currentS < s.size() && currentT < t.size() && s[currentS] == t[currentT]) {
                        currentS++;
                        currentT++;
                    }
                    info = vector<int>();
                    info.push_back(sPtr + 1);
                    info.push_back(currentS);
                    info.push_back(i);
                    info.push_back(currentT - 1);
                    substrInfo[abs(currentS - sPtr)].push_back(info);
                }
            }
        }
        
        // output, O(n)
        for (int i = substrInfo.size() - 1; i > 0; i--) {
            if (substrInfo[i].size() != 0) {
                for (int j = 0; j < substrInfo[i].size(); j++) {
                    successful = true;
                    for (int k = substrInfo[i][j][2]; k <= substrInfo[i][j][3]; k++) {
                        // fail
                        if (visited[k] == true) {
                            successful = false;
                        }
                    }
                    if (successful) {
                        vector<int> substr;
                        substr.push_back(substrInfo[i][j][0]);
                        substr.push_back(substrInfo[i][j][1]);
                        output.push_back(substr);
                        for (int k = substrInfo[i][j][2]; k <= substrInfo[i][j][3]; k++) {
                            visited[k] = true;
                        }
                    }
                }
            }
        }
        if (output.size() != 0) {
            for (int i = 0; i < output.size(); i++) {
                cout << "[" << output[i][0] << ", " << output[i][1] << "]" << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }
