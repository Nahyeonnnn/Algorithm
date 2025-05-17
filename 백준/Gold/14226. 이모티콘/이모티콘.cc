#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct set {
    int emoji;
    int clip;
    int time;
};

int main() {
    int s;
    cin >> s;
    vector<vector<bool>> visited(5001, vector<bool>(5001, false));

    //visited[임티][클립보드]
    visited[1][0] = true;//임티 한개, 클립보드x

    queue<set> Q;
    Q.push({1, 0, 0});

    int time = 0;

    while (!Q.empty()) {
        int emoji_c = Q.front().emoji;
        int clip_c = Q.front().clip;
        int time_c = Q.front().time;
        Q.pop();

        if (emoji_c == s) {
            time=time_c;
            break;
        }

        if (visited[emoji_c][emoji_c] == false) {
            visited[emoji_c][emoji_c] = true;
            Q.push({emoji_c, emoji_c, time_c+1});
        }

        if (emoji_c+clip_c < 5000 && 0 < clip_c && visited[emoji_c+clip_c][clip_c] == false) {
            visited[emoji_c+clip_c][clip_c]=true;
            Q.push({emoji_c+clip_c, clip_c, time_c+1});
        }

        if (1 < emoji_c && visited[emoji_c-1][clip_c]==false) {
            visited[emoji_c-1][clip_c]=true;
            Q.push({emoji_c-1, clip_c, time_c+1});
        }
    }

    cout<<time;

    return 0;
}