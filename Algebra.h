#include<iostream>
#include<vector>
#include<string>
#include <cmath>
using namespace std;
//test

//base class Expr
class Expr {
private: Expr* e;
public:
    virtual double eval() = 0;
    virtual string outputExpr() const = 0;
    friend ostream& operator <<(ostream &os, const Expr &a) {
        return os << a.outputExpr();
    }
    
};

// class of const
class Const :public Expr {
private:
    int a;
public:
    Const(double a) :a(a) {}
    double eval() { return a; }
    string outputExpr()const {
        return to_string(a);
    }
    double getConst() { return this->a; }
};

//class of sin
class Sin :public Expr {
private: string s; double a;
public:  Sin (string s, double a = 0) :s(s), a(a) { Sin::Globalmap->push_back(this); }
    static vector<Sin*> *Globalmap;
    static void set(string n, int v) {
        for (auto it = Globalmap->begin(); it != Globalmap->end(); it++)
        {
            if ((*it)->s == n)
            {
                (*it)->a = v;
            }
        }
    }
    double eval() { return sin(this->a); }
    //test
    string outputExpr()const {
        return "sin("+this->s+")";
    }
    double getVar() { return sin(this->a); }
    
};

//class of cos
class Cos :public Expr {
private: string s; double a;
public:  Cos (string s, double a = 0) :s(s), a(a) { Cos::Globalmap->push_back(this); }
    static vector<Cos*> *Globalmap;
    static void set(string n, int v) {
        for (auto it = Globalmap->begin(); it != Globalmap->end(); it++)
        {
            if ((*it)->s == n)
            {
                (*it)->a = v;
            }
        }
    }
    double eval() { return cos(this->a); }
    
    string outputExpr()const {
        return "cos("+this->s+")";
    }
    double getVar() { return cos(this->a); }
    
};

//Var
class Var :public Expr {
private: string s; double a;
public:  Var(string s, double a = 0) :s(s), a(a) { Var::Globalmap->push_back(this); }
    static vector<Var*> *Globalmap;
    static void set(string n, int v) {
        for (auto it = Globalmap->begin(); it != Globalmap->end(); it++)
        {
            if ((*it)->s == n)
            {
                (*it)->a = v;
            }
        }
    }
    double eval() { return this->a; }
    string outputExpr()const {
        return this->s;
    }
    double getVar() { return this->a; }
};

class Add :public Expr
{
private:
    Expr  *leftOp, *rightOp;
public:
    Add(Expr *lhs, Expr *rhs)
    {
        leftOp = lhs;
        rightOp = rhs;
    }
    string outputExpr() const
    {
        return leftOp->outputExpr() + " + " + rightOp->outputExpr();
    }
    double eval()
    {
        return leftOp->eval() + rightOp->eval();
    }
};
// Mult
class Mult :public Expr
{
private:
    Expr  *leftOp, *rightOp;
public:
    Mult(Expr *lhs, Expr *rhs)
    {
        leftOp = lhs;
        rightOp = rhs;
    }
    string outputExpr() const
    {
        return leftOp->outputExpr() + " * " + rightOp->outputExpr();
    }
    double eval()
    {
        return leftOp->eval() * rightOp->eval();
    }
};
