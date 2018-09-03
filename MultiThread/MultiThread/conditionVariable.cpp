//
//  conditionVariable.cpp
//  MultiThread
//
//  Created by PinguMac on 2018/8/30.
//  Copyright © 2018年 PinguMac. All rights reserved.
//

#include "ThreadExample.hpp"
#include <mutex>


bool var = true;

void threadFunc(mutex &mtx, condition_variable &convar) {
  unique_lock<mutex> lock(mtx);
  
  while (var) {
    
  }
}

void conditionVariable() {
  mutex mtx;
  condition_variable convar;
  thread t1 {threadFunc, ref(mtx), ref(convar)};
  
  this_thread::sleep_for(chrono::seconds(1));
  var = false;
  
  t1.join();
}
