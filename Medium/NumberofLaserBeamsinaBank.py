class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        source = 0
        total_lasers = 0
        for row in bank:
            # Set initial source at the start
            if source == 0:
                source = sum(int(char) for char in row)
            # Blank row
            elif sum(int(char) for char in row) == 0:
                continue
            # If row has beacons
            else:
                row_sum = sum(int(char) for char in row)
                total_lasers += row_sum * source
                source = row_sum
        return total_lasers
