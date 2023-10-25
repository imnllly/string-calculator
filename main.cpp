#include <iostream>
#include <string>
using namespace std;

long long itc_len(string str) {
	int len = 0;
	for (int i = 0; str[i] != '\0'; i++) len++;
	return len;
}

string itc_reverse_str(string str) {
	int len = itc_len(str);
	string str2{};
	for (int i = len - 1; i >= 0; i--) {
		str2 += str[i];
	}
	return str2;
}

string calculator(string str1, string str2) {
	str1 = itc_reverse_str(str1);
	str2 = itc_reverse_str(str2);
	int tsch1 = 0;
	int tsch2 = 0;
	int tsch3 = 0;
	int tsch_new = 0;
	int x = 1;
	for (int i = 0; i < itc_len(str1) && i < itc_len(str2) ; i--) {
		tsch1 = str1[i] - '0';
		tsch2 = str2[i] - '0';
		tsch3 = (tsch1 + tsch2 + tsch_new) % 10;
		tsch_new += x * tsch3;
		x *= 10;
	}
}

int main()
{
	// cout << calculator();
}
