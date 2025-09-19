#include <iostream>>
using namespace std;

class WalkableRobot
{
public:
    virtual void walk();
    virtual ~WalkableRobot()
    {
    }
};

class NormalWalk : public WalkableRobot
{
public:
    void walk() override
    {
        cout << "walking normally" << endl;
    }
};

class NoWalk : public WalkableRobot
{
public:
    void walk() override
    {
        cout << "Cannnot Walk" << endl;
    }
};

// --- Strategy Interface for Talk ---
class TalkableRobot
{
public:
    virtual void talk() = 0;
    virtual ~TalkableRobot() {}
};

// --- Concrete Strategies for Talk ---
class NormalTalk : public TalkableRobot
{
public:
    void talk() override
    {
        cout << "Talking normally..." << endl;
    }
};

class NoTalk : public TalkableRobot
{
public:
    void talk() override
    {
        cout << "Cannot talk." << endl;
    }
};

// --- Strategy Interface for Fly ---
class FlyableRobot
{
public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
};

class NormalFly : public FlyableRobot
{
public:
    void fly() override
    {
        cout << "Flying normally..." << endl;
    }
};

class NoFly : public FlyableRobot
{
public:
    void fly() override
    {
        cout << "Cannot fly." << endl;
    }
};

class Robot
{
protected:
    WalkableRobot *walkBehavior;
    TalkableRobot *TalkBehavior;
    FlyableRobot *flyBehavior;

public:
    Robot(WalkableRobot *w, TalkableRobot *t, FlyableRobot *f)
    {
        this->walkBehavior = w;
        this->TalkBehavior = t;
        this->flyBehavior = f;
    }

    void walk()
    {
        walkBehavior->walk();
    }

    void talk()
    {
        TalkBehavior->talk();
    }

    void fly()
    {
        flyBehavior->fly();
    }

    virtual void projection() = 0;
};

class CompanionRobot : public Robot
{
public:
    CompanionRobot(WalkableRobot *w, TalkableRobot *t, FlyableRobot *f) : Robot(w, t, f) {}
    void projection() override
    {
        cout << "Displaying friendly companion features..." << endl;
    }
};

class WorkerRobot : public Robot {
public:
    WorkerRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f)
        : Robot(w, t, f) {}

    void projection() override {
        cout << "Displaying worker efficiency stats..." << endl;
    }
};

int main()
{
    Robot *robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());

    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

    cout << "--------------------" << endl;

    Robot *robot2 = new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();

    return 0;
}