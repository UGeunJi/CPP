# 스타크래프트 만들기

#### 이 강좌 자료의 저자의 목표가 스타크래프트의 뼈대를 차근차근 만들어보는 거라고 한다?


### 마린 생성 및 attack

```
#include <iostream>

class Marine {
    int hp;                      // 마린체력
    int coord_x, coord_y;        // 마린 위치
    int damage;                  // 공격력
    bool is_dead;

    public:
        Marine();                     // 기본 생성자
        Marine(int x, int y);         // x, y 좌표에 마린 생성

    int attack();                           // 데미지를 리턴
    void be_attacked(int damage_earn);      // 입는 데미지
    void move(int x, int y);                // 새로운 위치

    void show_status();                     // 상태를 보여줌
};

Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}

Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    Marine marine1(2, 3);
    Marine marine2(3, 5);

    marine1.show_status();
    marine2.show_status();

    std::cout << " 마린1이 마린2를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}
```

![image](https://github.com/UGeunJi/CPP/assets/84713532/0e4d49f1-c22c-4fc3-9ef4-012094b01f0a)


### 마린이 여러 마리일 땐??

#### 배열을 활용해서 처리!

```
#include <iostream>

class Marine {
    int hp;                      // 마린체력
    int coord_x, coord_y;        // 마린 위치
    int damage;                  // 공격력
    bool is_dead;

    public:
        Marine();                     // 기본 생성자
        Marine(int x, int y);         // x, y 좌표에 마린 생성

    int attack();                           // 데미지를 리턴
    void be_attacked(int damage_earn);      // 입는 데미지
    void move(int x, int y);                // 새로운 위치

    void show_status();                     // 상태를 보여줌
};

Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}

Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    Marine* marines[100];

    marines[0] = new Marine(2, 3);
    marines[1] = new Marine(3, 5);

    marines[0]->show_status();
    marines[1]->show_status();

    std::cout << " 마린1이 마린2를 공격! " << std::endl;

    marines[0]->be_attacked(marines[1]->attack());
    
    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];
    delete marines[1];
}
```

```
- 포인터를 가리키는 배열이기 때문에 method를 호출할 때 '.'이 아니라 '->'사용해줘야 함.
- 동적으로 할당한(new) 메모리는 언제나 delete로 해제해주어야 함.
```

### 마린의 이름 추가

```
// 마린 이름 만들기
#include <string.h>

#include <iostream>

class Marine {
    int hp;                      // 마린체력
    int coord_x, coord_y;        // 마린 위치
    int damage;                  // 공격력
    bool is_dead;
    char* name;

    public:
        Marine();                                              // 기본 생성자
        Marine(int x, int y, const char* marine_name);         // 이름까지 지정
        Marine(int x, int y);                                  // x, y 좌표에 마린 생성

    int attack();                           // 데미지를 리턴
    void be_attacked(int damage_earn);      // 입는 데미지
    void move(int x, int y);                // 새로운 위치

    void show_status();                     // 상태를 보여줌
};

Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name = NULL;
}

Marine::Marine(int x, int y, const char* marine_name) {
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);

    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}

Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
    name = NULL;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
    std::cout << " *** Marine: " << name << "***" << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    Marine* marines[100];

    marines[0] = new Marine(2, 3, "Marine 2");
    marines[1] = new Marine(1, 5, "Marine 1");

    marines[0]->show_status();
    marines[1]->show_status();

    std::cout << " 마린1이 마린2를 공격! " << std::endl;

    marines[0]->be_attacked(marines[1]->attack());
    
    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];
    delete marines[1];
}
```

![image](https://github.com/UGeunJi/CPP/assets/84713532/cf5c6ae2-5a02-43f6-a606-8680743872ff)

#### name을 동적으로 생성하여 문자열을 복사했는데, 이렇게 할당된 char 배열은 delete되지 않는다.
#### 이로 인해 메모리 누수(Memory Leak)이 발생함.
#### 따라서 소멸자 함수를 호출해야 함

```
(생략)

~Marine();

(생략)

Marine::~Marine() {
    std::cout << name << " 의 소멸자 호출! " << std::endl;
    if (name != NULL) {
        deletep[] name;
    }
}

(생략)
```

![image](https://github.com/UGeunJi/CPP/assets/84713532/17fd1e30-1417-4705-a626-bba6ae407227)


### 소멸자 호출 확인

```
// 소멸자 호출 확인하기
#include <string.h>
#include <iostream>

class Test {
    char c;

    public:
        Test(char _c) {
            c = _c;
            std::cout << "생성자 호출" << c << std::endl;
        }
        ~Test() { std::cout << "소멸자 호출" << c << std::endl; }
};

void simple_function() {Test b('b'); }

int main() {
    Test a('a');
    simple_function();
}
```

```
생성자 호출a
생성자 호출b
소멸자 호출b
소멸자 호출a
```

#### 실행결과가 위와 같은데, 함수 a가 먼저 실행되고 b에 대한 함수가 실행되었고, b에 대한 함수가 모두 마무리 되고, a에 대한 함수가 마무리 되었기 떄문이다.
#### main function start -> simple_function start -> simple_function end -> main function end

~ page 98











