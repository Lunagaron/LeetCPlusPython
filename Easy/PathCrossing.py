class Solution:
    def isPathCrossing(self, path: str) -> bool:
        # Initialise params
        starting = [0, 0]
        traversed = {tuple(starting): 1}

        for direction in path:
            if direction == 'N':
                starting[1] += 1
            elif direction == 'S':
                starting[1] -= 1
            elif direction == 'E':
                starting[0] += 1
            elif direction == 'W':
                starting[0] -= 1
            else:
                print("ERROR: Invalid direction")
                return None

            current_location = tuple(starting)
            # print(f"Moving {direction} into location {starting}")

            if current_location in traversed:
                return True
            else:
                traversed[current_location] = 1

        return False
