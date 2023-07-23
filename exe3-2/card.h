#ifndef CARD_H
#define CARD_H

namespace card
{
  class Card
  {
  private:
    char data;
    bool status; // true->open, false->close
  public:
    Card(char data);
    ~Card();
    char getData();
    bool getStatus();
    void changeStatus();
  };
};

#endif
