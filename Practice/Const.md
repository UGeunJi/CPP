## 생성자의 초기화 리스트 (initializer list)

```
#include <iostream>

class Marine {
    int hp;                          // 마린 체력
    int coord_x, coord_y;            // 마린 위치
    int damage;                      // 공격력
    bool is_dead;

    public:
        Marine();                    // 기본 생성자
        Marine(int x, int y_);       // x, y 좌표에 마린 생성

        int attack();                            // 데미지를 리턴한다.
        void be_attacked(int damage_earn);       // 입는 데미지
        void move(int x, int y);                 // 새로운 위치

        void show_status();          // 상태를 보여준다.
};

Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {}

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), damage(5), is_dead(false) {}

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
    std::cout << "Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    Marine marine1(2, 3);
    Marine marine2(3, 5);

    marine1.show_status();
    marine2.show_status();
}
```

#### 특이하게 달라진 점은 생성자의 초기화 방식이 달라졌다는 것.

```
** 이전 방식 **

Marine::Marine() {
  hp = 50;
  coord_x = coord_y = 0;
  damage = 5;
  is_dead = false;
}

------------------------------------------------------------------------

** 생성자 초기화 리스트 방식 **

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), damage(5), is_dead(false) {}
```

#### 둘의 차이가 뭘까?

초기화 리스트를 사용한 버전은 생성과 초기화를 동시에 하는 것이다. <br>
이 말이 의미하는 건 

```
** 초기화 리스트 **
int a = 10;

** 이전 버전 **
int a;
a = 10;
```

#### 작업을 이중적으로 하지 않고 동시에 실행하는 것을 의미 -> 효율적임.

#### 이 방식을 사용하는 이유는 상수와 레퍼런스들은 모두 생성과 동시에 초기화 되어야 하기 때문.

```
const int a;
a = 3;

int& ref;   
ref = c;  
```

#### 따라서 class 내부에 레퍼런스 변수나 상수를 넣고 싶다면 이들을 생성자에서 무조건 초기화 리스트를 사용해서 초기화 시켜주어야만 함.

```
#include <iostream>

class Marine {
    int hp;                          // 마린 체력
    int coord_x, coord_y;            // 마린 위치
    bool is_dead;

    const int default_damage;        // 기본 공격력

    public:
        Marine();                    // 기본 생성자
        Marine(int x, int y_);       // x, y 좌표에 마린 생성

        int attack();                            // 데미지를 리턴한다.
        void be_attacked(int damage_earn);       // 입는 데미지
        void move(int x, int y);                 // 새로운 위치

        void show_status();          // 상태를 보여준다.
};

Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << "Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    Marine marine1(2, 3);
    Marine marine2(3, 5);

    marine1.show_status();
    marine2.show_status();

    std::cout << "마린1이 마린2를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}
```

### default_damage를 변경하는 명령을 넣는 경우

```
#include <iostream>

class Marine {
    int hp;                          // 마린 체력
    int coord_x, coord_y;            // 마린 위치
    bool is_dead;

    const int default_damage;        // 기본 공격력

    public:
        Marine();                    // 기본 생성자
        Marine(int x, int y);       // x, y 좌표에 마린 생성
        Marine(int x, int y, int default_damage);

        int attack();                            // 데미지를 리턴한다.
        void be_attacked(int damage_earn);       // 입는 데미지
        void move(int x, int y);                 // 새로운 위치

        void show_status();          // 상태를 보여준다.
};

Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y, int default_damage) : coord_x(x), coord_y(y), hp(50), default_damage(default_damage), is_dead(false) {}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << "Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    Marine marine1(2, 3, 10);
    Marine marine2(3, 5, 10);

    marine1.show_status();
    marine2.show_status();

    std::cout << "마린1이 마린2를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}
```

#### defaut_damage를 5에서 10으로 변경했지만 오류는 발생하지 않았고, damage를 10이나 입은 marine2를 확인할 수 있었다.

