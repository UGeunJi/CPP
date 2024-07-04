## new, delete

```
#include <iostream>

int main() {
	int* p = new int;
	*p = 10;

	std::cout << *p << std::endl;

	delete p;
	return 0;
}

```
int* p = int new;

int* pointer = int new;

int new == int만큼의 공간을 할당

할당된 공간에 *pointer = 10을 통해 값 입력

delete p;로 마무리

delete는 new로 할당된 공간만 해제 가능.
```

```
#include <iostream>

int main() {
  int a = 5;

  delete &a;

  return 0;
```

#### 오류 발생

---

## new로 배열 할당하기

```
#include <iostream>

int main() {
	int arr_size;
	std::cout << "array size: ";
	std::cin >> arr_size;
	int* list = new int[arr_size];

	for (int i = 0; i < arr_size; i++) {
		std::cin >> list[i];
	}

	for (int i = 0; i < arr_size; i++) {
		std::cout << i << "th element of list: " << list[i] << std::endl;
	}
	delete[] list;
	return 0;
}
```

![image](https://github.com/UGeunJi/CPP/assets/84713532/d5ea4070-93a8-4b22-87ca-c917b8eec7f1)


#### C++은 변수 선언 범위는 괄호 내이다. 매번 선언해줘야 한다.


~ page 51






























