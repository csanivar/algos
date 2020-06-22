class Solution:
    
    dirs = [[1,0],[-1,0],[0,1],[0,-1]]
    
    def isValidPos(self, x, y, N, M):
        return x>=0 and y>=0 and x<N and y<M
    
    def dfs(self, board, row, col, N, M):
        if board[row][col] == '-1':
            return
        
        stack = [[row,col]]
        
        while len(stack):
            x, y = stack[-1]
            stack.pop()
            board[x][y] = '-1'
            for dir in self.dirs:
                x_new = x + dir[0]
                y_new = y + dir[1]
                if self.isValidPos(x_new, y_new, N, M) and board[x_new][y_new] == 'O':
                    stack.append([x_new, y_new])
    
    
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        N = len(board)
        if N == 0:
            return
        M = len(board[0])
        
        for row in [0, N-1]:
            for col in range(M):
                if board[row][col] == 'O':
                    self.dfs(board, row, col, N, M)
        
        for col in [0, M-1]:
            for row in range(N):
                if board[row][col] == 'O':
                    self.dfs(board, row, col, N, M)
        
#         print(board)
        
        for row in range(N):
            for col in range(M):
                if board[row][col] == '-1':
                    board[row][col] = 'O'
                elif board[row][col] == "O":
                    board[row][col] = 'X'
