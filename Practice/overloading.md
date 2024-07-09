#### C++은 C와 다르게 같은 이름을 가진 함수가 여러개 존재해도 됨.
#### 함수를 호출했을 때 사용하는 인자로 구분.

```
/* 험수의 오버로딩 */
#include <iostream>

void print(int x) { std::cout << "int: " << x << std::endl;}
void print(char x) { std::cout << "char: " << x << std::endl;}
void print(double x) { std::cout << "double: " << x << std::endl;}

int main() {
	int a = 1;
	char b = 'c';
	double c = 3.2f;

	print(a);
	print(b);
	print(c);

	return 0;
}
```

![image](https://github.com/UGeunJi/CPP/assets/84713532/52218c2c-8e89-4fbf-be94-9869ff97b6dd)

---

#### 적합한 인자를 자동으로 찾아서 인자를 가지도록 해줌.

```
/* 험수의 오버로딩 */
#include <iostream>

void print(int x) { std::cout << "int: " << x << std::endl;}
void print(double x) { std::cout << "double: " << x << std::endl;}

int main() {
	int a = 1;
	char b = 'c';
	double c = 3.2f;

	print(a);
	print(b);
	print(c);

	return 0;
}
```

![image](https://github.com/UGeunJi/CPP/assets/84713532/47b559b8-7d4d-4445-85b8-ca9f2b7717ca)

```
char 인자의 함수가 없었기에 자신과 최대한 근접한 함수를 찾게 됨.

정확히 일치하는 타입이 없을 경우 형변환을 통해 일치하는 함수를 찾아봄.

- Char, unsigned char, short는 int로 변환
- Unsigned short는 int의 크기에 따라 int 혹은 unsigned int로 변환
- float는 double로 변환
- Enum은 int로 변환

그 다음은 좀 더 포괄적인 형변환을 수행

- 임의의 숫자(numeric) 타입은 다른 숫자 타입으로 변환됨. (float -> int)
- Enum도 임의의 숫자 타입으로 변환 (Enum -> double)
- 0은 포인터 타입이나 숫자 타입으로 변환된 0은 포인터 타입이나 숫자 타입으로 변환
- 포인터는 void 포인터로 변환

** 단, 두 개 이상의 타입으로 변환되면 안된다.**
```

## Date class

```
#include<iostream>

class Date {
	int year_;
	int month_;    // 1~12
	int day_;      // 1~31

	public:
		void SetDate(int year, int month, int date);
		void AddDay(int inc);
		void AddMonth(int inc);
		void AddYear(int inc);

		//해당 월의 총 일 수를 구한다.
		int GetCurrentMonthTotalDays(int year, int month);

		void ShowDate();
};

void Date::SetDate(int year, int month, int day) {
	year_ = year;
	month_ = month;
	day_ = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month) {
	static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month != 2) {
		return month_day[month - 1];
	} else if (year % 4 == 0 && year % 100 != 0) {
		return 29;  // 윤년
	} else {
		return 28;
	}
}

void Date::AddDay(int inc) {
	while (true) {
		// 현재 달의 총 일 수
		int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

		// 같은 달 안에 들어온다면
		if (day_ + inc <= current_month_total_days) {
			day_ += inc;
			return;
		} else {
			// 다음달로 넘어가야 한다.
			inc -= (current_month_total_days - day_ + 1);
			day_ = 1;
			AddMonth(1);
		}
	}
}

void Date::AddMonth(int inc) {
	AddYear((inc + month_ - 1) / 12);
	month_ = month_ + inc % 12;
	month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate() {
	std::cout << "오늘은" << year_ << "년" << month_ << "월" << day_ << "일입니다" << std::endl;
}

int main() {
	Date day;
	day.SetDate(2011, 3, 1);
	day.ShowDate();

	day.AddDay(30);
	day.ShowDate();

	day.AddDay(2000);
	day.ShowDate();

	day.SetDate(2012, 1, 31);  // 윤년
	day.AddDay(29);
	day.ShowDate();

	day.SetDate(2012, 8, 4);
	day.AddDay(2500);
	day.ShowDate();

	return 0;
}
```

![image](https://github.com/UGeunJi/CPP/assets/84713532/5cdb14a1-1c3a-4e25-9b2b-ae76556bdcbe)


```
class에서 변수와 함수를 미리 선언해놓고

아래에서 void Date::~~~ 형식으로 함수의 동작을 설정했다.
```

#### 여기서 

```
	Date day;
	day.SetDate(2011, 3, 1);
	day.ShowDate();
```

이런 식으로 따로 초기화를 시켜줬는데,

```
  Date day(2011, 3, 1);
day.ShowDate();
```

이렇게 초기화해도 된다.
**이를 생성자라고 한다.**

```
Date day(2011, 3, 1);             // 암시적 방법 (implicit)
Date day = Date(2012, 3, 1);      // 명시적 방법 (explicit)
```

## Default Constructor

#### 컴파일러가 자동으로 생성자를 추가해주는 생성자

```
#include<iostream>

class Date {
	int year_;
	int month_;    // 1~12
	int day_;      // 1~31

	public:
		void ShowDate();
		
	Date() {
		year_ = 2012;
		month_ = 7;
		day_ = 12;
	}
};

void Date::ShowDate() {
	std::cout << "오늘은" << year_ << "년" << month_ << "월" << day_ << "일입니다" << std::endl;
}

int main() {
	Date day = Date();
	Date day2;

	day.ShowDate();
	day2.ShowDate();

	return 0;
}
```

![image](https://github.com/UGeunJi/CPP/assets/84713532/62614d3b-960e-4696-9ca4-3ccf226b31b0)
