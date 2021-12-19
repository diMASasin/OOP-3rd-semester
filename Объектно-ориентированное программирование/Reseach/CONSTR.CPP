#include <iostream.h>

main()
{
{
  cout << "\n\n\nDeclaration\n";
  class sim
  {
  private:
    int k;
  public:
    sim() : k(0) { cout << this << ".sim()\n"; }
    sim(const sim & s) : k(s.k) { cout << this << ".sim(const sim &)\n"; }
    sim(int v) : k(v) { cout << this << ".sim(int)\n"; }
    sim(double v) : k(v) { cout << this << ".sim(double)\n"; }
    ~sim () { cout << this << ".~sim()\n"; }
  } a, b(a), c(1), d(2.0);

  cin.get(char());
  cout << "\nAssignment (int)\n";
  a = 1;

  cin.get(char());
  cout << "\nAssignment (sim)\n";
  b = c;

  cin.get(char());
  cout << "\nArray[5] declaration\n";
  sim e[5];

  cin.get(char());
  cout << "\nInheritance\n";
  class inh1 : public sim {} f;
  class inh2 : public sim { public: inh2() {} } g;

  cin.get(char());
  cout << "\nEnd\n";
}
  cin.get(char());
  return 0;
}