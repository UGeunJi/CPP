#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    reverse(my_string.begin(), my_string.end());
    return my_string;
}

/* ****************************************************************************************************** */

#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    int n = my_string.size();
    for (int i = 0; i < n / 2; i++) {
        char temp = my_string[i];
        my_string[i] = my_string[n - 1 - i];  // 뒤의 문자를 앞으로
        my_string[n - 1 - i] = temp;          // 앞의 문자를 뒤로
    }
    return my_string;
}
