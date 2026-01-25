#include <iostream>
#include <string>
#include <format>

class AirlineTicker {
private:
  std::string m_passengerName { "Unknow Passenger" };
  int m_numberOfMiles { 0 };
  bool m_hasEliteSuperRewardsStatus { false };
  std::string m_customerNumber { "" };

public:
  double calculatePriceInDollars() const {
    if (this->hasEliteSuperRewardsStatus()) {
      return 0;
    }

    return this->getNumberOfMiles() * 0.1;
  }

  std::string getPassengerName() const {
    return this->m_passengerName;
  }
  void setPassengerName(const std:: string &name) {
    this->m_passengerName = name;
  }

  int getNumberOfMiles() const {
    return this->m_numberOfMiles;
  }
  void setNumberOfMiles(const int &miles) {
    this->m_numberOfMiles = miles;
  }

  bool hasEliteSuperRewardsStatus() const {
    return this->m_hasEliteSuperRewardsStatus;
  }
  void setHasEliteSuperRewardsStatus(const bool &status) {
    this->m_hasEliteSuperRewardsStatus = status;
  }

  std::string getCustomerNumber() const {
    return this->m_customerNumber;
  }
  void setCustomerNumber(std::string customerNumber) {
    this->m_customerNumber = customerNumber;
  }
};

int main() {
  AirlineTicker myTicket;
  myTicket.setPassengerName("Sherman T. Socketwrench");
  myTicket.setNumberOfMiles(700);
  myTicket.setCustomerNumber("BB01");
  const double cost { myTicket.calculatePriceInDollars() };
  std::cout << std::format("This ticket will cost {}, customer number is {}", cost, myTicket.getCustomerNumber()) << std::endl;

  return 0;
}