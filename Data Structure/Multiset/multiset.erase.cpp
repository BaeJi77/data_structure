//
//  main.cpp
//  Data Structure
//
//  Created by Hoon on 2018. 7. 26..
//  Copyright © 2018년 Hoon. All rights reserved.
//  출처 : http://www.cplusplus.com/reference/set/multiset/erase/

#include <iostream>
#include <set>

int main ()
{
   std::multiset<int> mymultiset;
   std::multiset<int>::iterator it;
   
   // insert some values:
   mymultiset.insert (40);                            // 40
   for (int i=1; i<7; i++) mymultiset.insert(i*10);   // 10 20 30 40 40 50 60
   
   it=mymultiset.begin();
   it++;                                              //    ^
   printf("%d\n" , *it);
   mymultiset.erase (it);                             // 10 30 40 40 50 60
   it++;
   printf("%d\n" , *it);
   mymultiset.erase (it);                             // 10 30 50 60
   
   it=mymultiset.find (50);
   mymultiset.erase ( it, mymultiset.end() );         // 10 30
   
   std::cout << "mymultiset contains:";
   for (it=mymultiset.begin(); it!=mymultiset.end(); ++it)
       std::cout << ' ' << *it;
   std::cout << '\n';
   
   return 0;
}

