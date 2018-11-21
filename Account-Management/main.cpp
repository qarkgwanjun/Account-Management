
#include <iostream>
#include <cstring>
#define SIZE 10

using namespace std;
bool a = true;

// 신용등급
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

// 계좌의 종류
enum { NORMAL = 1, CREDIT = 2 };


/*
 * 클래스 이름: Account
 * 클래스 유형: Entity 클래스
 */

class Account
{
private:
	int accID; 			//계좌번호
	int balance;    		//잔액
	char * cusName; 		//고객명
};


/*
 * 클래스 이름: NormalAccount
 * 클래스 유형: Entity 클래스
 */

class NormalAccount : public Account
{
private:
	int interRate;   		// 입금시 발생하는 이자율 %단위
};


/*
 * 클래스 이름: HighCreditAccount
 * 클래스 유형: Entity 클래스
 */

class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;		//기본이율에 추가되는 이자율
};


/*
 * 클래스 이름: AccountHandler
 * 클래스 유형: 컨트롤(Control) 클래스
 */

class AccountHandler
{
private:
	Account * accArr[100];	//계좌를 관리하는 배열
	int accNum;		//현재 등록된 계좌수
};
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

