//
//  threadsWithSTL.cpp
//  MultiThread
//
//  Created by PinguMac on 2018/8/28.
//  Copyright © 2018年 PinguMac. All rights reserved.
//

#include "ThreadExample.hpp"
#include <initializer_list>

void threadFunction(initializer_list<int> initList) {
  cout << "initList size = " << initList.size() << endl;
}

void threadsWithSTL() {
  
  cout << "---threadsWithSTL()---" << endl;
  
  initializer_list<int> initList = {1, 2, 3, 4, 5};
  thread t1 {threadFunction, initList};
  
  t1.join();
}
