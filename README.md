# OpenGL-Sauna-for-Linux


## Description  
OpenGL C++ 라이브러리를 이용하여 만든 카메라 시점 변경이 가능한 그래픽 작품입니다.  
본래 윈도우에서만 실행 가능했지만 리눅스 환경에서도 프로그램이 돌아가도록 코드를 수정했습니다.  

### 유튜브 영상
[![OpenGL-Sauna(Linux)](https://img.youtube.com/vi/72RhwXY1G5I/0.jpg)](https://youtu.be/72RhwXY1G5I "OpenGL-Sauna(windows)")

* 프로젝트 인원 : 1명
* 프로젝트 기간 : 2018.05.10 ~ 2018.06.12
* 사용 컴포넌트 : OpenGL(C++)

### 실행 방법
```ruby
$sudo apt-get install cmake libx11-dev xorg-dev libglu1-mesa-dev freeglut3-dev libglew1.5 libglew1.5-dev libglu1-mesa libglu1-mesa-dev libgl1-mesa-glx libgl1-mesa-dev libglfw3-dev libglfw3

출처: https://zenoahn.tistory.com/87 [제노 엔진]

$cd ~/OpenGL-Sauna-for-Linux
$make
$./sauna
```


### 조작키 설명
+ w : Move forward
+ s : Move backward
+ a : Turn left
+ d : Turn right
+ spacebar: Move up
+ v : Move down
