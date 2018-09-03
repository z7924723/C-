//
//  mutexControl.cpp
//  MultiThread
//
//  Created by PinguMac on 2018/8/30.
//  Copyright © 2018年 PinguMac. All rights reserved.
//

#include "ThreadExample.hpp"
#include <mutex>

void threadFunc(mutex &mtx, int value) {
  lock_guard<mutex> lock(mtx); // lock thread when job done, and auto release
  
  cout << "Number:";
  for( int i = 0; i < value; ++i ) {
    this_thread::sleep_for(chrono::milliseconds(10));
    cout << " " << i;
  }
  cout << endl;
}

void mutexControl1() {
  
  cout << "---mutexControl---" << endl;
  mutex mtx;
  thread t1 {threadFunc, ref(mtx), 3};
  thread t2 {threadFunc, ref(mtx), 5};
  cout << "[Main] wait 1 second" << endl;
  

  t1.join();
  t2.join();
}
