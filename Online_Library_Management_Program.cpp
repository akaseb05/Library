#include <iostream> // For input and output operations
#include <fstream>  // For file handling operations
#include <stdlib.h> // For general purpose functions
#include <stdio.h>  // For standard input and output functions
#include <process.h> // For process control functions
#include <conio.h>  // For console input/output operations
#include <vector>	// For vector container functionality
using namespace std;
#define nl "\n"    // Macro for newline

// Function prototypes
int res_book(int,int);				//To check whether any book with a given book no. exists or not
/*Class of books*/
// Class definition: book
class book{
	// Member variables
	protected:
	int bno,quant;					//Book number and quantity
	char bname[50]; 				//Book name
	char aname[50]; 				//Book author's name
	char pname[50];  				//Publication name
	public:
		void createb();				// To enter data in data members of class book
		void showb();				// To display the details of books
		void showlist();			// To display book details in list form
		void assignbno(int x) {     // Assigns book number based on the number of objects in the file						    
			bno=10001;				//Number of objects in file
			bno+=x-1;
			start1:
				bno+=1;
				if(res_book(bno,0))
				goto start1;
		}
		void set_q() {				// Decrements quantity of book
			quant-=1;
		}
		int quantity() {				// Returns quantity of book
			return quant;
		}
		void reset_q() {				// Resets quantity of book
			quant+=1;
		}
		int retbno() {				// Returns book number
			return bno;
		} 
};
/*End of class book*/

class Reward {
private:
    int rewardNumber;
    string rewardName;
    double rewardValue;

public:
    // Constructor
    Reward(int number, const string& name, double value) : rewardNumber(number), rewardName(name), rewardValue(value) {}

    // Getter methods
    int getRewardNumber() const { return rewardNumber; }
    string getRewardName() const { return rewardName; }
    double getRewardValue() const { return rewardValue; }

    // Setter methods
    void setRewardName(const string& name) { rewardName = name; }
    void setRewardValue(double value) { rewardValue = value; }

    // Function to display reward details
    void displayReward() const {
        cout << "Reward Number: " << rewardNumber << endl;
        cout << "Reward Name: " << rewardName << endl;
        cout << "Reward Value: " << rewardValue << endl;
    }
};

// Function to delete a reward based on its number
void deleteReward(int number, vector<Reward>& rewards) {
    for (auto it = rewards.begin(); it != rewards.end(); ++it) {
        if (it->getRewardNumber() == number) {
            rewards.erase(it);
            cout << "Reward with number " << number << " deleted successfully." << endl;
            return;
        }
    }
    cout << "Reward with number " << number << " not found." << endl;
}

// Function to enter data in data members of class book
void book::createb() {
	int i;
	cout<<"\n\t\tEnter the details:-\n";
	cout<<"\n\t\tEnter Book's Name: ";
	char n[50];						// Using getline to input book name to handle spaces
	cin.getline(n,50);
	cin.getline(bname,50);			// Storing book name
	// Converting book name to uppercase
	for(i=0;bname[i]!='\0';i++) {
		if(bname[i]>='a'&&bname[i]<='z')
		bname[i]-=32;
	}
	cout<<"\n\t\tEnter Author's Name: ";
	// Using getline to input author's name to handle spaces
	cin.getline(aname,50);			// Storing author's name
	cout<<"\n\t\tEnter Publication Name: ";
	// Using getline to input publication name to handle spaces
	cin.getline(pname,50);			// Storing publication name
	cout<<"\n\t\tEnter Book's quantity: ";
	cin>>quant;						// Storing book quantity
}

// Function to display the details of books
void book::showb() {
	cout<<"\n\t\tBook No.: "<<bno<<nl; // Displaying book number
	cout<<"\n\t\tBook Name: "<<bname<<nl; // Displaying book name
	cout<<"\n\t\tBook's Author Name: "<<aname<<nl; // Displaying author name
	cout<<"\n\t\tBook's Publication: "<<pname<<nl; // Displaying publication name
	cout<<"\n\t\tBook's Quantity: "<<quant<<nl; // Displaying book quantity
}

// Function to display book details in list form
void book::showlist() {
	cout<<"\n\t"<<bno<<"\t\t"<<bname<<"\t\t"<<aname<<"\t\t"<<quant;
}


