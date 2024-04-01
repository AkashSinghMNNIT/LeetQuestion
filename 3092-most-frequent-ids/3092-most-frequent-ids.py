from sortedcontainers import SortedList
class Solution:
    def mostFrequentIDs(self, nums: List[int], freq: List[int]) -> List[int]:
        cnt = Counter()
        srt = SortedList()
        ans = []
        for num, f in zip(nums, freq):
            if cnt[num]:
                srt.remove(cnt[num])
            cnt[num]+=f
            srt.add(cnt[num])
            ans.append(srt[-1] if len(srt)>0 else 0)
        return ans