#include<bits/stdc++.h>
using namespace std;
void firstFit(int blockSize[], int m,
int processSize[], int n)
{
int allocation[n];
memset(allocation, -1, sizeof(allocation));
for (int i = 0; i < n; i++)
{
for (int j = 0; j < m; j++)
{
if (blockSize[j] >= processSize[i])
{
allocation[i] = j;
blockSize[j] -= processSize[i];
break;
}
}
}
cout<<"First Fit Method\n";
cout << "\nProcess No.\tProcess Size\tBlock no.\n";
for (int i = 0; i < n; i++)
{
cout << " " << i+1 << "\t\t"
<< processSize[i] << "\t\t";
if (allocation[i] != -1)
cout << allocation[i] + 1;
else
cout << "Not Allocated";
cout << endl;
}
}
void bestFit(int blockSize[], int m, int processSize[], int n)
{
int allocation[n];
memset(allocation, -1, sizeof(allocation));
for (int i=0; i<n; i++)
{
int bestIdx = -1;
for (int j=0; j<m; j++)
{
if (blockSize[j] >= processSize[i])
{
if (bestIdx == -1)
bestIdx = j;
else if (blockSize[bestIdx] > blockSize[j])
bestIdx = j;
}
}
if (bestIdx != -1)
{
allocation[i] = bestIdx;
blockSize[bestIdx] -= processSize[i];
}
}
cout<<"Best Fit Method\n";
cout << "\nProcess No.\tProcess Size\tBlock no.\n";
for (int i = 0; i < n; i++)
{
cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
if (allocation[i] != -1)
cout << allocation[i] + 1;
else
cout << "Not Allocated";
cout << endl;
}
}
void worstFit(int blockSize[], int m, int processSize[],int n)
{
int allocation[n];
memset(allocation, -1, sizeof(allocation));
for (int i=0; i<n; i++)
{
int wstIdx = -1;
for (int j=0; j<m; j++)
{
if (blockSize[j] >= processSize[i])
{
if (wstIdx == -1)
wstIdx = j;
else if (blockSize[wstIdx] < blockSize[j])
wstIdx = j;
}
}
if (wstIdx != -1)
{
allocation[i] = wstIdx;
blockSize[wstIdx] -= processSize[i];
}
}
cout<<"Worst Fit Method\n";
cout << "\nProcess No.\tProcess Size\tBlock no.\n";
for (int i = 0; i <n; i++)
{
cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
if (allocation[i] != -1)
cout << allocation[i] + 1;
else
cout << "Not Allocated";
cout << endl;
}
}
int main()
{
int m,n;
cout<<"Enter the no. of blocks :: ";
cin>>m;
int blockSize[m];
cout<<"Enter the blockSizes :: ";
for(int i=0;i<=m;i++)
{
cin>>blockSize[i];
}
cout<<"Enter the no. of process :: ";
cin>>n;
int processSize[n];
cout<<"Enter the processSizes :: ";
for(int i=0;i<=n;i++)
{
cin>>processSize[i];
}
int ch =0 ;
cout<<"MENU \n 1. First Fit Method \n 2. Best Fit Method \n 3. Worst Fit Method \n Enter your choice:";
cin>>ch;
switch(ch)
{
case 1: firstFit(blockSize, m, processSize, n);
break;
case 2: bestFit(blockSize, m, processSize, n);
break;
case 3: worstFit(blockSize, m, processSize, n);
break;
default: cout<<"Check input";
}
return 0 ;
}