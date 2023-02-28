struct ListNode
{
 int value;
 struct ListNode* next;
};
// Specification file for the IntList class
class IntList
{
private:
 ListNode* head; // List head pointer
 // Destroy function
 void destroy();
public:
 // Constructor
 IntList()
 {
 head = nullptr;
 }
 // Destructor
 ~IntList();
 // List operations
 void insertNode(int);
 void deleteNode(int);
 void print();
 void reverse();
 void removeByPos(int);
 //void destroy();
};