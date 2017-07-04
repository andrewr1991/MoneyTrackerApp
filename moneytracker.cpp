#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <iostream>
#include <sstream>

using namespace boost::archive;
using namespace std;

stringstream ss;

class User {
	public:
		void addFunds(float funds) {
			totalFunds += funds;
		}
		
		void addEstimate();
		
		float funds_toString() {
			return totalFunds;
		}
		
	private:
		friend class boost::serialization::access;
	
		template <typename Archive>
		void serialize(Archive &ar, const unsigned int version) {
			ar& totalFunds;
			ar& totalSpent;
		}
		
		float totalFunds = 0;
		float totalSpent;
		
};

class Sub {
	private:
		string companyName;
		string supervisorName;
		string typeOfWork;
		string descriptionOfWorkCompleted;
		float cost;
	
	public:
		string sub_toString();
};	

void saveData(User user) {
	text_oarchive oa{ss};
	oa << user;
}

User loadData() {
	text_iarchive ia{ss};
	User user;
	ia >> user;
	return user;
}

int main() {
	int choice;
	
	cout << "Do you want to enter information";
	cin >> choice;
	
	if (choice == 1) {
		User user;
		user.addFunds(102.3);
		cout << user.funds_toString() << endl;
		saveData(user);
		user.addFunds(200.1);
		cout << user.funds_toString() << endl;
		user = loadData();
		cout << user.funds_toString() << endl;
	}
	
	return 0;
}
