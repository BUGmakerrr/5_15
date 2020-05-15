#include<iostream>
using namespace std;

//class Date{
//public:
//	Date(int year = 0,int month = 1,int day = 1){
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(Date& d){
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	Date operator=(const Date &d){
//		if (this != &d){
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//	Date operator-(const Date &d){
//		Date bigger = *this;
//		Date smaller = d;
//
//
//	}
//	void Print(){
//		cout << _year <<"-"<< _month <<("-")<< _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
class Date{
public:
	int GetMonthDay(int year, int month){
		static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		// 是2月且是闰年返回29
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}

		return monthDays[month];
	}
	Date(int year = 0, int month = 1, int day = 1){
		_year = year;
		_month = month;
		_day = day;
	}
	Date(Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	bool operator==(const Date& d){
		return _year == d._year&&_month == d._month&&_day == d._day;
	}
	bool operator>(const Date& d)
	{
		if (_year > d._year)
			return true;
		else if (_year == d._year && _month > d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day > d._day)
			return true;

		return false;
	}
	inline bool operator<(const Date& d) // bool operator<(Date* this, const Date& d)
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day < d._day)
			return true;

		return false;
	}
	Date operator=(const Date &d){
		if (this != &d){
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}
	Date operator+(int day)
	{
		Date ret(*this); // 用d1拷贝构造一个ret
		ret._day += day;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			// 如果日期的天不合法，就需要往月进度
			ret._day -= GetMonthDay(ret._year, ret._month);
			ret._month++;

			if (ret._month == 13)
			{
				ret._year++;
				ret._month = 1;
			}
		}

		return ret;
	}
	Date operator-( Date &d){
		Date bigger = *this;
		Date smaller=d;
		if (*this < d){
			bigger = d;
			smaller = *this;
		}
		int n;
		while (*this != d){
			smaller = smaller + 1;
			++n;
		}
		return n;
	}
	void Print(){
		cout << _year << "-" << _month << ("-") << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main(){
	/*Date d1(2019,6,1);
	d1.Print();
	Date d2(d1);
	d2.Print();*/
	getchar();
	return 0;

}