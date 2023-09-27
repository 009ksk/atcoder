#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> get_input(){
    int input_num;
    cin >> input_num;
    vector<pair<int, int>> input_data;
    for (int i = 0; i < input_num; i++){
        int x, y;
        cin >> x >> y;
        input_data.push_back(make_pair(x, y));
    }
    return input_data;
}

pair<int, int> get_result(vector<pair<int, int>> input_data) {
    int result_a = 0;
    int result_b = 0;
    for (const pair<int, int>& item: input_data){
        if (item.first > item.second){
            result_a += item.first + item.second;
        }
        else if (item.first < item.second){
            result_b += item.first + item.second;
        }
        else{
            result_a += item.first;
            result_b += item.second;
        }
    }
    return make_pair(result_a, result_b);
}

void output_result(pair<int, int> result_data){
    cout << result_data.first << " " << result_data.second << endl;
}

int main(){
    vector<pair<int, int>> input_data;
    pair<int, int> result_data;
    input_data = get_input();
    result_data = get_result(input_data);
    output_result(result_data);
    return 0;
}