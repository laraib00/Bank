
  //-------------------------------------MAXIMIZE  YOUR  OUTPUT  WINDOW  BEFORE  VIEWING  THIS  PROGRAM---------------------------------------------//




//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<iostream>
#include<fstream>
#include<ctime>
#include<cctype>
#include<iomanip>
using namespace std;

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************
int ab ;		//var for back opt choice
//int acc;		//var for administration PIN

class account
{
	int acno ,pin ;
	char name[50];
	int deposit;
	char type;
public:
	void create_account();	//function to get data from user
	void show_account() const;	//function to show data on screen
	void modify();	//function to add new data
	void dep(int);	//function to accept amount and add to balance amount
	void draw(int);	//function to accept amount and subtract from balance amount
	void report() const;	//function to show data in tabular format
	int retacno() const;	//function to return account number
	int retdeposit() const;	//function to return balance amount
	char rettype() const;	//function to return type of account
	int retpin() const;
};         //class ends here

void account::create_account()
{
	cout<<"\n\t\t\t   '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''"<<endl;
	cout<<"\t\t\t   '"<<endl;
	cout<<"\t\t\t   '   Enter The account No. :";
	cin>>acno;
	cout<<"\t\t\t   '"<<endl;
	cout<<"\t\t\t   '"<<endl;
	cout<<"\t\t\t   '   Enter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\t\t\t   '"<<endl;
	cout<<"\t\t\t   '"<<endl;
	cout<<"\t\t\t   '   Enter Type of The account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\t\t\t   '"<<endl;
	cout<<"\t\t\t   '"<<endl;
	cout<<"\t\t\t   '   Set Your 4-digit PIN Code : ";
	cin>>pin;
	cout<<"\t\t\t   '"<<endl;
	cout<<"\t\t\t   '"<<endl;
	cout<<"\t\t\t   '   Enter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin>>deposit;
	cout<<"\t\t\t   '"<<endl;
	cout<<"\t\t\t   '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''"<<endl;
	cout<<"\n\n\n\t\t\t\t\t\tAccount Created Successfully!"<<endl;
	
}

void account::show_account() const
{
	cout<<"\n\t\t\t\t      Your Account Details Are :"<<endl;
	cout<<"\n\t\t\t\t      Account No. : "<<acno;
	cout<<"\n\t\t\t\t      Account Holder Name : ";
	cout<<name;
	cout<<"\n\t\t\t\t      Type of Account : "<<type;
	cout<<"\n\t\t\t\t      Balance amount : "<<deposit;
}


void account::modify()
{
	cout<<"\n\t\t\t\t      Account No. : "<<acno;
	cout<<"\n\t\t\t\t      Modify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\t\t\t\t      Modify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\t\t\t\t      Modify Balance amount : ";
	cin>>deposit;
	cout<<"\t\t\t\t      Modify PIN : ";
	cin>>pin;
	
}

	
void account::dep(int x)
{
	deposit+=x;
}
	
void account::draw(int x)
{
	deposit-=x;
}
	
void account::report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(10)<<deposit<<setw(10)<<pin<<endl;
}

	
int account::retacno() const
{
	return acno;
}

int account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return type;
}

int account::retpin() const
{
	return pin;
}


//***************************************************************
//    	function declaration
//****************************************************************
void write_account();	//function to write record in binary file
void display_sp(int, int);	//function to display account details given by user
void modify_account(int, int);	//function to modify record of file
void delete_account(int, int);	//function to delete record of file
void display_all();		//function to display all account details
void deposit_withdraw(int, int, int); // function to desposit/withdraw amount for given account
void intro();	//introductory screen function
void menu();
void hp();

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************


int main()
{
	hp();
	intro();

	return 0;
}


//***************************************************************
//    	THE MENU FUNCTION OF PROGRAM
//****************************************************************

