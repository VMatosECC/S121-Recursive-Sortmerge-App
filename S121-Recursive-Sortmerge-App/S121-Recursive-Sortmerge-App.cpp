// S121-Recursive-Sortmerge-App.cpp 

#include <iostream>
#include <vector>
using namespace std;

void mymerge(vector<int>& v, vector<int>& aux, int lo, int hi);
void showVector(vector<int> v, string caption = "");
void msort(vector<int>& v);
void msort(vector<int>& v, vector<int>& aux, int lo, int hi);

int main()
{
   vector<int> v{ 2, 4, 5, 9, 1, 6, 7, 8 };
   showVector(v, "Original vector: ");
   //mymerge(v, aux, 0, v.size() - 1);
   //showVector(v, "Merged vector: ");

   msort(v);
   showVector(v, "Sorted vector: ");

   cout << "\nAll done!\n";
}
//----------------------------------------------------------
void msort(vector<int>& v, vector<int>& aux, int lo, int hi)
{
    //base case testing
    if (hi <= lo) return;

    //General case of recursion
    int mid = (lo + hi) / 2;

    cout << "(" << lo << ", " << mid << "),  (" << mid + 1 << ", " << hi << ")" << endl;
    msort(v, aux, lo, mid);
    msort(v, aux, mid + 1, hi);
    mymerge(v, aux, lo, hi);
}

//----------------------------------------------------------
void msort(vector<int>& v)
{
    vector<int> aux(v);
    msort(v, aux, 0, v.size() - 1);
}


//-----------------------------------------------------------
void showVector(vector<int> v, string caption)
{
    cout << endl << caption << " ";
    for (auto element : v) { cout << element << ", "; }
    cout << endl;
}

//------------------------------------------------------------
void mymerge(vector<int>& v, vector<int>& aux, int lo, int hi)
{
    //vector<int> aux(v);
    copy(v.begin(), v.end(), aux.begin());

    int mid = (lo + hi) / 2;
    int i = lo;
    int j = mid + 1;

    for (int k = lo; k <= hi; k++) {
        if (i > mid) { v[k] = aux[j++]; }
        else
            if (j > hi) { v[k] = aux[i++]; }
            else {

                if (aux[i] < aux[j])
                {
                    v[k] = aux[i++];
                }
                else
                {
                    v[k] = aux[j++];
                }
            }
    }
}