#pragma once
#include <string>
namespace Records {	//���ӽ����̽� Records 
	const int kDefaultStartingSalary = 30000;	//���� �޿�
	class Employee {	
	public:
		Employee() = default;
		Employee(const std::string& firstName,
			const std::string& LastName);

		void promote(int raiseAmount = 1000);
		void demote(int deritAmount = 1000);
		void hire();	//������ ä���ϰų� ���ӿ��Ѵ�.
		void fire();	//������ �ذ��Ѵ�.
		void display() const;	//���������� ����Ѵ�.

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
