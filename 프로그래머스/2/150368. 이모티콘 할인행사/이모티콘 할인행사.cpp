#include <map>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

struct node {
    int emo_num;
    int rate;
};

void cal_member_sales(const vector<int> &selected_rates, const vector<vector<int>> &users, const vector<map<int, int>> &discounted, int &member_cnt, int& sales) {

    for (int i=0; i<users.size(); i++) {
        int user_sale=0;
        for (int j=0; j<selected_rates.size(); j++) {
            if (users[i][0] <= selected_rates[j])
                user_sale += discounted[j].at(selected_rates[j]);
        }
        if (user_sale >= users[i][1])
            member_cnt++;
        else
            sales += user_sale;
    }

}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<int> rates = {10, 20, 30, 40};
    vector<map<int, int>> discounted(emoticons.size(), map<int,int>());

    for (int i=0; i<emoticons.size(); i++) {
        for (int rate : rates) {
            discounted[i][rate] = emoticons[i] * (100-rate)/100;
        }
    }

    stack<node> st;
    vector<int> selected_rates(emoticons.size());
    map<int, vector<int>> member_sales_list;
    st.push({0, rates[0]});
    st.push({0, rates[1]});
    st.push({0, rates[2]});
    st.push({0, rates[3]});
    while (!st.empty()) {
        node cur = st.top();
        st.pop();
        selected_rates[cur.emo_num] = cur.rate;

        if (cur.emo_num == emoticons.size() - 1) {
            int member_cnt=0;
            int sales=0;
            cal_member_sales(selected_rates, users, discounted, member_cnt, sales);
            member_sales_list[member_cnt].push_back(sales);
            continue;
        }

        
        for (int i=0; i<rates.size(); i++) {
            st.push({cur.emo_num + 1, rates[i]});
        }
    }

    answer.push_back(member_sales_list.rbegin()->first);
    int max_sale=0;
    for (int sale : member_sales_list[answer[0]]) {
        if (max_sale < sale)
            max_sale = sale;
    }
    answer.push_back(max_sale);

    return answer;
}