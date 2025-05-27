#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton
{
public:
    static Singleton &Get();
     void fun();

private:
    Singleton();
    static Singleton s_Instance;

};

#endif // SINGLETON_H
