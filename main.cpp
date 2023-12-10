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

} // добивает длину для сложения

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

} // добивает длину для вычитания

string maxx(string str1, string str2) {
	if (str1.size() > str2.size()) return str1;
	else if (str2.size() > str1.size()) return str2;
	else {
		for (int i = str1.size(); i >= 0; i--) {
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
	string str3 = "";
	string str_new = "";
	straight2(str1, str2);
	str1 = itc_reverse_str(str1);
	str2 = itc_reverse_str(str2);
	//if (str1 == str2) return "0";
	long long len1 = str1.size();
	long long len2 = str2.size();
	int o = 0, j = 0, q = 0;
	char r = ' ';
	for (int i = 0; i < len1; i++) {
		tsch1 = str1[i] - '0';
		tsch2 = str2[i] - '0';
		if (tsch1 - o >= tsch2) {
			tsch3 = tsch1 - tsch2 - o;
			o = 0;
		}
		else if (tsch2 > tsch1 - o) {
			tsch3 = tsch1 - tsch2 + o + 10;
			o = 1;
		}  
		//tsch3 = tsch1 - tsch2 - o + q;
		//q = 0;
		/* if (tsch2 > tsch1) {
			tsch3 += 10;
			o = 1;
			if ((tsch1 == 0 && tsch2 == 0) && (i != 0)) {
				q = 10;
				o = 1;
			}
		} 
		else o = 0;  */
		
		r = tsch3 + '0';
		str_new += r;
	}
	return str_new;
} // вычитание


string proverka(string str1, string str2, string str3, string str4, int op) {
	int zn1 = 1, zn2 = 1;
	string str_new = "";
	if (str1[0] == '-') zn1 = -1;
	if (str2[0] == '-') zn2 = -1;
	str1 = itc_reverse_str(str1);
	str2 = itc_reverse_str(str2);
	str3 = itc_reverse_str(str3);
	str4 = itc_reverse_str(str4);
	if (zn1 == 1 && zn2 * op == 1) return itc_reverse_str(calc_plus(str1, str2)); // работает
	if (zn1 == -1 && zn2 * op == -1) return itc_reverse_str(calc_plus(str3, str4) + "-"); // работает
	if (maxx(str3, str4) == str3) {
		if (zn1 == -1 && zn2 * op == 1) return itc_reverse_str(calc_minus(str3, str4) + "-");
		if (zn1 == 1 && zn2 * op == -1) return itc_reverse_str(calc_minus(str3, str4));
	}
	if (maxx(str3, str4) == str4) {
		if (zn1 == -1 && zn2 * op == 1) return itc_reverse_str(calc_minus(str4, str3));
		if (zn1 == 1 && zn2 * op == -1) return itc_reverse_str(calc_minus(str4, str3) + "-");
	}
}

int main()
{
	string str1, str, res, str2 = "";
	int op = 0;
	char ope = ' ';
	setlocale(LC_ALL, "RU");
	cout << "Введите число 1: ";
	cin >> str1;
	cout << "Введите число 2: ";
	cin >> str2;
	cout << "Введите операцию (+/-): ";
	cin >> ope;
	string str3 = "";
	string str4 = "";
	if (ope == '+') op = 1;
	else if (ope == '-') op = -1;
	 if (str1[0] == '-') {
		for (int i = 1; i < str1.size(); i++) str3 += str1[i];
	} // убирает минус в первом числе
	if (str2[0] == '-') {
		for (int i = 1; i < str2.size(); i++) str4 += str2[i];
	} // убирает минус во втором числе
	cout << proverka(str1, str2, str3, str4, op) << endl;
		return 0;
} 