/*Class of Students*/
class student {
	protected:
		char name[25];					//Student name
		int bno;						//Book no. of the issued book
		int token;						// To verify if a book is issued or not
	public:
		void creates();					// Function to create student
		void shows();					// Function to show student
		void showlist();				// Function to show list of students
		void settoken(int x) {			// Function to set token and assign bno a book no.
			bno=x;
			token=1;
		}
		void resettoken() {				// Function to reset token
			bno=0;
			token=0;
		}
		int retbno(){					// Function to return book number
			return bno;
		}
		int admno;						//Admission No
};
/*End of class Students*/

// Function to check whether the admission no. already exists or not
bool res_student(int);					// Declaration
// Function to enter values to all data members of class student
void student::creates() {
	int i;
	plane:
	system("CLS");						// Clearing screen
	cout<<"\n\t\tEnter the details:-\n";
	cout<<"\n\t\tEnter student's Admission no: ";
	cin>>admno;							// Getting admission number
	if(res_student(admno)) {
		cout<<"\n\t\tRecord already exist with this admission no.";
		cout<<"\n\t\tEnter a different admission no.\n";
		system("PAUSE");				// Pausing screen
		goto plane;						// Jumping to label plane
	}
	cout<<"\n\t\tEnter student's Name: ";
	char n[50];
	cin.getline(n,50);					// Getting student's name
	cin.getline(name,25);
	for(i=0;name[i]!='\0';i++) {
		if(name[i]>='a'&&name[i]<='z')
		name[i]-=32;					// Converting name to uppercase
	}
	bno=0;								// Initializing book number to 0
	token=0;							// Initializing token to 0
}

// Function to show details of Students
void student::shows() {
	cout<<"\n\t\tStudent's Admission No.: "<<admno<<nl; // Displaying admission number
	cout<<"\n\t\tStudent's Name: "<<name<<nl; // Displaying student's name
	if(token==1) {
		cout<<"\n\t\tBook Issued (Book no): "<<bno; // Displaying issued book number
	}
}

// Function to display student details in list form
void student::showlist() {
	cout<<"\n\t"<<admno<<"\t\t"<<name<<"\t\t"<<bno; // Displaying student details in list format
}

// Function to write object of class book in file
void write_book() {						// Implementation omitted for brevity
	book bk;							// Create a book object
	ofstream outf("book1.bin",ios::app|ios::binary); // Open the file for writing in binary mode, appending to the end
	outf.seekp(0,ios::end); // Move the write pointer to the end of the file
	int x=outf.tellp()/sizeof(book); // Calculate the position to assign book number based on file size and size of book object
	bk.assignbno(x); // Assign book number to the book object
	bk.createb(); // Prompt user to enter book details
	bk.showb(); // Display the book details
	outf.write(reinterpret_cast<char *>(&bk),sizeof(book)); // Write the book object to the file
	cout<<"\n\t\tRecord added successfully"; // Inform user about successful record addition
	outf.close(); // Close the file
}

// Function to write object of class student in file
void write_student() {					
	student st; // Create a student object
	ofstream outf("student.bin",ios::app|ios::binary); // Open the file for writing in binary mode, appending to the end
	outf.seekp(0,ios::end); // Move the write pointer to the end of the file
	st.creates(); // Prompt user to enter student details
	st.shows(); // Display the student details
	outf.write(reinterpret_cast<char *>(&st),sizeof(student)); // Write the student object to the file
	cout<<"\n\t\tRecord added successfully"; // Inform user about successful record addition
	outf.close(); // Close the file
}

// Function to display student records in list form
void list_student() {					
	system("CLS"); // Clear the screen
	student st; // Create a student object
	ifstream intf("student.bin",ios::in|ios::binary); // Open the file for reading in binary mode
	intf.seekg(0,ios::beg); // Move the read pointer to the beginning of the file
	if(!intf) // If file does not exist or cannot be opened
	cout<<"\n\t\tFile not found";
	else {
		cout<<"\n\t*****Students Details*****\n\n";
		cout<<"\n\tAdmission No:\tName: \tBook Issued:";
		while(intf.read(reinterpret_cast<char *>(&st),sizeof(student)))
		st.showlist();
	}
	intf.close();
}

// Function to display book records in list form
void list_book() {						
	book bk;
	ifstream intf("book1.bin",ios::in|ios::binary);
	intf.seekg(0,ios::beg);
	if(!intf)
	cout<<"\n\t\tFile not found";
	else {
		cout<<"\n\t*****Books Details*****\n\n";
		cout<<"\n\tBook No:\t\tName: \t\tAuthor's Name: \t\tQuantity: ";
		while(intf.read(reinterpret_cast<char *>(&bk),sizeof(book)))
		bk.showlist();
	}
	intf.close();
}

