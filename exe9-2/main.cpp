#include <iostream>
#include "Package.h"

using namespace std;

int main()
{
  Package package1("Lou Brown", "Boston", "Mary Smith", "New York", 8.5, 0.5);
  TwoDayPackage package2("Lisa Klein", "Somerville", "Bob George", "Cambridge", 10.5, 0.65, 2.0);
  OvernightPackage package3("E Lewis", "Boston", "Don Kelly", "Denver", 12.25, 0.7, 0.25 );

  cout << "Package 1:" << endl << "Sender:" << endl;
  cout << package1.getSenderName() << " / " << package1.getSenderCity() << endl;
  cout << "Recipient:" << endl;
  cout << package1.getRecipientName() << " / " << package1.getRecipientCity() << endl;
  cout << "Cost: $" << package1.calculateCost() << endl << endl;

  cout << "Package 2:" << endl << "Sender:" << endl;
  cout << package2.getSenderName() << " / " << package2.getSenderCity() << endl;
  cout << "Recipient:" << endl;
  cout << package2.getRecipientName() << " / " << package2.getRecipientCity() << endl;
  cout << "Cost: $" << package2.calculateCost() << endl << endl;

  cout << "Package 3:" << endl << "Sender:" << endl;
  cout << package3.getSenderName() << " / " << package3.getSenderCity() << endl;
  cout << "Recipient:" << endl;
  cout << package3.getRecipientName() << " / " << package3.getRecipientCity() << endl;
  cout << "Cost: $" << package3.calculateCost() << endl;

  return 0;
}
