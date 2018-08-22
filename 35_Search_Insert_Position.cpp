class Solution {
public:
    
    int searchInsert(vector<int>& nums, int target) {
        int numSize = nums.size();
        int idx = numSize / 2;
        int maxIdx = numSize;
        
        if(target > nums.at(numSize - 1))
        {
            return numSize;
        }
        
        if(nums.size() > 0 && target < nums.at(0))
        {
            return 0;
        }
        
        for (;;)
        {
            int cur = nums.at(idx);
            if(cur == target)
            {
                return idx;
            }
            else if (cur > target)
            {
                maxIdx = idx;
                idx = idx/2;
            }
            else
            {
                if(target < nums.at(idx+ 1))
                {
                    return idx + 1;
                }
                idx = ((maxIdx - idx)/2) + idx;
            }
        }
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        int ret = Solution().searchInsert(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}