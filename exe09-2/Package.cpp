#include <iostream>
#include <string>
#include "Package.h"

using namespace std;

Package::Package(string senderName, string senderCity, string recipientName, string recipientCity, double weight, double costPerWeight)
{
  this->senderName = senderName;
  this->senderCity = senderCity;
  this->recipientName = recipientName;
  this->recipientCity = recipientCity;
  this->weight = weight;
  this->costPerWeight = costPerWeight;
}

double Package::calculateCost()
{
  return weight * costPerWeight;
}

string Package::getSenderName()
{
  return senderName;
}

string Package::getSenderCity()
{
  return senderCity;
}

string Package::getRecipientName()
{
  return recipientName;
}

string Package::getRecipientCity()
{
  return recipientCity;
}

double Package::getWeight()
{
  return weight;
}

TwoDayPackage::TwoDayPackage(string senderName, string senderCity, string recipientName, string recipientCity, double weight, double costPerWeight, double flatFee) : Package(senderName, senderCity, recipientName, recipientCity, weight, costPerWeight)
{
  this->flatFee = flatFee;
}

double TwoDayPackage::calculateCost()
{
  return Package::calculateCost() + flatFee;
}

OvernightPackage::OvernightPackage(string senderName, string senderCity, string recipientName, string recipientCity, double weight, double costPerWeight, double overnightFreePerWeight) : Package(senderName, senderCity, recipientName, recipientCity, weight, costPerWeight)
{
  this->overnightFreePerWeight = overnightFreePerWeight;
}

double OvernightPackage::calculateCost()
{
  return Package::calculateCost() + getWeight() * overnightFreePerWeight;
}

