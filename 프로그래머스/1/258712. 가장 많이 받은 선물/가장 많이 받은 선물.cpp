#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cvt_num(string &s, vector<string> &friends) {
    int r = -1;
    for (int i=0; i<friends.size(); i++) {
        if (s == friends[i]) {
            r = i;
        }
    }
    return r;
}

int solution(vector<string> friends, vector<string> gifts) {
    vector<vector<int>> g_list(friends.size(), vector<int>(friends.size(), 0));
    vector<int> g_jisoo(friends.size(), 0);
    
    for (int i=0; i<gifts.size(); i++) {
        for (int j=0; j<gifts[i].size(); j++) {
            if (gifts[i][j] == ' ') {
                string a = gifts[i].substr(0, j);
                string b = gifts[i].substr(j + 1);
                int a_num = cvt_num(a, friends);
                int b_num = cvt_num(b, friends);
                
                g_list[a_num][b_num] += 1;
            }
        }
    }
    
    //선물지수 계산
    for (int i=0; i<friends.size(); i++) {
        int give = 0;
        int receive = 0;
        
        for (int j=0; j<friends.size(); j++) {
            give += g_list[i][j];
        }     
        for (int j=0; j<friends.size(); j++) {
            receive += g_list[j][i];
        }
        
        g_jisoo[i] = give - receive;
    }
    

    
    //가장 선물을 많이 받는 경우
    int max_g = 0;
    for (int i=0; i<friends.size(); i++) {
        int g_cnt =0;
        for (int j=0; j<friends.size(); j++) {
            if (i == j)
                continue;
            
            if (g_list[i][j] > g_list[j][i])
                g_cnt++;
            else if (g_list[i][j] == g_list[j][i]) {
                if (g_jisoo[i] > g_jisoo[j])
                    g_cnt++;
            }
        }
        
        if (max_g < g_cnt)
            max_g = g_cnt;
    }
    
    
    // for (int i=0; i<g_list.size(); i++) {
    //     for (int j=0; j<g_list[i].size(); j++) {
    //         cout << g_list[i][j] << " ";
    //     }
    //     cout <<"\n";
    // }
    
    return max_g;
    
}