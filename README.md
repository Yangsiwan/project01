# 비전관 택배 보관함 프로젝트 #
made by 21900429 양시완
## 소개 ##
이 프로그램은 기숙사 택배 보관을 위한 레코드 생성, 읽기, 수정, 삭제를 할 수 있는 프로그램이다.    
레코드를 호수, 이름, 학번 별로 정렬할 수 있고, 파일 백업, 택배이용통계현황을 저장할 수 있다.
## make utility를 이용한 사용법 ##
1. make main : main 파일 생성
2. make debug : debug 파일 생성
## 기능 ##
> ### 1. create : 새로운 레코드를 생성한다.
> ### 2. search (student number) : 학번으로 레코드를 검색한다.
> ### 3. search (room) : 방 호수로 레코드를 검색한다.
> ### 4. Delivery list : 1개 이상의 택배를 가지고 있는 레코드 출력
> ### 5. All list : 관리자모드 (비밀번호 : vision00)으로 들어간 후, 모든 레코드 출력
> ### 6. Update delivery : 학번을 입력하고 택배개수를 업데이트한다.
> ### 7. Load : 파일에 있는 레코드를 불러온다.
> ### 8. Save (backup) : 백업을 위한 파일을 backup.txt에 저장한다.
> ### 9. Sort : 1.학번 2.이름 3.방호수 순으로 레코드를 정렬한다.
> ### 10. Delete : 학번을 입력하고 레코드를 삭제한다.
> ### 11. Delete empty space : 데이터 조각 모음
> ### 12. save (statics) : 학번별 택배 이용통계를 statics.txt에 저장한다.
> ### 13. Update : 레코드를 업데이트 한다.
> ### 14. Find delivery : 택배를 찾는다.
> ### 15. Backup : 백업 파일을 불러온다.

## 주의사항 ##
### CREATE / UPDATE
  > * 학번 길이는 8자 이상으로 할 것
  > * 비밀번호를 생성/변경할 때 학번 뒤 세글자와 겹치는 부분이 없도록 할 것
  > * 이미 존재하는 레코드의 학번으로 생성/변경 불가
  > * 방에 4명이상의 레코드가 존재하면 해당 방으로 설정 불가
### READ
  > * 없는 학번/ 방 호수이면 레코드를 찾을 수 없음
  > * 모든 리스트 보기(관리자 모드)가 아니면 비밀번호는 함부로 열람할 수 없음
### DELETE
  > * 레코드를 지운 후에 조각 모음을 하지 않고 sorting을 하면 공간오류가 뜸.

## 참고 ##
* [양시완 project](https://github.com/Yangsiwan/project01, "project01 github")    
* [마크다운 사용법](https://gist.github.com/ihoneymon/652be052a0727ad59601, "how to use markdown")

