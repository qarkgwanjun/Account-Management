//1. ����ü�� Ŭ������ ����
//2. Ŭ������ ĸ��ȭ �� �������� ����
//3. ������ �� �̴� ���¼��� 100��
//->��ü ������ �迭�� �ڵ带 �ۼ�
//4. ������ ���̸��� �����Ҵ����� ����
//5. ��ü�� �ʱ�ȭ �� �Ҹ��� ���ؼ�, Ŭ������ ������ �� �Ҹ��ڸ� �ۼ�
//6. ���°���, �Ա�, ���, �������� ��ü ���, ���� ����� ���� �Լ��� ����

#include <iostream>
#include <cstring>
#define SIZE 10

using namespace std;
bool a = true;

class AccountInfo
{
private:
	int account;
	int cash;
	char *name;

public:
	AccountInfo()
	{
		name = 0;
		account = 0;
		cash = 0;
	}
	AccountInfo(char *myName, int myaccount, int mycash) : account(myaccount), cash(mycash)
	{
		int len = strlen(myName) + 1;
		this->name = new char[len];
		strcpy(this->name, myName);

	}

	void ShowMeTheMoney() const
	{
		cout << "�����ܰ�� : " << cash << " �� �Դϴ�." << endl;
	}
	void plus(int money)
	{
		cash += money;
	}
	void minus(int money)
	{
		cash -= money;
	}
	int getID()
	{
		return account;
	}
	int CurrentMoney()
	{
		return cash;
	}
	void ShowInfo(void)
	{
		cout << "���� : " << account << endl;
		cout << "�̸� : " << name << endl;
		cout << "�ܰ� : " << cash << endl;
	}
	~AccountInfo()
	{
		delete[] name;
	}
};

class ControlClass
{
private:
	AccountInfo *accounts[100];
	int accNum;

public:
	ControlClass() : accNum(0)
	{}

	int GetAccNum()
	{
		return accNum;
	}

	void MakeAccount(AccountInfo *Acc)
	{
		accounts[accNum++] = Acc;
	}

	void InputMoney(int money, int i)
	{
		accounts[i]->plus(money);
	}
	void OutputMoney(int money, int i)
	{
		accounts[i]->minus(money);
	}
	int Search(int ID)
	{
		for (int i = 0; i < accNum; i++)
		{
			if (accounts[i]->getID() == ID)
				return i;
		}
		return -1;
	}
	void ShowMeTheMoney(int accNum)
	{
		accounts[accNum]->ShowMeTheMoney();
	}
	int CurrentMoney(int accNum)
	{
		return accounts[accNum]->CurrentMoney();
	}

	int getID(int accNum)
	{
		return accounts[accNum]->getID();
	}

	int GetInt(const char *str)
	{
		int buffer;
		cout << str;
		cin >> buffer;
		return buffer;
	}
	void print(void)
	{
		for (int i = 0; i < accNum; i++)
		{
			accounts[i]->ShowInfo();
		}
	}


};

void Exit(void)
{
	cout << "���α׷��� �����մϴ�." << endl;
	a = false;
}

int main(void)
{
	//AccountInfo account;
	ControlClass handler;


	int select;
	int location;
	int idBuffer;
	char nameBuffer[20];// = new char[20];
	int moneyBuffer;

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
			if (handler.GetAccNum() > 100)
				cout << "���� ��� �ʰ�" << endl;
			else
			{
				cout << "[���°���]" << endl;

				while (a)
				{
					idBuffer = handler.GetInt("����ID  : ");
					if (handler.Search(idBuffer) == -1)
					{
						cout << "�̸� : ";
						cin >> nameBuffer;
						cout << "�Աݾ� : ";
						cin >> moneyBuffer;

						/*int len = strlen(nameBuffer) + 1;
						char *nameptr = new char[len];
						strcpy(nameptr, Mname);
						*/
						/*AccountInfo peoplebuf(nameBuffer, idBuffer, moneyBuffer);
						AccountInfo *peoplebufptr = &peoplebuf;
						handler.MakeAccount(peoplebufptr);*/


						handler.MakeAccount(new AccountInfo(nameBuffer, idBuffer, moneyBuffer));
						//int i = handler.Search(idBuffer);
						//handler.InputMoney(moneyBuffer, i); //�Է��� id ��ġ�� ���� ����

						cout << "�����Ϸ� �Ǿ����ϴ�." << endl;
						a = false;
					}
					else
					{
						cout << "�̹� �ִ� �����Դϴ�. �ٽ� �Է��ϼ���" << endl;
					}
				}
				a = true;
			}
			break;

		case 2:
			while (a)
			{
				idBuffer = handler.GetInt("����ID  : ");
				if (handler.Search(idBuffer) == -1)
				{
					cout << "ã�� ���°� �����ϴ�. �ٽ� �Է��ϼ���" << endl;
				}
				else
				{
					cout << "�Աݾ� : ";
					cin >> moneyBuffer;
					location = handler.Search(idBuffer);
					handler.InputMoney(moneyBuffer, location); //�Է��� id ��ġ�� ���� ����
					handler.ShowMeTheMoney(location);
					a = false;
				}
			}
			a = true;
			break;

		case 3:
			while (a)
			{
				idBuffer = handler.GetInt("����ID  : ");
				if (handler.Search(idBuffer) == -1)
				{
					cout << "ã�� ���°� �����ϴ�. �ٽ� �Է��ϼ���" << endl;
				}
				else
				{
					cout << "��ݾ� : ";
					cin >> moneyBuffer;
					location = handler.Search(idBuffer);
					int money = handler.CurrentMoney(location);
					if (moneyBuffer > money)
					{
						cout << "�ܾ��� �����մϴ�!!!" << endl;
						handler.ShowMeTheMoney(location);
						cout << "��ݾ��� �ٽ� �Է��ϼ��� : " << endl;
						cout << "��ݾ� : ";
						cin >> moneyBuffer;
					}
					location = handler.Search(idBuffer);
					handler.OutputMoney(moneyBuffer, location); //�Է��� id ��ġ�� ���� ����
					handler.ShowMeTheMoney(location);
					a = false;
				}
			}
			a = true;
			break;

		case 4:
			cout << "[��ü ���] " << endl;
			handler.print();
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

