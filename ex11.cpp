//-----------------------INCLUDE SECTION--------------------------------------
#include <iostream>
#include <new>
//------------------------USING SECTION---------------------------------------
using std::endl;
using std::cout;
using std::cin;
using std::cerr;
//-----------------------FUNCTION SECTION------------------------------------
void input_rows(int **&arr , int &num_of_lines);
void arr_size(int **arr , int rows);
void read(int arr[] , int size);
void calc_sum(int **arr , int num_of_lines );
//----------------------------MAIN---------------------------------------------
int main ()
{
    int **arr ;
    int num_of_lines ;

    input_rows(arr ,num_of_lines);
    arr_size(arr,num_of_lines);
    calc_sum(arr, num_of_lines);
    for (int i= 0; i<num_of_lines; i++)
    {
        delete[]arr[i];
    }
    return EXIT_SUCCESS;
}
//----------------------------------------------------------------------------
void input_rows(int **&arr , int &num_of_lines)
{
    cin>>num_of_lines ;
    arr = new(std::nothrow) int *[num_of_lines];

    if(arr == NULL)
    {
        cerr<<"OOPS"<<endl;
        delete[]arr;
        exit(EXIT_FAILURE);
    }
}
//-----------------------------------------------------------------------------
void arr_size(int **arr , int num_of_lines)
{
    int size;

    for (int i = 0; i < num_of_lines ; i++)
    {
        cin >>size ;

        arr[i] = new (std::nothrow) int [size+1];

        if(arr[i] == NULL)
        {
            cerr<<"OOPS"<<endl;
            for (int i = 0; i< num_of_lines; i++)
            {
                delete[] arr[i];
            }
            exit(EXIT_FAILURE);
        }
        read(arr[i],size);
    }
}
//-------------------------------------------------------------------------------
void read(int arr[],int size)
{
    arr[0]=size;
    for (int i = 1; i <= size ; i++)
    {
        cin>>arr[i];
    }
}
//---------------------------------------------------------------------------------
void calc_sum(int **arr,int num_of_lines)
{
    int sum=0;
    for (int i=0; i<num_of_lines ; i++)
    {
        for (int j=1; j<=arr[i][0]; j++)
        {
            sum+=arr[i][j];
        }
    }
    cout<<sum ;
}
