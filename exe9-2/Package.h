#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

using namespace std;

class Package
{
private:
  string senderName;
  string senderCity;
  string recipientName;
  string recipientCity;
  double weight; // weight of the package
  double costPerWeight; // cost per weight to ship the package
public:
  Package(string, string, string, string, double, double);
  double calculateCost();
  string getSenderName();
  string getSenderCity();
  string getRecipientName();
  string getRecipientCity();
  double getWeight();
};

class TwoDayPackage : public Package
{
private:
  double flatFee; // flat fee for two-day-delivery service
public:
  TwoDayPackage(string, string, string, string, double, double, double);
  double calculateCost();
};

class OvernightPackage : public Package
{
private:
  double overnightFreePerWeight; // flat fee weight for overnight delivery
public:
  OvernightPackage(string, string, string, string, double, double, double);
  double calculateCost();
};

#endif

