#include "Algebra.h"

vector<Sin*>* Sin::Globalmap = new vector<Sin*>();
vector<Var*>* Var::Globalmap = new vector<Var*>();
vector<Cos*>* Cos::Globalmap = new vector<Cos*>();

//double const Pi= 3.141592653;

int main() {
    Expr* e = new Const(5);
    cout << *e<<endl;   //5
    
    cout << e->eval()<<endl; //5
    
    Expr* e2 = new Add(new Const(5), new Const(3)); // 5 + 3
    cout << e2->eval()<<endl; // 5 + 3 =8
    cout << *e2 << endl;
    
    Expr* e3 = new Add(new Var("x"), new Const(3)); // 5 + 3
    Var::set("x", 5);
    cout << e3->eval() << endl; // 8
    cout << *e3 << endl; // x + 3
    cout << endl;
    
    Expr* e4 = new Add(new Add(new Const(3), new Const(4)),new Var("y"));
    cout << *e4;
    
    Expr* e5 = new Sin("x");
    cout << *e5 << endl;
    Sin::set("x", 5);
    cout << e5->eval()<<endl;
    
    Expr* e6 = new Mult(new Sin("x"),new Cos("y"));
    Cos::set("y",8);
    cout << *e6 << endl;//sin(x)*sin(y)
    cout << e6->eval();
}
