/**
 * Merge sort (stable): Recursive version
 * Worst: Tw = O(NlogN), extra S = O(N)
 *
 * Recursive version: L equals to the starting index of left part, R equals to 
 * the starting index of right part, RightEnd = the end index of the left part
 *
 * Merge Sort well-ordered A[L]~A[R-1] and A[R]~A[RightEnd] out into 
 * an ordered sequence
 */
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd) {
	int LeftEnd, NumElements, Tmp, i;
	LeftEnd = R - 1;
	Tmp = L;
	NumElements = RightEnd - L + 1;
	while (L <= LeftEnd && R <= RightEnd)
		if (A[L] <= A[R]) TmpA[Tmp++] = A[L++];
		else TmpA[Tmp++] = A[R++];
	while (L <= LeftEnd) TmpA[Tmp++] = A[L++];
	while (R <= RightEnd) TmpA[Tmp++] = A[R++];
	for (i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd];
}
void Msort(ElementType A[], ElementType TmpA[], int L, int RightEnd) {
	if (L < RightEnd) {
		int Centre = (L + RightEnd)/2;
		Msort(A, TmpA, L, Centre);
		Msort(A, TmpA, Centre+1, RightEnd);
		Merge(A, TmpA, L, Centre+1, RightEnd);
	}
}
void MergeSort(ElementType A[], int N) {
	ElementType *TmpA = (ElementType *) malloc(N * sizeof(ElementType));
	if (TmpA != NULL) {
		Msort(A, TmpA, 0, N-1);
		free(TmpA);
	} else printf("Not enough space!\n");
}
