#ifndef length
#define length(arr) (sizeof(arr) / sizeof(arr[0]))
#endif

void swap(int *a, int *b);

int max(int a, int b);

int min(int a, int b);

void printArray(int arr[], int n);

int maxInArray(int arr[], int n);

int minInArray(int arr[], int n);

int indexOf(int arr[], int n, int element);

void bubbleSort(int arr[], int n);

void bubbleSortDsc(int arr[], int n);

void selectionSort(int arr[], int n);

void selectionSortDsc(int arr[], int n);

void insertionSort(int arr[], int n);

void insertionSortDsc(int arr[], int n);

int partition(int arr[], int low, int high);

void quickSort(int arr[], int low, int high);

int partitionDsc(int arr[], int low, int high);

void quickSortDsc(int arr[], int low, int high);

void merge(int arr[], int l, int m, int r);

void mergeSort(int arr[], int l, int r);

void mergeDsc(int arr[], int l, int m, int r);

void mergeSortDsc(int arr[], int l, int r);

void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int max(int a, int b){
	if(a > b)
		return a;
	else
		return b;
}

int min(int a, int b){
	if(a < b)
		return a;
	else
		return b;
}

void printArray(int arr[], int n){ 
	int i; 
	for (i=0; i <n; i++){
		printf("[%d] ", arr[i]);
	}
	printf("\n");
}

int maxInArray(int arr[], int n){
	int i, index;
	int max = arr[0];
	for(i=0; i<n; i++){
		if(arr[i] > max){
			max = arr[i];
			index = i;
		}
	}
	return i;
}

int minInArray(int arr[], int n){
	int i, index;
	int min = arr[0];
	for(i=0; i<n; i++){
		if(arr[i] < min){
			min = arr[i];
			index = i;
		}
	}
	return i;
}

int indexOf(int arr[], int n, int element){
	int i;
	for(i=0; i<n; i++){
		if(arr[i] == element)
			return i;
	}
	return -1;
}

void bubbleSort(int arr[], int n){
	int i, j,tmp; 
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

void bubbleSortDsc(int arr[], int n){
	int i, j,tmp; 
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(arr[j] < arr[j+1]){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

void selectionSort(int arr[], int n){
	int i,j,index,tmp;
	for(i=0; i<n-1; i++){
		index = i;
		for(j=i+1; j<n; j++){
			if(arr[j] < arr[index]){
				index = j;
			}
		}
		swap(&arr[i],&arr[index]);
	}
}

void selectionSortDsc(int arr[], int n){
	int i,j,index,tmp;
	for(i=0; i<n-1; i++){
		index = i;
		for(j=i+1; j<n; j++){
			if(arr[j] > arr[index]){
				index = j;
			}
		}
		swap(&arr[i],&arr[index]);
	}
}

void insertionSort(int arr[], int n){
	int i,j,key;
	for(i=1; i<n; i++){
		key = arr[i];
		j = i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

void insertionSortDsc(int arr[], int n){
	int i,j,key;
	for(i=1; i<n; i++){
		key = arr[i];
		j = i-1;
		while(j>=0 && arr[j]<key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int partition(int arr[], int l, int r){
	int pivot = arr[r], i = (l - 1), j, tmp;
	for (j=l; j<=r-1; j++){
		if (arr[j] < pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[r]);
	return (i + 1);
}

void quickSort(int arr[], int l, int r){
	if (l < r){
		int pi = partition(arr, l, r);
		quickSort(arr, l, pi - 1);
		quickSort(arr, pi + 1, r);
	}
}

int partitionDsc(int arr[], int l, int r){
	int pivot = arr[r], i = (l - 1), j, tmp;
	for (j=l; j<=r-1; j++){
		if (arr[j] >= pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[r]);
	return (i + 1);
}

void quickSortDsc(int arr[], int l, int r){
	if (l < r){
		int pi = partitionDsc(arr, l, r);
		quickSortDsc(arr, l, pi - 1);
		quickSortDsc(arr, pi + 1, r);
	}
}

void merge(int arr[], int l, int m, int r){
	int i, j, k;
	int n1 = m-l+1;
	int n2 = r-m;
	int L[n1], R[n2];	
	for(i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for(j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 
	i = 0;
	j = 0;
	k = l;
	while(i<n1 && j<n2){
		if(L[i] <= R[j]){ 
			arr[k] = L[i]; 
			i++; 
		} 
		else{ 
			arr[k] = R[j];
			j++;
		} 
		k++;
	}
	while(i < n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2){
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r){
	if (l < r){
		int m = l+(r-l)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

void mergeDsc(int arr[], int l, int m, int r){
	int i, j, k;
	int n1 = m-l+1;
	int n2 = r-m;
	int L[n1], R[n2];	
	for(i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for(j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 
	i = 0;
	j = 0;
	k = l;
	while(i<n1 && j<n2){
		if(L[i] >= R[j]){ 
			arr[k] = L[i]; 
			i++; 
		} 
		else{ 
			arr[k] = R[j];
			j++;
		} 
		k++;
	}
	while(i < n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2){
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSortDsc(int arr[], int l, int r){
	if (l < r){
		int m = l+(r-l)/2;
		mergeSortDsc(arr, l, m);
		mergeSortDsc(arr, m+1, r);
		mergeDsc(arr, l, m, r);
	}
}
