#include <bits/stdc++.h>
using namespace std;
int size = 8;
int disk_size =200;
void CLOOK (int arr[], int head)
{
    int seek_count =0;
    int c=1;
    int d=1;
    int distance ,cur_track;
    vector <int> right;
    vector <int> left;
    int seek_sequence[100];

    for (int i=0; i<size; i++)
    {
        if (arr[i]<head)
        {  left.push_back(arr[i]);
            c=c+1;
        }
        if (arr[i]>head)
        {
            right.push_back(arr[i]);
            d++;
        }


    }
    void sort(left[], int c)
    {
        int i,j;
        for (i=0;i<c-1;i++)
        for (j=0;j<c-i-1;j++)
            if (left[j]>left[j+1])
                swap(&left[j], &left[j+1]);
    }
    void sort(right[], int d)
    {
        int i, j;
        for (i=0; i < d-1; i++)
        for (j=0; j< d-i-1;j++)
            if (right[j]>right[j+1])
                swap(&right[j],&right[j+1]);
    }
    for (int i=0; i<right.size();i++)
    {
        cur_track=right[i];
        seek_sequence.push_back(cur_track);
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
        seek_count +=distance;
        head=cur_track;
    }
    cout <<"Total number of operations:"<<seek_count<<endl;
    cout <<"seek sequence is "<<endl;
    for (int i=0;i < seek_sequence.size();i++)
    {
        cout <<seek_sequence[i]<<endl;
    }
}
int main()
{
    int arr[size] = { 176, 79, 34, 60, 92, 11, 41, 114};
    int head =50;
    cout << "Initial position of head :"<<head <<endl;
    CLOOK(arr,head);
}