<br>
<br>

---

<br>
<br>

# 생성된 총 Marine 수 세기 (static 변수)

#### 전역 변수를 실제로 사용하지 않고, 전역 변수와 같이 사용할 수 있는 변수
#### class 하나에만 종속됨.

<br>

#### 지역 변수처럼 함수가 종료될 때 소멸되는 게 아니라 프로그램이 종료될 때 소멸됨.

```
// static 멤버 변수의 사용

#include <iostream>

class Marine {
    static int total_marine_num;

    int hp;                          // 마린 체력
    int coord_x, coord_y;            // 마린 위치
    bool is_dead;

    const int default_damage;        // 가본 공격력

    public:
        Marine();                                      // 기본 생성자
        Marine(int x, int y);                          // x, y 좌표에 마린 생성
        Marine(int x, int y, int default_damage);

        int attack();                             // 데미지 리턴
        void be_attacked(int damage_earn);        // 입는 데미지
        void move(int x, int y);                  // 새로운 위치

        void show_status();                       // 상태를 보여줌

        ~Marine() { total_marine_num--; }
};

int Marine::total_marine_num = 0;

Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
    total_marine_num++;
}

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
    total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage) : coord_x(x), coord_y(y), hp(50), default_damage(default_damage), is_dead(false) {
    total_marine_num++;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << "Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP: " << hp << std::endl;
    std::cout << " 현재 총 마린 수: " << total_marine_num << std::endl;
}

void create_marine() {
    Marine marine3(10, 10, 4);
    marine3.show_status();
}

int main() {
    Marine marine1(2, 3, 5);
    marine1.show_status();

    Marine marine2(3, 5, 10);
    marine2.show_status();

    create_marine();

    std::cout << "마린1이 마린2를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}
```

![image](https://github.com/user-attachments/assets/53b1c968-2061-48ae-bf08-f7fa99d0dd10)

```
static int total_marine_num;
int Marine::total_marine_num = 0; 으로 초기화.

class Marine {
  static int total_marine_num = 0;
} 으로 초기화 안됨?
-> 안됨.

class Marine {
  const static int x = 0;
} 은 됨.

=> const 차이

## static은 변수뿐만 아니라 함수도 만들 수 있는데 class 내에 하나만 생성 가능하다.

```
// static 함수
#include <iostream>

class Marine {
    static int total_marine_num;
    const static int i = 0;

    int hp;                          // 마린 체력
    int coord_x, coord_y;            // 마린 위치
    bool is_dead;

    const int default_damage;        // 가본 공격력

    public:
        Marine();                                      // 기본 생성자
        Marine(int x, int y);                          // x, y 좌표에 마린 생성
        Marine(int x, int y, int default_damage);

        int attack();                             // 데미지 리턴
        void be_attacked(int damage_earn);        // 입는 데미지
        void move(int x, int y);                  // 새로운 위치

        void show_status();                       // 상태를 보여줌
        static void show_total_marine();
        ~Marine() { total_marine_num--; }
};

int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
    std::cout << "전체 마린 수: " << total_marine_num << std::endl;
}

Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
    total_marine_num++;
}

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
    total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage) : coord_x(x), coord_y(y), hp(50), default_damage(default_damage), is_dead(false) {
    total_marine_num++;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << "Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP: " << hp << std::endl;
    std::cout << " 현재 총 마린 수: " << total_marine_num << std::endl;
}

void create_marine() {
    Marine marine3(10, 10, 4);
    Marine::show_total_marine();
}

int main() {
    Marine marine1(2, 3, 5);
    marine1.show_status();

    Marine marine2(3, 5, 10);
    marine2.show_status();

    create_marine();

    std::cout << "마린1이 마린2를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}
```

![image](https://github.com/user-attachments/assets/517960c3-0c70-49e0-bb4e-466028273b86)

~ page 130













