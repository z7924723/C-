//
//  passValueToThread.cpp
//  MultiThread
//
//  Created by PinguMac on 2018/8/24.
//  Copyright © 2018年 PinguMac. All rights reserved.
//

#include "ThreadExample.hpp"

void threadFunction(int value1, int &value2) {
  cout << "In thread function, thread ID: " << this_thread::get_id() << endl;
  cout << "Value 1 = " << value1 << endl;
  cout << "Value 2 = " << ++value2 << endl;
}

void passValueToThread() {
  cout << "---passValueToThread()---" << endl;
  int localVal = 200;
  thread t1(threadFunction, 100, ref(localVal));

  t1.join();
}
