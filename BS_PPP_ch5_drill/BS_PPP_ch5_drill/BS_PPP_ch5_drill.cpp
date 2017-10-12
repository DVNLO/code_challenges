/*The following is a drill from chapter 5 Errors of
Bjarne Stroustrup's Programming Principles and Practice.
Author: Dan Vyenielo
Date: 10/12/17*/

#include "stdafx.h"
#include "std_lib_facilities.h"

int main()
{
	try {
		//cout << "Success!\n";
		cout << "Success!\n";
		//cout << "Success!\n;
		cout << "Success!\n";
		//cout << "Success" << !\n"
		cout << "Success" << "!\n";
		//cout << success << '\n';
		cout << "Success!" << '\n';
		//string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
		int res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
		//vector<int> v(10); v(5) = 7; if (v(5)!=7) cout << "Success!\n";
		vector<int> v1(10); v1[5] = 7; if (v1[5] != 7) cout << "Success!\n";
		//if (cond) cout << "Success!\n"; else cout << "Fail!\n";
		if (v1[5] == 7) cout << "Success!\n"; else cout << "Fail!\n";
		//bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";
		bool c = true; if (c) cout << "Success!\n"; else cout << "Fail!\n";
		//string s = "ape"; boo c = "fool"<s; if (c) cout << "Success!\n";
		string s1 = "ape"; bool c1 = (s1 < "fool"); if (c1) cout << "Success!\n";
		//string s = "ape"; if (s=="fool") cout << "Success!\n";
		string s2 = "ape"; if (s2 != "fool") cout << "Success!\n";
		//string s = "ape"; if (s=="fool") cout < "Success!\n";
		string s3 = "ape"; if (s3 == "fool") cout << "Success!\n";
		//string s = "ape"; if (s+"fool") cout < "Success!\n";
		string s4 = "ape"; if (s4 != "fool") cout << "Success!\n";
		//vector<char> v(5); for (int i=0; 0<v.size(); ++i) ; cout << "Success!\n";
		vector<char> v2(5); for (unsigned int i = 0; i<v2.size(); ++i); cout << "Success!\n";
		//vector<char> v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";
		vector<char> v3(5); for (unsigned int i = 0; i < v.size(); ++i); cout << "Success!\n";
		//string s = "Success!\n"; for (int i=0; i<6; ++i) cout << s[i];
		string s6 = "Success!\n"; for (unsigned int i=0; i<s6.size(); ++i) cout << s6[i];
		if (true) cout << "Success!\n"; else cout << "Fail!\n";
		//int x = 2000; char c = x; if (c==2000) cout << "Success!\n";
		int x = 2000; int c5 = x; if (c == 2000) cout << "Success!\n";
		//string s = "Success!\n"; for (int i=0; i<10; ++i) cout << s[i];
		string s7 = "Success!\n"; for (unsigned int i = 0; i < s7.size(); ++i) cout << s7[i];
		//vector v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";
		vector<int> v4(5); for (unsigned int i = 0; i < v4.size(); ++i); cout << "Success!\n";
		//int i=0; int j = 9; while (i<10) ++j; if (j<i) cout << "Success!\n";
		int i = 0; int j = 9; while (i<10) ++i; if (j<i) cout << "Success!\n";
		//int x = 2; double d = 5/(x–2); if (d==2*x+0.5) cout << "Success!\n";
		int x1 = 2; double d = 9/(x1); if (d == 2 * x1 + 0.5) cout << "Success!\n";
		//string<char> s = "Success!\n"; for (int i=0; i<=10; ++i) cout << s[i];
		string s8 = "Success!\n"; for (unsigned int i = 0; i < s7.size(); ++i) cout << s8[i];
		//int i=0; while (i<10) ++j; if (j<i) cout << "Success!\n";
		int i2 = 0, j2 = i2; while (i2 < 10) ++i2; if (j2 < i2) cout << "Success!\n";
		//int x = 4; double d = 5/(x–2); if (d=2*x+0.5) cout << "Success!\n";
		int x2 = 4; double d2 = 18/(x2); if (d2 = 2 * x2 + 0.5) cout << "Success!\n";
		//cin << "Success!\n";
		cout << "Success!\n";
		keep_window_open();
		return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "oops: unknown exception! \n";
		keep_window_open();
		return 2;
	}
}

