#include <iostream>
#include <cstring>
#define SIZE 10

using namespace std;
int a = 1;
int i = 0;

struct AccoutInfo
{
	int accout;
	int input;
	int output;
	int sum = 0;
	int i = 0;

	char name[10];
};

int Search(AccoutInfo *info, int n, int id)
{
	int j;
	for (j = 0; j < n; j++)
	{
		if (info[j].accout == id)
			return j;
	}
	return -1;
}

int MakeAccount(AccoutInfo *info)
{
	if (i > 100)
		cout << "계좌 등록 초과" << endl;
	int a = 1;
	int id;
	int search;
	cout << "[계좌개설]" << endl;

	while (a)
	{
		cout << "계좌ID  : ";
		cin >> id;
		search = Search(info, SIZE, id);
		if (id == info[search].accout)
		{
			cout << "이미 있는 계좌입니다. 다시 입력하세요" << endl;
		}
		else
		{
			info[i].accout = id;
			cout << "이름 : ";
			cin >> info[i].name;
			cout << "입금액 : ";
			cin >> info[i].input;
			info[i].sum = info[i].input;
			cout << "입금완료 되었습니다." << endl;
			i++;
			a = 0;
		}
	}
	return i - 1;
}

void InputMoney(AccoutInfo *info)
{
	int id;
	int search;
	int a = 1;
	cout << "[입금] " << endl;

	while (a)
	{
		cout << "계좌ID  : ";
		cin >> id;
		search = Search(info, SIZE, id);
		if (id != info[search].accout)
		{
			cout << "찾는 계좌가 없습니다. 다시 입력하세요" << endl;
		}
		else
		{
			cout << "입금액 : ";
			cin >> info[search].input;
			info[search].sum += info[search].input;
			cout << "현재 잔고 : " << info[search].sum << "원" << endl;
			a = 0;
		}
	}
}

void OutputMoney(AccoutInfo *info)
{

	int a = 1;
	int id;
	int search;
	cout << "[출금] " << endl;
	cout << "계좌ID : ";
	cin >> id;

	while (a)
	{
		search = Search(info, SIZE, id);
		if (id != info[search].accout)
		{
			cout << "찾는 계좌가 없습니다. 다시 입력하세요" << endl;
			cout << "계좌ID : ";
			cin >> id;
		}
		else
		{
			cout << "출금액 : ";
			cin >> info[search].output;
			a = 0;
		}
	}
	a = 1;
	while (a)
	{
		search = Search(info, SIZE, id);
		if ((info[search].sum - info[search].output) < 0)
		{
			cout << "잔액이 부족합니다!!!" << endl;
			cout << "현재 잔고" << info[search].sum << endl;
			cout << "출금액을 다시 입력하세요 : " << endl;
			cout << "출금액 : ";
			cin >> info[search].output;
		}
		else
		{
			info[search].sum -= info[search].output;
			a = 0;
		}
	}

}

int PrintAllAccout(AccoutInfo *info, int count)
{
	cout << "i는" << count << endl;
	cout << "[전체 출력] " << endl;
	int t;
	for (t = 0; t <= count; t++)
	{
		cout << "계좌 ID : " << info[t].accout << endl;
		cout << "이름 : " << info[t].name << endl;
		cout << "입금액 : " << info[t].sum << endl;
	}
	return 0;
}

void Exit(void)
{
	cout << "프로그램을 종료합니다." << endl;
	a = 0;
}

int main(void)
{
	AccoutInfo info[100];
	int select;
	int count;
	while (a)
	{
		cout << "---------- Menu ----------" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입금" << endl;
		cout << "3. 출금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "선택 : ";
		cin >> select;

		switch (select)
		{
		case 1:
			count = MakeAccount(info);
			break;

		case 2:
			InputMoney(info);
			break;

		case 3:
			OutputMoney(info);
			break;

		case 4:
			PrintAllAccout(info, count);
			break;

		case 5:
			Exit();
			break;

		default:
			cout << "번호를 다시 입력하세요!" << endl;
			break;
		}
	}

	return 0;
}