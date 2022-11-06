import sys
INT_MAX = sys.maxsize


#l = [5,2,4,7,1,3,2,6]

def merge_sort(A,p,r):
    if p < r:
        q = (p+r)/2
        merge_sort(A,p,q)
        merge_sort(A,q+1,r)
        merge(A,p,q,r)

def merge(A,p,q,r):
    n1 = q-p+1
    n2 = r-q
    A1=[0]*(n1+1)
    A2=[0]*(n2+1)

    for i in range(0,n1):
        A1[i] = A[p+i]
    for j in range(1,n2):
        A2[j] = A[q+j+1]

    A1[n1] = INT_MAX
    A2[n2] = INT_MAX

    i,j =0

    for k in range(p,r+1):
        if A1[i] <= A2[j]:
            A[k] = A1[i]
            i = i+1
        else:
            A[k] = A2[j]
            j = j+1
            

def main():

    l = [5,2,4,7,1,3,2,6]

    #print("Before sort: &d" %*l)
    print(*l)
    merge_sort(l,0,len(l)-1)
    print(*l)
    #print("After sort: %d" %*l)

if __name__ == "__main__":
    main()
