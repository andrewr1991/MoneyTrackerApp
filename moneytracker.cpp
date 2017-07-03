#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <iostream>
#include <sstream>

using namespace boost::archive;
using namespace std;

class User {
	public:
		void addFunds();
		void addEstimate();
		
	private:
		friend class boost:serialization::access;
	
		template <typename Archive>
		void serialize(Archive &ar, const unsigned int version) {
		float totalFunds;
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

int main() {

	
	return 0;
}
