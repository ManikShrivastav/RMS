#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>

class interface{
	public:
	       char welcome(); //Welcome Page at the Beginning //  First page
	       void choice(char c1); //Choice for User to Enter the Software
	       void superinterface();// Super Admin beginning Interface
	       void admininterface(); // Admin Beginning Interface
	       void userinterface(); // User Beginning Interface
	       char usern[20]; // User Name of Train User(Passenger)

	};


/*class user{

	public:
		display();



	};

   */
char interface:: welcome() { // first page
	char choice;
		clrscr();
		cout<<"\n\t\t\t ! Welcome to Nepal Railways !\n";
		cout<<"\n\t 1. Super Admin";
		cout<<"\n\t 2. Admin";
		cout<<"\n\t 3. User";
		cout<<"\n\t 4. Exit";
		cout<<"\n\n\n\n\n\n\n\n\n\t Enter your choice(1-4):";
			cin>>choice;
			return (choice);

}

void interface:: choice(char c1){
		switch (c1) {
			case '1':
				superinterface();
				break;
			case '2':
				admininterface();
				break;
			case '3':
				userinterface();
				break;
			case '4':
				exit(1);
				break;
			default :
				cout<<"\n\n\n\t Wrong Input!! Do again";
				getch();
				welcome();
				break;
		}
	}

void  interface :: superinterface(){
		char suname[20],supass[30];
		clrscr();
		cout<<"\n\t\t\t ! Welcome to Nepal Railways !\n";
		cout<<"\n\n\t Username:";
			fflush(stdin);
			gets(suname);
		cout<<"\n\t Password:";
			for(int i=0;i<=30;i++){
				supass[i]=getch();

					if (supass[i] == 8) {
					cout<<" \b";
					 }
					else if (supass[i] ==10 ){
					 break;
					 }
					 else{
						cout<<"*";
					 }

						}

			welcome();
		}


void interface:: admininterface(){
			superinterface();

		}

void interface :: userinterface(){

		clrscr();
		cout<<"\n\t\t\t ! Welcome to Nepal Railways !\n";
		cout<<"\n\n\t\t Your Good Name: ";
		fflush(stdin);
		gets(usern);
		getch();

		}


int main(){

		interface a;
		a.choice(a.welcome());


		getch();
		return 0;

	}