// Function to search for a specific student
void search_student(int x) {			
	student st;
	int cnt=0;
	ifstream intf("student.bin",ios::in|ios::binary);
	intf.seekg(0,ios::beg);
	if(!intf)
	cout<<"\n\t\tFile not found";
	else {
		while(intf.read(reinterpret_cast<char *>(&st),sizeof(student))) {
			if(st.admno==x) {
				cnt++;
				cout<<"\n\t\tFILE FOUND!!!!";
				st.shows();
				break;
			}
		}
		if(cnt==0)
		cout<<"\n\t\tNo such record exists";
	}
	intf.close();
}

// Function to search for a specific book
void search_book(int x) {
	book bk;
	int cnt=0;
	ifstream intf("book1.bin",ios::in|ios::binary);
	intf.seekg(0,ios::beg);
	if(!intf)
	cout<<"\n\t\tFile not found";
	else {
		while(intf.read(reinterpret_cast<char *>(&bk),sizeof(book))) {
			if(bk.retbno()==x) {
				cnt++;
				cout<<"\n\t\tFILE FOUND!!!!";
				bk.showb();
				break;
			}
		}
		if(cnt==0)
		cout<<"\n\t\tNo such record exists";
	}
	intf.close();
}

// Function to modify the book records
void modify_book(int x) {
	book bk;
	int cnt=0;
	fstream intf("book1.bin",ios::in|ios::out|ios::ate|ios::binary);
	intf.seekg(0,ios::beg);
	if(!intf)
	cout<<"\n\t\tFile not found";
	else {
		while(intf.read(reinterpret_cast<char *>(&bk),sizeof(book))) {
			if(bk.retbno()==x) {
				cnt++;
				bk.createb();
				bk.showb();
				intf.seekp(intf.tellp()-sizeof(book));
				intf.write(reinterpret_cast<char *>(&bk),sizeof(book));
				cout<<"\n\t\tRecord Updated";
				break;
			}
		}
		if(cnt==0)
		cout<<"\n\t\tNo such record exists";
	}
	intf.close();
}

// Function to modify the student records
void modify_student(int x) {
	student st;
	int cnt=0;
	fstream intf("student.bin",ios::in|ios::out|ios::ate|ios::binary);
	intf.seekg(0,ios::beg);
	if(!intf)
	cout<<"\n\t\tFile not found";
	else {
		while(intf.read(reinterpret_cast<char *>(&st),sizeof(student))) {
			if(st.admno==x) {
				cnt++;
				st.creates();
				st.shows();
				intf.seekp(intf.tellp()-sizeof(student));
				intf.write(reinterpret_cast<char *>(&st),sizeof(student));
				cout<<"\n\t\tRecord Updated";
				break;
			}
		}
		if(cnt==0)
		cout<<"\n\t\tNo such record exists";
	}
	intf.close();
}

// Function to delete a specific student record
void delete_student(int x) {
	student st;
	int cnt=0;
	ifstream intf("student.bin",ios::in|ios::binary);
	intf.seekg(0,ios::beg);
	if(!intf)
	cout<<"\n\t\tFile not found";
	else {
		ofstream outf("temp.bin",ios::app|ios::binary);
		while(intf.read(reinterpret_cast<char *>(&st),sizeof(student))) {
			if(st.admno==x)
			cnt++;
			else
			outf.write(reinterpret_cast<char *>(&st),sizeof(student));
		}
		intf.close();
		outf.close();
		if(cnt==0) {
			remove("temp.bin");
			cout<<"\n\t\tNo such record exists";
		}
		else {
			remove("student.bin");
			rename("temp.bin","student.bin");
			cout<<"\n\t\tRecord deleted successfully";
		}
	}
}

// Function to delete a specific book record
void delete_book(int x) {
	book bk;
	int cnt=0;
	ifstream intf("book1.bin",ios::in|ios::binary);
	intf.seekg(0,ios::beg);
	if(!intf)
	cout<<"\n\t\tFile not found";
	else {
		ofstream outf("temp1.bin",ios::app|ios::binary);
		while(intf.read(reinterpret_cast<char *>(&bk),sizeof(book))) {
			if(bk.retbno()==x)
			cnt++;
			else
			outf.write(reinterpret_cast<char *>(&bk),sizeof(book));
		}
		intf.close();
		outf.close();
		if(cnt==0) {
			remove("temp1.bin");
			cout<<"\n\t\tNo such record exists";
		}
		else {
			remove("book.bin");
			rename("temp1.bin","book.bin");
			cout<<"\n\t\tRecord deleted successfully";
		}
	}
}

