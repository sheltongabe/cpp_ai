
# A* Search Algorithm

## aStar(initialState, getActions, goalTest, heuristic) -> void

- Place initialState in the root node and state map
- Check if initialState is in a goal state and return if it is
- Create a frontier vector and make it a heap
- Create an explored map<State, string>
- While true:
  - If the frontier is empty:
    - Return failure
  - Get the front Node of the vector (minimum estimated cost) and place in node
  - Pop that value from the heap
  - Add node.state to the explored map
  - Get all of the actions from this State
  - For each action:
    - Copy node.state and apply action
    - If the result is not in explored:
      - Create a childNode with that state
      - Calculate the estimatedCost of the state
      - Set everything with the childNode
      - If the state is a goal state:
        - GenerateSolution(childNode)
        - Return success
      - Push the childNode to the frontier