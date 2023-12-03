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
	straight2(str1, str2);
	str1 = itc_reverse_str(str1);
	str2 = itc_reverse_str(str2);
	long long len1 = str1.size();
	long long len2 = str2.size();

	string str_new = "";
	int o = 0, j = 0, q = 0;
	char r = ' ';
	for (int i = 0; i < len1; i++) {
		tsch1 = str1[i] - '0';
		tsch2 = str2[i] - '0';
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
	
	return str_new;
}

int main()
{
	string str1, str, res, str2 = "";
	char op = ' ';
	setlocale(LC_ALL, "RU");
	cout << itc_reverse_str(calc_minus("150", "30"));
	/*cout << "Введите число 1: ";
	cin >> str1;
	cout << "Введите число 2: ";
	cin >> str2;
	cout << "Введите операцию (+/-): ";
	cin >> op;
	string str3 = "";
	string str4 = "";
	/* if (str1[0] == '-') {
		for (int i = 1; i <= itc_len(str1); i++) str3 += str1[i];
	}
	if (str2[0] == '-') {
		for (int i = 1; i <= itc_len(str2); i++) str4 += str2[i];
	} 
	str1 = itc_reverse_str(str1);
	str2 = itc_reverse_str(str2);
	str3 = str1.erase(0, 1);
	str4 = str2.erase(0, 1);
	if (op == '+') {
		if ((str1[0] != '-') && (str2[0] != '-')) {
			str = calc_plus(str1, str2);
			cout << itc_reverse_str(str) << endl; // a + b
		}
		else if ((str1[0] == '-') && (str2[0] == '-')) {
			str1 = str1.erase(0, 1);
			str2 = str2.erase(0, 1);
			str = calc_plus(str1, str2) + "-";
			// res = '-' + itc_reverse_str(str);
			cout << itc_reverse_str(str) << endl;
		}

	}
/*
	else if ((str1[0] != '-') && (str2[0] == '-') && (op == '-')) {
		str = calc_plus(str1, str4);
		cout << itc_reverse_str(str) << endl;
	}
	
	else if (str1[0] == '-') */
		return 0;
}
