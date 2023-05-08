# using branch of Git
git pull
git switch -c branchname
> tagname/issue-anithing  


//touch test.txt 파일 생성  
//vi test.txt (:wq 는 저장 후 종료 q는 종료)  
git add test.txt //스테이징  
git status // commit 현황 확인  
git commit  

> ----commit convention----  
> tagname: ~~~  
> 상세 설명  

git switch main
git pull  
git merge branchname  
git switch branchname  
git push origin branchname 
--> origin : 원격저장소를 부르는 별명  
--> origin에 있는 브랜치인 branchname에 형이 현재 있는 브랜치를 push하시오

# git 원격저장소에는 없는 branch를 로컬 저장소에 남아있는 branch 제거
> git fetch -p