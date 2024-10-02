from heapq import heappush, heappop

class PuzzleState:
    def __init__(self, board, move=0, prev=None):
        self.board = board
        self.move = move
        self.prev = prev
        self.cost = 0

    def __lt__(self, other):
        return self.cost < other.cost

    def __eq__(self, other):
        return self.board == other.board

    def __hash__(self):
        return hash(tuple(self.board))

    def find_zero(self):
        return self.board.index(0)

    def neighbors(self):
        zero_index = self.find_zero()
        neighbors = []

        # Define possible moves (left, right, up, down)
        moves = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        for dx, dy in moves:
            x, y = zero_index % 3, zero_index // 3
            nx, ny = x + dx, y + dy
            if 0 <= nx < 3 and 0 <= ny < 3:
                neighbor_index = ny * 3 + nx
                new_board = self.board[:]
                new_board[zero_index], new_board[neighbor_index] = new_board[neighbor_index], new_board[zero_index]
                neighbors.append(PuzzleState(new_board, self.move + 1, self))
        return neighbors

def manhattan_distance(board, goal):
    distance = 0
    for index, value in enumerate(board):
        if value == 0:
            continue
        target_index = goal.index(value)
        x1, y1 = index % 3, index // 3
        x2, y2 = target_index % 3, target_index // 3
        distance += abs(x1 - x2) + abs(y1 - y2)
    return distance

def a_star_search(initial, goal):
    open_set = []
    closed_set = set()
    initial_state = PuzzleState(initial)
    initial_state.cost = manhattan_distance(initial_state.board, goal)
    heappush(open_set, initial_state)
    while open_set:
        current_state = heappop(open_set)
        if current_state.board == goal:
            return reconstruct_path(current_state)
        closed_set.add(current_state)
        for neighbor in current_state.neighbors():
            if neighbor in closed_set:
                continue
            neighbor.cost = neighbor.move + manhattan_distance(neighbor.board, goal)
            heappush(open_set, neighbor)
    return None

def reconstruct_path(state):
    path = []
    while state:
        path.append(state.board)
        state = state.prev
    return path[::-1]

# Example usage
initial_state = [1, 2, 3, 4, 5, 6, 7, 8, 0]
goal_state = [1, 2, 3, 4, 5, 6, 7, 8, 0]
solution_path = a_star_search(initial_state, goal_state)

if solution_path:
    print("Solution found in {} moves:".format(len(solution_path) - 1))
    for step in solution_path:
        print(step[0:3])
        print(step[3:6])
        print(step[6:9])
        print()
else:
    print("No Solution found.")
