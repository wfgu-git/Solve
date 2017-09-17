#include <bits/stdc++.h>
using namespace std;

template <class V>
class FibonacciHeap;

template <class V>
struct node {
 private:
  node<V>* prev;
  node<V>* next;
  node<V>* child;
  node<V>* parent;
  V value;
  int degree;
  bool marked;

 public:
  friend class FibonacciHeap<V>;
  node<V>* getPrev() { return prev; }
  node<V>* getNext() { return next; }
  node<V>* getChild() { return child; }
  node<V>* getParent() { return parent; }
  V getValue() { return value; }
  bool isMarked() { return marked; }

  bool hasChildren() { return child; }
  bool hasParent() { return parent; }
};

template <class V>
class FibonacciHeap {
 protected:
  node<V>* heap;

 public:
  FibonacciHeap() { heap = _empty(); }
  virtual ~FibonacciHeap() {
    if (heap) {
      _deleteAll(heap);
    }
  }
  node<V>* insert(V value) {
    node<V>* ret = _singleton(value);
    heap = _merge(heap, ret);
    return ret;
  }
  void merge(FibonacciHeap& other) {
    heap = _merge(heap, other.heap);
    other.heap = _empty();
  }

  bool isEmpty() { return heap == nullptr; }

  V getMinimum() { return heap->value; }

  V removeMinimum() {
    node<V>* old = heap;
    heap = _removeMinimum(heap);
    V ret = old->value;
    delete old;
    return ret;
  }

  void decreaseKey(node<V>* n, V value) { heap = _decreaseKey(heap, n, value); }

  node<V>* find(V value) { return _find(heap, value); }

 private:
  node<V>* _empty() { return nullptr; }

  node<V>* _singleton(V value) {
    node<V>* n = new node<V>;
    n->value = value;
    n->prev = n->next = n;
    n->degree = 0;
    n->marked = false;
    n->child = nullptr;
    n->parent = nullptr;
    return n;
  }

  node<V>* _merge(node<V>* a, node<V>* b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;
    if (a->value > b->value) {
      node<V>* temp = a;
      a = b;
      b = temp;
    }
    node<V>* an = a->next;
    node<V>* bp = b->prev;
    a->next = b;
    b->prev = a;
    an->prev = bp;
    bp->next = an;
    return a;
  }

  void _deleteAll(node<V>* n) {
    if (n != nullptr) {
      node<V>* c = n;
      do {
        node<V>* d = c;
        c = c->next;
        _deleteAll(d->child);
        delete d;
      } while (c != n);
    }
  }

  void _addChild(node<V>* parent, node<V>* child) {
    child->prev = child->next = child;
    child->parent = parent;
    parent->degree++;
    parent->child = _merge(parent->child, child);
  }

  void _unMarkAndUnParentAll(node<V>* n) {
    if (n == nullptr) return;
    node<V>* c = n;
    do {
      c->marked = false;
      c->parent = nullptr;
      c = c->next;
    } while (c != n);
  }

  node<V>* _removeMinimum(node<V>* n) {
    _unMarkAndUnParentAll(n->child);
    if (n->next == n) {
      n = n->child;
    } else {
      n->next->prev = n->prev;
      n->prev->next = n->next;
      n = _merge(n->next, n->child);
    }
    if (n == nullptr) return n;
    node<V>* trees[64] = {nullptr};

    while (true) {
      if (trees[n->degree] != nullptr) {
        node<V>* t = trees[n->degree];
        if (t == n) break;
        trees[n->degree] = nullptr;
        if (n->value < t->value) {
          t->prev->next = t->next;
          t->next->prev = t->prev;
          _addChild(n, t);
        } else {
          t->prev->next = t->next;
          t->next->prev = t->prev;
          if (n->next == n) {
            t->next = t->prev = t;
            _addChild(t, n);
            n = t;
          } else {
            n->prev->next = t;
            n->next->prev = t;
            t->next = n->next;
            t->prev = n->prev;
            _addChild(t, n);
            n = t;
          }
        }
        continue;
      } else {
        trees[n->degree] = n;
      }
      n = n->next;
    }
    node<V>* min = n;
    do {
      if (n->value < min->value) min = n;
      n = n->next;
    } while (n != n);
    return min;
  }

  node<V>* _cut(node<V>* heap, node<V>* n) {
    if (n->next == n) {
      n->parent->child = nullptr;
    } else {
      n->next->prev = n->prev;
      n->prev->next = n->next;
      n->parent->child = n->next;
    }
    n->next = n->prev = n;
    n->marked = false;
    return _merge(heap, n);
  }

  node<V>* _decreaseKey(node<V>* heap, node<V>* n, V value) {
    if (n->value < value) return heap;
    n->value = value;
    if (n->value < n->parent->value) {
      heap = _cut(heap, n);
      node<V>* parent = n->parent;
      n->parent = nullptr;
      while (parent != nullptr && parent->marked) {
        heap = _cut(heap, parent);
        n = parent;
        parent = n->parent;
        n->parent = nullptr;
      }
      if (parent != nullptr && parent->parent != nullptr) parent->marked = true;
    }
    return heap;
  }

  node<V>* _find(node<V>* heap, V value) {
    node<V>* n = heap;
    if (n == nullptr) return nullptr;
    do {
      if (n->value == value) return n;
      node<V>* ret = _find(n->child, value);
      if (ret) return ret;
      n = n->next;
    } while (n != heap);
    return nullptr;
  }
};

class DotFibonacciHeap : public FibonacciHeap<int> {
 public:
  void dump() {
    printf("digraph G {\n");
    if (heap == nullptr) {
      printf("empty;\n}\n");
      return;
    }
    printf("minimum -> \"%p\" [constraint=false];\n", heap);
    node<int>* c = heap;
    do {
      _dumpChildren(c);
      c = c->getNext();
    } while (c != heap);
    printf("}\n");
  }

 private:
  void _dumpChildren(node<int>* n) {
    printf("\"%p\" -> \"%p\" [constraint=false,arrowhead=lnormal];\n", n,
           n->getNext());
    printf("\"%p\" -> \"%p\" [constraint=false,arrowhead=ornormal];\n", n,
           n->getPrev());
    if (n->isMarked()) printf("\"%p\" [style=filled,fillcolor=grey];\n", n);
    if (n->hasParent()) {
      printf("\"%p\" -> \"%p\" [constraint=false,arrowhead=onormal];\n", n,
             n->getParent());
    }
    printf("\"%p\" [label=%d];\n", n, n->getValue());
    if (n->hasChildren()) {
      node<int>* c = n->getChild();
      do {
        printf("\"%p\" -> \"%p\";\n", n, c);
        _dumpChildren(c);
        c = c->getNext();
      } while (c != n->getChild());
    }
  }
};

void test() {
  DotFibonacciHeap h;
  h.insert(2);
  h.insert(3);
  h.insert(1);
  h.insert(4);
  h.removeMinimum();
  h.removeMinimum();
  h.insert(5);
  h.insert(7);
  h.removeMinimum();
  h.insert(2);
  node<int>* nine = h.insert(90);
  h.removeMinimum();
  h.removeMinimum();
  h.removeMinimum();
  for (int i = 0; i < 20; i += 2) h.insert(30 - i);
  for (int i = 0; i < 4; i++) h.removeMinimum();
  for (int i = 0; i < 20; i += 2) h.insert(30 - i);
  h.insert(23);
  for (int i = 0; i < 7; i++) h.removeMinimum();
  h.decreaseKey(nine, 1);
  h.decreaseKey(h.find(28), 2);
  h.decreaseKey(h.find(23), 3);

  h.dump();
}

int main() { test(); }
