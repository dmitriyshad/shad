#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <algorithm>

using std::pair;
using std::vector;

template <typename T>
class NodeForHeap {
public:
  NodeForHeap();
  
  NodeForHeap<T>* mLeft;
  NodeForHeap<T>* mRight;
  NodeForHeap<T>* mExternalLink;
  bool mIsFree;
  int mPosInHeap;
  T value;
};

template <typename T, class Compare = std::less<T> >
class Heap {
public:
  std::vector<T> mBuf;
  std::vector<std::pair<T, NodeForHeap<T>* > > mPairBuf;
  int mSize;
  NodeForHeap<T>* mListBegin;
  NodeForHeap<T>* mListEnd;
  
  Heap();
  ~Heap();
  void Swap(int posA, int posB);
  void Delete(int pos);
  void Insert(const T& inElem);
  
  int Left(int pos);
  int Right(int pos);
  int Parent(int pos);
  T Top();
  void HeapifyUp(int pos);
  void HeapifyDown(int pos);
  void BuildHeap();
};

class Compare {
public:
  bool operator()(std::pair<int, int> aa, std::pair<int, int> bb) {
    if (aa.first < bb.first) {
      return true;
    } else {
      if (aa.first == bb.first && aa.second > bb.second) {
        return true;
      }
    }
    return false;
  }
};

class MemManager {
public:
  int mMemSize;
  // T = pair<int, int> (длина, начало)
  // PosInHeap используется только в куче, список ничего не знает
  typedef NodeForHeap<pair<int, int> > mPart;
  vector<pair<int, mPart* > > mRequestHistory;
  mPart* mListBegin;
  Heap<pair<int, int>, Compare> mHeapMax;
  
  explicit MemManager(int memlen);
  int GetMem(int size);
  void FreeMem(int requestNumber);
};


int main() {
  int nn, mm;
  std::cin >> nn >> mm;
  MemManager manager(nn);
  int xx;
  for (int i = 0; i < mm; ++i) {
    std::cin >> xx;
    if (xx < 0) {
      manager.mRequestHistory.push_back(std::make_pair(-1, nullptr));
      manager.FreeMem(-xx);
    } else {
      std::cout << manager.GetMem(xx) << std::endl;
    }
  }
  
  return 0;
}
