#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int student_num, friend_pair_num;
int result = 0;

void group_maker(vector<pair<int, int> > &friend_store, vector<pair<int, int> > &pair_store, int check_num, int index){
    // 확인하는 케이스(총 member수가 구해야하는 것과 같을 때 전체 케이스를 만족하는지 체크)
    if(check_num == 0){
        vector<int> check_value(student_num, 0);
        for(int i = 0; i < pair_store.size(); i++){
            check_value[pair_store[i].first] = 1;
            check_value[pair_store[i].second] = 1;
        }
        for(int i = 0; i < student_num; i++){
            if(check_value[i] == 0) return; // 아닌 케이스 존재
        }
        result += 1;
        return;// 해당하는 케이스 find
    }
    int picked = bool(index == 0 && pair_store.empty()) ? 0 : index + 1;

    for(int i = picked; i < friend_store.size(); i++){
        pair_store.push_back(friend_store[i]);
        group_maker(friend_store, pair_store, check_num - 1, i);
        pair_store.pop_back();
    }
    return;
}

int main(void){
    
    int test_case_num;
    cin >> test_case_num;

    for(int i = 0; i < test_case_num; i++){
        vector<pair<int, int> > friend_store;
        vector<pair<int, int> > pair_store;
        cin >> student_num >> friend_pair_num;
        
        result = 0;
        for(int j = 0; j < friend_pair_num; j++){
            int front, back;
            cin >> front >> back;
            friend_store.push_back(make_pair(front,back));
        } // Allocate friend
        group_maker(friend_store, pair_store, student_num / 2, 0);
        cout << result << "\n";
    }
    return 0;
}