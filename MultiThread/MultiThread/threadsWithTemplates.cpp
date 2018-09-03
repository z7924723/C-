//
//  threadsWithTemplates.cpp
//  MultiThread
//
//  Created by PinguMac on 2018/8/28.
//  Copyright © 2018年 PinguMac. All rights reserved.
//

#include "ThreadExample.hpp"

template <typename T>
void threadFunction() {
  cout << "Type is: " << typeid(T).name() << endl;
}

void threadsWithTemplates() {
  
  cout << "---threadsWithTemplates()---" << endl;
  
  thread t1 {threadFunction<int>};
  this_thread::sleep_for(chrono::milliseconds(1000));
  thread t2 {threadFunction<float>};
  
  t1.join();
  t2.join();
}
