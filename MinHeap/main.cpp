#include<iostream>
#include<math.h>
using namespace std;

void swap(int &a1, int &a2)
{
    int temp=a1;
    a1=a2;
    a2=temp;
}
class MinHeap
{
public:
    int *harr;      //pointer to the array of elements in heap
    int capacity;  //maximum possible size of the min heap
    int heap_size; //current number of elements in the min heap
    MinHeap(int cap)
    {
        heap_size=0;
        capacity = cap;
        harr= new int[capacity];
    }
    void linearSearch(int val)
    {
        for(int i=0;i<heap_size;i++)
        {
            if(harr[i]==val)
            {
                cout<<"Value found!";
                return;
            }
        }
        cout<<"Value is not found";
    }
    void printArray()
    {
        for(int i=0;i<heap_size;i++)
        {
            cout<<harr[i]<<" ";
        }
        cout<<endl;
    }
    int height()
    {
        return ceil(log2(heap_size+1))-1;
    }
    int parent(int i)
    {
        return (i-1)/2;
    }
    int left(int i)
    {
        return (2*i+1);
    }
    int right(int i)
    {
        return (2*i+2);
    }
    void insertKey(int val)
    {
        if(heap_size==capacity)
        {
            cout<<"Overflow: Heap full";
            return;
        }
        harr[heap_size]=val;
        heap_size++;
        int i=heap_size-1;
        while(i!=0 && harr[i]<harr[parent(i)])
        {
            swap(harr[i],harr[parent(i)]);
            i=parent(i);
        }
    }
    int getMin()
    {
        return harr[0];
        
    }
    void minHeapify(int index)
    {
        int l = left(index);
        int r = right(index);
        int smallest =index;
        if(l<heap_size && harr[l]<harr[smallest])
            smallest= l;
        if(r<heap_size && harr[r]<harr[smallest])
            smallest= r;
        if(smallest!=index)
        {
            swap(harr[index], harr[smallest]);
            minHeapify(smallest);
        }
    }
    int extractMin()
    {
       if(heap_size<=0)
           return INT_MAX;
      else if(heap_size==1)
      {
          heap_size--;
          return harr[0];
      }
     else
     {
         int root=harr[0];
         harr[0]=harr[heap_size-1];
         heap_size--;
         minHeapify(0);
         return root;
     }
    }
    void deleteKey(int i)
    {
        if(i>=heap_size)
            return;
        else
        {
            harr[i]=INT_MIN; // -2147483648
            while(i!=0 && harr[i]<harr[parent(i)])
            {
                swap(harr[i],harr[parent(i)]);
                i=parent(i);
            }
            extractMin();
        }
    }
};
void bubbleDown(int i,int size,int arr[])
{
    int l=2*i+1;
    int r=2*i+2;
    int largest=i;
    if(l<size-1 && arr[l]>arr[largest])
        largest=l;
    if(r<size-1 && arr[r]>arr[largest])
        largest=r;
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        bubbleDown(largest,size,arr);
    }
}
void heapify(int arr[],int n)
{
    int i= (n-2)/2;
    while(i>=0)
    {
        bubbleDown(i,n,arr);
        i--;
    }
}

void heapsortHelper(int arr[], int size)
{
    if(size>0)
    {
        int r=arr[0];
        arr[0]=arr[size-1];
        bubbleDown(0,size,arr);
        arr[size-1]=r;
        heapsortHelper(arr,size-1);
    }
    return;
    
}
void heapSort(int arr[], int size)
{
    heapify(arr,size);
    heapsortHelper(arr,size);
}
int main()
{
    int arr[]={10,20,15,30,40,79,3,65,33,12,3433,1,6543,545,322};
    heapify(arr,15);
    for(int i=0;i<15;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapSort(arr,15);
    for(int i=0;i<15;i++)
    {
        cout<<arr[i]<<" ";
    }
//    int s;
//    cout<<"Enter the size of the min heap"<<endl;
//    cin>>s;
//    MinHeap obj(s);
//    cout<<"Min Heap Created"<<endl;
//    int option,val;
//    do
//    {
//        cout<<"What operation do you want to perform?"<<" Select Option number. Enter 0 to exit."<<endl;
//        cout<<"1. Insert Key/Node/value"<<endl;
//        cout<<"2. Search Key/Node"<<endl;
//        cout<<"3. Delete Key/Node"<<endl;
//        cout<<"4. Get Min"<<endl;
//        cout<<"5. Extract Min"<<endl;
//        cout<<"6. Height of Heap"<<endl;
//        cout<<"7. Print/Traversal Heap values"<<endl;
//        cout<<"8. Clear Screen"<<endl;
//        cout<<"0. Exit Program"<<endl;
//
//        cin>> option;
//        switch(option)
//        {
//            case 0:
//                break;
//            case 1:
//                cout<<"Insert Operation -"<<endl;
//                cout<<"Enter value to insert in heap: ";
//                cin>>val;
//                obj.insertKey(val);
//                cout<<endl;
//                break;
//            case 2:
//                cout<<"Search Operation -"<<endl;
//                cout<<"Enter value to search in the heap :";
//                cin>>val;
//                //obj.linearSearch(int val);
//                break;
//            case 3:
//                cout<<"Delete Operation -"<<endl;
//                cout<<"Enter index of heap array to delete : ";
//                cin>>val;
//                obj.deleteKey(val);
//                break;
//            case 4:
//                cout<<"Get Min value : ";
//                //cout<<obj.getMin()<<endl;
//                cout<<endl;
//                break;
//            case 5:
//                cout<<"Extract Min value : ";
//                cout<<obj.extractMin()<<endl;
//                cout<<endl;
//                break;
//            case 6:
//                cout<<"Heap Tree Height : ";
//                //cout<<obj.height()<<endl;
//                break;
//            case 7:
//                cout<<"print Heap Array :"<<endl;
//                obj.printArray();
//                cout<<endl;
//            default:
//                cout<<" Enter Proper Option number "<<endl;
//        }
//
//    }while(option!=0);
    return 0;
    
}
