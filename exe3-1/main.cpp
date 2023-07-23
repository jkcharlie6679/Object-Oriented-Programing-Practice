#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node *next;
};

//global variable root is used to record the head of link list
Node* root = NULL;

void InsertNode (int data)
{
  Node *tmp = root;
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;
  if (tmp == NULL)
  {
    root = newNode;
    return;
  }
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = newNode;
}

int DeleteNode(int data)
{
  Node *pre = NULL;
  Node *cur = root;
  while (cur != NULL && cur->data != data)
  {
    pre = cur;
    cur = cur->next;
  }
  if (cur->data == data)
  {
    pre->next = cur->next;
    return 1;
  }
  else 
    return 0; 
}

void Display(void)
{
  Node *tmp = root;
  while(tmp)
  {
    cout << tmp->data << "->";
    tmp = tmp->next;
  }
  cout << endl;
}

int main()
{
  size_t i = 0;
  while (1)
  {
    cout << "Please select an option:" << endl
    << "1.Insert a node" << endl
    << "2.Delete a node" << endl
    << "3.Display the list" << endl
    << "4.End" << endl;
    cin >> i;
    int data;
    switch(i)
    {
      case 1:
        cout << "Please enter the number:" << endl;
        cin >> data;
        InsertNode(data);
        break;
      case 2:
        cout << "Please enter the number:" << endl;
        cin >> data;
        if ( !DeleteNode(data) )
          cout << "Failed to delete node " << data << endl;
        break;
      case 3:
        Display();
        break;
      case 4:
        return 0;
      default:
        break;
    }
  }
}
