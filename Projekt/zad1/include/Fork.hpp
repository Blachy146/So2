#pragma once


class Fork
{
public:
  Fork(int id);

  int startUsing();
  int stopUsing();

  ~Fork();
private:
  const int id;
};
