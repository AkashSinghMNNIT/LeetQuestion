class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        freq = [0]*26
        for task in tasks:
            freq[ord(task)-ord('A')] += 1
        freq.sort()
        chunk = freq[25]-1
        vacant = chunk * n

        for i in range(24, -1, -1):
            vacant -= min(chunk, freq[i])
        
        return len(tasks) + vacant if vacant>=0 else len(tasks)
        