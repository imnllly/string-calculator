#include <iostream>
#include <string>

using namespace std;


string itc_reverse_str(string str) {
	int len = str.size();
	string str2{};
	int k = 0;
	if (str[0] == '-') k = 1;
	for (int i = len - 1; i >= k; i--) {
		str2 += str[i];
	}
	return str2;
} // переворачивает строку



void straight(string& str1, string& str2) {
	int len1 = str1.size();
	int len2 = str2.size();
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
// добивает длину

string maxx(string str1, string str2) {
	if (str1.size() > str2.size()) return str1;
	else if (str2.size() > str1.size()) return str2;
	else {
		for (int i = str1.size(); i > 0; i--) {
			if (str1[i] - '0' > str2[i] - '0') return str1;
			else if (str2[i] - '0' > str1[i] - '0') return str2;
		}
	}
	return str1;
} // находит большее число

string calc_plus(string str1, string str2) {
	int tsch1, tsch2, tsch3 = 0;
	straight(str1, str2);
	int len1 = str1.size();
	int len2 = str2.size();
	string str_new = "";
	int o = 0;
	char r = ' ';
	for (int i = 0; i < len1; i++) {
		tsch1 = str1[i] - '0';
		tsch2 = str2[i] - '0';
		tsch3 = tsch1 + tsch2 + o;
		o = 0;
		if (tsch3 > 9) {
			tsch3 %= 10;
			o = 1;
		}
		r = tsch3 + '0';
		str_new += r;
	}
	if (o == 1) str_new += '1';
	return str_new;
} // сложение 


string calc_minus(string str1, string str2) {
	int tsch1, tsch2, tsch3 = 0;
	string str_new = "";
	straight(str1, str2);
	long long len1 = str1.size();
	int o = 0;
	char r = ' ';
	for (int i = 0; i < len1; i++) {
		tsch1 = str1[i] - '0';
		tsch2 = str2[i] - '0';
		if (tsch1 - o >= tsch2) {
			tsch3 = tsch1 - tsch2 - o;
			o = 0;
		}
		else {
			tsch3 = 10 - (tsch2 - tsch1 + o);
			o = 1;
		}
		r = tsch3 + '0';
		str_new += r;
	}
	return str_new;
} // вычитание


string proverka(string str1, string str2, int op) {
	int zn1 = 1, zn2 = 1;
	string str_new = "";
	if (str1[0] == '-') zn1 = -1;
	if (str2[0] == '-') zn2 = -1;
	str1 = itc_reverse_str(str1);
	str2 = itc_reverse_str(str2);
	if (zn1 == 1 && zn2 * op == 1) return itc_reverse_str(calc_plus(str1, str2)); // a + b; a - (-b)
	if (zn1 == -1 && zn2 * op == -1) return itc_reverse_str(calc_plus(str1, str2) + "-"); // -a - b; -a + (-b)
	if (maxx(str1, str2) == str1) {
		if (zn1 == -1 && zn2 * op == 1) return itc_reverse_str(calc_minus(str1, str2) + "-"); // -a + b; -a - (-b)
		if (zn1 == 1 && zn2 * op == -1) return itc_reverse_str(calc_minus(str1, str2)); // a - b; a + (-b)
	}
	if (maxx(str1, str2) == str2) {
		if (zn1 == -1 && zn2 * op == 1) return itc_reverse_str(calc_minus(str2, str1)); // -a + b; -a - (-b)
		if (zn1 == 1 && zn2 * op == -1) return itc_reverse_str(calc_minus(str2, str1) + "-"); // a - b; a + (-b)
	}
}

int main()
{
	string str1, str, res, str2 = "";
	int op = 0;
	string ope = "";
	setlocale(LC_ALL, "RU");
	cout << "Введите число 1: ";
	cin >> str1;
	cout << "Введите число 2: ";
	cin >> str2;
	cout << "Введите операцию (+/-): ";
	cin >> ope;
	string str3 = "";
	string str4 = "";
	if (ope == "+") op = 1;
	else if (ope == "-") op = -1;
	cout << proverka(str1, str2, op) << endl;
	return 0;
}
