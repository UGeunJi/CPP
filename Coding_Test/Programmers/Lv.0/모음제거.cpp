#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = "";
    my_string.erase(remove(my_string.begin(), my_string.end(), 'a'), my_string.end());
    my_string.erase(remove(my_string.begin(), my_string.end(), 'e'), my_string.end());
    my_string.erase(remove(my_string.begin(), my_string.end(), 'i'), my_string.end());
    my_string.erase(remove(my_string.begin(), my_string.end(), 'o'), my_string.end());
    my_string.erase(remove(my_string.begin(), my_string.end(), 'u'), my_string.end());
    return my_string;
}
