#include <iostream>
#include <stack>
using namespace std;

bool checkOperator( string str , int n )
{
    if ( str[n] == '+' && str[n] == '-' && str[n] == '*' && str[n] == '/'  )
    {
        return true ;
    }
    return false ;
}

int checkParenthesis(string expr) {
    stack<int> s;
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(') {
            s.push(i);
        }
        else if (expr[i] == ')') {
            if (!s.empty()) {
                cout << s.top()  << " " << i << endl ;
                s.pop();
             }
            else
            {
                return 2;
            }
        }
    }
    int c ;
    if (s.empty())
    {
        c = 0 ;
    }
    else
    {
        c = 1 ;
    }
    return  c;
}
void suggest_Parenthesis_baz ( string expr )
{
    stack<int> s;
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(') {
            s.push(i);
        }
        else if (expr[i] == ')') {
            if (!s.empty()) {
                s.pop();
             }
        }
    }
    while (!s.empty())
    {
        for ( int j = s.top() ; j <  expr.length() ; j++ )
        {
            if ( expr[j]>=97 && expr[j]<=122  && checkOperator( expr , j-1 )==0  )
            {
                for (int k=0 ; k <= j ; k++ )
                {
                    cout << expr[k] ;
                }
                cout << ')' ;
                for ( int k = j+1 ; k <= expr.length() ; k++)
                {
                    cout << expr[k];
                }
                cout << endl ;
                s.pop();
            }

        }
    }
}
void suggest_Parenthesis_basteh ( string expr )
{
    stack<int> s;
    stack<int> basteh ;
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(') {
            s.push(i);
        }
        else if (expr[i] == ')') {
            if (!s.empty()) {
                s.pop();
            }
            else
            {
                basteh.push(i);
            }
        }
    }
    while(!basteh.empty())
    {
        for (int j = basteh.top()  ; j!=0 ; j-- )
        {
            if ( expr[j]>=97 && expr[j]<=122  && checkOperator( expr , j+1 )==0 )
            {
                for (int k=0 ; k < j ; k++ )
                {
                    cout << expr[k] ;
                }
                cout << '(' ;
                for ( int k = j ; k < expr.length() ; k++)
                {
                    cout << expr[k];
                }
                cout << endl ;
                basteh.pop();
            }
        }
    }

}
int main() {
    string expr = "(a+b)*c-d)+c)";
    if ( checkParenthesis(expr) == 0 ) {
        cout << "Valid expression" << endl;
    }
    else if ( checkParenthesis(expr) == 1  )
    {
        suggest_Parenthesis_baz(expr);
    }
    else
    {
        suggest_Parenthesis_basteh(expr);
    }
    return 0;
}
