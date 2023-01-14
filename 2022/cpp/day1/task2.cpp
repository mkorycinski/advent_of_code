#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <tuple>

using namespace std;

tuple <int, int> minArrValue(int arr[]) {
    int n = sizeof(arr) / sizeof(arr[0]);
    int min_val = arr[0];
    int index = -1;
    
    for (int i=0;i<n+1;i++){
        min_val = min(min_val, arr[i]);
    }
    index = find(arr, arr+n, min_val) - arr;
    return make_tuple(index, min_val);

}


int main() {
    string line;
    int curr_cal = 0;
    int elves_num = 3;
    int elves[elves_num] = {10, 20, 30};
    int ind, minval;

    while (getline(cin, line)) {
        if (line.empty()) {
            tie(ind, minval) = minArrValue(elves);
            
            if (curr_cal > minval){
                elves[ind] = curr_cal;
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

    tie(ind, minval) = minArrValue(elves);

    if (curr_cal > minval){
        
        if (curr_cal > minval){ 
            elves[ind] = curr_cal;
        }
    }

    int total_cal = 0;
    for (int i=0;i<elves_num;i++){
        total_cal += elves[i];
    }
    cout << total_cal << endl;
    return 0;
}