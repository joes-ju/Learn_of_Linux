#include"string.h"

int main()
{
  try
  {
    joes::test09();
  }
  catch (const exception& e)
  {
    cout<<e.what()<<endl;
  }//抛异常

  return 0;
}
