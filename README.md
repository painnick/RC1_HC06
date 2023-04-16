# 블루투스를 활용한 RC 만들기1

모형전자공작 모임 스터디 자료   
아두이노와 블루투스를 이용해 RC를 만드는 예제

> HC-05 또는 HC-06은 애플 기기에서 지원하지 않습니다(애플의 전력 소비 정책과 관련).   
> 그래서, 이 작업은 안드로이드 기기에서만 동작합니다.

<img src="https://user-images.githubusercontent.com/1592254/232291442-cc87c321-fb07-4a3f-8ee3-7c73b41378d8.jpg" width="500"></img>

(큰 바퀴가 앞쪽입니다)

## 0 준비물
- Adruino (Nano)
- HC-05/06 블루투스 모듈
- DC 모터(입력 전원에서 동작해야 함. 6V 입력에서는 3V 모터가 타버림)
- L298N 모터 드라이버(다른 모터 드라이버 사용 가능)
- 안드로이드 앱 Arduino Blurtooth Controller(다른 앱 사용 가능)

![Diagram](https://user-images.githubusercontent.com/1592254/229138472-cbda8e1f-e5aa-4e59-9a97-a7726786d434.png)

## 1 Pairing(기기 등록)

1. RC 카에 전원을 넣은 후, 휴대폰에 등록합니다.
2. RC 카가 제대로 켜진다면, 아래와 같이 연결 가능한 기기 목록에 RC 카 이름(예:JDY-31-SPP)이 추가됩니다.   
<img src="https://user-images.githubusercontent.com/1592254/232290231-3e488212-b0dc-4ce4-b463-91faca4ba2e0.png" width="500"></img>
3. 항목을 선택하면 암호를 입력합니다. JDY-31-SPP의 기본 암호는 1234입니다.
4. 정상적으로 등록되면 등록된 기기 목록에 노출됩니다.   
<img src="https://user-images.githubusercontent.com/1592254/232290837-03b2fdca-2693-466d-8d89-7a76f3c28f4a.png" width="500"></img>

## 2 애플리케이션 테스트

Android 앱인 Android Bluetooth Controller를 기준으로 설명합니다.
https://play.google.com/store/apps/details?id=com.giumig.apps.bluetoothserialmonitor
![GooglePlay](https://user-images.githubusercontent.com/1592254/232289691-9c066988-3c21-4ba3-b9c6-300656f904f3.png)

1. 연결할 수 있는 기기 목록에 RC 카(예:JDY-31-SPP)가 노출됩니다.   
<img src="https://user-images.githubusercontent.com/1592254/232291114-55b8d498-1fd6-4b4e-89e9-ce294cdcdd3c.png" width="500"></img>
2. 해당 항목을 클릭하면 선택할 수 있는 모드 중에서 Controller Mode를 선택합니다.   
<img src="https://user-images.githubusercontent.com/1592254/232291164-f96b8a47-cfdc-47b9-ae26-d6d693469aba.png" width="500"></img>
3. 게임 패드와 유사한 화면에서 우측 상단에 있는 설정 버튼을 누릅니다.   
<img src="https://user-images.githubusercontent.com/1592254/232291193-ce754834-035d-4ec3-bf8b-1b0a45cb39a2.png" width="500"></img>
4. 각 항목을 선택하고 L, R, U, D 각각의 문자를 등록합니다.   
<img src="https://user-images.githubusercontent.com/1592254/232291220-cf70a05b-0a6c-468a-9490-464f1df61a83.png" width="500"></img>
5. 다시 컨트롤러 화면으로 돌아와 방향 버튼을 눌러, 바퀴가 원하는대로 움직이는지 확인합니다.
