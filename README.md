#Implementation of greedy algorithms.

---
<p align="right">
Specialization:Data Structures and Algorithms</br>
Course:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Algorithmic Toolbox</br>
Project:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
Assignment&nbsp;2</br></p>

---
Implemented solutions by using greedy algorithm for the following computational problems:

- changing money
- fractional knapsack
- covering segments by points
- pairwise distinct summands

## Problem 1: [Changing Money]
Find the minimum number of coins (C) needed to change the given amount of money (M)
using coins with denominations 1, 5, and 10.</br> 
Input:&nbsp;&nbsp;&nbsp;1&le;M&le;1E5</br> 
Output: C</br>
**Note**  </br>
- Current implementation assumes that input is the same value as coins(no devision by 100).  
- Current implementation is O(1). Doesn't support any other coin values.

## Problem 2: [Fractional Knapsack]
Given a set of items (N) with specified weight (w<sub>i</sub>) and value (v<sub>i</sub>)
and total capacity of a knapsack (W), 
find the maximal value of fractions of items that fit into the knapsack (M).  
Input:&nbsp;&nbsp;&nbsp;1&le;N&le;10<sup>3</sup>, 0&le;W&le;2&times;10<sup>6</sup>,
0&le;v<sub>i</sub>&le;2&times;10<sup>6</sup>, 0&lt;w<sub>i</sub>&le;2&times;10<sup>6</sup> for all i in 1&le;i&le;N</br>
Output: M  
*Example*:  
Input:      

    3   50  Number of items 3.   Total capacity of knapsack 50.
    60  20  Value of item 1 60,  Weigh of item 1 20.
    100 50  Value of item 2 100, Weigh of item 2 50. 
    120 30  Value of item 3 120, Weigh of item 3 30.
Output:

    180.0000
**Note**  
- Complexity O(n&sdot;log(n))

## Problem 3: [Covering Segments by Points]
Given a set of n segments {[a<sub>0</sub>,b<sub>0</sub>],
[a<sub>1</sub>,b<sub>1</sub>],...,[a<sub>n-1</sub>,b<sub>n-1</sub>]} with integer coordinates on a line,
find the minimum number m of points such that each segment contains at least one point.
That is, find a set of integers &Chi; of the minimum size such that for any segment [a<sub>i</sub>,b<sub>i</sub>] there is a point x&isin;&Chi; such that a<sub>i</sub>&le;x&le;b<sub>i</sub>.  
Input:&nbsp;&nbsp;&nbsp;1&le;n&le;1000; 0&le;a<sub>i</sub>&le;b<sub>i</sub>&le;10<sup>9</sup> for all 0&le;i&le;n. 
Output: number of points m and there coordinates.  
*Example*:  
Input:

    4   Number of segments 
    4 7 Segment 1
    1 3 Segment 2
    2 5 Segment 3
    5 6 Segment 4
Output:

    2   Number of points
    3 6 Coordiantes of points

**Note**
- Complexity O(n&sdot;log(n))

## Problem 4: [Pairwise Distinct Summands]
Given positive integer N as a sum of as many pairwise distinct positive integers as possible. 
That is, to find the maximum k such that N can be written as a<sub>1</sub>+a<sub>2</sub>+...+a<sub>k</sub> where a<sub>1</sub>,...,a<sub>k</sub>
are positive integers and a<sub>i</sub>&ne;a<sub>j</sub> for all 1&le;*i*&lt;*j*&le;k.  
Input:&nbsp;&nbsp;&nbsp;1&le;N&le;10<sup>9</sup>  
Output:Number of summands and list of summands.  
*Example*:  
Input:

    8
Output:

    3      Number of summands.
    1 2 5  Summands

**Note**  
- Complexity O(&radic;N)

[Changing Money]:./src/change.c
[Fractional Knapsack]:./src/fractional_knapsack.c
[Covering Segments by Points]:./src/covering_segments.c
[Pairwise Distinct Summands]:./src/different_summands.c