// Function to search whether a specific student record exists or not
bool res_student(int x) {
	student st;
	int cnt=0,f=0;
	ifstream intf("student.bin",ios::in|ios::binary);
	intf.seekg(0,ios::beg);
	if(!intf)
	f=1;
	else {
		while(intf.read(reinterpret_cast<char *>(&st),sizeof(student))) {
			if(st.admno==x) {
				cnt++;
				break;
			}
		}
		if(cnt==0)
		f=1;
	}
	intf.close();
	if(f)
	return 0;
	else
	return 1;
}

// Function to search a specific book and return true or false
int res_book(int x,int z) {
	book bk;
	int cnt=0,f=1;
	fstream intf("book1.bin",ios::in|ios::out|ios::ate|ios::binary);
	intf.seekg(0,ios::beg);
	if(!intf)
	f=0;
	else {
		while(intf.read(reinterpret_cast<char *>(&bk),sizeof(book))) {
			if(bk.retbno()==x) {
				cnt++;
				if(z==1) {
					bk.showb();
					if(bk.quantity()>0) {
						bk.set_q();
						intf.seekp(intf.tellp()-sizeof(book));
						intf.write(reinterpret_cast<char *>(&bk),sizeof(book));
					}
					else
					f=2;
				}
				else if(z==2) {
					bk.showb();
					bk.reset_q();
					intf.seekp(intf.tellp()-sizeof(book));
					intf.write(reinterpret_cast<char *>(&bk),sizeof(book));
				}
				break;
			}
		}
		if(cnt==0)
		f=0;
	}
	intf.close();
	return f;
}

// Function to write object of class book in file
void book_issue() {
	int sn,bn;
	system("CLS"); // Clear the screen
	cout << "\t\t......................................................." << endl;
	cout << "\t\t: ____   ___   ___  _  __  ___ ____ ____  _   _ _____ :" << endl;
	cout << "\t\t:| __ ) / _ \\ / _ \\| |/ / |_ _/ ___/ ___|| | | | ____|:" << endl;
	cout << "\t\t:|  _ \\| | | | | | | ' /   | |\\___ \\___ \\| | | |  _|  :" << endl;
	cout << "\t\t:| |_) | |_| | |_| | . \\   | | ___) |__) | |_| | |___ :" << endl;
	cout << "\t\t:|____/ \\___/ \\___/|_|\\_\\ |___|____/____/ \\___/|_____|:" << endl;
	cout << "\t\t......................................................." << endl;
	cout << "\t\t          __...--~~~~~-._   _.-~~~~~--...__" << endl;
	cout << "\t\t        //               `V'               \\\\ " << endl;
	cout << "\t\t       //                 |                 \\\\ " << endl;
	cout << "\t\t      //__...--~~~~~~-._  |  _.-~~~~~~--...__\\\\ " << endl;
	cout << "\t\t     //__.....----~~~~._\\ | /_.~~~~----.....__\\\\" << endl;
	cout << "\t\t    ====================\\\\|//====================" << endl;
	cout<<"\n\n\t\tEnter the student's admission no: ";
	cin>>sn;
	int cnt=0;
	student st;
	fstream outf("student.bin",ios::in|ios::out|ios::ate|ios::binary);
	outf.seekg(0,ios::beg);
	if(!outf)		// If file does not exist or cannot be opened
	cout<<"\n\t\tFile not found\n";
	else {
		while(outf.read(reinterpret_cast<char *>(&st),sizeof(student))) {
			if(st.admno==sn) {
				cnt++;
				list_book();
				cout<<"\n\n\t\tEnter the book no.:";
				cin>>bn;
				cout<<"\n";
				int flag=res_book(bn,1);
				if(flag==1) {
					st.settoken(bn);
					outf.seekp(outf.tellp()-sizeof(student));
					outf.write(reinterpret_cast<char *>(&st),sizeof(student));
					cout<<"\n\t\tBook Issued";
					cout<<"\n\t\tNote: Write the current date in backside of the book";
					cout<<"\n\t\t      Should be submitted within 15 days to avoid fine";
					cout<<"\n\t\t      The fine is Rs. 1 for each day after 15 days period\n";
					break;
				}
				else if(flag==2) {
					cout<<"\n\t\tTHE BOOK IS OUT OF STOCK!!!";
					break;
				}
				else{
					cout<<"\n\t\tNo such record exists\n";
					break;
				}
			}
		}
		if(cnt==0)
		cout<<"\n\t\tNo such record exists\n";
	}
	outf.close();
}

