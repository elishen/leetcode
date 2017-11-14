class Solution:
    def longestWord(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        
        if len(words) == 0: 
            return ''
        
        words.sort(key=len)
        
        maps = []
        
        for i in range(30):
            maps.append({})
        
        max_len = 0
        max_wrd = ''
        prv_len = 0
        
        for w in words:
            print(w)
            cur_len = len(w)
            if cur_len > prv_len + 1:
                break
            for i in range(cur_len):
                c = w[i]
                m = maps[i]
                
                # if this is the last char
                if i == cur_len - 1: 
                    if c not in m:
                        m[c] = {}
                    if cur_len > 1:
                        prev_c = w[i-1]
                        m[c][prev_c]  = 1
                        
                    if cur_len > max_len:
                        max_len = cur_len
                        max_wrd = w
                    elif cur_len == max_len:
                        if w < max_wrd:
                            max_wrd = w
                else:  
                    if c not in m:
                        break
                    elif i > 0:
                        prev_c = w[i-1]
                        if prev_c not in m[c]:
                            break
                
                    
            prv_len = cur_len     
        
        return max_wrd