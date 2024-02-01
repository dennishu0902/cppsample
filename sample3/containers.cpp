#include <iostream>
#include <array>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <set>

//array size is fixed at definition 
void my_array()
{
  std::array<int,5> myarray = { 2, 16, 77, 34, 50 };

  std::cout << "myarray contains:";
  for ( auto it = myarray.begin(); it != myarray.end(); ++it )
    std::cout << ' ' << *it;
  std::cout << '\n';
}
//size is vary, push_front, pop_front, push_back, pop_back
void my_deque()
{
 std::deque<int> mydeque;

  for (int i=1; i<=5; i++) mydeque.push_back(i);

  std::cout << "mydeque contains:";
  for ( auto it = mydeque.begin(); it != mydeque.end(); ++it )
     std::cout << ' ' << *it; 
  std::cout << '\n';
  std::cout << "after mydeque.push_front(11);";
  mydeque.push_front(11);
  for ( auto it = mydeque.begin(); it != mydeque.end(); ++it )
     std::cout << ' ' << *it;
  std::cout << '\n';
  std::cout << "after mydeque.push_front(51);";
  mydeque.push_back(51);
  for ( auto it = mydeque.begin(); it != mydeque.end(); ++it )
     std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "after mydeque.pup_front();";
  mydeque.pop_front();
  for ( auto it = mydeque.begin(); it != mydeque.end(); ++it )
     std::cout << ' ' << *it;
  std::cout << '\n';

}
void my_queue()
{
   std::queue<int> myqueue;
   myqueue.push(5);
   myqueue.push(4);
   myqueue.push(3);
   std::cout << " current front value " << myqueue.front();
   std::cout << '\n';
   myqueue.pop();
   std::cout << " current front value after pop " << myqueue.front();
   std::cout << '\n';
   myqueue.pop();
   std::cout << " current front value after pop " << myqueue.front();
   std::cout << '\n';
  
}
int main ()
{
 
  my_array();
  my_deque();
  my_queue();
  return 0;
}