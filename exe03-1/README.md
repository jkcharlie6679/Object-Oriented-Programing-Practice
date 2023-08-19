# LINKED LIST

The following is the sample output of the program.

```text
Please select an option:
1.Insert a node
2.Delete a node
3.Display the list
4.End
1
Please enter the number:
1
Please select an option:
1.Insert a node
2.Delete a node
3.Display the list
4.End
1
Please enter the number:
2
Please select an option:
1.Insert a node
2.Delete a node
3.Display the list
4.End
1
Please enter the number:
3
Please select an option:
1.Insert a node
2.Delete a node
3.Display the list
4.End
3
1->2->3->
Please select an option:
1.Insert a node
2.Delete a node
3.Display the list
4.End
2
Please enter the number:
2
Please select an option:
1.Insert a node
2.Delete a node
3.Display the list
4.End
3
1->3->
Please select an option:
1.Insert a node
2.Delete a node
3.Display the list
4.End
4
```

Please finish the given code to achieve the sample output.

```cpp
#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node *next;
};
//global variable root is used to record the head of link list

Node* root = NULL;

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
```

## Reference

[NYCU OCW Object-Oriented Programming Lab 03](https://ocw.nycu.edu.tw/course/oop002/LAB_03.pdf)

