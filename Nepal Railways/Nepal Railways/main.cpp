//-----------------------------------------------------------------------------------
//------------------------------HEADER FILES-----------------------------------------
//-----------------------------------------------------------------------------------
#include  <sstream>				// String Stream Function
#include  <mysql.h>				// Database File
#include  <iostream>			// Basic Input Output File
#include  <stdio.h>				// For Input Output
#include  <conio.h>				// Getch and cls
#include  <process.h>			// Exit Function
#include  <string>				// String Calculations
#include  <iomanip>				//getline function
#include  <Windows.h>			// Password Method
#include  <cstdlib>				// For random Function




using namespace std;

//---------------------------------------------------------------------------------
//-----------------------DATABASE VARIABLES----------------------------------------
//---------------------------------------------------------------------------------
MYSQL* connection;
MYSQL_ROW row;
MYSQL_RES* res;

//--------------------------------------------------------------------------------
//----------------------------OUTPUT EDIT VARIABLE--------------------------------
//--------------------------------------------------------------------------------
int c;

//--------------------Book Tickets-----------------------------------------------
int book_ticket(int);
int cancel_ticket(int);

//--------------------------------------------------------------------------------
//----------------------Rows in tale calculate------------------------------------
//--------------------------------------------------------------------------------
int rows_in_trains;

//---------------------------------------------------------------------------------
//-------------- Mode Function for Main Cpp----------------------------------------
//---------------------------------------------------------------------------------
int mode();		// Mode Selection

//---------------------------------------------------------------------------------
//-----------------Password And check Function Declartion-------------------------
//---------------------------------------------------------------------------------
string takePassFromUser();
int Pass_check(string ,string);



