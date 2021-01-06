#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int height, width;
int calculated_result;
int check_store[4][3][2] = {
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {0, 1}, {1, 0}},
    {{0, 0}, {1, 0}, {1, -1}}
};

// 블럭 넣어야하는 갯수 체크
// 3의 배수가 아니면 -1, 3의 배우시면 해당하는 갯수
int pair_count(vector<string> &data_store){
    int result = 0;
    for(int i = 0; i< height; i++){
        for(int j = 0; j < width; j++){
            if(data_store[i][j] == '.') result += 1;
        }
    }
    if(result % 3 != 0) return -1;
    else return result / 3;
}

pair<int, int> find_top_left(vector<string> &data_store){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(data_store[i][j] == '.'){
                return make_pair(i, j);
            }
        }
    }
}

// 비어있으면 1 출럭, 범위 밗이거나 차있으면 0 출력
int blank_check(int x, int y, vector<string> &data_store){
    if(x < 0 || x >= height || y < 0 || y >= width) return 0;
    else{
        if(data_store[x][y] == '.') return 1;
        else return 0;
    }
}

// 해당 check_value가 유효한 값을 지니는지 체크하는 함수
// 1 이면 유효, 0이면 무효
int case_check(int x, int y, vector<string> &data_store, int check_value){
    for(int i = 0; i < 3; i++){
        int dx = x + check_store[check_value][i][0];
        int dy = y + check_store[check_value][i][1];
        if(blank_check(dx, dy, data_store) == 0) return 0;
    }
    return 1;
}

void make_not_blank(int x, int y, vector<string> &data_store, int check_value){
    for(int i = 0; i< 3; i++){
        int dx = x + check_store[check_value][i][0];
        int dy = y + check_store[check_value][i][1];
        data_store[dx][dy] = '#';
    }
    return;
}

void make_blank(int x, int y, vector<string> &data_store, int check_value){
    for(int i = 0; i< 3; i++){
        int dx = x + check_store[check_value][i][0];
        int dy = y + check_store[check_value][i][1];
        data_store[dx][dy] = '.';
    }
    return;
}

void checker_function(vector<string> &data_store, int pair_num){
    if(pair_num == 0){
        calculated_result += 1;
        return;
    }// 목표하는 값 도달
    else{
        pair<int, int> top_left_cor = find_top_left(data_store);
        int pair_check[4] = {0};
        for(int i = 0; i < 4; i ++){
            pair_check[i] = case_check(top_left_cor.first, top_left_cor.second, data_store, i);
        }
        // 중간에 만족하는 상황이 없는 것
        if(pair_check[0] == 0 && pair_check[1] == 0 && pair_check[2] == 0 && pair_check[3] == 0){
            return;
        } 
        else{
            for(int i = 0; i < 4; i++){
                // 만족하는 케이스일 때
                if(pair_check[i] == 1){
                    make_not_blank(top_left_cor.first, top_left_cor.second, data_store, i);
                    checker_function(data_store, pair_num -1);
                    make_blank(top_left_cor.first, top_left_cor.second, data_store, i);
                }
            }
            return;
        }
    }
}



int main(void){
    int test_case_num;
    cin >> test_case_num;

    for(int i = 0; i < test_case_num; i++){
        cin >> height >> width;
        vector<string> data_store;
        for(int i = 0; i < height; i++){
            string temp;
            cin >> temp;
            data_store.push_back(temp);
        }// data_store

        int pair_num = pair_count(data_store);

        // 만족하는 상황이 아얘 안되는 경우
        if(pair_num == -1){
            cout << "0\n";
            continue;
        }
        else{
            calculated_result = 0;
            checker_function(data_store, pair_num);
            cout << calculated_result << "\n";
        }
    }
    return 0;
}