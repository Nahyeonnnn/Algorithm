#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

bool is_expired(int term_size, string privacy, vector<int> &today_list) {
    stringstream ss(privacy);
    vector<int> priv_date;
    string cur;
    while (getline(ss, cur, '.')) {
        priv_date.push_back(stoi(cur));
    }

    priv_date[0] += term_size/12;
    priv_date[1] += term_size%12;
    if (priv_date[1] > 12) {
        priv_date[0]++;
        priv_date[1] -= 12;
    }

    priv_date[2]--;
    if (priv_date[2] <= 0) {
        priv_date[1]--;
        priv_date[2] = 28;
    }
    
    if (priv_date[0] < today_list[0])
        return true;
    else if (priv_date[0] > today_list[0])
        return false;

    if (priv_date[1] < today_list[1])
        return true;
    else if (priv_date[1] > today_list[1])
        return false;

    if (priv_date[2] < today_list[2])
        return true;

    return false;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> today_list;
    stringstream ss(today);
    string cur;

    while (getline(ss, cur, '.')) {
        today_list.push_back(stoi(cur));
    }

    map<char, int> term_list;
    for (string ele : terms) {
        stringstream strs(ele);
        string name, term;
        strs >> name >> term;
        term_list[ele[0]] = stoi(term);
    }

    for (int i=0; i<privacies.size(); i++) {
        stringstream strs(privacies[i]);
        string date, term;
        strs >> date >> term;
        if (is_expired(term_list[term[0]], date, today_list)) {
            answer.push_back(i+1);
        }
    }

    return answer;
}