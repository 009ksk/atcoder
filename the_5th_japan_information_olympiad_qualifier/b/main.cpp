#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<pair<string, string>> get_conversion_table(){
    int input_num;
    cin >> input_num;
    vector<pair<string, string>> input_data;
    for (int i = 0; i < input_num; i++){
        string x, y;
        cin >> x >> y;
        input_data.push_back(make_pair(x, y));
    }
    return input_data;
}

vector<string> get_input(){
    int input_num;
    cin >> input_num;
    vector<string> input_data;
    for (int i = 0; i < input_num; i++){
        string x;
        cin >> x;
        input_data.push_back(x);
    }
    return input_data;
}

vector<string> convert_input(vector<string> input_data, vector<pair<string, string>> convertion_table){
    vector<string> result_data;
    for (const string& input_item: input_data){
        pair<bool, string> convert_info (false, "");
        for (const pair<string, string>& convertion_table_row: convertion_table){
            if (convertion_table_row.first == input_item){
                convert_info.first = true;
                convert_info.second = convertion_table_row.second;
            }
        }
        result_data.push_back(convert_info.first ? convert_info.second : input_item);
    }
    return result_data;
}

void output_data(vector<string> result_data){
    string result_string;
    for (const string& result_item: result_data){
        result_string += result_item;
    }
    cout << result_string << endl;
}

int main (){
    vector<pair<string, string>> convertion_table;
    vector<string> input_data;
    vector<string> result_data;
    convertion_table = get_conversion_table();
    input_data = get_input();
    result_data = convert_input(input_data, convertion_table);
    output_data(result_data);
    return 0;
}