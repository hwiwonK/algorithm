# 장현실

## 4/7 Hash
*문제 : J2631, S2948*

## 4/8 Graph 알고리즘 1
*문제 : ~~S1249~~, ~~S1267~~*
- Topological Sort

- Dijkstra 알고리즘 + priority queue 이용하기

- BFS로 최단거리 구하기

## 4/9 Graph 알고리즘 2
*문제 : S1251, J1060*
- Disjoint set
- Prim algorithm
- Kruskal algorithm


## 4/12 동적계획법
*문제 : ~~J1077~~, ~~J1278~~, ~~S3282~~*
- 피보나치 (sliding window 사용)
- 거스름돈 구하기 (1D, 2D table 사용)
- 이항계수 구하기
- Knapsack (dp, dfs(백트래킹), bfs, best-first-search)

## 4/13 동적계획법2
*문제 : ~~J1871~~, ~~J2191~~, ~~S1263~~*
(S1263 floyd, dijkstra)
(S1263 우선순위 큐 써서 풀어보기)
- all pairs shortest (floyd, dijkstra)
- LIS
- Edit distance

## 4/14 동적계획법3
*문제 : ~~S1260~~, ~~J1220~~, J1858, ~~S1264~~*
- LCS(Longest Common Subsequence)
- MCM(Matrix Chain Multiplication)

## 4/15 동적계획법4
*문제 : ~~J1545~~, ~~J1863~~, J1133(런타임에러)*
- TSP(외판원 문제)
  완전검색(불가), DP기반 접근
- TSP 근사 알고리즘
  MST알고리즘 이용, 비트 이용 DP

## 4/16 기하 알고리즘
*문제 : J1151(미해결), J3336*
- ccw 알고리즘
  평면 위에 놓여진 세 점의 방향 관계 구하기
- Graham 알고리즘
  볼록 다각형 구하기

평면 sweeping 참고 : https://codedoc.tistory.com/421

## 4/19~ 문제풀이
#### 4/19
~~J1620~~(1) : 전화번호 암호 | <br>
~~J2499(시간초과)~~(3) : 저울 | Greedy <br>
~~J1108~~(1) : 페이지 전환 | all pairs shortest - floyd <br>
~~J3431~~(3) : 개구리 점프 |

#### 4/20
~~J2259~~(1) : 참외밭 |<br>
J1025(4) : 홍수 시뮬레이션 | <br>
~~J1761~~(2) : 숫자야구 |<br>
~~J1695~~(1) : 단지 번호 붙이기 | dfs, bfs 영역 구하기

#### 4/21
~~J1457~~(1) : 영역 구하기 | DFS 영역 면적 계산 문제<br>
J1025(4) : 홍수 시뮬레이션 | <br>
~~J2613~~(3) : 토마토 | bfs 최단시간 <br>
~~J2097~~(1) : 지하철 | dijkstra 최단거리 + 경로 구하기 <br>

#### 4/22
J1230 : 선물의 집 | dfs <br>
J2460 : 회장 정하기 | 논리구조 오류없이 짜기 <br>
~~J1078~~ : 저글링 방사능 오염 | bfs

#### 4/23
~~J1113~~(2) : 119 구급대 | dfs <br>
~~J1906~~(1) : 촌수계산 | 집합- 공통부모 찾기 <br>
~~J1462~~(2) : 보물섬 | bfs 

#### 4/26
J1082(2) : 화염에서 탈출 | dfs <br>
J1257(1) : 전깃줄(중) | 집합- 공통부모 찾기 <br>
J1180(2) : Dessert | bfs 


## TIP
한 작업 단위 끝나면 메모리 정리 + 출력 (다량의 데이터 출력할 때는 한꺼번에 출력하는 것이 성능 좋음)

### To do
- S1263 all pairs shortest 문제 dijkstra로 
