cd {your directory}<br/>
<!-- python3 -m venv ./{your venv name} - 가상환경 만들기<br/> -->
source {your venv name(mysite)}/bin/activate   ||  source activate // 가상환경 진입하기  
mysite directory에서 $python manage.py runserver // 서버구동
deactivate //가상환경 벗어나기


mysite.zshrc  // 숨김파일