class Solution:

    def encode(self, strs):
        res = ""

        for string in strs:
            res += "#"
            res += str(len(string))
            res += string

        return res

    def decode(self, s):
        ans = []
        current = ""
        # 4 n e e t # 4 c  o  d  e  #  4  l  o  v  e  #  3  y  o  u
        i = 1
        while i < len(s):
            curr_len = int(s[i])
            k = i + 1
            for j in range(0, curr_len):
                current += s[k]
                k = k + 1
            ans.append(current)
            i = k + 1
            current = ""

        return ans


def main():
    s = Solution()
    input_list = ["neet", "code", "love", "you"]
    res = s.encode(input_list)
    s.decode(res)


if __name__ == "__main__":
    main()
