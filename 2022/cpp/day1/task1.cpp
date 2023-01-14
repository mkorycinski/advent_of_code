#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    int max_cal = 0;
    int curr_cal = 0;



    while (getline(cin, line)) {
        if (line.empty()) {
            if (curr_cal > max_cal){
                max_cal = curr_cal;
            }
            curr_cal = 0;
        }
        else {
            stringstream ss;
            int cal;
            ss << line;
            ss >> cal;
            curr_cal += cal;
        }

    }
    if (curr_cal > max_cal){
        max_cal = curr_cal;
    }
    cout << max_cal << endl;
    return 0;
}