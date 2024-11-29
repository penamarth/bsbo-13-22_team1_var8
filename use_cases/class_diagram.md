# Диаграмма классов UML для информационной системы жилищного агентства

![class_diagram](/assets/plantuml/class_diagram.svg)

<!--
```plantuml
@startuml

class App {
-cur_user: User
-chat: Chat
-ads: Advert[]
+open_chat();
+send_message();
+get_new_messages();
}

interface AdvertState {}

class ActiveAdvert {}

class InactiveAdvert {}

class Advert {
-state: AdvertState
-flat: Flat
}

Advert o-> AdvertState
ActiveAdvert --\> Advert
InactiveAdvert --\> Advert
ActiveAdvert --|> AdvertState
InactiveAdvert --|> AdvertState

class Flat {
-owner: User
-renter: User
-address: String
-room_num: int
}

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

Advert --\> Flat

@enduml
```
-->
