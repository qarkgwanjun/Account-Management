//1. 구조체를 클래스로 변경
//2. 클래스를 캡슐화 및 정보은닉 적용
//3. 관리할 수 이는 계좌수를 100개
//->객체 포인터 배열로 코드를 작성
//4. 계좌의 고객이름은 동적할당으로 적용
//5. 객체의 초기화 및 소멸을 위해서, 클래스에 생성자 및 소멸자를 작성
//6. 계좌개설, 입금, 출금, 계좌정보 전체 출력, 종료 기능을 각각 함수로 구현

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
		cout << "현재잔고는 : " << cash << " 원 입니다." << endl;
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
		cout << "계좌 : " << account << endl;
		cout << "이름 : " << name << endl;
		cout << "잔고 : " << cash << endl;
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
	cout << "프로그램을 종료합니다." << endl;
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
			if (handler.GetAccNum() > 100)
				cout << "계좌 등록 초과" << endl;
			else
			{
				cout << "[계좌개설]" << endl;

				while (a)
				{
					idBuffer = handler.GetInt("계좌ID  : ");
					if (handler.Search(idBuffer) == -1)
					{
						cout << "이름 : ";
						cin >> nameBuffer;
						cout << "입금액 : ";
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
						//handler.InputMoney(moneyBuffer, i); //입력한 id 위치에 돈을 넣음

						cout << "개설완료 되었습니다." << endl;
						a = false;
					}
					else
					{
						cout << "이미 있는 계좌입니다. 다시 입력하세요" << endl;
					}
				}
				a = true;
			}
			break;

		case 2:
			while (a)
			{
				idBuffer = handler.GetInt("계좌ID  : ");
				if (handler.Search(idBuffer) == -1)
				{
					cout << "찾는 계좌가 없습니다. 다시 입력하세요" << endl;
				}
				else
				{
					cout << "입금액 : ";
					cin >> moneyBuffer;
					location = handler.Search(idBuffer);
					handler.InputMoney(moneyBuffer, location); //입력한 id 위치에 돈을 넣음
					handler.ShowMeTheMoney(location);
					a = false;
				}
			}
			a = true;
			break;

		case 3:
			while (a)
			{
				idBuffer = handler.GetInt("계좌ID  : ");
				if (handler.Search(idBuffer) == -1)
				{
					cout << "찾는 계좌가 없습니다. 다시 입력하세요" << endl;
				}
				else
				{
					cout << "출금액 : ";
					cin >> moneyBuffer;
					location = handler.Search(idBuffer);
					int money = handler.CurrentMoney(location);
					if (moneyBuffer > money)
					{
						cout << "잔액이 부족합니다!!!" << endl;
						handler.ShowMeTheMoney(location);
						cout << "출금액을 다시 입력하세요 : " << endl;
						cout << "출금액 : ";
						cin >> moneyBuffer;
					}
					location = handler.Search(idBuffer);
					handler.OutputMoney(moneyBuffer, location); //입력한 id 위치에 돈을 넣음
					handler.ShowMeTheMoney(location);
					a = false;
				}
			}
			a = true;
			break;

		case 4:
			cout << "[전체 출력] " << endl;
			handler.print();
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

