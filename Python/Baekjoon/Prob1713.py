N = int(input())
M = int(input())
Voting = list(map(int,input().split()))
pictures = []
count = []
# 같은 인덱스로 저장되는 사진 리스트와 점수 리스트

for i in range(len(Voting)):
    if Voting[i] in pictures: # 투표가 이미 사진틀에 있는 후보라면
        for j in range(len(pictures)):
            if pictures[j] == Voting[i]: # 해당 사진의 인덱스 j를 찾아서, count 점수 추가
                count[j] += 1
    elif len(pictures) >= N: # 투표가 사진틀에 없는 다른 사진의 투표고, 모든 사진틀이 꽉 찬 경우
        for j in range(len(pictures)):
            if min(count) == count[j]: # 사진틀에서 최저점인 사진의 인덱스 j를 찾아서 삭제 후, 새 사진 추가
                del pictures[j]
                del count[j]
                break
        pictures.append(Voting[i])
        count.append(1)
    else: # 사진틀에 남은 공간이 있고, 기존 사진틀에 없는 사진 투표라면 그냥 추가
        pictures.append(Voting[i])
        count.append(1)

result = sorted(pictures)
for i in result:
    print(i, end= ' ')