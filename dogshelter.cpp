#include <iostream>
#include<string>
#include <regex>
#include <fstream>

using namespace std;

bool isEndDateLater(string start_date, string end_date) {
    try {
        // Validate start date format
        int start_day, start_month, start_year;
        char separator;
        stringstream(start_date) >> start_day >> separator >> start_month >> separator >> start_year;

        // Validate end date format
        int end_day, end_month, end_year;
        stringstream(end_date) >> end_day >> separator >> end_month >> separator >> end_year;

        // Compare dates
        if (end_year > start_year) {
            return true;
        } else if (end_year == start_year) {
            if (end_month > start_month) {
                return true;
            } else if (end_month == start_month) {
                if (end_day > start_day) {
                    return true;
                }
            }
        }
    } catch (...) {
        // Invalid date format, return false
    }
    return false;
}

/*
bool isValidDate(string dateStr)
{
    const regex dateRegex("\\b(0?[1-9]|[12][0-9]|3[01])/(0?[1-9]|1[012])/((19|20)\\d\\d)\\b");
    return regex_match(dateStr,dateRegex);
}
*/
bool Emailcheck(string email)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}

/*
bool Emailcheck(const std::string& email) {
    try {
        istringstream ss(email);
        string username, domain;
        char at;
        ss >> username >> at >> domain;

        if (!ss.eof() || ss.fail() || at != '@' || username.empty() || domain.empty()) {
            throw std::invalid_argument(" Invalid email format");
        }
        return true;
    } catch (const invalid_argument& e) {
        cerr << "\t\t\tError: " << e.what() << ": " << email << endl;
        return false;
    }
}
*/
bool isValidDate(const string& dateStr) {
    try {
        istringstream ss(dateStr);
        int day, month, year;
        char delim1, delim2;
        ss >> day >> delim1 >> month >> delim2 >> year;

        if (!ss.eof() || ss.fail() || delim1 != '/' || delim2 != '/' || year < 1900 || year > 2099 || month < 1 || month > 12) {
            throw invalid_argument("Invalid date format: " + dateStr);
        }

        int maxDays = 31;
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            maxDays = 30;
        } 

        if (day < 1 || day > maxDays) {
            throw invalid_argument("Invalid date: " + dateStr);
        }

        return true;
    } catch (const invalid_argument& e) {
        cerr << "\t\t\t" << e.what() << endl;
        return false;
    }
}

/*
bool isValidDate(const string& dateStr) {
    istringstream ss(dateStr);
    int day, month, year;
    char delim1, delim2;
    ss >> day >> delim1 >> month >> delim2 >> year;

    if (!ss.eof() || ss.fail() || delim1 != '/' || delim2 != '/' || year < 1900 || year > 2099 || month < 1 || month > 12) {
        throw invalid_argument("Invalid date format: " + dateStr);
    }

    int maxDays = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDays = 30;
    } 

    if (day < 1 || day > maxDays) {
        throw invalid_argument("Invalid date: " + dateStr);
    }

    return true;
}
*/

class owner
{
protected :
	string address;
public:
	string owner_name,mail_id;
	long long ph_no;
	owner()
	{
		address = "xyz";
		owner_name = " ";
		ph_no = 0;
		mail_id = " ";
	}
	owner(string a, string j, string o, long long p,string m)
	{
		address = a;
		owner_name = o;
		ph_no = p;
		mail_id = m;
	}
	void get_details()
	{
		cout<<"\t\t\tEnter your name : \t\t";
		//cin.ignore();
        cin>>owner_name;
		//getline(cin,owner_name);
		contact:
			cout<<"\t\t\tEnter mobile number : \t\t";
			cin>>ph_no;
			if (ph_no < 1000000000 || ph_no > 9999999999)
				{
					cout << "\t\t\t Please Enter Only 10 Digits..." << endl;
					goto contact;
				}
		mail :
			cout<<"\t\t\tEnter mail id : \t\t";
			cin>>mail_id;
			if (!Emailcheck(mail_id))
			{
			     cout << "\t\t\t Your mail ID is InValid" << endl;
			     goto mail;
			}
		cout<<"\t\t\tEnter your address : \t\t";
		//cin.ignore();
        //getline(cin,address);
        cin>>address;

	}
};
class pet : public owner
{
    int age;
    string vet, special_req;
public:
    string pet_name,start_date,end_date;
    pet()
    {
    	start_date = "0/0/0";
    	end_date = "0/0/0";
        age = 0;
        vet = "xyz";
        special_req = "none";
        pet_name = "zyx";
    }
    pet(int a, string v, string s,string p, string st,string e)
    {
    	start_date = st;
    	end_date = e;
    	age = a;
    	vet = v;
    	special_req = s;
    	pet_name = p;
    }
    void get_details()
    {
    	fstream file;
    	owner :: get_details();
    	s_date :
    	cout<<"\t\t\tEnter checkin date (dd/mm/yyyy) : \t\t";
    	cin>>start_date;
    	if (!isValidDate(start_date))
    	{
    		cout << "\t\t\t Your check-in date is InValid" << endl;
    		goto s_date;
    	}
    	e_date :
    	cout<<"\t\t\tEnter checkout date (dd/mm/yyyy) : \t\t";
    	cin>>end_date;
    	if (!isValidDate(end_date) && start_date>end_date)
    	{
    		cout << "\t\t\t Please enter in (dd/mm/yyyy) format" << endl;
    	    goto e_date;
       	}
    	if (!isEndDateLater(start_date,end_date))
    	{
    		cout<<"\t\t\t End date cannot be before start date "<<endl;
    		goto e_date;
    	}
        cout<<"\t\t\tEnter pet name : \t\t";
        cin>>pet_name;
        age :
        cout<<"\t\t\tEnter pet age : \t\t";
        cin>>age;
        if (age<1)
        {
        	cout<<"We only accomodate dogs over the age of 1";
        	goto age;
        }

       // cin.ignore();
        cout<<"\t\t\tEnter vet name : \t\t";
        //getline(cin,vet);
        cin>>vet;
        cout<<"\t\t\tEnter any special requests : \t\t";
        //getline(cin,special_req);
         cin>>special_req;
        file.open("petinfo.txt",ios :: app | ios :: out);
        // PUTTING DATA INTO THE FILE
        file <<"\n "<< owner_name <<" "<< ph_no <<" "<< address<<" "<< pet_name <<" "<< age <<" "<< vet <<" "<<special_req;
        file.close();
    }
};


