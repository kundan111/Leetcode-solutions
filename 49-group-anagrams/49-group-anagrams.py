class Solution:
    def groupAnagrams(self, strs):
        map_ = {}
        for str_ in strs:
            sorted_ = ''.join(sorted(str_))
            if not sorted_ in map_.keys():
                map_[sorted_] = []
            map_[sorted_].append(str_)
            
        return map_.values()
        