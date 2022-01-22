from cgi import print_directory


def wordPattern(pattern: str, s: str) -> bool:
    recd = {}
    recd1 = {}
    s_lis = s.split(" ")
    if len(s_lis) != len(pattern):
        return False
    for x in range(0, len(s_lis)):
        if pattern[x] in recd and s_lis[x] in recd1:
            if recd[pattern[x]] != s_lis[x] or recd1[s_lis[x]] != pattern[x]:
                return False
        if pattern[x] in recd or s_lis[x] in recd1:
            return False
        else:
            recd[pattern[x]] = s_lis[x]
            recd1[s_lis[x]] = pattern[x]
    return True

pattern = "abba"
s = "dog cat cat fish"
print(wordPattern(pattern, s))