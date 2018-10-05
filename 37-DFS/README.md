#### `Well done is better than well said. Benjamin Franklin`

                                ―-  Benjamin Franklin
Winston S. Churchill

### mother's milk:
    You can use both DFS/BFS for searching the solution.
    DFS: use stack
        1. you know what to search, or your state
        2. you know when to branch to next search
        3. you know when to exit  and when to cut the twig (not going further)
    BFS: use queue
        the same as DFS

    when to use DFS or BFS?
        Just my experience, not a rule
        1. If you want to traverse all the choices, both are ok
        2. If you want to find the path, DFS might be the first choice
        3. If you want to find the optimal solution (like shortest path), BFS might be the first choice.

### Home Work:
    1. DFS: sudoku solver, similar to 8-queen problem
        is_safe(X): X is the state 
        DFS: how to search the solution? find unassigned grid, find the safe number, then do DFS for next state
        For sudoku, there is only one solution (normal), or no solution, or multiple solutions.
        We first use backtracking, then branch-and-bound.

        BACKTRACKING vs. BRANCH-AND-BOUND
        1. backtracking is normal, can be used for a lot of cases.
        2. branch-and-bound is an optimization technique.  Only when you find the bound function, can you use the bound to cut the twig fast.  Not all the problems can be optimized by using B&B, just like DP (Dynamic programming).


### BFS: USACO knight cover problem (as few as knight)
        knight cover vs. knight tour


