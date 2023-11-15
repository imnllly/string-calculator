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
	int k = 0;
	if (str[0] == '-') k = 1;
	for (int i = len - 1; i >= k; i--) {
		str2 += str[i];
	}
	return str2;
}

 /*string calculator(string str1, string str2) {
	str1 = itc_reverse_str(str1);
	str2 = itc_reverse_str(str2);
	int tsch1 = 0;
	int tsch2 = 0;
	int tsch3 = 0;
	int tsch_new = 0;
	int x = 1;
	for (int i = 0; i < itc_len(str1) && i < itc_len(str2); i--) {
		tsch1 = str1[i] - '0';
		tsch2 = str2[i] - '0';
		tsch3 = (tsch1 + tsch2 + tsch_new) % 10;
		tsch_new += x * tsch3;
		x *= 10;
	}
} */

void straight(string &str1, string &str2) {
	int len1 = itc_len(str1);
	int len2 = itc_len(str2);
	if (len1 < len2) {
		for (int j = len1; j < len2; j++) {
			str1 += '0';
		}
	}
	else if (len1 > len2) {
		for (int j = len2; j < len1; j++) {
			str2 += '0';
		}
	}
	
}

string calc_plus(string str1, string str2) {
	int tsch1, tsch2, tsch3 = 0;
	straight(str1, str2);
	int len1 = itc_len(str1);
	int len2 = itc_len(str2);
	string str_new = "";
	int o = 0;
	char r = ' ';
	for (int i = 0; i < len1 + 1; i++) {
		tsch1 = str1[i] - '0';
		tsch2 = str2[i] - '0';
		tsch3 += o;
		o = 0;
		tsch3 = tsch1 + tsch2;
		if (tsch3 > 9) {
			tsch3 %= 10;
			o = 1;
		}
		r = tsch3 + '0';
		str_new += r;
	}
	str_new = itc_reverse_str(str_new);
	return str_new;
}

int main()
{
	string str1, str2 = "";
	char op = ' ';
	setlocale(LC_ALL, "RU");
	cout << "Введите число 1: ";
	cin >> str1;
	cout << "Введите число 2: ";
	cin >> str2;
	cout << "Введите операцию (+/-): ";
	cin >> op;
	if(str1[0] == '-') string str3 = str1;
	if(str2[0] == '-') string str4 = str2;
	str1 = itc_reverse_str(str1);
	str2 = itc_reverse_str(str2);
	if (op == '+') {
		cout << calc_plus(str1, str2);
	}

	return 0;
}
