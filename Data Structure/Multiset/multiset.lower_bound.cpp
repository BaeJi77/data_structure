//
//  multiset_equl_range.cpp
//  Data Structure
//
//  Created by Hoon on 2018. 7. 26..
//  Copyright © 2018년 Hoon. All rights reserved.
//  출처 : http://www.cplusplus.com/reference/set/multiset/lower_bound/


// multiset::lower_bound/upper_bound
#include <iostream>
#include <set>

int main ()
{
    std::multiset<int> mymultiset;
    std::multiset<int>::iterator itlow,itup;
    
    for (int i=1; i<8; i++) mymultiset.insert(i*10); // 10 20 30 40 50 60 70
    
    itlow = mymultiset.lower_bound (30);             //       ^
    itup = mymultiset.upper_bound (40);              //             ^
    printf("%d %d\n" , *itlow , *itup);              // 30 50
//    mymultiset.erase(itlow,itup);                    // 10 20 50 60 70
    
    std::cout << "mymultiset contains:";
    for (std::multiset<int>::iterator it=itlow; it!=itup; ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    
    return 0;
}
