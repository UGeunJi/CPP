#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    if (price >= 500000) {
        price -= price * 0.2;
    } else if (price >= 300000 && price <= 499999) {
        price -= price * 0.1;
    } else if (price >= 100000 && price <= 299999) {
        price -= price * 0.05;
    } else {
        price = price;
    }

    return price;
}
