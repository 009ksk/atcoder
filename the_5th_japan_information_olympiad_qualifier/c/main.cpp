#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Dice{
private:
    int front;
    int back;
    int top;
    int bottom;
    int right;
    int left;
public:

    Dice(){
        front = 1;
        back = 6;
        top = 5;
        bottom = 2;
        right = 3;
        left = 4;
    }
    
    int get_front(){
        return front;
    }
    int get_back(){
        return back;
    }
    int get_top(){
        return top;
    }
    int get_bottom(){
        return bottom;
    }
    int get_right(){
        return right;
    }
    int get_left(){
        return left;
    }

    void roll_north(){
        int temp_top = front;
        int temp_front = bottom;
        int temp_bottom = back;
        int temp_back = top;

        top = temp_top;
        front = temp_front;
        bottom = temp_bottom;
        back = temp_back;
    }

    void roll_east(){
        int temp_right = front;
        int temp_left = back;
        int temp_back = right;
        int temp_front = left;

        front = temp_front;
        back = temp_back;
        right = temp_right;
        left = temp_left;
    }

    void roll_south(){
        int temp_bottom = front;
        int temp_top = back;
        int temp_front = top;
        int temp_back = bottom;

        front = temp_front;
        back = temp_back;
        top = temp_top;
        bottom = temp_bottom;
    }

    void roll_west(){
        int temp_left = front;
        int temp_front = right;
        int temp_back = left;
        int temp_right = back;

        left = temp_left;
        front = temp_front;
        back = temp_back;
        right = temp_right;
    }

    void roll_right(){
        int temp_right = top;
        int temp_bottom = right;
        int temp_left = bottom;
        int temp_top = left;

        right = temp_right;
        bottom = temp_bottom;
        left = temp_left;
        top = temp_top;
    }

    void roll_left(){
        int temp_top = right;
        int temp_left = top;
        int temp_bottom = left;
        int temp_right = bottom;

        top = temp_top;
        left = temp_left;
        bottom = temp_bottom;
        right = temp_right;
    }
};


vector<string> get_input(){
    vector<string> input_data;
    int input_num;
    cin >> input_num;

    for (int i = 0; i < input_num; i++){
        string temp_input;
        cin >> temp_input;
        input_data.push_back(temp_input);
    }

    return input_data;
}

int  roll_dice(vector<string> input_data){
    Dice dice;
    int result_num = 1;
    for (const string& input_item: input_data){
        if (input_item == "North"){
            dice.roll_north();
        }
        else if (input_item == "East"){
            dice.roll_east();
        }
        else if (input_item == "South"){
            dice.roll_south();
        }
        else if (input_item == "West"){
            dice.roll_west();
        }
        else if (input_item == "Right"){
            dice.roll_right();
        }
        else if (input_item == "Left"){
            dice.roll_left();
        }
        result_num += dice.get_front();
    }
    return result_num;

}

int main(){
    vector<string> input_data;
    
    input_data = get_input();
    
    cout << roll_dice(input_data) << endl;
    
    return 0;
}