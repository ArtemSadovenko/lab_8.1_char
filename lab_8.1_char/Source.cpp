#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

void print_line(char* s) {
	cout << "line: ";
	for (int i = 0; s[i] != '\0'; i++) {
		cout << s[i];
	}
	cout << endl;
}

int count(char* s) {
	size_t k = strlen(s);
	char* buf = new char[2*k - 1];
	char* bufg = strcpy(buf, s);
	char* sear;
	int b_i;

	for (int i = 0; i < 4; i++) {
		sear = strrchr(bufg, '.');
		b_i = sear - bufg;
		bufg[b_i] = '^';
	}
	
	return b_i;
}

char* change(char* s){
	char* sNew = new char[(strlen(s)-1)*2 +1];
	size_t l = 0;
	for (size_t i = 0; i < strlen(s); i++)
	{
		if (s[i] == '.')
		{
			sNew[l] = '*';
			sNew[l + 1] = '*';
			l += 2;
		}
		else
		{
			sNew[l] = s[i];
			++l;
		}
	}
	sNew[l] = '\0';
	strcpy_s(s, strlen(sNew) + 1, sNew);
	return s;
}

void main() {
	char s[50];
	int p;
	char* iut;

	cout << "Enter string: "; cin.getline(s, 100);
	print_line(s);

	p = count(s);

	iut = change(s);

	print_line(iut);

	cout << "4th \".\" on position " << p << endl;
}