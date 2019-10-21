#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
using namespace std;

class CStr {
private:
	char* str;
	char* generateStringRandomLength(int length) {
		char* a = new char[length + 1];
		for (int i = 0; i < length + 1; ++i)
			a[i] = 0;

		for (int i = 0; i < length; ++i) {
			a[i] = rand() % ('z' - 'a') + 'a';
		}
		a[length] = 0;
		return a;
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
		str = generateStringRandomLength(length);
	}
	CStr(char* inputString) {
		str = inputString;
	}
	CStr(int length) {
		str = generateStringRandomLength(length);
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

int main() {
	srand(time(NULL));
	CStr a;
	cout << a << endl;
	CStr b(10);
	cout << b << endl;
	CStr c(a);
	cout << c << endl;
	CStr d = a;
	cout << d << endl;
	return 0;
}