// Function to return books
void book_return() {
	int sn,bn;
	system("CLS"); // Clear the screen
	cout << "\t\t................................................................" << endl;
	cout << "\t\t: ____   ___   ___  _  __  ____  _____ _____ _   _ ____  _   _ :" << endl;
	cout << "\t\t:| __ ) / _ \\ / _ \\| |/ / |  _ \\| ____|_   _| | | |  _ \\| \\ | |:" << endl;
	cout << "\t\t:|  _ \\| | | | | | | ' /  | |_) |  _|   | | | | | | |_) |  \\| |:" << endl;
	cout << "\t\t:| |_) | |_| | |_| | . \\  |  _ <| |___  | | | |_| |  _ <| |\\  |:" << endl;
	cout << "\t\t:|____/ \\___/ \\___/|_|\\_\\ |_| \\_\\_____| |_|  \\___/|_| \\_\\_| \\_|:" << endl;
	cout << "\t\t................................................................" << endl;
	cout << "\t\t\t    _______" << "\t\t\t    _______" << endl;
	cout << "\t\t\t   /      /," << "\t\t\t   /      /," << endl;
	cout << "\t\t\t  /      //       ------->" << "\t  /      //" << endl;
	cout << "\t\t\t /______//" << "\t\t\t /______//" << endl;
	cout << "\t\t\t(______(/" << "\t\t\t(______(/" << endl;
	cout<<"\n\n\t\tEnter the student's admission no: ";
	cin>>sn;
	int cnt=0;
	student st;
	fstream outf("student.bin",ios::in|ios::out|ios::ate|ios::binary);
	outf.seekg(0,ios::beg);
	if(!outf) // If file does not exist or cannot be opened
	cout<<"\n\t\tFile not found\n";
	else
	{
		while(outf.read(reinterpret_cast<char *>(&st),sizeof(student)))
		{
			if(st.admno==sn)
			{
				cnt++;
				bn=st.retbno();
				bool flag=res_book(bn,2);
				if(flag)
				{
					st.resettoken();
					outf.seekp(outf.tellp()-sizeof(student));
					outf.write(reinterpret_cast<char *>(&st),sizeof(student));
					int days;
					cout<<"\n\t\tBook returned in no. of days:";
					cin>>days;
					if(days>15)
					{
						int fine=(days-15)*1;
						cout<<"\n\n\t\tFine: "<<fine<<nl;
					}
					cout<<"\n\t\tBook Returned Successfully\n";
					break;
				}
				else
				{
					cout<<"\n\t\tNo such record exists\n";
					break;
				}
			}
		}
		if(cnt==0)
		cout<<"\n\t\tNo such record exists\n";
	}
	outf.close();
}

