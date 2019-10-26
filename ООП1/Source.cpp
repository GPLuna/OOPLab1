#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
using namespace std;

class CStr {
private:
	char* str;
	char* generateStringRandom(int length) {
		if (length <= 20 && length > 0) {
			char* a = new char[length + 1];
			for (int i = 0; i < length + 1; ++i)
				a[i] = 0;

			for (int i = 0; i < length; ++i) {
				a[i] = rand() % ('z' - 'a') + 'a';
			}
			a[length] = 0;
			return a;
		}
		else
			return nullptr;
	}
public:
	int getLength() {
		return strlen(str);
	}
	char* getString() {
		return str;
	}
	CStr() {
		int length = rand() % 20 + 1;
		str = generateStringRandom(length);
	}
	CStr(char* inputString) {
		str = new char[strlen(inputString) + 1];
		strcpy(str, inputString);
	}
	CStr(int length) {
		str = generateStringRandom(length);
	}
	~CStr() {
		if (str != nullptr) {
			delete[] str;
		}
	}
	CStr(const CStr& obj) {
		str = new char[strlen(obj.str)+1];
		strcpy(str, obj.str);
	}
	CStr& operator= (const CStr& obj) {
		str = new char[strlen(obj.str)+1];
		strcpy(str, obj.str);
	}
	bool operator> (const CStr& object) {
		return str > object.str;
	}
	bool operator< (const CStr& object) {
		return str < object.str;
	}
	friend ostream& operator<< (ostream& out, const CStr& obj) {
		out << obj.str;
		return out;
	}
};
class CStrArray {
private:
	CStr** arr;
	int length;
public:
	CStrArray(int length) {
		arr = new CStr* [length];
		for (int i = 0; i < length; ++i)
			arr[i] = new CStr;
		this->length = length;
	}
	~CStrArray() {
		if (arr != nullptr)
			delete[] arr;
	}
	CStr &operator[](int index) {
		return *arr[index];
	}
	void sortByContent() {
		for (int i = 0; i < length - 1; ++i)
			for (int j = i + 1; j < length; ++j)
				if (arr[i] > arr[j]) {
					CStr* temp = arr[j];
					arr[j] = arr[i];
					arr[i] = temp;
				}
	}
	void sortByLength() {
		for (int i = 0; i < length - 1; ++i)
			for (int j = i + 1; j < length; ++j)
				if (arr[i]->getLength() > arr[j]->getLength()) {
					CStr* temp = arr[j];
					*arr[j] = *arr[i];
					*arr[i] = *temp;
				}
	}
	bool isSortedByContent() {
		for (int i = 0; i < length - 1; ++i) {
			for (int j = i + 1; j < length; ++j)
				if (arr[i] > arr[j])
					return false;
		}
		return true;
	}
};
int main() {
	srand(time(NULL));
	CStr a;					//По умолчанию
	cout << a << endl;
	CStr b(10);				//Длинна
	cout << b << endl;
	CStr c(a);				//Копия
	cout << c << endl;
	CStr d = a;				//Оператор =
	cout << d << endl;
	char test[] = "gwrh";	//Готовая строка
	CStr f(test);
	cout << f << endl<< endl;
	CStrArray arr(10);
	arr.sortByContent();
	for (int i = 0; i < 10; ++i)
		cout << arr[i] << endl;
	cout << arr.isSortedByContent();
	return 0;
}