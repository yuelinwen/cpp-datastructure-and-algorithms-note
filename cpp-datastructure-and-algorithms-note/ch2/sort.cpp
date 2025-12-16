
//ranking sort
template <class T>
void rank(T a[], int n, int r[])
{
	for (int i=0; i<n; i++)
		r[i] = 0;

	for (int i=1; i<n; i++)
		for (int j=0; j<i; j++)
			if(a[j] <= a[i]) r[i] ++;
			else
				r[j]++;
}

//selection sort 
template <class T>
void selection (T a[], int n)
{
	for (int size = n; size > 1; size--)
	{
		int j = indexOfMax(a, size);
		swpa(a[j], a[size - 1]);
	}
}

// bubble sort
template <class T>
void bubble(T a[], int n)
{
	for (int 1 = 0; i < n - 1; i++)
		if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
}

template <class T>
void bubbleSort(T a[], int n)
{
	for(int i=n; i>1; i--)
		bubble(a, i);
}