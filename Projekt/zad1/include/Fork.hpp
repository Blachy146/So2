#pragma once

#include <mutex>
#include <memory>


class Fork
{
public:
  Fork(int id, std::shared_ptr<std::mutex> printMtx);

  int startUsing();
  int stopUsing();

  int getId();

  ~Fork();
private:
  const int id;
  std::shared_ptr<std::mutex> printMtx;
};
