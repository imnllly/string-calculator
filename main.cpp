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
	if(o == 1) str_new += '1';
	return str_new;
}

int main()
{
	string str1, str, res, str2 = "";
	char op = ' ';
	setlocale(LC_ALL, "RU");
	cout << "Введите число 1: ";
	cin >> str1;
	cout << "Введите число 2: ";
	cin >> str2;
	cout << "Введите операцию (+/-): ";
	cin >> op;
	string str3 = "";
	string str4 = "";
    if(str1[0] == '-') {
        for(int i = 1; i <= itc_len(str1); i++) str3 += str1[i];
    }
	if(str2[0] == '-') {
        for(int i = 1; i <= itc_len(str2); i++) str4 += str2[i];
    }
	str1 = itc_reverse_str(str1);
	str2 = itc_reverse_str(str2);
	str3 = itc_reverse_str(str3);
	str4 = itc_reverse_str(str4);
	if ((str1[0] != '-') && (str2[0] != '-') && (op == '+')) {
		str = calc_plus(str1, str2);
		cout << itc_reverse_str(str) << endl;
	}
	else if ((str1[0] != '-') && (str2[0] == '-') && (op == '-')) {
		str = calc_plus(str1, str4);
		cout << itc_reverse_str(str) << endl;
	}
    else if ((str1[0] == '-') && (str2[0] != '-') && (op == '+')) {
		str = calc_plus(str1, str2) + "-";
		// res = '-' + itc_reverse_str(str);
		cout << itc_reverse_str(str) << endl;
	}
	else if(str1[0] == '-')
	return 0;
}