void menu()
{
	
	char ch;
	int num ,no;
		do
	{
		system("cls");
		cout << "\t\t\t\t'''''''''''''''''''''''''''''''''''''''''''''''''''''''''"   << endl;
		cout << "\t\t\t\t'                     MENU                              '\n" << endl;
		cout << "\t\t\t\t'            Enter [1]  for  New Account                '\n" << endl;
		cout << "\t\t\t\t'            Enter [2]  for  Deposit Cash               '\n" << endl;
		cout << "\t\t\t\t'            Enter [3]  for  Withdraw Cash              '\n" << endl;
		cout << "\t\t\t\t'            Enter [4]  for  Balance Inquiry            '\n" << endl;
		cout << "\t\t\t\t'            Enter [5]  for  All Account Holder List    '\n" << endl;
		cout << "\t\t\t\t'            Enter [6]  for  Close An Account           '\n" << endl;
		cout << "\t\t\t\t'            Enter [7]  for  Modify An Account          '\n" << endl;
		cout << "\t\t\t\t'            Enter [0]  for  Exit                       '\n" << endl;
		cout << "\t\t\t\t'''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n" << endl;
		cout << "\n\n\t\t\t\t      Choose one of the above options : ";
		cin>>ch;
		
		system("cls");
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			cout<<"\n\n\tEnter The account PIN : "; cin>>no;
			deposit_withdraw(num, no, 1);
			break;
		case '3':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			cout<<"\n\n\tEnter The account PIN : "; cin>>no;
			deposit_withdraw(num, no, 2);
			break;
		case '4': 
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			cout<<"\n\n\tEnter The account PIN : "; cin>>no;
			display_sp(num, no);
			break;
		case '5':
			display_all();
			break;
		case '6':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			cout<<"\n\n\tEnter The account PIN : "; cin>>no;
			delete_account(num, no);
			break;
		 case '7':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			cout<<"\n\n\tEnter The account PIN : "; cin>>no;
			modify_account(num, no);
			break;
		 case '0':
			intro();
			break;
		 default :
			cout<<"\a";
		    menu();
		}
		cin.ignore();
		cin.get();
	}while(ch!='8');
}


//***************************************************************
//    	function to write in file
//****************************************************************

void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.txt",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
	
	cout << "\n\t\t\t\t\t            Press [1] for  Menu                " << endl;
	cout << "\n\t\t\t\t\t            Enter [0]  for  Exit                " << endl;
	cout<<"\t\t\t\t\t\t\t    ";
	cin>>ab;
	if(ab==1)
	{
	menu();
	}
	if(ab==0)
	{
	intro();
	}
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_sp(int n, int p)
{
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.txt",ios::binary);
	if(!inFile)
	{
		cout<<"\n\t\t\t\t    File could not be open !! ";
		
		cout << "\n\n\t\t\t\t\t            Press [1] for  Menu                " << endl;
		cout << "\n\t\t\t\t\t            Enter [0]  for  Exit                " << endl;
		cout<<"\t\t\t\t\t\t\t    ";
		cin>>ab;
		if(ab==1)
		{
		menu();
		}
		if(ab==0)
		{
		intro();
		}
	}
	
	cout<<"\n\t\t\t\t      BALANCE DETAILS\n";

    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n && ac.retpin()==p)
		{
			ac.show_account();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
	{
		cout<<"\n\n\t\t\t\t             	      Invalid Details";
	}
	
	
		cout << "\n\n\t\t\t\t\t            Press [1] for  Menu                " << endl;
		cout << "\n\t\t\t\t\t            Enter [0]  for  Exit                " << endl;
		cout<<"\t\t\t\t\t\t\t    ";
		cin>>ab;
		if(ab==1)
		{
		menu();
		}
		if(ab==0)
		{
		intro();
		}
}


//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_account(int n ,int p)
{
	bool found=false;
	account ac;
	fstream File;
	File.open("account.txt",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"\n\t\t\t\t    File could not be open !! ";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read((char *) (&ac), sizeof(account));
		if(ac.retacno()==n && ac.retpin()==p)
		{
			ac.show_account();
			cout<<"\n\n\t\t\t\t    Enter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t\t\t\t\t  Account Updated Successfully!";
			found=true;
		  }
	}
	File.close();
	if(found==false)
	{
		cout<<"\n\n\t\t\t\t             	      Invalid Details";
	}
	
		
	cout << "\n\n\t\t\t\t\t            Press [1] for  Menu                " << endl;
	cout << "\n\t\t\t\t\t            Enter [0]  for  Exit                " << endl;
	cout<<"\t\t\t\t\t\t\t    ";
	cin>>ab;
	if(ab==1)
	{
		menu();
	}
	if(ab==0)
	{
		intro();
	}
}

//***************************************************************
//    	function to delete record of file
//****************************************************************


