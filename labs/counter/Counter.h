#ifndef COUNTER_H
#define COUNTER_H

#include <cstddef>
#include <string>

#include "List.h"
#include "Index.h"

// This is the Counter class you need to implement.
// It includes the Counter::Iterator as a nested class.

class Counter {
public:
  class Iterator {
    Node *mIndex;

  public:
    Iterator();
    Iterator(Node *nodeIndex);
    const std::string& key() const;
    int value() const;

    void operator ++ ();
    bool operator == (const Iterator& other) const;
    bool operator != (const Iterator& other) const;
  };

private:
  size_t mCount;
  int mTotal;
  List list;
  Hashmap map;

private:
  // Helper Functions

public:
  Counter();
  ~Counter();

  size_t count() const;
  int    total() const;

  void inc(const std::string& key, int by = 1);
  void dec(const std::string& key, int by = 1);
  void del(const std::string& key);
  int  get(const std::string& key) const;
  void set(const std::string& key, int count);

  Iterator begin() const;
  Iterator end() const;
};

#endif
