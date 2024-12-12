# Диаграмма классов UML для информационной системы жилищного агентства

![class_diagram](/assets/plantuml/class_diagram.svg)

<!--
```plantuml
@startuml

class App {
-cur_user: User
-chat: Chat
-advert: Advert
+open_chat();
+send_message();
+get_new_messages();
+create_advert();
+set_advert_info(room_num, address);
+make_advert_do_smth();
}

interface AdvertState {
+do_smth();
}

class ActiveAdvert {}

class InactiveAdvert {}

class Advert {
-state: AdvertState
-int: room_num
-string: address
}

Advert o-> AdvertState
ActiveAdvert --\> Advert
InactiveAdvert --\> Advert
ActiveAdvert --|> AdvertState
InactiveAdvert --|> AdvertState

class Chat {
-one: User
-two: User
-messages: Message[]
+send_message(text);
+get_new_messages();
}

class User {
+user_id: long long
}

App *-- Advert
App *-- Chat
App -- User

Chat -- User

@enduml
```
-->
