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
		cout << "���� ��� �ʰ�" << endl;
	int a = 1;
	int id;
	int search;
	cout << "[���°���]" << endl;

	while (a)
	{
		cout << "����ID  : ";
		cin >> id;
		search = Search(info, SIZE, id);
		if (id == info[search].accout)
		{
			cout << "�̹� �ִ� �����Դϴ�. �ٽ� �Է��ϼ���" << endl;
		}
		else
		{
			info[i].accout = id;
			cout << "�̸� : ";
			cin >> info[i].name;
			cout << "�Աݾ� : ";
			cin >> info[i].input;
			info[i].sum = info[i].input;
			cout << "�ԱݿϷ� �Ǿ����ϴ�." << endl;
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
	cout << "[�Ա�] " << endl;

	while (a)
	{
		cout << "����ID  : ";
		cin >> id;
		search = Search(info, SIZE, id);
		if (id != info[search].accout)
		{
			cout << "ã�� ���°� �����ϴ�. �ٽ� �Է��ϼ���" << endl;
		}
		else
		{
			cout << "�Աݾ� : ";
			cin >> info[search].input;
			info[search].sum += info[search].input;
			cout << "���� �ܰ� : " << info[search].sum << "��" << endl;
			a = 0;
		}
	}
}

void OutputMoney(AccoutInfo *info)
{

	int a = 1;
	int id;
	int search;
	cout << "[���] " << endl;
	cout << "����ID : ";
	cin >> id;

	while (a)
	{
		search = Search(info, SIZE, id);
		if (id != info[search].accout)
		{
			cout << "ã�� ���°� �����ϴ�. �ٽ� �Է��ϼ���" << endl;
			cout << "����ID : ";
			cin >> id;
		}
		else
		{
			cout << "��ݾ� : ";
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
			cout << "�ܾ��� �����մϴ�!!!" << endl;
			cout << "���� �ܰ�" << info[search].sum << endl;
			cout << "��ݾ��� �ٽ� �Է��ϼ��� : " << endl;
			cout << "��ݾ� : ";
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
	cout << "i��" << count << endl;
	cout << "[��ü ���] " << endl;
	int t;
	for (t = 0; t <= count; t++)
	{
		cout << "���� ID : " << info[t].accout << endl;
		cout << "�̸� : " << info[t].name << endl;
		cout << "�Աݾ� : " << info[t].sum << endl;
	}
	return 0;
}

void Exit(void)
{
	cout << "���α׷��� �����մϴ�." << endl;
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
		cout << "1. ���°���" << endl;
		cout << "2. �Ա�" << endl;
		cout << "3. ���" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
		cout << "���� : ";
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
			cout << "��ȣ�� �ٽ� �Է��ϼ���!" << endl;
			break;
		}
	}

	return 0;
}