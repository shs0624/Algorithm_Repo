Vowel = ['a', 'e', 'i', 'o', 'u']

L, C = list(map(int,input().split()))
charList = list(map(str,input().split()))

charList = sorted(charList)

# 모음 1개, 자음2개 이상인지 체크
def check(pswd):
    vCnt, cCnt = 0, 0
    for i in pswd:
        if i in Vowel:
            vCnt += 1
        else:
            cCnt += 1

    if vCnt >= 1 and cCnt >= 2:
        return True
    else:
        return False


def brute(pswd):
    if len(pswd) == L:
        if check(pswd):
            print("".join(pswd))
            return
        # 체크실패? 패스

    # 비밀번호를 채우기 위한 문자 추가 작업 진행. 위치는 len(pswd)부터 체크
    for i in range(len(pswd), C):
        if pswd[-1] < charList[i]:
            # 재귀로 체크
            pswd.append(charList[i])
            brute(pswd)
            pswd.pop()

for i in range(0,len(charList)):
    brute([charList[i]])