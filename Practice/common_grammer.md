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

< 26 page