// Function that provides the features of the Admin Menu
void admin_menu() {
fine:
	system("PAUSE"); // Pause execution to wait for user input
	system("CLS"); // Clear the screen
	int opt;
	cout << "\t\t\t.........................................................................................................." << endl;
	cout << "\t\t\t:    _    ____  __  __ ___ _   _ ___ ____ _____ ____      _  _____ ___  ____    __  __ _____ _   _ _   _ :" << endl;
	cout << "\t\t\t:   / \\  |  _ \\|  \\/  |_ _| \\ | |_ _/ ___|_   _|  _ \\    / \\|_   _/ _ \\|  _ \\  |  \\/  | ____| \\ | | | | |:" << endl;
	cout << "\t\t\t:  / _ \\ | | | | |\\/| || ||  \\| || |\\___ \\ | | | |_) |  / _ \\ | || | | | |_) | | |\\/| |  _| |  \\| | | | |:" << endl;
	cout << "\t\t\t: / ___ \\| |_| | |  | || || |\\  || | ___) || | |  _ <  / ___ \\| || |_| |  _ <  | |  | | |___| |\\  | |_| |:" << endl;
	cout << "\t\t\t:/_/   \\_\\____/|_|  |_|___|_| \\_|___|____/ |_| |_| \\_\\/_/   \\_\\_| \\___/|_| \\_\\ |_|  |_|_____|_| \\_|\\___/ :" << endl;
	cout << "\t\t\t.........................................................................................................." << endl;
	cout << "\t\t\t\t\t                       .,,uod8B8bou,,." << endl;
	cout << "\t\t\t\t\t              ..,uod8BBBBBBBBBBBBBBBBRPFT?l!i:." << endl;
	cout << "\t\t\t\t\t         ,=m8BBBBBBBBBBBBBBBRPFT?!||||||||||||||" << endl;
	cout << "\t\t\t\t\t         !...:!TVBBBRPFT||||||||||!!^^""'   ||||" << endl;
	cout << "\t\t\t\t\t         !.......:!?|||||!!^^""'            ||||" << endl;
	cout << "\t\t\t\t\t         !.........||||                     ||||" << endl;
	cout << "\t\t\t\t\t         !.........||||  ##                 ||||" << endl;
	cout << "\t\t\t\t\t         !.........||||                     ||||" << endl;
	cout << "\t\t\t\t\t         !.........||||                     ||||" << endl;
	cout << "\t\t\t\t\t         !.........||||                     ||||" << endl;
	cout << "\t\t\t\t\t         !.........||||                     ||||" << endl;
	cout << "\t\t\t\t\t         `.........||||                    ,||||" << endl;
	cout << "\t\t\t\t\t          .;.......||||               _.-!!|||||" << endl;
	cout << "\t\t\t\t\t   .,uodWBBBBb.....||||       _.-!!|||||||||!:'" << endl;
	cout << "\t\t\t\t\t!YBBBBBBBBBBBBBBb..!|||:..-!!|||||||!iof68BBBBBb...." << endl;
	cout << "\t\t\t\t\t!..YBBBBBBBBBBBBBBb!!||||||||!iof68BBBBBBRPFT?!::   `." << endl;
	cout << "\t\t\t\t\t!....YBBBBBBBBBBBBBBbaaitf68BBBBBBRPFT?!:::::::::     `." << endl;
	cout << "\t\t\t\t\t!......YBBBBBBBBBBBBBBBBBBBRPFT?!::::::;:!^\"`;:::       `." << endl;
	cout << "\t\t\t\t\t!........YBBBBBBBBBBRPFT?!::::::::::^''...::::::;         iBBbo." << endl;
	cout << "\t\t\t\t\t`..........YBRPFT?!::::::::::::::::::::::::;iof68bo.      WBBBBbo." << endl;
	cout << "\t\t\t\t\t  `..........:::::::::::::::::::::::;iof688888888888b.     `YBBBP^'" << endl;
	cout << "\t\t\t\t\t    `........::::::::::::::::;iof688888888888888888888b.     `" << endl;
	cout << "\t\t\t\t\t      `......:::::::::;iof688888888888888888888888888888b." << endl;
	cout << "\t\t\t\t\t        `....:::;iof688888888888888888888888888888888899fT!" << endl;
	cout << "\t\t\t\t\t          `..::!8888888888888888888888888888888899fT|!^\"'" << endl;
	cout << "\t\t\t\t\t            `' !!988888888888888888888888899fT|!^\"'" << endl;
	cout << "\t\t\t\t\t                `!!8888888888888888899fT|!^\"'" << endl;
	cout << "\t\t\t\t\t                  `!988888888899fT|!^\"'" << endl;
	cout << "\t\t\t\t\t                    `!9899fT|!^\"'" << endl;
	cout << "\t\t\t\t\t                      `!^\"'" << endl;
    cout<<"\n\n\t1.\tCREATE STUDENT RECORD";
    cout<<"\n\n\t2.\tDISPLAY ALL STUDENTS RECORD";
    cout<<"\n\n\t3.\tDISPLAY SPECIFIC STUDENT RECORD ";
    cout<<"\n\n\t4.\tMODIFY STUDENT RECORD";
    cout<<"\n\n\t5.\tDELETE STUDENT RECORD";
    cout<<"\n\n\t6.\tCREATE BOOK ";
    cout<<"\n\n\t7.\tDISPLAY ALL BOOKS ";
    cout<<"\n\n\t8.\tDISPLAY SPECIFIC BOOK ";
    cout<<"\n\n\t9.\tMODIFY BOOK ";
    cout<<"\n\n\t10.\tDELETE BOOK ";
    cout<<"\n\n\t11.\tREWARDS";
	cout<<"\n\n\t12.\tBACK TO MAIN MENU";
    cout<<"\n\n\tPlease Enter Your Choice (1-12) ";
    cin>>opt;
    if(opt==1) {	// Clear the screen and call the function to create a student record
    	system("CLS");
    	write_student();
    	cout<<nl;
    	goto fine;
	}
	else if(opt==2) {	// Clear the screen and display all student records
		system("CLS");
    	list_student();
    	cout<<nl;
    	goto fine;
	}
	else if(opt==3) {	// Clear the screen and prompt user to enter the admission number, then search for the student record
		system("CLS");
		int ad;
		cout<<"\n\n\n\t\tEnter the admission no. of the student";
		cin>>ad;
		search_student(ad);
		cout<<nl;
		goto fine;
	}
	else if(opt==4) {	// Clear the screen and prompt user to enter the admission number, then modify the student record
		system("CLS");
		int ad;
		cout<<"\n\n\n\t\tEnter the admission no. of the student";
		cin>>ad;
		modify_student(ad);
		cout<<nl;
		goto fine;
	}
	else if(opt==5) {	// Clear the screen and prompt user to enter the admission number, then delete the student record
		system("CLS");
		int ad;
		cout<<"\n\n\n\t\tEnter the admission no. of the student";
		cin>>ad;
		delete_student(ad);
		cout<<nl;
		goto fine;
	}
	else if(opt==6) {	// Clear the screen and call the function to create a book record
    	system("CLS");
    	write_book();
    	cout<<nl;
    	goto fine;
	}
	else if(opt==7) {	// Clear the screen and display all book records
		system("CLS");
    	list_book();
    	cout<<nl;
    	goto fine;
	}
	else if(opt==8) {	// Clear the screen and prompt user to enter the book number, then search for the book record
		system("CLS");
		int ad;
		cout<<"\n\n\n\t\tEnter the no. of the book";
		cin>>ad;
		search_book(ad);
		cout<<nl;
		goto fine;
	}
	else if(opt==9) {	// Clear the screen and prompt user to enter the book number, then modify the book record
		system("CLS");
		int ad;
		cout<<"\n\n\n\t\tEnter the no. of the book";
		cin>>ad;
		modify_book(ad);
		cout<<nl;
		goto fine;
	}
	else if(opt==10) {	// Clear the screen and prompt user to enter the book number, then delete the book record
		system("CLS");
		int ad;
		cout<<"\n\n\n\t\tEnter the no. of the book";
		cin>>ad;
		delete_book(ad);
		cout<<nl;
		goto fine;
	}
	else if (opt == 11) {
    // Clear the screen and prompt user to enter the reward number, then delete the reward record
    system("CLS");
    int ad;
    cout << "\n\n\n\t\tEnter the no. of the reward: ";
    cin >> ad;
    cout << "\n";
    goto fine;
	}
	else if(opt==12)	
	return ;
	else {				// If an invalid option is entered, inform the user and loop back to the menu
		cout<<"\n\t\tEnter correct option";
		cout<<nl;
		goto fine;
	}
}

