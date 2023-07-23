#include "card.h"

using namespace card;

Card::Card(char data)
{
  this->data = data;
  this->status = false;
}

Card::~Card()
{
  delete(this);
}

char Card::getData()
{
  return data;
}

bool Card::getStatus()
{
  return status;
}

void Card::changeStatus()
{
  status = !status;
}


