```
예에에에전에 C 해봤다가 cpp을 시작해보고자 한다..
뭔가 기억이 나는 듯한 느낌
```

## hello, world!!

#### 실행은 vscode에서 한다. 서버에서 실행시키는 게 지금 알고 있는 방법으론 제일 편한 것 같다.

```
#include <iostream>

int main(){
  std::cout << "Hello, World!!" << std:endl;
  return 0;
}
```

## namespace

#### spacename이라는 개념이 있다. 호출에 관련한 내용이다.

```
#include <iostream>
using namespace;

int main() {
  cout << "Hello, World!!" << endl;
  return 0;
}
```

## 이름 없는 이룸 공간

```
#include <iostream>

namespace {
// 이 함수는 이 파일 안에서만 사용 가능
// static int OnlyInThisFile() 과 동일
int OnlyInThisFile() {}

// static int x 와 동일
int only_in_this_file = 0;
} // namespace

int main() {
  OnlyInThisFile();
  only_in_this_file = 3;
}

---

## 문제 2

```
#include <iostream>

int main() {
  std::cout << "Hi" << std:endl;
            << "My name is "
            << "Psi" << std:endl;
  return 0;
}
```
