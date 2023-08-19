#include <iostream>
#include <vector>
#include <cstdlib>
#include "card.h"

using namespace std;
using namespace card;


int initCards(vector<Card*> &cards, int row, int col)
{
  if ((row*col) % 2 != 0)
    return -1;
  int size = row * col / 2;
  int *pool = new int[size];
  memset(pool, 0, sizeof(int) * size);
  srand(time(NULL));
  
  while (cards.size() < row * col)
  {
    int shift = rand() % size;
    while (pool[shift] > 1)
      shift = rand() % size;
    pool[shift]++;
    char data = shift + 'a';
    Card* newCard = new Card(data);
    cards.push_back(newCard);
  }
  return 0;
}

int printCard(vector<Card*> &cards, int row, int col)
{
  int notOpen = 0;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      if (cards[col * i + j]->getStatus() == false)
      {
        notOpen++;
        cout << "* ";
      }
      else
        cout << cards[col * i + j]->getData() << " "; 
    }
    cout << endl;
  }
  return notOpen;
}

int checkGame(vector<Card*> &cards, int first, int second)
{
  if (cards[first]->getData() == cards[second]->getData())
    return 1;
  return 0;
}

int main (int argc, char *argv[])
{
  vector<Card*> cards;
  int row = stoi(argv[1]), col = stoi(argv[2]);
  int notOpen = 0;
  if (initCards(cards, row, col))
  {
    cout << "The number of row and column is not acceptable!!" << endl;
    exit(-1);
  }
  cout << "Please enter the number from 0 to " << row * col - 1 << " to open the card." << endl;
  notOpen = printCard(cards, row, col);
  while (notOpen)
  {
    cout << "new round" << endl;
    int first, second;
    cout << "Please enter first card index: ";
    cin >> first;
    while (first >= row *col || cards[first]->getStatus() == true)
    { 
      cout << "Please enter first card index: ";
      cin >> first;
    }
    cards[first]->changeStatus();
    notOpen = printCard(cards, row, col);
    cout << "Please enter second card index: ";
    cin >> second;
    while (second >= row *col || cards[second]->getStatus() == true)
    { 
      cout << "Please enter second card index: ";
      cin >> second;
    }
    cards[second]->changeStatus();
    notOpen = printCard(cards, row, col);
    if (checkGame(cards, first, second) == 0)
    {
      cards[first]->changeStatus();
      cards[second]->changeStatus();
    }
  }
  cout << "Congurlation!!" << endl;
  return 0;
}

