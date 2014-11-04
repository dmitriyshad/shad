#include <utility>
#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <algorithm>

using std::vector;
using std::stack;
using std::pair;

bool compare(pair<long long, long long> first, pair<long long, long long> second);

void fill(std::istream& inStream,
          vector<pair<long long, long long> >& players, long long& inpsize);
void print_buf(std::ostream& outStream, vector<long long>& buf);

void print_team(std::ostream& outStream, vector<pair<long long, long long> >& players);

int main() {

  long long inpsize;
  vector<pair<long long, long long> > players;
  fill(std::cin, players, inpsize);
  std::sort(players.begin(), players.end(), compare);
  print_team(std::cout, players);
  
  
  return 0;
}
