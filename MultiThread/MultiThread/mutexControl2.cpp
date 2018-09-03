//
//  mutexControl2.cpp
//  MultiThread
//
//  Created by PinguMac on 2018/8/30.
//  Copyright © 2018年 PinguMac. All rights reserved.
//

#include "ThreadExample.hpp"
#include <mutex>

struct Box {
  explicit Box(string name, int money) {
    this->name = name;
    this->money = money;
  }
  
  int money;
  string name;
  
  mutex mtx;
};

void transfer(Box &from, Box &to, int amount) {
  // don't actually take the locks yet
  unique_lock<mutex> lock1(from.mtx, defer_lock);
  unique_lock<mutex> lock2(to.mtx, defer_lock);
  
  // lock both unique_locks without deadlock
  lock(lock1, lock2);
  
  from.money -= amount;
  to.money += amount;
  
  // 'from.money' and 'to.money' mutexes unlocked in 'unique_lock' dtors
  cout << "Transfer " << amount << " from " << from.name << " to " << to.name << endl;
  cout << from.name << " left " << from.money << endl;
  cout << to.name << " left " << to.money << endl;
}

void mutexControl2() {
  
  cout << "---mutexControl---" << endl;
  Box acc1("Gavin", 100);
  Box acc2("Ells", 50);
  
  thread t1(transfer, ref(acc1), ref(acc2), 10);
  thread t2(transfer, ref(acc2), ref(acc1), 5);
  
  t1.join();
  t2.join();
}
