#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

string get_base(int num) {
    int base = 3;
    string res = "";
    while (num > 0) {
        res = to_string(num % base) + res;
        num /= base;
    }
    return res;
}

string math_expression(int k) {
    string base = get_base(k);
    vector<char> base_list(base.begin(), base.end());
    vector<char> mark(9);
    for (int i = 1; i < 10; i++) {
        int t = i - 1;
        i *= (-1);
        if (t < base_list.size()) {
            int element = base_list[i] - '0';
            if (element == 0) {
                mark[i] = ' ';
            } else if (element == 1) {
                mark[i] = '+';
            } else if (element == 2) {
                mark[i] = '-';
            }
        } else {
            mark[i] = ' ';
        }
    }
    string math_expression = "";
    for (int i = 0; i < 9; i++) {
        math_expression += to_string(9 - i) + mark[i];
    }
    math_expression += "0";
    return math_expression;
}

string solution(int expected_result) {
    map<int, vector<string>> dict_results;
    int quantity = pow(3, 9);
    for (int i = 0; i < quantity; i++) {
        string expression = math_expression(i);
        int result = eval(expression);
        if (dict_results.find(result) != dict_results.end()) {
            dict_results[result].push_back(expression);
        } else {
            dict_results[result] = {expression};
        }
    }
    if (dict_results.find(expected_result) != dict_results.end()) {
        return "Результат " + to_string(expected_result) + " дают выражения " + dict_results[expected_result];
    } else {
        return "К сожалению не существует выражения, результатом которого являлось бы число " + to_string(expected_result) + ".";
    }
}

int main() {
    cout << solution(200);
    return 0;
}