class staff
{
    int age;
    double salary;
public:
    string staff_name[10],designation[10],ph_no[10];
    void show_staff()
    {
    	cout<<"Following are the staff which will be taking care of your furry friend!\n";
    	int n = 5;
    	staff_name[1] = "Vedant";
    	designation[1] = "Manager\t";
    	ph_no[1] = "94223xxxxx";
    	staff_name[2] = "Apoorwa";
    	designation[2] = "Booking incharge";
    	ph_no[2] = "94230xxxxx";
    	staff_name[3] ="Ishaan";
    	designation[3] = "Kennel incharge";
    	ph_no[3] = "89213xxxxx";
   		staff_name[4] = "Aditya";
   		designation[4] = "Food incharge";
   		ph_no[4] = "84826xxxxx";
   		staff_name[5] = "Arjun";
   		designation[5] = "Caretaker";
   		ph_no[5] = "74125xxxxx";
   		for(int i=1;i<n+1;i++)
   		{
            cout<<"Name : "<<staff_name[i]<<"\t\t Designation : "<<designation[i]<<"\t\t Contact :"<<ph_no[i]<<endl;
   		}
    }
};


class kennel : protected pet,public staff
{
public:
    int avail = 20,full = 0;
    int calc()
    {
    	if (avail == 0){
    		return 1;
    	}
    	else
    	{
			avail -= 1;
			full += 1;
			return 0;
    	}
    }
    void search_reservation(string owner_name)
    {
        ifstream file("petinfo.txt");
        string line;
        bool found = false;
    
        while (getline(file, line)) {
            stringstream ss(line);
            string name, phone, address, pet_name, vet, special_req;
            int age;
            ss >> name >> phone >> address >> pet_name >> age >> vet >> special_req;
    
            if (name == owner_name) {
                found = true;
                cout << "Reservation details for " << name << ":\n";
                cout << "Pet name: " << pet_name << endl;
                cout << "Pet age: " << age << endl;
                cout << "Vet name: " << vet << endl;
                cout << "Special requests: " << special_req << endl;
                break;
            }
        }
    
        file.close();
        if (!found) {
            cout << "No reservation found for " << owner_name << endl;
        }
    }

};

int main()
{
	int ch = 'y';
	string owner_name;
	char op;
	pet p;
	kennel k;
	do{
        //ADD description
        cout<<"\n\t###############################################################\n";
	    cout<<"\t\t--- Welcome to furry friends pet boarding! ---\n";
         cout<<"\t###############################################################\n";
	    cout<<"\nWe offer quality pet boarding and make sure each and every need of your pet is fullfilled :)\n";
        cout<<"Our job is to provide a hassle free experience for you and your pet the "<<endl;
        cout<<"next time you plan on a vacation or excursion and are wondering about the wellbeing of your furry friend!:)\n";
		cout<<"\t\t\t->Enter to proceed\n\n \t\t\t1.Make new reservation\n \t\t\t2.View reservation confirmation\n \t\t\t3.View on-field staff\t\t\t\n"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				k.calc();
				if (k.calc() == 0)
				{
					p.get_details();
					k.calc();
					cout<<"\nThank you for registering your pet " <<p.pet_name<< " with us!\n";
					cout<<"Please navigate to main menu to view confirmation\n";
				}
				else
					cout<<"Sorry all kennels are full!\n";
				break;
			}
			case 2:
			{
                cout << "Enter owner name to search for reservation: ";
                //cin.ignore();
                //getline(cin, owner_name);
                cin>>owner_name;
                k.search_reservation(owner_name);
				break;
			}
			case 3:
			{
				k.show_staff();
				cout<<"Please feel free to reach out to any of our team members for enquires! \n";
			}
		}
		cout<<"Press 'y' to navigate to main menu OR Press any key to exit";
		cin>>op;
	} while(op=='y');
	cout<<"\nThank you for visiting our portal!\n";
}