# Define variables

## 변수의 정의 
```
#include <iostream>

int main() {
  int i;
  char c;
  double d;
  float f;

  return 0;
}
```

## 배열, 포인터

```
int arr[10];
int *parr = arr;

int i;
int *pi = &i;
```

## 반복문

```
#include <iostream>

int main() {
  int i;

  for (i = 0; i < 10; i++) {
    std::cout << i << std::endl;
  }
  return 0;
}
```

```
#include <iostream>

int main() {
  int i, sum = 0;

  for (i = 0; i < 10; i++) {
    sum += i;
  }
  std::cout << "합은: " << sum << std::endl;
  return 0;
}
```

```
#include <iostream>

int main() {
  sum = 0;

  for (int i = 0; i < 10; i++) {
    sum += i;
  }
  std::cout << "합은: " << sum << std::endl;
  return 0;
}
```

```
#include <iostream>

int main() {
  sum = 0;

  while (i < 10) {
    sum += 1;
    i++;
  }
  std::cout << "합은: " << sum << std::endl;
  return 0;
}
```

---

```
/* 행운의 숫자 맞추기 */
#include <iostream>

int main() {
    int lucky_number =3;
    std::cout << "내 비밀 수를 맞춰 보세요~" << std::endl;
    
    int user_input; // 사용자 입력
    
    while (1) {
        std::cout << "입력: ";
        std::cin >> user_input;
        if (lucky_number == user_input) {
            std::cout << "맞추셨습니다~~" << std::endl;
            break;
        } else {
            std::cout << "다시 생각해보세요~" << std::endl;
        }
    }
    return 0;
}
```

```
cpp은 
- 조건문이나 반복문의 범위를 {} 괄호를 통해 인위적으로 묶어줌.
- 각 줄마다 ;를 통해 마무리 해줌
- iostream 안에 있는 하나의 객체로, character output, character input으로 cout과 cin으로 나뉘고,
  입력과 출력으로 구분되어 << / >>도 구분해서 사용한다.
```

```
// switch 문 이용하기
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
    int user_input;
    cout << "저의 정보를 표시해줍니다" << endl;
    cout << "1. 이름" << endl;
    cout << "2. 나이" << endl;
    cout << "3. 성별" << endl;
    cin >> user_input;
    
    switch (user_input) {
        case 1:
            cout << "Jug!" << endl;
            break;
            
        case 2:
            cout << "99살" << endl;
            break;
            
        case 3:
            cout << "남자" << endl;
            break;
            
        case 4:
            cout << "궁금한 게 없군요~" << endl;
            break;
    }
    return 0;
}
```

![image](https://github.com/UGeunJi/CPP/assets/84713532/22de4bde-fe4a-4fab-869e-715f73c0cffd)
