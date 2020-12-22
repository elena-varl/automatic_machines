#include <iostream>
#include <string>
#include <map>
using namespace std;
/*��������� ������� ����� � ��������*/
/* I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000*/
int TranslateFromRomToArabian(string str)
{
	map<char, int> ch;//��� ����������� ������� �����
	int t,res;
	ch.insert(make_pair('M', 1000));
	ch.insert(make_pair('D', 500));
	ch.insert(make_pair('C', 100));
	ch.insert(make_pair('L', 50));
	ch.insert(make_pair('X', 10));
	ch.insert(make_pair('V',5));
	ch.insert(make_pair('I', 1));
	t = 0;
	res = 0;
	for (char i:str)//���� �� �����, ����� ������ ����� ����� ����� �������
	{
		int n = ch[i];
		if (n < t)//���� ������� ����� ����� �������, �� ���������� 
		{
			res += t;
			t = n;
		}
		else if (n > t)
		{
			if (t == 0)//��� �� ������ ����, t =0
			{
				t = n;
			}
			else
			{
				res += n - t;//��� ���� ������� ����� ����� ����� �������, �� �� ������� �� �������� �� �������� �������
				t = 0;
			}			
		}
		else	if (n == t)
		{
			res += n + t;
			t = 0;
		}

	}
	return res + t;
}
int main() 
{
	//��������
	cout << "Translate from Roman to Arabian" << endl;
	cout << "XI" << "-" << TranslateFromRomToArabian("XI") << endl;
	cout << "VII" << "-" << TranslateFromRomToArabian("VII") << endl;
	cout << "IX" << "-" << TranslateFromRomToArabian("IX") << endl;
	/*MMIX = 2009, XLIII = 43, XC = 90, CD = 400, CMXCVII = 997*/
	const char* ex[]{ "MMIX","XLIII","XC","CD","CMXCVII" };
	cout << "Checking example" << endl;
	for (auto x : ex)
	{
		cout << x << "-" << TranslateFromRomToArabian(x) << endl;
	}
	/*MMIX-2009
XLIII-43
XC-90
CD-400
CMXCVII-997*/
//MCMLXXXV-1985
	string s;
	cout << "Insert Roman number without spaces" << endl;
	cout << "I = 1,V = 5,X = 10,L = 50,C = 100,D = 500,M = 1000" << endl;
	cin >> s;
	cout << "Your number:" << TranslateFromRomToArabian(s) << endl;
}