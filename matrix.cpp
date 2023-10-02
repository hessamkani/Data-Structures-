#include<iostream>
using namespace std;
#include<vector> 

class matrixes
{
 private:
 int row,col;
 public:
 int get()
 {
    cout<<"enter row of matrixe"<<endl;
    cin>>row;
    cout<<"enter col of matrixe"<<endl;
    cin>>col;
    return row,col;
}

int mohasebat(vector<matrixes>& matrix)
{




}

};
int main(){
    int N;
    class matrixes my_matrix;
    cout << "Enter number of matrixe"<<endl;
    cin>>N;

    vector<matrixes> matrix;

    for(int i=0 ; i<N ; i++)
    {
        // gereftean abad
        my_matrix.get();
        matrix.push_back(my_matrix);
    }


}
