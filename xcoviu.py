def rotate(A,B,C):
  return (B[0]-A[0])*(C[1]-B[1])-(B[1]-A[1])*(C[0]-B[0])
def convexHull(A):
  n = len(A) # number of points 
  P = list(range(n)) # the list of point numbers 
  for i in range(1,n):
    if A[P[i]][0]<A[P[0]][0]:
      P[i], P[0] = P[0], P[i] # swap the numbers of these points 
  for i in range(2,n): # insertion sort 
    j = i
    while j>1 and (rotate(A[P[0]],A[P[j-1]],A[P[j]])<0): 
      P[j], P[j-1] = P[j-1], P[j]
      j -= 1
    S = [A[P[0]], A[P[1]]]
  for i in range(2,n):
    while rotate(A[S[-2]],A[S[-1]],A[P[i]])<0:
      del S[-1] # pop(S)
    S.append(A[P[i]]) # push(S,P[i])
  return S
print (convexHull([[0,3],[2,2],[1,1],[2,1],[3,0],[0,0],[3,3]])