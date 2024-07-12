#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;
    int rest = 0;
    
    answer += hp / 5;
    rest = hp % 5;
    answer += rest / 3;
    rest %= 3;
    answer += rest;
    return answer;
}
