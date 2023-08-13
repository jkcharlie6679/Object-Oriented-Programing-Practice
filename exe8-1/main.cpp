#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;

class Item
{
private:
  string name;
  int armorL;
  int armorH;
  int damageL;
  int damageH;
public:
  Item(string name)
  {
    this->name = name;
    this->armorL = 0;
    this->armorH = 0;
    this->damageL = 0;
    this->damageH = 0;
  };
  void setArmor(int armorL, int armorH)
  {
    this->armorL = armorL;
    this->armorH = armorH;
  };
  void setDamage(int damageL, int damageH)
  {
    this->damageL = damageL;
    this->damageH = damageH;
  };
  int getArmorL()
  {
    return this->armorL;
  };
  int getArmorH()
  {
    return this->armorH;
  };
  int getDamageL()
  {
    return this->damageL;
  };
  int getDamageH()
  {
    return this->damageH;
  };
};

int main ()
{
  ifstream file;
  unordered_map<string, Item*> items;
  file.open("../ex8-1-2.txt");
  if (file.is_open())
  {
    string line;
    string item;
    while (file >> line)
    {
      istringstream ss(line);
      getline(ss, line, ':');
      if (line == "Item")
      {
        file >> item;
        items[item] = new Item(item);
      }
      else if (line == "Armor")
      {
        string al, ah;
        getline(ss, al, '-');
        ah = al;
        getline(ss, ah);
        items[item]->setArmor(stoi(al), stoi(ah));
      }
      else if (line == "Damage")
      {
        string dl, dh;
        getline(ss, dl, '-');
        dh = dl;
        getline(ss, dh);
        items[item]->setDamage(stoi(dl), stoi(dh));
      }
      else
        continue;
    }
  }
  else
    cout << "File not found." << endl;
  file.close();

  file.open("../ex8-1-1.txt");
  if (file.is_open())
  {
    string line;
    while (getline(file, line))
    {
      istringstream ss(line);
      string name;
      ss >> name;
      int armorL = 0;
      int armorH = 0;
      int damageL = 0;
      int damageH = 0;
      while (ss)
      {
        string item;
        ss >> item;
        if (items.find(item) != items.end())
        {
          armorL += items[item]->getArmorL();
          armorH += items[item]->getArmorH();
          damageL += items[item]->getDamageL();
          damageH += items[item]->getDamageH();
        }
      }
      cout << name << "\tDmage:" << damageL << "-" << damageH << "\tArmor:" << armorL << "-" << armorH << endl;
    }
  }
  else
    cout << "File not found." << endl;
  file.close();

  return 0;
}

