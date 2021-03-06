#include "Test.h"

void Test::testAll(){
    testVector();
    testHeap();
    testCollection();
    testSLinkedList();
    testSet();
    testMap();
    testStack();
    testQueue();
    testPriorityQueue();
}

void Test::testVector(){
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    assert(v[0] == 1);
    assert(v.size() == 5);

    v.removeEnd();

    assert(v.size() == 4);

    v.removeAt(0);

    assert(v.size() == 3);
    assert(v.get_element(0) == 2);
    assert(v.find(2) == 0);
    try{
        assert(v.find(15) == -1);
    }catch(...){
        assert(true);
    }
    assert(v.front() == 2);
    assert(v.back() == v[v.size()-1]);
}

void Test::testHeap(){
    Heap<int> h;

    h.add(1);
    h.add(2);
    h.add(3);
    h.add(4);
    h.add(5);
    //h.print();

    int t = h.remove();
    assert(t == 5);
    //h.print();
}

void Test::testCollection(){
    Collection<int> c;
    c.add(1);
    c.add(2);
    c.add(3);
    c.add(1);
    c.add(4);
    c.add(1);
    assert(c.dim() == 6);

    assert(c.find(1) == true);

    c.remove(1);
    assert(c.dim() == 5);
    assert(c.voidCollection() == false);
}

void Test::testSLinkedList(){
    LinkedList<int> l;
    
    l.add(1);
    l.add(2);
    l.add(3);
    l.add(4);
    l.add(5);
    l.add(6);
    l.first();
   
    assert(l.find(5) == true);
    assert(l.find(6) == true);
    assert(l.Lenght() == 6);
    
}

void Test::testSet(){
    Set<int> s;
    s.add(1);
    assert(s.Length() == 1);
    assert(s[0] == 1);
    s.add(2);
    s.add(3);
    assert(s.Length() == 3);

    try{
        s.add(2);
        assert(false);
    }catch(...){
        assert(true);
    }
    try{
        assert(s[10] == 1);
    }catch(...){
        assert(true);
    }
    assert(s.find(2) == true);
}

void Test::testMap(){
    Map<int> m;
    m.add(Pair<int>(1, 1));
    m.add(Pair<int>(2, 1));
    m.add(Pair<int>(3, 1));

    assert(m.Length() == 3);

    m.add(Pair<int>(4, 2));
    m.add(Pair<int>(5, 3));

    assert(m.Length() == 5);
    assert(m.element(3) == 1);
    assert(m[4] == 2);
}

void Test::testStack(){
    Stack<int> s;
    assert(s.empty() == true);
    s.push(1);
    s.push(2);
    s.push(3);
    assert(s.top() == 3);
    assert(s.pop() == 3);
    s.pop();
    assert(s.Length() == 1);
    assert(s.top() == 1);
    assert(s.empty() == false);
}

void Test::testQueue(){
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    assert(q.Length() == 3);
    assert(q.front() == 1);
    assert(q.back() == 3);
    q.push(4);
    assert(q.empty() == false);
    assert(q.pop() == 1);
    
}

void Test::testPriorityQueue(){
    PriorityQueue<int> pq;
    pq.push(PriorityPair<int>(1, 10));
    pq.push(PriorityPair<int>(3, 30));
    pq.push(PriorityPair<int>(2, 20));
    assert(pq.Length() == 3);
    assert(pq.front() == 30);    

    assert(pq.pop() == 30);
    pq.pop();
    assert(pq.back() == 10);
    assert(pq.pop() == 10);
    assert(pq.empty() == true);
}