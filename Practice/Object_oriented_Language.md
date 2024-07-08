## 프로그래밍 발달 과정

1. 에니악 (크고 오류 발생시 치명적)
2. 어셈블리어 (체계화 되어있지 않아 코딩에 비효율적(스파게티 코드))
3. 파스칼 - 절차지향언어(Procedural Programming Language)
4. 객체지향언어 (Object Oriented Language)

---

```
객체지향언어가 필요해진 이유는 캡슐화를 통해 설명할 수 있다.

캡슐이란 함수(function)을 의미하며 예를 들어 변수의 상태를 변화시키고자 한다면 두 가지 방법이 있다.
ex) animal.food = 100;

animal.food += 100;           // 불가능
animal.increase_food(100);    // 가능

increase_food(100) function을 활용하면 animal에 대한 food가 100 상승한다.
다른 변수의 변화는 몰라도 된다.

하지만 animal.food += 100;으로 해줄시,
다른 변수들의 변화도 동시에 신경써서 하나하나 다 설정해줘야 한다.

이 말이 의미하는 건, 예를 들어 키보드로 문자 'a'를 입력했을 때 컴퓨터에서 일어나는 현상을 모두 우리가 일일히 타이핑을 해주는 것과 같다는 것을 의마한다.
우린 지금 단지 'a'만 입력할 뿐 컴퓨터가 어떻게 처리하는지 모르지 않은가?

이 과정을 생략하고 편리하게 해주는 것이 캡슐화이며, 객체지향언어이다.
코딩할 때는 번거로울 수 있는 class가 이것이다.
```

---

# class

#### class를 이용해서 만들어진 객체를 instance라고 부름.

```
#include <iostream>

class Animal {
	private:                                       // 따로 설정해주지 않아도 자동으로 private로 설정함.
		int food;
		int weight;

	public:
		void set_animal(int _food, int _weight) {
			food = _food;
			weight = _weight;
		}

		void increase_food(int inc) {
			food += inc;
			weight += (inc / 3);
		}

		void view_stat() {
			std::cout << "이 동물의 food   : " << food << std::endl;
			std::cout << "이 동물의 weight : " << weight << std::endl;
		}
};   // class의 마무리 세미콜론

int main() {
	Animal animal;                                // main 함수에서 animal instance 선언
	animal.set_animal(100, 50);
	animal.increase_food(30);

	animal.view_stat();
	return 0;
}
```

#### instance 함수(=member function): set_animal, increase_food, view_stat
#### instance 변수(=member variable): food, weight
