#pragma once
#include <string>
namespace Records {	//네임스페이스 Records 
	const int kDefaultStartingSalary = 30000;	//시작 급여
	class Employee {	
	public:
		Employee() = default;
		Employee(const std::string& firstName,
			const std::string& LastName);

		void promote(int raiseAmount = 1000);
		void demote(int deritAmount = 1000);
		void hire();	//직원을 채용하거나 재임용한다.
		void fire();	//직원을 해고한다.
		void display() const;	//직원정보에 출력한다.

		//getter , setter
		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;

		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;

		void setEmployeeNumber(int employeeNumber);
		int getEmployeeNumber() const;

		void setSalary(int newSalary);
		int getSalary() const;

		bool isHired() const;
	private:
		std::string mFirstName;
		std::string mLastName;
		int mEmployeeNumber = -1;
		int mSalary = kDefaultStartingSalary;
		bool mHired = false;
	};
}
