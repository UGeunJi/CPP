# C++의 참조자 (Reference)

```
#include <iostream>
  int change_val(int *p) {
    *p = 3;
  return 0;
  }

int main() {
  int number = 5;
  std::cout << number << std::endl;
  change_val(&number);
  std::cout << number << std::endl;
  }
```

```
#include <iostream>


int main() {
    int a = 3;
    int& another_a = a;
    
    another_a = 5;
    std::cout << "a: " << a << std::endl;
    std::cout << "another_a: " << another_a << std::endl;
    
    return 0;
}
```

```
#include <iostream>

int change_val(int &p) {
    p = 3;
    
    return 0;
}

int main() {
    int number = 5;
    
    std::cout << number << std::endl;
    change_val(number);
    std::cout << number << std::endl;
    
    return 0;
}
```

## 여러가지 참조자 예시들

```
#include <iostream>

int main() {
    int x;
    int& y = x;
    int& z = y;
    
    x = 1;
    std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;
    
    y = 2;
    std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;
    
    z = 3;
    std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;
}
```

![image](https://github.com/UGeunJi/CPP/assets/84713532/e5f62414-92af-475d-b6e0-3aec5af0da97)

## 배열상의 reference

```
#include <iostream>

int main() {
    int arr[3] = {1, 2, 3};
    int(&ref)[3] = arr;
    
    ref[0] = 2;
    ref[1] = 3;
    ref[2] = 1;
    
    std::cout << arr[0] << arr[1] << arr[2] << std::endl;
    return 0;
}
```

![image](https://github.com/UGeunJi/CPP/assets/84713532/77786adf-d94f-46b1-83d3-2fab43bf4a17)
