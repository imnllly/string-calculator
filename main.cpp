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
}



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

void straight2(string& str1, string& str2) {
	int len1 = str1.size();
	int len2 = str2.size();
	if (len1 < len2) {
		for (int j = len1; j < len2; j++) {
			str1 = '0' + str1;
		}
	}
	else if (len1 > len2) {
		for (int j = len2; j < len1; j++) {
			str2 = '0' + str2;
		}
	}

}

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
}

string calc_minus(string str1, string str2) {
	int tsch1, tsch2, tsch3 = 0;
	string str3 = "";
	string str_new = "";
	char min = ' ';
	if (str1.size() < str2.size()) {
		str3 = str1;
		str1 = str2;
		str2 = str3;
		min = '-';
	}
	straight2(str1, str2);
	str1 = itc_reverse_str(str1);
	str2 = itc_reverse_str(str2);
	long long len1 = str1.size();
	long long len2 = str2.size();

	int o = 0, j = 0, q = 0;
	char r = ' ';
	for (int i = 0; i < len1; i++) {
		tsch1 = str1[i] - '0';
		tsch2 = str2[i] - '0';
		/*if (tsch1 >= tsch2) {
			tsch3 = tsch1 - tsch2 - o;
			o = 0;
		}
		else if (tsch2 > tsch1) {
			tsch3 = tsch1 - tsch2 + o + 10;
			o = 1;
		} */
		tsch3 = tsch1 - tsch2 - o + q;
		q = 0;
		if (tsch2 > tsch1) {
			tsch3 += 10;
			o = 1;
			if ((tsch1 == 0 && tsch2 == 0) && (i != 0)) {
				q = 10;
				o = 1;
			}
		} 
		else o = 0; 
		
		r = tsch3 + '0';
		str_new += r;
	}
	str_new += min;
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
	 if (str1[0] == '-') {
		for (int i = 1; i < str1.size(); i++) str3 += str1[i];
	}
	if (str2[0] == '-') {
		for (int i = 1; i < str2.size(); i++) str4 += str2[i];
	} 
	if (op == '+') {
		if ((str1[0] != '-') && (str2[0] != '-')) {
			str1 = itc_reverse_str(str1);
			str2 = itc_reverse_str(str2);
			str = calc_plus(str1, str2);
			cout << itc_reverse_str(str) << endl; // a + b, работает
		}
		else if ((str1[0] == '-') && (str2[0] == '-')) {
			str3 = itc_reverse_str(str3);
			str4 = itc_reverse_str(str4);
			str = calc_plus(str3, str4);
			str = itc_reverse_str(str);
			str = '-' + str; 
			cout << str << endl; // -a + -b, работает
		}
		else if ((str1[0] == '-') && (str2[0] != '-')) {
			str1 = itc_reverse_str(str1);
			str4 = itc_reverse_str(str4);
			str = calc_minus(str4, str1);
			cout << itc_reverse_str(str) << endl; // -a + b, работает
		}
		else if ((str1[0] != '-') && (str2[0] == '-')) {
			str = calc_minus(str1, str4);
			cout << itc_reverse_str(str) << endl; // a + (-b), работает 
		}
	}

	else if (op == '-') {
		if ((str1[0] != '-') && (str2[0] != '-')) {
			str = calc_minus(str1, str2);
			cout << itc_reverse_str(str) << endl; // a - b, работает
		}
		else if ((str1[0] != '-') && (str2[0] == '-')) {
			str1 = itc_reverse_str(str1);
			str4 = itc_reverse_str(str4);
			str = calc_plus(str1, str4);
			cout << itc_reverse_str(str) << endl; // a - (-b), работает
		}
		else if ((str1[0] == '-') && (str2[0] != '-')) {
			str3 = itc_reverse_str(str3);
			str2 = itc_reverse_str(str2);
			str = calc_plus(str3, str2);
			cout << '-' + itc_reverse_str(str) << endl; // -a - b, работает
		}
		else if ((str1[0] == '-') && (str2[0] == '-')) {
			str3 = itc_reverse_str(str3);
			str4 = itc_reverse_str(str4);
			str = calc_minus(str4, str3);
			cout << itc_reverse_str(str) << endl; // -a - (-b), работает
		}
	}
	
		return 0;
} 
