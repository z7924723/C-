//
//  futurePromiseAndAsync.cpp
//  MultiThread
//
//  Created by PinguMac on 2018/8/29.
//  Copyright © 2018年 PinguMac. All rights reserved.
//

#include "ThreadExample.hpp"
#include <future>

int asyncFun(int value) {
  cout << "In async Function. " << endl;
  cout << "Async thread =>" << this_thread::get_id() << endl;
  
  return value + 100;
}

void promiseFun(promise<int> & prom) {
  cout << "Promise thread =>" << this_thread::get_id() << endl;
  this_thread::sleep_for(chrono::seconds(2));
  prom.set_value(200);
}

void futurePromiseAndAsync() {
  
  cout << "---futurePromiseAndAsync---" << endl;
  cout << "Main thread =>" << this_thread::get_id() << endl;
  
  future<int> func = async(launch::async, asyncFun, 50);
  
  if (func.valid()) {
    cout << func.get() << endl;
  }
  
  promise<int> mypromise;
  future<int> myfuture = mypromise.get_future();
  
  cout << "Main thread =>" << this_thread::get_id() << endl;
  thread t1 {promiseFun, ref(mypromise)};
  t1.join();
  cout << "Value in main thread =>" << myfuture.get() << endl;
  
  
}
