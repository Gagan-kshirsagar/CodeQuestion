vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;

    for(const string& str : strs){
        string key = str;
        sort(key.begin(), key.end());
        map[key].push_back(str);
    }

    vector<vector<string>> result;

    for(auto& pair : map){
        result.push_back(pair.second);
    }

    return result;
}