//
//  ThreadExample.cpp
//  MultiThread
//
//  Created by PinguMac on 2018/8/24.
//  Copyright © 2018年 PinguMac. All rights reserved.
//

#include "ThreadExample.hpp"

void threadFunction(int value) {
  cout << "In thread function, thread ID: " << this_thread::get_id() << endl;
  cout << "value = " << value << endl;
}

void createThread() {
  cout << "---createThread()---" << endl;
  thread t1(threadFunction, 100);
  
  // wait the thread stop
  t1.join();

}