void delete_account(int n, int p)
{

	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.txt",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
		outFile.open("Temp.txt",ios::binary);
		inFile.seekg(0, ios::beg);
		{
			while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
			{
				if(ac.retacno()!=n || ac.retpin()!=p)
				{	
					outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
				}
				if(ac.retacno()==n && ac.retpin()==p )
				{
					inFile.close();
					outFile.close();
					remove("account.txt");
					rename("Temp.txt","account.txt");
					cout<<"\n\n\t\t\t\t\t     Account Deleted Successfully! ..";
				}
				else
				{
					cout<<"\n\n\t\t\t\t\t     Invalid Details!";
				}
			}
		}
		
		
	cout << "\n\n\t\t\t\t\t            Press [1] for  Menu                " << endl;
	cout << "\n\t\t\t\t\t            Enter [0]  for  Exit                " << endl;
	cout<<"\t\t\t\t\t\t\t    ";
	cin>>ab;
	if(ab==1)
	{
		menu();
	}
	if(ab==0)
	{
		intro();
	}
	
}

//***************************************************************
//    	function to display all accounts deposit list
//****************************************************************

void display_all()
{	
	int acc;
	account ac;
	ifstream inFile;
	inFile.open("account.txt",ios::binary);
	if(!inFile)
	{
		cout<<"\n\t\t\t\t    File could not be open !! ";
		return;
	}
	
	cout<<"\n\t\t\t\t    Enter PIN to access all Accounts : ";
	cin>>acc;
	
	{
		if(acc==0000)
		{
				cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
			cout<<"=======================================================\n";
			cout<<"A/c no.   NAME   Type   Balance   PIN\n";
			cout<<"=======================================================\n";
			while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
			{
				
				ac.report();
			}
			inFile.close();
		}
		else
		{
			cout<<"\n\t\t\t\t    Invalid PIN";
		}
		
	}
	
	cout << "\n\n\t\t\t\t\t            Press [1] for  Menu                " << endl;
		cout << "\n\t\t\t\t\t            Enter [0]  for  Exit                " << endl;
		cout<<"\t\t\t\t\t\t\t    ";
		cin>>ab;
		if(ab==1)
		{
		menu();
		}
		if(ab==0)
		{
		intro();
		}
}

//***************************************************************
//    	function to deposit and withdraw amounts
//****************************************************************

void deposit_withdraw(int n, int p, int option)
{
	int amt;
	bool found=false;
	account ac;
	fstream File;
	File.open("account.txt", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"\n\t\t\t\t    File could not be open !! ";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n && ac.retpin()==p)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\t\t\t\t      DEPOSIT AMOUNT ";
				cout<<"\n\n\t\t\t\t      Enter The amount to be deposited : ";
				cin>>amt;
				ac.dep(amt);
			}
			if(option==2)
			{
				cout<<"\n\n\t\t\t\t      WITHDRAW AMOUNT ";
				cout<<"\n\n\t\t\t\t      Enter The amount to be withdrawed : ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"Insufficient balance";
				else
					ac.draw(amt);
			}
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t\t\t\t\t      Action Performed Successfully!";
			found=true;
	       }
         }
	File.close();
			if(found==false)
			{
				cout<<"\n\n\t\t\t\t             	      Invalid Details";
			}
		
		cout << "\n\n\t\t\t\t\t            Press [1] for  Menu                " << endl;
		cout << "\n\t\t\t\t\t            Enter [0]  for  Exit                " << endl;
		cout<<"\t\t\t\t\t\t\t    ";
		cin>>ab;
		if(ab==1)
		{
		menu();
		}
		if(ab==0)
		{
		intro();
		}
}


//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void hp()
{
	system("Color f0" );
	cout<<"\n\n\t\t\t *******C++ PROJECT*******"<<endl;
	cout<<"\n\n\t\t\t *******LARAIB FATIMA*******"<<endl;
	

	cout<<"\n\n\t\t\tPress [ENTER] to continue..."<<endl;
		cin.get();
}



void intro()
{
	int access;
system("Color f0" );
   		system("cls");
   		
   		cout << "\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO ATM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
   		cout << "\t\t\t\t''''''''''''''''''''''''''''''''''''''" << endl;
		cout << "\t\t\t\tCurrent date : ";
				time_t now;
	            time(&now);
	            cout<<("%s\n", ctime(&now)) << endl;
	    cout << "\t\t\t\t''''''''''''''''''''''''''''''''''''''" << endl;
	    cout << "\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
		cout << "\t\t\t\t  Press 1 to access or create account" << endl;
		cout << "\n\t\t\t\t\t\t" ;
		
		cin>>access;
		if(access==1)
		{
			menu();
		}
		if(access!=1)
		{
			cout<<"\a";
			intro();
		}
		cin.get();
}


//***************************************************************
//    			END OF PROJECT
//***************************************************************
