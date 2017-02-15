#include <iostream>

using namespace std;

//饿汉模式
class A {
public:
     static A* instance() {
        return inst;
    }

     ~A() {cout<<"free" <<endl;} //destructor never executed, because u allocate the object with new
private:
    A(){}
    A(const A&){}
    A& operator=(const A&){}

    static A* inst;
};
A* A::inst = new A();


//懒汉模式 最佳
//class A {
//public:
//    static A* instance() {
//        static A a;// Guaranteed to be destroyed.
//                   // Instantiated on first use.
//        return &a;
//    }
//private:
//    A() {}
//    A(const A&);
//    A& operator=(const A&);

////public: //c++11
////    A(const A&) = delete;
////    A& operator=(const A&)=delete;

//};

int main(int argc, char *argv[])
{
    A* a = A::instance();
    A* b = A::instance();
    if(a==b) cout<<"cebor"<<endl;
    delete a;
    return 0;
}
