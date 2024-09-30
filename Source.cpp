#include <iostream>
#include <list>
#include <iterator>
using namespace std;

class cmp
{
	int Val;
public:
	cmp(int iVal) : Val(iVal) {}
	// �������� () ������������ ��� ��������� ���������
	// ���������� �� ���������, ����������� � ������
	bool operator()(int a)
	{
		return a < Val;
	}
};

void main()
{
	// ���������� � ���������� ������
	int ar[] = { 1, 3, 2, 5, 8, 6, 7, 9, 4, 0 };
	list<int> a(ar, ar + 10);
	ostream_iterator<int> out(cout, " ");
	// ����� ���������� ��������� ������
	cout << "Initial state: " << endl;
	copy(a.begin(), a.end(), out);
	cout << endl;

	// �������� ��������� �� ��������� < 3 � �������������� ��������
	cmp  f(3);
	// � ����� ���� ����� remove_if()
	a.remove_if(f);
	cout << endl << "After remove less then 3: " << endl;
	copy(a.begin(), a.end(), out);
	cout << endl;

	// �������� ��������� �� ��������� < 6 � �������������� ��������
	cmp f2(6);
	a.remove_if(f2);
	cout << endl << "After remove less then 6: " << endl;
	copy(a.begin(), a.end(), out);
	cout << endl;
}
