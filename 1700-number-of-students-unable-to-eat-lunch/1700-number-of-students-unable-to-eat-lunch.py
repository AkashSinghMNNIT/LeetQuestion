class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        a, b, n = 0, 0, len(students)
        for _ in students:
            a += _
        for i in range(n):
            b += sandwiches[i]
            if sandwiches[i] and b>a:
                return n-i
            elif not sandwiches[i] and i+1-b > n-a:
                return n-i
        return 0;