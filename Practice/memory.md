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

### ex)

```
/* #include <iostream>

typedef struct Animal {
	char name[30];   // 이름
	int age;         // 나이

	int health;      // 체력
	int food;        // 배부른 정도
	int clean;       // 깨끗한 정도
} Animal;

void create_animal(Animal* animal) {
	std::cout << "동물의 이름? ";
	std::cin >> animal->name;

	std::cout << "동물의 나이? ";
	std::cin >> animal->age;
	
	animal->health = 100;
	animal->food = 100;
	animal->clean = 100;
}

void play(Animal* animal) {
	animal->health += 10;
	animal->food -= 10;
	animal->clean -= 30;
}

void one_day_pass(Animal* animal) {
	//하루가 지나면
	animal->health -= 10;
	animal->food -= 30;
	animal->clean -= 20;
}

void show_stat(Animal* animal) {
	std::cout << animal->name << "의 상태" << std::endl;
	std::cout << "체력   : " << animal->health << std::endl;
	std::cout << "배부름 : " << animal->food << std::endl;
	std::cout << "청결   : " << animal->clean << std::endl;
}

int main() {
	Animal* list[10];
	int animal_num = 0;

	for (;;) {
		std::cout << "1. 동물 추가하기" << std::endl;
		std::cout << "2. 놀기" << std::endl;
		std::cout << "3. 상태 보기" << std::endl;

		int input;
		std::cin >> input;

		switch (input) {
			int play_with;
			case 1:
				list[animal_num] = new Animal;
				create_animal(list[animal_num]);

				animal_num++;
				break;
			case 2:
				std::cout << "누구랑 놀게? : ";
				std::cin >> play_with;

				if (play_with < animal_num) play(list[play_with]);
				
				break;
			case 3:
				std::cout << "누구 꺼 보게? : ";
				std::cin >> play_with;

				if (play_with < animal_num) show_stat(list[play_with]);
				break;
		}

		for (int i = 0; i != animal_num; i++) {
			one_day_pass(list[i]);
		}
	}
	for (int i = 0; i != animal_num; i++) {
		delete list[i];
	}
} */

#include <iostream> 
typedef struct Animal {
    char name[30]; 
    int age;
    
    int health;
    int food; 
    int clean; 
} Animal;

void create_animal(Animal *animal) { 
    std::cout << "동물의 이름? "; std::cin >> animal->name;
    std::cout << "동물의 나이? "; std::cin >> animal->age;
    
    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}

void play(Animal *animal) { 
    animal->health += 10; 
    animal->food -= 20; 
    animal->clean -= 30;
}

void one_day_pass(Animal *animal) {
    animal->health -= 10; 
    animal->food -= 30; 
    animal->clean -= 20;
}

void show_stat(Animal *animal) {
    std::cout << animal->name << "의 상태" << std::endl; 
    std::cout << "체력 : " << animal->health << std::endl; 
    std::cout << "배부름 : " << animal->food << std::endl;
    std::cout << "청결  : " << animal->clean << std::endl;
}

int main() {
    Animal *list[10]; 
    int animal_num = 0;

    for (;;) {
        std::cout << "1. 동물 추가하기" << std::endl; 
        std::cout << "2. 놀기 " << std::endl; 
        std::cout << "3. 상태 보기 " << std::endl;
        
        int input;

        std::cin >> input;
        
        switch (input) { 
            int play_with; 
            case 1:
                list[animal_num] = new Animal; 
                create_animal(list[animal_num]);
                
                animal_num++;
                break; 
            case 2:
                std::cout << "누구랑 놀게? : "; 
                std::cin >> play_with;

                if (play_with < animal_num) play(list[play_with]);
                break;
            case 3:
                std::cout << "누구껄 보게? : ";
                std::cin >> play_with;
                
                if (play_with < animal_num) show_stat(list[play_with]); 
                break;
        }
        for (int i = 0; i != animal_num; i++) { 
            one_day_pass(list[i]);
        } 
    }
    for (int i = 0; i != animal_num; i++) { 
        delete list[i];
    } 
}
```

```
해당 코드는 굉장히 비효율적임.
- 변수 하나라도 달라지면 구조체 코드 그대로 복사해서 변수 추가한 코드 써줘야함.

이 문제점을 해결하고자 함.
```


