/* 
   Checks for correct password
   The password is predefined and has to be changed through the source code of the application
   Returns:
       bool: true if the entered password matches the predefined password, false otherwise
*/
bool passwords() {
	int i=0;
	char ch,st[21],ch1[21]={"1"};	// Predefined password
	cout<<"\n\n\t\tEnter Password : ";
	while(1) {
    	ch=getch();
    	if(ch==13) {
        	st[i]='\0';
        	break;
    	}
    	else if(ch==8&&i>0) {
        	i--;
        	cout<<"\b \b";
    	}
    	else {
    		cout<<"*";
    		st[i]=ch;
    		i++;
    	}
    }
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);	// Checking if the entered password matches the predefined password
    if(st[i]=='\0'&&ch1[i]=='\0')
    return 1; // Passwords match
    else
    return 0; // Passwords don't match
}

// Main function
int main() {
cout << "\t\t\t*********************************************************************************" << endl;
cout << "\t\t\t*  ___  _   _ _     ___ _   _ _____   _     ___ ____  ____      _    ______   __*" << endl;
cout << "\t\t\t* / _ \\| \\ | | |   |_ _| \\ | | ____| | |   |_ _| __ )|  _ \\    / \\  |  _ \\ \\ / /*" << endl;
cout << "\t\t\t*| | | |  \\| | |    | ||  \\| |  _|   | |    | ||  _ \\| |_) |  / _ \\ | |_) \\ V / *" << endl;
cout << "\t\t\t*| |_| | |\\  | |___ | || |\\  | |___  | |___ | || |_) |  _ <  / ___ \\|  _ < | |  *" << endl;
cout << "\t\t\t* \\___/|_| \\_|_____|___|_|_\\_|_____|_|_____|___|____/|_| \\_\\/_/___\\_\\ | \\_\\|_|  *" << endl;
cout << "\t\t\t*|  \\/  |  / \\  | \\ | |  / \\  / ___| ____|  \\/  | ____| \\ | |_   _|             *" << endl;
cout << "\t\t\t*| |\\/| | / _ \\ |  \\| | / _ \\| |  _|  _| | |\\/| |  _| |  \\| | | |               *" << endl;
cout << "\t\t\t*| |  | |/ ___ \\| |\\  |/ ___ \\ |_| | |___| |  | | |___| |\\  | | |               *" << endl;
cout << "\t\t\t*|_|__|_/_/___\\_\\_|_\\_/_/___\\_\\____|_____|_|  |_|_____|_| \\_| |_|               *" << endl;
cout << "\t\t\t*/ ___\\ \\ / / ___|_   _| ____|  \\/  |                                           *" << endl;
cout << "\t\t\t*\\___  \\ V /\\___ \\ | | |  _| | |\\/| |                                           *" << endl;
cout << "\t\t\t* ___) || |  ___) || | | |___| |  | |                                           *" << endl;
cout << "\t\t\t*|____/ |_| |____/ |_| |_____|_|  |_|                                           *" << endl;
cout << "\t\t\t*                                                                               *" << endl;
cout << "\t\t\t*********************************************************************************" << endl;
	bool a=passwords();
	if(!a) {
		for(int i=0;i<2;i++) {
			cout<<"\nWrong password";
			cout<<"\nYou have "<<2-i<<"attempts left";
			if(passwords())
			goto last;
			if(i==1) {
				cout<<"\n\n\n\t\t\t All attempts failed........";
				cout<<"\n\n\t\t\t Sorry, but you can't login";
				exit(0);
			}
		}
	}
	last:	 // Jump label to indicate the end of password verification loop
		cout<<"\n\n";
	start:	// Start of the main program loop
		system("PAUSE");
		system("CLS");
		int opt;
		cout<<"\n\n\t\t\t  ------------------------------------------";
		cout<<"\n\t\t\t\t  LIBRARY MANAGEMENT SYSTEM";
		cout<<"\n\t\t\t  ------------------------------------------" << endl;
		cout << "\t\t             .--.           .---.        .-." << endl;
		cout << "\t\t         .---|--|   .-.     | A |  .---. |~|    .--." << endl;
		cout << "\t\t      .--|===|Ch|---|_|--.__| S |--|:::| |~|-==-|==|---." << endl;
		cout << "\t\t      |%%|NT2|oc|===| |~~|%%| C |--|   |_|~|CATS|  |___|-." << endl;
		cout << "\t\t      |  |   |ah|===| |==|  | I |  |:::|=| |    |GB|---|=|" << endl;
		cout << "\t\t      |  |   |ol|   |_|__|  | I |__|   | | |    |  |___| |" << endl;
		cout << "\t\t      |~~|===|--|===|~|~~|%%|~~~|--|:::|=|~|----|==|---|=|" << endl;
		cout << "\t\t      ^--^---'--^---^-^--^--^---'--^---^-^-^-==-^--^---^-'" << endl;
		cout<<"\n\n\t\t\tWhat do you want to do?";
		cout<<"\n\t\t\t1.\tISSUE BOOK";
		cout<<"\n\t\t\t2.\tRETURN BOOK";
		cout<<"\n\t\t\t3.\tADMINISTRATOR MENU";
		cout<<"\n\t\t\t4.\tEnd Program";
		cout<<"\n\n Choose your option: ";
		cin>>opt;
		if(opt==1) {
			system("CLS");
			book_issue();
			goto start;
		}
		else if(opt==2) {
			system("CLS");
			book_return();
			goto start;	
		}
		else if(opt==3) {
			admin_menu();
			goto start;
		}
		else if(opt==4)
		exit(0);
		else {
			cout<<"\n\t\tEnter an option";
			goto start;
		}
		// Example usage of the Reward class
    vector<Reward> Reward;

    // Adding some rewards
    Reward.emplace_back(1, "Free Coffee", 5.0);
    Reward.emplace_back(2, "Discount on Movie Tickets", 10.0);
    Reward.emplace_back(3, "Gift Voucher", 20.0);

    // Deleting a reward
    deleteReward(2, Reward);

    // Displaying remaining rewards
    cout << "Remaining Rewards:" << endl;
    for (const auto& reward : Reward) {
        reward.displayReward();
        cout << endl;
    }
}