//---------------------------------------------------------------------------------
//---------------------------------DATABASE CONNECTION-----------------------------
//---------------------------------------------------------------------------------
///---------------------------- Connection Check-----------------------------------
int sqlconn() {
	connection = mysql_init(0);
	connection = mysql_real_connect(connection, "localhost", "root", "", "db_nepalrailways", 3306, NULL, 0);
	if (connection)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
///-----------------insert command for any records-----------------------------------///

int insert(const char* query) {
	int state = 0;
	state = mysql_query(connection, query);
	if (state == 0)
	{
		return 1;
	}
	else
	{
		return 0;

	}

}

///-----------------select command for any records--------------------------------------///
void rec_select(const char* query) {
	if (connection)
	{
		int qstate = mysql_query(connection, query);
		if (!qstate)
		{
			res = mysql_store_result(connection);
		}
	}

}

///-----------------delete command for any records--------------------------------------///
int delete_r(const char* query) {
	if (connection)
	{
		int state2 = mysql_query(connection, query);
		if (state2 == 0)
		{
			return 1;
		}
		else {
			return 0;
		}
	}

}

///-----------------edit command for any records----------------------------------------///
int edit(const char* query) {
	if (connection)
	{
		int state3 = mysql_query(connection, query);
		if (state3 == 0)
		{
			return 1;
		}
		else {
			return 0;
		}
	}
}




 

	/// -------------------------------------------------------------------
	/// --------------------------------USER CONTROL---------------------//
	/// -------------------------------------------------------------------

	string username;		// Username
	int c_id;


		class uDesign   // Class for User and Beginning Page
	{
	public:
		void topprint()   //Welcome Lines
		{
			system("cls");
			cout << "\n          _____     __      _______        _______         ___          __                        ________           ___          __     __           __     __          ___       __       __   _______        ";
			cout << "\n*********|     \\   |  |    |  _____|      |   __  |       /   \\        |  |                      |   __   |         /   \\        |  |   |  |         |  |   |  |       /    \\      \\  \\   /  /  |   ____|********";
			cout << "\n*********|  |\\  \\  |  |    |  |____       |  |__| |      /  /\\ \\       |  |                      |  |__|  |        /  /\\ \\       |  |   |  |         |  |   |  |      /  /\\  \\      \\  \\_/  /   |  |____ ********";
			cout << "\n*********|  | \\  \\ |  |    |   ____|      |   ____|     /  ___  \\      |  |                      |      __|       /  ___  \\      |  |   |  |         |  | _ |  |     /  ___   \\      \\     /    |____   |********";
			cout << "\n*********|  |  \\  \\|  |    |  |____       |  |         /  /   \\  \\     |  |____                  |  |\\  \\        /  /   \\  \\     |  |   |  |____     |  |/_\\|  |    /  /    \\  \\      |   |      ____|  |********";
			cout << "\n*********|__|   \\_____|    |_______|      |__|        /__/     \\__\\    |_______|                 |__| \\__\\      /__/     \\__\\    |__|   |_______|    |___/ \\___|   /__/      \\__\\     |___|     |_______|********";
			cout << "\n\n";
		}


		int uname() {			// User Input Name Case User


			topprint();
			cout << "\n\n\n\n\t\t\t\t Please, Enter Your Name: ";
			cin >> ws;
			getline(cin, username);
		 	cout << "\n\n\n\t\t\t Press any Key to Continue....";
			_getch();
			uwelcome();
			return 0;

		}

		int uwelcome()		// Welcome Screen and User Choice Service
		{
				int Identity;
			topprint();
			cout << "\n\n \t\t\t You are most Welcome," << username;
			cout << "\n\n\n\t\t\t 1. Train Schedule";
			cout << "\n\n\t\t\t 2. No. of Seats";
			cout << "\n\n\t\t\t 3. Book Ticket";
			cout << "\n\n\t\t\t 4. Cancel Tickets";
			cout << "\n\n\t\t\t 5. Main Page";
			cout << "\n\n\t\t\t 6. Exit";
			cout << "\n\n\n\n\t\t\t Enter your choice(1-6): ";
			cin >> choice2;
			switch (choice2)
			{
			case '1':
				trains();
				break;

			case '2':
				tseats();
				break;

			case'3':
			{	
				
				cout << "\n\n\t\t Enter The ID of Train:\t";
				cin >> ws;
				cin >> Identity;
				book_ticket(Identity);
			}
				break;
			case'4':
			{

				cout << "\n\n\t\t Enter The ID of Train:\t";
				cin >> ws;
				cin >> Identity;
				cancel_ticket(Identity);
			}
			break;

			case '5':
				mode();
				break;
			case '6':
				exit(0);
				break;
			
			default:
				cout << "\n\n\n\t\t\t !!! ERROR IN INPUT  !!!";
				cout << "\n\n \t\t\t Press any key to go to back menu.....";
				_getch();
				uwelcome();
				break;
			}

			return 0;

		}
		int trains()				// Trains Scheduling Destination Check and Output Accordingly
		{
			topprint();
			cout << "\n\t\t\t\t\t Please Enter the Train ID .....\n";
			cout << "\n\n\n\t\t\t\t Train ID:  ";
			cin >> c_id;
			//------------------------------------------------------------------------
			//---------------------------- Checking according to User-----------------
			//-------------------------------------------------------------------------
			stringstream query_holder0;
			query_holder0 << "select * from trains where ID = " << c_id;
			string temp_query0 = query_holder0.str();
			const char* final_query0 = temp_query0.c_str();

			rec_select(final_query0);
			rows_in_trains = mysql_num_rows(res);

			if (rows_in_trains == 0)
			{
				cout << "\n\n\n\n\t\t\t\t\tNo Record Found";
			}

			else
			{
				cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t Trains List ";
				cout << "\n\n\t Trains ID" << "\t\t" << "Name" << "\t\t\t" << "Start Point" << " " << "Destination" << "\t" << "Total Seats" << "\t" << "Available Seats" << " \t" << " Cost" << "\t\t" << "Time\n";
				cout << "\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
				while ((row = mysql_fetch_row(res)))
				{

					cout << "\t" << row[0] << "\t\t" << row[1] << "\t\t" << row[2] << "\t\t" << row[3] << "\t\t" << row[4] << "\t\t" << row[5] << "\t\t\t" << row[6] << "\t\t" << row[7] << " \n";
					cout << "\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";

				}

				cout << "\n\n\t\t\t\t Press any key to continue........";
			
			}
			_getch();
			uwelcome();
		}

		//------------------------------------------------------------------------------------------------------------------------
		//-----------------------------------------No. of Seats according to User-------------------------------------------------
		//------------------------------------------------------------------------------------------------------------------------

		int tseats()					// No. of seats in train
		{
			topprint();
			cout << "\n\n\n\t\t\t Train ID: ";
			cin >> tcode;
			stringstream query_holder01;
			query_holder01 << "select ID,Total_Seats,Av_Seats from trains where ID =" << tcode;
			string temp_query01 = query_holder01.str();
			const char* final_query01 = temp_query01.c_str();

			rec_select(final_query01);
			rows_in_trains = mysql_num_rows(res);

			if (rows_in_trains == 0)
			{
				cout << "\n\n\n\n\t\t\t\t\tNo Record Found";
			}

			else
			{
				
				row = mysql_fetch_row(res);
				cout << "\n\n\t\t\t Total Seats: " << row[1];
				cout << "\n\n\t\t\t Available Seats: " << row[2];
				cout << "\n\n\n\n\n\t\t\t\t !!THANKS FOR USING NEPAL RAILWAYS!!";
				cout << "\n\n\t\t\t\t\t Press any key to Continue.......";

			}
			_getch();
			uwelcome();
		}

		char  choice2;		// Choice for different Options
		int tcode;					// Train Code to fetch from database



	private:

	};

//----------------------------------------------------------------------------------------------
//-------------------------------------ADMIN CONTROL PANEL------------------------------------//
//----------------------------------------------------------------------------------------------

	int ID, seats;
	string Name, Start, Destiny, Train_time;
	float cost;
	char check;

	class admindesign : public uDesign {

	public:
		int adminlogin();  // Admin Login Page for Employees

	protected:
		int admincontrol(); // Control Panel for Admins i.e. Employees of Railways //*
		int addtrain();		// Function For Adding Trains
		int edittrain();	// Functions for Editing Train Details
		int deletetrain();	// Function for Deleting Trains
		int viewtrain();	// View Train Details

	protected:
		string adminname, adminpass;
		char choice3;

	};

	int admindesign::adminlogin() {

		topprint();
		cout << "\n\n\n\t\t\t\t Username: ";  // Username of Employee
		cin>>ws;
		cin >> adminname;
		cout << "\n\n\t\t\t\t Password: ";   // Password of Employee
		cin>>ws;
		adminpass = takePassFromUser();
		int check123;
		check123=Pass_check(adminname,adminpass);
		if (check123 == 1)
		{
			admincontrol();
		}
		else
		{
			cout << "\n\n\n Wrong Input !! \n Press any key to Continue.....";
			_getch();
			mode();
		}
		_getch();
		
		return 0;
	}

	int admindesign::admincontrol() {

		topprint();
		cout << "\n\n\n\t\t\t\t\t\t\t\t\t!!!!!!!Trains Control Panel !!!!!!!"; /// Front Control Panel Title
		cout << "\n\n\n\n\t\t 1. Add new Train";					/// New Train Addition
		cout << "\n\n\t\t 2. View Trains";							///View the Details of available Trains
		cout << "\n\n\t\t 3. Edit Trains";							/// Edit the Information of Trains
		cout << "\n\n\t\t 4. Delete Trains";						/// Delete the Train and its Details
		cout << "\n\n\t\t 5. Log Out";								/// Log out from admin and go to main menu
		cout << "\n\n\t\t 6. Exit";									/// Exit from the program
		cout << "\n\n\n\n\t\t\t\t Enter Your Choice(1-6): ";
		cin >> choice3;

		switch (choice3)
		{
				
		case '1':
			addtrain();
			break;

		case'2':
			viewtrain();
			break;
		case '3':
			edittrain();
			break;
		case '4':
			deletetrain();
			break;
		case '5':
			mode();
			break;
		case'6':
			exit(0);
			break;
		default:
			cout << "\n\n\n\t\t\t !!ERROR IN INPUT!!";
			_getch();
			admincontrol();
			break;
		}

		return 0;
	}

	int admindesign::addtrain() {
		topprint();
		cout << "\n\t\t\t\t\t\t\t ADDITION OF TRAINS";
		cout << "\n\n\t\t !! ID and Time cannot be changed!!So, Enter the correct Information..........";		//-------------------NOTICE
		cout << "\n\n\n\t\t Train ID: \t";
		cin >> ws;
		cin >> ID;
		cout << "\n\n\t\t Name of the Train: \t";
		cin>>ws;
		getline(cin, Name);
		cout << "\n\n\t\t Starting Place : \t";
		cin>>ws;
		getline(cin, Start);
		cout << "\n\n\t\t Final Destination: \t";
		cin>>ws;
		getline(cin, Destiny);
		cout << "\n\n\t\t Total No. of Seats: \t";
		cin>>ws;
		cin >> seats;
		cout << "\n\n\t\t Cost of per Tickets: \t";
		cin >> cost;
		cout << "\n\t\t Time(YYYY-MM-DD HH:MM:SS ): \t";
		cin>>ws;
		getline(cin, Train_time);

		//------ Query Making for Entry in Database-----//
		stringstream query;
		query << "INSERT INTO `trains` (`ID`, `Name`, `Start`, `Destiny`, `Total_Seats`, `Av_Seats`, `Cost`, `Time`) VALUES('" << ID << "', '" << Name << "', '" << Start << "', '" << Destiny << "', '" << seats << "', '" << seats << "', '" << cost << "', '" <<Train_time<<"')";
		string temp_query = query.str();
		const char* final = temp_query.c_str();


		//**------------------------- Calling Database Function---------------//
		int temp;
		temp = insert(final);
		if (temp == 1)
		{
			cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\t !!! Train Added Successfully !!!";

		}
		else
		{
			cout << "\n\n\n\n\t\t\t\t\t\t  !!! Error in Database !!! ";
			cout << mysql_errno(connection);
		}
		_getch();
		admincontrol();
		
	}

	int admindesign::edittrain() {
		topprint();
		cout << "\n\n\n\t\t Enter the ID of the train:";
		cin >>ID ;
		cout << "\n\n\n\t\t Enter the value you want to edit";
		cout << "\n\n\t 1. Name";
		cout << "\n\t 2. Start Place";
		cout << "\n\t 3. Destination ";
		cout << "\n\t 4. Total Seats";
		cout << "\n\t 5. Cost of Tickets";
		cout << "\n\n\n\t\t Enter Your Choice(1-5):\t";
		cin >> check;
		switch (check)
		{
		case '1':
			{
			cout << "\n\n\t\t Name of the Train: \t";
			cin >> ws;
			getline(cin, Name);
			//---------------------------------------------------------------------------
			//---------------------EDIT NAME---------------------------------------------
			//---------------------------------------------------------------------------
			stringstream query1;
			query1 << "UPDATE `trains` SET Name = '" << Name << "' WHERE ID =" << ID;
			string temp_query1 = query1.str();
			const char* final1 = temp_query1.c_str();

			c = edit(final1);

			if (c == 1)
				{
					cout << "\n\n\n\n\t\t\t\t !!!RECORD UPDATED SUCCESSFULLY!!!";
					_getch();
				}
			else
				{
					cout << "\n\n\n\n\t\t\t\t !!!RECORD NOT UPDATED. TRY AGAIN!!!";
					_getch();
					edittrain();

				}
			}
			break;

		case '2':
		{
			cout << "\n\n\t\t Starting Place : \t";
			cin >> ws;
			getline(cin, Start);
			//---------------------------------------------------------------------------
			//---------------------Starting Place Edit----------------------------------
			//---------------------------------------------------------------------------
			stringstream query3;
			query3 << "UPDATE `trains` SET Start = '" << Start << "' WHERE ID =" << ID << ";";
			string temp_query3 = query3.str();
			const char* final3 = temp_query3.c_str();

			c = edit(final3);

			if (c == 1)
			{
				cout << "\n\n\n\n\t\t\t\t !!!RECORD UPDATED SUCCESSFULLY!!!";
				_getch();
			}
			else
			{
				cout << "\n\n\n\n\t\t\t\t !!!RECORD NOT UPDATED. TRY AGAIN!!!";
				_getch();
				edittrain();

			}
		}
		break;
		case '3':
		{
			cout << "\n\n\t\t Final Destination: ";
			cin >> ws;
			getline(cin, Destiny);
			//---------------------------------------------------------------------------
			//---------------------DEstination Place Edit----------------------------------
			//---------------------------------------------------------------------------
			stringstream query4;
			query4 << "UPDATE `trains` SET Destiny = '" << Start << "' WHERE ID =" << ID << ";";
			string temp_query4 = query4.str();
			const char* final4 = temp_query4.c_str();

			c = edit(final4);

			if (c == 1)
			{
				cout << "\n\n\n\n\t\t\t\t !!!RECORD UPDATED SUCCESSFULLY!!!";
				_getch();
			}
			else
			{
				cout << "\n\n\n\n\t\t\t\t !!!RECORD NOT UPDATED. TRY AGAIN!!!";
				_getch();
				edittrain();

			}
		}
			break;
		case '4':
		{
			cout << "\n\n\n\n\t\t\t Enter the Number of Seats:";
			cin >> ws;
			cin >> seats;
			//---------------------------------------------------------------------------
			//---------------------Number of Seats Edit----------------------------------
			//---------------------------------------------------------------------------
			stringstream query2;
			query2 << "UPDATE `trains` SET Total_Seats = " << seats << " WHERE ID =" << ID;
			string temp_query2 = query2.str();
			const char* final2 = temp_query2.c_str();

			c = edit(final2);

			if (c == 1)
			{
				cout << "\n\n\n\n\t\t\t\t !!!RECORD UPDATED SUCCESSFULLY!!!";
				_getch();
			}
			else
			{
				cout << "\n\n\n\n\t\t\t\t !!!RECORD NOT UPDATED. TRY AGAIN!!!";
				_getch();
				edittrain();

			}
		}
			break;

		case '5':
		{
			cout << "\n\n\t\t Cost of per Tickets: ";
			cin >> cost;
			//---------------------------------------------------------------------------
			//---------------------Cost of Tickets Edit----------------------------------
			//---------------------------------------------------------------------------
			stringstream query5;
			query5 << "UPDATE `trains` SET Cost = " << Start << " WHERE ID =" << ID << ";";
			string temp_query5 = query5.str();
			const char* final5 = temp_query5.c_str();

			c = edit(final5);

			if (c == 1)
			{
				cout << "\n\n\n\n\t\t\t\t !!!RECORD UPDATED SUCCESSFULLY!!!";
				_getch();
			}
			else
			{
				cout << "\n\n\n\n\t\t\t\t !!!RECORD NOT UPDATED. TRY AGAIN!!!";
				_getch();
				edittrain();

			}

		}
			break;

		default:
		{
			cout << "\n\n\n\n\n\t\t\t !!!ERROR IN INPUT!!!\n\t\t\t Press any key to Continue.....";
			_getch();
			edittrain();

		}
			break;
	}

		admincontrol();

	}

	int admindesign::deletetrain() {
		topprint();
		cout << "\n\n\t\t\t\t\t    !!!! DELETION OF TRAINS !!!!";
		cout << "\n\n\t\t Train ID, you want to delete : ";
		cin >> ID;
		stringstream query6;
		query6 << "DELETE FROM `trains`  WHERE ID =" << ID << ";";
		string temp_query6 = query6.str();
		const char* final6 = temp_query6.c_str();

		c = delete_r(final6);

		if (c == 1)
		{
			cout << "\n\n\n\n\t\t\t\t !!!RECORD DELETED SUCCESSFULLY!!!";
		}
		else
		{
			cout << "\n\n\n\n\t\t\t\t !!!RECORD NOT DELETED. TRY AGAIN!!!";
		
		}
		_getch();
		admincontrol();

	}
	int admindesign::viewtrain() {
		topprint();
		stringstream query_holder;
		query_holder << "select * from trains";
		string temp_query = query_holder.str();
		const char* final_query = temp_query.c_str();

		rec_select(final_query);
		rows_in_trains = mysql_num_rows(res);

		if (rows_in_trains == 0)
		{
			cout << "\n\n\n\n\t\t\t\t\tNo Record Found";
		}

		else
		{
			cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t Trains List ";
			cout << "\n\n\t Trains ID" << "\t\t\t"  << "Name" << "\t\t" << "Start Point" << "\t" << "Destination" << "\t" << "Total Seats" << "\t" << "Available Seats" << " \t" << " Cost" << "\t" << "Time\n";
			cout << "\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
			while ((row = mysql_fetch_row(res)))
			{
				
				cout <<"\t" << row[0] << "\t\t" << row[1] << "\t\t\t" << row[2] << "\t\t" << row[3] << "\t\t" << row[4] << "\t\t" << row[5] << "\t\t" << row[6] << "\t\t" << row[7] << " \n";
				cout << "\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
			
			}
			
			cout << "\n\n\t\t\t\t Press any key to continue........";			
		}
		_getch();
		admincontrol();
	}


//-------------------------------------------------------------------------------------------------------
//-------------------------------------Super Admin Panel-----------------------------------------------//
//-------------------------------------------------------------------------------------------------------


	class super : public admindesign {

	private:
		//------------------Variable Declaration
		string Super_name, Super_pass;



	public:
		//------------ Taking Login Credentials from Superadmin
		int Super_login() {

			topprint();
			cout << "\n\n\n\n\t\t\t\t\t SUPER ADMIN LOGIN PAGE";
			cout << "\n\n\n\t\t Username:\t";
			cin >> ws;
			getline(cin, Super_name);
			cout << "\n\n\t\t Password:\t";
			cin >> ws;
			getline(cin, Super_pass);
			Super_check(Super_name, Super_pass);
			return 0;
		}

	private:
		//---------------------- Checking the Credentials-------------------
		int Super_check(string user, string pass) {
			if (user == "NepalRailways" && pass == "Nepal") {
				cout << "\n\n\t\t\t !! YOU LOGGED IN SUCCESSFULLY !!";
				cout << "\n\n\t\t Press any key to continue......";
				_getch();
				Super_control();
			}

			else {
				cout << "\n\n\t\t !! ERROR IN YOUR CREDENTIALS !!";
				cout << "\n\n\t\t Press any key to continue......";
				_getch();
				mode();
			}

			return 0;
		}

		//-----------------------Super Admin Control Panel-----------------
		int Super_control() {
			char choice;
			topprint();
			cout << "\n\n\n\t\t\t ----------- SUPER ADMIN CONTROL PANEL ---------------";
			cout << "\n\n\t\t 1. Train Controls";
			cout << "\n\n\t\t 2. Admin Controls";
			cout << "\n\n\t\t 3. Log Out";
			cout << "\n\n\t\t 4. Exit";
			cout << "\n\n\n\n\t\t\t Enter Your Choice(1-4)";
			cin >> ws;
			cin >> choice;

			switch (choice) {

			case'1':
				admincontrol();
				break;
			case'2':
				Admin_check();
				break;
			case'3':
				mode();
				break;
			case'4':
				exit(0);
				break;
			default:
			{
				cout << "\n\n\n\t\t\t ERROR IN INPUT ";
				cout << "\n\n\n\t\t\t Press any key to continue....";
				_getch();
				Super_control();
			}
			break;
			}
			return 0;
		}


		int Admin_check() {
			char choice;
			topprint();
			cout << "\n\n\n\t\t\t\t ADMIN CONTROLS";
			cout << "\n\n\n\t\t 1. Add new Admin";
			cout << "\n\n\t\t 2. View Admin List";
			cout << "\n\n\t\t 3. Edit Admin Details";
			cout << "\n\n\t\t 4. Delete Admin";
			cout << "\n\n\t\t 5. Log Out";
			cout << "\n\n\t\t 6. Exit";
			cout << "\n\n\n\n\t\t\t Enter Your Choice(1-6):\t";
			cin >> ws;
			cin >> choice;

			switch (choice) {
			case'1':
				add_admin();
				break;
			case'2':
				view_admin();
				break;
			case'3':
				edit_admin();
				break;
			case'4':
				delete_admin();
				break;
			case'5':
				mode();
				break;
			case'6':
				exit(0);
				break;
			default:
			{
				cout << "\n\n\t\t\t ERROR INPUT";
				cout << "\n\t\t\t Press any key....";
				_getch();
				Admin_check();
			}
			}
			return 0;
		}

		int add_admin() {

			string Password, Qualification, Position, Sex, Name, Location;
			int ID, age;
			topprint();
			cout << "\n\n\n\n\n\t\t\t\t\t ADDITION OF NEW ADMIN";
			cout << "\n\n\n\t\t 1. Name :\t";
			cin >> ws;
			getline(cin, Name);
			cout << "\n\n\t\t 2. Address :\t";
			cin >> ws;
			getline(cin, Location);
			cout << "\n\n\t\t 3. Age :\t";
			cin >> ws;
			cin >> age;
			cout << "\n\n\t\t 4. Sex(Male/Female/Other) :\t";
			cin >> ws;
			getline(cin, Sex);
			cout << "\n\n\t\t 5. Position :\t";
			cin >> ws;
			getline(cin, Position);
			cout << "\n\n\t\t 6. Qualification :\t";
			cin >> ws;
			getline(cin, Qualification);
			cout << "\n\n\t\t 7. Password(For User) :\t";
			cin >> ws;
			getline(cin, Password);
			cout << "\n\n\t\t 8. ID for New Admin:\t";
			cin >> ws;
			cin>>ID;

			//---------------Insertion in table------------
			stringstream query;
			query << "INSERT INTO `admins` (`ID`, `Name`, `Location`, `Age`, `Sex`, `Position`, `Qualification`, `Password`) VALUES ('" << ID << "', '" << Name << "', '" << Location << "', '" << age << "', '" << Sex << "', '" << Position << "', '" << Qualification << "', '" << Password << "')";
			string temp_query = query.str();
			const char* final_query = temp_query.c_str();
			int choice;
			choice = insert(final_query);

			if (choice == 1)
			{
				cout << "\n\n\t\t\t !! RECORD ADDED SUCCESSFULLY";
			}

			else
			{
				cout << "\n\n\n\t\t\t !! ERROR IN DATABASE !!";
			}

			_getch();
			Admin_check();
			return 0;
		}

		//--------------- VIEW ADMMIN
		int view_admin() {

			topprint();
			//----------- Selection from table
			stringstream query_holder;
			query_holder << "select * from admins";
			string temp_query = query_holder.str();
			const char* final_query = temp_query.c_str();

			rec_select(final_query);
			int rows_in_admins = mysql_num_rows(res);

			if (rows_in_trains == 0)
			{
				cout << "\n\n\n\n\t\t\t\t\tNo Record Found";
			}

			else
			{
				cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t Admin List ";
				cout << "\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
				while ((row = mysql_fetch_row(res)))
				{

					cout << "\n\n\t ID\t: " << row[0] << "\n\t Name\t: " << row[1] << "\n\tAddress\t:" << row[2] << "\n\tAge\t:" << row[3] << "\n\tSex\t:" << row[4] << "\n\tPosition\t:" << row[5] << "\n\tQualification\t:" << row[6] << "\n\tPassword\t:" << row[7] << " \n";
					cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------\n\n";

				}

				cout << "\n\n\t\t\t\t Press any key to continue........";
			}
			_getch();
			Admin_check();
			return 0;
		}


		//-------------------- Delete Train
		int delete_admin() {
			int ID;
			topprint();
			cout << "\n\n\t\t\t\t\t    !!!! DELETION OF ADMINS !!!!";
			cout << "\n\n\t\t Admin ID, you want to delete : ";
			cin >> ID;

			//---------------- Deletion From Table
			stringstream query03;
			query03 << "DELETE FROM admins where ID=" << ID;
			string temp_query03 = query03.str();
			const char* final03 = temp_query03.c_str();
			int c;
			c = delete_r(final03);

			if (c == 1)
			{
				cout << "\n\n\n\n\t\t\t\t !!!RECORD DELETED SUCCESSFULLY!!!";
			}
			else
			{
				cout << "\n\n\n\n\t\t\t\t !!!RECORD NOT DELETED. TRY AGAIN!!!";
			}

			_getch();
			Admin_check();
			return 0;
		}

		//---------------------- Edit Admin Table----------------------------
		int edit_admin() {

			char choice;
			int ID;
			topprint();
			cout << "\n\n\n\t\t\t\t EDIT ADMINS";
			cout << "\n\n\n\t\t What value you want to edit?\n";
			cout << "\n\n\n\t\t 1. Name";
			cout << "\n\n\t\t 2. Address";
			cout << "\n\n\t\t 3. Age";
			cout << "\n\n\t\t 4. Position";
			cout << "\n\n\t\t 5. Qualification";
			cout << "\n\n\t\t 6. Password";
			cin >> ws;
			cin >> choice;

			cout << "\n\n\n\t\t ID of Admin:\t";
			cin >> ws;
			cin >> ID;
			stringstream query_holder;

			string Password, Qualification, Position, Sex, Name, Location;
			int Age;

			switch (choice) {
			case '1': {
				cout << "\n\n\t\t New Name:\t";
				cin >> ws;
				getline(cin, Name);
				query_holder << "UPDATE admins SET Name='" << Name << "' WHERE ID=" << ID;
			}
					break;
			case '2': {
				cout << "\n\n\t\t New Address:\t";
				cin >> ws;
				getline(cin, Location);
				query_holder << "UPDATE admins SET Location='" << Location << "' WHERE ID=" << ID;
			}
					break;
			case '3': {
				cout << "\n\n\t\t New Age:\t";
				cin >> ws;
				cin >> Age;
				query_holder << "UPDATE admins SET Age=" << Age << " WHERE ID=" << ID;
			}
					break;
			case '4': {
				cout << "\n\n\t\t New Position:\t";
				cin >> ws;
				getline(cin, Position);
				query_holder << "UPDATE admins SET Position='" << Position << "' WHERE ID=" << ID;
			}

					break;
			case '5': {
				cout << "\n\n\t\t New Qualification:\t";
				cin >> ws;
				getline(cin, Qualification);
				query_holder << "UPDATE admins SET Qualification='" << Qualification << "' WHERE ID=" << ID;
			}

					break;
			case '6': {
				cout << "\n\n\t\t New Password:\t";
				cin >> ws;
				getline(cin, Password);
				query_holder << "UPDATE admins SET Password='" << Password << "' WHERE ID=" << ID;
			}

					break;
			default: {
				cout << "\n\n\n\t\t ERROR IN DATABASE";
				_getch();
				Admin_check();
			}
				   break;
			}

			string temp_query = query_holder.str();
			const char* final_query = temp_query.c_str();
			int choice1;
			choice1 = edit(final_query);
			if (choice1 == 1)
			{
				cout << "\n\n\n\t\t\t !! RECORD UPDATED SUCCESSFULLY !!";
			}

			else {
				cout << "\n\n\n\t\t\t !! ERROR IN DATABASE !!";
			}

			_getch();
			Admin_check();
			return 0;
		}
	};
//-------------------------------------------------------------------------------------------------------
//-----------------------------------------MAIN FUNCTION-----------------------------------------------//
//-------------------------------------------------------------------------------------------------------
int main() {
				super s;
				int vcheck = sqlconn();
				if (vcheck == 1)
				{
					s.topprint();
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t !! DATABASE  CONNECTED !!\n";
					cout << "\t\t\t\t\t\t\t\t\t Press any key to Continue......";
					_getch();
					mode();
				}

				else
				{
					s.topprint();
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t !! DATABASE NOT  CONNECTED !!\n";
					cout << "\t\t\t\t\t\t\t\t\t Press any key to Exit......";
					_getch();
					exit(0);
				}


				_getch();
				return 0;
		}


//--------------------------------------------------------------------------------------------------------
//------------------------------------------Mode Function for main Selection----------------------------//
//--------------------------------------------------------------------------------------------------------

// Global Variables
		char choice;

		int	mode() {		// Mode Selection 
				super u;


				u.topprint();
				cout << "\n\n\n\t\t\t 1. Super Admin ";
				cout << "\n\n\t\t\t 2. Admin ";
				cout << "\n\n\t\t\t 3. User ";
				cout << "\n\n\t\t\t 4. Exit";
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t Enter your choice(1-4):\t";
				cin >> choice;
				switch (choice)
				{
				case '1':
					u.Super_login();
					break;
				case '2':
					u.adminlogin();
					break;
				case '3':
					u.uname();
					break;
				case '4':
					exit(0);
					break;

				default:
					cout << "\n\n\n\t\t\t !!! ERROR IN INPUT  !!!";
					cout << "\n\n \t\t\t Press any key to go to back menu.....";
					_getch();
					mode();
					break;
				}
				return 0;
		}




		//-----------------------------------------------------------------------------------------
		// ---------------------------------------PASSWORD TAKING--------------------------------//
		// ----------------------------------------------------------------------------------------
		string takePassFromUser()
		{
			HANDLE hStdInput
				= GetStdHandle(STD_INPUT_HANDLE);
			DWORD mode = 0;

			// Create a restore point Mode
			// is know 503
			GetConsoleMode(hStdInput, &mode);

			// Enable echo input
			// set to 499
			SetConsoleMode(
				hStdInput,
				mode & (~ENABLE_ECHO_INPUT));

			// Take input
			string ipt;
			getline(cin, ipt);

			// Otherwise next cout will print
			// into the same line
			cout << endl;

			// Restore the mode
			SetConsoleMode(hStdInput, mode);

			return ipt;
		}


		//---------------Password Check for Admins

		int Pass_check(string name, string pass) {

			stringstream query;
			query << "SELECT * FROM admins where ID=" << pass << " AND Password='" << pass << "';";
			string temp_query = query.str();
			const char* final_query = temp_query.c_str();

			rec_select(final_query);
			int rows_in_admins = mysql_num_rows(res);

			if (rows_in_trains == 1)
			{
				cout << "\n\n\n\n\t\t\t\t\t !!YOU LOGGED IN SUCCESSFULLY!!";
				cout << "\n\n\n\t\t\t Press any key to Continue.....";
				_getch();
				return 1;
			}
			else {

				return 0;
			}
		}

		//--------------------------Ticket Booking and Cancellation-----------
		int book_ticket(int train_no) {
			uDesign obj;
			int Av_Seats;
			//-------------------------Passing Query------------------
			stringstream query;
			query << "SELECT Av_Seats FROM trains WHERE ID=" << train_no << ";";
			string temp_query = query.str();
			const char* final_query = temp_query.c_str();

			rec_select(final_query);

			//-------------------- Checking-----------
			int rows_in_admins = mysql_num_rows(res);

			if (rows_in_admins == 0)
			{
				cout << "\n\n\t !! No Such Train is Available !!";
				_getch();

			}

			else {

				//-------------- Calculation
				row = mysql_fetch_row(res);
				Av_Seats =atoi(row[0]);
				Av_Seats = Av_Seats - 1;

				//----------------- Passing Query----------
				stringstream query0;
				query0 << "UPDATE trains SET Av_Seats=" << Av_Seats << "WHERE ID=" << train_no << ";";
				string temp_query0 = query0.str();
				const char* final_query0 = temp_query0.c_str();
				int choice;
				choice = edit(final_query0);

				//------------- Checking----------------------------

				if (choice == 1)
				{
					cout << "\n\n\n\t\t Your Ticket is Booked Successfully !!";
					_getch();

				}

				else {
					cout << "\n\n\n\t\t\t No Seats are Available";
					_getch();
				}
				obj.uwelcome();

			}

			return 0;

		}

		int cancel_ticket(int train_no) {
			uDesign obj;
			int Av_Seats;
			//-------------------------Passing Query------------------
			stringstream query;
			query << "SELECT Av_Seats FROM trains WHERE ID=" << train_no << ";";
			string temp_query = query.str();
			const char* final_query = temp_query.c_str();

			rec_select(final_query);

			//-------------------- Checking-----------
			int rows_in_admins = mysql_num_rows(res);

			if (rows_in_admins == 0)
			{
				cout << "\n\n\t !! No Such Train is Available !!";
				_getch();

			}

			else {

				//-------------- Calculation
				row = mysql_fetch_row(res);
				Av_Seats = atoi(row[0]);
				Av_Seats = Av_Seats + 1;

				//----------------- Passing Query----------
				stringstream query0;
				query0 << "UPDATE trains SET Av_Seats=" << Av_Seats << "WHERE ID=" << train_no << ";";
				string temp_query0 = query0.str();
				const char* final_query0 = temp_query0.c_str();
				int choice;
				choice = edit(final_query0);

				//------------- Checking----------------------------

				if (choice == 1)
				{
					cout << "\n\n\n\t\t Your Ticket is Cancelled Successfully !!";
					_getch();

				}

				else {
					cout << "\n\n\n\t\t\t No Seats are Available";
					_getch();
				}
				obj.uwelcome();

			}

			return 0;

		}