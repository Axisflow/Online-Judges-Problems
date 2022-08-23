/*
計算五則運算式的結果，包含加、減、乘、除、餘
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

string toString(int _in_) {
    if(_in_ == 0)
        return "0";

    string result = "";
    bool neg = false;

    if(_in_ < 0) {
        _in_ = -_in_;
        neg = true;
    }

    while(_in_) {
        result = (char)(_in_ % 10 + '0') + result;
        _in_ /= 10;
    }

    if(neg)
        result = '-' + result;

    return result;
}

int toInt(string _in_) {
    int result = 0, tmp = _in_.size(), i = 0;
    bool neg = false;

    if(_in_[0] == '-') {
        i++;
        neg = true;
    }

    for(; i < tmp; i++) {
        result = result * 10 + _in_[i] - '0';
    }

    return neg ? -result : result;
}

bool isNum(char _in_) {
    if(_in_ < '0' || _in_ > '9')
        return false;
    return true;
}

bool isNum(string _in_) {
    for(int i = 0; i < _in_.size(); i++) {
        if(_in_[i] < '0' || _in_[i] > '9')
            return false;
    }
    return true;
}

string eval(string _code_) {
    vector<string> input;
    string tmp;
    int sizeTemp, numTemp, quotNum, result = 0;

    // Process brackets and break up the input
    if(_code_[0] == '-')
        _code_ = '0' + _code_;
    sizeTemp = _code_.size();

    for(int i = 0; i < sizeTemp; i++) {
        if(isNum(_code_[i])) {
            if(input.size() != 0 && isNum(input.back())) {
                tmp = input.back() + _code_[i];
                input.pop_back();
                input.push_back(tmp);
            } else {
                tmp = _code_[i];
                input.push_back(tmp);
            }
        } else if(_code_[i] == '+' || _code_[i] == '-' || _code_[i] == '*' || _code_[i] == '/' || _code_[i] == '%') {
            tmp = _code_[i];
            input.push_back(tmp);
        } else if(_code_[i] == '(') {
            tmp = "";
            quotNum = 1;

            while(true) {
                i++;
                if (_code_[i] == '(')
                    quotNum++;
                else if (_code_[i] == ')')
                    quotNum--;

                if (quotNum == 0)
                    break;
                tmp += _code_[i];
            }

            input.push_back(eval(tmp));
        }
    }

    // Process */%
    vector<int> num_in;
    vector<char> operator_in;
    sizeTemp = input.size();

    for(int i = 0; i < sizeTemp; i++) {
        if(i % 2) {
            tmp = input[i];

            if(tmp == "*" || tmp == "/" || tmp == "%") {
                i++;
                numTemp = num_in.back();
                num_in.pop_back();
                if(tmp == "*") {
                    num_in.push_back(numTemp * toInt(input[i]));
                } else if(tmp == "/") {
                    num_in.push_back(numTemp / toInt(input[i]));
                } else if(tmp == "%") {
                    num_in.push_back(numTemp % toInt(input[i]));
                }
            } else {
                operator_in.push_back(input[i][0]);
            }
        } else {
            num_in.push_back(toInt(input[i]));
        }
    }

    // Process +-
    sizeTemp = operator_in.size();
    result = num_in[0];

    for (int i = 0; i < sizeTemp; i++) {
        tmp = operator_in[i];

        if(tmp == "+") {
            result += num_in[i + 1];
        } else if(tmp == "-") {
            result -= num_in[i + 1];
        }
    }

    return toString(result);
}

int main() {
    string form;
    while (getline(cin, form)) {
        cout << eval(form) << '\n';
    }

    return 0;
}
