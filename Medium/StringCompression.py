class Solution:
    def compress(self, chars: List[str]) -> int:
        write = 0
        read = 0

        while read < len(chars):
            # Write the character to the list
            chars[write] = chars[read]
            # Keep track of the count of the character
            count = 1
            # Keep on going on to count max consecutive
            while read < len(chars) - 1 and chars[read] == chars[read + 1]:
                read += 1
                count += 1
            # If counter is greater than 1, turn into string and replace
            if count > 1:
                for num in str(count):
                    write += 1
                    chars[write] = num
            read += 1
            write += 1
        return write
