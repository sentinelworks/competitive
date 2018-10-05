#### `Without continual growth and progress, such words as improvement, achievement, and success have no meaning.`

                                ―-  Benjamin Franklin


## DP AND Binary Search

    DP  complexity: time O(n) or more
    binary search: O(log(n)).  For binary search, you must find there is order.  If you can not find the order, you can not use binary search.

#### We already used binary search to find if any number exists in a given sorted array.
    Given the array of integers (not sorted), how can you find kth element (k<=array size n):
    1. sort array, return a[k-1]: O(nlogn).
    2. can we do better, for example O(logn)? Yes
    3. sort change the original location of number, can we find kth number without change location? Yes we can.
        O(n) solution: use pair with O(n) extra space.
        O(nlogn) solution: binary search, O(1) space  complexity.

#### Find kth element in a unsorted array 
    1. sort array, return a[k-1]: O(nlogn).
    2. can we do better, for example O(logn)? min heap: heap select
    3. quick select
    4. preserve order: use pair with O(n) extra space. Or use array of index, sort index based on a[i]
            introduction: Functor, anonymous function in C++
    5. preserve order: use O(n) space do a quick select or min heap select
    6. use priority_queue for k elements.  for (int i=0; i<k; ++i) for (;i<n; ++i) if(a[i]<pq.top()) pq.pop(), pq.push(a[i]); return pq.top()
    7. binary search: O(1) space

#### DP properties:
    1. overlapped sub-problems
    2. optimal substructure

    dp: mathematical induction
    cost: extra memory to save the solution for previous simpler sub-problems.
    If sub-problems does not overlap, there is no sense to use dp.

#### How to use DP:
    1. state: what does state means
    2. initial state: it is the base or simplest sub-problem
    3. state transition: get the current state from previous state
    4. solution based on final or/and other states

    bottom-up or top-down: in most cases use bottom up as it is faster without recursive calls.  But there might be cases that you should/must use top-down, like x**n.

    Longest increasing sub-sequence
    Longest Panlindrome sub-sequence
    Longest Common Substring
    Number Triangle

    We will focus on sum set problems


### Home Work

    0. count bits for number 0-n. : dp
    1.  for two sorted array of integer, find kth.
    2.  for one sorted matrix (sorted in every row and column), find kth
        brute force
        dp: use col[number of rows]
        binary search
        heap (priority queue) what should be put into queue: value, index

    https://www.geeksforgeeks.org/kth-smallest-element-in-a-row-wise-and-column-wise-sorted-2d-array-set-1/

    3. Given an array of integers, Divide it into k non-empty groups, Find max sum in all these k groups.
        brute force
        dp (bottom-up, top-down)
        binary search
